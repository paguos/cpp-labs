APP=container-benchmark

build:
	cmake -H. -Bbuild -S $(APP)
	cmake --build build -- -j3
	mv build $(APP)/build

run: build
	./$(APP)/build/$(APP)

clear:
	rm -rf $(APP)/build
