#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread(void *arg) {
        pthread_detach(pthread_self());
        pthread_exit((void*) 42);
}

int main(void) {
	int i = 0;
        pthread_t tid;
        pthread_create(&tid, NULL, thread, (void*)&i);
        pthread_join(tid, (void**)&i);
        printf("%d\n", i);
} 

