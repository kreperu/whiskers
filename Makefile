all:
	cp -rf assets build/
	cd build && cmake .. && make && ./whiskers
build:
	cp -rf assets build/
	cd build && cmake .. && make
run:
	cd build && ./whiskers
clean:
	rm -rf build/*
