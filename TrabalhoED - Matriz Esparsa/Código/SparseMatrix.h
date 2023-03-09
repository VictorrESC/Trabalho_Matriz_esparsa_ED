#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class SparseMatrix {
    private:
        Node * m_head = {nullptr}; // ponteiro para o inicio da lista, sempre aponta para um no sentinela.
        Node * linha;
        Node * coluna;
        int m_linha, m_coluna;
    public:
        // inicializa uma matriz esparsa vazia com capacidade para m linhas e n colunas e verifica se os valores sao validos.
        SparseMatrix(int m_linha, int m_coluna);

        // destrutor que libera toda a memoria que foi alocada dinamicamente.
        ~SparseMatrix();

        /*Esta funcao-membro faz o valor na celula (i, j) da matriz ser igual a value, onde i e a linha e j e a coluna. Se ja houver um valor nessa posicao, ele e atualizado para esse novo valor. Essa funcao deve checar se os indices i, j passados por parametro sao validos; se nao forem validos, uma excecao deve ser lancada. Garante que não perca um valor já existente na linha.*/
        void insert(int i, int j, double value);

        /*Esta funcao-membro retorna o valor na celula (i, j) da matriz, onde i e a linha e j e a coluna. Se nao houver um valor nessa posicao, retorna 0. Essa funcao deve checar se os indices i, j passados por parametro sao validos; se nao forem validos, uma excecao deve ser lancada.*/
        double getValor(int i, int j);

        int getColuna(); // retorna o numero de colunas da matriz.
        int getLinha(); // retorna o numero de linhas da matriz.

        /*Essa funcao imprime a matriz A no terminal,  inclusive os elementos iguais a zero.*/
        void Print();
};
#endif