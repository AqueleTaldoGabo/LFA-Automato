#include <iostream>
#include <string>
using namespace std;
#include "listas.h"

no *preencheAlfabeto(no *lista);
no *preencheEstador(no *lista, int quantia);
no *preencheEstadoresFinais(Qses *lista1, no *lista2, int quant);
Qses *preencheRegras(Qses *lista, int quanti, no *lista1, no *lista2);
Qses *pilharQses(Qses *lista, string c);
string criarInicial(Qses *lista);
void caminhaLista(Qses *lista, string c, string q, no *finais);
void imprimeListaQ(Qses *lista, int quant);
void imprimeLista(no *lista);
void imprimeListaCaminhos(Qses *lista);

int main(){
    no *L1, *L2, *Qfs;
    Qses *qsese;
    string entrada, inicial;
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
    
    inicial = criarInicial(qsese);
    qsese = preencheRegras(qsese, quantQ, L1, L2);

    cout << "Insira a entrada" << endl;
    cin >> entrada;
    caminhaLista(qsese, entrada, inicial, Qfs);

    imprimeListaQ(qsese, quantQ);
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
    system("cls");
    return (lista);
}
string criarInicial(Qses *lista){
    string inicial, k;
    Qses *aux = lista;
    while(true){
        cout << "Insira o estado inicial" << endl;
        cin >> inicial;
        k = "Q" + inicial;
        while(aux->nome != k){
            aux = aux->fila;
            if(aux == NULL){
                break;
            }
        }
        if(aux == NULL){
            cout << "Não é um estado possivel" << endl;
        }
        else{
            break;
        }
        aux = lista;
    }
    return k;
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
    imprimeListaQ(lista1, quant);
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
    system("cls");
    return (lista2);
}

Qses *preencheRegras(Qses *lista, int quanti, no *lista1, no *lista2){
    Qses *inicial = lista, *ponteiro = lista, *ponteiro2 = lista;
    no *pk = lista1, *pa = lista2;
    
    string c = " ", k;
    while(c != "S"){
        ponteiro = inicial;
        cout << "Qual estado?" << endl;
        cin >> c;
        k = "Q" + c;
        
        if(c != "S"){
            
            while (ponteiro->nome != k && stoi(c) < quanti){
                ponteiro = ponteiro->fila;
            }
            if(stoi(c) >= quanti){
                cout << "Nao existe esse ponto!!!!!" << endl;
            }
            else{
                while(true){
                    pk = lista1;
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
                            no *X;
                            X = new no;
                            X->info = c;
                            X->link = ponteiro->condicoes;
                            ponteiro->condicoes = X;

                            pa = lista2;
                            cout << "Defina o que vai ser desempilhado" << endl;
                            cin >> c;
                            while(pa->info != c && c != "NULL"){
                                pa = pa->link;
                                if(pa == NULL)
                                 break;
                            }
                            if(pa == NULL){
                                cout << "Nao faz parte do alfabeto da pilha" << endl;
                            }else{
                                if(c == "NULL"){
                                    c = " ";
                                }
                                no *Y;
                                Y = new no;
                                Y->info = c;
                                Y->link = ponteiro->desempilha;
                                ponteiro->desempilha = Y;
                                pa = lista2;
                                cout << "Defina o que vai ser empilhado" << endl;
                                cin >> c;
                                while(pa->info != c && c != "NULL"){
                                    pa = pa->link;
                                    if(pa == NULL)
                                        break;
                                }
                                if(pa == NULL){
                                    cout << "Nao faz parte do alfabeto da pilha" << endl;
                                }else {
                                    if(c == "NULL"){
                                        c = " ";
                                    }
                                    no *Z;
                                    Z = new no;
                                    Z->info = c;
                                    Z->link = ponteiro->empilha;
                                    ponteiro->empilha = Z;
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
                                            no *P;
                                            P = new no;
                                            P->info = c;
                                            P->link = ponteiro->condicionados;
                                            ponteiro->condicionados = P;
                                            carros = false;
                                        }
                                    }
                                }
                            break;
                        }
                    }
                }   
            }
        }
    }
}
    lista = ponteiro;
    return lista;
}

