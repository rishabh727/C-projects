#  Port Scanner 

This is a simple asynchronous port scanner implemented in C++ using Boost.Asio library. It allows you to scan a range of ports on a specified host to determine which ports are open.

## Prerequisites

- C++ compiler that supports C++11 or later
- Boost.Asio library

## Installation

1. Install Boost.Asio library if you haven't already. You can download it from the [official website](https://www.boost.org/users/download/).
2. Compile the source code using your preferred C++ compiler. For example, if you're using g++, you can compile it with the following command:
    ```bash
    g++ -std=c++11 -o port_scanner port_scanner.cpp -lboost_system -lpthread
    ```
    Make sure to link against the Boost.System library (`-lboost_system`) and the pthread library (`-lpthread`).

## Usage

1. Run the compiled executable:
    ```bash
    ./port_scanner
    ```
2. Enter the target host, start port, and end port when prompted.

## Features

- Asynchronous scanning of multiple ports simultaneously.
- Progress bar indicating the scanning progress.
- Timeout for connection attempts to prevent indefinite blocking.
- Outputs the list of open ports after the scan is complete.

## Example

```bash
Enter the target host: example.com
Enter the start port: 1
Enter the end port: 100

