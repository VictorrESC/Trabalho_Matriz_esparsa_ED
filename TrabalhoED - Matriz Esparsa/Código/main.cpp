#include <fstream>
#include <iostream>
#include "SparseMatrix.h"
#include "menu.h"

/*
*   Trabalho de Estrutura de Dados
*   Matriz Esparsa
*   Alunos: Victor Emanuel e Kaynan Pereira
*   
*   Para compilar o programa, basta abrir o terminal na pasta do projeto e digitar:
*   g++ *.cpp ; ./a.exe
*
*/
using namespace std;

// funcao que le um arquivo.txt e cria a matriz apartir de seus valores
SparseMatrix * readSparseMatrix(string numero_do_arquivo) {
    // abrindo o arquivo.
    ifstream file;
    file.open(numero_do_arquivo);

    // verificando se o arquivo foi aberto.
    if (!file.is_open()) {
        throw runtime_error("ERROR: Arquivo nao encontrado.");
    }

    // lendo o numero de linhas e colunas.
    int m_linha, m_coluna;
    file >> m_linha >> m_coluna;

    // criando a matriz.
    SparseMatrix * matriz = new SparseMatrix(m_linha, m_coluna);
    int i, j;
    double valor;

    // lendo os valores da matriz.
    while (file >> i >> j >> valor) {
        // adicionando os valores na matriz.
        matriz -> insert(i, j, valor);
    }

    // fechando o arquivo.
    file.close();
    return matriz;
}

SparseMatrix * Soma(SparseMatrix * a, SparseMatrix * b) {

    if (a -> getLinha() == b -> getLinha() && a -> getColuna() == b -> getColuna()) { // C1 

        SparseMatrix * c = new SparseMatrix(a -> getLinha(), a -> getColuna());

        for (int i = 1; i <= a -> getLinha(); i++) { 
            for (int j = 1; j <= a -> getColuna(); j++) { 
                c -> insert(i, j, a -> getValor(i, j) + b -> getValor(i, j)); // é chamado o metodo getValor que tem complexidade O(n) dentro do metodo insert que tem complexidade O(n) logo a complexidade fica O(n^2). Esses metodos são chamados dentro de um for que tem complexidade O(n), então a complexidade fica O(n^3). Porém, esse for está dentro de outro for que tem complexidade O(n), então a complexidade dessa funcão fica O(n^4).
            } 
        }
        return c;
    } else { 
        try {
            throw "ERROR: Matrizes de tamanhos diferentes!";
        } catch (const char * msg) {
            cerr << msg << endl;
        }
        return 0;
    }

}

SparseMatrix * Multiplicacao(SparseMatrix * a, SparseMatrix * b) {
    // verifica se o numero de colunas da primeira matriz e o numero de linhas da
    // segunda matriz sao iguais.
    if (a -> getColuna() == b -> getLinha()) { 

        // cria uma nova matriz com o numero de linhas da segunda matriz e o numero
        // de colunas da primeira matriz.
        SparseMatrix * c = new SparseMatrix(a -> getLinha(), b -> getColuna());

        // percorre as matrizes e realiza o calculo da multiplicacao.
        for (int i = 1; i <= a -> getLinha(); i++) { 
            for (int j = 1; j <= b -> getColuna(); j++) { 
                for (int k = 1; k <= a -> getColuna(); k++) { 
                    c -> insert(i, j, c -> getValor(i, j) + (a -> getValor(i, k) * b -> getValor(k, j)));
                }
            }
        }
        // imprime a matriz.
        c -> Print();
        cout << endl;
        return c;
    } else {
        try {
            throw "ERROR: Matrizes de tamanhos diferentes!";
        } catch (const char * msg) {
            cerr << msg << endl;
        }
        return 0;
    }
}

int verifica_matriz_Usuario1 = 0;
int verifica_matriz_Usuario2 = 0;
int verifica_matriz_Arquivo1 = 0;
int verifica_matriz_Arquivo2 = 0;