void caminhaLista(Qses *lista, string c, string q, no *finais){
    Qses *Aux = lista;
    no *pilha;
    pilha = inicializaLista(pilha);
    pilha = PUSH(pilha, "Z");
    bool verify;
    while(Aux->nome != q){
        Aux = Aux->fila;
    }
    for(int i = 0; i<c.length(); i++){
        cout << Aux->nome << endl;
        imprimeLista(pilha);
        do{
            cout << "BOSTA1" << endl;
            if(c[i] == Aux->condicoes->info[0]){
                string aux = Aux->condicionados->info;
                if(Aux->empilha->info != " "){
                    pilha = PUSH(pilha, Aux->empilha->info);
                }
                if(Aux->desempilha->info != " "){
                    no *pilha2 = pilha, *ANT;
                    string x;
                    if(Aux->desempilha->info == pilha->info){
                        pilha = POP(pilha, &x);
                        cout << "BOSTA1" << endl;
                    }
                    else{
                        cout << "BOSTA1" << endl;
                        do{
                            if(pilha2 == NULL)
                                break;
                            ANT = pilha2;
                            pilha2 = pilha2->link;
                        }while(pilha2->info != Aux->desempilha->info && pilha2 != NULL);
                        cout << "BOSTA2" << endl;
                        if(pilha2 != NULL){
                            ANT->link = pilha2->link;
                            delete pilha2;
                        }
                        else{
                            cout << "Nao tem oq desempilhar" << endl;
                            i+=c.length();
                            break;
                        }
                    }
                }
                cout << "legeal" << endl;
                Aux = lista;
                while(Aux->nome != ("Q" + aux)){
                        Aux = Aux->fila;
                }
                cout << "legeal" << endl;
                imprimeLista(pilha);
                break;
            }
            else if(Aux->condicoes == NULL){
                cout << "Nao e possivel realizar o processo com essa entrada" << endl;
                i+=c.length();
            }
            else{
                cout << "carlo" << endl;
                Aux->condicoes = Aux->condicoes->link;
                Aux->condicionados = Aux->condicionados->link;
                Aux->desempilha = Aux->desempilha->link;
                Aux->empilha = Aux->empilha->link;
            }

        }while(Aux->condicoes != NULL);
        system("pause");
        system("cls");
    }
    do{
        if(finais->info == Aux->nome){
            break;
        }
        string x;
        finais = POP(finais, &x);
    }while(finais->info != Aux->nome && finais != NULL);
    if(finais == NULL){
        cout << "Nao esta no estado final" << endl;
    }
    else{
        cout << "Automato chegou no estado final" << endl;
    }
    if(pilha != NULL)
        cout << "Pilha nao esta vazia" << endl;
    else
        cout << "Pilha esta vazia" << endl;
    system("pause");
    system("cls");
}

void imprimeLista(no *lista){
    no *X;
    X = lista;
    
    while(X != NULL){
        if(X == NULL){
            break;
        }
        cout << X->info << " ";
        X = X->link;
    }
    cout << endl;
}

void imprimeListaQ(Qses *lista, int quant){
    Qses *X;
    int i = 0;
    X = lista;
    
    while(X != NULL && i<quant ){
        cout << X->nome << " ";
        X = X->fila;
        i++;
    }
    cout << endl;
}
void imprimeListaCaminhos(Qses *lista){
    Qses *X;
    X = lista;
    
    while(X != NULL){
        if(X == NULL)
            break;
        cout << X->nome << endl;
        int i = 0;
        do{
            string condicoes, empilha, desempilha, condicionados;
            X->condicoes = POP(X->condicoes, &condicoes);
            X->empilha = POP(X->empilha, &empilha);
            X->desempilha = POP(X->desempilha, &desempilha);
            X->condicionados= POP(X->condicionados, &condicionados);
            cout << condicoes + " -> " + empilha + " -> " + desempilha + " -> " + condicionados << endl;
            
        }while(X->condicoes != NULL);
        X = X->fila;
    }
    cout << endl;
    system("pause");
}