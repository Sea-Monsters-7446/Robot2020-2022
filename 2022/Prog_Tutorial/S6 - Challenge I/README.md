# Challenge I
## Goal:
**Create a basic unbreakable calculator**

Your goal is to create a calculator that can handle 2 numbers each 4 digits in length

You do not need to use decimals for inputs or outputs

This means that equations like "1 / 2" may result in incorrect answers

## Perimeters
* Takes 3 inputs, 2 for the numbers and 1 for the operation

There's a number of ways you can take the 3 inputs, but as long as it's not hard coded then it's fine

For example, you can have a prompt for the numbers and the operation:

```
> Please input your first number: 3
> Please input your operation: +
> Please input your second number: 6
> Your output is: 9
```

You can have it as 1 input seperated by spaces

```
> Please input your equation in the following format:
> OPERATION NUMBER1 NUMBER2
> Examples: "+ 1 2", "- 4 5", "* 9 2", "/ 2 1"
> Be sure to put a space in between every item
>
> Enter equation: / 10 2
> Your output is: 5
```

* Supports addition, subtraction, multiplication, division
* Won't break by dividing by zero

Don't have the program panic when dividing by zero, handle the error

```
> Please input your first number: 1
> Please input your operation: /
> Please input your second number: 0
> Invalid denominator, cannot divide by zero
```
