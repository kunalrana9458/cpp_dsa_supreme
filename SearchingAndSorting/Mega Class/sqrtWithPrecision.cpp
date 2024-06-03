#include<iostream>
using namespace std;
int findSqrt(int n){
    int start=0;
    int end=n;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid*mid <= n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

double findPrecision(int ans,int precision,int n){
    double finalAns=ans;
    double stepUp=0.1;
    for(int i=0;i<precision;i++){
        for(double j=finalAns;j*j<=n;j+=stepUp){
            finalAns = j;
        }
        stepUp /= 10;
    }
    return finalAns;
}
double BSPrecision(int n){
    double start = 0;
    double end = n;
    double ans = 0;

    while((end-start) >= 0.0000001){
        double mid=(start+(end-start)/2);
        double sqr = mid*mid;
        if(sqr <= n){
            ans=mid;
            start=mid;
        }
        else{
            end=mid;
        }
    }
    return ans;
}

int main()
{
    int n=63;
    int ans=findSqrt(n);
    int precision=5;
    double finalAns=BSPrecision(n);
    cout << "Answer is:" << finalAns << endl;
    return 0;
}