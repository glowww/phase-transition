
# https://networkx.github.io/documentation/networkx-2.0/tutorial.html

import networkx as nx
import matplotlib.pyplot as plt

G = nx.extended_barabasi_albert_graph(10, 2, 0.05, 0.05, seed=None)
plt.subplot(121)
nx.draw(G, with_labels=True, font_weight='bold')
plt.subplot(122)
nx.draw_shell(G, nlist=[range(5, 10), range(5)], with_labels=True, font_weight='bold')
plt.show()


# https://networkx.github.io/documentation/networkx-2.2/reference/readwrite/generated/networkx.readwrite.adjlist.write_adjlist.html

nx.write_adjlist(G,"test.adjlist")