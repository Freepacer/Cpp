/*
On an infinite number line, the position of the i-th stone is given by stones[i].  Call a stone an endpoint stone if it has the smallest or largest position.
Each turn, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
When the game ends, what is the minimum and maximum number of moves that you could have made?  Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]

Example 1:
	Input: [7,4,9]
	Output: [1,2]
	Explanation:
	We can move 4 -> 8 for one move to finish the game.
	Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.

Example 2:
	Input: [6,5,4,3,10]
	Output: [2,3]
	We can move 3 -> 8 then 10 -> 7 to finish the game.
	Or, we can move 3 -> 7, 4 -> 8, 5 -> 9 to finish the game.
	Notice we cannot move 10 -> 2 to finish the game, because that would be an illegal move.

Example 3:
	Input: [100,101,104,102,103]
	Output: [0,0]

Note:
	1. 3 <= stones.length <= 10^4
	2. 1 <= stones[i] <= 10^9
	3. stones[i] have distinct values.
*/

class Solution {
public:
	static const int INF = 1e9 + 5;

	vector<int> numMovesStonesII(vector<int>& stones) {
		sort(stones.begin(), stones.end());
		int n = stones.size();
		int least = INF, most = -INF;

		for (int i = 0, j = 0; i < n; i++) {
			while (j + 1 < n && stones[j + 1] - stones[i] < n)
				j++;

			int now = n - (j - i + 1);

			if (j - i == n - 2 && stones[j] - stones[i] == j - i)
				now++;
			cout << i << " " << now << endl;
			least = min(least, now);
		}

		most = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - (n - 2);
		return { least, most };
	}
};