#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

int main(){
    int a,c=0,n=0,k;
    start:
    cout<<"Enter any positive integer : ";
    cin>>a;
    if(a<0){
        cout<<"Invalid input... pls enter some valid input"<<endl;
        goto start;
    }

    for(int i=1;i<=a;i++){
        if(a%i==0)
        c++;
    }

    if(c>2){
        cout<<a<<" IS NOT A PRIME NUMBER ..."<<endl<<"Factors of "<<a<<" are :"<<endl;
        for(int i=1;i<=a;i++){
        if(a%i==0){
        c=i;
        cout<<c<<endl;
    }
    }
    }

    if(c==2){
        cout<<a<<" IS A PRIME NUMBER..";
        k=a+1;
        while(1){
        int n1=1;
        for(int i=2;i<k;i++){
            if(k%i==0){
                n1=0;
            }
        }
        if(n1==1){
        cout<<"The next prime number after "<<a<<" is .. "<<k<<endl;
        break;
        }
        else
        k++;
   }
  }
}