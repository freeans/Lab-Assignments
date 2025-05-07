/*2Bparent.c*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
char *args[n + 2];
args[0] = "./2Bchild"; // Program to execute
args[n + 1] = NULL; // Null terminate the arguments
printf("Enter the elements of the array:\n");
for (int i = 1; i <= n; i++) {
args[i] = (char *)malloc(10 * sizeof(char));
scanf("%s", args[i]);
}
pid_t pid = fork();
if (pid < 0) {
perror("Fork failed");
exit(EXIT_FAILURE);
}
if (pid == 0) {
// Child process
execve(args[0], args, NULL);
perror("Execve failed");
exit(EXIT_FAILURE);
} else { // Parent process
wait(NULL);
printf("Parent process: Child process has completed.\n");
for (int i = 1; i <= n; i++) {
free(args[i]);
}}
return 0;
}
(Save both parent and child separate and run by giving path of child program in parent like shown in above program in bold line.)
/*2Bchild.c*/
#include <stdio.h>
int main(int argc, char *argv[]) {
printf("Array in reverse order:\n");
for (int i = argc - 1; i > 0; i--) {
printf("%s ", argv[i]);
}
printf("\n");
return 0;
}
