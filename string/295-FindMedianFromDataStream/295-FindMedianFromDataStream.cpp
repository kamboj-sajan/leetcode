// Last updated: 19/08/2026, 16:03:21
class MedianFinder {
public:
    priority_queue<int> maxheap; // left half
    priority_queue<int, vector<int>, greater<int>> minheap; // right half
    double median = 0.0;

    int signum(int a, int b) {
        if (a == b) return 0;
        else if (a > b) return 1;
        else return -1;
    }

    MedianFinder() {}

    void call_median(int ele) {
        switch (signum(maxheap.size(), minheap.size())) {
            case 0:
                if (ele > median) {
                    minheap.push(ele);
                    median = minheap.top();
                } else {
                    maxheap.push(ele);
                    median = maxheap.top();
                }
                break;

            case 1:
                if (ele > median) {
                    minheap.push(ele);
                } else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(ele);
                }
                median = (maxheap.top() + minheap.top()) / 2.0;
                break;

            case -1:
                if (ele > median) {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(ele);
                } else {
                    maxheap.push(ele);
                }
                median = (maxheap.top() + minheap.top()) / 2.0;
                break;
        }
    }

    void addNum(int num) {
        call_median(num);
    }

    double findMedian() {
        return median;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */