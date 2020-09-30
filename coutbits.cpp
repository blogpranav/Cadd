#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin>>num;

int dp[num+1]={0};
        
        int k=0;
        dp[1]=1;        
       dp[0]=0;
        for(int i=1;pow(2,i)<=num;i++)
        {
            k=pow(2,i);
            dp[k]=1;
            dp[k+1]=2;
            // cout<<"i"<<endl;
        }
       
        int j=2;
        
        for(int i=3;i<=num;i++)
        {
            
            if(i>pow(2,j+1))
            {
                j++;
            }
            if(dp[i]!=0)
                continue;
            

            
            	int p=pow(2,j);
                dp[i]=dp[i-p]+1;
            
        }
        for(int i=0;i<=num;i++)
        {
        	cout<<dp[i]<<endl;
        }

	}