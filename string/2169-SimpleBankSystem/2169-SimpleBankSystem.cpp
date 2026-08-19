// Last updated: 19/08/2026, 15:33:50
class Bank {
public: 
    bool val(int ac){
        return ac > 0 && ac <= n;
    }

    vector<long long> bal;
    int n;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }
    
    bool transfer(int account1 /*from*/, int account2/*to*/, long long money) {
        if(!val(account1) || !val(account2) || bal[account1 - 1] < money)return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!val(account))return false;
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!val(account) || bal[account - 1] < money)return false;
        bal[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */