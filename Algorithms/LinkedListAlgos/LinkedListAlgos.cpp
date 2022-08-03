#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LinkedListNode {
	int data;
	LinkedListNode* next;
	LinkedListNode* arbitrary_pointer;
	LinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};

class LinkedList {
public:
	LinkedListNode* head;

	LinkedList() { head = nullptr; }

	void InsertAtHead(int data) {
		if (head == nullptr) {
			head = new LinkedListNode(data);
		}
		else {
			LinkedListNode* new_node = new LinkedListNode(data);
			new_node->next = head;
			head = new_node;
		}
	}

	void InsertAtTail(int data) {
		if (head == nullptr) {
			head = new LinkedListNode(data);
		}
		else {
			LinkedListNode* new_node = new LinkedListNode(data);
			LinkedListNode* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void CreateLinkedList(vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}

	void DisplayList() {
		LinkedListNode* temp = head;
		string result = "[";
		while (temp != nullptr) {
			result += to_string(temp->data);
			temp = temp->next;
			if (temp != nullptr) {
				result += ", ";
			}
		}
		cout << result << "]";
	}

	LinkedListNode* Reverse(LinkedListNode* head) {
		LinkedListNode* Prev = nullptr, * Next = nullptr;
		while (head)
		{
			Next = head->next;
			head->next = Prev;
			Prev = head;
			head = Next;
		}
		head = Prev;
		return head;
	}

	//LinkedListNode* DeleteNode(LinkedListNode* head, int key) {
	//	LinkedListNode* prev;
	//	LinkedListNode* curr = head;
	//	while (curr->data == key)
	//	{
	//		prev = curr;
	//		curr = curr->next;
	//		delete prev;
	//		head = curr;
	//	}
	//	while (curr->next)
	//	{
	//		if (curr->next->data == key)
	//		{
	//			prev = curr->next;
	//			curr->next = curr->next->next;
	//			delete prev;
	//		}
	//		curr = curr->next;
	//	}
	//	return head;
	//}

	LinkedListNode* SwapNthNode(LinkedListNode* head, int n) {
		LinkedListNode* curr = head;
		for (int i = 1; i < n; ++i)
		{
			if (!curr->next)
			{
				curr = head;
				break;
			}
			curr = curr->next;
		}
		int temp = head->data;
		head->data = curr->data;
		curr->data = temp;
		return head;
	}
};

int main()
{
	vector<int> a = { 4, 8, 15, 19, 22 };
	vector<int> b = { 7, 9, 10, 16 };
	LinkedList dels;
	dels.DisplayList();
}