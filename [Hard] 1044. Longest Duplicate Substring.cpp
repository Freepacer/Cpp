/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

Example 1:
	Input: "banana"
	Output: "ana"

Example 2:
	Input: "abcd"
	Output: ""

Note:
	1. 2 <= S.length <= 10^5
	2. S consists of lowercase English letters.
*/

class Solution {
public:
	int getcommon(int i, int j, string& s)
	{
		int k = 0;
		while (i + k < s.size() && j + k < s.size() && s[i + k] == s[j + k])
			k++;
		return k;
	}

	string longestDupSubstring(string s) {
		int n = s.size();
		bool same = true;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != s[0])
			{
				same = false;
				break;
			}
		}
		if (same) return s.substr(1);
		auto cmp = [&](int i, int j) {
			int k = 0;
			while (i + k < n && j + k < n)
			{
				if (s[i + k] == s[j + k]) k++;
				else return s[i + k] < s[j + k];
			}
			if (j + k < n) return true;
			return false;
		};
		vector<int> suff(n);
		for (int i = 0; i < n; ++i)
		{
			suff[i] = i;
		}
		sort(suff.begin(), suff.end(), cmp);

		int len = 0;
		int pos = 0;
		for (int i = 0; i + 1 < n; ++i)
		{
			int cur = getcommon(suff[i], suff[i + 1], s);
			if (cur > len)
			{
				len = cur;
				pos = suff[i];
			}
		}
		return s.substr(pos, len);
	}
};