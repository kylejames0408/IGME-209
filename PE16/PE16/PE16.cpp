// 1 - Start with a C++ console application
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 2 - In main(), use an ofstream object to create and write a few lines to a text file

    //     ____     ____          __
    //    / __/__ _/ / /__  __ __/ /_
    //   / _// _ `/ / / _ \/ // / __/
    //  /_/  \_,_/_/_/\___/\_,_/\__/

    ofstream outFile = ofstream("FalloutASCII.txt");

    if (outFile.is_open())
    {
        outFile << "   ____     ____          __" << endl;
        outFile << "  / __/__ _/ / /__  __ __/ /_" << endl;
        outFile << " / _// _ `/ / / _ \\/ // / __/" << endl;
        outFile << "/_/  \\_,_/_/_/\\___/\\_,_/\\__/" << endl;
        outFile.close();
    }

    // 3 - Run the program, then open the project folder on your computer and verify the file was written correctly.
    // Check!

    // 4 - Back in main( ), use an ifstream object to read the file back in.
    // 4a - Read the file in binary mode
    ifstream inFile("FalloutASCII.txt", ios::binary);

    // 4b - Read the entire file to a single array (don’t forget to add the null terminator)
    string fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
    inFile.close();

    // 4c - Print the file's contents to the console window
    cout << fileAsString << endl;
}