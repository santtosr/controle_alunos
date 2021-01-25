

#define LISTA_H_INCLUDED
#ifdef LISTA_H_INCLUDED

#include "cstdio"
#include "stdlib.h"
#include "aluno.h"
#include "cstring"
#include "iostream"
#include "fstream"

using namespace std;


struct lista {
	aluno* cabeca;
};

void novaLista(lista* l);
void novoAluno(aluno* a);
void insere(aluno* a, lista* l);
void busca(char nome[], lista* l);
void lerArquivo(char arquivo[], lista* l);
void gerarArquivoAprovados(lista* l);
void gerarArquivoReprovados(lista* l);

#endif