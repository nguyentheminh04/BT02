import random
import time

INSERTION_SORT_THRESHOLD = 10

# Hàm sắp xếp bằng Insertion Sort
def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Hàm phân vùng cho Quick Sort
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Hàm cài đặt Hybrid Quick Sort
def hybrid_quick_sort(arr, low, high):
    if high - low < INSERTION_SORT_THRESHOLD:
        insertion_sort(arr, low, high)
    else:
        pi = partition(arr, low, high)
        hybrid_quick_sort(arr, low, pi - 1)
        hybrid_quick_sort(arr, pi + 1, high)

# Chạy thử nghiệm
sizes = [5000, 10000, 20000]
for size in sizes:
    arr = [random.randint(0, 10000) for _ in range(size)]

    start_time = time.time()
    hybrid_quick_sort(arr, 0, len(arr) - 1)
    hybrid_duration = (time.time() - start_time) * 1000
    print(f"Thời gian Hybrid Quick Sort với kích thước {size}: {hybrid_duration:.2f} ms")