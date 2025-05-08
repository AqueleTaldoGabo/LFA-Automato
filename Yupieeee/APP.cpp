#include <iostream>
#include <string>
using namespace std;
#include "listas.h"

no *preencheAlfabeto(no *lista);
no *preencheEstador(no *lista, int quantia);
no *preencheEstadoresFinais(no *lista1, no *lista2, int quant);
void imprimeLista(no *lista);

int main(){
    no *L1, *L2, *Qs, *Qfs;
    int quantQ;
    cout << "Insira a quantidade de estados: "<< endl;
    cin >> quantQ;
    L1 = inicializaLista(L1);
    L2 = inicializaLista(L2);
    Qs = inicializaLista(Qs);
    Qfs = inicializaLista(Qfs);
    Qs = preencheEstador(Qs, quantQ);
    cout << "Alfabeto" << endl;
    L1 = preencheAlfabeto(L1);
    cout << "Automato" << endl;
    L2 = preencheAlfabeto(L2);
    cout << "Finais: " << endl;
    Qfs = preencheEstadoresFinais(Qs, Qfs, quantQ);
    imprimeLista(Qs);
    imprimeLista(Qfs);
    imprimeLista(L1);
    imprimeLista(L2);
}

no *preencheAlfabeto(no *lista){
    no *X;
    string c = " ";
    X = inicializaLista(X);
    
    while(c != "S"){
        cout << "Digite um caractere" << endl;
        cin >> c;
        if(c != "S")
            X = PUSH(X, c);
    }
    lista = X;
    return (lista);
}

no *preencheEstador(no *lista, int quantia){
    no *X;
    X = inicializaLista(X);

    for(int i = quantia-1; i>=0; i--)
        X = PUSH(X, ("Q" + to_string(i)));
    lista = X;
    return (lista);
}

no *preencheEstadoresFinais(no *lista1, no *lista2, int quant){
    no *X, *Y;
    string c = " ", k;
    X = inicializaLista(X);
    cout << "Quais estados seriam finais:" << endl;
    imprimeLista(lista1);
    while(c != "S" || X == NULL){
        Y = lista1;
        cin >> c;
        k = "Q" + c;
        if(c != "S"){
            while(Y->info != k && stoi(c) <= quant){
                Y = Y->link;
            }
            if(stoi(c) > quant){
                cout << "Estado nao existe" << endl;
            }
            else{
                X = PUSH(X, k);
            }
        }
    }
    lista2 = X;
    return (lista2);
}

void imprimeLista(no *lista){
    no *X;
    X = lista;
    
    while(X != NULL){
        cout << X->info << " ";
        X = X->link;
    }
    cout << endl;
}