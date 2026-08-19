// Last updated: 19/08/2026, 15:52:32
// class H2O {
//      mutex m;
//      condition_variable cv;
//      int turn;
// public:
//     H2O() {
//        turn = 0;
//     }

//     void hydrogen(function<void()> releaseHydrogen) {
//         unique_lock<mutex> lock(m);
//         while(turn == 2){
//             cv.wait(lock);
//         }
//         // releaseHydrogen() outputs "H". Do not change or remove this line.
//         releaseHydrogen();
//         ++turn;
//         cv.notify_all();
//     }

//     void oxygen(function<void()> releaseOxygen) {
//         unique_lock<mutex> lock(m);
//         while(turn < 2){
//             cv.wait(lock);
//         }
//         // releaseOxygen() outputs "O". Do not change or remove this line.
//         releaseOxygen();
//         turn = 0;
//         cv.notify_all();

//     }
// };

class H2O {
private:
    int turn;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        turn=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(m);
        while(turn==2)
        cv.wait(lock);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>lock(m);
        while(turn<2)
        cv.wait(lock);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn=0;
        cv.notify_all();
    }
};