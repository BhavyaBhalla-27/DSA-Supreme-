#include<iostream>
using namespace std;
bool findElement(int arr[],int size,int key){
    for(int i = 0;i<size;i++){ // Traversing the array
        if(arr[i]==key){ // Comparing key with each element
            return true; // If found then return true and exit from function
        }
    }
    return false; // If traversed all the elements and not found, then return false and exit from function
}
int main(){
    int arr[] = {2,9,6,7,4,12,15};
    int size = 7;
    int key = 16;
    if(findElement(arr,size,key)){ // calling the boolean function
        cout<<"Found element"; // condition true then just cout found element
    }
    else{
        cout<<"Not Found"; // condition false
    }
    return 0;
}