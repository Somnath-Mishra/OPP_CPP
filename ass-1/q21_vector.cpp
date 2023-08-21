#include <iostream>
using namespace std;

class MyVector {
private:
    int n;
    int* arr;

public:
    MyVector(int m, int arr[]) : n(m) {
        this->arr = new int[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = arr[i];
        }
    }

    int* additionVector(int arrTemp[]) {
        int* ansVector = new int[n];
        for (int i = 0; i < n; i++) {
            ansVector[i] = arr[i] + arrTemp[i];
        }
        return ansVector;
    }

    int* subtractionVector(int arrTemp[]) {
        int* ansVector = new int[n];
        for (int i = 0; i < n; i++) {
            ansVector[i] = arr[i] - arrTemp[i];
        }
        return ansVector;
    }

    bool isLess(int arrTemp[]) {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= arrTemp[i]) {
                return false;
            }
        }
        return true;
    }

    bool isGreater(int arrTemp[]) {
        for (int i = 0; i < n; i++) {
            if (arr[i] <= arrTemp[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter number of elements in vector: ";
    cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    cout << "Enter elements of vector1: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    MyVector v1(n, arr1);

    cout << "Enter elements of vector2: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    MyVector v2(n, arr2);

    int* ans1 = v1.additionVector(arr2);
    cout << "Addition of vectors v1, v2 is: ";
    for (int i = 0; i < n; i++) {
        cout << ans1[i] << " ";
    }
    delete[] ans1;

    int* ans2 = v1.subtractionVector(arr2);
    cout << "\nSubtraction of vectors v1, v2: ";
    for (int i = 0; i < n; i++) {
        cout << ans2[i] << " ";
    }
    delete[] ans2;

    cout << "\nIs v1 less than v2: " << v1.isLess(arr2) << endl;
    cout << "Is v1 greater than v2: " << v1.isGreater(arr2) << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
