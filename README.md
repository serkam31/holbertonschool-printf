## Holbertonschool-printf

Project by:  
Véronique BEAUVAIS (GitHub: Veroniquebvs) & Matéo MARQUES (GitHub: serkam31)  
Students at Holberton School

## Description

This project is a recreation of the C `printf` function. It handles various format specifiers and produces output according to a format string. 

## Features

- Format specifier parsing
- Variadic argument handling
- Modular design using a dispatch table

### Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `_printf("%c", 'A')` → `A` |
| `%s` | String | `_printf("%s", "hello")` → `hello` |
| `%d` | Signed decimal integer | `_printf("%d", -42)` → `-42` |
| `%i` | Signed integer | `_printf("%i", 42)` → `42` |
| `%%` | Literal percent sign | `_printf("%%")` → `%` |

## Installation

Clone the repository and compile with GCC:

```bash
git clone https://github.com/your-username/holbertonschool-printf.git
cd holbertonschool-printf
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Usage

Include the header file in your program:

```c
#include "main.h"

int main(void)
{
    _printf("String: %s\n", "Hello, World!");
    _printf("Character: %c\n", 'H');
    _printf("Integer: %d\n", 42);
    _printf("Negative: %i\n", -42);
    _printf("Percent: %%\n");
    
    return (0);
}
```

**Output:**
```
String: Hello, World!
Character: H
Integer: 42
Negative: -42
Percent: %
```

## Return Value

- On success: the number of characters printed (excluding the null byte)
- On error: `-1`

## File Structure

```
holbertonschool-printf/
├── main.h              # Header file with prototypes and struct definition
├── _printf.c           # Main printf implementation
├── _putchar.c          # Character output function
├── _print_char.c       # Handler for %c
├── _print_string.c     # Handler for %s
├── _print_integer.c    # Handler for %d and %i
├── _print_percentage.c # Handler for %%
└── README.md
```

## Architecture

The implementation uses a structure-based dispatch table to map format specifiers to their handler functions:

```c
typedef struct check
{
    char *type;
    int (*func)(va_list);
} check_t;
```

This design allows for easy extension by simply adding new entries to the specifier array.

## Compilation

All files are compiled on Ubuntu 20.04 LTS using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Testing

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    len1 = _printf("Custom: [%s]\n", "test");
    len2 = printf("Standard: [%s]\n", "test");
    
    _printf("Custom length: %d\n", len1);
    printf("Standard length: %d\n", len2);
    
    return (0);
}
```

## Limitations

- Does not handle field width or precision
- Does not handle length modifiers (`l`, `h`)
- Does not handle flag characters (`+`, `-`, `#`, `0`, space)

## Authors

- **Mateo** - [GitHub](https://github.com/your-username)

## License

This project is part of the Holberton School curriculum.

## Acknowledgments

- Holberton School for the project guidelines
- The creators of the original `printf` function
