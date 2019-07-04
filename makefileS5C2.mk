plotS5C2.png: datos.dat plotS5C2.py BelloAnaS5C2.cpp
	python plotS5C2.py
datos.dat: a.out
	./a.out
a.out: BelloAnaS5C2.cpp
	g++ BelloAnaS5C2.cpp