#include<stdio.h>
#include<pthread.h>

int var1[2],var2[2];

void *Sum(void *arg){

int*arr;
arr= arg;
int n1,n2, sum;
n1= arr[0];
n2= arr[1];;
sum =n1+n2;
printf("The sum of the two numbers is %d\n",sum);
printf("End of thread\n");
}


void main(){
printf("Enter the number 1 for the first thread");
scanf("%d",&var1[0]);
printf("Enter the number 2 for the first thread");
scanf("%d",&var1[1]);

printf("Enter the number 1 for the second thread");
scanf("%d",&var2[0]);
printf("Enter the number 2 for the second thread");
scanf("%d",&var2[1]);



pthread_t thread1, thread2;
pthread_create(&thread1,NULL,Sum,var1);
pthread_create(&thread2,NULL,Sum,var2);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("The process ID of the first process id %lu\n",thread1);

printf("The process ID of the second process id %lu\n",thread2);



