#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node{
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor;
};

#endif