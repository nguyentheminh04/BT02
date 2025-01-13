#include <iostream>
#include <vector>

using namespace std;

// Hàm hợp nhất hai mảng đã được sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Kích thước mảng bên trái
    int n2 = right - mid;    // Kích thước mảng bên phải

    // Tạo các mảng tạm thời
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng tạm L và R
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Hợp nhất các mảng tạm vào arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép phần còn lại của L, nếu có
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Sao chép phần còn lại của R, nếu có
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Hàm sắp xếp hợp nhất
void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tránh tràn số nguyên

        // Đệ quy sắp xếp hai nửa
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Hợp nhất các nửa đã được sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    merge_sort(arr, 0, arr_size - 1);

    cout << "Kết quả sau Merge Sort: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}