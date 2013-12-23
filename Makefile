all:
	@echo "veuillez indiquer la SDA à utiliser, ex: make C1"

prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

C1: prepare
	g++ -o ./build/cartouchiere.o -c ./src/cartouchiere/C1/cartouchiere.cpp -I ./src/cartouchiere
	g++ ./src/cartouchiere/main.cpp ./build/cartouchiere.o -o ./build/hotel -I ./src/cartouchiere/C1

C2: prepare
	g++ -o ./build/cartouchiere.o -c ./src/cartouchiere/C2/cartouchiere.cpp -I ./src/cartouchiere
	g++ ./src/cartouchiere/main.cpp ./build/cartouchiere.o -o ./build/hotel -I ./src/cartouchiere/C2

clean:
	rm -rf ./build
