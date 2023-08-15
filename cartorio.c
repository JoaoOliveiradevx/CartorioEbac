#include <stdio.h>  //Biblioteca de Comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memoria
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro()//Responsável porr cadastrar usuários
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); ///coletando informações de usuário
	scanf("%s", cpf);//%s é referente a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo/"w"significa write 	
	fprintf(file,cpf); //Salvo o valor da váriavel
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo existente
	fprintf(file, ","); // "," para que a apresentação das informações possua uma separação
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //"a" atualiza o arquivo existente
	fprintf(file,","); // "," para que a apresentação das informações possua uma separação
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo existente
	fprintf(file,","); // "," para que a apresentação das informações possua uma separação
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
		
	
	
}

int consulta()//Consultando informações de usuários
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
		printf("Não foi possível abrir o arquivo, não localizado! \n");	
	}	
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto o que for escrito em conteudo tiver o tamanho maximo de 200, dentro do arquivo(file), irá rodar ate trazer todas as informações / Irá parar quando um caractere for nulo
	{
		printf("\nEssas são as informações do usuário: "); 
		printf("%s", conteudo);
		printf("\n\n");	
	}	
	
	system("pause");
	
	fclose(file);	
	
} 	



int deletar()//Deleta informações de usuários
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	 
	
	
	FILE *file;
	file = fopen(cpf, "r"); //r para ler arquivos
	
	
	
	
	
	if(file==NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
	if(file!=NULL)
	{
		remove(cpf);
		printf("Usuário deletado! \n");
		system("pause");
	}
	
	
	fclose(file);
			
}


int main ()
{
	int opcao=0; //Definindo váriaveis
	int laco=1;
			
		
		
	for(laco=1;laco=1;)
	
	{
		
		system("cls");//Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ### \n\n");//Início do menú
		printf("Escolha a opção desejada do menú: \n\n");
		printf("\t1 - Registrar nomes: \n"); 
		printf("\t2 - Consultar nomes: \n");
		printf("\t3 - Deletar nomes: \n\n");//Final do menú	
		printf("\t4 - Sair do sistema \n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário	
	
		system("cls");
		
		switch(opcao)//Início da seleção do menú
		{
			case 1:
			registro();//Chamada de função
			break;	
			
			case 2:
			consulta();//Chamada de função
			break;
			
			case 3:
			deletar();//Chamada de função
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!\n");
			return 0;
			
		break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
			
		}
	}
	
}
