#include<bits/stdc++.h>
using namespace std;
int main()         
     int n;
     cin >> n;
     vector<int> arr;
     for (int i = 0; i < n;i++){
          int temp;
          cin >> temp;
          arr.emplace_back(temp);
     }
     int m, k;
     cin >> m >> k;

     if(m*k > arr.size()){
          cout << "-1";
          return ;
     }

     int days = *min_element(arr.begin(), arr.end());
     int maxEle = *max_element(arr.begin(), arr.end());
     int boq = 0;

     for (int i = 0; i < n;i++){
          if(arr[i]==days)
               arr[i] = 0;
          else
               arr[i] -= days;
     }
     int i;
     for ( i = days; i < maxEle;i++){
          if(boq==m) {
               cout << i-1 ;
               return 0;
          }
          int count = 0;
          for (int j = 0; j < n;j++){
               if(arr[j]==0){
                    count++;
                    if(count==k){
                         boq++;
                         int tempJ = j;
                         while(count>=0){
                              arr[tempJ] = -1;
                              tempJ--;
                              count--;
                         }
                    }
               }
               else if(count>0 && count!=k){
                    count = 0;
               }
          }
          
          for (int j = 0; j < n; j++){
               if(arr[j]==0)
                    continue;
               else
                    arr[j] -= 1;
          }
     }
     if(boq==m) 
          cout << i-1;
     return 0;
}
