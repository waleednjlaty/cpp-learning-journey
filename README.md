# SafeCopy CLI

A lightweight command-line file backup utility written in modern C++.

SafeCopy CLI allows users to select a file, inspect its basic information, and create a backup copy in a destination directory. The project was built as a practical C++ learning project focused on file handling, resource management, and the C++ standard library.

## Features

- Open and validate files from a user-provided path
- Display the source file name and size
- Create destination directories automatically when needed
- Copy files to a selected backup directory
- Preserve the original file name
- Overwrite an existing backup when necessary
- Display the original and copied file sizes
- Handle filesystem errors using exception handling
- Support binary files such as images, archives, PDFs, and executables
- Run continuously until the user chooses to exit

## Technologies

- C++17
- C++ Standard Library
- `std::filesystem`
- `std::ifstream`
- Exception Handling
- RAII

## C++ Concepts Practiced

This project was created after studying C++ memory and resource management concepts, including:

- Stack vs. Heap
- Dynamic Memory Management
- Dangling Pointers
- Double-Free
- Memory Fragmentation
- Lvalues and Rvalues
- Move Semantics
- `std::move`
- Move Constructors and Move Assignment
- RVO / NRVO
- RAII
- Rule of 0 / 3 / 5
- AddressSanitizer
- Valgrind

Not every concept is manually implemented in the program. The project intentionally relies on standard-library RAII types where appropriate instead of manually managing resources unnecessarily.

## How It Works

The program asks the user for the path of a source file.

It then:

1. Attempts to open the file.
2. Displays the file name and size.
3. Requests a destination directory.
4. Creates the destination directory if it does not exist.
5. Copies the source file to that directory.
6. Displays the size of both the original file and the copied file.

The application continues running until the user enters `X`.

## Build

A compiler with C++17 support or newer is required.

Using GCC:

```bash
g++ -std=c++17 main.cpp -o safecopy
```

## Run

### Linux

```bash
./safecopy
```

### Windows

```powershell
.\safecopy.exe
```

## Example

```text
Please enter the file path:
example.pdf

File opened successfully.
File size: 152430 bytes

File name: example.pdf
Enter the new file path to save the file: backup

File copied successfully.
Original File size: 152430 bytes
Copied File size: 152430 bytes
```

## Memory Testing

During development, memory-analysis tools can be used to check the application for memory-related problems.

Example with Valgrind:

```bash
valgrind --leak-check=full ./safecopy
```

AddressSanitizer can also be used when supported by the compiler and environment.

## Project Purpose

SafeCopy CLI is primarily a learning project built to strengthen practical C++ skills.

The goal was not to manually recreate functionality already provided safely by the C++ Standard Library, but to practice using standard components correctly while understanding the memory-management concepts behind them.

## Future Improvements

Possible future additions include:

- Backup integrity verification
- Recursive directory backups
- Progress indicators for large files
- Timestamped backups
- Improved command-line arguments
- Automated tests

## License

This project is available for educational and personal use.
