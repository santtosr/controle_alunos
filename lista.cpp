#include "lista.h"

// cria uma nova lista duplamente encadeada
void novaLista(lista* l){
	l->cabeca = new aluno;
	l->cabeca->ant = l->cabeca->prox = NULL;

}

// cria um novo aluno
void novoAluno(aluno* a){

	getchar();
	printf("    Informe o Nome do Aluno: ");
	scanf("%[^\n]", a->nome);

	printf("    Informe o RA do Aluno: ");
	scanf("%d", &a->ra);

	printf("    Informe a nota da P1: ");
	scanf("%f", &a->p1);

	printf("    Informe a nota da P2: ");
	scanf("%f", &a->p2);

	printf("    Informe a nota do Trabalho: ");
	scanf("%f", &a->t);

	printf("    Informe a nota da PO: ");
	scanf("%f", &a->po);


	if (a->po > a->p1 || a->po > a->p2){
		if (a->p1 > a->p2){
			a->mf = ((a->p1 * 0.35) + (a->po * 0.35) + (a->t *0.3));
		} else {
			a->mf = ((a->p2 * 0.35) + (a->po * 0.35) + (a->t *0.3));
		}
	} else {
		a->mf = ((a->p2 * 0.35) + (a->p1 * 0.35) + (a->t *0.3));
	}


}

// insere um novo aluno na lista 
// em ordem alfabetica lexicografica
void insere(aluno* a, lista* l){

	aluno *p, *q;

	q = l->cabeca;
	p = l->cabeca->prox;


	while(p != NULL && !(strcmp(p->nome, a->nome) > 0 
		&& strcmp(a->nome, q->nome) > 0)){

		q = p;
		p = p->prox;
	}

	a->ant = q;
	a->prox = p;
	q->prox = a;

	if(p != NULL)
		p->ant = a;
}

// busca os alunos de acordo com a entrada
// e imprime sua media final e se foram aprovado ou reprovado
void busca(char nome[], lista* l){

	aluno *q, *p;
	char* res;
	int cont = 0;

	q = l->cabeca;
	p = l->cabeca->prox;

	while(p != NULL){
		q = p;
		p = p->prox;

		res = strstr(q->nome, nome);
		if(res != NULL){
			printf("\n");
			printf("  Aluno: %s- Media Final: %.1f\n", q->nome, q->mf);
			if(q->mf >= 6.0){
				printf("   Aprovado!\n");
			} else {
				printf("   Reprovado!\n");
			}

			cont++;
		}
	}

	if (cont == 0)
		printf("   O Nome informado não foi encontrado!! \n");
}

void lerArquivo(char arquivo[], lista* l){

	aluno* a;

	int cont = 0;
	FILE *infile;

	infile = fopen(arquivo, "r");


	while(!feof(infile)){
		a = new aluno;
		fscanf(infile, "%[^0-9]", a->nome);
		fscanf(infile, "%d", &a->ra);
		fscanf(infile, "%f", &a->p1);
		fscanf(infile, "%f", &a->p2); 
		fscanf(infile, "%f", &a->t);
		fscanf(infile, "%f %*[^A-Za-zEOF]", &a->po);

		if (a->po > a->p1 || a->po > a->p2){
			if (a->p1 > a->p2){
				a->mf = ((a->p1 * 0.35) + (a->po * 0.35) + (a->t *0.3));
			} else {
				a->mf = ((a->p2 * 0.35) + (a->po * 0.35) + (a->t *0.3));
			}
		} else {
			a->mf = ((a->p2 * 0.35) + (a->p1 * 0.35) + (a->t *0.3));
		}
		cont++;
		insere(a, l);
	}
	fclose(infile);
	printf("   Total: %d\n", cont);
}


void gerarArquivoAprovados(lista* l){
	
	ofstream outfile;
	outfile.open("aprovados.txt", ios::trunc);
	
	aluno *p, *q;
	q = l->cabeca;
	p = l->cabeca->prox;

	int cont = 0;

	while(p != NULL){
		q = p;
		p = p->prox;

		if(q->mf >= 6.0){
			cont++;
			outfile << "Nome: " << q->nome << ", ";
			outfile << "Media Final: " << q->mf << "\n";
		}
	}
	outfile.close();
	printf("  Total: %d\n", cont);
}

void gerarArquivoReprovados(lista* l){
	
	ofstream outfile;
	outfile.open("reprovados.txt", ios::trunc);
	
	aluno *p, *q;
	q = l->cabeca;
	p = l->cabeca->prox;

	int cont = 0;
	while(p != NULL){
		q = p;
		p = p->prox;

		if(q->mf <= 5.9){
			cont++;
			outfile << "Nome: " << q->nome << ", ";
			outfile << "Media Final: " << q->mf << "\n";
		}
	}
	outfile.close();
	printf("  Total: %d\n", cont);
}
