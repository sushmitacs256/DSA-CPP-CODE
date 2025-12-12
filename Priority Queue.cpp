#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max-Heap Priority Queue
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Priority Queue (Max-Heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // Highest value first
        pq.pop();
    }

    cout << "\n";

    // Min-Heap Priority Queue
    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(30);
    minpq.push(10);
    minpq.push(50);
    minpq.push(20);

    cout << "Priority Queue (Min-Heap): ";
    while (!minpq.empty()) {
        cout << minpq.top() << " "; // Smallest value first
        minpq.pop();
    }

    return 0;
}
