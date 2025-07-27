# corelib
_General Purpose C++ Library._

`corelib` emphasizes **computational efficiency** over strict adherence to mathematical formalisms — without sacrificing correctness.

## Performance-Oriented Philosophy

Take, for instance, the computation of permutations:

$${}^nP_k = \frac{n!}{(n-k)!}$$

Rather than evaluating this using the traditional mathematical expression, which contains computational redundancies:

```cpp
factorial(n) / factorial(n - k);
```

— we apply a more efficient approach — in this case a loop-based calculation:

```cpp
int result = 1;
for (int i = n; i > (n - k); --i) {
    result *= i;
}
```

The goal is to provide clean and minimal interfaces for mathematical functions, algorithms, and data structures, with performance-aware implementations when appropriate.

## Pre-requisites
### Building
- `cmake`
- `gcc-15`
- `make`

### Documentation
- `doxygen`
- `graphviz`
