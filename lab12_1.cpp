#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double min=A[0],max=A[0],sum=A[0],sd,s=A[0],z=1/A[0];
    for(int i=1;i<N;i++){
        if(A[i]<min) min=A[i];
        if(A[i]>max) max=A[i];
        sum+=A[i];
        s*=A[i];
        z+=1/A[i];
    }
    B[0]=sum/N;

    for(int c=0;c<N;c++){
        sd+=pow(A[c]-B[0],2);
    }

    B[1]=sqrt(sd/N);
    B[2]=pow(s,1./N);
    B[3]=N/z;
    B[4]=max;
    B[5]=min;
}