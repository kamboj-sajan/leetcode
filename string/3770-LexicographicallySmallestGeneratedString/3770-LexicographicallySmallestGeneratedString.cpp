// Last updated: 19/08/2026, 15:25:48

// class Solution {
// public:
//     string generateString(string str1, string str2) {
//         int n = str1.size(), m = str2.size();
//         int len = n + m - 1;
        
//         vector<char> word(len, '?');
        
//         // Step 1: Apply 'T' constraints
//         for (int i = 0; i < n; i++) {
//             if (str1[i] == 'T') {
//                 for (int j = 0; j < m; j++) {
//                     if (word[i + j] == '?' || word[i + j] == str2[j]) {
//                         word[i + j] = str2[j];
//                     } else {
//                         return ""; // conflict
//                     }
//                 }
//             }
//         }
        
//         // Step 2: Fill remaining with 'a'
//         for (int i = 0; i < len; i++) {
//             if (word[i] == '?') word[i] = 'a';
//         }
        
//         // Step 3: Handle 'F' constraints
//         for (int i = 0; i < n; i++) {
//             if (str1[i] == 'F') {
//                 bool match = true;
//                 for (int j = 0; j < m; j++) {
//                     if (word[i + j] != str2[j]) {
//                         match = false;
//                         break;
//                     }
//                 }
                
//                 if (match) {
//                     bool fixed = false;
                    
//                     // try to break match
//                     for (int j = m - 1; j >= 0 && !fixed; j--) {
//                         for (char c = 'a'; c <= 'z'; c++) {
//                             if (c != str2[j]) {
//                                 char original = word[i + j];
//                                 word[i + j] = c;
                                
//                                 // check all T constraints still valid
//                                 bool valid = true;
//                                 for (int k = 0; k < n; k++) {
//                                     if (str1[k] == 'T') {
//                                         for (int x = 0; x < m; x++) {
//                                             if (word[k + x] != str2[x]) {
//                                                 valid = false;
//                                                 break;
//                                             }
//                                         }
//                                         if (!valid) break;
//                                     }
//                                 }
                                
//                                 if (valid) {
//                                     fixed = true;
//                                     break;
//                                 }
                                
//                                 word[i + j] = original;
//                             }
//                         }
//                     }
                    
//                     if (!fixed) return "";
//                 }
//             }
//         }
        
//         return string(word.begin(), word.end());
//     }
// };


class Solution {
    vector<int> calcZ(const string &s) {
        int size = s.size();
        vector<int> z(size, 0);
        int l = 0, r = 0;   // z-box: [l, r]
        for (int i = 1; i < size; i++) {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < size && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i]++;
            }
        }
        z[0] = size;
        return z;
    }
public:
    string generateString(string str1, string str2) {
        int size1 = str1.size(), size2 = str2.size();
        int wordSize = size1 + size2 - 1;
        string word(wordSize, '*');
        vector<int> z = calcZ(str2);

        // process T
        int pre = -size2;
        for (int i = 0; i < size1; i++) {
            if (str1[i] == 'F')
                continue;
            int residueLen = max(0, pre + size2 - i);
            if (residueLen && z[size2 - residueLen] < residueLen)
                return "";
            for (int j = residueLen; j < size2; j++) {
                word[i + j] = str2[j];
            }
            pre = i;
        }

        vector<int> lastWild(wordSize, -1);
        pre = -1;
        for (int i = 0; i < wordSize; i++) {
            if (word[i] == '*') {
                word[i] = 'a';
                pre = i;
            }
            lastWild[i] = pre;
        }

        // process F
        z = calcZ(str2 + word);
        for (int i = 0; i < size1; i++) {
            if (str1[i] == 'T' || z[size2 + i] < size2)
                continue;
            int candidatePos = lastWild[i + size2 - 1];
            if (candidatePos < i)
                return "";
            word[candidatePos] = 'b';
            i = candidatePos;
        }
        return word;
    }
};