Implicit casting is a type of automatic type conversion that is performed by the compiler without requiring an explicit cast operator.

```c
int i = 5;
float f = i; // this is a implicit cast
```

generic -> specific = demotion
- float to int (lower precision)


specific -> generic = promotion
- int to float (higher precision)

Demotion requires an explicit cast, because the compiler cannot always determine whether the cast is safe or appropriate.

