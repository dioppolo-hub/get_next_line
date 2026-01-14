*This project has been created as part of the 42 curriculum by dioppolo.*

# get_next_line

## Description

**get_next_line** is a C project that implements a function to read a file line by line. The primary goal is to learn file handling, dynamic memory allocation, and the importance of efficient algorithms in C programming.

The project requires implementing a `get_next_line()` function that:
- Reads a file descriptor line by line
- Returns one line at a time on successive calls
- Handles files of any size with a configurable buffer size
- Properly manages memory to avoid leaks
- Works with any BUFFER_SIZE value (defined at compile time)

This is a foundational project that teaches essential systems programming concepts, including:
- Static variables for maintaining state between function calls
- Efficient memory management and string manipulation
- Buffer handling and edge cases (EOF, empty lines, etc.)
- Proper error handling in low-level I/O operations

## Instructions

### Compilation

Compile the project using `make` or directly with `gcc`:

```bash
# Using gcc with default BUFFER_SIZE of 42
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o get_next_line

# Or with a custom buffer size
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c -o get_next_line
```

### Execution

```bash
./get_next_line
```

The program will read from `test.txt` and print each line read by `get_next_line()`.

### Usage Example

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("filename.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm Explanation

### Core Concept: Static Buffer Management

The `get_next_line()` function uses a **static buffer** that persists across function calls. This allows the function to maintain state between invocations without requiring the caller to manage the buffer themselves.

### Algorithm Flow

1. **Initialization**: On the first call, a static string `stat` is used to accumulate data read from the file.

2. **Reading Phase**:
   - Read `BUFFER_SIZE` bytes from the file descriptor
   - Append the new data to the static buffer using `ft_strjoin()`
   - Continue reading until a newline character (`\n`) is found or EOF is reached

3. **Line Extraction**:
   - If a newline exists in the buffer: `get_line()` extracts the line including the newline
   - If no newline (EOF reached): `get_last_line()` extracts the remaining data as the final line

4. **State Update**:
   - `set_stat()` updates the static buffer to contain only the data after the returned line
   - The next call starts with this remaining data

5. **Return**: The extracted line is returned; the caller must free it.

### Key Functions

| Function | Lines | Purpose |
|----------|-------|---------|
| `get_next_line()` | 24 | Main function that reads and returns lines |
| `get_line()` | 17 | Extracts a line including the newline character |
| `get_last_line()` | 21 | Handles EOF: returns remaining data without newline |
| `readfile()` | 13 | Reads from file descriptor and joins with buffer |
| `set_stat()` | 9 | Updates static buffer with remaining data |
| `ft_strjoin()` | 21 | Joins two strings with proper memory allocation |

### Why This Approach?

- **State Preservation**: The static variable eliminates the need for the caller to manage buffer state
- **Efficiency**: `ft_strjoin()` avoids redundant copying by freeing old allocations
- **Flexibility**: Works with any buffer size defined at compile time
- **Simplicity**: The algorithm is straightforward and easy to debug

### Edge Cases Handled

- Empty files
- Files without trailing newline
- Single character reads (BUFFER_SIZE=1)
- Large files exceeding system memory
- Files with only newline characters
- Read errors and allocation failures

## Resources

### Documentation & References

- **UNIX File I/O**: [man page - read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- **Memory Management in C**: [Dynamic Memory Allocation](https://en.wikipedia.org/wiki/Memory_management)
- **String Handling**: [Standard C Library - string.h](https://www.cplusplus.com/reference/cstring/)
- **42 School Resources**: [42 Intra](https://intra.42.fr)

### How AI Was Used

**GitHub Copilot** was used in this project for:

1. **Documentation**: Generated algorithm explanations and helped create comprehensive comments for complex sections.

The AI was **NOT** used for:
- The core algorithmic concept (static buffer approach)
- Initial logic design or problem-solving strategy
- Understanding the 42 School's specific requirements and norms

## Technical Choices

### Why Use a Static Variable?

The static variable `stat` maintains the reading position and unconsumed data between function calls. This eliminates the need for:
- Passing opaque structures to the caller
- Complex state management
- Multiple file descriptors tracking

### Memory Allocation Strategy

- Each line is dynamically allocated to return to the caller
- The static buffer is updated after each line extraction
- Failed allocations are properly handled with NULL returns

### Compilation Flag BUFFER_SIZE

The configurable buffer size allows testing with various scenarios:
- **BUFFER_SIZE=42** (default): Balanced approach for testing
- **BUFFER_SIZE=1**: Tests character-by-character reading
- **BUFFER_SIZE=1000000**: Tests large buffer efficiency

All sizes must produce identical functional results.

## Norminette Compliance

This project adheres to the 42 School's **Norminette** standards:
- Maximum 25 lines per function (excluding main)
- Maximum 5 functions per file (excluding main)
- Proper naming conventions (snake_case for functions)
- Consistent indentation and formatting

Verify compliance with:
```bash
norminette
```

# Bonus

## Descrizione ✅
- Questa repository include la **versione bonus** che supporta la lettura da **più file descriptor** contemporaneamente.
- La funzione `get_next_line()` mantiene lo stato separato per ogni `fd`, permettendo chiamate intercalate su file diversi senza perdita di dati.

## File aggiuntivi 🔧
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

## Come testare 💡
- Compila includendo i file bonus:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

- Esempio di test (apri e leggi più file):

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
// alterna le chiamate per verificare che lo stato di ciascun fd sia preservato
```

## Note implementative ⚠️
- Usare una struttura dati (es. lista o array dinamico) per mantenere lo stato associato a ciascun `fd`.
- Assicurarsi di liberare la memoria relativa a un `fd` quando viene raggiunto EOF o il file viene chiuso.
- Verificare che i file bonus rispettino la **Norminette** e gli stessi vincoli di stile del progetto principale.

