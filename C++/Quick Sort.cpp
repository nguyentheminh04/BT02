#include <iostream>
#include <vector>
using namespace std;

// Hàm Partition: Đưa pivot về vị trí đúng và sắp xếp các phần tử
int partitionFunc(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn pivot là phần tử cuối
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]); // Hoán đổi arr[i] với arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Hoán đổi pivot vào vị trí đúng
    return i + 1; // Vị trí của pivot
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partitionFunc(arr, low, high); // Tìm vị trí pivot
        quickSort(arr, low, p - 1); // Sắp xếp bên trái pivot
        quickSort(arr, p + 1, high); // Sắp xếp bên phải pivot
    }
}

int main() {
    vector<int> arr = {5 ,2, 9, 1, 5, 6};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Kết quả sau Quick Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}