# ex02 - Abstract class

### Facts :

1. A class is abstarct if it has at least 1 pure virtual function
2. Can have pointers and references of abstract class type
3. If we do not override pure virtual function in derived class, then derived class also become an abstract class
4. An abstract class can also have contrustor

### Virtual function

```
void someFunction(var i) = 0;
```

## Why use abstract class?

An abstract class cannot be instantiated. The purpose of an abstract class is to provide a common definition of a base class that multiple derived classes can share

derived concrete class -> a derived class that has no virtual function and provide function definition for its inherited function