int main() {

    // main interativa com switch case.
    int opcao;
    SparseMatrix * a, * b, * c, * d;
    string numero_do_arquivo;

    do {
        primeiro_menu();
        cin >> opcao;
        cout << endl;

        switch (opcao) {
        case 1: {
            // outro switch case para operacoes com matrizes do arquivo.
            int opcao2;
            menu_MatrizArquivo();
            cin >> opcao2;
            cout << endl;

            switch (opcao2) {
            case 1: {
                cout << "Digite o numero do arquivo (1 ou 2): ";
                cin >> numero_do_arquivo;
                if (numero_do_arquivo == "1") {
                    a = readSparseMatrix("matriz1.txt");
                    verifica_matriz_Arquivo1 = 1;
                    cout << "Matriz 1 lida com sucesso!" << endl;
                } else if (numero_do_arquivo == "2") {
                    b = readSparseMatrix("matriz2.txt");
                    verifica_matriz_Arquivo2 = 1;
                    cout << "Matriz 2 lida com sucesso!" << endl;
                } else {
                    try {
                        throw "ERROR: Arquivo nao encontrado!";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }

                break;
            }
            case 2: {
                if (verifica_matriz_Arquivo1 == 1 || verifica_matriz_Arquivo2 == 1) {
                    cout << "Digite qual matriz deseja verificar: ";
                    cin >> numero_do_arquivo;
                    if (numero_do_arquivo == "1" && verifica_matriz_Arquivo1 == 1) {
                        cout << "Digite a linha e a coluna da matriz: ";
                        int linha, coluna;
                        cin >> linha;
                        cin >> coluna;
                        if (linha > 0 && linha <= a -> getLinha() && coluna > 0 && coluna <= a -> getColuna()) {
                            cout << "Valor: " << a -> getValor(linha, coluna) << endl;
                        } else {
                            try {
                                throw "ERROR: Valor nao encontrado!";
                            } catch (const char * msg) {
                                cerr << msg << endl;
                            }
                        }
                    } else if (numero_do_arquivo == "2" && verifica_matriz_Arquivo2 == 1) {
                        cout << "Digite a linha e a coluna da matriz: ";
                        int linha, coluna;
                        cin >> linha;
                        cin >> coluna;
                        if (linha > 0 && linha <= b -> getLinha() && coluna > 0 && coluna <= b -> getColuna()) {
                            cout << "Valor: " << b -> getValor(linha, coluna) << endl;
                        } else {
                            try {
                                throw "ERROR: Valor nao encontrado.";
                            } catch (const char * msg) {
                                cerr << msg << endl;
                            }
                        }
                    } else {
                        try {
                            throw "ERROR: Matriz nao encontrada!";
                        } catch (const char * msg) {
                            cerr << msg << endl;
                        }
                    }
                } else {
                    try {
                        throw "ERROR: Nenhuma matriz foi lida!";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }
                break;
            }
            case 3: {
                if ((verifica_matriz_Arquivo1 == 1 && verifica_matriz_Arquivo2 == 1)) {
                    c = Soma(a, b);
                    c -> Print();
                    cout << endl;
                } else {
                    try {
                        throw "ERROR: Nao foi possivel realizar a soma, nao possui as duas matrizes necessarias para a operacao.";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }
                break;
            }
            case 4: {
                if (verifica_matriz_Arquivo1 == 1 && verifica_matriz_Arquivo2 == 1) {
                    d = Multiplicacao(a, b);
                } else {
                    try {
                        throw "ERROR: Nao foi possivel realizar a multiplicacao, nao possui as duas matrizes necessarias para a operacao.";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }
                break;
            }
            case 5: {
                if (verifica_matriz_Arquivo1 == 1 || verifica_matriz_Arquivo2 == 1) {
                    cout << "Digite qual matriz deseja imprimir: ";
                    cin >> numero_do_arquivo;
                    if (numero_do_arquivo == "1" && verifica_matriz_Arquivo1 == 1) {
                        a -> Print();
                    } else if (numero_do_arquivo == "2" && verifica_matriz_Arquivo2 == 1) {
                        b -> Print();
                    } else {
                        try {
                            throw "ERROR: Matriz nao encontrada!";
                        } catch (const char * msg) {
                            cerr << msg << endl;
                        }
                    }
                } else {
                    try {
                        throw "ERROR: Nenhuma matriz foi lida!";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }
                break;
            }
            case 6: {
                cout << "Voltando..." << endl;
                break;
            }
            default: {
                cout << "Opcao invalida." << endl;
                break;
            }
            }
            break;
        }
        case 2: {
            // outro switch case para operacoes com matrizes do usuario.
            int opcao3;
            menu_MatrizUsuario();
            cin >> opcao3;
            cout << endl;

            switch (opcao3) {
            case 1: {
                // cria matriz do usuario, insere os valores e permite criar outra matriz, guardando a anterior, caso o usuario queira.
                cout << "Crie a Matriz 1 ou a Matriz 2: ";
                string nomeMatriz;
                cin >> nomeMatriz;

                cout << "Insira o tamanho da matriz: ";
                int linha, coluna;
                cin >> linha >> coluna;

                if (nomeMatriz == "1") {
                    a = new SparseMatrix(linha, coluna);
                    verifica_matriz_Usuario1 = 1;
                    cout << "Matriz 1 criada com sucesso!" << endl;
                } else if (nomeMatriz == "2") {
                    b = new SparseMatrix(linha, coluna);
                    verifica_matriz_Usuario2 = 1;
                    cout << "Matriz 2 criada com sucesso!" << endl;
                } else {
                    try {
                        throw "ERROR: Matriz nao encontrada!";
                    } catch (const char * msg) {
                        cerr << msg << endl;
                    }
                }

                break;
            }
            case 2: {
                // verificar se a matriz existe
                if ((verifica_matriz_Usuario1 == 1 && verifica_matriz_Usuario2 == 0) || (verifica_matriz_Usuario1 == 0 && verifica_matriz_Usuario2 == 1) || (verifica_matriz_Usuario1 == 1 && verifica_matriz_Usuario2 == 1)) {

                    cout << "Deseja inserir o valor na Matriz 1 ou 2? ";
                    string nomeMatriz;
                    cin >> nomeMatriz;

                    if (nomeMatriz == "1" && verifica_matriz_Usuario1 == 0) {
                        try {
                            cout << "ERROR: Matriz 1 nao existe." << endl;
                        } catch (const char * e) {
                            cout << e << endl;
                        }
                    } else if (nomeMatriz == "2" && verifica_matriz_Usuario2 == 0) {
                        try {
                            cout << "ERROR: Matriz 2 nao existe!" << endl;
                        } catch (const std::exception & e) {
                            std::cerr << e.what() << '\n';
                        }
                    } else {
                        cout << "Quantos valores voce quer inserir? ";
                        int numValores;
                        cin >> numValores;

                        if ((nomeMatriz == "1" && numValores <= (a -> getLinha() * a -> getColuna())) || (nomeMatriz == "2" && numValores <= (b -> getLinha() * b -> getColuna()))) {
                            for (int k = 0; k < numValores; k++) {
                                cout << "Digite a linha, a coluna e o valor: ";
                                int i, j;
                                double valor;
                                cin >> i >> j >> valor;

                                if (nomeMatriz == "1") {
                                    if (i > 0 && i <= a -> getLinha() && j > 0 && j <= a -> getColuna()) {
                                        a -> insert(i, j, valor);
                                    } else {
                                        try {
                                            throw "ERROR: Celula nao encontrada.";
                                        } catch (const char * e) {
                                            cout << e << endl;
                                        }
                                    }
                                } else if (nomeMatriz == "2") {
                                    if (i > 0 && i <= b -> getLinha() && j > 0 && j <= b -> getColuna()) {
                                        b -> insert(i, j, valor);
                                    } else {
                                        try {
                                            throw "ERROR: Posicao invalida.";
                                        } catch (const char * e) {
                                            cout << e << endl;
                                        }
                                    }
                                } else {
                                    try {
                                        throw "ERROR: Matriz nao encontrada.";
                                    } catch (const char * msg) {
                                        cout << msg << endl;
                                    }
                                }
                            }
                            cout << "Valores inseridos com sucesso!" << endl;
                        } else {
                            try {
                                throw "ERROR: Numero de valores invalido.";
                            } catch (const char * msg) {
                                cout << msg << endl;
                            }
                        }
                    }

                } else {
                    try {
                        throw 1;
                    } catch (int e) {
                        cout << "ERROR: Nao foi possivel inserir valores, matriz nao criada." << endl;
                    }
                    cout << endl;
                    break;
                }
                break;
            }
            case 3: {
                if ((verifica_matriz_Usuario1 == 1 && verifica_matriz_Usuario2 == 1)) {
                    c = Soma(a, b);
                    c -> Print();
                    cout << endl;
                } else {
                    try {
                        throw 1;
                    } catch (int e) {
                        cout << "ERROR: Nao foi possivel realizar a soma, nao possui as duas matrizes necessarias para a operacao." << endl;
                    }
                }
                break;
            }
            case 4: {
                if (verifica_matriz_Usuario1 == 1 && verifica_matriz_Usuario2 == 1) {
                    d = Multiplicacao(a, b);
                } else {
                    try {
                        throw 1;
                    } catch (int e) {
                        cout << "ERROR: Nao foi possivel realizar a multiplicacao, nao possui as duas matrizes necessarias para a operacao." << endl;
                    }
                }
                break;
            }
            case 5: {
                if (verifica_matriz_Usuario1 == 1 || verifica_matriz_Usuario2 == 1) {
                    cout << "Digite qual matriz deseja imprimir: ";
                    cin >> numero_do_arquivo;
                    cout << endl;
                    if (numero_do_arquivo == "1" && verifica_matriz_Usuario1 == 1) {
                        a -> Print();
                    } else if (numero_do_arquivo == "2" && verifica_matriz_Usuario2 == 1) {
                        b -> Print();
                    } else {
                        try {
                            throw 1;
                        } catch (int e) {
                            cout << "ERROR: Matriz nao encontrada!" << endl;
                        }
                    }
                } else {
                    try {
                        throw 1;
                    } catch (int e) {
                        cout << "ERROR: Nao foi possivel imprimir, matrizes nao criadas." << endl;
                    }
                }
                cout << endl;
                break;
            }
            case 6: {
                cout << "Voltando..." << endl;
                break;
            }
            default: {
                cout << "Opcao invalida." << endl;
                break;
            }
            break;
            }
            break;
        }
        case 3: {
            menu_saida();
            a -> ~SparseMatrix();
            b -> ~SparseMatrix();
            c -> ~SparseMatrix();
            d -> ~SparseMatrix();
            break;
        }
        default: {
            system("clear || cls");
            cout << endl;
            cout << "Opcao invalida" << endl;
            break;
        }
        break;
        }
    } while (opcao != 3);
}