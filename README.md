# .shny Interpreter

A simple interpreter for `.shny` files that supports basic commands like variable declaration and output.

## Overview

This interpreter processes a custom scripting language with the `.shny` file extension. The language supports basic operations such as declaring variables and writing output to the console.

## Supported Commands

- **Variable Declaration:**
  - Declare a variable using the `var` keyword.
  - Example: `var myVar = "Test variable"`

- **Writing Output:**
  - Output the value of a variable to the console using the `write()` function.
  - Example: `write(myVar)`

## Running the Interpreter

To run the interpreter, use the following command:

```sh
./shny_interpreter myscript.shny
```
Replace myscript.shny with the path to your .shny file.

## Example Script

Create a .shny file with the following content:
```.shny
var myVar = "Test variable"
write(myVar)
```
When executed, the interpreter will output:

```sh
Test variable
```
