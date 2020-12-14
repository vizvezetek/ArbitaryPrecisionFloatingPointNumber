main: *.cpp 
	g++ -std=c++17 *.cpp -o main -w

docs:
	doxygen doxconf
	cd DOCS/latex
	make

clean:
	rm main main.exe