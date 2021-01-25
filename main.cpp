#include <stdio.h>
#include "lista.h"


int main(){

	int op;
	char nome[50];
	char arquivo[15];

// instancia uma lista
	lista* listaAlunos;
	listaAlunos = new lista;
	novaLista(listaAlunos);


	do {

	        printf("\n");
	        printf("---------------Escolha uma Opção---------------\n");
	        printf("      1 - Cadastrar Aluno \n");
	        printf("      2 - Busar Alunos \n");
	        printf("      3 - Ler arquivo de alunos\n");
	        printf("      4 - Gerar arquivo de aprovados\n");
	        printf("      5 - Gerar arquivo de reprovados\n");
	        printf("      0 - Encerrar programa. \n");
	        printf("-----------------------------------------------\n");
	        printf("  Qual operação deseja realizar: ");
	        scanf("%d", &op);


	    switch (op) {

	        case 1:
	        //instacia um novo aluno
	        	aluno* novo;
				novo = new aluno;
				novoAluno(novo);

				insere(novo, listaAlunos);
			        	
	    	break;
	    	case 2:
	    		getchar();
	    		printf("   Informe o nome que deseja buscar: ");
	    		scanf("%[^\n]", nome);
	    		busca(nome, listaAlunos);
	    		
	    	break;
	    	case 3:
	    		getchar();
	    		printf("  Informe o nome do arquivo que deseja ler: ");
	    		scanf("%[^\n]", arquivo);
	    		lerArquivo(arquivo, listaAlunos);

	    	break;
	    	case 4:
	    		gerarArquivoAprovados(listaAlunos);

	    	break;
	    	case 5:
	    		gerarArquivoReprovados(listaAlunos);

	    	break;
	        default:
	            printf("\n");
	            printf("   Programa finalizado. \n");
	            printf("\n");
	        break;
	    }

	} while (op != 0);


	return 0;
}