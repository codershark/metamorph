// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given an input string, reverse the string word by word.
* 
* Example 1:
* 
* Input: "the sky is blue"
* Output: "blue is sky the"
*               
**********************************************************************************/


class Solution {
public:
    void trimString(string& s) {
        int pos = 0;
        char last = ' ';
        for (int i = 0; i < s.size(); ++i) {
            if (last == ' ' && s[i] == ' ')
                continue;
            s[pos++] = s[i];
            last = s[i];
        }
        if (s[pos - 1] == ' ')
            --pos;
        s.resize(pos);
    }
    string reverseWords(string s) {
        trimString(s);
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                end = i;
                reverse(s.begin() + start, s.begin() + end);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
