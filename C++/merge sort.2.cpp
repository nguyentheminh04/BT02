#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main() {
    vector<int> sizes = {5000, 10000, 20000};
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10000; // Tạo mảng ngẫu nhiên

        // Thời gian cho Merge Sort
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> merge_duration = end - start;
        cout << "Thời gian Merge Sort với kích thước " << size << ": " << merge_duration.count() << " ms" << endl;

        // Tạo lại mảng ngẫu nhiên cho Bubble Sort
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10000;

        // Thời gian cho Bubble Sort
        start = chrono::high_resolution_clock::now();
        bubbleSort(arr);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> bubble_duration = end - start;
        cout << "Thời gian Bubble Sort với kích thước " << size << ": " << bubble_duration.count() << " ms" << endl;
    }
    return 0;
}