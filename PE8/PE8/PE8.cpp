// 1.1a - Includes, Using Statements, and Main
#include <iostream>
using namespace std;

#pragma region Function Declarations

// Function Declarations
#pragma region Part 1 Declarations

/// <summary>
/// Alters the value of the variable and prints out the new value.
/// </summary>
/// <param name="number">The integer variable to change.</param>
void changeVariable(int number);

/// <summary>
/// Alters the value of the data stored at the pointer.
/// </summary>
/// <param name="intPtr">The pointer with data to alter.</param>
void changePointer(int* intPtr);

#pragma endregion

#pragma region Part 2 Declarations

/// <summary>
/// A function which gets the number of elements before the terminator of an array.
/// </summary>
/// <param name="intArr">The array to get the length of.</param>
/// <returns>The number of elements before the terminator.</returns>
int getLengthArray(int intArr[]);

/// <summary>
/// A function which gets the number of elements before a terminator.
/// </summary>
/// <param name="intPtr">The pointer to get the length of.</param>
/// <returns>The number of elements before the terminator.</returns>
int getLengthPointer(int* intPtr);

#pragma endregion

#pragma region Part 3 Declarations

/// <summary>
/// Creates an array in the stack.
/// </summary>
/// <returns>An array in the stack.</returns>
int* createStackArray();

/// <summary>
/// Creates an array in the heap.
/// </summary>
/// <param name="size">The size of the array to create.</param>
/// <returns>An array in the heap.</returns>
int* createHeapArray(int size);

#pragma endregion

#pragma endregion

/// <summary>
/// The main function of the program.
/// </summary>
/// <returns>Console application.</returns>
int main()
{
    // PART 1
    cout << "=========================PART 1=========================" << endl;
    
    // 1.4
    // Create a value of chosen data type and give it an initial value
    int myInt = 10;

    // Print out the data in the variable
    cout << "myInt = " << myInt << endl;

    // Call changeVariable, passing in the variable
    changeVariable(myInt);

    // Print out the data in the variable
    cout << "myInt = " << myInt << endl;

    // Call changePointer(), passing in the address of the variable
    changePointer(&myInt);

    // Print out the data in the variable
    cout << "myInt = " << myInt << endl;

    // 1.5 - Describe in the comments of your code how these function differ in terms of altering the value of a variable:
    //  changeVariable() takes the "myInt" integer and effectively makes a temporary variable copy on the stack called "number."
    //  Within that function, it only changes the value of "number" and not the passed in "myInt."
    //  changePointer(), on the other hand, gets the location of "myInt" and changes the value at the address of "myInt."
    //  This effectively changes the value of "myInt" as it changed the value of the data stored at it's address.
    //  In conclusion, changeVariable() doesn't change the value of the integer outside of the function, but changePointer() does.

    // PART 2
    cout << "\n=========================PART 2=========================" << endl;
    
    // 2.2 - Set up an array of integers of a substantial length (at least seven). The last element in the array should be -1.
    //  Create a new integer pointer variable and set it equal to the array.
    int intArr[8] = { 1, 2, 3, 4, 5, 6, 7, -1 };
    int* intArrPtr = intArr;

    // 2.2a - Print out the results of passing the pointer into getLengthArray
    cout << "Results of passing intArrPtr to getLengthArray = " << getLengthArray(intArrPtr) << endl;

    // 2.4 - In main, call getLengthPointer and pass in the array as before. Print out the results and verify that both function work properly.
    cout << "Results of passing intArr to getLengthPointer = " << getLengthPointer(intArr) << endl;

    // PART 3
    cout << "\n=========================PART 3=========================" << endl;

    // 3.3 - In main, call both functions and store the results in separate pointers (you can pass in 5 for createHeapArray).
    //  Using those pointers, print out the contents of both arrays. Don't forget to delete[] your array from the heap!
    int* stackArray = createStackArray();
    int* heapArray = createHeapArray(5);

    // Print out the stack array
    cout << "Stack Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *stackArray + i;
        if (i != 4)
            cout << ", ";
    }

    // Print out the heap array
    cout << endl << "Heap Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *heapArray + i;
        if (i != 4)
            cout << ", ";
    }
    
    // End the line
    cout << endl;

    // Delete the heap array
    delete[] heapArray;
    heapArray = nullptr;

    // 3.4 - What do you notice about the array created on the stack? Why might this be? Put your answer in the comments below.
    //  The array created on the stack is referencing other data now stored in the stack since the stack array only needed
    //  referencing in the createStackArray() function. The system automatically cleaned up the data stored there since it
    //  shouldn't be in use anymore, whereas we are in control of the heap, and since we don't delete it until after we print
    //  the array, we are able to continue to access it.
}

