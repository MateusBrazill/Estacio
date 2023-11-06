//Aluno: Mateus Brazil de Oliveira
//Matricula: 202003447031

//Questão 4
/*
    Desenvolver um programa contendo uma função que faça algum tipo de cálculo (por exemplo, potenciação, multiplicação, fatorial) 
    e crie múltiplas threads usando a biblioteca pthreads.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define QNT_FAC 16

unsigned long long result = 1;
pthread_mutex_t mutex;

void* partial_factorial(void* args) {
    int thread_id = *((int*)args);
    unsigned long long partial_result = 1;

    for (int i = thread_id + 1; i <= QNT_FAC; i += NUM_THREADS){ 
        partial_result *= i;
    }
    
    pthread_mutex_lock(&mutex);
    result *= partial_result;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, partial_factorial, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) pthread_join(threads[i], NULL);
    
    pthread_mutex_destroy(&mutex);

    printf("Fatorial de %d é %llu\n", QNT_FAC, result);

    return 0;
}
