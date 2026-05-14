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

    v2.resize(10, 5);
    v2.print("Resize to 10: ");

    cout << "v2[6] (5): " << v2[6] << '\n';
    
    v2[6] = 7;
    cout << "v2[6] = 7: " << v2[6] << '\n';

    v2.at(4) = 15;
    cout << "v2.at(4) = 15: " << v2[4] << '\n';
    return 0;
}