hello:
	echo "Hello World"

mallocMain: mallocMain.c
	gcc -o mallocMain mallocMain.c

runWithoutCustomMalloc: mallocMain.c
	./mallocMain

runWithCustomMalloc: customMalloc.c mallocMain.c
	gcc -o mallocMain customMalloc.c mallocMain.c
	./mallocMain

clean:
	rm memoryAllocator
