<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

## Holbertonschool-printf

Project by:
Véronique BEAUVAIS (GitHub: Veroniquebvs) & Matéo MARQUES (GitHub: serkam31)
Students at Holberton School

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## Description

This project is a custom implementation of the C standard library `printf` function. It handles format specifiers (%c, %s, %d, %i, %%) and outputs formatted text to stdout. Built using a modular architecture with function pointers for easy extensibility.

<img width="1151" height="1722" alt="Diagramme sans nom drawio (2)" src="https://github.com/user-attachments/assets/5ce9b81d-1d09-4014-9851-8e11c336c575" />

---

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

---

## Requirements

- Ubuntu 20.04 LTS
- - My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra`, `-pedantic` and `-std=gnu89`.
- No more than 5 functions per file.

---

## Supported Specifiers

| Specifier | Output             |
|:---------:|--------------------|
| `%c`      | Single character   |
| `%s`      | String             |
| `%d`      | Decimal integer    |
| `%i`      | Integer            |
| `%%`      | `%` symbol         |

---

## Man Page

To view the man page:
```bash
man ./man_3_printf
```

---

## Examples
```c
#include "main.h"

int main(void)
{
    /* Basic usage */
    _printf("Hello, %s!\n", "World");           // Hello, World!
    
    /* Characters */
    _printf("Letter: %c\n", 'Z');               // Letter: Z
    
    /* Integers */
    _printf("Answer: %d\n", 42);                // Answer: 42
    _printf("Negative: %i\n", -1234);           // Negative: -1234
    
    /* Edge cases */
    _printf("NULL string: %s\n", NULL);         // NULL string: (null)
    _printf("Percent sign: %%\n");              // Percent sign: %
    
    /* Return value = number of chars printed */
    int len = _printf("Test\n");                // len = 5
    
    return (0);
}
```

---

## How It Works

The implementation uses a **dispatch table** pattern:
```c
typedef struct check
{
    char *type;              /* Specifier character */
    int (*func)(va_list);    /* Handler function */
} check_t;
```

**Flow:**

1. Parse format string character by character
2. When `%` is found, look up the next character in the dispatch table
3. Call the matching handler function with `va_list` arguments
4. Handler prints and returns character count
5. Accumulate total count and return

This architecture makes adding new specifiers trivial — just write a handler and add it to the table.

---

## Authors

|    | Name               | GitHub                                          |
|:--:|--------------------|-------------------------------------------------|
| 👩‍💻 | Véronique BEAUVAIS | [@Veroniquebvs](https://github.com/Veroniquebvs) |
| 👨‍💻 | Matéo MARQUES      | [@serkam31](https://github.com/serkam31)         |

*Students at [Holberton School](https://www.holbertonschool.com/)*
