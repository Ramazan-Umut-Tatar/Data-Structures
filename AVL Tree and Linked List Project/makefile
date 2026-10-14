Tum: derleme calistirma

derleme:

	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Agac.o ./lib/Dugum.o ./lib/Kuyruk.o ./lib/BagliListe.o ./src/main.cpp
	
calistirma:
	./bin/main