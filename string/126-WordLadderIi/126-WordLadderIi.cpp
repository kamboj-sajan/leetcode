// Last updated: 19/08/2026, 16:07:54
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord,
//                                        vector<string>& wordList) {

//         unordered_set<string> st(wordList.begin(), wordList.end());

//         vector<vector<string>> ans;

//         if (!st.count(endWord))
//             return ans;

//         queue<vector<string>> q;
//         q.push({beginWord});

//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);

//         int level = 1;

//         while (!q.empty()) {

//             vector<string> path = q.front();
//             q.pop();

//             if (path.size() > level) {

//                 level = path.size();

//                 for (auto &x : usedOnLevel)
//                     st.erase(x);

//                 usedOnLevel.clear();

//                 if (!ans.empty() && level > ans[0].size())
//                     break;
//             }

//             string word = path.back();

//             if (word == endWord) {

//                 if (ans.empty())
//                     ans.push_back(path);

//                 else if (path.size() == ans[0].size())
//                     ans.push_back(path);

//                 continue;
//             }

//             for (int i = 0; i < word.size(); i++) {

//                 char org = word[i];

//                 for (char ch = 'a'; ch <= 'z'; ch++) {

//                     word[i] = ch;

//                     if (st.count(word)) {

//                         path.push_back(word);
//                         q.push(path);
//                         path.pop_back();

//                         usedOnLevel.push_back(word);
//                     }
//                 }

//                 word[i] = org;
//             }
//         }

//         return ans;
//     }
// };


/*
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> st(wordList.begin(),wordList.end());
      queue<vector<string>> q;
      q.push({beginWord});
      vector<string> usedonlevel;
      usedonlevel.push_back(beginWord);
      int level = 0;
      vector<vector<string>> ans;
      while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        //erase all words that has been used in the previous levels to transform
        if(vec.size() > level){
            level++;
            for(auto it : usedonlevel){
                st.erase(it);
            }
            usedonlevel.clear();
        }

        string word = vec.back();
        //store the answers
        if(word == endWord){
            //the first sequence where we reached end
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }
        // wordlength = 26
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char c='a'; c<='z'; c++){
                word[i] = c;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level
                    usedonlevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
      }
      return ans;  
    }
};
*/

/*
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        
        if (!st.count(endWord)) return ans; // Early exit if endWord not present

        queue<vector<string>> q;
        q.push({beginWord});
        
        unordered_set<string> usedonlevel;
        int level = 0;
        
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            // New level reached
            if (vec.size() > level) {
                level++;
                for (const string& w : usedonlevel) {
                    st.erase(w);
                }
                usedonlevel.clear();
            }
            
            string word = vec.back();
            
            // Found valid transformation sequence
            if (word == endWord) {
                if (ans.empty() || ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
                continue; // Don't explore further from endWord
            }

            // Try changing every character
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (st.count(word)) {
                        vec.push_back(word);
                        q.push(vec);
                        usedonlevel.insert(word);  // use set instead of vector
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        // For backtracking
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currLevel, nextLevel;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            currLevel.clear();
            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();
                string orig = word;
                for (int j = 0; j < word.size(); ++j) {
                    char ch = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (dict.count(word) && !visited.count(word)) {
                            if (word == endWord) found = true;
                            if (!currLevel.count(word)) {
                                q.push(word);
                                currLevel.insert(word);
                            }
                            parents[word].push_back(orig);
                        }
                    }
                    word[j] = ch;
                }
            }
            for (const string& w : currLevel) visited.insert(w);
        }

        // Backtrack from endWord to beginWord
        vector<string> path;
        function<void(string)> dfs = [&](string word) {
            path.push_back(word);
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            } else {
                for (const string& p : parents[word]) {
                    dfs(p);
                }
            }
            path.pop_back();
        };

        if (found) dfs(endWord);
        return res;
    }
};


