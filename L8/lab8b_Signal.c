// 64050156 พงศธร ธุระเสร็จ
/* Program demonstrates the use of kill() */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
int main(){
    pid_t pid = fork();
    if(pid==0){
        printf("Child Created\n");
        while(1);
        printf("this line should not be show\n");
        exit(0);
    }else{
        sleep(0);
        kill(pid, SIGINT);
    }
    printf("child has been killed\n");
    return 0;
}