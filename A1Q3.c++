#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

int main(){
    string s,s1;
    cout<<"Enter any string : ";
    getline(cin,s);

    int n=s.length();

    for(int i=n-1;i>=0;i--){
        s1=s1+s[i];       
        }
    
    cout<<s1<<endl;
    
    if(s==s1)
        cout<<"ITS A PALINDROME STRING";
    
    else
    cout<<"NOT A PALINDROME STRING";

    int c=0;

    cout<<endl<<"COUNTING FREQUENCY OF ALPHABETS IN THE GIVEN STRING .. "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i]==s[j])
            c++;
        }
        cout<<"Frequency of "<<s[i]<<" is "<<c<<endl;
        c=0;
    }

    char k;
    cout<<"Enter character to replace with vowels in string : ";
    cin>>k;

    cout<<"REPLACING VOWELS IN STRING WITH "<<k<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='O'){
            s.replace(i,1,1,k);
        }
    }
    cout<<s;

}




