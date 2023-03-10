# reinterpret_cast

uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.

### How it works
This is used to reinterpret the bits of a data type as if it were another data type. It can be used to perform low-level type punning or to convert between unrelated pointer types. The reinterpret_cast is generally considered unsafe because it can lead to undefined behavior if the conversion is not valid.

### Some use case
1. When working with memory-mapped hardware devices or raw memory buffers. In such cases, the program needs to access the hardware or memory using specific types of pointers, which may not be compatible with the program's data types. reinterpret_cast can be used to reinterpret the bits of a pointer as a different type.

2. Serialization or deserialization of data. For example, if a program needs to serialize data into a binary format and then deserialize it back into memory, it may need to reinterpret the bits of a pointer in order to properly reconstruct the original data.