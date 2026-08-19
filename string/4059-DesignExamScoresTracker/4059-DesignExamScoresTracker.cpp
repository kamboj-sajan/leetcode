// Last updated: 19/08/2026, 15:20:40
class ExamTracker {
public:
    vector<long> t;
    vector<long> pret;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        t.push_back(time);
        if(pret.empty()){
            pret.push_back(score);
        }else{
            pret.push_back(pret.back() + score);
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        if(t.empty())return 0;
        int r = upper_bound(t.begin(),t.end(),endTime) - t.begin() - 1;
        int l = lower_bound(t.begin(),t.end(),startTime) - t.begin() - 1;
        if(r < 0)return 0;
        if(l == r)return (l < 0 ? pret[r] : pret[r] - pret[l]);
        if(r < l)return 0;
        return pret[r] - (l >= 0 ? pret[l] : 0);
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */