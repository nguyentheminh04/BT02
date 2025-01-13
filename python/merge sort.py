def merge(arr, left, mid, right):
    # Kích thước các mảng tạm
    n1 = mid - left + 1
    n2 = right - mid

    # Tạo các mảng tạm
    L = arr[left:mid + 1]
    R = arr[mid + 1:right + 1]

    # Chỉ số ban đầu cho các mảng tạm
    i = 0
    j = 0
    k = left

    # Hợp nhất các mảng tạm vào arr
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Sao chép phần còn lại của L, nếu có
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Sao chép phần còn lại của R, nếu có
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    # Sắp xếp nếu còn nhiều hơn 1 phần tử
    if left < right:
        mid = (left + right) // 2
        
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

# Ví dụ sử dụng
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    merge_sort(arr, 0, len(arr) - 1)
    print("Kết quả sau Merge Sort:", arr)