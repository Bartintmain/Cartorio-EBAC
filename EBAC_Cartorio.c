#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //O "w"  cria um arquivo em modo texto para grava��o.
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
    system("pause"); //Pausar a execu��o do programa at� que o usu�rio aperte uma tecla qualquer

}

int consulta() //Fun��o responsavel por consultar usu�rio no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o de variaveis/string
	char cpf [40];
	char conteudo[200];
	//Final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser consultado:"); //Coletando informa��o do usu�rio
	scanf("%s" ,cpf); //%s refere-se a string
	
	FILE *file; //Criar o arquivo
	file = fopen(cpf,"r"); //O �r� abre um arquivo para leitura em modo texto
	
	if(file == NULL) //Representa uma refer�ncia nula, que n�o faz refer�ncia a qualquer objeto
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //A fun��o fgets especifica o tamanho m�ximo da string de entrada
	{
    	printf("Essas s�o as informa��es do usu�rio:\n ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");//Pausar a execu��o do programa at� que o usu�rio aperte uma tecla qualquer
	
}


int deletar() //Fun��o responsavel por deletar usu�rio do sistema
{
	char cpf[40]; //Cria��o de variaveis/string
	
	printf("Vo�e escolheu deletar nomes: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); //O �r� abre um arquivo para leitura em modo texto
	

	if(file == NULL) //Representa uma refer�ncia nula, que n�o faz refer�ncia a qualquer objeto
	{ 
		printf("O usu�rio n�o se encontrta no sistema!.\n");
		system("pause"); //Pausar a execu��o do programa at� que o usu�rio aperte uma tecla qualquer
	}
        fclose(file);
}

int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		 
		printf("Op��o: ");//fim do menu
		
		
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //Respons�vel por limpar a tela
	
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro(); //Chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
		    case 4:
		    printf("Obrigado por utilizar nosso sistema!\n");
		    return 0;
		    break;
				
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}
