#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

void *_thread(void *arg) {
	int i;
	//char *buf;
	struct addrinfo *res;
	
	for (i=0; i<10000; i++) {
		if (getaddrinfo("localhost", NULL, NULL, &res) == 0) {
			if (res) freeaddrinfo(res);
		}
		//buf = malloc(1024*sizeof(char));
		//strcpy(buf, "abcdefghijklmnopqrstuvwuxyz");
		//free(buf);
	}
	
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
