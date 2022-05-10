								/*Ejercicio 4*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void manejador(int a){

	write(STDOUT_FILENO,"Me rehuso a terminar\n",sizeof("Me rehuso a terminar\n"));   
}


int main ()
{
  //signal(SIGKILL, manejador);
  //signal(SIGINT, manejador);//Ctrl + c
  signal(SIGSTOP, manejador);  //Ctrl + Z
   
   printf("Proceso PID = %d\n", getpid());   
   
   while(1);
   
   exit(0);
}
