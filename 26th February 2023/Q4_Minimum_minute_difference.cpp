#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMinDifference(vector<string>&timepoints){
    vector<int>minutes; // Making minutes vector to store all the time in minutes
    for(int i = 0;i<timepoints.size();i++){
        // Creating the minutes array
        string curr = timepoints[i];
        int hours = stoi(curr.substr(0,2));
        int min = stoi(curr.substr(3,2));
        int totalminutes = hours*60 + min;
        minutes.push_back(totalminutes);
    }
    // Sort the minutes array
    sort(minutes.begin(),minutes.end());
    // Calculate minimum difference bw adjacent elements
    int n = minutes.size();
    int mini = INT_MAX;
    for(int i = 0;i<n-1;i++){
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini,diff);
    }
    // Last and first element compare
    int lastdiff = (minutes[0] + 1440) - minutes[n-1]; // This is where we fail to understand. Remember this
    mini = min(mini,lastdiff);
    return mini;
}
int main(){
    vector<string>timepoints{"23:59","00:00"}; // For this test case we have done the modification i.e. last and first element compare 
    int ans = findMinDifference(timepoints);
    cout<<ans;
    return 0;
}