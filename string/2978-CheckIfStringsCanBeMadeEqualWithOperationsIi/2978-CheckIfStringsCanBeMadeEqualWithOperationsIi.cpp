// Last updated: 19/08/2026, 15:30:01
// class Solution {
// public:
//     bool checkStrings(string s1, string s2) {
//         vector<int> e1(26,0),e2(26,0);
//         vector<int> o1(26,0),o2(26,0);
//         int n = s1.size();
//         for(int i=0; i<n; ++i){
//             if(i % 2 == 0){
//                 e1[s1[i] - 'a']++;
//                 e2[s2[i] - 'a']++;
//             }else{
//                 o1[s1[i] - 'a']++;
//                 o2[s2[i] - 'a']++;
//             }
//         }
//         if(e1 == e2 && o1 == o2)return true;
//         else return false;
//     }
// };


class Solution {
public:
    static bool checkStrings(string& s1, string& s2) {
        array<array<int, 26>, 2> freq{};
        constexpr array<array<int, 26>, 2> zero{};
        const int n=s1.size();
        for(int i=0; i<n; i++){
            bool iOdd=i&1;
            freq[iOdd][s1[i]-'a']++;
            freq[iOdd][s2[i]-'a']--;
        }
        return freq==zero;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();