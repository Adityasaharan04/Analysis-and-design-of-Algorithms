#include<bits/stdc++.h>
using namespace std;

void correct_pos(int*arr,int size,int ele)
{
  int i,j,indx,cnt;
  i=0;
  j=size;
  cnt = 0;
  int k = 0;
  while(k<=size) 
  {
    if(arr[k] < ele)
    {
      cnt++;
    }
    else if(arr[k]==ele)
    {
      indx = k;
    }
    k++;
  }
  swap(arr[indx],arr[cnt]);
  indx = cnt;
  while(i < j)
  {
    if(arr[i]<=arr[indx])
    {
      i++;
    }
    else if(arr[i]>arr[indx])
    {
      if(arr[i]>arr[j])
      {
        swap(arr[i],arr[j]);
        j--;
      }
      else if(arr[i]<arr[j])
      {
        i++;
      }
    }
  }
}