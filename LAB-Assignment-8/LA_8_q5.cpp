#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}


void heapSortIncreasing(int arr[], int n) {
    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}


void heapSortDecreasing(int arr[], int n) {
    // Build min heap
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {50, 20, 40, 10, 60, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    int choice;
    cout << "\n1. HeapSort Increasing Order";
    cout << "\n2. HeapSort Decreasing Order\n";
    cin >> choice;

    if(choice == 1) {
        heapSortIncreasing(arr, n);
        cout << "Sorted Increasing: ";
        printArray(arr, n);
    }
    else if(choice == 2) {
        heapSortDecreasing(arr, n);
        cout << "Sorted Decreasing: ";
        printArray(arr, n);
    }
    else {
        cout << "Invalid Choice!";
    }

    return 0;
}
