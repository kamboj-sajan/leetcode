// Last updated: 19/08/2026, 15:57:30
class Solution {
public:
    string makeLargestSpecial(string s) {
       vector<string> parts;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // found a special substring
            if (count == 0) {
                // recursively process inside
                string inner =
                    makeLargestSpecial(s.substr(start + 1, i - start - 1));

                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // sort descending for lexicographically largest
        sort(parts.begin(), parts.end(), greater<string>());

        string result;
        for (auto &p : parts)
            result += p;

        return result; 
    }
};