// Last updated: 19/08/2026, 15:52:24
// class Foo {
//     mutex m;
//     condition_variable cv;
//     int turn;
// public:
//     Foo() {
//         turn = 0;
//     }

//     void first(function<void()> printFirst) {
        
//         // printFirst() outputs "first". Do not change or remove this line.
//         printFirst();
//         turn = 1;
//         cv.notify_all();
//     }

//     void second(function<void()> printSecond) {
//         unique_lock<mutex> lock(m);
//         while(turn != 1){
//             cv.wait(lock);
//         }

//         // printSecond() outputs "second". Do not change or remove this line.
//         printSecond();
//         turn = 2;
//         cv.notify_all();
//     }

//     void third(function<void()> printThird) {
//         unique_lock<mutex> lock(m);
//         while(turn != 2){
//             cv.wait(lock);
//         }
//         // printThird() outputs "third". Do not change or remove this line.
//         printThird();
//     }
// };

class Foo {
public:
    std::condition_variable cv;
    std::mutex m;
    size_t completed_task_id = 0;

    void first(function<void()> printFirst) {
        {
            auto lk = std::lock_guard{m};
            printFirst();
            completed_task_id = 1;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            auto lk = std::unique_lock{m};
            cv.wait(lk, [&]() { return completed_task_id == 1; });
            printSecond();
            completed_task_id = 2;
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        auto lk = std::unique_lock{m};
        cv.wait(lk, [&]() { return completed_task_id == 2; });
        printThird();
    }
};