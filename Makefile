all:
	@echo "indiquez la SDA à utiliser, ex: make C1"

prepare:
	if [ ! -d ./build ] ; then mkdir ./build ; fi;

C1: prepare
	g++ -o ./build/cartouchiere.o -c ./src/cartouchiere/C1/cartouchiere.cpp -I ./src/cartouchiere
	g++ ./src/cartouchiere/main.cpp ./build/cartouchiere.o -o ./build/tp4 -I ./src/cartouchiere/C1

C2: prepare
	@echo "coming soon"

clean:
	rm -rfv ./build
