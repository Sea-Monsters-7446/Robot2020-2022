# How does a C++ program work?

First, let's take a "Hello world" program and dissect it line-by-line

```
#import <iostream>
/*
These lines in the beginning starting with '#' are preprocessor instructions, they give instructions to the compiler before compilation
Because they aren't C++ functions, they don't end in ';'
This line says to include the code from "iostream" before our other code during compilation
*/

int main() { // Our entrypoint into the program, first thing to be ran. We return an int because that's our error code returned.
    std::cout << "Hello world!" << std::endl;
    /*
    This gets the "cout" class from "std" and uses the insertion operator "<<" to say put "Hello world!" into "cout"
    We then get "endl" from "std" and add it too
    We finish the line off with ';' signifying the end of the line
    */
    
    return 0; // Return error code 0, no error
} // Mark the end of this function
```

**Placeholder**
