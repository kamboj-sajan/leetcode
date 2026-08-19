// Last updated: 19/08/2026, 15:52:20
// class ZeroEvenOdd {
// private:
//     int n;
//     mutex m;
//     condition_variable cv;
//     int turn;
//     int i;
// public:
//     ZeroEvenOdd(int n) {
//         this->n = n;
//         turn = 0;
//         i = 1;
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void zero(function<void(int)> printNumber) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(turn != 0 && i<=n){
//                 cv.wait(lock);
//             }
//             if(i>n)break;
//             printNumber(0);
//             turn = (i%2) == 0 ? 2 : 1;
//             cv.notify_all();
//         }
//     }

//     void even(function<void(int)> printNumber) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(turn != 2 && i<=n){
//                 cv.wait(lock);
//             }
//             if(i>n)break;
//             printNumber(i++);
//             turn = 0;
//             cv.notify_all();
//         }
//     }

//     void odd(function<void(int)> printNumber) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(turn != 1 && i<=n){
//                 cv.wait(lock);
//             }
//             if(i>n)break;
//             printNumber(i++);
//             turn = 0;
//             cv.notify_all();
//         }
//     }
// };


using namespace std;
class ZeroEvenOdd {
    enum {P_ZERO = 0, P_EVEN, P_ODD};
private:
    int n;
    atomic<uint8_t> a_todo;
    atomic_flag af_stop;
    atomic_flag af_next_odd;


public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->a_todo = P_ZERO;
        this->af_stop.clear();
        this->af_next_odd.test_and_set();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (!af_stop.test()) {
            while (a_todo != P_ZERO && !af_stop.test()) this_thread::sleep_for(1us);            
            if (af_stop.test()) return;
            printNumber(0);
            a_todo = (af_next_odd.test() ? P_ODD : P_EVEN);
        } 
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; !af_stop.test(); i += 2) {
            while (a_todo != P_EVEN && !af_stop.test()) this_thread::sleep_for(1us);
            if (af_stop.test()) return;
            printNumber(i);
            if (i >= n) af_stop.test_and_set();
            af_next_odd.test_and_set();
            a_todo = P_ZERO;
        }
    }

    void odd(function<void(int)> printNumber) {        
       for (int i = 1; !af_stop.test(); i += 2) {
            while (a_todo != P_ODD && !af_stop.test()) this_thread::sleep_for(1us);
            if (af_stop.test()) return;
            printNumber(i);
            if (i >= n) af_stop.test_and_set();
            af_next_odd.clear();
            a_todo = P_ZERO;
        }
    }
};