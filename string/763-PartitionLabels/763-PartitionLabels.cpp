// Last updated: 11/10/2026, 08:09:33
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//        int n = s.size();
//        unordered_map<char,pair<int,int>> mpp;
//        for(int i=0; i<n; i++){
//         if(mpp.find(s[i]) == mpp.end()){
//             mpp[s[i]] = {i,i};
//         }else{
//             mpp[s[i]].second = i;
//         }
//        }
//        vector<int> ans;
//        int maxi = 0;
//        int start = 0;
//        for(int i=0; i<n; i++){
//         maxi = max(maxi,mpp[s[i]].second);
//         if(i == maxi){
//             ans.push_back(i - start +1);
//             start = i+1;
//         }
//        }
//        return ans;
//     }
// };

class Solution {
public:

    // take char one by one, let's say first char is 'a'
    // and last occurence of 'a' is 8, so hume 8 tak toh
    // lena hi padega current partition mein, taaki saare 'a'
    // ek hi partition mein aa jaaye
    // ab 8 tak toh traverse karenge hi, and note bhi karenge
    // ki beech mein or bhi jitne char aa rahe, unki last occurence 
    // kya hai, agar wo 8 se kam hai, tab toh ek single parition hoga
    // agar unki last occurence 8 se bhi jyada hai, toh or bhi
    // aage badhao parititon ka end, and ese karke hume ek esi end
    // position find karni hai ki start se end tak jitne bhi char aaye
    // un sabki last occurence <=end tak ho, and ese ek parition bana 
    // payenge. Ese hone ke baad start ko end+1 karenge, and or aage
    // traverse karke next partition find karenge

    vector<int> partitionLabels(string s) {
        unordered_map<char, int>lastOccurence;
        for(int i=0; i<s.length(); i++){
            lastOccurence[s[i]] = i;
        }

        vector<int>ans;

        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++){
            end = max(end, lastOccurence[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }

        return ans;
    }
};