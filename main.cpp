#include "myvector.hpp"
#include <iostream>

using namespace std;

int main()
{
    MyVector<int> v1;
    v1.print("Empty:");
    v1.push_back(5);
    v1.print("[+ 5]: ");
    v1.push_back(6);
    v1.print("[+ 6]: ");
    v1.push_back(7);
    v1.print("[+ 7]: ");

    MyVector<int> v2;
    v2 = v1;
    v2.print("Copy assignment: ");

    v2.pop_back();
    v2.print("[- 7]: ");
    return 0;
}