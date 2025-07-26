BUILD_DIR := build
INSTALL_DIR := install

DOXYGEN = doxygen
DOXYFILE = Doxyfile
DOCS_DIR = docs/html


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

.PHONY: docs
docs:
	@command -v $(DOXYGEN) >/dev/null 2>&1 || { echo >&2 "Doxygen is not installed."; exit 1; }
	$(DOXYGEN) $(DOXYFILE)
	@echo "Documentation generated in $(DOCS_DIR)"

clean-docs:
	rm -rf docs/html docs/latex
	@echo "Documentation cleaned."
