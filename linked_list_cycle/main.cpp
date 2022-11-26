//Given head, the head of a linked list, determine if the linked list has a cycle in it.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

//Return true if there is a cycle in the linked list.Otherwise, return false.

#include<vector>
#include<unordered_map>

struct ListNode 
{
	  int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(nullptr) {}
};
 

class Solution {
public:
	bool hasCycle(ListNode* head)
	{
		if (head == nullptr) return false;

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
				return true;
		}

		return false;
	}
};


int main()
{
	ListNode* l5 = new ListNode(5);
	ListNode* l4 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	ListNode* l2 = new ListNode(2);
	ListNode* l1 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution solution;

	solution.hasCycle(l1);

	return 0;
}