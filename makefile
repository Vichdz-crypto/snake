run : bin/programa  #./ es para ejecutar
	./bin/programa 


bin/programa : main.cpp include/*.hpp  # * es para mandar a traer todos los archivos de la carpeta,  build systems: Automatizador de tareas
	g++ main.cpp -Iinclude -o bin/programa 