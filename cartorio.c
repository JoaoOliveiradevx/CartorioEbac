#include <stdio.h>  //Biblioteca de Comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro()//Respons�vel porr cadastrar usu�rios
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio da cria��o de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); ///coletando informa��es de usu�rio
	scanf("%s", cpf);//%s � referente a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo/"w"significa write 	
	fprintf(file,cpf); //Salvo o valor da v�riavel
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo existente
	fprintf(file, ","); // "," para que a apresenta��o das informa��es possua uma separa��o
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //"a" atualiza o arquivo existente
	fprintf(file,","); // "," para que a apresenta��o das informa��es possua uma separa��o
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo existente
	fprintf(file,","); // "," para que a apresenta��o das informa��es possua uma separa��o
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
		
	
	
}

int consulta()//Consultando informa��es de usu�rios
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" de read, significando leituda dos arquivos
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");	
	}	
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto o que for escrito em conteudo tiver o tamanho maximo de 200, dentro do arquivo(file), ir� rodar ate trazer todas as informa��es / Ir� parar quando um caractere for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);
		printf("\n\n");	
	}	
	
	system("pause");
	
	fclose(file);	
	
} 	



int deletar()//Deleta informa��es de usu�rios
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	 
	
	
	FILE *file;
	file = fopen(cpf, "r"); //r para ler arquivos
	
	
	
	
	
	if(file==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
	if(file!=NULL)
	{
		remove(cpf);
		printf("Usu�rio deletado! \n");
		system("pause");
	}
	
	
	fclose(file);
			
}


int main ()
{
	int opcao=0; //Definindo v�riaveis
	int laco=1;
			
		
		
	for(laco=1;laco=1;)
	
	{
		
		system("cls");//Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cart�rio da EBAC ### \n\n");//In�cio do men�
		printf("Escolha a op��o desejada do men�: \n\n");
		printf("\t1 - Registrar nomes: \n"); 
		printf("\t2 - Consultar nomes: \n");
		printf("\t3 - Deletar nomes: \n\n");//Final do men�	
		printf("\t4 - Sair do sistema \n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio	
	
		system("cls");
		
		switch(opcao)//In�cio da sele��o do men�
		{
			case 1:
			registro();//Chamada de fun��o
			break;	
			
			case 2:
			consulta();//Chamada de fun��o
			break;
			
			case 3:
			deletar();//Chamada de fun��o
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!\n");
			return 0;
			
		break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
			
		}
	}
	
}
