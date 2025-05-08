struct no{
    string info;
    no *link;
};
struct transicao{
    string nome;
    
};

no *inicializaLista(no *lista){
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
