#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void get_process_info(pid_t pid) {
    char path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *file;

    printf("Fetching information for PID: %d\n", pid);

    // Fetch process name
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    file = fopen(path, "r");
    if (file) {
        if (fgets(buffer, sizeof(buffer), file)) {
            printf("Process Name: %s", buffer);
        }
        fclose(file);
    } else {
        perror("Error reading process name");
    }

    // Fetch command-line arguments
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
    file = fopen(path, "r");
    if (file) {
        printf("Command-line: ");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s ", buffer);
        }
        printf("\n");
        fclose(file);
    } else {
        perror("Error reading command-line");
    }

    // Fetch process state and parent process ID
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    file = fopen(path, "r");
    if (file) {
        printf("=== Status ===\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strncmp(buffer, "State:", 6) == 0 || 
                strncmp(buffer, "PPid:", 5) == 0 || 
                strncmp(buffer, "Threads:", 8) == 0 || 
                strncmp(buffer, "VmSize:", 7) == 0) {
                printf("%s", buffer);
            }
        }
        fclose(file);
    } else {
        perror("Error reading process status");
    }

    // Fetch executable path
    snprintf(path, sizeof(path), "/proc/%d/exe", pid);
    if (readlink(path, buffer, sizeof(buffer)) != -1) {
        printf("Executable Path: %s\n", buffer);
    } else {
        perror("Error reading executable path");
    }

    printf("\n");
}

int main() {
    pid_t pid;

    printf("Enter Process ID (PID): ");
    if (scanf("%d", &pid) != 1) {
        fprintf(stderr, "Invalid input. Please enter a valid PID.\n");
        return EXIT_FAILURE;
    }

    if (pid <= 0) {
        fprintf(stderr, "Invalid PID. PID must be a positive number.\n");
        return EXIT_FAILURE;
    }

    get_process_info(pid);

    return EXIT_SUCCESS;
}
