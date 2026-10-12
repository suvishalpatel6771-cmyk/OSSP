#include <stdio.h>
#include <unistd.h>
#include "process_lifecycle.h"

/* ANSI colors */
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[97m"
#define GRAY    "\033[90m"

void process_creation(pid_t parent_pid)
{
    clear_screen();

    printf(CYAN);
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                 PROCESS LIFE CYCLE PROJECT                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");
    printf(BLUE "  PROCESS CREATION\n" RESET);
    printf("  ────────────────────────────────────────────────────────────\n\n");

    printf("  Parent Process\n");
    printf("  PID : " GREEN "%d" RESET "\n\n", parent_pid);

    printf(YELLOW "  Creating child process using fork()...\n\n" RESET);

    printf("                 " CYAN "fork()" RESET "\n");
    printf("                   │\n");
    printf("             ┌─────┴─────┐\n");
    printf("             │           │\n");
    printf("             ▼           ▼\n");

    printf("       ┌─────────────┐   ┌─────────────┐\n");
    printf("       │   PARENT    │   │    CHILD    │\n");
    printf("       │             │   │             │\n");
    printf("       │ PID: %-7d│   │ PID: %-7d│\n",
           parent_pid, getpid());
    printf("       └─────────────┘   └─────────────┘\n\n");

    printf(GREEN "  ✓ fork() system call ready\n" RESET);
    printf(GREEN "  ✓ Parent process identified\n" RESET);
    printf(GREEN "  ✓ Child process created\n" RESET);

    printf("\n  " GRAY "Press ENTER to return..." RESET);
    getchar();
}