#include <iostream>
#include "aluno.hpp"

using namespace std;

int main() {
  string nome[5] = {"Lucas", "Joao", "Ana", "Maria", "Clara"};
  int p1[5] = {10, 8, 5, 8, 6};
  int p2[5] = {7, 8, 9, 5, 10};
  string* pNome = nome;
  int* pP1 = p1;
  int* pP2 = p2;

  bool rodar=true;
  while(rodar){
    int opcao;
    cout << "\n\n\n ESCOLHA UMA OPCAO PARA PROSSEGUIR" << endl;
    cout << "  1) Adicionar ou mudar um nome." << endl;
    cout << "  2) Adicionar ou mudar as duas notas de um aluno." << endl;
    cout << "  3) Adicionar ou mudar a nota P1 de um aluno" << endl;
    cout << "  4) Adicionar ou mudar a nota P2 de um aluno" << endl;
    cout << "  5) Imprimir as duas notas de um aluno." << endl;
    cout << "  6) Imprimir a primeira (P1) nota de um aluno." << endl;
    cout << "  7) Imprimir a segunda nota (P2) de um aluno." << endl;
    cout << "  8) Calcular a media das duas notas de um aluno." << endl;
    cout << "  9) Procurar um aluno pelas notas." << endl;
    cout << "  0) Fechar programa." << endl;
    cout << " -> ";
    cin >> opcao;

    switch(opcao){
      case 1:
        AddNome(nome, pNome);
        break;
      case 2:
        AddNotas(nome, pP1, pP2);
        break;
      case 3:
        AddP1(nome, pP1);
        break;
      case 4:
        AddP2(nome, pP2);
        break;
      case 5:
        NotasDoAluno(nome, p1, p2);
        break;
      case 6:
        NotaP1(nome, p1);
        break;
      case 7:
        NotaP2(nome, p2);
        break;
      case 8:
        CalculaMedia(nome, p1, p2);
        break;
      case 9:
        ProcurarPorNota(nome, p1, p2);
        break;
      default:
        rodar = false;
        break;
    }
  }
}