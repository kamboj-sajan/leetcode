// Last updated: 19/08/2026, 15:52:22
class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(int i=0; i<address.size(); ++i){
            if(address[i] == '.'){
                ans += "[.]";
            }else{
                ans += address[i];
            }
        }
        return ans;
    }
};