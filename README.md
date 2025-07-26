# corelib
General Purpose C++ Library.

This library emphasizes computational performance over strict adherence to traditional mathematical expressions — without compromising correctness.

For example, when computing the number of permutations:

$${}^nP_k = \frac{n!}{(n-k)!}$$

Rather than evaluating this directly using `factorial(n) / (factorial(n - k)` which performs and allocates redundant resources, we would use an efficient loop-based approach:

```cpp
int result = 1;
for (int i = n; i > (n - k); --i) {
    result *= i;
}
```

## Pre-requisites
### Documentation
- `doxygen`
- `graphviz`
