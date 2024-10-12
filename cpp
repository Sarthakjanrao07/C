#include <iostream>
using namespace std;
void Bankers(int need[][10], int available[], int allocated[][10], int p, int n) {
 int n_available[n];
 bool finish[p] = { false };
 int safeSeq[p];
 int count = 0;
 
 for (int i = 0; i < n; i++) {
 n_available[i] = available[i];
 }
 while (count < p) {
 bool found = false;
 for (int i = 0; i < p; i++) {
 if (!finish[i]) {
 bool canAllocate = true;
 for (int j = 0; j < n; j++) {
 if (need[i][j] > n_available[j]) {
 canAllocate = false;
 break;
 }
 }
 if (canAllocate) {
 for (int j = 0; j < n; j++) {
 n_available[j] += allocated[i][j];
 }
 safeSeq[count++] = i;
 finish[i] = true;
 found = true;
 }
 }
 }
 if (!found) {
 cout << "\nSystem is not in a safe state." << endl;
 return;
 }
 }
 cout << "System is in a safe state.\nSafe Sequence is: ";
 for (int i = 0; i < p; i++) {
 cout << safeSeq[i] << " ";
 }
 cout << endl;
}
int main() {
 int i, j, n;
 cout << "\nEnter the number of Resources: ";
 cin >> n;
 int t_resource[n];
 cout << "\nEnter the instances of Resources:" << endl;
 for (i = 0; i < n; i++) {
 cout << "R" << i + 1 << ": ";
 cin >> t_resource[i];
 }
 int p;
 cout << "\nEnter the Number of Processes: ";
 cin >> p;
 int allocated[p][10], max[p][10], need[p][10];
 int t_allocated[10] = {0}, available[10];
 cout << "\nEnter the values of Allocated matrix: " << endl;
 for (i = 0; i < p; i++) {
 for (j = 0; j < n; j++) {
 cin >> allocated[i][j];
 }
 }
 cout << "\nAllocated Matrix" << endl;
 for (i = 0; i < p; i++) {
 for (j = 0; j < n; j++) {
 cout << allocated[i][j] << " ";
 }
 cout << endl;
 }
 cout << "\nEnter the values of Max matrix: " << endl;
 for (i = 0; i < p; i++) {
 for (j = 0; j < n; j++) {
 cin >> max[i][j];
 }
 }
 for (i = 0; i < p; i++) {
 for (j = 0; j < n; j++) {
 need[i][j] = max[i][j] - allocated[i][j];
 }
 }
 cout << "\nNeed Matrix" << endl;
 for (i = 0; i < p; i++) {
 for (j = 0; j < n; j++) {
 cout << need[i][j] << " ";
 }
 cout << endl;
 }
 for (j = 0; j < n; j++) {
 for (i = 0; i < p; i++) {
 t_allocated[j] += allocated[i][j];
 }
 }
 
 cout << "\nTotal Allocated" << endl;
 for (i = 0; i < n; i++) {
 cout << t_allocated[i] << " ";
 }
 for (i = 0; i < n; i++) {
 available[i] = t_resource[i] - t_allocated[i]; 
 }
 
 cout << "\nAvailable: " << endl;
 for (i = 0; i < n; i++) {
 cout << available[i] << " ";
 }
 
 Bankers(need, available, allocated, p, n);
 
 return 0;
}

