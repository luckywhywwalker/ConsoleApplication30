#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void randarr(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 - 5;
    }
}
void printarr(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
void sumnegative(float* arr, int n) {
    float sumneg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            sumneg += arr[i];
    }
    cout << "Sum of negative elements = " << sumneg << endl;
}
void summintomax(float* arr, int n) {
    int max = 0, min = 0, p = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min])
            min = i;
        if (arr[i] > arr[max])
            max = i;
    }
    for (int i = max + 1; i < min; i++)
        p *= arr[i];
    cout << "Product of elements between min and max = " << p << endl;
}
void sumpair(float* arr, int n) {
    int sumpairelements = arr[1];
    for (int i = 1; i < n; i++) {
        if (i % 2 != 0) {
            sumpairelements *= arr[i];
        }
    }
    cout << "Product of elements at even positions = " << sumpairelements << endl;
}
void sumnegtoneg(float* arr, int n) {
    int sum = 0, acc = 0;
    bool started = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (!started) {
                acc = 0;
                started = true;
            }
            else {
                sum += acc;
                acc = arr[i];
            }
        }
        else
            acc += arr[i];
    }
    cout << "Sum of elements between first and last negative elements = " << sum << endl;
}
int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "English");
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    float* arr = new float[n];
    randarr(arr, n);
    cout << "Array:" << endl;
    printarr(arr, n);
    cout << "\nFinding the sum of negative elements..." << endl;
    sumnegative(arr, n);
    cout << "\nFinding the product of elements between min and max..." << endl;
    summintomax(arr, n);
    cout << "\nFinding the product of elements at even positions..." << endl;
    sumpair(arr, n);
    cout << "\nFinding the sum of elements between the first and last negative elements..." << endl;
    sumnegtoneg(arr, n);
    delete[] arr;
    return 0;
}