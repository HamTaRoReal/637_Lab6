#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum, csum;
void *runner(void *param);

int main(int argc, char*argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid,NULL);
    int sum = atoi(argv[1]);
    printf("sum = %d\n", sum);
    
    for(int i = 0; i <= sum; i++){
        msum += i;
    }
    printf("msum = %d\n", msum);
    printf("dif = %d\n", csum - msum);
    return 0;
}

void *runner(void *param){
    int upper = atoi(param);
    csum = 0;
    if(upper > 0){
        for(int i = 0; i <= 2*upper; i++){
            csum += i;
        }
        printf("csum = %d\n",csum);
    }
    pthread_exit(0);
}
