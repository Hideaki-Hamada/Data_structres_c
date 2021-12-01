def bubble_sort(numbers):
  print(f"Initial order: {numbers}\n\n")
  
  for i in range(0, len(numbers) - 1):
    print(f"Iteration {i}")

    for j in range(0, len(numbers) - 1 - i):
      if numbers[j] > numbers[j + 1]:
        print(f"Swap: {numbers[j]} <-- --> {numbers[j+1]}")

        temp = numbers[j]
        numbers[j] = numbers[j + 1] 
        numbers[j + 1] = temp

        print(f"Order after swap: {numbers}\n")

    print("\n")

  print(f"Final order: {numbers}")

numbers = [89, 45, 68, 90, 29, 34, 17]
bubble_sort(numbers)
