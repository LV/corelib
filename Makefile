BUILD_DIR := build
INSTALL_DIR := install

.PHONY: all
all: build

.PHONY: build
build:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && \
		cmake .. -DCMAKE_INSTALL_PREFIX=$(abspath $(INSTALL_DIR)) && \
		$(MAKE) -j

.PHONY: install
install: build
	cd $(BUILD_DIR) && $(MAKE) install

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR) $(INSTALL_DIR)
