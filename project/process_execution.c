#include <stdio.h>
#include <unistd.h>
#include "process_lifecycle.h"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[97m"
#define GRAY    "\033[90m"

void process_execution(pid_t child_pid, pid_t parent_pid)
{
    clear_screen();

    printf(CYAN);
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                 PROCESS LIFE CYCLE PROJECT                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");
    printf(BLUE "  PROCESS EXECUTION\n" RESET);
    printf("  ────────────────────────────────────────────────────────────\n\n");

    printf("  Child Process\n");
    printf("  PID    : " GREEN "%d" RESET "\n", child_pid);
    printf("  Parent : " GREEN "%d" RESET "\n\n", parent_pid);

    printf(YELLOW "  Executing program using exec()...\n\n" RESET);

    printf("        ┌──────────────────────────────┐\n");
    printf("        │           exec()             │\n");
    printf("        │                              │\n");
    printf("        │  Replace current program    │\n");
    printf("        │  with another program       │\n");
    printf("        └──────────────────────────────┘\n\n");

    printf("  Command: " CYAN "ls -l" RESET "\n\n");

    printf(GREEN "  ✓ Child process is executing\n" RESET);
    printf(GREEN "  ✓ exec() loads the requested program\n" RESET);

    printf("\n  " GRAY "Press ENTER to return..." RESET);
    getchar();
}