#include<iostream>
using namespace std;
int main(){

    int num =  10;
    int *p = &num;
    cout<<"Valor de num: "<<num<<endl;
    cout<<"Valor de la direccion de memoria de num: "<<&num<<endl; 
    cout<<"Valor de *p: "<<*p<<endl;
    cout<<"Valor de p: "<<p<<endl;
    system("pause");
    return 0; 
}