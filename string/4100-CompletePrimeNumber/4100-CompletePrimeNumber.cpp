// Last updated: 19/08/2026, 15:19:53
class Solution {
public:
    bool isPrime(int n){
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    bool completePrime(int num) {
        string c = to_string(num);
        int n = c.size();
        string pref;
        for (int i = 0; i < n; ++i) {
            pref += c[i];
            if (!isPrime(stoi(pref)) || !isPrime(stoi(c.substr(n - 1 - i))))
                return false;
        }
        return true;
    }
};
