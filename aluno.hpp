#ifndef __aluno_hpp
#define __aluno_hpp

#include <iostream>
#include <string>
#include "aluno.h"

using namespace std;

void PrintarNomes(string nomes[]){
  cout << "\n\n";
  for(int i=0; i<5; i++){
    if (i == 4){
      cout << nomes[i] << endl;
    }else{
      cout << nomes[i] << " / ";
    }
  }
}

tAluno aluno; 

void CalculaMedia(string nome[], int P1[], int P2[], bool encontrou=false){

  string procurar;

  do{
    PrintarNomes(nome);

    cout << "Digite o nome de quem voce deseja consultar a media: ";
    cin >> procurar;

    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      aluno.P1 = P1[i];
      aluno.P2 = P2[i];

      if (aluno.nome == procurar){ 
        cout << "A media do aluno " << aluno.nome << " foi: " << getMedia(&aluno); 
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false); 
}

void AddNome(string nome[], string* pNome, bool alterou=false){
  string mudarNome, novoNome;

  do{
    PrintarNomes(nome);

    cout << "Digite o nome de quem voce deseja mudar: ";
    cin >> mudarNome;
    cout << "Digite o nome a ser colocado no lugar: ";
    cin >> novoNome;

    int tam = novoNome.length(); 
    char charNome[tam]; 

    for(int i=0; i<tam; i++){
      charNome[i] = novoNome[i];
    }

    char* pCharNome = charNome;

    for (int i=0; i<5; i++){
      aluno.nome = nome[i];

      if (aluno.nome == mudarNome){
        setNome(&aluno, pCharNome, tam);
        alterou = true;
        *(pNome+i) = aluno.nome;
      }
    }
    if (alterou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(alterou==false);
}


void ProcurarPorNota(string nome[], int p1[], int p2[]){
  int nota;
  
  cout << "Digite uma nota para procurar os alunos com notas iguais: ";
  cin >> nota;

  string sNota = "";
  sNota = to_string(nota);

  int tam = sNota.length();
  char charNota[tam]; 

  for(int i=0; i<tam; i++){
    charNota[i] = sNota[i];
  }

  char* pCharNota = charNota;


  for (int i=0; i<5; i++){
    aluno.nome = nome[i];
    aluno.P1 = p1[i];
    aluno.P2 = p2[i];

    if (aluno.P1 == nota){ 
      getNome(&aluno, pCharNota);
      cout << " tirou" << nota << " na P1." << endl; 
    }
    if (aluno.P2 == nota){
      getNome(&aluno, pCharNota);
      cout << " tirou" << nota << " na P2." << endl;
    }
  }
}

void AddNotas(string nome[], int* pP1, int* pP2, bool encontrou=false){
  string procurar;
  int nota1, nota2;

  do{
    PrintarNomes(nome);

    cout << "Digite o nome de quem voce deseja definir as notas: ";
    cin >> procurar;
    cout << "Digite a nota a nota da P1 a ser definida: ";
    cin >> nota1;
    cout << "Digite a nota a nota da P2 a ser definida: ";
    cin >> nota2;

    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      if (aluno.nome == procurar){
        leDadosAluno(&aluno, nota1, nota2);
        
        *(pP1+i) = nota1;
        *(pP2+i) = nota2; 
        
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}



void AddP1(string nome[], int* pP1, bool encontrou=false){
  string procurar;
  int nota;
  do{
    PrintarNomes(nome);
    cout << "Digite o nome de quem voce deseja definir a nota P1: ";
    cin >> procurar;
    cout << "Digite a nota a ser definida: ";
    cin >> nota;
    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      if (aluno.nome == procurar){
        setP1(&aluno, nota);
        *(pP1+i) = nota;
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}

void AddP2(string nome[], int* pP2, bool encontrou=false){
  string procurar;
  int nota;
  do{
    PrintarNomes(nome);
    cout << "Digite o nome de quem voce deseja definir a nota P2: ";
    cin >> procurar;
    cout << "Digite a nota a ser definida: ";
    cin >> nota;
    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      if (aluno.nome == procurar){
        setP2(&aluno, nota);
        *(pP2+i) = nota;
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}

void NotasDoAluno(string nome[], int P1[], int P2[], bool encontrou=false){
  string procurar;
  do{
    PrintarNomes(nome);
    cout << "Digite o nome de quem voce deseja consultar as notas: ";
    cin >> procurar;
    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      aluno.P1 = P1[i];
      aluno.P2 = P2[i];
      if (aluno.nome == procurar){
        imprimeAluno(&aluno);
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}


void NotaP1(string nome[], int P1[], bool encontrou=false){
  string procurar;
  do{
    PrintarNomes(nome);
    cout << "Digite o nome de quem voce deseja consultar a nota P1: ";
    cin >> procurar;
    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      aluno.P1 = P1[i];
      if (aluno.nome == procurar){
        cout << "\n\nNota do " << aluno.nome << " na P1: " << getP1(&aluno) << "\n\n";
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}


void NotaP2(string nome[], int P2[], bool encontrou=false){
  string procurar;
  do{
    PrintarNomes(nome);
    cout << "Digite o nome de quem voce deseja consultar a nota P2: ";
    cin >> procurar;
    for (int i=0; i<5; i++){
      aluno.nome = nome[i];
      aluno.P2 = P2[i];
      if (aluno.nome == procurar){
        cout << "\n\nNota do " << aluno.nome << " na P2: " << getP2(&aluno) << "\n\n";
        encontrou = true;
      }
    }
    if (encontrou == false){
      cout << "\nNome nao encontrado. Preste atenção nas letras maiusculas e minusculas." << endl;
    }
  }while(encontrou==false);
}


#endif