#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocacao de espaco em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar novos usuários
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo (w significa write)
	fprintf(file, "CPF: "); // salva a escrita CPF: antes do valor do CPF em si
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo já existente
	fprintf(file, "\n"); //para dar um espaço entre o CPF e o Nome
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo já existente
	fprintf(file, "Nome: "); // salva a escrita Nome: antes do valor do nome em si
	fprintf(file, nome); // salva o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" para atualizar um arquivo já existente
	fprintf(file, "\n"); //para dar um espaço entre o Nome e o Sobrenome
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
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
		printf ("Cadastro náo localizado \n");
	}
	
	else
	printf("Informações do usuário:\n\n");
	
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // repetição dos comandos
	{
		
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //definição do idioma
		
		printf("### Cartório da EBAC ### \n \n"); //inicio do menu
		printf("Escolha a opção desejada do menu: \n \n");
		printf("\t 1. Registrar nomes\n");
		printf("\t 2. Consultar nomes\n");
		printf("\t 3. Deletar nomes\n");
		printf("\t 4. Sair do sistema\n\n");
		printf("Digite a opção desejada: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpa a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Esta opção não está disponível \n");
			system("pause");
			break;					
		} //fim da seleção
	
    }
        
}
