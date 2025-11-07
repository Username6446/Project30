#include <iostream>
#include "MyStack.h"
#include "Queue.h"

using namespace std;


int main() {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.print();

    int first = q.GetItem();
    cout << "First: " << first << endl;

    int removed = q.pop();
    cout << "Removed: " << removed << endl;
    q.print();

    cout << "Size: " << q.GetN() << endl;

    Queue<int> q2(q);
    q2.push(40);
    q2.print();

    Queue<int> q3;
    q3 = q2;
    q3.print();

    q.clear();
    q.print();

    cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl;

    return 0;
}