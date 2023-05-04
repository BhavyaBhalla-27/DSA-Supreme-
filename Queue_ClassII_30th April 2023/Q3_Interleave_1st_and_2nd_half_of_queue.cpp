#include<iostream>
#include<queue>
using namespace std;
void interleaveQueue(queue<int>&originalQueue){
    // Edge case
    if(originalQueue.empty()){
        return;
    }
    int n = originalQueue.size();
    int k = n/2;
    int count = 0;
    queue<int>newQueue;
    // Step 1 -> Push first half elements of q to q2
    while(!originalQueue.empty()){
        int temp = originalQueue.front();
        originalQueue.pop();
        newQueue.push(temp);
        count++;
        if(count == k){
            break;
        }
    }
    // Step - 2 First push element from newQueue to originalQueue and then from originalQueue to originalQueue
    while(!originalQueue.empty() && !newQueue.empty()){
        // Push from NQ to OQ
        int first = newQueue.front();
        newQueue.pop();
        originalQueue.push(first);
        // Push from OQ to NQ
        int second = originalQueue.front();
        originalQueue.pop();
        originalQueue.push(second);
    }
    // Handling odd case in which originalQueue will have one more element than newQueue
    if(n&1){ // For odd
        int element = originalQueue.front();
        originalQueue.pop();
        originalQueue.push(element);
    }
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    interleaveQueue(q);
    // Printing queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}