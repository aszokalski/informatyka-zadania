//
// Created by Adam Szokalski on 24/10/2019.
//

//
// Created by Adam Szokalski on 16/10/2019.
//
#include <iostream>
#include <vector>

using namespace std;

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}

int pivot(int T[], int n) {
    int p = T[0];
    int i = 0, j = n - 1;

    while (T[i] < p) { i++; }
    while (T[j] > p) { j--; }

    int k;
    for (k = i; k <= j; ++k) {
        if (T[k] > p) {
            swap(T[k], T[j]);
            while (T[j] > p) { j--; }
        } else {
            swap(T[k], T[i]);
            while (T[i] < p) { i++; }
        }
    }
    return i;
}

void quick_sort(int T[], int p, int q) {
    if (q == p) {
        return;
    }
    cout << &(T[p]) << endl;
    int piv = pivot(&T[p], q + 1);
    cout << piv << endl;
    quick_sort(T, p, piv);
    quick_sort(T, piv + 1, q);
}

int main() {
//    int T[9] = {8, 7, 12, 5, 4, 1, 16, 9, 10};
//    pivot(T, 9);
//    for (int l = 0; l < 9; ++l) {
//        cout << T[l] << " ";
//    }
//    cout << endl ;
    int arr[] = {13, 12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}
