//Given a signed 32-bit integer x, return x with its digits reversed.
//If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include<iostream>


class Solution {
public:
	int Reverse(int x) {
		int upper_limit = INT_MAX;
		int lower_limit = INT_MIN;
		int result = 0;

		while (x != 0)
		{
			if ((upper_limit / 10 < result) ||
				(upper_limit / 10 == result && x % 10 > upper_limit % 10))
				return 0;

			if ((lower_limit / 10 > result) ||
				(lower_limit / 10 == result && x % 10 < lower_limit % 10))
				return 0;


			result = result * 10 + x % 10;
			x /= 10;
		}

		return result;
	}
};

int main()
{
	Solution solution;

	solution.Reverse(23);
	return 0;
}