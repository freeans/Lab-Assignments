#include <stdio.h>
struct Process {
int id;
int arrivalTime;
int burstTime;
int waitingTime;
int turnAroundTime;
};
void calculateTimes(struct Process proc[], int n) {
int totalWaitingTime = 0, totalTurnAroundTime = 0;
int completionTime[n];
// Sort the processes by Arrival Time and Burst Time
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (proc[i].arrivalTime > proc[j].arrivalTime ||
(proc[i].arrivalTime == proc[j].arrivalTime &&
proc[i].burstTime > proc[j].burstTime)) {
struct Process temp = proc[i];
proc[i] = proc[j];
proc[j] = temp;
}
}
}
// Initialize the completion time of the first process
completionTime[0] = proc[0].arrivalTime + proc[0].burstTime;
proc[0].turnAroundTime = proc[0].burstTime;
proc[0].waitingTime = 0;
// Calculate waiting time and turn-around time for each process
for (int i = 1; i < n; i++) {
// Calculate completion time for this process
completionTime[i] = completionTime[i - 1] + proc[i].burstTime;
// Turn Around Time = Completion Time - Arrival Time
proc[i].turnAroundTime = completionTime[i] - proc[i].arrivalTime;
// Waiting Time = Turn Around Time - Burst Time
proc[i].waitingTime = proc[i].turnAroundTime - proc[i].burstTime;
}
// Display results
printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
for (int i = 0; i < n; i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime,
proc[i].arrivalTime, proc[i].waitingTime, proc[i].turnAroundTime);
totalWaitingTime += proc[i].waitingTime;
totalTurnAroundTime += proc[i].turnAroundTime;
}
printf("Average waiting time: %.2f\n", (float)totalWaitingTime / n);
printf("Average turn around time: %.2f\n", (float)totalTurnAroundTime / n);
}
int main() {
int n;
printf("Enter number of processes: ");
scanf("%d", &n);
struct Process proc[n];
// Input arrival time and burst time for each process
for (int i = 0; i < n; i++) {
proc[i].id = i + 1;
printf("Enter arrival time for process %d: ", proc[i].id);
scanf("%d", &proc[i].arrivalTime);
printf("Enter burst time for process %d: ", proc[i].id);
scanf("%d", &proc[i].burstTime);
}
// Calculate and display the scheduling results
calculateTimes(proc, n);
return 0;
