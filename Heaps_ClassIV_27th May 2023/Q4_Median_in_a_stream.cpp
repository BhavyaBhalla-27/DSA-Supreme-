#include <iostream>
#include <queue>
using namespace std;
int signum(int a, int b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}
void callMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{

    switch (signum(minHeap.size(), maxHeap.size()))
    {
    case 0: // Both heaps have equal size
        if (element > median)
        {
            // Push in minHeap
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            // Push in maxHeap
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    case 1: // minHeap has larger size than maxHeap
        if (element > median)
        {
            // first remove from minHeap and push to maxHeap
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            // Push new element to the minHeap
            minHeap.push(element);
            // Both have equal size so average will be median
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // simply push in maxHeap
            maxHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    case -1: // maxHeap has larger size than minHeap
        if (element > median)
        {
            // simply insert in minHeap
            minHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // first remove from maxHeap and push to minHeap
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            // Push new element to the maxHeap
            maxHeap.push(element);
            // Both have equal size so average will be median
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    }
}
int main()
{
    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;
    // Max - heap
    priority_queue<int> maxHeap;
    // Min - heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Initially median is 0
    double median = 0;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout << median << " ";
    }
    cout << endl;
    return 0;
}