TEMPLATE = example.cppt
TEMPLATE_BIN = $(TEMPLATE:.cppt=)
DRIVER = ../driver.c
INCLUDE_TARGET = template.cppt
BUILD_DIR = build

$(TEMPLATE_BIN): $(TEMPLATE) $(DRIVER)
	mkdir -p $(BUILD_DIR)
	ln -fs ../$(TEMPLATE) $(BUILD_DIR)/$(INCLUDE_TARGET)
	gcc -I $(BUILD_DIR) $(DRIVER) -o $@

.PHONY: clean
clean:
	-rm -rv $(BUILD_DIR) $(TEMPLATE_BIN)
