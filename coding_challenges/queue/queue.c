#include <stdio.h>
#include <stdlib.h>

/*
Number of Recent Calls
You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has 
happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in 
the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

 

Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
 

Constraints:

1 <= t <= 10^9
Each test case will call ping with strictly increasing values of t.
At most 10^4 calls will be made to ping.
*/

#define MAX_TIME_LIMIT 3000

static int count = 0;

struct RecentCounter {
    int timeStamp;
    struct RecentCounter *prev;
    struct RecentCounter *next;
};

struct RecentCounter *head = NULL;
struct RecentCounter *tail = NULL;

void addToQueue(struct RecentCounter *new_node){
    if(head == NULL){
        head = new_node;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = NULL;
        tail = new_node;
    }
    count++;
}

void del(struct RecentCounter *node){
    if(node != NULL){
        free(node);
    }
}

void removeFromQueue(){
    if(head->next != NULL){
        head = head->next;                  //Move head to the next node
        head->prev->next = NULL;            //Remove next ptr of prev node 
        del(head->prev);                    //Delete prev node
        head->prev = NULL;                  //Set current prev node to NULL
    }
    else{
        del(head);
        head = NULL;
        tail = NULL;
    }
    count--;
}

void removeOldEntries(int t){
    while(head != NULL && ((t - (head->timeStamp)) > MAX_TIME_LIMIT)) {
        removeFromQueue();
    }
}

int ping(int t) {
    // Adds a new request at time t, where t represents some time in milliseconds, and returns the number 
    // of requests that has happened in the past 3000 milliseconds (including the new request). 
    // Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
    // It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
    struct RecentCounter *newNode = malloc(sizeof(struct RecentCounter));
    newNode->timeStamp = t;
    addToQueue(newNode);
    removeOldEntries(t);
    return count;
}

struct RecentCounter* CreateRecentCounter(){
    head = tail = NULL;
    count = 0;
}
    
void print_requests_list(){
    struct RecentCounter *curr = head;
    printf("Request Time List: [");
    while(curr != NULL){
        printf("%d, ", curr->timeStamp);
        curr = curr->next;
    }
    printf("]\n\n");
}
int main(){
    struct RecentCounter* recentCounter = CreateRecentCounter();
    int ret = 0;

    printf("Sending ping(1)\n");
    ret = ping(1);     // requests = [1], range is [-2999,1], return 1
    printf("Return value: %d\n", ret);
    print_requests_list();

    printf("Sending ping(100)\n");
    ping(100);   // requests = [1, 100], range is [-2900,100], return 2
    printf("Return value: %d\n", ret);
    print_requests_list();

    printf("Sending ping(3001)\n");
    ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
    printf("Return value: %d\n", ret);
    print_requests_list();

    printf("Sending ping(3002)\n");
    ping(3002);  // requests = [100, 3001, 3002], range is [2,3002], return 3
    printf("Return value: %d\n", ret);
    print_requests_list();
    return 0;
}