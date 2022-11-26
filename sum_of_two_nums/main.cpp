//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

#include<vector>
#include<unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> storage{};
		std::vector<int> result(2, 0);

		for (int it{ 0 }; it < nums.size(); ++it) 
		{
			if (storage.find(target - nums.at(it)) != storage.end()) 
			{
				result.at(0) = storage.at(target - nums.at(it));
				result.at(1) = it;
				break;
			}
			else 
			{
				storage[nums.at(it)] = it;
			}
		}

		return result;
	}
};


int main()
{
	Solution solution;

	std::vector<int> v{ 11, 2, 15, 7 };

	std::vector<int> res = solution.twoSum(v, 9);

	return 0;
}