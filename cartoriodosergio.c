#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o seu CPF para cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //salva na pasta - o "W" signifca "Write" ou "escrever"
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "A" � o comando para alterar ele
	fprintf(file,","); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Usu�rio cadastra o nome
	scanf("%s",nome); //%s se refere a string
	
	file = fopen(arquivo,"a"); //Abre o arquivo para alterar
	fprintf(file,nome);  //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,","); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Mensagem ao usu�rio para ele informar o sobrenome
	scanf("%s",sobrenome); //%s se refere a string
	
	file = fopen(arquivo,"a"); //Abre o arquivo para alterar
	fprintf(file,sobrenome); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,","); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Mensagem ao usu�rio para ele informar o cargo
	scanf("%s",cargo); //%s se refere a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo para alterar
	fprintf(file,cargo); //Altera o valor
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa a tela para n�o retornar ao inicio
}

int consulta() //Fun��o respons�vel pela consulta de usu�rio
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio da consulta de vari�veis/string
	char cpf[40]; 
	char conteudo[200]; 
	//Final da consulta de vari�veis/string
	
	printf("Digite o CPF para a consulta: "); //Mensagem ao usu�rio para ele informar o cpf a ser consultado
	scanf("%s",cpf); //%S se refere a string
	
	FILE *file; //Acessa o arquivo file
	file = fopen(cpf,"r"); //L� as informa��es do arquivo file "R" Read
	
	if(file == NULL) //Se o resultado for "NULL" n�o encontrado
	{
		printf("Consulta n�o encontrada\n"); //Mensagem ao usu�rio de arquivo n�o encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Usu�rio encontrado
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Mensagem para o usu�rio com as informa��es solicitadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa a tela para n�o retornar ao inicio
}

int deletar() ////Fun��o respons�vel por deletar usu�rio
{
	//inicio da consulta de vari�veis/string
	char cpf[40];
	//Final da consulta de vari�veis/string
	
	printf("Digite o CPF a ser deletado: "); //Mensagem para o usu�rio informar o CPF para deletar
	scanf ("%s",cpf); //%s se refere a string
	
	remove(cpf); //Deleta o CPF informado
	
	FILE *file;
	file = fopen(cpf,"r"); //Faz a leitura do arquivo
	
	if(file == NULL) //Se o resultado for "NULL" n�o encontrado
	{
		printf("Usu�rio n�o encontrado ou j� deletado\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //Definindo looping

	for(laco=1;laco=1;)
	{

		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem

		system("cls"); //apaga a tela (clean)

		//Inicio do menu
		printf("##############################\n");
		printf("##### Cart�rio do S�rgio #####\n");
		printf("##############################\n\n");
		printf("Escolha sua op��o no menu abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Digite a op��o desejada: ");
		//Final do menu

		scanf("%d", &opcao); //inicio da sele��o

		system("cls"); //apaga a tela (clean)

		switch(opcao) //Inicio da sele��o do menu
		{
			case 1:
                registro(); //Chama a fun��o de registro
			break;
			case 2:
			    consulta(); //Chama a fun��o de consulta
			break;
            case 3:
			    deletar(); //Chama a fun��o de deletar
			break;
			default:
			    printf("Op��o inv�lida, selecione uma das op��es exibidas no menu\n\n");
				system("pause");
				break;
		} //Fim da sele��o

	}
}


