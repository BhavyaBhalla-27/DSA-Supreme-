#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    // Constructor
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    // pushRear function
    void pushRear(int data)
    {
        // Queue is full (One condition to handle)
        if ((front == 0 && rear == size - 1))
        {
            cout << "Q is fulll, cannot insert" << endl;
            return;
        }
        // Empty case
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular case
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // Normal flow
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        // Queue is full (One condition to handle)
        if ((front == 0 && rear == size - 1))
        {
            cout << "Q is fulll, cannot insert" << endl;
            return;
        }
        // Empty case
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular case
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        // Normal flow
        else
        {
            front--;
        }
        arr[front] = data;
    }
    // popFront function
    void popFront()
    {   
        // Empty queue
        if (front == -1)
        {
            cout << "Q is empty , cannot pop" << endl;
            return;
        }
        // Single element case
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // Circular case
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // Normal flow
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    // popRear function
    void popRear()
    {
        // Empty queue
        if (front == -1)
        {
            cout << "Q is empty , cannot pop" << endl;
            return;
        }
        // Single element case
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // Circular case
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // Normal flow
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
    // Just for understanding purposes
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deque dq(10);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushRear(40);
    dq.pushRear(50);
    dq.pushRear(60);
    dq.pushRear(70);
    dq.pushRear(80);
    dq.pushRear(90);
    dq.pushRear(100);
    dq.print();
    return 0;
}