#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array to create spiral pattern : ";
    cin>>n;
    int arr[n][n];
    int row=0,b=n-1,t=0,col=n-1;
    int k=1;


    while(row<=b && t<=col){
        for(int i=t;i<=col;i++){
            arr[row][i]=k;
            k++;
        }
        row++;

        for(int i=row;i<=b;i++){
            arr[i][col]=k;
            k++;
        }
        col--;

        if(row<=b){
            for(int i=col;i>=t;i--){
                arr[b][i]=k;
                k++;
            }
            b--;
        }

        if(t<=col){
            for(int i=b;i>=row;i--){
                arr[i][t]=k;
                k++;
            }
            t++;
        }
    }
 

    
    cout << "The square matrix is:\n";
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++) {
            cout << arr[i][j] << " ";  
        }
        cout << endl;
    }


}