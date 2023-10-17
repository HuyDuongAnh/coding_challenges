/*
 *  Problem:
 *      Every thread rolls a dice, saved its value in an array.
 * 
 *      The main thread calculates the winner.
 * 
 *      Each thread prints a message with whether or not they lost or won.
*/
#define _POSIX_C_SOURCE 200112L
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define THREAD_NUM 4U

static int dice_array[THREAD_NUM] = {0};
// Create status array
static int status[THREAD_NUM] = {0};

// Barriers declaration
static pthread_barrier_t dice_calc;
static pthread_barrier_t determine_winner;

// Create a rolling dice function that populates dice values into the array
void *rolling_dice(void *vargp){
    int index = *(int *)vargp;
    int dice_val = rand() % 6 + 1;
    dice_array[index] = dice_val;
    pthread_barrier_wait(&dice_calc);
    pthread_barrier_wait(&determine_winner);
    if(status[index]){
        printf("Thread %d out of %d: I won!\n", index, THREAD_NUM);
    }
    else{
        printf("Thread %d out of %d: I lost!\n", index, THREAD_NUM);
    }
    free(vargp);
}

int main(){
    //Main thread
    time_t t;
    srand((unsigned) time(&t));

    //Initialize threads
    pthread_t th[THREAD_NUM];
    int i = 0, th_index = 0, max = 0;
    
    //Initialize barriers
    if(pthread_barrier_init(&dice_calc, NULL, THREAD_NUM) != 0){
        return 1;
    }
    if(pthread_barrier_init(&determine_winner, NULL, THREAD_NUM) != 0){
        return 1;
    }

    //Create threads
    for(i = 0; i < THREAD_NUM; ++i){
        if(th_index = malloc(sizeof(int)) == NULL){
            return 1;
        }
        th_index = i;
        if(pthread_create(&th[th_index], NULL, rolling_dice, NULL) != 0){
            perror("Failed to create the thread");
        }
    }

    pthread_barrier_wait(&dice_calc);
    //Calculate maximum values in dice value array
    for(i = 0; i < THREAD_NUM; ++i){
        max = ((max > dice_array[i]) ? dice_array[i] : max);
    }

    //Determine the winner
    for(i = 0; i < THREAD_NUM; ++i){
        if(max == dice_array[i]){
            status[i] = 1;
        }
    }

    pthread_barrier_wait(&determine_winner);

    //Join threads
    for(i = 0; i < THREAD_NUM; ++i){
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join the thread");
        }
    }

    //Destroy barriers
    pthread_barrier_destroy(&dice_calc);
    pthread_barrier_destroy(&determine_winner);

    return 0;
}