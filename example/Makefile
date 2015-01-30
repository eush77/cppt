TARGET = example

$(TARGET): $(TARGET).o driver.o
	gcc $^ -o $@

$(TARGET).o: $(TARGET).cppt
	gcc -xc -c $< -o $@

driver.o: ../driver.c
	gcc -xc -c $< -o $@

.PHONY: clean
clean:
	-rm -v *.o $(TARGET)
