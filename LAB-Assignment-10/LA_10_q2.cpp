#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cout << "Enter size of A: ";
    cin >> n;
    cout << "Enter size of B: ";
    cin >> m;

    int A[n], B[m];
    cout << "Enter elements of A:\n";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Enter elements of B:\n";
    for (int i = 0; i < m; i++) cin >> B[i];

    unordered_set<int> setA;
    for (int x : A) setA.insert(x);

    cout << "Common Elements: ";
    for (int x : B) {
        if (setA.count(x)) {
            cout << x << " ";
            setA.erase(x); 
        }
    }
    cout << endl;

    return 0;
}
