#Binary search function

def binary_search(arr, key):
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = start + (end - start) // 2
        
        if arr[mid] == key:
            return mid

        elif arr[mid] < key:
            start = mid + 1

        else:
            end = mid - 1

    return False

array = [1,4,5,9,12,16,18,27,33]

search_key = int(input(f'{array}\nInsert search key: '))
r = binary_search(array, search_key)
print(f'Binary search result: {r}')
