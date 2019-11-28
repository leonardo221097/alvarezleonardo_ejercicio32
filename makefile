ejercicio32.png: ejercicio32.dat 
	python ejercicio32.py

ejercicio32.dat: ejercicio32.x
	./ejercicio32.x > ejercicio32.dat
	
ejercicio32.x : ejercicio32.cpp
	c++ ejercicio32.cpp -o ejercicio32.x