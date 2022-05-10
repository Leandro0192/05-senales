								/*Ejercicio 7*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void manejador(){

	pid_t status,pid1;
	 
	
	pid1 = wait(&status);
	
	write(STDOUT_FILENO,"Hijo terminó\n",sizeof("Hijo termino\n"));
	printf("PID: %d\n", pid1);// Lo que devuelve funcìon wait
	printf("wait(&status): %d\n", status); //Lo que devulve wait(&status)
	   
}


int main ()
{
 signal(SIGCHLD, manejador);
 pid_t pid;
 
 pid = fork();
 if(pid==0)
 	{
 		printf("Hijo, PID: %d\n",getpid());
 		sleep(2);
 		exit(0);
 	}else{
 	
	sleep(10);
	
	return(0);
	}
		 	
}
