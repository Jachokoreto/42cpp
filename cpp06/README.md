- C-style casts
```c++
    float f = 5.0;
    int i = (int)f;
```

- static_cast
```c++
    float f = 5.0;
    int i = static_cast<int>(f);
```

- reinterpret_cast
```c++
    int x = 42;
    void* void_ptr = &x; // void pointer to int x

    // Cast the void pointer to a pointer of type double*
    double* double_ptr = reinterpret_cast<double*>(void_ptr);

    // Dereference the double pointer to print the value of x interpreted as a double
    std::cout << "x interpreted as a double: " << *double_ptr << std::endl;
```
- dynamic_cast
