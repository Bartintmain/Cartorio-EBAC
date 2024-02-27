#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Início da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //O "w"  cria um arquivo em modo texto para gravação.
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); //Cria uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar 
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
    system("pause"); //Pausar a execução do programa até que o usuário aperte uma tecla qualquer

}

int consulta() //Função responsavel por consultar usuário no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da criação de variaveis/string
	char cpf [40];
	char conteudo[200];
	//Final da criação de variaveis/string
	
	printf("Digite o CPF a ser consultado:"); //Coletando informação do usuário
	scanf("%s" ,cpf); //%s refere-se a string
	
	FILE *file; //Criar o arquivo
	file = fopen(cpf,"r"); //O “r” abre um arquivo para leitura em modo texto
	
	if(file == NULL) //Representa uma referência nula, que não faz referência a qualquer objeto
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //A função fgets especifica o tamanho máximo da string de entrada
	{
    	printf("Essas são as informações do usuário:\n ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");//Pausar a execução do programa até que o usuário aperte uma tecla qualquer
	
}


int deletar() //Função responsavel por deletar usuário do sistema
{
	char cpf[40]; //Criação de variaveis/string
	
	printf("Voçe escolheu deletar nomes: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); //O “r” abre um arquivo para leitura em modo texto
	

	if(file == NULL) //Representa uma referência nula, que não faz referência a qualquer objeto
	{ 
		printf("O usuário não se encontrta no sistema!.\n");
		system("pause"); //Pausar a execução do programa até que o usuário aperte uma tecla qualquer
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
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		 
		printf("Opção: ");//fim do menu
		
		
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //Responsável por limpar a tela
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro(); //Chamada de funções 
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
