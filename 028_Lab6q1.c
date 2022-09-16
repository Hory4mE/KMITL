//64050156 พงศธร ธุระเสร็จ
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//global var
int msum = 0;
int csum = 0;
int diff = 0;

void *runner(void *param); // return void

int main(int argc, char *argv[])// input in argv
{
    pthread_t tid; // call child
    pthread_attr_t attr; // used for child
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]); // fork in multiverse

    pthread_join(tid, NULL); // while(wait NULL) wait child
    int upper = atoi(argv[1]); // change to int like parseint
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            msum += i;
        }
    }
    diff = csum - msum;
    printf("msum = %d   csum = %d\n", msum,csum);
    printf("diff = %d\n",diff);
    return 0;
}
void *runner(void *param)
{
    int upper = (atoi(param) * 2);
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            csum += i;
        }
        pthread_exit(0);
    }
}

// ได้ 2 แบบ โดยจะมีแบบที่แม่เสร็จก่อนทำให้ลูกติดเป็นค่าลบ กับ ลูกเสร็จก่อนทำให้แม่เป็นค่าบวก