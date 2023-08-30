flags=-Wall
obj=gcc -c 
out=gcc -o 
name=first_practice
src=./src/
icd=./include/
build=./build/
target=$(build)$(name)

objs=src/main.o $(src)pq.o $(src)dijkstra.o $(src)utils.o

all: compile clean

compile: $(objs)
	$(out)$(target) $(objs) $(flags)

main.o: $(src)main.c
	$(obj)$(src)/main.c

pq.o: $(src)pq.c $(icd)pq.h
	$(obj)$(src)/pq.c

dijkstra.o: $(src)dijkstra.c $(icd)dijkstra.h
	$(obj)$(src)/dijkstra.c

utils.o: $(src)utils.c $(icd)utils.h
	$(obj)$(src)/utils.c

clean:
	rm $(objs)
