object = rcilent.o re_group.o re_login.o

main : $(object)
	g++ -o main $(object) -g

$(object) : head.h

rcilent.o : rcilent.cpp
re_group.o : re_group.cpp
re_login.o : re_login.cpp

clean : 
	rm $(object)

