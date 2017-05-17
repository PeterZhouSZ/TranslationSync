all:
	g++ -o solver main.cpp -O3 -std=c++11 -fopenmp

n=2000
edge_density=0.2
bias=1.0
inc=0
max_iter=10000
noise_type=2
noise_ratio=0
decay=0.5
output=uniform_n1p2/
a=-1
b=2
graph_file=

synthetic:
	mkdir -p $(output)
	./solver $(n) $(edge_density) $(bias) $(inc) $(noise_type) $(noise_ratio) $(max_iter) $(decay) 	$(a)	$(b)	$(output)		$(graph_file)

graph1:
	mkdir -p $(output)/$@/
	./solver 2000 	0.1 			1.0 	0.0 	2 				0 			10000 		0.9 	-1		2		$(output)/$@/	graph1.meta

graph2:
	mkdir -p $(output)/$@/
	./solver 2000 	0.4 			0.2 	0.6 	2 				0 			10000 		0.9 	-1		2		$(output)/$@/	graph2.meta

graph3:
	mkdir -p $(output)/$@/
	./solver 20000 	0.001 			1.0 	0.0 	2 				0 			10000 		0.9 	-1		2		$(output)/$@/	graph3.meta

graph4:
	mkdir -p $(output)/$@/
	./solver 20000 	0.1 			0.04 	0.12 	2 				0 			10000 		0.9 	-1		2		$(output)/$@/ 	graph4.meta

draw_graph:
	python graph1.py
	python graph2.py
	python graph3.py
	python graph4.py