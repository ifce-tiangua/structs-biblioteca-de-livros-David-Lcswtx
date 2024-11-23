#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Livro{
	
	char nome[50];
	char isbn[30];
	float preco;
	int score;
	char editora[30];
	
};


typedef struct Livro* pLivro;

pLivro livro_aloc(int qtde){
	
	pLivro livros = (pLivro)malloc(qtde * sizeof(struct Livro));
	
	return livros;
	
}

void livro_ler(pLivro livros, int qtde){
	
	int i;
	
	for (i = 0; i < qtde; i++){
		scanf(" %[^\n]", livros[i].nome);
		scanf("%s", livros[i].isbn);
		scanf("%f", &livros[i].preco);
		scanf("%d", &livros[i].score);
		scanf(" %[^\n]", livros[i].editora);
	}
	
}

void livro_exibe(pLivro livros, int qtde){
	
	int i;
	
	for (i = 0; i < qtde; i++){
		
		printf("Livro %d:\n", i + 1);
		printf("Nome: %s\n", livros[i].nome);	
		printf("ISBN: %s\n", livros[i].isbn);
		printf("Preço: R$ %.2f\n", livros[i].preco);
		printf("Score: %d\n", livros[i].score);
		printf("Editora: %s\n", livros[i].editora);
		
		if(i < qtde - 1){
			printf("\n");
		}
		
	}
	
}

void livro_desaloca(pLivro livros){	
	
	free(livros);
	
}

int main(){
	
	int quantidade;
	
	scanf("%d",&quantidade);
	
	if(quantidade <= 0){
		printf("Sem livros\n");
		
		return 0;
	}
	
	pLivro livros = livro_aloc(quantidade);
	
	livro_ler(livros, quantidade);
	
	livro_exibe(livros, quantidade);
	
	livro_desaloca(livros);
	
	return 0;	
}
