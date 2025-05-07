#include <stdio.h>
void printFrames(int frames[], int frameSize) {
for (int i = 0; i < frameSize; i++) {
if (frames[i] == -1) {
printf(" - ");
} else {
printf(" %d ", frames[i]);
}
}
printf("\n");
}
int findOptimal(int frames[], int frameSize, int refString[], int refSize,
int currentIndex) {
int farthest = currentIndex;
int index = -1;
for (int i = 0; i < frameSize; i++) {
int j;
for (j = currentIndex; j < refSize; j++) {
if (frames[i] == refString[j]) {
if (j > farthest) {
farthest = j;
index = i;
}
break;
}
}
if (j == refSize) return i; // If not found in future, replace this
}
return index == -1 ? 0 : index;
}
void optimal(int refString[], int refSize, int frameSize) {
int frames[frameSize];
for (int i = 0; i < frameSize; i++) frames[i] = -1;
int pageFaults = 0;
printf("\nOptimal Page Replacement:\n");
for (int i = 0; i < refSize; i++) {
int found = 0;
for (int j = 0; j < frameSize; j++) {
if (frames[j] == refString[i]) {
found = 1;
break;
}
}
if (!found) {
int replaceIndex =
(i < frameSize)
? i
: findOptimal(frames, frameSize, refString, refSize, i + 1);
frames[replaceIndex] = refString[i];
pageFaults++;
}
printFrames(frames, frameSize);
}
printf("Total Page Faults: %d\n", pageFaults);
}
int main() {
int refSize, frameSize;
printf("Enter the number of pages in the reference string: ");
scanf("%d", &refSize);
int refString[refSize];
printf("Enter the reference string:\n");
for (int i = 0; i < refSize; i++) {
scanf("%d", &refString[i]);
}
printf("Enter the number of frames (minimum 3): ");
scanf("%d", &frameSize);
if (frameSize < 3) {
printf("Frame size should be at least 3.\n");
return 1;
}
optimal(refString, refSize, frameSize);
return 0;
}
