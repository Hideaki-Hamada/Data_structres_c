def Insertion_sort(list):

# We start from 1 since the first element is trivially sorted
	for number in range(1, len(list)):
		current_number = list[number]
		i = number - 1
   
#If there is an element in our sorted array greater than the one
#which is going to be inserted, the function moves the greater to the right

		while i >= 0 and current_number < list[i]:
		   list[i + 1] = list[i]
		   i -= 1

#And now if we found an ele,emt pf the sorted array smaller than the one 
#we are trying to insert at at index current_number, we insert that element
#ar current_number
		list[i + 1] = current_number


numbers = [8, 20, 45, 1, 6, 9]
print(f"Order before sorting numbers: {numbers}\n")

Insertion_sort(numbers)

print(f"Order after sorting numbers: {numbers}\n")
