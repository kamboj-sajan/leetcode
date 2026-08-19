// Last updated: 19/08/2026, 16:07:50
// class Solution {
// public:
//     int ladderLength(string bw, string ew, vector<string>& wordList) {
//         queue<pair<string,int>> q;
//         q.push({bw,1});
//         set<string> st(wordList.begin(),wordList.end());
//         st.erase(bw);
//         while(!q.empty()){
//             string word = q.front().first;
//             int stp = q.front().second;
//             q.pop();
//             if(word == ew)return stp;
//             for(int i=0; i<word.size(); i++){
//                 char org = word[i];
//                 for(char ch = 'a'; ch <='z'; ch++){
//                     word[i]= ch;
//                     if(st.find(word) != st.end()){
//                         st.erase(word);
//                         q.push({word,stp+1});
//                     }
//                 }
//                 word[i] = org;
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         queue<pair<string,int>> q;
//         q.push({beginWord,1});
//         set<string> st(wordList.begin(),wordList.end());
//         st.erase(beginWord);
//         while(!q.empty()){
//             string word = q.front().first;
//             int steps = q.front().second;
//             q.pop();
//             if(word == endWord) return steps;
//             //N x wordlength x 26 x logN
//             for(int i=0; i<word.size(); i++){
//                 char original = word[i];
//                 for(char ch='a'; ch<= 'z'; ch++){
//                     word[i] = ch;
//                     // it exists in the set
//                     if(st.find(word) != st.end()){
//                         st.erase(word);
//                         q.push({word,steps+1});
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int ladderLength(string bg, string ed, vector<string>& s) {
//     int  n =  s.size();
//     queue<pair<string,int>>q;
//     q.push({bg,1});
//     int c =2  ;
// unordered_set<string>ss(s.begin(),s.end());
//     ss.erase(bg);
//    while(!q.empty())
//       {
//           string word = q.front().first;
//             int steps  =  q.front().second;
//        q.pop();
//          for (int i = 0; i < word.size(); i++) {
//                 char org = word[i];
//                 for (char ch = 'a'; ch <= 'z'; ch++) {
//                     if (ch == org) continue;
//                     word[i] = ch;
//                     if (ss.count(word)) {
//                         if (word == ed)
//                             return steps + 1;
//                         q.push({word, steps + 1});
//                         ss.erase(word);  
//                     }
//                 }
//                 word[i] = org; 
//             }
//          }
//       return 0;    
//     }
// };

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set <string> dict(wordList.begin(),wordList.end());

//         if(dict.find(endWord) == dict.end()){
//             return 0;
//         }

//         unordered_set <string> head,tail;
//         head.insert(beginWord);
//         tail.insert(endWord);

//         int dist = 1;

//         while(!head.empty() && !tail.empty()){
//             if(head.size() > tail.size()){
//                 swap(head,tail);
//             }

//             unordered_set<string> temp;

//             for(string word: head){
//                 for(int i = 0 ; i < word.size() ; i++){
//                     char currentChar = word[i];
//                     for(char ch = 'a'; ch <= 'z' ; ch++){
//                         word[i] = ch;

//                         if(tail.find(word) != tail.end()){
//                             return dist+1;
//                         }

//                         if(dict.find(word) != dict.end()){
//                             temp.insert(word);
//                             dict.erase(word);
//                         }
//                     }
//                     word[i] = currentChar;
//                 }
//             }

//             head = temp;
//             dist++;
//         }

//         return 0;
//     }
// };



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set for O(1) lookups and tracking unvisited words
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        // Two frontiers
        unordered_set<string> forward_set, backward_set;
        forward_set.insert(beginWord);
        backward_set.insert(endWord);

        int steps = 1;

        while (!forward_set.empty() && !backward_set.empty()) {
            // Always expand the smaller set to minimize operations
            if (forward_set.size() > backward_set.size()) {
                swap(forward_set, backward_set);
            }

            unordered_set<string> next_set;

            for (string word : forward_set) {
                string original = word;
                for (int i = 0; i < word.size(); i++) {
                    char original_char = word[i];
                    
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original_char) continue;
                        word[i] = ch;

                        // If the sets meet, we found the shortest path
                        if (backward_set.find(word) != backward_set.end()) {
                            return steps + 1;
                        }

                        // If it's a valid unvisited word in the dictionary
                        if (dict.find(word) != dict.end()) {
                            next_set.insert(word);
                            dict.erase(word); // Mark as visited
                        }
                    }
                    word[i] = original_char; // Undo change
                }
            }

            // Move to the next level
            forward_set = move(next_set);
            steps++;
        }

        return 0;
    }
};