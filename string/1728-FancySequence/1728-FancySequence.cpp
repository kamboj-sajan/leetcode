// Last updated: 19/08/2026, 15:38:35
class Fancy {
public:
    const long long mod = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modpow(long long a,long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - add) % mod;
        if(x < 0) x += mod;
        x = (x * modpow(mul, mod-2)) % mod;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % mod;
    }
};