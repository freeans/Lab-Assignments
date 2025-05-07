#include <stdio.h>
#include <stdlib.h>
int main() {
int n, i, head, total_movement = 0, direction;
printf("Enter the number of requests: ");
scanf("%d", &n);
int requests[n];
printf("Enter the request sequence: ");
for (i = 0; i < n; i++) {
scanf("%d", &requests[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &head);
printf("Enter the disk size (last cylinder number): ");
int disk_size;
scanf("%d", &disk_size);
printf("Enter the direction (1 for high, 0 for low): ");
scanf("%d", &direction);
// Sort the request array
for (i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (requests[i] > requests[j]) {
int temp = requests[i];
requests[i] = requests[j];
requests[j] = temp;
}
}
}
// SCAN algorithm
if (direction == 1) { // Move towards higher end
for (i = 0; i < n && requests[i] < head; i++)
;
for (; i < n; i++) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
if (head < disk_size - 1) {
total_movement += abs(head - (disk_size - 1));
head = disk_size - 1;
}
for (i--; i >= 0; i--) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
} else { // Move towards lower end
for (i = n - 1; i >= 0 && requests[i] > head; i--)
;
for (; i >= 0; i--) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
if (head > 0) {
total_movement += head;
head = 0;
}
for (i++; i < n; i++) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
}
printf("Total head movement: %d\n", total_movement);
return 0;
}
