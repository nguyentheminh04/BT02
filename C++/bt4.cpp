#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

const int INSERTION_SORT_THRESHOLD = 10;

// Hàm sắp xếp bằng Insertion Sort
void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm phân vùng cho Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm cài đặt Hybrid Quick Sort
void hybridQuickSort(vector<int>& arr, int low, int high) {
    if (high - low < INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, low, high);
    } else {
        int pi = partition(arr, low, high);
        hybridQuickSort(arr, low, pi - 1);
        hybridQuickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> sizes = {5000, 10000, 20000};
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10000;

        auto start = chrono::high_resolution_clock::now();
        hybridQuickSort(arr, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        cout << "Thời gian Hybrid Quick Sort với kích thước " << size << ": " << duration.count() << " ms" << endl;
    }
    return 0;
}