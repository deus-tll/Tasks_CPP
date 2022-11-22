//You are given two non - empty linked lists representing two non - negative integers
//The digits are stored in reverse order, and each of their nodes contains a single digit.
//Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#include<iostream>


struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution
{
	void Adding(ListNode* cur, ListNode* l1, ListNode* l2)
	{
		ListNode* tmp_l1 = l1;
		ListNode* tmp_l2 = l2;

		int val;
		int n1;
		int n2;
		int tmp;

		bool additional_digit = false;

		while (tmp_l1 != nullptr || tmp_l2 != nullptr)
		{
			n1 = tmp_l1 ? tmp_l1->val : 0;
			n2 = tmp_l2 ? tmp_l2->val : 0;

			val = n1 + n2;

			if (val <= 9 && val >= 0 )
			{
				tmp = !additional_digit ? val : val + 1;
				
				if (tmp == 10)
				{
					cur->val = 0;
					additional_digit = true;
				}
				else
				{
					cur->val = tmp;
					additional_digit = false;
				}
			}
			else if(val == 10)
			{
				cur->val = additional_digit ? 1 : 0;
				additional_digit = true;
			}
			else
			{
				cur->val = additional_digit ? (val % 10) + 1 : val % 10;
				additional_digit = true;
			}

			if(tmp_l1 != nullptr) tmp_l1 = tmp_l1->next;

			if(tmp_l2 != nullptr) tmp_l2 = tmp_l2->next;

			if (tmp_l1 != nullptr || tmp_l2 != nullptr)
			{
				cur->next = new ListNode();
				cur = cur->next;
			}

			cur->next = (tmp_l1 == nullptr && tmp_l2 == nullptr) && additional_digit ? new ListNode(1) : nullptr ;
		}

	}
public:
	ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* res_l = new ListNode();
		ListNode* cur = res_l;

		Adding(cur, l1, l2);
		
		return res_l;
	}
};

void Show(ListNode* l)
{
	ListNode* tmp = l;
	while (tmp != nullptr)
	{
		std::cout << tmp->val << std::endl;
		tmp = tmp->next;
	}
}

int main()
{
	ListNode* firstNumber_l2 = new ListNode(6);
	ListNode* firstNumber_l1 = new ListNode(5, firstNumber_l2);
	
	ListNode* secondNumber_l3 = new ListNode(9);
	ListNode* secondNumber_l2 = new ListNode(4, secondNumber_l3);
	ListNode* secondNumber_l1 = new ListNode(5, secondNumber_l2);

	Solution solution;
	ListNode* result = solution.AddTwoNumbers(firstNumber_l1, secondNumber_l1);
	Show(result);

	return 0;
}