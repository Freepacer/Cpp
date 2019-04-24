/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. 
(We may insert each character at any position, and may insert 0 characters.)
Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true ifand only if queries[i] matches the pattern.

Example 1:
	Input: queries = ["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], pattern = "FB"
	Output : [true, false, true, true, false]
	Explanation :
	"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
	"FootBall" can be generated like this "F" + "oot" + "B" + "all".
	"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2 :
	Input : queries = ["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], pattern = "FoBa"
	Output : [true, false, true, false, false]
	Explanation :
	"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
	"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Example 3 :
	Input : queries = ["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], pattern = "FoBaT"
	Output : [false, true, false, false, false]
	Explanation :
	"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".


Note :
	1 <= queries.length <= 100
	1 <= queries[i].length <= 100
	1 <= pattern.length <= 100
	All strings consists only of lower and upper case English letters.
*/

class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector <bool> res;
		for (int i = 0; i < queries.size(); i++) {
			res.push_back(helper(queries[i], pattern));
		}
		return res;
	}

	bool helper(string a, string b) {
		int j = 0;
		int temp = 0;
		for (int i = 0; i < a.size(); i++) {
			if (j == b.size()) {
				break;
			}
			while (a[i] != b[j] && i < a.size())
			{
				if (a[i] >= 'A' && a[i] <= 'Z') return false;
				i++;
			}
			if (i == a.size()) return false;
			j++;
			temp = i;
		}
		if (j < b.size()) return false;
		for (int i = temp + 1; i < a.size(); i++) {
			if (a[i] >= 'A' && a[i] <= 'Z') return false;
		}
		return true;
	}
};