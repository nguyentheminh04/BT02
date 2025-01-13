merge_count = 0  # Biến đếm số lần so sánh trong Merge Sort

def merge(arr, left, mid, right):
    global merge_count
    n1 = mid - left + 1
    n2 = right - mid
    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]
    
    i = j = 0
    k = left
    while i < n1 and j < n2:
        merge_count += 1
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    merge_sort(arr, 0, len(arr) - 1)
    print("Kết quả sau Merge Sort:", arr)
    print("Số lần so sánh trong Merge Sort:", merge_count)