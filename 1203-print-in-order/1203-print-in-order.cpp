class Foo {
    mutex m;
    condition_variable cv;
    int step;
public:
    Foo() {
        step=0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step=1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>lock(m);
        while(step!=1){
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>lock(m);
        while(step!=2){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};