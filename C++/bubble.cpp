#include <iostream>
#include <vector>

using namespace std;

// Hàm thực hiện thuật toán sắp xếp nổi bọt
void bubbleSort(vector<int>& arr) {
    int n = arr.size();  // Lấy kích thước của mảng
    bool swapped;  // Biến cờ để kiểm tra xem có xảy ra hoán đổi nào không

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;  // Giả định ban đầu là không có hoán đổi

        for (int j = 0; j < n - i - 1; ++j) {
            // So sánh hai phần tử liền kề
            if (arr[j] > arr[j + 1]) {
                // Nếu phần tử trước lớn hơn phần tử sau thì hoán đổi
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;  // Đánh dấu là đã xảy ra hoán đổi
            }
        }

        // Nếu không có hoán đổi nào trong vòng lặp bên trong,
        // nghĩa là mảng đã được sắp xếp và có thể dừng lại
        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};

    bubbleSort(arr);

    cout << "Kết quả sau khi sắp xếp nổi bọt: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}