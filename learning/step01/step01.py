print("This is a simple program in python")
N = int(raw_input("Enter a small integer: "))
print("The squares and cubes of the first "+str(N)+" numbers are:")
for i in range(1,N+1):
  print("Number: "+str(i)+". Square: "+str(i**2)+". Cube: "+str(i**3))

