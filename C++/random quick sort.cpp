#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;

int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low);
    swap(arr[randomIndex], arr[high]); // Đưa pivot ngẫu nhiên vào cuối mảng
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

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main() {
    vector<int> sizes = {5000, 10000, 20000};
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10000;

        // Thời gian cho Randomized Quick Sort
        auto start = chrono::high_resolution_clock::now();
        randomizedQuickSort(arr, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> rand_duration = end - start;
        cout << "Thời gian Randomized Quick Sort với kích thước " << size << ": " << rand_duration.count() << " ms" << endl;

        // Tạo lại mảng ngẫu nhiên cho Quick Sort
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10000;

        // Thời gian cho Quick Sort
        start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, size - 1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> quick_duration = end - start;
        cout << "Thời gian Quick Sort với kích thước " << size << ": " << quick_duration.count() << " ms" << endl;
    }
    return 0;
}