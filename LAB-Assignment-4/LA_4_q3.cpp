#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even.\n";
        return;
    }

    queue<int> firstHalf;
    int half = n / 2;


    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int x, n;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
