#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0;       
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;
        }

        case 2: {   
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            break;
        }

        case 3: {   
            int pos, val;
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;

            if (pos < 0 || pos > n)
                cout << "Invalid Position!\n";
            else {
                for (int i = n; i > pos; i--)
                    arr[i] = arr[i-1];
                arr[pos] = val;
                n++;
            }
            break;
        }

        case 4: {   
            int pos;
            cout << "Enter position to delete (0 to " << n-1 << "): ";
            cin >> pos;

            if (pos < 0 || pos >= n)
                cout << "Invalid Position!\n";
            else {
                for (int i = pos; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
            }
            break;
        }

        case 5: {   
            int key, found = 0;
            cout << "Enter element to search: ";
            cin >> key;

            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at index " << i << endl;
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Element not found.\n";
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
