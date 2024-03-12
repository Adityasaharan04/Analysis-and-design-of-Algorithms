#include<bits/stdc++.h>
using namespace std;

void BinaryS(vector<int>&arr , int i , int e){
    int begin=0;
    int end = i-1;
    int mid;
    while(begin<=end)
    { 
      mid = begin+(end-begin)/2;
      if(arr[mid]==e)
      {
        return;
      }
      else if(arr[mid]>e)
      {
        end = mid-1;
      }
      else if(arr[mid]<e)
      {
        begin = mid+1;
      }
    }
    return;
}
vector<int>Generate(vector<int>&arr,int i)
{
    int j=0;
    for(j=0 ; j<i ; j++)//1000 times
    {
     arr.push_back(rand());
    }
    return arr;
}
void store(int i , int avg)
{
  cout<<i<<" "<<avg<<endl;
}
void AC()
{   
    int i=0;
    int k=0;
    double avg = 0;
    vector<int>arr; 
    //switch case ;
    //case a :
    for(i=1 ; i<=20 ; i+=4)
    {
      // arr = Generate(arr,i);
      //clock starts => t1;
      for(k=1 ; k<=10 ; k++)
      {
        //function :
        clock_t clk = clock();
        //sum_of_n(arr,i);
        // selection_sort(arr,i);
        // permutation(arr,i);
        //  tt_ff("abc",3);
        // towerOfHanoi(25,'a','c','b');
        clock_t clk2 = clock();
        avg+= (clk2-clk);
      }
      //clock ends => t2;
      avg = avg/10;
      store(i,avg);
}
}
int main()
{
  AC();
  return 0;
}