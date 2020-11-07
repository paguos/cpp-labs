APP=container-benchmark

build:
	cmake -H. -Bbuild -S $(APP) -B $(APP)


run: build
	./$(APP)/build/$(APP)
