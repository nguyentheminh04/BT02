quick_count = 0  # Biến đếm số lần so sánh trong Quick Sort

def partition(arr, low, high):
    global quick_count
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        quick_count += 1
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)
        quick_sort(arr, low, p - 1)
        quick_sort(arr, p + 1, high)

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    quick_sort(arr, 0, len(arr) - 1)
    print("Kết quả sau Quick Sort:", arr)
    print("Số lần so sánh trong Quick Sort:", quick_count)