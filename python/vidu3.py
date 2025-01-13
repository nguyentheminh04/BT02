def partition(arr, low, high):
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1        # Chỉ số của phần tử nhỏ hơn

    for j in range(low, high):
        if arr[j] <= pivot:  # Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Hoán đổi pivot về vị trí chính xác
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # Chỉ số của pivot
        quick_sort(arr, low, pi - 1)    # Sắp xếp các phần tử bên trái pivot
        quick_sort(arr, pi + 1, high)   # Sắp xếp các phần tử bên phải pivot

arr = [5, 2, 9, 1, 5, 6]
quick_sort(arr, 0, len(arr) - 1)
print("Kết quả Quick Sort:", arr)  # Output: [1, 2, 5, 5, 6, 9]