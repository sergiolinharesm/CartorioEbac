#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o
#include <string.h> //biblioteca responsável por cuidar dos strings

int registro() //função responsável por cadastrar os usuários
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o seu CPF para cadastro: "); //coletando informação do usuário
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //salva na pasta - o "W" signifca "Write" ou "escrever"
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "A" é o comando para alterar ele
	fprintf(file,","); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Usuário cadastra o nome
	scanf("%s",nome); //%s se refere a string
	
	file = fopen(arquivo,"a"); //Abre o arquivo para alterar
	fprintf(file,nome);  //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,","); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Mensagem ao usuário para ele informar o sobrenome
	scanf("%s",sobrenome); //%s se refere a string
	
	file = fopen(arquivo,"a"); //Abre o arquivo para alterar
	fprintf(file,sobrenome); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,","); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Mensagem ao usuário para ele informar o cargo
	scanf("%s",cargo); //%s se refere a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,cargo); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa a tela para não retornar ao inicio
}

int consulta() //Função responsável pela consulta de usuário
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio da consulta de variáveis/string
	char cpf[40]; 
	char conteudo[200]; 
	//Final da consulta de variáveis/string
	
	printf("Digite o CPF para a consulta: "); //Mensagem ao usuário para ele informar o cpf a ser consultado
	scanf("%s",cpf); //%S se refere a string
	
	FILE *file; //Acessa o arquivo file
	file = fopen(cpf,"r"); //Lê as informações do arquivo file "R" Read
	
	if(file == NULL) //Se o resultado for "NULL" não encontrado
	{
		printf("Consulta não encontrada\n"); //Mensagem ao usuário de arquivo não encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Usuário encontrado
	{
		printf("\nEssas são as informações do usuário: "); //Mensagem para o usuário com as informações solicitadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa a tela para não retornar ao inicio
}

int deletar() ////Função responsável por deletar usuário
{
	//inicio da consulta de variáveis/string
	char cpf[40];
	//Final da consulta de variáveis/string
	
	printf("Digite o CPF a ser deletado: "); //Mensagem para o usuário informar o CPF para deletar
	scanf ("%s",cpf); //%s se refere a string
	
	remove(cpf); //Deleta o CPF informado
	
	FILE *file;
	file = fopen(cpf,"r"); //Faz a leitura do arquivo
	
	if(file == NULL) //Se o resultado for "NULL" não encontrado
	{
		printf("Usuário não encontrado ou já deletado\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo looping

	for(laco=1;laco=1;)
	{

		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem

		system("cls"); //apaga a tela (clean)

		//Inicio do menu
		printf("##############################\n");
		printf("##### Cartório do Sérgio #####\n");
		printf("##############################\n\n");
		printf("Escolha sua opção no menu abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Digite a opção desejada: ");
		//Final do menu

		scanf("%d", &opcao); //inicio da seleção

		system("cls"); //apaga a tela (clean)

		switch(opcao) //Inicio da seleção do menu
		{
			case 1:
                registro(); //Chama a função de registro
			break;
			case 2:
			    consulta(); //Chama a função de consulta
			break;
            case 3:
			    deletar(); //Chama a função de deletar
			break;
			default:
			    printf("Opção inválida, selecione uma das opções exibidas no menu\n\n");
				system("pause");
				break;
		} //Fim da seleção

	}
}


