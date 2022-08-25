#pragma once
#include <iostream>
#include "Header.h"

using namespace std;

const int Array_Size = 8;

template <class itemtype>
struct Chunk
{
	itemtype List[Array_Size];
	int size;
	Chunk* next;
};

template <class itemtype>
class ChunkList
{
	Chunk<itemtype>* head;
	Chunk<itemtype>* tail;
	int size;
public:
	 ChunkList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;

	}

	 /* Precondition: value is added to
	 the head
	 */

	 /* Postcondition: value is added to the
	 tail */

	void Append(ItemT elem)
	{
		// Initally creates new chunk list
		if (head == nullptr)
		{
			head = new Chunk<itemtype>;
			head->size = 0;
			head->List[head->size++] = elem;
			tail = new Chunk<itemtype>;
			tail->size = 0;
			tail->List[tail->size++] = elem;
			head->next = tail;
		}
		// Puts elements in as long as size is not big
		else if (tail->size < Array_Size)
		{
			tail->List[tail->size++] = elem;
		}
		// Creates new chunk if size too big
		else
		{
			Chunk<itemtype>* NewChunk = new Chunk <itemtype>;
			NewChunk->size = 0;
			NewChunk->List[NewChunk->size++] = elem;
			tail->next = NewChunk;
			tail = tail->next;
		}
		// Tail is no longer retrieving next item
		tail->next = nullptr;
		size++;
	}

	// Precondition: List is present
	// Postcondition: List size is returned

	int GetLength()
	{
		return size;
	}

	// Precondition: integer exists in array
	/* Postcondition: item is returned,
	if item is not found return not found */
	int GetIndex(int i)
	{
		int count = 1;
		Chunk<itemtype>* N = head->next;
		while (N != nullptr)
		{
			for (int k = 0; k < N->size; k++)
			{
				if (count == i)
				{
					return N->List[k];
				}
				count += 1;
			}
			N = N->next;
		}
		return -1;
	}

	/* Precondition: Item exists in array */
	/* Postcondition: return true, else if item
	is not found return false */
	bool Contains(ItemT elem)
	{
		Chunk <itemtype>* N = head->next;
		while (N != nullptr)
		{
			for (int k = 0; k < N->size; k++)
			{
				if (N->List[k] == elem)
				{
					return true;
				}
			}
			N = N->next;
		}
		return false;
	}

	/* Precondition: List is present
	and linked by head and tail with next */
	/* Postcondition: List is printed with
	chunk number and items */
	void Print(ostream &out)
	{
		int count = 1;
		Chunk<itemtype>* N = head->next;
		while (N != nullptr)
		{
			out << "Chunk#" << " " << count << ": ";
			for (int k = 0; k<N->size; k++)
			{
				out << N->List[k] << " ";
			}
			out << endl;
			count++;
			N = N->next;
		}

	}

	/* Precondition: Check if item is in array */
	/* Postcondition: Item is no longer in array
	and list is smaller, return false if item isn't found */
	bool Remove(ItemT elem)
	{
		bool x = false;
		Chunk<itemtype>* temp = head->next;
		while (temp != nullptr)
		{
			for (int i = 0; i < temp->size; i++)
			{
				if (temp->List[i] == elem)
				{
					for (int k = i; k < temp->size; k++)
					{
						temp->List[k] = temp->List[k + 1];
						temp->size--;
						size-=1;
						x = true;
					}
				}
			}
			temp = temp->next;
		}
		return x;
	}

	// Precondition: Size is checked
	// Postcondition: Return true if
	// there are no items else return false
	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

};
