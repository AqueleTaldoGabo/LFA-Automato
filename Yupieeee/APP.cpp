#include <iostream>
#include <string>
using namespace std;
#include "listas.h"

no *preencheAlfabeto(no *lista);
no *preencheEstador(no *lista, int quantia);
no *preencheEstadoresFinais(Qses *lista1, no *lista2, int quant);
Qses *preencheRegras(Qses *lista, int quanti, no *lista1, no *lista2);
Qses *pilharQses(Qses *lista, string c);
void imprimeListaQ(Qses *lista);
void imprimeLista(no *lista);
void imprimeListaCaminhos(Qses *lista);

int main(){
    no *L1, *L2, *Qfs;
    Qses *qsese;
    int quantQ;
    cout << "Insira a quantidade de estados: "<< endl;
    cin >> quantQ;
    L1 = inicializaLista(L1);
    L2 = inicializaLista(L2);
    qsese = inicializaListaQ(qsese);
    Qfs = inicializaLista(Qfs);
    qsese = CriaQ(qsese, quantQ);
    
    cout << "Alfabeto" << endl;
    L1 = preencheAlfabeto(L1);
    cout << "Automato" << endl;
    L2 = preencheAlfabeto(L2);
    cout << "Finais: " << endl;
    Qfs = preencheEstadoresFinais(qsese, Qfs, quantQ);
    qsese = preencheRegras(qsese, quantQ, L1, L2);
    imprimeListaQ(qsese);
    imprimeLista(Qfs);
    imprimeLista(L1);
    imprimeLista(L2);
    imprimeListaCaminhos(qsese);
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

no *preencheEstadoresFinais(Qses *lista1, no *lista2, int quant){
    no *X;
    Qses *Y;
    string c = " ", k;
    X = inicializaLista(X);
    cout << "Quais estados seriam finais:" << endl;
    imprimeListaQ(lista1);
    while(c != "S" || X == NULL){
        Y = lista1;
        cin >> c;
        k = "Q" + c;
        if(c != "S"){
            while(Y->nome != k && stoi(c) < quant){
                Y = Y->fila;
            }
            if(stoi(c) >= quant){
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

Qses *preencheRegras(Qses *lista, int quanti, no *lista1, no *lista2){
    Qses *inicial = lista, *ponteiro = lista, *ponteiro2 = lista;
    no *pc, *pp, *pk = lista1, *pa = lista2, *pe, *ps;
    
    string c = " ", k;
    while(c != "S"){
        cout << "Qual estado?" << endl;
        cin >> c;
        k = "Q" + c;
        
        if(c != "S"){
            ponteiro = inicial;
            while (ponteiro->nome != k && stoi(c) < quanti){
                ponteiro = ponteiro->fila;
            }
            if(stoi(c) >= quanti){
                cout << "Nao existe esse ponto!!!!!" << endl;
            }
            else{
                pc = ponteiro->condicoes;
                pp = ponteiro->condicionados;
                pe = ponteiro->empilha;
                ps = ponteiro->desempilha;
                while(true){
                    pk = lista1;
                    pa = lista2;
                    cout << "Defina o caracter:" << endl;
                    cin >> c;
                    if(c == "S"){
                        c = " ";
                        break;
                    }
                    else{
                        while (pk->info != c){
                            pk = pk->link;
                            if(pk == NULL)
                                break;
                        }
                        if(pk == NULL){
                            cout << "Nao tem caractere!!!!" << endl;
                        }
                        
                        else{
                            pc = PUSH(pc, c);
                            cout << "Defina o que vai ser desempilhado" << endl;
                            cin >> c;
                            while(pa->info != c){
                            pa = pa->link;
                            if(pa == NULL)
                                break;
                            }
                            if(pa == NULL){
                            cout << "Nao faz parte do alfabeto da pilha" << endl;
                            }else{
                                ps = PUSH(ps, c);
                                cout << "Defina o que vai ser empilhado" << endl;
                                cin >> c;
                                while(pa->info != c){
                                    pa = pa->link;
                                    if(pa == NULL)
                                        break;
                                }
                                if(pa == NULL){
                                    cout << "Nao faz parte do alfabeto da pilha" << endl;
                                }else {
                                    pe = PUSH(pe, c);
                                    bool carros = true;
                                    while(carros){
                                        ponteiro2 = inicial;
                                        cout << "Defina seu caminho" << endl;
                                        cin >> c;
                                        k = "Q" + c;
                                        if(c == "S"){
                                            break;
                                        }
                                        while(ponteiro2->nome != k && ponteiro2 != NULL){
                                            ponteiro2 = ponteiro2->fila;
                                        }
                                        if(ponteiro2 == NULL){
                                            cout << "Estado nao existe" << endl;
                                        }
                                        else{
                                            pp = PUSH(pp, k);
                                            carros = false;
                                        }
                                    }
                                }
                            break;
                        }
                    }
                }   
            }
            ponteiro->condicoes = pc;
            ponteiro->condicionados = pp;
            ponteiro->empilha = pe;
            ponteiro->desempilha = ps;
        }
     }
}
    return lista;
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

void imprimeListaQ(Qses *lista){
    Qses *X;
    X = lista;
    
    while(X != NULL){
        cout << X->nome << " ";
        X = X->fila;
    }
    cout << endl;
}
void imprimeListaCaminhos(Qses *lista){
    Qses *X;
    X = lista;
    
    while(X != NULL){
        cout << X->nome << endl;
        no *pc = X->condicoes;
        no *pp = X->condicionados;
        while(pc != NULL){
            if(pc == NULL){
                break;
            }
            cout << pc->info + " -> " + pp->info << endl;
            pc = pc->link;
            pp = pp->link;

        }
        X = X->fila;
    }
    cout << endl;
}