//POWER OF NO.
#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int power(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return(m*power(m,n-1));
    }
}

int main()
{
    int *arr = new int(10000000);
    for(int i=100000;i<=1000000;i+=100000)
    {
    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        int p = power(2,i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
    }

    return 0;
}

/*

#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int power(int m, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) 
    { 
        int temp = power(m, n / 2);
        return temp * temp;
    } else {
        return m * power(m, n - 1);
    }
}


int main()
{
    int *arr = new int(1000000);
    for(int i=100000;i<=1000000 ;i=i+100000)
    {
    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        int p = power(2,i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
    }

    return 0;
}


