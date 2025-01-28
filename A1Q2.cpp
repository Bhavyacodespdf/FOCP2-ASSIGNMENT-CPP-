#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

int main(){
    int n,temp;
    cout<<"Enter the size of array ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"Enter value to be added in "<<i+1<<" position = ";
        cin>>arr[i];
    }

    cout<<"Reversing the array..."<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Searching for second largest and second smallest.."<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"Second smallest = "<<arr[1]<<endl;;
    cout<<"Second largest = "<<arr[n-2];
    


}