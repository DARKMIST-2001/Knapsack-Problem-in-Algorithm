#include<iostream>
using namespace std;


int Max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else{
        return y;
    }
}

int knapSack(int capacity, int length,int profit[],int weight[])
{
int k[length+1][capacity +1];
for(int i=0;i<=length;i++)
{
    for(int j=0;j<=capacity;j++)
    {
        if(i==0 || j==0)
        {
            k[i][j]=0;
        }
        else if(weight[i]<=j)
        {
            k[i][j]=Max(k[i-1][j], profit[i]+ k[i-1][j-weight[i]]);
        }
        else{
            k[i][j]=k[i-1][j];
        }
    }

}
return k[length][capacity];
}


int main()
{
int weight[]={0,2,3,4,5};
int profit[]={0,1,2,6,5};
int length=4;
int capacity=8;
int maxP;
maxP=knapSack(capacity,length,profit,weight);
cout<<"Max Profit Gained By 0/1 Knapsack is: "<<maxP<<endl;
return 0;
}