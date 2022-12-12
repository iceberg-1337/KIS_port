MyProject : port.o port.c
	gcc port.o -o port
	./a.exe
MyProject : port.c
	gcc -c port.c -o port.o
installemsdk: 
	cd .. && git clone https://github.com/emscripten-core/emsdk.git
	cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc RabbitChase.c -s WASM=1 -o pge.html
	npm i http-server -g
runserver:
	  cd ../emrun pge.html