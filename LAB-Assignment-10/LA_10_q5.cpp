#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    Node* temp = head;
    while (temp != NULL) {
        if (visited.find(temp) != visited.end()) {
            return true;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    return false; 
}

int main() {
    
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; 

    cout << (hasCycle(n1) ? "true" : "false");

    return 0;
}
