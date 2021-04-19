// Experience the unpredictability of threads and attempt to control them.
#include <iostream>

#include <thread>
#include <vector>

#include "NumberPrinter.h"
#include "GamePlay.h"

using namespace std;

int main()
{
    // 1b.1 - Create a for loop that runs 10 times. Inside the loop, create a new NumberPrinter object and call its Print() method.
    vector<thread*> printerThreads;
    for (int i = 0; i < 50; i++)
    {
        NumberPrinter numberPrinter = NumberPrinter(i);

        // 1b.2 - Run the program.
        // 1b.2a - You should see numbers on the screen, in order.
        //      Correct!

        // 1b.3 - Now comment out the line where you called the Print method. Still in the loop:
        //numberPrinter.Print();

        // 1b.3a - Instead of calling Print() in the loop, make a new thread object and pass in the NumberPrinter object’s Print method as the parameter.
        // 1b.3b - Start the thread you just created.
        printerThreads.push_back(new thread(&NumberPrinter::Print, numberPrinter));
    }

    // Loop through threads
    for (int i = 0; i < printerThreads.size(); i++)
    {
        // Rejoin threads and delete them since they were declared on the heap
        printerThreads[i]->join();
        delete printerThreads[i];
    }

    // 1b.4 - Run the program again and think about the following questions:
    // 1b.4a - Is the output any different?
    //      Yes.
    // 1b.4b - Why or why not?
    //      Each thread calling their respective "couts" simultaneously.

    // 1b.5 - Make sure each thread has time to start before all previous threads finish. Do this by making more threads and making each thread do more work. Have at least 50 threads,
    //  each of which prints at least 50 numbers.
    // 1b.5a - Are the numbers perfect? More jumbled? Why?
    //      The numbers are more jumbled. The threads are jumping around and trying to simultaneously call their "couts."
    


    // 2b - After the code in Part 1’s main method, do the following:
    // 2b.1 - Create 5 GamePlay objects, each with a unique name
    GamePlay physics = GamePlay("Physics");
    GamePlay pathfinding = GamePlay("Pathfinding");
    GamePlay worldLoading = GamePlay("World Loading");
    GamePlay rendering = GamePlay("Rendering");
    GamePlay generating = GamePlay("Generating");

    // 2b.2 - Create a vector<thread*> which will hold our threads
    vector<thread*> gamePlayThreads;

    // 2b.3 - Create 5 new thread objects, each one using a different GamePlay object’s Update
    thread* physicsThread = new thread(&GamePlay::Update, physics);
    thread* pathfindingThread = new thread(&GamePlay::Update, pathfinding);
    thread* worldLoadingThread = new thread(&GamePlay::Update, worldLoading);
    thread* renderingThread = new thread(&GamePlay::Update, rendering);
    thread* generatingThread = new thread(&GamePlay::Update, generating);

    // 2b.3a - Add each thread to the vector<thread*>
    gamePlayThreads.push_back(physicsThread);
    gamePlayThreads.push_back(pathfindingThread);
    gamePlayThreads.push_back(worldLoadingThread);
    gamePlayThreads.push_back(renderingThread);
    gamePlayThreads.push_back(generatingThread);

    // 2b.3b - The threads will automatically start

    // 2b.4 - Print “Update Complete! Time to Draw”
    //cout << "Update Complete! Time to Draw" << endl;

    // 2b.5 - Run your program a few times. Where does “Update Complete” appear?
    //      Seemingly random locations.

    // 2ba - Lastly, try to get all the threads to finish before the main method reaches “Update Complete”. You can use any of the thread control concepts we’ve talked about:
    // 2ba.1 - this_thread.sleep_for()
    // 2ba.2 - thread.join()

    // Loop through threads
    for (int i = 0; i < gamePlayThreads.size(); i++)
    {
        // Rejoin threads and delete them since they were declared on the heap
        gamePlayThreads[i]->join();
        delete gamePlayThreads[i];
    }

    // 2b.4 - Print “Update Complete! Time to Draw”
    cout << "Update Complete! Time to Draw" << endl;

    // 2bb - The end goal is to allow the threads to run at the same time, but ensure they’re ALL done before the main method finishes. Adding a large this_thread.sleep_for() in main is
    //  not acceptable here.
}