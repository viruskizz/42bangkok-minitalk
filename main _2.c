/* ---------------------------------------------------------------- */
/* PROGRAM  process-a.c:                                            */
/*   This program demonstrates the use of the kill() system call.   */
/* This process must run before process-b.c because it creates a    */
/* shared memory segment for storing its process id.                */
/* ---------------------------------------------------------------- */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
/* ---------------------------------------------------------------- */
/*                 signal handler function prototypes               */
/* ---------------------------------------------------------------- */

void  SIGINT_handler(int);         /* for SIGINT                    */
void  SIGQUIT_handler(int);        /* for SIGQUIT                   */

/* ---------------------------------------------------------------- */
/*                         global variable                          */
/* ---------------------------------------------------------------- */

int   ShmID;                       /* shared memory ID              */
pid_t *ShmPTR;                     /* shared memory pointer         */

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void main(void)
{
     int   i;
     pid_t pid = getpid();
     key_t MyKey;
                    
     if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("SIGINT install error\n");
          exit(1);
     }
     if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) {
          printf("SIGQUIT install error\n");
          exit(2);
     }

     MyKey   = ftok(".", 's');     /* create a shared memory segment*/
     ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     *ShmPTR = pid;                /* save my pid there             */
     
     for (i = 0; ; i++) {          /* generating output             */
          printf("From process %d: %d\n", pid, i);
          sleep(1);
     }
}

/* ---------------------------------------------------------------- */
/* FUNCTION  SIGINT_handler:                                        */
/*    SIGINT signal handler.  It only reports that a Ctrl-C has     */
/* been received.   Nothing else.                                   */
/* ---------------------------------------------------------------- */

void  SIGINT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGINT: just got a %d (SIGINT ^C) signal\n", sig);
     signal(sig, SIGINT_handler);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  SIGQUIT_handler:                                       */
/*    SIGQUIT signal handler.   When SIGQUIT arrives, this handler  */
/* shows a message, removes the shared memory segment, and exits.   */
/* ---------------------------------------------------------------- */

void  SIGQUIT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal"
                          " and is about to quit\n", sig);
     shmdt(ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);
     
     exit(3);
}

          