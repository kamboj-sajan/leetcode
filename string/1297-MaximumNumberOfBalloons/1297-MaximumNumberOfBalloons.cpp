// Last updated: 19/08/2026, 15:51:27
// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         int n = text.size();
//         unordered_map<char,int> mpp;
//         string s = "balloon";
//         for(int i=0; i<n; ++i){
//             if(s.find(text[i]) != string::npos)mpp[text[i]]++;
//         }
//         mpp['l'] = mpp['l']/2;
//         mpp['o'] = mpp['o']/2;
//         int mini = INT_MAX;
//         for(auto &p : mpp){
//             mini = min(mini,p.second);
//         }
//         bool a = true;
//         for(char c : s){
//             if(mpp.find(c) == mpp.end()){
//                 a = false;
//                 break;
//             }
//         }
//         return (a == true)?mini:0;
//     }
// };

// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         unordered_map<char,int> freq;
//         for(char c:text){
//             freq[c]++;
//         }
//         return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
//     }
// };

class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int a = 0,b = 0,l = 0,o = 0,n = 0;
         int count = 0;
        for(int i = 0;i<text.size();i++)
        {
            if(text[i]=='a')a++;
            else if(text[i]=='b')b++;
            else if(text[i]=='l')l++;
            else if(text[i]=='o')o++;
            else if(text[i]=='n') n++;

            while(a>=1 && b>=1 && l>=2 && o>=2 && n>=1)
            {
                count++;
                a--;
                b--;
                l-=2;
                o-=2;
                n--;

            }
            
        }
        return count;
    }
};