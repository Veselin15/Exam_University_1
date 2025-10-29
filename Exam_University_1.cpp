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

int OddArray(int arr[], int n) {
	int oddArr[MAX_STUDENTS];
	int oddCount = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			oddCount++;
			oddArr[oddCount] = arr[i];
		}
	}
	if (oddCount == 0) {
		cout << "No odd faculty numbers found." << endl;
		return;
	}
	int maxOdd = *max_element(oddArr, oddArr + oddCount);
	//int maxOdd = oddArr[0];
	//for (int i = 1; i < oddCount; i++) {
	//	if (oddArr[i] > maxOdd) {
	//		maxOdd = oddArr[i];
	//	}
	//}
	return maxOdd;
}

int main() {
	cout << "------Menu------" << endl;
	cout << "1. Input faculty numbers(max 25)" << endl;
	cout << "2. Make a new array only of odd faculty numbers and get the max value" << endl;
	cout << "3. Overwrite the initial array and sort it in ascending order" << endl;
	cout << "4. Exit" << endl;
	int choice;
	int initial_arr[MAX_STUDENTS];
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			int num_students = inputArray(initial_arr);
			printArray(initial_arr, num_students, "Faculty numbers entered:");
			break;
		}   
		case 2: {
			int maxOdd = OddArray(initial_arr, MAX_STUDENTS);
			if (maxOdd != 0) {
				cout << "Maximum odd faculty number: " << maxOdd << endl;
			}
			printArray(initial_arr, MAX_STUDENTS, "Initial array remains unchanged:");
            break;
		}
        case 3: {
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