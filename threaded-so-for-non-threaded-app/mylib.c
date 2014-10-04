#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *_thread(void *arg) {
	int i;
	struct addrinfo *res;
	
	for (i=0; i<10000; i++) {
		if (getaddrinfo("localhost", NULL, NULL, &res) == 0) {
			if (res) freeaddrinfo(res);
		}
	}
	
	pthread_mutex_lock(&mutex);
	printf("Just another thread message!\n");
	pthread_mutex_unlock(&mutex);
	
	return NULL;
}

void make_thread() {
	pthread_t tid[10];
	int i, rc;
	
	for (i=0; i<10; i++) {
		rc = pthread_create(&tid[i], NULL, _thread, NULL);
		assert(rc == 0);
	}
	
	void *rv;
	for (i=0; i<10; i++) {
		rc = pthread_join(tid[i], &rv);
		assert(rc == 0);
	}
}
