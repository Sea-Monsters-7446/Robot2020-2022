# Advantages vs disadvantages of C++
When picking a programming language, you usually weigh it against other to see advantages and disadvantages to each one.
Because you're reading this guide, I'll assume you have your own reason to use C++ versus other ones, but you can look at this list for ideas about your next language.

## C
Advantages
* Supported on virtually everything
* More control over the execution
* Performance is excellent

Disadvantages
* Lacks namespace features
* No OOP (object orientated programming) features

```
#include <stdio.h> // Include standard library

int main() { // Create main function that returns an int
    printf("Hello world!\n"); // Print "Hello world!" with a newline
    return 0; // Return error code 0, no error
} // End function
```

## C++
Advantages
* Superset of C
* Supports OOP features
* C++ handles abstraction of complex code making it more elegant

Disadvantages
* Compiler may not fully optimise code
* Sub-optimal performace
* Buffer overflows

```
#include <iostream> // Include standard library

int main() { // Create main function that returns an int
    std::cout << "Hello world!" << std::endl; // Print "Hello world!" with a newline
    return 0; // Return error code 0, no error
} // End function
```

## Golang
Advantages
* Has built-in garbage collector
* Protection from buffer overflows
* More abstraction making it even more elegant

Disadvantages
* No OOP features
* Garbage collector slows it down

```
package main // Declare package as main

import ( // Start imports
    "fmt" // Import formatting package
) // End imports

func main() { // Create main function
    fmt.Println("Hello world!") // Print "Hello world!" with a newline
} // End function
```

## Python
Advantages
* The code runs everywhere
* Has built-in garbage collector
* Easier syntax
* 100% OOP

Disadvantages
* Not even compiled, slow
* You need the interpreter to run code
* Whitespace levels need to match (no mixing)
* No backwards compatibility with major versions

```
print("Hello world!") # Print "Hello world!" with a newline
```

## Nim
Advantages
* Compiled, fast
* Syntactic sugar (flexable syntax)
* Easy syntax
* Emulates OOP

Disadvantages
* Not widely used

```
# These all print "Hello world!" with a newline
echo("Hello world!")
echo "Hello world!"
"Hello world!".echo()
"Hello world!".echo
```
