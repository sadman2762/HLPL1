#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int server_id;
    int current_load;
} Server;

typedef struct {
    int task_id;
    int duration;
    int priority;
    int deadline;
} Task;

int cmp_servers(const void *a, const void *b) {
    Server *left = (Server *)a;
    Server *right = (Server *)b;
    return left->current_load - right->current_load;
}

int cmp_tasks(const void *a, const void *b) {
    Task *left = (Task *)a;
    Task *right = (Task *)b;
    return left->priority - right->priority;
}

int** optimize(int server_list_rows, int server_list_columns, int** server_list, int task_list_rows, int task_list_columns, int** task_list, int* result_rows, int* result_columns) {
    // Create arrays of Server and Task structures
    Server servers[server_list_rows];
    Task tasks[task_list_rows];

    // Initialize server and task data
    for (int i = 0; i < server_list_rows; i++) {
        servers[i].server_id = i + 1;
        servers[i].current_load = server_list[i][1];
    }
    for (int i = 0; i < task_list_rows; i++) {
        tasks[i].task_id = task_list[i][0];
        tasks[i].duration = task_list[i][1];
        tasks[i].priority = task_list[i][2];
        tasks[i].deadline = task_list[i][3];
    }

    // Sort servers by current load (ascending)
    qsort(servers, server_list_rows, sizeof(Server), cmp_servers);

    // Sort tasks by priority (ascending)
    qsort(tasks, task_list_rows, sizeof(Task), cmp_tasks);

    // Assign tasks to servers
    int** result = malloc(server_list_rows * sizeof(int*));
    for (int i = 0; i < server_list_rows; i++) {
        *(result + i) = malloc(sizeof(int));
        *(*(result + i)) = tasks[i].task_id;
        servers[i].current_load += tasks[i].duration;
    }

    // Calculate total energy consumption
    int total_energy = 0;
    for (int i = 0; i < task_list_rows; i++) {
        int server_id = *(*(result + i)) - 1;
        total_energy += tasks[i].duration * servers[server_id].current_load;
    }

    *result_rows = server_list_rows;
    *result_columns = 1;

    return result;
}

// Example usage
int main() {
    // Input data (servers_list and tasks_list)
    // ...

    // Call the optimize function
    int result_rows;
    int result_columns;
    int** result = optimize(num_servers, 2, servers, num_tasks, 4, tasks, &result_rows, &result_columns);

    // Print the result (server schedules and total energy consumption)
    // ...

    return 0;
}
