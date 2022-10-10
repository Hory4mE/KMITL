//64050156 พงศธร ธุระเสร็จ
// Q1 20! = 2432902008176640000
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
signed long prev_computed, i;
/* global variables */
void SIGhandler(int sig) { // no need prototype
printf("\nReceived a ");
printf("SIGUSR1. The max n is ");
printf("%ld! = %ld\n", i-1, prev_computed);
exit(0);
}
int main(void) {
signed long cur_value;
//to know type size,
printf("%ld\n",sizeof(long));
printf("2 power n:\n");
signal(SIGUSR1, SIGhandler);
/* install SIGUSR1 handler */
prev_computed = 1;
for (i = 1; ; i++ ) { // loop until raise()
cur_value = prev_computed * i;// 2 to the n
if (cur_value < prev_computed)
raise(SIGUSR1); /* overflow, raise */
prev_computed = cur_value;
/* after raise prev is the last value possible */
} //for
return 0;
} //main