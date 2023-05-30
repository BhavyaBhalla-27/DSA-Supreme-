#include<iostream>
#include<unordered_map>
using namespace std;
bool checkCircular(Node* head){
    unordered_map<Node*,bool>visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited.find(temp) != visited.end()){
            visted[temp] = true;
        }
        else{
            return false;
        }
        temp = temp->next;
    }
    return true;
}
int main(){

    return 0;
}