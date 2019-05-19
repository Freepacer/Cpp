/*
Given a list of words, each word consists of English lowercase letters.
Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".
A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:
	Input: ["a","b","ba","bca","bda","bdca"]
	Output: 4
	Explanation: one of the longest word chain is "a","ba","bda","bdca".

Note:
	1. 1 <= words.length <= 1000
	2. 1 <= words[i].length <= 16
	3. words[i] only consists of English lowercase letters.
*/

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		int n = words.size();
		vector<int> dp(n, 1);
		sort(words.begin(), words.end(), [](string & a, string & b) {return (a.size() != b.size()) ? a.size() < b.size() : a < b; });
		map<int, map<char, int>> temp;
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				temp[i][words[i][j]]++;
			}
		}
		int res = 0;
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (words[i].size() != words[j].size() + 1) continue;
				auto t = temp[i];
				bool con = false;
				for (int k = 0; k < words[j].size(); k++) {
					if (!t.count(words[j][k])) {
						con = true;
						break;
					}
					t[words[j][k]]--;
					if (t[words[j][k]] == 0) t.erase(words[j][k]);
				}
				if (!con && t.size() == 1 && t.begin()->second == 1) dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};