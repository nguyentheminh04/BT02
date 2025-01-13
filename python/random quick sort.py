import random
import time

def randomized_partition(arr, low, high):
    random_index = random.randint(low, high)
    arr[random_index], arr[high] = arr[high], arr[random_index]  # Đưa pivot ngẫu nhiên vào cuối
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def randomized_quick_sort(arr, low, high):
    if low < high:
        pi = randomized_partition(arr, low, high)
        randomized_quick_sort(arr, low, pi - 1)
        randomized_quick_sort(arr, pi + 1, high)

def quick_sort(arr, low, high):
    if low < high:
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        quick_sort(arr, low, i)
        quick_sort(arr, i + 2, high)

sizes = [5000, 10000, 20000]
for size in sizes:
    arr = [random.randint(0, 10000) for _ in range(size)]

    start_time = time.time()
    randomized_quick_sort(arr, 0, len(arr) - 1)
    rand_duration = (time.time() - start_time) * 1000
    print(f"Thời gian Randomized Quick Sort với kích thước {size}: {rand_duration:.2f} ms")

    arr = [random.randint(0, 10000) for _ in range(size)]  # Tạo lại mảng ngẫu nhiên

    start_time = time.time()
    quick_sort(arr, 0, len(arr) - 1)
    quick_duration = (time.time() - start_time) * 1000
    print(f"Thời gian Quick Sort với kích thước {size}: {quick_duration:.2f} ms")