#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "process_lifecycle.h"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
#define GRAY    "\033[90m"

void process_waiting(pid_t child_pid)
{
    clear_screen();

    printf(CYAN);
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                 PROCESS LIFE CYCLE PROJECT                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");
    printf(YELLOW "  PROCESS WAITING\n" RESET);
    printf("  ────────────────────────────────────────────────────────────\n\n");

    printf("  Parent Process is waiting for:\n\n");

    printf("              PARENT\n");
    printf("                │\n");
    printf("              wait()\n");
    printf("                │\n");
    printf("                ▼\n");
    printf("              CHILD\n");
    printf("              PID: %d\n\n", child_pid);

    printf(GREEN "  ✓ wait() synchronizes parent and child\n" RESET);
    printf(GREEN "  ✓ Parent waits for child completion\n" RESET);

    printf("\n  " GRAY "Press ENTER to return..." RESET);
    getchar();
}

void process_termination(pid_t child_pid)
{
    clear_screen();

    printf(CYAN);
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                 PROCESS LIFE CYCLE PROJECT                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");
    printf(PURPLE "  PROCESS TERMINATION\n" RESET);
    printf("  ────────────────────────────────────────────────────────────\n\n");

    printf("  Child Process PID : %d\n\n", child_pid);

    printf("              Child Process\n");
    printf("                    │\n");
    printf("                  exit()\n");
    printf("                    │\n");
    printf("                    ▼\n");
    printf("              Terminated\n\n");

    printf("  Exit Status : " GREEN "0 (SUCCESS)" RESET "\n\n");

    printf(GREEN "  ✓ Child process terminated\n" RESET);
    printf(GREEN "  ✓ Exit status received\n" RESET);
    printf(GREEN "  ✓ Process life cycle completed\n" RESET);

    printf("\n  " GRAY "Press ENTER to return..." RESET);
    getchar();
}