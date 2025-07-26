BUILD_DIR := build
INSTALL_DIR := install

DOXYGEN = doxygen
DOXYFILE = Doxyfile
DOCS_DIR = docs/html


.PHONY: help
help:
	@echo "Available targets:"
	@echo "  help        - Show this help message"
	@echo "  all         - Build library, run tests, and generate docs"
	@echo "  build       - Compile the library and test executable"
	@echo "  test        - Build and run tests via CTest"
	@echo "  test-direct - Build and run test executable directly"
	@echo "  install     - Build and install the library"
	@echo "  docs        - Generate documentation with Doxygen"
	@echo "  clean       - Remove build and install directories"
	@echo "  clean-docs  - Remove generated documentation"

.PHONY: all
all: build test docs

.PHONY: build
build:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && \
		cmake .. -DCMAKE_INSTALL_PREFIX=$(abspath $(INSTALL_DIR)) && \
		$(MAKE) -j

.PHONY: install
install: build
	cd $(BUILD_DIR) && $(MAKE) install

.PHONY: test
test: build
	cd $(BUILD_DIR) && ctest --verbose

.PHONY: test-direct
test-direct: build
	cd $(BUILD_DIR) && ./test_corelib

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