#pragma region Functions

// Functions
#pragma region Part 1 Functions

/// <summary>
/// Alters the value of the variable and prints out the new value.
/// </summary>
/// <param name="number">The integer variable to change.</param>
void changeVariable(int number)
{
    // Add one to number
    number++;

    // Print out a message with the new value
    cout << "Inside changeVariable() - variable's value is now: " << number << endl;
}

/// <summary>
/// Alters the value of the data stored at the pointer.
/// </summary>
/// <param name="intPtr">The pointer with data to alter.</param>
void changePointer(int* intPtr)
{
    // Add one to the data at intPtr
    *intPtr = *intPtr + 1;

    // Print out a message with the new value
    cout << "Inside changePointer() - data's value is now: " << *intPtr << endl;
}

#pragma endregion

#pragma region Part 2 Functions

/// <summary>
/// A function which gets the number of elements before the terminator.
/// </summary>
/// <param name="intArr">The array to get the length of.</param>
/// <returns>The number of elements before the terminator.</returns>
int getLengthArray(int intArr[])
{
    // Variable to keep track of length
    int length = 0;

    // Loop through the possible longest array
    for (int i = 0; i < INT_MAX; i++)
    {
        // If the value is not equal to -1
        if (intArr[i] != -1)
            length++;       // Increment length
        // If the value equals -1
        else
            return length;  // Return the length
    }

    // In case -1 is never reached, report calculated length -- all paths will return a value
    return length;
}

/// <summary>
/// A function which gets the number of elements before a terminator.
/// </summary>
/// <param name="intPtr">The pointer to get the length of.</param>
/// <returns>The number of elements before the terminator.</returns>
int getLengthPointer(int* intPtr)
{
    // Variables
    int iteration = 0;  // Iteration to loop with 

    // Loop through the array until it reaches -1
    while (*(intPtr + iteration) != -1)
    {
        // Print out the number -- DEBUG ONLY
        //cout << *(intArr + iteration);

        // Increase the iteration
        iteration++;
    }

    // The length is the number of iterations
    return iteration;
}

#pragma endregion

#pragma region Part 3 Functions

/// <summary>
/// Creates an array in the stack.
/// </summary>
/// <returns>An array in the stack.</returns>
int* createStackArray()
{
    // 3.1a - In the function, declare an integer array of size 5, where each element is equal to its index:
    //  data[0] is 0, data[1] is 1, etc. Do not use "new" for this array, as you want it on the stack!
    int data[5] = { 0, 1, 2, 3, 4 };

    // 3.1b - Return the array.
    return data;
}

/// <summary>
/// Creates an array in the heap.
/// </summary>
/// <param name="size">The size of the array to create.</param>
/// <returns>An array in the heap.</returns>
int* createHeapArray(int size)
{
    // 3.2a - Create an array of the specified size using the "new" operator.
    int* data = new int[size];

    // 3.2b - Fill the array with data similar to the previous function: data[0] is 0, data[1] is 1, etc.
    for (int i = 0; i < size; i++)
    {
        data[i] = i;
    }

    // 3.2c - Return the array
    return data;
}

#pragma endregion

#pragma endregion