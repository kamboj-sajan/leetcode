// Last updated: 19/08/2026, 15:16:58
class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;
    vector<ll> vec;
    vector<ll> ivec;
    ll po(ll a,ll b){
        ll res = 1;
        while(b){
            if(b & 1)res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    }
    void f(int n){
        vec.resize(n+1);
        ivec.resize(n + 1);
        vec[0] =1;
        for(int i=1; i<=n; ++i){
            vec[i] = vec[i-1]*i % mod;
        }
        ivec[n] = po(vec[n],mod -2);
        for(int i = n-1; i>=0; i--){
            ivec[i] = ivec[i+1]*(i+1)%mod;
        }
    }
    ll ncr(int n , int r){
        if(r < 0 || r > n)return 0;
        return vec[n]*ivec[r]%mod*ivec[n-r]%mod;
    }
public:
    int countVisiblePeople(int n, int pos, int k) {
        f(n);
        return (2LL*ncr(n-1,k))%mod;
    }
};