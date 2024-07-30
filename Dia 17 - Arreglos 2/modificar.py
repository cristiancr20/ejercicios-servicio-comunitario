arr= [1,2,3,4,5]

print("Array Original")
for i in range(0,len(arr)):
  print(f"posicion: {i} valor: {arr[i]}")

arr[3]=100

print("Array Modificado")

for i in range(0,len(arr)):
  print(f"posicion: {i} valor: {arr[i]}")
  