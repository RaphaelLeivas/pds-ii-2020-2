#include <iostream>

using namespace std;

#define SIZE 5

int main(){
    long value1=200000;
    long value2;
    
    //imprima o valor do objeto apontado por long_ptr
    long* p_long1 = &value1;
    cout << *p_long1 << " ";
    
    //Imprima o valor de value2
    value2 = *p_long1;
    cout << value2 << " ";
    
    //Imprima o endereço de value1
    cout << &value1 << " "; 
    
    //Imprima o endereço armazenado em long_ptr
    cout << p_long1 << " ";
    
    //Imprima a comparação entre o endereço de value1 com o endereço armazenado em long_ptr
    if(&value1 == p_long1) cout << true << " ";
    else cout << false << " ";
    
    //imprimir os elementos do array values usando notação de array subscrito.
    int vec[5] = {2, 4, 6, 8, 10};
    int* p_vec = NULL;
    for(int i = 0; i < 5; ++i)
        cout << vec[i] << " ";

    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento.
    for(int i = 0; i < 5; ++i)
        cout << vec[i] << " ";
    
    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento com o nome de array como o ponteiro.
    p_vec = vec;
    for(int i = 0; i < 5; ++i)
        cout << *(p_vec + i) << " ";

    //imprimir os elementos do array values utilizando subscritos no ponteiro para o array.
    for(int i = 0; i < 5; ++i)
        cout << *(p_vec + i) << " ";

    //imprimir o quinto elemento de values utilizando a notação de subscrito de array,
    cout << vec[4] << " ";
    
    //a notação de ponteiro/deslocamento com o nome de array como o ponteiro, 
    cout << *(p_vec + 4) << " ";

    //a notação de subscrito de ponteiro,
    cout << *(p_vec + 4) << " ";
    
    //a notação de ponteiro/deslocamento.
    cout << *(p_vec + 4) << " ";

    //endereço referenciado por v_ptr + 3 e que valor é esse
    cout << p_vec + 3 << " ";
    cout << *(p_vec + 3) << " ";
    
    //endereço referenciado por v_ptr + 4 e que valor é esse
    cout << p_vec + 4 << " ";
    cout << 2 << " ";
    
    return 0;
}