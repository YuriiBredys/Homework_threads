#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

atomic<int> balance = 0;

void processBalance(string path)
{
    cout << "thread started "<< path << endl;


    ifstream input;


    input.open(path);

    if (!input.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << "starting file processing "<< path << endl;

        while (!input.eof())
        {
            int temp;
            input >> temp;
            
            balance += temp;
            
        }

        cout << "finishing file processing "<< path << endl;
    }

    input.close();


}

int main()
{
    auto start = chrono::system_clock::now();

    string path1 = "inputThread1.txt";
    string path2 = "inputThread2.txt";

    thread thr1(processBalance,path1);
    thread thr2(processBalance, path2);

    thr1.join();
    thr2.join();

    cout << balance << endl;

    auto finish = chrono::system_clock::now();

    auto time = finish - start;

    cout << time.count() << endl;

    return 0;
}
