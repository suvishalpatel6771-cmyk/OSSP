#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "process_lifecycle.h"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
#define WHITE   "\033[97m"
#define GRAY    "\033[90m"

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_header()
{
    printf(CYAN);
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                    PROCESS LIFE CYCLE PROJECT                       ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf(RESET);
}

void print_footer()
{
    printf("\n");
    printf(GRAY);
    printf("  Operating System & System Programming | C Language\n");
    printf("  Build  •  Execute  •  Wait  •  Terminate\n");
    printf(RESET);
}

void show_dashboard(pid_t parent_pid)
{
    clear_screen();

    print_header();

    printf("\n");

    /* LEFT NAVIGATION */
    printf(BLUE "  ┌───────────────────────┐\n" RESET);
    printf(BLUE "  │       NAVIGATION      │\n" RESET);
    printf(BLUE "  ├───────────────────────┤\n" RESET);
    printf("  │ " GREEN "1" RESET "  Home               │\n");
    printf("  │ " CYAN "2" RESET "  Process Creation   │\n");
    printf("  │ " CYAN "3" RESET "  Process Execution   │\n");
    printf("  │ " YELLOW "4" RESET "  Process Waiting     │\n");
    printf("  │ " PURPLE "5" RESET "  Process Termination │\n");
    printf("  │ " WHITE "6" RESET "  Exit               │\n");
    printf(BLUE "  └───────────────────────┘\n" RESET);

    printf("\n");

    /* PROJECT INFORMATION */
    printf(CYAN "  PROCESS LIFE CYCLE PROJECT\n" RESET);
    printf("  ──────────────────────────────────────────────────────────────\n");

    printf("\n  This project demonstrates the complete life cycle of a process\n");
    printf("  in an Operating System using the C programming language.\n\n");

    /* FOUR CARDS */
    printf("  ┌────────────────────┐   ┌────────────────────┐\n");
    printf("  │ " BLUE "1  CREATION" RESET "        │   │ " GREEN "2  EXECUTION" RESET "      │\n");
    printf("  │                    │   │                    │\n");
    printf("  │   fork()           │   │   exec()           │\n");
    printf("  │   Create child     │   │   Run program      │\n");
    printf("  └────────────────────┘   └────────────────────┘\n\n");

    printf("  ┌────────────────────┐   ┌────────────────────┐\n");
    printf("  │ " YELLOW "3  WAITING" RESET "         │   │ " PURPLE "4  TERMINATION" RESET "   │\n");
    printf("  │                    │   │                    │\n");
    printf("  │   wait()           │   │   exit()           │\n");
    printf("  │   Synchronize      │   │   Finish process   │\n");
    printf("  └────────────────────┘   └────────────────────┘\n");

    printf("\n");

    printf(CYAN "  SYSTEM CALLS\n" RESET);
    printf("  fork() | exec() | wait() | exit() | getpid() | getppid()\n");

    printf("\n");

    printf(CYAN "  PROJECT FILES\n" RESET);
    printf("  main.c | process_creation.c | process_execution.c\n");
    printf("  process_termination.c | process_lifecycle.h\n");

    print_footer();
}

int main()
{
    pid_t parent_pid = getpid();
    pid_t child_pid;
    int choice;

    while (1)
    {
        show_dashboard(parent_pid);

        printf("\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                break;

            case 2:
                child_pid = fork();

                if (child_pid < 0)
                {
                    printf("Fork failed!\n");
                    exit(1);
                }

                if (child_pid == 0)
                {
                    process_creation(parent_pid);
                    exit(0);
                }
                else
                {
                    wait(NULL);
                }
                break;

            case 3:
                child_pid = fork();

                if (child_pid < 0)
                {
                    printf("Fork failed!\n");
                    exit(1);
                }

                if (child_pid == 0)
                {
                    process_execution(getpid(), parent_pid);
                    exit(0);
                }
                else
                {
                    wait(NULL);
                }
                break;

            case 4:
                child_pid = fork();

                if (child_pid < 0)
                {
                    printf("Fork failed!\n");
                    exit(1);
                }

                if (child_pid == 0)
                {
                    sleep(1);
                    exit(0);
                }
                else
                {
                    process_waiting(child_pid);
                    wait(NULL);
                }
                break;

            case 5:
                child_pid = fork();

                if (child_pid < 0)
                {
                    printf("Fork failed!\n");
                    exit(1);
                }

                if (child_pid == 0)
                {
                    exit(0);
                }
                else
                {
                    process_termination(child_pid);
                    wait(NULL);
                }
                break;

            case 6:
                clear_screen();

                printf("\n");
                printf(GREEN);
                printf("  ╔════════════════════════════════════════════════════════╗\n");
                printf("  ║       PROCESS LIFE CYCLE COMPLETED SUCCESSFULLY      ║\n");
                printf("  ╚════════════════════════════════════════════════════════╝\n");
                printf(RESET);

                return 0;

            default:
                printf("\n  Invalid choice. Please select 1-6.\n");
                sleep(1);
        }
    }

    return 0;
}