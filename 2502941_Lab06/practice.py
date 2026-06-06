def swap(input , index0ne , indextwo):
   n = len(input)
   for items in range(n):
      indexone = items
      for j in range( items + 1 , n):
         if (input[indexone] > input[indextwo]):
            temp_var = input[indexone]
            input[indexone] = input[indextwo]
            input[indextwo] = temp_var
   return input 

data = [
    87, 3, 56, 21, 90, 14, 45, 72, 1, 38,
    64, 12, 99, 7, 33, 18, 81, 26, 59, 5,
    41, 68, 23, 95, 8, 50, 36, 70, 2, 88,
    16, 61, 9, 44, 29, 74, 11, 54, 6, 79,
    25, 63, 31, 97, 19, 48, 4, 83, 20, 66
    ]
print(swap(data,0,1))

