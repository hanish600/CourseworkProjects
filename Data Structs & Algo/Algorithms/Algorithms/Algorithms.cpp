#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int BinarySearch(int nums[], int target, int length)
{
	int low = 0, mid = 0, high = length - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == nums[mid]) { return mid; }
		else if (nums[mid] > target) { high = mid - 1; }
		else { low = mid + 1; }
	}
	return -1;
}

void reverse(vector<int>& nums, int start, int end)
{
	while (start <= end)
	{
		int temp = nums[end];
		nums[end] = nums[start];
		nums[start] = temp;
		++start;
		--end;
	}
}

void rotateArrayOptimal(vector<int>& nums, int n)
{
	// turn n to positive shift
	n = n % nums.size();
	if (n < 0)
	{
		n += nums.size();
	}
	// reverse from 0 to length
	reverse(nums, 0, nums.size() - 1);
	// reverse left portion
	reverse(nums, 0, n - 1);
	// reverse right portion
	reverse(nums, n, nums.size() - 1);
}

int GetFibonacci(int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	int first = 0, second = 1, sum = -1;
	--n;
	for (int i = 0; i < n; ++i)
	{
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

class StackUsingQueue
{
public:
	queue<int> queue1;

	void Push(int data) {
		int n = queue1.size();
		queue1.push(data);
		for (int i = 0; i < n; ++i)
		{
			queue1.push(queue1.front());
			queue1.pop();
		}
	}

	bool IsEmpty() {
		if (queue1.empty()) { return true; }
		return false;
	}

	int Pop() {
		if (!queue1.empty()) {
			int top = queue1.front();
			queue1.pop();
			return top;
		}
		return -1;
	}
};

class QueueUsingStack {
public:
	stack<int> stack1;

	stack<int> stacktoqueue(stack<int> s, int data, int n)
	{
		stack<int> stack2;
		for (int i = 0; i < n; ++i)
		{
			stack2.push(s.top());
			s.pop();
		}
		s.push(data);
		while (!stack2.empty())
		{
			s.push(stack2.top());
			stack2.pop();
		}
		return s;
	}

	void Enqueue(int data) {
		int n = stack1.size();
		if (n == 0)
		{
			stack1.push(data);
		}
		else
		{
			stack1 = stacktoqueue(stack1, data, n);
		}
	}

	bool IsEmpty() {
		if (stack1.empty()) { return true; }
		return false;
	}

	int Dequeue() {
		if (!stack1.empty()) {
			int front = stack1.top();
			stack1.pop();
			return front;
		}
		return -1;
	}
};

int BinarySearchRotated(vector<int>& nums, int target) {
	int low = 0, high = nums.size() - 1, mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == nums[mid])
		{
			return mid;
		}
		// case 1 mid is on left side of rotation
		if (nums[mid] >= nums[low])
		{
			if (target <= nums[mid] and target >= nums[low])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		// case 2 mid is on right side of rotation
		else
		{
			if (target >= nums[mid] and target <= nums[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}

bool IsNumberValid(const string s) {
	int dotCount = 0;
	bool valid = true;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!isdigit((s[i])) and s[i] != '.' and s[0] != '-' and s[0] != '+')
		{
			valid = false;
			break;
		}
		if (s[i] == '.')
		{
			++dotCount;
		}
		if (dotCount > 1)
		{
			valid = false;
			break;
		}
	}
	return valid;
}

int FindLeastCommonNumber(vector<int>& arr1, vector<int>& arr2,
	vector<int>& arr3) {
	int i = 0, j = 0, k = 0;
	if (arr1.size() == 0 || arr2.size() == 0 || arr3.size() == 0)
	{
		return -1;
	}
	int lowest = arr1[0];
	while (i < arr1.size() && j < arr2.size() && k < arr3.size())
	{
		if (arr1[i] == arr2[j] && arr1[i] == arr3[k])
		{
			return arr1[i];
		}
		if (arr2[j] < arr1[i])
		{
			++j;
		}
		if (arr3[k] < arr1[i])
		{
			++k;
		}
		if (arr1[i] < arr2[j] || arr1[i] < arr3[k])
		{
			++i;
		}
	}
	return -1;
}

bool containsDuplicate(vector<int>& nums) {
	if (nums.size() <= 1)
	{
		return false;
	}
	set<int> duplicates;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (duplicates.find(nums[i]) != duplicates.end())
		{
			return true;
		}
		duplicates.insert(nums[i]);
	}
	return false;
}

int main()
{
	
}