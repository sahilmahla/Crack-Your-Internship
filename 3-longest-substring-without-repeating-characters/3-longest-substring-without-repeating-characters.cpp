class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> seen;
	int left = 0;
	int right = 0;
	int res = 0;
	for (; right < s.size(); ++right) {
		if (seen.count(s[right])) {
			left = max(left, seen[s[right]]+1);
		}
		seen[s[right]] = right;
		res = max(res, right-left+1);
	}
	return res;
    }
};