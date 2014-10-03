#include <pthread.h>
#include <assert.h>
#include <stdio.h>

void *_thread(void *arg) {
	printf("Just another thread message!\n");
	return NULL;
}

void make_thread() {
	pthread_t tid;
	int rc = pthread_create(&tid, NULL, _thread, NULL);
	assert(rc == 0);
	
	void *rv;
	rc = pthread_join(tid, &rv);
	assert(rc == 0);
}
