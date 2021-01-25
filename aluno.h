//define a estrutura de um nó 
//de uma lista duplamente encadeada 

#define ALUNO_H_INCLUDED
#ifdef ALUNO_H_INCLUDED

struct aluno {
	char nome[50];
	int ra;
	float p1;
	float p2;
	float t;
	float po;
	float mf;

	aluno* ant;
	aluno* prox;
};

#endif