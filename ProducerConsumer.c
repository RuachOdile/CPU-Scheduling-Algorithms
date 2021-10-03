#include<stdio.h>
#include<stdlib.h>

int n,mutex=1,full=0,empty,x=0;

int main(){

int c;
printf("Enter the size of the buffer\n");
scanf("%d",&n);
empty =n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("1.Producer\t 2.Consumer\t 3.Exit\n");
while(1){

	printf("Enter your choice: \n");
	scanf("%d",&c);
	switch(c){
	
		case 1:
			if((mutex==1)&&(empty!=0))
				producer();
			else
				printf("Buffer full!!\n");
			break;
			
		case 2:
			if((mutex==1)&&(full!=0))
				consumer();
			else
				printf("Buffer is empty\n");	
			break;
		case 3:
			exit(0);
			break;			
	}

}
}

int wait(int s){
	
	return(--s);
}

int signal(int s){

	return(++s);
}

void producer(){

	mutex =wait(mutex);
	full =signal(full);
	empty =wait(empty);
	x++;
	printf("The Producer produced %d\n",x);
	mutex =signal(mutex);
}

void consumer(){

	mutex =wait(mutex);
	full =wait(full);
	empty= signal(empty);
	printf("The Consumer consumed %d\n",x);
	x--;
	mutex =signal(mutex);
	
}
