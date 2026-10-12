#ifndef PROCESS_LIFECYCLE_H
#define PROCESS_LIFECYCLE_H

#include <sys/types.h>

void show_dashboard(pid_t parent_pid);
void process_creation(pid_t parent_pid);
void process_execution(pid_t child_pid, pid_t parent_pid);
void process_waiting(pid_t child_pid);
void process_termination(pid_t child_pid);

void clear_screen();
void print_header();
void print_footer();

#endif