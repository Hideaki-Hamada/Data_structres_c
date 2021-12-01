def selection_sort(numbers):
  print(f"Initial order: {numbers}\n\n")

  for i in range(0, len(numbers) - 1):
    print(f"Iteration {i}")
    minimum = i

    print(f"Current minimum: {numbers[minimum]}")
    for j in range(i + 1, len(numbers)):
      if numbers[j] < numbers[minimum]:
        minimum = j

        print(f"Current minimum: {numbers[minimum]}")

    print(f"Swap: {numbers[i]} <-- --> {numbers[minimum]}")

    temp = numbers[i]
    numbers[i] = numbers[minimum]
    numbers[minimum] = temp

    print(f"Order after swap: {numbers}\n")
    print("\n")

  print(f"Final order: {numbers}")

numbers = [89, 45, 68, 90, 29, 34, 17]
selection_sort(numbers)