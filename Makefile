run:
	cp -rf assets build/
	cd build && cmake .. && make && ./whiskers
