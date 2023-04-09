#include <iostream>
#include <windows.h>
#include <process.h>
#include "main.h"

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int n;

HANDLE hMinMax;
HANDLE hAverage;

DWORD WINAPI MinMaxThread(LPVOID lpParam) {
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        Sleep(7);

        if (arr[i] < minVal) {
            minVal = arr[i];
        }

        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;

    return 0;
};

DWORD WINAPI AverageThread(LPVOID lpParam) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        Sleep(12);

        sum += arr[i];
    }

    double average = sum / (double)n;
    cout << "Average value: " << average << endl;

    return 0;
};


void replaceMinMaxWithAverage() {
    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }

        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double average = sum / (double)n;
    arr[minIdx] = average;
    arr[maxIdx] = average;

    cout << "Array after replacing min and max with average: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    hMinMax = CreateThread(NULL, 0, MinMaxThread, NULL, 0, NULL);
    hAverage = CreateThread(NULL, 0, AverageThread, NULL, 0, NULL);

    WaitForSingleObject(hMinMax, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    replaceMinMaxWithAverage();

    return 0;
}