#include <iostream>
#include "menu.h"

using namespace std;

void primeiro_menu() {
    cout << "+=============================================+" << endl;
    cout << "|(1) - Operacoes com Matriz do Arquivo        |" << endl;
    cout << "|(2) - Operacoes com Matriz do Usuario        |" << endl;
    cout << "|(3) - Sair                                   |" << endl;
    cout << "+=============================================+" << endl;
    cout << "Opcao: ";
}

void menu_MatrizArquivo() {
    system ("clear || cls");
    cout << "+=============================================+" << endl;
    cout << "|(1) - Ler Matriz                             |" << endl;
    cout << "|(2) - Retorna o valor da celula da Matriz    |" << endl;
    cout << "|(3) - Soma                                   |" << endl;
    cout << "|(4) - Multiplicacao                          |" << endl;
    cout << "|(5) - Imprime                                |" << endl;
    cout << "|(6) - Voltar                                 |" << endl;
    cout << "+=============================================+" << endl;
    cout << "Opcao: ";
}

void menu_MatrizUsuario() {
    system ("clear || cls");
    cout << "+=============================================+" << endl;
    cout << "|(1) - Criar Matriz                           |" << endl;
    cout << "|(2) - Insere o valor na Matriz               |" << endl;
    cout << "|(3) - Soma                                   |" << endl;
    cout << "|(4) - Multiplicacao                          |" << endl;
    cout << "|(5) - Imprime                                |" << endl;
    cout << "|(6) - Voltar                                 |" << endl;
    cout << "+=============================================+" << endl;
    cout << "Opcao: ";
}

void menu_saida() {
    system("clear || cls");
    cout << endl;
    cout << "+==================================+\n";
    cout << "|           DESENVOLVIDO           |\n";
    cout << "|               POR:               |\n";
    cout << "|==================================|\n";
    cout << "|         - KAYNAN PEREIRA         |\n";
    cout << "|         - VICTOR EMANUEL         |\n";
    cout << "|==================================|\n";
    cout << "|   CIENCIA DA COMPUTACAO 2022.2   |\n";
    cout << "|==================================|\n";
    cout << "|      UFC - CAMPUS DE QUIXADA     |\n";
    cout << "|==================================|\n";
    cout << "|             DISCIPLINA:          |\n";
    cout << "|         ESTRUTURA DE DADOS       |\n";
    cout << "|==================================|\n";
    cout << "|              PROJETO:            |\n";  
    cout << "|           MATRIZ ESPARSA         |\n";
    cout << "|==================================|\n";
    cout << "|             PROFESSOR:           |\n";
    cout << "|            ATILIO GOMES          |\n";
    cout << "+==================================+\n";

    cout << endl;
}