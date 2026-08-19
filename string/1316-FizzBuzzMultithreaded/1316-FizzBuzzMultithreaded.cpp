// Last updated: 19/08/2026, 15:51:02
// class FizzBuzz {
// private:
//     int n;
//     mutex m;
//     condition_variable c;
//     int i;
// public:
//     FizzBuzz(int n) {
//         this->n = n;
//         this->i = 1;
//     }

//     // printFizz() outputs "fizz".
//     void fizz(function<void()> printFizz) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(i<=n && (((i%3) ==0) && ((i%5) != 0)) == 0){
//                 c.wait(lock);
//             }
//             if(i<=n){
//                 printFizz();
//                 ++i;
//             }
//             c.notify_all();
//         }
//     }

//     // printBuzz() outputs "buzz".
//     void buzz(function<void()> printBuzz) {
//          while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(i<=n && (((i%5) ==0) && ((i%3) != 0)) == 0){
//                 c.wait(lock);
//             }
//             if(i<=n){
//                 printBuzz();
//                 ++i;
//             }
//             c.notify_all();
//         }
//     }

//     // printFizzBuzz() outputs "fizzbuzz".
// 	void fizzbuzz(function<void()> printFizzBuzz) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(i<=n && (((i%5) ==0) && ((i%3) == 0)) == 0){
//                 c.wait(lock);
//             }
//             if(i<=n){
//                 printFizzBuzz();
//                 ++i;
//             }
//             c.notify_all();
//         }
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void number(function<void(int)> printNumber) {
//         while(i <= n){
//             unique_lock<mutex> lock(m);
//             while(i<=n && (((i%5) !=0) && ((i%3) != 0)) == 0){
//                 c.wait(lock);
//             }
//             if(i<=n){
//                 printNumber(i++);
//             }
//             c.notify_all();
//         }
//     }
// };

// class FizzBuzz {
// private:
//     int n;
//     int i;
//     mutex m;
//     condition_variable cv;

// public:
//     FizzBuzz(int n) {
//         this->n = n;
//         this->i = 1;  // FIXED
//     }

//     void fizz(function<void()> printFizz) {
//         while (true) {
//             unique_lock<mutex> lock(m);
//             cv.wait(lock, [&]() {
//                 return i > n || (i % 3 == 0 && i % 5 != 0);
//             });

//             if (i > n) return;

//             printFizz();
//             i++;
//             cv.notify_all();
//         }
//     }

//     void buzz(function<void()> printBuzz) {
//         while (true) {
//             unique_lock<mutex> lock(m);
//             cv.wait(lock, [&]() {
//                 return i > n || (i % 5 == 0 && i % 3 != 0);
//             });

//             if (i > n) return;

//             printBuzz();
//             i++;
//             cv.notify_all();
//         }
//     }

//     void fizzbuzz(function<void()> printFizzBuzz) {
//         while (true) {
//             unique_lock<mutex> lock(m);
//             cv.wait(lock, [&]() {
//                 return i > n || (i % 3 == 0 && i % 5 == 0);
//             });

//             if (i > n) return;

//             printFizzBuzz();
//             i++;
//             cv.notify_all();
//         }
//     }

//     void number(function<void(int)> printNumber) {
//         while (true) {
//             unique_lock<mutex> lock(m);
//             cv.wait(lock, [&]() {
//                 return i > n || (i % 3 != 0 && i % 5 != 0);
//             });

//             if (i > n) return;

//             printNumber(i++);
//             cv.notify_all();
//         }
//     }
// };



// GO Solution
/*
type FizzBuzz struct {
    n             int
    allowFizz     chan struct{}
    allowBuzz     chan struct{}
    allowFizzBuzz chan struct{}
    allowNumber   chan struct{}
}

func NewFizzBuzz(n int) *FizzBuzz {
    fb := &FizzBuzz{
        n:             n,
        allowFizz:     make(chan struct{}, 1),
        allowBuzz:     make(chan struct{}, 1),
        allowFizzBuzz: make(chan struct{}, 1),
        allowNumber:   make(chan struct{}, 1),
    }
    fb.allowNumber <- struct{}{}
    return fb
}

func (fb *FizzBuzz) signal(x int) {
    if x > fb.n {
        return
    }
    if x%3 == 0 && x%5 == 0 {
        fb.allowFizzBuzz <- struct{}{}
    } else if x%3 == 0 {
        fb.allowFizz <- struct{}{}
    } else if x%5 == 0 {
        fb.allowBuzz <- struct{}{}
    } else {
        fb.allowNumber <- struct{}{}
    }
}

func (fb *FizzBuzz) Fizz(printFizz func()) {
    for i := 1; i <= fb.n; i++ {
        if i%3 == 0 && i%5 != 0 {
            <-fb.allowFizz
            printFizz()
            fb.signal(i + 1)
        }
    }
}

func (fb *FizzBuzz) Buzz(printBuzz func()) {
    for i := 1; i <= fb.n; i++ {
        if i%5 == 0 && i%3 != 0 {
            <-fb.allowBuzz
            printBuzz()
            fb.signal(i + 1)
        }
    }
}

func (fb *FizzBuzz) FizzBuzz(printFizzBuzz func()) {
    for i := 1; i <= fb.n; i++ {
        if i%3 == 0 && i%5 == 0 {
            <-fb.allowFizzBuzz
            printFizzBuzz()
            fb.signal(i + 1)
        }
    }
}

func (fb *FizzBuzz) Number(printNumber func(int)) {
    for i := 1; i <= fb.n; i++ {
        if i%3 != 0 && i%5 != 0 {
            <-fb.allowNumber
            printNumber(i)
            fb.signal(i + 1)
        }
    }
}

*/

#include <functional>
#include <mutex>
#include <condition_variable>

class FizzBuzz {
private:
    int n;
    mutex mu;
    condition_variable cv;
    // whose turn is it?
    // 0=number, 1=fizz, 2=buzz, 3=fizzbuzz
    int turn = 0;
    int i = 1;

    void waitFor(int myTurn) {
        unique_lock<mutex> lock(mu);
        cv.wait(lock, [this, myTurn] { return turn == myTurn || i > n; });
    }

    void signalNext() {
        if (i > n) {
            cv.notify_all();
            return;
        }
        if      (i%3==0 && i%5==0) turn = 3;
        else if (i%3==0)           turn = 1;
        else if (i%5==0)           turn = 2;
        else                       turn = 0;
        cv.notify_all();
    }

public:
    FizzBuzz(int n) : n(n) {}

    void fizz(function<void()> printFizz) {
        while (true) {
            waitFor(1);
            if (i > n) return;
            printFizz();
            i++;
            {
                lock_guard<mutex> lock(mu);
                signalNext();
            }
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            waitFor(2);
            if (i > n) return;
            printBuzz();
            i++;
            {
                lock_guard<mutex> lock(mu);
                signalNext();
            }
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            waitFor(3);
            if (i > n) return;
            printFizzBuzz();
            i++;
            {
                lock_guard<mutex> lock(mu);
                signalNext();
            }
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            waitFor(0);
            if (i > n) return;
            printNumber(i);
            i++;
            {
                lock_guard<mutex> lock(mu);
                signalNext();
            }
        }
    }
};