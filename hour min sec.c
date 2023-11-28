#include<stdio.h>
#include<stdlib.h>
void display(unsigned short int);
int main(){
	// we cant store odd seconds
	int hours,minutes,seconds;
	printf("Time format HH:MM:SS\n");
	printf("Enter hours minutes seconds : ");
	scanf("%d:%d:%d",&hours,&minutes,&seconds);
	if(hours>=24 || minutes>59 || seconds>59 )  {
		printf("wrong input ");
		return 0;
	}
	unsigned short int hms = 0;
	hms += seconds / 2;
	hms += (minutes <<5 );
	hms += (hours << 11);
	display(hms);
	return EXIT_SUCCESS;
}
void display(unsigned short int hms){
	int seconds = hms % (1<<5);
	int minutes = (hms % (1<<11)) >> 5;
	int hours = hms >> 11;
	printf("%d:%d:%d",hours,minutes,seconds*2);
}