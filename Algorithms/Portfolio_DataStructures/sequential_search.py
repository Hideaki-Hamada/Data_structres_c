#Sequential search function

def sequential_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return False


array = [1,4,5,9,12,16,18,27,33]

search_key = int(input(f'{array}\nInsert search key: '))
r = sequential_search(array, search_key)
print(f'\nSequential search result: {r}')