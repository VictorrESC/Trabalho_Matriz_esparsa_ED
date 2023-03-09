#include <iostream>
#include "SparseMatrix.h"

using namespace std;

/*
*   Construtor da Matriz Esparsa que reccebe por parametro a quantidade de linhas e colunas e cria seus respectivos nos sentinela.
*/
SparseMatrix::SparseMatrix(int m_linha, int m_coluna) {
    // criando o nó m_head.
    m_head = new Node;
    m_head -> direita = m_head;
    m_head -> abaixo = m_head;
    m_head -> linha = 0;
    m_head -> coluna = 0;
    m_head -> valor = 0;

    if (m_linha > 0 && m_coluna > 0) {
        // criando a primeira linha.
        linha = m_head;
        for (int i = 0; i < m_linha; i++) { // criando os nos sentinelas das linhas.
            linha -> abaixo = new Node;
            linha -> abaixo -> direita = linha -> abaixo;
            linha -> abaixo -> abaixo = m_head;
            linha -> abaixo -> linha = i + 1;
            linha -> abaixo -> coluna = 0;
            linha -> abaixo -> valor = 0;
            linha = linha -> abaixo;
        }

        // criando a primeira coluna.
        coluna = m_head;
        for (int i = 0; i < m_coluna; i++) { // criando os nos sentinelas das colunas.
            coluna -> direita = new Node;
            coluna -> direita -> direita = m_head;
            coluna -> direita -> abaixo = coluna -> direita;
            coluna -> direita -> linha = 0;
            coluna -> direita -> coluna = i + 1;
            coluna -> direita -> valor = 0;
            coluna = coluna -> direita;
        }

        // atribuindo os valores de linha e coluna.
        this -> m_linha = m_linha;
        this -> m_coluna = m_coluna;

        cout << endl;
    } else {
        try {
            throw "Erro: Parametros invalidos!";
        } catch (const char * msg) {
            cerr << msg << endl;
        }
    }
}

/*
*    Destrutor que libera toda a memoria que foi alocada dinamicamente.
*/
SparseMatrix::~SparseMatrix()
{
    // percorre as linhas e colunas da matriz deletando os nos e liberando a memoria alocada dinamicamente.
    for (int i = 0; i < m_linha; i++) {

        Node * aux = m_head; // aponta para o nó m_head

        for (int j = 0; j < m_coluna; j++) {

            if (aux -> direita == aux) break; // se o nó auxiliar apontar para ele mesmo, significa que chegou ao fim da linha.

            Node * prev = aux -> direita;
            aux -> direita = prev -> direita;
            delete prev;
            /* nesse bloco de codigo, o nó "prev" aponta para o nó que será removido, o nó "aux" aponta para seu proximo, e por fim o nó "prev" é deletado.
            */
        }
        m_head = m_head -> abaixo;
        // deslocando o nó m_head para a proxima linha. E após isso deletamos o nó auxiliar.
        delete aux;
    }
    delete m_head;
    // deletando o nó m_head. e liberando a memoria alocada dinamicamente.
}

/*
*   Funcao que insere um valor na matriz esparsa.
*/
void SparseMatrix::insert(int i, int j, double value) {
    // verifica se os indices passados para linha e coluna sao validos.
    if (i > 0 && i <= m_linha && j > 0 && j <= m_coluna) {

        // criamos dois nós auxilares 
        Node * prev = {nullptr};
        Node * aux;

        linha = coluna = m_head; 

        // percorre a linha ate achar a posicao desejada.
        for (int k = 1; k <= i; k++) {
            linha = linha -> abaixo; 
        }
        aux = linha;

        // percorre a coluna ate achar a posicao desejada.
        for (int k = 1; k <= j; k++) {
            coluna = coluna -> direita;
        }

        // aux recebe o primeiro elemento da linha.
        prev = aux; 
        aux = aux -> direita; 

        // percorre a linha ate achar o nó desejado.
        while (aux != linha && aux -> coluna < j) { 
            prev = aux; 
            aux = aux -> direita; 
        }

        // verifica se esta no nó desejado.
        if (aux != linha && aux -> coluna == j && aux -> linha == i) {

            // se o valor for 0, remove o nó.
            if (value == 0) {
                if (prev == linha) { 
                    linha -> direita = aux -> direita; 
                } else {
                    prev -> direita = aux -> direita;
                    coluna -> abaixo = aux -> abaixo;
                }
                delete aux; 
            } else { // senão, atualiza o valor do nó.
                aux -> valor = value;
            }
        } else { // se o nó não existir, cria um novo nó.
            Node * novo = new Node;
            novo -> linha = i;
            novo -> coluna = j;
            novo -> valor = value;

            novo -> direita = aux;
            if (prev == linha) {
                linha -> direita = novo;
            } else {
                prev -> direita = novo;
            }
        }
    } else {
        try {
            throw "Erro: Parametros invalidos!";
        } catch (const char * msg) {
            cerr << msg << endl;
        }
    }
}

/*
*   Funcao que retorna o valor de um no da matriz esparsa.
*/
double SparseMatrix::getValor(int i, int j) {
    
    // verifica se os indices passados para linha e coluna sao validos.
    if (i > 0 && j > 0 && i <= m_linha && j <= m_coluna) { 

        linha = m_head -> abaixo; 

        // percorre a linha ate achar a posicao desejada.
        for (int k = 1; k < i; k++) {
            linha = linha -> abaixo; 
        }

        Node * aux;
        aux = linha -> direita; 

        // enquanto nao chegar no fim da linha, percorre a linha.
        while (aux != linha) {
            // se a coluna e a linha do no forem iguais as desejadas, retorna o valor.
            if (aux -> coluna == j && aux -> linha == i) { 
                return aux -> valor; 
            }
            aux = aux -> direita; 
        }
    } else {
        try {
            throw "Erro: Indices invalidos!";
        } catch (const char * msg) {
            cerr << msg << endl;
        }
    }

    return 0;
}

int SparseMatrix::getLinha() {
    // retorna o numero de linhas da matriz.
    return m_linha;
}

int SparseMatrix::getColuna() {
    // retorna o numero de colunas da matriz.
    return m_coluna;
}

void SparseMatrix::Print() {
    //imprime a matriz com os valores inseridos usando a funcao get em formato de matriz e onde nao houver no, imprime 0.
    for (int i = 1; i <= m_linha; i++) {
        for (int j = 1; j <= m_coluna; j++) {
            cout << getValor(i, j) << " "; 
        }
        cout << endl;
    }
}