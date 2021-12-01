#Interpolation search function

def interpolation_search(arr, key):
    start = 0
    end = len(arr) - 1

    while (arr[end] != arr[start]) and (key >= arr[start]) and (key <= arr[end]):
        X = start + ( (key - arr[start])*(end - start) ) // (arr[end] - arr[start])
        
        if arr[X] < key:
            start = X + 1

        elif arr[X] > key:
            end = X -1

        else:
            return X

    if key == arr[start]:
        return start
    else:
        return False

array = [1,4,5,9,12,16,18,27,33]

search_key = int(input(f'{array}\nInsert search key: '))
r = interpolation_search(array, search_key)

print(f'Interpolation search: {r}')