[wiki for exception and error handling](https://isocpp.org/wiki/faq/exceptions)

## How to use exception?

- In C++, exceptions are used to signal errors that cannot be handled locally,

In particular, **do not use exceptions for control flow**. throw is not simply an alternative way of returning a value from a function (similar to return). Doing so will be slow and will confuse most C++ programmers who are rightly used to seeing **exceptions used only for error handling**. Similarly, throw is not a good way of getting out of a loop.

[Good point on return codes vs exceptions](https://isocpp.org/wiki/faq/exceptions#exceptions-avoid-spreading-out-error-logic)

[How and when (not) to use exception](http://www.codinghell.ch/blog/2013/03/31/how-and-when-not-to-use-exceptions/#:~:text=Exceptions%20should%20be%20used%20for,unwilling%20or%20unable%20to%20handle.)

It is recommended to throw an object.

Good way to write exceptions:

- List down all the possible error that can't be handled locally
- create object/class for all the exceptions
- try...catch block for the exceptions that can be handled by the caller.
