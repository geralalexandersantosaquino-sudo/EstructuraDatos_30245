#include<iostream>
using namespace std;
int main(){

    int num[5] =  {10,25,5,4,9};
    int *p = num;
    for(int i=0; i<5; i++)
    {
        cout<<"Elemento "<<* p + 5 <<endl;
    }
    system("pause");
    return 0; 
}