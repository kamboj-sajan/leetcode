// Last updated: 19/08/2026, 15:29:57
// class Solution {
// public:
//     bool canBeEqual(string s1, string s2) {
//         if(s1[0] != s2[0])swap(s1[0],s1[2]);
//         if(s1[1] != s2[1])swap(s1[1],s1[3]);
//         if(s1 == s2)return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Check even indices (0 and 2)
        // They must either match as-is OR match if swapped
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) || 
                         (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // Check odd indices (1 and 3)
        // They must either match as-is OR match if swapped
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) || 
                        (s1[1] == s2[3] && s1[3] == s2[1]);
        
        return evenMatch && oddMatch;
    }
};