#ifndef __aluno_h
#define __aluno_h

#include <iostream>

using namespace std;

struct tAluno{
    string nome;
    int P1, P2; 
};

float getMedia(tAluno* aluno){
  return ((aluno->P1 + aluno->P2)/2);
} 

void setNome(tAluno* aluno, char *Nome, int tam){
  string novoNome;
  for(int i=0; i<tam; i++){
    novoNome += *(Nome+i);
  }
  aluno->nome = novoNome;
}

void setP1(tAluno* aluno, int P1){
  aluno->P1 = P1;
}

void setP2(tAluno* aluno, int P2){
  aluno->P2 = P2;
}

void imprimeAluno(tAluno* aluno){
  cout << "\n\nA nota do " << aluno->nome << " na P1 foi " << aluno->P1 << endl;
  cout << "A nota do " << aluno->nome << " na P2 foi " << aluno->P2 << endl;
}

void leDadosAluno(tAluno* aluno, int P1, int P2){
  aluno->P1 = P1;
  aluno->P2 = P2;
}

void getNome(tAluno* aluno, char *Nome){
  cout << aluno->nome;
}

int getP1(tAluno* aluno){
  return aluno->P1;
}

int getP2(tAluno* aluno){
  return aluno->P2;
}

#endif