



## 实现一个线程池
线程池通过维护一组线程来运行用户添加到队列中的任务
免去了线程创建和销毁的开销,提高了系统的性能.

基本功能描述:


+ threadpool调用run之后启动用户指定数目的线程
每个线程都执行一个循环,从任务队列中取任务,执行任务
+ 用户通过add接口向池中添加task或者通过launch接口add&run

+ 调度策略
队列中有N个任务,池中有M个线程,那么就需要调度



用法示例
```cpp
struct Task
{
  std::function<void(void *)> fun;
}
//创建线程池
ThreadPool tp;
//添加任务
tp.add(task)

tp.run();
tp.join();
```

