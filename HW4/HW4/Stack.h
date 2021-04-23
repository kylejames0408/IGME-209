#pragma once
#include <iostream>

using namespace std;

template <class IncomingClass>
class Stack
{
private:
	IncomingClass removedItem;
	IncomingClass** stackArray;
	int stackCount;
	int stackSize;

public:
	/// <summary>
	/// Default Stack constructor.
	/// </summary>
	Stack()
	{
		// Initialize fields.
		stackCount = 0;
		stackSize = 4;
		stackArray = new IncomingClass*[stackSize];
	};

	/// <summary>
	/// Stack copy constructor.
	/// </summary>
	/// <param name="other">The other Stack to copy.</param>
	Stack(const Stack& other)
	{
		// Create a new array and copy over all of the elements from other to have two identical arrays in different spots.
		stackCount = other.stackCount;
		stackSize = other.stackSize;
		stackArray = new IncomingClass*[stackSize];

		// Save a reference to the Stack array's data
		IncomingClass* transferStackArray = new IncomingClass[stackSize];

		// Copy over current data to the transfer Stack array
		for (int i = 0; i < stackCount; i++)
		{
			transferStackArray[i] = *other.stackArray[i];
		}

		// Copy over the data to the Stack array
		for (int i = 0; i < stackSize; i++)
		{
			stackArray[i] = new IncomingClass(transferStackArray[i]);
		}

		// Clean up temporary heap data
		delete[] transferStackArray;
		transferStackArray = nullptr;
	};

	/// <summary>
	/// Stack copy assignment constructor.
	/// </summary>
	/// <param name="other">The other Stack to copy.</param>
	/// <returns>Returns a Stack reference.</returns>
	Stack& operator =(const Stack& other)
	{
		// If we are trying to set something equal to itself.
		if (this == &other)
		{
			// Return the current Stack and store it back in itself.
			return *this;
		}

		// If the Stack is already set up.
		if (stackArray != nullptr)
		{
			// Delete the Stack array's items to prevent memory leaks.
			for (int i = 0; i < stackCount; i++)
			{
				delete stackArray[i];
				stackArray[i] = nullptr;
			}

			// Delete the Stack array to prevent memory leaks.
			delete[] stackArray;
			stackArray = nullptr;
		}

		// Create a new array and copy over all of the elements from other to have two identical arrays in different spots.
		stackCount = other.stackCount;
		stackSize = other.stackSize;
		stackArray = new IncomingClass*[stackSize];

		// Save a reference to the Stack array's data
		IncomingClass* transferStackArray = new IncomingClass[stackSize];

		// Copy over current data to the transfer Stack array
		for (int i = 0; i < stackCount; i++)
		{
			transferStackArray[i] = *other.stackArray[i];
		}

		// Copy over the data to the Stack array
		for (int i = 0; i < stackSize; i++)
		{
			stackArray[i] = new IncomingClass(transferStackArray[i]);
		}

		// Clean up temporary heap data
		delete[] transferStackArray;
		transferStackArray = nullptr;

		return *this;
	};

	/// <summary>
	/// Stack destructor.
	/// </summary>
	~Stack()
	{
		// Delete the Stack array's items to prevent memory leaks.
		for (int i = 0; i < stackSize; i++)
		{
			//delete stackArray[i];
			//stackArray[i] = nullptr;
		}

		// Clean up the heap memory Stack array
		delete[] stackArray;
		stackArray = nullptr;
	};

	/// <summary>
	/// Add information to the Stack.
	/// </summary>
	/// <param name="data">The data to add to the Stack as a reference.</param>
	void Push(IncomingClass* data)
	{
		// If there is room in the Stack array
		if (stackCount < stackSize)
		{
			// Add the data to the end of the Stack array
			stackArray[stackCount] = data;

			// Increment the item count
			stackCount++;
		}
		// If there is no room in the Stack array
		else
		{
			// Save a reference to the Stack array's data
			IncomingClass* smallStackArray = new IncomingClass[stackSize];

			// Copy over current data to the small Stack array
			for (int i = 0; i < stackSize; i++)
			{
				smallStackArray[i] = *stackArray[i];

				// Clear old data
				delete stackArray[i];
				stackArray[i] = nullptr;
			}

			// Clear old data
			delete[] stackArray;
			stackArray = nullptr;
			
			// Double the Stack array's size
			stackSize *= 2;

			// Create a new Stack array
			stackArray = new IncomingClass*[stackSize];

			// Copy over the small Stack array to the new larger array
			for (int i = 0; i < stackCount; i++)
			{
				stackArray[i] = new IncomingClass(smallStackArray[i]);
			}

			// Clear up the old heap data
			delete[] smallStackArray;
			smallStackArray = nullptr;

			// Call push again to add the data
			Push(data);
		}
	};

	/// <summary>
	/// Removes the top-most data from the Stack.
	/// </summary>
	/// <returns>The top-most data in the Stack as a reference.</returns>
	IncomingClass* Pop()
	{
		// If the Stack array has items in it.
		if (!IsEmpty())
		{
			// Track the item to be removed.
			removedItem = *stackArray[stackCount - 1];

			// Set the spot of the item to be NULL.
			delete stackArray[stackCount - 1];
			stackArray[stackCount - 1] = nullptr;
			
			// Decrement the count
			stackCount--;

			// Return the removed item.
			return &removedItem;
		}
		
		// If the Stack array is empty, return NULL.
		return nullptr;
	};

	/// <summary>
	/// Prints all of the elements in the Stack.
	/// </summary>
	void Print()
	{
		// Loop through the Stack array.
		for (int i = 0; i < stackCount; i++)
		{
			// Print out the item at each location.
			cout << *stackArray[i] << " ";
		}

		// End the line.
		cout << endl;
	};

	/// <summary>
	/// Gets the count of the Stack.
	/// </summary>
	/// <returns>The number of items in the Stack.</returns>
	int GetSize()
	{
		return stackCount;
	};

	/// <summary>
	/// Gets whether or not the Stack is empty.
	/// </summary>
	/// <returns>True if the Stack is empty, false otherwise.</returns>
	bool IsEmpty()
	{
		// If the count is 0, there are no Stack items.
		return stackCount == 0;
	};
};