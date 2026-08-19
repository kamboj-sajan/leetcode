// Last updated: 19/08/2026, 15:52:27
// class FooBar {
// private:
//     int n;
//     mutex m;
//     condition_variable cv;
//     bool turn;
// public:
//     FooBar(int n) {
//         this->n = n;
//         turn = 0;
//     }

//     void foo(function<void()> printFoo) {
        
//         for (int i = 0; i < n; i++) {
//             unique_lock<mutex> lock(m);
//             while(turn == 1){
//                 cv.wait(lock);
//             }
//         	// printFoo() outputs "foo". Do not change or remove this line.
//         	printFoo();
//             turn = 1;
//             cv.notify_all();
//         }
//     }

//     void bar(function<void()> printBar) {
        
//         for (int i = 0; i < n; i++) {
//             unique_lock<mutex> lock(m);
//             while(turn == 0){
//                 cv.wait(lock);
//             }
//         	// printBar() outputs "bar". Do not change or remove this line.
//         	printBar();
//             turn = 0;
//             cv.notify_all();
//         }
//     }
// };

class FooBar {
private:
    int n;
    mutex m1,m2;
public:
    FooBar(int n) {
        m2.lock();
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            m1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            m2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m1.unlock();
        }
    }
};