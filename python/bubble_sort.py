def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(n - 1 - i):
            # Hoán đổi
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if not swapped:
            break

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5]
    print("Kết quả sau Bubble Sort:", end=" ")
    bubble_sort(arr)
    print(arr)