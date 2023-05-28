#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[101];
    int size;
    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        // Insert at correct index
        size = size + 1;
        int index = size;
        arr[index] = value;
        // Place the value at correct position
        while (index > 1)
        {
            // greater than 1 as then parent of index = 1 will be 0 but it is not a valid element
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                // Swap
                swap(arr[parentIndex], arr[index]);
                // Update index so that we get out of loop somewhere
                index = parentIndex;
            }
            else
            {
                // Do nothing
                break;
            }
        }
    }
    // Deletion
    // We can delete the root node only
    int deleteValue()
    {
        int ans = arr[1];
        // Replace root node and the last node
        arr[1] = arr[size];
        size--; // Delete the last value
        // Now make sure heap property is satisfied
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            // Now find maximum value among parent and child
            int largest = index;
            if (left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right <= size && arr[largest] < arr[right])
            {
                largest = right;
            }
            // Swap with the maximum value
            if (largest == index)
            {
                // Value is at correct place
                break;
            }
            else
            {
                swap(arr[index], arr[largest]);
                // update index
                index = largest;
            }
        }
        return ans;
    }
};
int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;
    cout << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    h.insert(110);
    cout << endl
         << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    h.deleteValue();
    cout << endl
         << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    return 0;
}