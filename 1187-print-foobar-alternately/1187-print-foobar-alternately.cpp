class FooBar {
private:
    int n;
    int flag=0;
    condition_variable cv;
    mutex m;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            while(flag==1){
                cv.wait(lock);
            }
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            while(flag==0){
                cv.wait(lock);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag=0;
            cv.notify_all();
        }
    }
};