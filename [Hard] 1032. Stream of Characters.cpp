/*
Implement the StreamChecker class as follows:
	StreamChecker(words) : Constructor, init the data structure with the given words.
	query(letter): returns true if and only if for some k >= 1, the last k characters queried 
	(in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

Example:

	StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]); // init the dictionary.
	streamChecker.query('a');          // return false
	streamChecker.query('b');          // return false
	streamChecker.query('c');          // return false
	streamChecker.query('d');          // return true, because 'cd' is in the wordlist
	streamChecker.query('e');          // return false
	streamChecker.query('f');          // return true, because 'f' is in the wordlist
	streamChecker.query('g');          // return false
	streamChecker.query('h');          // return false
	streamChecker.query('i');          // return false
	streamChecker.query('j');          // return false
	streamChecker.query('k');          // return false
	streamChecker.query('l');          // return true, because 'kl' is in the wordlist

Note:

	1 <= words.length <= 2000
	1 <= words[i].length <= 2000
	Words will only consist of lowercase English letters.
	Queries will only consist of lowercase English letters. 
	The number of queries is at most 40000. */


class StreamChecker {
public:
	StreamChecker(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
			string temp = words[i];
			temp = "";
			for (int j = 0; j < words[i].size(); j++) {
				temp += words[i][j];
				if (j != words[i].size() - 1) dict[temp] = true;
				if (j == words[i].size() - 1) last[temp] = true;
			}
		}
	}

	bool query(char letter) {
		string b = "";
		b += letter;
		bool found = false;
		int n = cur.size();
		for (int i = 0; i < n; i++) {
			string temp = cur.front();
			cur.pop();
			temp += b;
			if (last[temp] == true) found = true;
			if (dict[temp] == true) cur.push(temp);
		}
		if (last[b] == true) found = true;
		if (dict[b] == true) cur.push(b);
		return found;
	}
private:
	unordered_map<string, bool> dict;
	unordered_map<string, bool> last;
	queue<string> cur;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
