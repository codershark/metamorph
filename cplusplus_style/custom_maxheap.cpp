// Source : https://oj.leetcode.com/problems/sort-characters-by-frequency/
// Author : Sukriti
// Date   : 2020-03-01

class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> freq;
        auto comp = [](pair<char, int> a, pair<char, int> b) { return a.second < b.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> heap(comp);
        for (char ch : s) {
            freq[ch]++;
        }
        for (auto entry : freq) {
            heap.push(entry);
        }
        while (!heap.empty()) {
            auto temp = heap.top();
            heap.pop();
            while (temp.second) {
                ans.push_back(temp.first);
                temp.second--;
            }
        }
        return ans;
    }
};
