flags=-Wall -lbsd
obj=gcc -c 
out=gcc -o 
name=first_practice
src=./src/
icd=./include/
build=./build/
target=$(build)$(name)

objs=src/main.o \
	 $(src)pq.o \
	 $(src)dijkstra.o \
	 $(src)dijkstra-nopq.o \
	 $(src)utils.o \
	 $(src)map.o \
	 $(src)user_interaction.o

all: compile clean

compile: $(objs)
	@[ -d "$(build)" ] || { mkdir "$(build)"; }
	$(out)$(target) $(objs) $(flags)

%.o: $(src)%.c $(icd)%.h
	$(obj)$(src)%.c

example%:
	$(target) $@.txt 1

clean:
	rm $(objs)
