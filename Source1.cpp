#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

mutex m1;
mutex m2;

void thread1()
{
    m1.lock();
    this_thread::sleep_for(chrono::milliseconds(100));
    m2.lock();

    cout << "Lock thread1" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    m1.unlock();
    m2.unlock();

    cout << "Unlock thread1" << endl;
}

void thread2()
{
    m2.lock();
    this_thread::sleep_for(chrono::milliseconds(100));
    m1.lock();

    cout << "Lock thread2" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    m1.unlock();
    m2.unlock();
    cout << "Unlock thread2" << endl;
}

int main()
{
    thread thr1(thread1);
    thread thr2(thread2);

    thr1.join();
    thr2.join();

    return 0;
}