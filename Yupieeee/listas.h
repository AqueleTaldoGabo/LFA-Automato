struct no{
    string info;
    no *link;
};
struct Qses{
    string nome;
    Qses *fila;
    no *condicoes;
    no *condicionados;
};

no *inicializaLista(no *lista){
    return NULL;
}
Qses *inicializaListaQ(Qses *lista){
    return NULL;
}
no *PUSH(no *lista, string c){
    no *X;
    X = new no;
    X->info = c;
    X->link = lista;
    lista = X;

    return (lista);
}
Qses *CriaQ(Qses *lista, int quanti){
    Qses *N = new Qses, *J;
    J = N;
    string c;
    N->nome = "Q0";
    for(int i = 1; i<quanti; i++){
        Qses *pontos = new Qses;
        c = "Q" + to_string(i);
        pontos->nome = c;
        pontos->condicionados = NULL;
        pontos->condicoes = NULL;
        N->fila = pontos;
        N = N->fila;
    }
    lista = J;
    return (lista);
}
no *POP(no *lista, string *c){
    no *X;

    if(lista != NULL){
        *c = lista->info;
        X = lista;
        lista = lista->link;
        delete X;
    }
    else{
        *c = ' ';
    }
    return (lista);
}
