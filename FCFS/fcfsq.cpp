#include <stdio.h>

int main() {
    int n, i, j;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of processes should be positive.\n");
        return 1;
    }

    int pid[n], arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n];

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter the arrival time and burst time of process %d: ", pid[i]);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    // Sorting based on arrival time, and if same, then based on smaller PID
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j] || (arrival_time[i] == arrival_time[j] && pid[i] > pid[j])) {
                // Swap arrival time
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                // Swap burst time
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap PID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculating completion, turnaround and waiting times
    for (i = 0; i < n; i++) {
        if (i == 0) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            if (arrival_time[i] <= completion_time[i - 1]) {
                completion_time[i] = completion_time[i - 1] + burst_time[i];
            } else {
                completion_time[i] = arrival_time[i] + burst_time[i];
            }
        }
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time += waiting_time[i];
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}