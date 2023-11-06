//Aluno: Mateus Brazil de Oliveira
//Matricula: 202003447031

//Questão 3
/*
    Crie um programa de exemplo (baseado em alguma situação real) usando o conceito de mutex.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define INITIAL_BALANCE 1000

pthread_mutex_t mutex;
int account_balance = INITIAL_BALANCE;

void* deposit(void* args) {
    int deposit_amount = *((int*)args);
    int counter = 0; 
            
    pthread_mutex_lock(&mutex);
    account_balance += deposit_amount;
    printf("Deposito: +%d, Novo saldo: %d\n", deposit_amount, account_balance);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void* withdraw(void* args) {
    int withdraw_amount = *((int*)args);

    pthread_mutex_lock(&mutex);
    if (account_balance >= withdraw_amount) {
        account_balance -= withdraw_amount;
        printf("Saque: -%d, Novo saldo: %d\n", withdraw_amount, account_balance);
    } else {
        printf("Saque: Saldo insuficiente\n");
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int deposit_amounts[NUM_THREADS] = {200, 300, 500, 800};
    int withdraw_amounts[NUM_THREADS] = {150, 400, 700, 500};

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, deposit, &deposit_amounts[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, withdraw, &withdraw_amounts[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
