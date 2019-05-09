import os

start_p = int(float(0.00) * 100)
end_p = int(float(1.0) * 100) + 1
steps = int(float(0.01) * 100)

open('out.txt', 'w').close()
for i in range(start_p, end_p, steps):
	print(i)
	os.system("python graph_generator.py " + str(i))
	os.system("./program.exe >> out.txt")