-----------------------------------------------------------------------------------------------------------------
 //999999999999999999999999999999

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10 
// FIFO Page Replacement
void fifo(int incomingStream[], int pages, int frames) {
int temp[MAX_FRAMES];
int pageFaults = 0;
for (int m = 0; m < frames; m++) {
temp[m] = -1; 
}
printf("\nFIFO Page Replacement:\n");
printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
for (int m = 0; m < pages; m++) {
int s = 0; 
for (int n = 0; n < frames; n++) {
if (incomingStream[m] == temp[n]) {
s++;
break; 
}
}
if (s == 0) { 
temp[pageFaults % frames] = incomingStream[m]; 
pageFaults++; 
}
printf("%d\t\t", incomingStream[m]);
for (int n = 0; n < frames; n++) {
if (temp[n] != -1)
printf("%d\t\t", temp[n]);
else
printf("-\t\t");
}
printf("\n");
}
printf("Total Page Faults: %d\n", pageFaults);
}
// LRU Page Replacement
void lru(int incomingStream[], int pages, int frames) {
int frame[MAX_FRAMES], time[MAX_FRAMES];
int pageFaults = 0;
for (int i = 0; i < frames; i++) {
frame[i] = -1; 
time[i] = 0; 
}
printf("\nLRU Page Replacement:\n");
printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
for (int m = 0; m < pages; m++) {
int s = 0; 
for (int n = 0; n < frames; n++) {
if (frame[n] == incomingStream[m]) {
s = 1; 
time[n] = m; 
break;
}
}
if (s == 0) { 
int pos = 0, minimum = time[0];
for (int n = 1; n < frames; n++) {
if (time[n] < minimum) {
minimum = time[n];
pos = n; 
}
}
frame[pos] = incomingStream[m]; 
time[pos] = m; 
pageFaults++; 
}
printf("%d\t\t", incomingStream[m]);
for (int n = 0; n < frames; n++) {
if (frame[n] != -1)
printf("%d\t\t", frame[n]);
else
printf("-\t\t");
}
printf("\n");
}
printf("Total Page Faults: %d\n", pageFaults);
}
// Optimal Page Replacement
void optimal(int incomingStream[], int pages, int frames) {
int frame[MAX_FRAMES], pageFaults = 0;
for (int i = 0; i < frames; i++) {
frame[i] = -1; 
}
printf("\nOptimal Page Replacement:\n");
printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
for (int m = 0; m < pages; m++) {
int s = 0; 
for (int n = 0; n < frames; n++) {
if (frame[n] == incomingStream[m]) {
s = 1; 
break;
}
}
if (s == 0) { 
int pos = -1, farthest = m; 
for (int n = 0; n < frames; n++) {
int j;
for (j = m + 1; j < pages; j++) {
if (frame[n] == incomingStream[j]) {
if (j > farthest) {
farthest = j; 
pos = n; 
}
break;
}
}
if (j == pages) { 
pos = n; 
break;
}
}
frame[pos] = incomingStream[m]; 
pageFaults++; 
}
printf("%d\t\t", incomingStream[m]);
for (int n = 0; n < frames; n++) {
if (frame[n] != -1)
printf("%d\t\t", frame[n]);
else
printf("-\t\t");
}
printf("\n");
}
printf("Total Page Faults: %d\n", pageFaults);
}
int main() {
int choice, pages = MAX_PAGES, frames;
// Allocate memory for incomingStream
int* incomingStream = (int*)malloc(MAX_PAGES * sizeof(int));
if (incomingStream == NULL) {
printf("Memory allocation failed.\n");
return 1;
}
printf("Enter the page references (space-separated, max %d): ", MAX_PAGES);
char input[256]; // Buffer for user input
fgets(input, sizeof(input), stdin); // Read the entire line
// Parse the input into incomingStream
char* token = strtok(input, " ");
int count = 0;
while (token != NULL && count < MAX_PAGES) {
incomingStream[count++] = atoi(token);
token = strtok(NULL, " ");
}
// Update the number of pages based on user input
int pagesEntered = count;
printf("Enter the number of frames (max %d): ", MAX_FRAMES);
scanf("%d", &frames);
if (frames > MAX_FRAMES) {
printf("Number of frames exceeds the maximum limit.\n");
free(incomingStream);
return 1;
}
do {
printf("\nSelect Page Replacement Algorithm:\n");
printf("1. FIFO\n");
printf("2. LRU\n");
printf("3. Optimal\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
fifo(incomingStream, pagesEntered, frames);
break;
case 2:
lru(incomingStream, pagesEntered, frames);
break;
case 3:
optimal(incomingStream, pagesEntered, frames);
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please select again.\n");
}
} while (choice != 4);
// Free allocated memory
free(incomingStream);
return 0;
}

----------------------------------------10---------------------------------------------

 client.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
struct data{
char str[100];
int flag;
};
void main()
{
key_t key = ftok("2.txt",'A');
int shmid = shmget(key,1024,0777|IPC_CREAT);
struct data *d = shmat(shmid,NULL,0);
d->flag=0;
while(d->flag!=1)
{
printf("\nWaiting");
sleep(2);
}
printf("\nAccepted data is ");
printf("%s",d->str);
d->flag=-1;
shmdt(d);
}
Server.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
struct data{
char str[100];
int flag;
};
void main()
{
key_t key = ftok("2.txt",'A');
int shmid = shmget(key,1024,0777|IPC_CREAT);
struct data *d = shmat(shmid,NULL,0);
d->flag=0;
printf("\nEnter data ");
scanf("%s",d->str);
d->flag=1;
while(d->flag!=-1)
{
printf("\nWaiting");
sleep(2);
}
shmdt(d);
shmctl(shmid,IPC_RMID,NULL);
}

