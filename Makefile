OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: Cjt_Especies.o Especie.o Cluster.o Cjt_Cluster.o program.o
	g++ -o program.exe Cjt_Especies.o Especie.o Cluster.o Cjt_Cluster.o program.o
	
program.o: program.cc
	g++ program.cc -c $(OPCIONS)
Especie.o: Especie.hh
	g++ -c Especie.cc $(OPCIONS)

Cjt_Especies.o: Cjt_Especies.hh
	g++ -c Cjt_Especies.cc $(OPCIONS)

Cluster.o: Cluster.hh
	g++ -c Cluster.cc $(OPCIONS)

Cjt_Cluster.o: Cjt_Cluster.hh
	g++ -c Cjt_Cluster.cc $(OPCIONS)
	
clean:
	rm *.o
	rm *.exe
	rm *.gch

practica.tar: program.cc Especie.hh Especie.cc Cjt_Especies.hh Cjt_Especies.cc Makefile
	tar -cvf practica.tar program.cc Especie.hh Especie.cc Cjt_Especies.hh Cjt_Especies.cc Cluster.hh Cluster.cc Cjt_Cluster.hh Cjt_Cluster.cc Makefile

