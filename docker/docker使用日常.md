
<https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04>


Executing the Docker Command Without Sudo

+ 复制文件
docker cp /home/chen/.ssh/id_rsa.pub 4c92b262536d:root/.ssh
+ 提交修改
docker commit -m "install package" -a "chen" 8e654e7635be gubuntu
+ 查看修改历史
docker history <imagename>
+ 回滚到某个版本
docker tag 2844(hashtag) <imagename>
+ 共享/挂载目录
docker run -v /home/chen/ict/dm:/root/bin -it gubuntu
传入多个-v参数,可以挂载多个目录
<https://www.digitalocean.com/community/tutorials/how-to-share-data-between-docker-containers>
+ 开机自动启动ssh服务
装了openssh之后,不知为何无法通过正常的service启动
docker run启动的时候传入的要执行的命令必须是不能退出的那种,
否则container instance就也exit了
所以`docker run -it gubuntu /usr/sbin/sshd`不行
必须的`docker run -it gubuntu /usr/sbin/sshd -D`这样,加上D才行
可是这样的话,每个container instance启动之后,就只能通过ssh进去,不能直接操作了
启动sshd服务,然后还能正常操作这样最后
方法就是
在.bashrc中加入一行`/usr/sbin/sshd`


管理container instance
sudo docker ps -a  -q|xargs sudo docker kill --signal=TERM
sudo docker ps -a  -q|xargs sudo docker rm  

docker stop 

docker run -it gubuntu /usr/sbin/sshd -D

image导入导出

导出
docker save -o /home/matrix/matrix-data.tar matrix-data
导入
docker load -i <path_to_tar_file>
这个过程很耗时,执行完后 docker images就能看到导入的镜像了


docker save centos:6 | ssh -C ict16 docker load
docker save gubuntu| ssh -C root@10.3.1.81 docker load

centos 6.5 install docker 

yum -y install docker-io
https://www.liquidweb.com/kb/how-to-install-docker-on-centos-6/

centos 6.5 os 内核版本问题
yum upgrade device-mapper-libs -y
[CentOS 6.5安装docker](http://www.jianshu.com/p/6cdc5779af70)


--rm                             Automatically remove the container when it exits
这个选项太有用了,太符合需求了
exit的时候自动把实例删除
以前还要
sudo docker ps -a -q |sudo xargs docker stop
sudo docker ps -a -q |sudo xargs docker rm
当然有一点不好
做的改动exit之后就无法去commit了
exit之后也无法restart然后attache了


网络模型
定制网桥
-b=br0 --fixed-cidr=10.3.1.112/28 

bridge IPv4 (172.17.42.1) does not match requested
如果docker0已经配置了ip,就会直接使用
所以custome 要想生效
要先ifconfig docker0 0.0.0.0
清除既有配置

This is expected and intended behavior. As a rule, docker does not try to change the IP address of docker0 if one is already configured and is not the same as the one you are requesting using --bip. To make this work please remove the IP address from docker0 and then launch the daemon with the appropriate --bip configuration and it should work. Alternatively you can completely delete the docker0 bridge 
before you use this configuration. Daemon will create and set the right IP address for you

在各个宿主机上都建立一个新虚拟网桥设备br0,将各自物理网卡eth0桥接br0上,eth0的IP地址赋给br0
同时修改Docker daemon的DOCKER_OPTS,设置-b=br0（替代docker0）,并限制Container IP地址的分配范围为同物理段地址（–fixed-cidr）.
重启各个主机的Docker Daemon后,处于与宿主机在同一网段的Docker容器就可以实现跨主机访问了.
这个方案同样存在局限和扩展性差的问题：比如需将物理网段的地址划分 成小块,分布到各个主机上,防止IP冲突；子网划分依赖物理交换机设置；
Docker容器的主机地址空间大小依赖物理网络划分等.

跨主机通信
docker cookbook上有很多recipe


[理解Docker跨多主机容器网络](http://tonybai.com/2016/02/15/understanding-docker-multi-host-networking/)

docker资源配置
--cpuset-cpus


跨主机通信的场景是什么
配置网络之前,靠port forward 暴露ssh端口号,可以ssh log into 
可是如果需要其他端口号来通信,而且这些端口又未知
这时就必须要有完整的网路介入权限了,就是说,能ping通,能自由的建立tcpu连接
这就是配置容器和主机同网段的意义
最终达到主机网段的其他机器,能ping通主机上的容器
配同一网段,具体怎样操作?
docker run的时候, --net=None
然后用pipework脚本设置docker容器的ip
把物理主机的eth0的网路配置赋给br0
brctl br0 eth0
brctl br0 $docker

大概是这么个思路


免sudo执行命令
`permission denied. Are you trying to connect to a TLS-enabled daemon without TLS`
boot2docker start
boot2docker shellinit

docker build

```dockerfile
FROM docker/whalesay:latest
RUN apt-get -y update && apt-get install -y fortunes
CMD /usr/games/fortune -a | cowsay
```
docker build -t docker-whale . 

<none>:<none> images

没有name tag 
sudo docker run -v /home/cjh/project/dl:/root/notebook  -it 52415145a305 /bin/bash
用image id作启动参数也是可以的

