


观察者模式


class Observer  观察者
class Observable 被观察对象

Obj observe subject 
obj观察 subject,持有subject指针,用于析构的时候把自己从sujbect的观察者列表中去掉

subject 有一个vector存放 所有观察者的指针,用于 发生变化的时候调用观察者的update方法


多线程下的观察者要解决哪些竞争条件

+ Observable的vector会被并发访问:
1.Observer要向vector添加成员;2.Observer析构要从vector删除成员;3notify的时候要遍历这个vector
因此访问vector要加锁
+ 为了安全的释放资源和安全的访问指针,
要用shared_ptr管理Observer;
Observable要保存对Observer的weak_ptr