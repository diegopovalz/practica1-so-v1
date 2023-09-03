flags=-Wall -lbsd
obj=gcc -c 
out=gcc -o 
name=first_practice
src=./src/
icd=./include/
build=./build/
target=$(build)$(name)

objs=src/main.o $(src)pq.o $(src)dijkstra.o $(src)dijkstra-nopq.o $(src)utils.o $(src)map.o

all: compile clean

compile: $(objs)
	$(out)$(target) $(objs) $(flags)

main.o: $(src)main.c
	$(obj)$(src)/main.c

pq.o: $(src)pq.c $(icd)pq.h
	$(obj)$(src)/pq.c

dijkstra.o: $(src)dijkstra.c $(icd)dijkstra.h
	$(obj)$(src)/dijkstra.c

dijkstra-nopq.o: $(src)dijkstra-nopq.c $(icd)dijkstra-nopq.h
	$(obj)$(src)/dijkstra-nopq.c

map.o: $(src)map.c $(icd)map.h
	$(obj)$(src)/map.c

utils.o: $(src)utils.c $(icd)utils.h
	$(obj)$(src)/utils.c

clean:
	rm $(objs)
