// Last updated: 13/10/2026, 10:47:41
class BusBooking {
    vector<int> vec;
    int t = 0;
    int b = 0;
public:
    BusBooking(int n) {
        vec.assign(4*n,0);
    }
    
    void toggle(string seat) {
        int c = seat[0]-'A';
        int r = stoi(seat.substr(1)) -1;
        int i = r*4+c;
        if(vec[i]){
            t -= vec[i];
            vec[i]= 0;
            b--;
            return;
        }
        int cost = 1;
        if(c == 0 && vec[r*4+1])cost = 3;
        if(c ==3 && vec[r*4+2])cost = 3;
        vec[i] = cost;
        t += cost;
        b++;
    }
    
    int getTotalTime() {
        return t;
    }
    
    int getMinTime() {
        return b;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */