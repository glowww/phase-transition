# https://networkx.github.io/documentation/networkx-2.2/reference/readwrite/generated/networkx.readwrite.adjlist.write_adjlist.html
# https://networkx.github.io/documentation/networkx-2.0/tutorial.html
import sys, os, commands
import networkx as nx
import matplotlib.pyplot as plt

# Usage: Usage: python graph_generator.py
# 				start probability=0.4, ending probability=0.6,
# 				steps=0.01, repetions for graph=10, graph size=10
# example: python graph_generator.py 0.4 0.6 0.01 10 10

# start_p = int(float(sys.argv[1]) * 100)
# end_p = int(float(sys.argv[2]) * 100) + 1
# steps = int(float(sys.argv[3]) * 100)
# rep_p = int(sys.argv[4]) + 1
# size = int(sys.argv[5])

# start_p = int(float(0.5) * 100)
# end_p = int(float(0.5) * 100) + 1
# steps = int(float(0.01) * 100)
rep_p = int(50) + 1
size = 35

# for i in range(start_p, end_p, steps):
i = int(sys.argv[1])
open('list.txt', 'w').close()
with open("list.txt", "a+") as file:
	file.write(str(rep_p - 1) + " " + str(size) + '\n')
	for j in range(1, rep_p):
		G = nx.gnp_random_graph(size, i/100.0, seed=None, directed=False)
		adjlist = nx.generate_adjlist(G)
		for row in adjlist:
			file.write(row + '\n')
		file.write('\n')
		# plt.subplot(121)
		# nx.draw(G, with_labels=True, font_weight='bold')
		# plt.subplot(122)
		# nx.draw_shell(G, nlist=[range(5, 10), range(5)], with_labels=True, font_weight='bold')
		# plt.show()
	with open("out.txt", "a+") as file2:
		file2.write(str(float(i/100.0)) + ',')
