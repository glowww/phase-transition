import os, sys, time

start_time = time.time()

start_p = int(float(sys.argv[1]) * 100)
end_p = int(float(sys.argv[2]) * 100) + 1
steps = int(float(sys.argv[3]) * 100)
rep_p = int(sys.argv[4]) + 1
size = int(sys.argv[5])
graphType = int(sys.argv[6])

# start_p = int(float(0.00) * 100)
# end_p = int(float(1.0) * 100) + 1
# steps = int(float(0.01) * 100)

open('list.txt', 'w').close()
open('out.txt', 'w').close()
for i in range(start_p, end_p, steps):
	print(i)
	os.system("python c_graph_generator.py " + str(i) + " " + str(rep_p) + " " + str(size) + " " + str(graphType))
	os.system("./c_program.exe >> out.txt")

print(time.time() - start_time)