
#include<stdio.h>
#include<pthread.h>

#define G 10
#define G_THREAD 4


int a[]={1,7,8,10,12,16,20,21,22,24};

int sum[4]={0};
int part=0;


void*sum_array(void*arg)
{

int thread_part=part++;

for(int b=thread_part*(G/4);b<(thread_part+1)*(G/4);b++)

sum[thread_part]+=a[b];
}

int main()
{

pthread_t threads[G_THREAD];

for(int b=0;b<G_THREAD;b++)
pthread_create(&threads[b],NULL,sum_array,(void*)NULL);
for(int b=0;b<G_THREAD;b++)

pthread_join(threads[b],NULL);


int total_sum=0;

for(int b=0;b<G_THREAD;b++)
total_sum+=sum[b];
printf("sum is %b\n",total_sum);

return 0;
}
