#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

/*
Background
Security cameras often have an Ambient Light Sensor (ALS) which measures the amount of light around the camera and triggers a "night mode" when the ambient light is too low.

You've been given an ALS that reports sensor readings using the following struct:

```C
    struct SensorReading {
        int status;
        float lux;
        uint64_t timestamp; // time of reading
    };
```

To get a sensor reading, call:

    SensorReading read_next_sample();

This function will do one of two things:

The amount of light does not change within one second, the sensor returns NO_CHANGE in the status field. A total of one second elapses before the function unblocks.
The amount of light does change within one second, the sensor returns VALID in the status field and populates the lux and timestamp. A variable amount of time elapses before the function unblocks, between 0 and 1 seconds.
NOTE: The first call to read_next_sample will always return a valid value without blocking.

Working with blocking functions is hard and not thread-friendly, so we want to wrap the ALS function in a non-blocking, thread-safe way.

Tasks
Design and implement an API that allows users to read the most recent valid lux value. The API should be non-blocking and thread-safe.
Design and implement an API that allows users to read lux values from any time within the last 10 minutes. Your API should be non-blocking and thread-safe.

Expected Output
lux [1] = 3.94383, should be 3.94383
lux [2] = 3.35223, should be 3.35223
lux [3] = 5.5397, should be 5.5397
t: 0, lux: -1
t: 1, lux: 3.94383
t: 2, lux: 3.35223
t: 3, lux: 5.5397
t: 4, lux: -2
[execution time limit] 20 seconds (c)

[memory limit] 1 GB
*/

/* Status enum */
enum {
    ERROR = 0,
    NO_CHANGE = 1,
    VALID = 2,
};

/* Result from the vendor api */
typedef struct SensorReading {
    int status;
    float lux;
    uint64_t timestamp;
} SensorReading;

SensorReading myArray[600];
static int arrIndex = 0;

/* these functions are provided for you; no need to implement */
uint64_t get_timestamp();
struct SensorReading read_next_sample();

// Part 1
// Design and implement an API that allows users to read the most recent valid lux value. 
// The API should be non-blocking and thread-safe.
float get_most_recent_lux() {
    float validLux = 0;
    int tmpIdx = arrIndex;

    for (int i = 0; i<sizeof(myArray); i++) {
        if (myArray[tmpIdx].status == VALID) { 
            return myArray[tmpIdx].lux;
        }
        else {
            tmpIdx = --tmpIdx % (sizeof(myArray));
        }
    }
    return -1.0;
}

// Part 2
// return -2 if the input timestamp is in the future
// return -1 if the input timestamp is not represented in the history
float get_lux_at(uint64_t timestamp) {
    return -1.0;
}


// lock
pthread_mutex_t myMutex;

void *myThread(void *vargp){
    // sigset_t set = (sigset_t)SIGUSR1; 
    while (1){

        struct SensorReading tmpSample;
        tmpSample = read_next_sample();
        // Add lock here
        if(pthread_mutex_lock(&myMutex) == -1){
            return ERROR;
        }
        arrIndex = (arrIndex++)%sizeof(myArray);
        myArray[arrIndex] = tmpSample;
        // unlock here
        if(pthread_mutex_unlock(&myMutex) == -1){
            return ERROR;
        }
        // sigwait(&set);
    }

    pthread_exit(NULL);
}

int main() {
    uint64_t start = get_timestamp(); // don't move this from the start of main
    // create a thread to read the sensor dta and store the samples in a list of structures
    pthread_t   threadId;
    if(pthread_mutex_init(&myMutex, NULL) == -1){
        return ERROR;
    }
    if (pthread_create(&threadId, NULL, myThread, "thread to collect ALS samples") != 0) {
        perror("pthread_create() error");
        exit(1);
    }



    // Example behavior of read_next_sample, comment out when ready to start testing your code
    // for (int i = 0; i < 10; i++) {
    //     struct SensorReading reading = read_next_sample();
    //     printf("sample #: %d, status: %d, lux: %f, ts: %lu\n",
    //         i, reading.status, reading.lux, reading.timestamp);
    // }

    // tests for part 1
    usleep(999 * 1000);
    float lux = get_most_recent_lux();
    printf("lux [1] = %f, should be 3.94383\n", lux);
    
    usleep(500 * 1000);
    
    lux = get_most_recent_lux();
    printf("lux [2] = %f, should be 3.35223\n", lux);

    usleep(500 * 1000);

    lux = get_most_recent_lux();
    printf("lux [3] = %f, should be 5.5397\n", lux);

    // tests for part 2
    // sleep(1);
    
    // int test_points[5] = {0, 200 * 1000, 1600 * 1000, 2600 * 1000, 3100 * 1000};
    // for (int i = 0; i < 5; i++) {
    //     uint64_t time_at = start + test_points[i];
    //     float lux = get_lux_at(time_at);
    //     printf("t: %i, lux: %f\n", i, lux);
    // }

    pthread_exit(NULL);
    
    if(pthread_mutex_destroy(&myMutex) != 0){
        return ERROR;
    }

    return 0;
}

// nothing past here, don't bother scrolling down!


/* Don't edit this code */
float random_float() {
    return (float)rand() / RAND_MAX; 
}

/* Don't edit this code */
uint64_t get_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

/* Don't edit this code */
struct SensorReading read_next_sample() {
static bool first_run = true;
struct SensorReading return_value;

uint64_t max_wait = 1 * 1000000;

if (random_float() < 0.0001) {
    return_value.status = ERROR;
    return return_value;
}
if (first_run) {
    first_run = false;
    return_value.lux = random_float() * 10;
    return_value.status = VALID;
    return_value.timestamp = get_timestamp();
    return return_value;
}
uint64_t next_value_change = 2 * 1000000 * random_float();
if (max_wait <= next_value_change) {
    usleep(max_wait);
    return_value.status = NO_CHANGE;
    return return_value;
}
usleep(next_value_change);
return_value.lux = random_float() * 10;
return_value.status = VALID;
return_value.timestamp = get_timestamp();
return return_value;
}
