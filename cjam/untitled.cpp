#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

string getParentheses(const string& s) {
	string ans;
	int open_count = 0;
	for (auto ch : s) {
		while (open_count < ch) {
			ans += '(';
			open_count++;
		}
		while (open_count > ch) {
			ans += ')';
			open_count--;
		}
		ans += ch;
	}
	return ans;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cin >> n;
        string str;
        cin >> str;
        string ans = getParentheses(str);
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
}
