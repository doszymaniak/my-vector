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

    cout << "size (10): " << v2.size() << "\n";

    cout << "capacity: " << v2.capacity() << '\n';

    cout << "empty (v2): ";
    v2.empty() ? cout << "empty\n" : cout << "not empty\n";

    cout << "iterators: ";
    for (auto it = v2.begin(); it != v2.end(); it++) cout << *it << " ";
    cout << '\n';

    MyVector<int> v3({1, 2, 3});
    v3.print("Initialized with list: ");
    return 0;
}