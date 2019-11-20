#include <iostream>
using namespace std;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    }
}

int main() {
    int len;
    cout << "enter length: " << endl;
    cin >> len;
    int arr[len];

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}