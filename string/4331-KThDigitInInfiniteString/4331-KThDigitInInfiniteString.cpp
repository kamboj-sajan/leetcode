// Last updated: 19/08/2026, 15:15:28
// class Solution {
// public:
//     using ll = long long;
//     int kthDigit(long long k) {
//         if(k<=9)return k;
//         k-=9;
//         ll d=2;
//         ll p=10;
//         while(1){
//             ll cnt=9LL*p/10;
//             ll total=cnt*10*d;
//             if(k<=total){
//                 k--;
//                 ll bl=k/(10*d);
//                 ll pos= k%(10*d);
//                 ll st=p+10*bl;
//                 ll b=st/10;
//                 ll id=pos/d;
//                 ll t=pos%d;
//                 ll temp;
//                 if(b%2==0)temp=st+id;
//                 else temp=st+9-id;
//                 string s=to_string(temp);
//                 return s[t]-'0';
//             }
//             k-=total;
//             d++;
//             p*=10;
//         }
//     }
// };

class Solution {
public:
    using ll = long long;
    int kthDigit(ll k) {
        function<int(ll,ll)> solve = [&](ll k, ll len) {
            if(len == 1) {
                if(k <= 9) return (int)k;
                return solve(k - 9, len + 1);
            }
            ll lo = 1;
            for(int i = 1; i < len; i++) lo *= 10;
            ll bl = (9 * lo) / 10;
            ll st = 10 * len;
            ll total = bl * st;
            if(k <= total) {
                ll id = (k - 1) / st;
                ll in = k - id * st;
                ll b = lo / 10 + id;

                ll numId = (in - 1) / len;
                ll pos = (in - 1) % len;

                ll base = 10 * b;
                ll temp;

                if(b % 2 == 0)
                    temp = base + numId;
                else
                    temp = base + 9 - numId;

                string st = to_string(temp);
                return st[pos] - '0';
            }

            return solve(k - total, len + 1);
        };
        return solve(k, 1);
    }
};