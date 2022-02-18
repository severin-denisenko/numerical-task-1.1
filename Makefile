run: build $(wildcard data1.dat data2.dat)
	./build

build: $(wildcard *.c *.h)
	gcc *.c -o build

clean:
	rm -rf build output

