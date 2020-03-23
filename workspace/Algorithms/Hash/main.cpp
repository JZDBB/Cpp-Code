#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// TwoSum
vector<int> twoSum(vector<int>& nums, int target) {
	// 蛮力
	/*for (int i = 0; i < nums.size(); i++) {
		int diff = target - nums[i];
		for (int j = i+1; j < nums.size(); j++) {
			if ((j != i) && (nums[j] == diff)) return { i, j };
		}
	}*/

	// 哈希
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(target - nums[i]) != m.end()) return { m[target - nums[i]], i };
		m[nums[i]] = i;
	}
	
	return {};
}

// 和为K的子数组
int subarraySum(vector<int>& nums, int k) {
	// 蛮力
	/*int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		int sum = nums[i];
		if (sum == k) count++;
		for (int j = i+1; j < nums.size(); j++) {
			sum += nums[j];
			if (sum == k) count++;
		}
	}*/

	// 哈希
	int count = 0;
	int sum = 0;
	unordered_map<int, int> m;
	m[0] = 1;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (m.find(sum - k) != m.end()) count += m[sum - k];
		m[sum] ++;
	}
	return count;
}


int main() {
	
	int a[9] = { 1, 1, 1, -1, 0, 1, 2, 1};
	vector<int> nums(a, a + 8);
	int i = subarraySum(nums, 2);

	return 0;
}