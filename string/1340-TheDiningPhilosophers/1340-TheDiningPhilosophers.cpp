// Last updated: 19/08/2026, 15:50:37
// class Semaphore{
//     public:
//        Semaphore() {}
//        Semaphore(int c) : count(c){};
//        void setCount(int a){
//         count = a;
//        }
//        inline void signal(){
//         unique_lock<mutex> lock(mtx);
//         count++;
//         if(count <=0 )
//           cv.notify_one();
//        }
//        inline void wait(){
//         unique_lock<mutex> lock(mtx);
//         count--;
//         while(count < 0){
//             cv.wait(lock);
//         }
//        }
//        private:
//        mutex mtx;
//        condition_variable cv;
//        int count;
// };

// class DiningPhilosophers {
//     Semaphore fork[5];
//     mutex m,l;
// public:
//     DiningPhilosophers() {
//         for(int i=0; i<5; ++i){
//             fork[i].setCount(1);
//         }
//     }

//     void wantsToEat(int philosopher,
//                     function<void()> pickLeftFork,
//                     function<void()> pickRightFork,
//                     function<void()> eat,
//                     function<void()> putLeftFork,
//                     function<void()> putRightFork) {
//         {
// 		lock_guard<mutex> lock(m);
//         fork[(philosopher+1)%5].wait();
//         fork[philosopher].wait();
//         }
//         pickLeftFork();
//         pickRightFork();
//         eat();
//         putLeftFork();
//         fork[(philosopher+1)%5].signal();
//         putRightFork();
//         fork[philosopher].signal();
//     }
// };

#include <mutex>
#include <functional>
#include <semaphore>
using namespace std;

class DiningPhilosophers {
private:
    mutex forks[5];
    counting_semaphore<4> room{4}; // allow max 4 philosophers

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        room.acquire(); // enter dining room

        lock(forks[left], forks[right]); // avoid deadlock
        unique_lock<mutex> l1(forks[left], adopt_lock);
        unique_lock<mutex> l2(forks[right], adopt_lock);

        pickLeftFork();
        pickRightFork();

        eat();

        putRightFork();
        putLeftFork();

        room.release(); // leave dining room
    }
};