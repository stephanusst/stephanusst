#include <stdio.h>
#include <pthread.h>
#define MAX 1000000000 /* how many numbers to produce */
pthread mutex_t the_mutex;
pthread cond t condc, condp; /* used for signaling */
int buffer = 0; /* buffer used between producer and consumer */

void *producer(void *ptr) /* produce data */
{ 
	int i;
	for (i= 1; i <= MAX; i++) {
	pthread mutex lock(&the mutex); /* get exclusive access to buffer */
	while (buffer != 0) pthread cond wait(&condp, &the mutex);
		buffer = i; /* put item in buffer */
		pthread cond signal(&condc); /* wake up consumer */
		pthread mutex unlock(&the mutex); /* release access to buffer */
		}
	pthread exit(0);
}

void *consumer(void *ptr) /* consume data */
{ 
	int i;
	for (i = 1; i <= MAX; i++) {
	pthread mutex lock(&the mutex); /* get exclusive access to buffer */
	while (buffer ==0 ) pthread cond wait(&condc, &the mutex);
		buffer = 0; /* take item out of buffer */
		pthread cond signal(&condp); /* wake up producer */
		pthread mutex unlock(&the mutex); /* release access to buffer */
	}
	pthread exit(0);
}

int main(int argc, char **argv)
{
	pthread t pro, con;
	pthread mutex init(&the mutex, 0);
	pthread cond init(&condc, 0);
	pthread cond init(&condp, 0);
	pthread create(&con, 0, consumer, 0);
	pthread create(&pro, 0, producer, 0);
	pthread join(pro, 0);
	pthread join(con, 0);
	pthread cond destroy(&condc);
	pthread cond destroy(&condp);
	pthread mutex destroy(&the mutex);
}
