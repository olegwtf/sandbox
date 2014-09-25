#include <pthread.h>
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "ppport.h"

void *thread(void *arg) {
	char *msg = (char*)arg;
	printf("thread: %s\n", msg);
	free(msg);
	return NULL;
}

MODULE = My	PACKAGE = My

void
test_thread(char *msg)
	PPCODE:
		char *thread_arg = malloc((strlen(msg)+1)*sizeof(char));
		strcpy(thread_arg, msg);
		pthread_t tid;
		pthread_create(&tid, NULL, thread, (void*)thread_arg);
		
		void *rv;
		pthread_join(tid, &rv);
