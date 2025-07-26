# corelib
General Purpose C++ Library.

Computational performance is prioritized over mathematical form without the cost of correctness.

For instance, when deriving ${}^nP_k = \frac{n!}{(n-k)!$, instead of calculating the answer as `factorial(n)/factorial(n-k)`, we do `for(int i = n; i > k; i--)`.

## Pre-requisites
### Documentation
- `doxygen`
- `graphviz`
