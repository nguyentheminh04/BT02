#include <iostream>
#include <vector>
using namespace std;

int quickCount = 0; // Biến đếm số lần so sánh trong Quick Sort

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickCount++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Kết quả sau Quick Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nSố lần so sánh trong Quick Sort: " << quickCount << endl;
    return 0;
}