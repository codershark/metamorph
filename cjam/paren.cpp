#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <stdlib.h> 

using namespace std;

string getParentheses(const string& s) {
	string ans;
	int open_count = 0;
	for (char ch : s) {
		int d = ch - '0';
		while (open_count < d) {
			ans += '(';
			open_count++;
		}
		while (open_count > d) {
			ans += ')';
			open_count--;
		}
		ans += ch;
	}
	while (open_count) {
		ans += ')';
		open_count--;
	}

	return ans;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        string str;
        cin >> str;
        string ans = getParentheses(str);
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
}
