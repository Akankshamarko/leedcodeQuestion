#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canPlaceCows(vector<int>& stalls, int C, int distance){
    int last_pos = stalls[0];
    int cnt =1;
    for(int i =1; i<stalls.size(); i++){
        if(stalls[i]-last_pos>= distance){
            cnt++;
            last_pos = stalls[i];
        }if(cnt ==C) return true;
    }
    return false;

}
int MaxDistance(vector<int>& stalls, int C){
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls.back()-stalls.front();
    int ans =0;

    while(low<=high){
        int mid = low+(high -low)/2;
        if(canPlaceCows(stalls,C,mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return ans;

}
int main(){
    vector<int>stalls={5,17,100,11,23,50};
    int C =4;

    cout<<MaxDistance(stalls,C)<<endl;
    return 0 ;
}