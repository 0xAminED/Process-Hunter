# Process-Hunter

A C program that retrieves detailed information about a running process in the operating system using the **Process ID (PID)**. This program utilizes the Linux `/proc` filesystem to extract useful details such as process name, command-line arguments, state, parent process ID, memory usage, and executable path.

## Features

- **Process Name**: Fetches the name of the process.
- **Command-line Arguments**: Retrieves the command-line arguments used to launch the process.
- **Process State**: Displays the current state of the process (e.g., running, sleeping).
- **Parent Process ID (PPID)**: Fetches the parent process ID.
- **Memory Usage**: Displays the virtual memory size of the process.
- **Number of Threads**: Shows the number of threads used by the process.
- **Executable Path**: Gets the path to the executable of the running process.
- **Error Handling**: Gracefully handles errors such as invalid PID or file access issues.

## Requirements

- **C Compiler**: `gcc` or compatible C compiler.
- **Linux Operating System**: This program is designed to work on Linux-based systems as it uses the `/proc` filesystem.

## Installation

To build and run the project on a Linux-based system:

1. **Clone the repository**:
```bash
git clone https://github.com/0xAminED/Process-Hunter.git
cd Process-Hunter
```

2. **Compile the code**:
```bash
gcc -o Process_Hunter Process_Hunter.c
```
3. **Run the process scanner**:
```bash
./Process_Hunter
```

## Usage

The program requires the **Process ID (PID)** of the process whose details you want to retrieve.


### Example

```bash
Enter Process ID (PID): 1234
Fetching information for PID: 1234
Process Name: bash
Command-line: /bin/bash -c sleep 100
=== Status ===
State: S (sleeping)
PPid: 1000
Threads: 1
VmSize: 12456 kB
Executable Path: /usr/bin/bash
```


## Explanation of Output

- **Process Name**: Displays the name of the process.
- **Command-line**: Shows the full command line used to start the process.
- **State**: The current state of the process (e.g., sleeping, running).
- **Parent Process ID (PPid)**: The PID of the parent process that spawned the current process.
- **Threads**: Displays The number of threads associated with the process.
- **VmSize**: The virtual memory size allocated to the process.
- **Executable Path**: The full path to the executable file running the process.



## License
This project is licensed under the MIT License - see the LICENSE file for details.







