arr =[1,2,3,4,5]

print("Array Original")
for i in range(0,len(arr)):
  print(arr[i])

#Inserción de un elemento en la posicion 2

arr.insert(2,100)

print("\nArray con inserción")
for i in range(0,len(arr)):
  print(arr[i])

  #Eliminación de un elemento en la posicion 4

arr.pop(4)
print("\nArray con eliminación")
for i in range(0,len(arr)):
  print(arr[i])