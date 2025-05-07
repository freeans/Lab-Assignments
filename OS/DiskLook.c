#include <stdio.h>
#include <stdlib.h>
int main() {
int n, i, head, total_movement = 0;
printf("Enter the number of requests: ");
scanf("%d", &n);
int requests[n];
printf("Enter the request sequence: ");
for (i = 0; i < n; i++) {
scanf("%d", &requests[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &head);
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
// C-LOOK algorithm
for (i = 0; i < n && requests[i] < head; i++)
;
for (; i < n; i++) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
if (i > 0) {
total_movement += abs(head - requests[0]);
head = requests[0];
for (i = 1; i < n; i++) {
printf("Serviced request: %d\n", requests[i]);
total_movement += abs(head - requests[i]);
head = requests[i];
}
}
printf("Total head movement: %d\n", total_movement);
return 0;
}
