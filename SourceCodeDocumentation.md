# CCCP Programming Language source code documentation

## Variables

- `memory`: A vector that stores integer values of variables declared in the program.
- `IDs`: A vector that holds the names of variables.
- `file`: An `fstream` object used for file input.
- `path`: A string variable to store the path of the input file.
- `keywords`: A string containing a list of keywords used in the CCCP programming language.
- `sum`: A vector to store the sum of variables.

## Functions

- `interpreter()`: The main function responsible for interpreting the CCCP program.
- `createIntVariable()`: Creates a new integer variable and adds it to the `memory` vector.
- `getIntVariable()`: Retrieves the value of an integer variable from the `memory` vector.
- `intMath()`: Performs mathematical operations on integer variables.
- `setIntVariable()`: Assigns a value to an integer variable.
- `isKeyword()`: Checks if a given string is a keyword in CCCP.
- `isNumber()`: Checks if a given string is a number.
- `comparison()`: Performs a comparison between two values based on the given condition.
- `errors()`: Returns an error message based on the provided error ID.

## Main Function

The `main()` function serves as the entry point for the program. It prompts the user to provide the path to a `.cccp` file, opens and reads the file, and then calls the `interpreter()` function to process the code.

## Interpreter Function

The `interpreter()` function reads the lines from the file and processes each line according to the CCCP language rules. It identifies keywords, operators, and functions to execute the corresponding actions. The code includes support for variable declarations, assignments, mathematical operations, conditional statements, and basic input/output operations.

## Language Components

### Keywords

The CCCP programming language includes the following keywords:

- `comrade`: Used for declaring variables
- `if`: Used for conditional statements.
- `gulag`: Sets the line to return to after calling `sentToGulag`.
- `alert`: Used for printing messages
- `propaganda`: Used for printing messages
- `manifesto`: Used for printing variables or numbers 
- `progress`: Used to create a new line in the terminal
- `censor`: Clears the terminal screen 
- `contribute`: allows user input to assign a value to a variable
- `sendToGulag`: Used for jumping to a specific line of code indicated by `gulag`.

### Operators

The CCCP programming language includes the following operators:

- `=`: Used for assignment.
- `+=`: Used for adding a value to the existing value of a variable.
- `-=`: Used for subtracting a value from the existing value of a variable.
- `*=`: Used for multiplying the existing value of a variable by a value.
- `/=`: Used for dividing the existing value of a variable by a value.

### Logical Operators

The code does not explicitly include logical operators such as `&&` (logical AND) and `||` (logical OR). However, the `comparison()` function performs comparisons using operators like `==`, `!=`, `<`, `>`, `<=`, and `>=` for conditional statements.

### Input/Output

The CCCP programming language supports input and output operations. The `std::cin` statement is used to read user input, and the `std::cout` statement is used to display output.

### Control Flow

The code includes a `while` loop that continuously prompts the user for a file path, reads the file contents, and interprets the code line by line. It also has conditional statements (`if`) for executing code based on certain conditions.

### Comments

Comments in the CCCP programming language are denoted by the `;` character. Lines starting with `;` or containing `;` are considered comments and are skipped during execution.
