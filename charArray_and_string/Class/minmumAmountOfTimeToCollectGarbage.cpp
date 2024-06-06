#include<iostream>
#include<vector>
using namespace std;
int garbageCollection(vector<string>& garbage,vector<int>& travel){
    // P truck
    int pickTimeP=0;
    int travelTimeP=0;
    int lastHouseTimeP=0;
    // M truck
    int pickTimeM=0;
    int travelTimeM=0;
    int lastHouseTimeM=0;
    // G truck
    int pickTimeG=0;
    int travelTimeG=0;
    int lastHouseTimeG=0;

    // let's travel to the street of houses
    for(int i=0;i<garbage.size();i++){
        // ith house
        string currHouse = garbage[i];
        // let give into current house amd see the type of garbage present
        for(int j=0;j<currHouse.size();j++){
            char garbageType = currHouse[j];
            if(garbageType == 'P'){
                pickTimeP++;
                // yaha tkk to mera p truck pkka aaya hai so lets store it
                lastHouseTimeP = i;
            }
            if(garbageType == 'M'){
                pickTimeM++;
                lastHouseTimeM = i;
            }
            if(garbageType == 'G'){
                pickTimeG++;
                lastHouseTimeG = i;
            }
        }
    }
        // lets calculate travel time for P
        int travelP=0;
        for(int i=0;i<lastHouseTimeP;i++){
            travelP +=  travel[i];
        }

        // lets calculate travel time for P
        int travelM=0;
        for(int i=0;i<lastHouseTimeM;i++){
            travelM +=  travel[i];
        }

        // lets calculate travel time for P
        int travelG=0;
        for(int i=0;i<lastHouseTimeG;i++){
            travelG +=  travel[i];
        }

        int totalPickingTime = pickTimeG+pickTimeM+pickTimeP;
        int totalTravelTime = travelG+travelM+travelP;

        return totalPickingTime+totalTravelTime;
}
int main()
{
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel={2,4,3};
    int ans=garbageCollection(garbage,travel);
    cout << "Answer is:" << ans << endl;
    return 0;
}