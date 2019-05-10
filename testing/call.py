import os, sys

start_p = int(float(sys.argv[1]) * 100)
end_p = int(float(sys.argv[2]) * 100) + 1
steps = int(float(sys.argv[3]) * 100)
rep_p = int(sys.argv[4]) + 1
size = int(sys.argv[5])

# start_p = int(float(0.00) * 100)
# end_p = int(float(1.0) * 100) + 1
# steps = int(float(0.01) * 100)

open('out.txt', 'w').close()
for i in range(start_p, end_p, steps):
	print(i)
	os.system("python graph_generator.py " + str(i) + " " + str(rep_p) + " " + str(size))
	os.system("./program.exe >> out.txt")