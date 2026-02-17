#include<iostream>
#include<vector>
using namespace std;
int MaxSum(vector<int>& arr, int k){
    int n = arr.size();
    int window_sum =0;

    for(int i =0; i<k; i++)
        window_sum += arr[i];

        int max_sum = window_sum;
        for(int i =k; i<n; i++){
            window_sum +=arr[i]-arr[i-k];

            max_sum = max(max_sum, window_sum);
        }
    return max_sum;
}
int main(){
   vector<int> arr ={2,1,5,1,3,2};
     int k =3;
    cout<<MaxSum(arr,k)<<endl;
    return 0;
}