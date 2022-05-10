								/*Ejercicio 5*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void manejador(){

	write(STDOUT_FILENO,"Hijo terminó\n",sizeof("Hijo termino\n"));   
}


int main ()
{
 
//pid_t pid1,pid2,pid3;

signal(SIGCHLD, manejador);
  
  if (fork() == 0) {
  
		printf("Hijo 1 ,PID: %d\n", getpid());  
  		 while(1);
  		 
  }
  else {
  	if (fork() == 0){
  	
  	printf("Hijo 2 ,PID: %d\n", getpid());
  		while(1);
  		
  		}
  			 
  		else {
  			if(fork() == 0){
  	
  			printf("Hijo 3 ,PID: %d\n", getpid());
  			while(1);
  		
  			}
  			
  	}			
 	
	wait(NULL);
 	wait(NULL);
 	wait(NULL);
 	
	exit(0);
   }
}
