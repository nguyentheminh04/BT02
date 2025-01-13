def partition(arr, low, high):
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1  # Chỉ số của phần tử nhỏ hơn pivot

    for j in range(low, high):
        # Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if arr[j] <= pivot:
            i += 1  # Tăng chỉ số của phần tử nhỏ hơn
            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi arr[i] với arr[j]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Hoán đổi pivot vào vị trí đúng
    return i + 1  # Vị trí của pivot

def quick_sort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)  # Tìm vị trí pivot
        quick_sort(arr, low, p - 1)  # Sắp xếp bên trái pivot
        quick_sort(arr, p + 1, high)  # Sắp xếp bên phải pivot

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    quick_sort(arr, 0, len(arr) - 1)
    print("Kết quả sau Quick Sort:", arr)