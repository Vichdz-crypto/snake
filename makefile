run : bin/programa  #./ es para ejecutar
	./bin/programa 


bin/programa : main.cpp include/*.hpp  # * es para mandar a traer todos los archivos de la carpeta,  build systems: Automatizador de tareas
	g++ main.cpp -Iinclude -o bin/programa 


runtest : bin/test  #./ es para ejecutar
	./bin/test 


bin/test : scr/test.cpp include/*.hpp  # * es para mandar a traer todos los archivos de la carpeta,  build systems: Automatizador de tareas
	g++ scr/test.cpp -Iinclude -o bin/test -std=c++2a -lftxui-component -lftxui-dom -lftxui-screen
	 