// Last updated: 19/08/2026, 16:07:37
// class Solution {
// public:
//     bool ispalindrome(int i, int j,string &s){
//         while(i<j){
//             if(s[i] != s[j])return false;
//             i++; 
//             j--;
//         }
//         return true;
//     }
// public:
//     void f(int i,vector<string> &temp,vector<vector<string>> &ds,string &s){
//         if(i == s.size()){
//             ds.push_back(temp);
//             return;
//         }
//         string str = "";
//         for(int j=i; j<s.size(); j++){
//               str += s[j];
//               if(ispalindrome(i,j,s)){
//                 temp.push_back(str);
//                 f(j+1,temp,ds,s);
//                 temp.pop_back();
//               }
//         }
//     }
// public:
//     vector<vector<string>> partition(string s) {
//         vector<string> temp;
//         vector<vector<string>> ds;
//         f(0,temp,ds,s);
//         return ds;
//     }
// };




const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void *operator new(size_t size)
{
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void *ptr, unsigned long) {}
void operator delete(void *ptr) {}
void operator delete[](void *ptr) {}
class Solution {
public:
    bool checkPalin(string &s,int st,int end){
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void recurse(vector<vector<string>> &ans,vector<string> &curr,string &s,int pos){
        if(pos==s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=pos;i<s.size();i++){
            if(checkPalin(s,pos,i)){
                curr.push_back(s.substr(pos,i-pos+1));
                recurse(ans,curr,s,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        recurse(ans,curr,s,0);
        return ans;
    }
};