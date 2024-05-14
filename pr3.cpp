#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *function1();
void *function2();
void *function3();
pthread_mutex_t first_mutex; //MUTEX LOCK
pthread_mutex_t second_mutex;
pthread_mutex_t third_mutex;

int main()
{
pthread_mutex_init(&first_mutex,NULL); //INITIALIZE THE LOCK
pthread_mutex_init(&second_mutex,NULL);
pthread_mutex_init(&third_mutex, NULL);
pthread_t one, two, three;
pthread_create(&one, NULL, function1, NULL); //CREATE THREAD
pthread_create(&two, NULL, function2, NULL);
pthread_create(&three, NULL, function3, NULL);
pthread_join(one, NULL);
pthread_join(two, NULL);
pthread_join(three, NULL);
printf("Thread joined\n");
}
void *function1( )
{
pthread_mutex_lock(&first_mutex); //TO ACQUIRE THE RESOURCE/MUTEX LOCK
printf("Thread ONE Acquired first_mutex\n");
sleep(1);
pthread_mutex_lock(&second_mutex);
printf("Thread ONE Acquired second_mutex\n");
pthread_mutex_unlock(&second_mutex); //TO RELEASE THE RESOURCE
printf("Thread ONE Released second_mutex\n");
pthread_mutex_unlock(&first_mutex);
printf("Thread ONE Released first_mutex\n");
}

void *function2( )
{
pthread_mutex_lock(&second_mutex);
printf("Thread TWO Acquired second_mutex\n");
sleep(1);
pthread_mutex_lock(&third_mutex);
printf("Thread TWO Acquired third_mutex\n");
pthread_mutex_unlock(&third_mutex);
printf("Thread TWO Released third_mutex\n");
pthread_mutex_unlock(&second_mutex);
printf("Thread TWO Released second_mutex\n");
}

void *function3( )
{
pthread_mutex_lock(&third_mutex);
printf("Thread THREE Acquired third_mutex\n");
sleep(1);
pthread_mutex_lock(&first_mutex);
printf("Thread THREE Acquired first_mutex\n");
pthread_mutex_unlock(&first_mutex);
printf("Thread THREE Released first_mutex\n");
pthread_mutex_unlock(&third_mutex);
printf("Thread THREE Released third_mutex\n");
}
