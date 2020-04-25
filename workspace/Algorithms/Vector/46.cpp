#include"vector_func.h"

// 46. х╚ееап
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	queue<vector<int>> Q;
	Q.push({ nums[0] });
	int index = 1;
	while (index < nums.size()) {
		while (!Q.empty() && Q.front().size() == index) {
			vector<int> tmp = Q.front();
			int size = tmp.size();
			for (int i = 0; i <= size; i++) {
				tmp = Q.front();
				tmp.insert(tmp.begin() + i, nums[index]);
				if (index == nums.size() - 1) {
					res.push_back(tmp);
				}
				else {
					Q.push(tmp);
				}
			}
			Q.pop();
		}
		index++;
	}
	return res;
}