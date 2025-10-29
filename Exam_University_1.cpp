#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_STUDENTS = 25;

bool isValidFacNum(int facNum) {
    return facNum >= 10000000 && facNum <= 99999999;
}

int inputArray(int arr[]) {
    int n;
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    cin >> n;
    while (n < 1 || n > MAX_STUDENTS) {
        cout << "Invalid number of students. Please enter again: ";
        cin >> n;
    }

    cout << "Enter faculty numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!isValidFacNum(arr[i])) {
            cout << "Invalid faculty number. Please enter again: ";
            cin >> arr[i];
        }
    }
    return n;
}

void printArray(int arr[], int n, const string& msg) {
    cout << msg << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int OddArray(const int arr[], int n, int oddArr[]) {
    int oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            // store at index oddCount, then increment oddCount
            oddArr[oddCount++] = arr[i];
        }
    }
    return oddCount;
}
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
	}
}
int main() {

    int choice;
    int initial_arr[MAX_STUDENTS];
    int num_students = 0; // track how many students were entered

    do {
        cout << "------Menu------" << endl;
        cout << "1. Input faculty numbers(max 25)" << endl;
        cout << "2. Make a new array only of odd faculty numbers and get the max value" << endl;
        cout << "3. Overwrite the initial array and sort it in ascending order" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            num_students = inputArray(initial_arr);
            printArray(initial_arr, num_students, "Faculty numbers entered:");
            break;
        }
        case 2: {
            if (num_students == 0) {
                cout << "No faculty numbers entered yet. Choose option 1 first." << endl;
            }
            else {
                int oddArr[MAX_STUDENTS];
                int oddCount = OddArray(initial_arr, num_students, oddArr);

                if (oddCount == 0) {
                    cout << "No odd faculty numbers found." << endl;
                }
                else {
                    printArray(oddArr, oddCount, "Odd faculty numbers:");
                    int maxOdd = *max_element(oddArr, oddArr + oddCount);
                    cout << "Maximum odd faculty number: " << maxOdd << endl;
                }

                printArray(initial_arr, num_students, "Initial array remains unchanged:");
            }
            break;
        }
        case 3: {
            if (num_students == 0) {
                cout << "No faculty numbers entered yet. Choose option 1 first." << endl;
            }
            else {
                sortArray(initial_arr, num_students);
                printArray(initial_arr, num_students, "Array after sorting ascending:");
            }
            break;
        }
        case 4: {
            cout << "Exiting program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}