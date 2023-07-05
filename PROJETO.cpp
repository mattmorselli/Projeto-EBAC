#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de alocacao de espaco em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar novos usu�rios
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo (w significa write)
	fprintf(file, "CPF: "); // salva a escrita CPF: antes do valor do CPF em si
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo j� existente
	fprintf(file, "\n"); //para dar um espa�o entre o CPF e o Nome
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo j� existente
	fprintf(file, "Nome: "); // salva a escrita Nome: antes do valor do nome em si
	fprintf(file, nome); // salva o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo j� existente
	fprintf(file, "\n"); //para dar um espa�o entre o Nome e o Sobrenome
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a strings
	
	file = fopen (arquivo, "a");
	fprintf(file, "Sobrenome: "); 
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{ 
		printf ("Cadastro n�o localizado \n");
	}
	
	else
	printf("Informa��es do usu�rio:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	
	fclose(file);
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	
}


int main()
	{
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao; //
	
	printf("### Cart�rio da EBAC ### \n \n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //func�o de compara��o de strings
	
	if(comparacao == 0) //se for igual, retorna 0
	{
		for(laco=1;laco=1;) // repeti��o dos comandos
		{
		
			system("cls"); //limpa a tela
		
			setlocale(LC_ALL, "Portuguese"); //defini��o do idioma
		
			printf("### Cart�rio da EBAC ### \n \n"); //inicio do menu
			printf("Escolha a op��o desejada do menu: \n \n");
			printf("\t 1. Registrar nomes\n");
			printf("\t 2. Consultar nomes\n");
			printf("\t 3. Deletar nomes\n");
			printf("\t 4. Sair do sistema\n\n");
			printf("Digite a op��o desejada: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls"); //limpa a tela
		
			switch(opcao)
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
						
				default:
				printf("Esta op��o n�o est� dispon�vel \n");
				system("pause");
				break;					
			} //fim da sele��o
	
    	}		
	}	
	
	else
		printf("Senha incorreta!\n");
		system("pause");
		system("cls");
		main();
       
	}
