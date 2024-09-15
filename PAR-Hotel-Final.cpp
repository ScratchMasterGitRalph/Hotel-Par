//PAR-Hotel-05    30/06/2023
//Andre Garrido Macedo
//Pedro Evaristo de Oliveira
//Rafael de Mello Turaca
/*O projeto consiste no desenvolvimento de um programa 
em C++ para controlar a reserva de um hotel com 280 
quartos. O programa permitira a visualisacao da ocupacao 
dos apartamentos, fazer reservas, realizar check-ins e 
check-outs, e outras informacoes.*/

#include<stdio.h>
#include<iostream>

typedef struct apto //cria a estrutrura do apto
{
	char cpf[14];
	char nome[40];
	char tel[15];
	char email[40];
	char ender[40];
	char munic[40];
	char UF[3];
	char sit;
	
}tipoApto;

void fhotel(tipoApto hotel[20][14]);
void freserva(int a , int q , tipoApto hotel[][14]);
void fcheckinres(int a , int q, tipoApto hotel[][14]);
void fcheckinvazio(int a , int q, tipoApto hotel[][14]);
void fcheckout(int a , int q, tipoApto hotel[][14]);
void fcancelares(int a , int q, tipoApto hotel[][14]);
void fcadastro(int a , int q, tipoApto hotel [][14]);
void flotacao(int a , int q, tipoApto hotel[][14]);
void finfo(int a , int q, tipoApto hotel[][14]);
void fclear();

main()
{
	
	int i , j , a , q, opc; 
	tipoApto hotel[20][14];
	int n = 1;

	for(i=0; i < 20; i++)       //cria a matriz do hotel
		for(j=0 ; j < 14; j++)
		{
			hotel[i][j].sit = '.' ;
		}
	do
	{	
	printf("\n\n\nHOTEL PAR\n");
	printf("==========================================");
	printf("\n1- Mostrar o mapa do hotel");
	printf("\n2- Reservar um quarto");
	printf("\n3- Fazer o check-in em um quarto reservado");
	printf("\n4- Fazer o check-in em um quarto vazio");
	printf("\n5- Fazer o check-out");
	printf("\n6- Cancelar uma reserva");
	printf("\n7- Mostrar ocupacao do hotel");
	printf("\n8- Mostrar a situacao de um quarto");
	printf("\nDigite o que voce deseja fazer(0 para sair):");
	scanf("%d", &opc);
	
	switch(opc) //cria um menu de opcoes
	{
	case 0:
		{
			break;
		}
	case 1:
		{
			fhotel(hotel);
			continue;
		}
	case 2:
		{
			fhotel(hotel);
			freserva(a , q , hotel);
			continue;
		}
	case 3:
		{
			fhotel(hotel);
			fcheckinres(a , q , hotel);
			continue;
		}
	case 4:
		{
			fhotel(hotel);
			fcheckinvazio(a , q , hotel);
			continue;
			
		}
	case 5: 
		{
			fhotel(hotel);
			fcheckout(a , q , hotel);
			continue;
		}
	case 6:
		{
			fhotel(hotel);
			fcancelares(a , q , hotel);
			continue;
		}
	case 7:
		{
			fhotel(hotel);
			flotacao(a , q , hotel);
			continue; 
		}
	case 8:
		{
			fhotel(hotel);
			finfo(a , q , hotel);
			continue;
		}
	default:
		{
			printf("\nOpcao inexistente\n\n");
			continue;
		}
	}
	
	}while(opc != 0);
}


void fhotel(tipoApto hotel[20][14]) //mostra o mapa do hotel
{
	int i , j;
	system("cls");
	printf("\n");
	printf("Quartos ->\t ");
	for(j = 0; j < 14; j++)
		printf("%2d  ", j + 1);
	printf("\n\n");
	
	for(i = 19; i >= 0 ; i--)
	{
	printf("Andar %2d \t", i + 1 );
	for(j = 0; j < 14 ; j++)
		printf("%3c ", hotel[i][j].sit);
	printf("\n");
	}	
}


void freserva(int a , int q, tipoApto hotel[][14])//funcao de reserva de quarto
{
	printf("\nReserva de um quarto\n");
	printf("=====================");
	do
	{
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'O')
		{
		printf("O quarto esta ocupado\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'R')
		{
		printf("Esse quarto ja esta reservado\n");	
		continue;	
		}
	else
		{
		hotel[a-1][q-1].sit = 'R';
		fhotel(hotel);
		printf("\nQuarto %d do andar %d reservado!\n", q , a);
		}
	
	
	
	}while(a != 0);
}


void fcheckinres(int a , int q, tipoApto hotel[][14])//funcao de check-in de um quarto ja previamente reservado
{
	printf("\nCheck-In em um quarto reservado\n");
	printf("================================");
	do
	{	
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == '.')
		{
		printf("Esse quarto nao foi reservado\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'O')
		{
		printf("Esse quarto ja esta ocupado\n");	
		continue;	
		}
	else
		{
		fcadastro(a, q, hotel);
		hotel[a-1][q-1].sit = 'O';
		fhotel(hotel);	
		printf("\nCheck-in realizado no quarto %d do andar %d!\n", q , a);
		}
	
	
	
	}while(a != 0);
}


void fcheckinvazio(int a , int q, tipoApto hotel[][14])//fazer o check in em um quarto que nao foi reservado
{
	printf("\nCheck-In em um quarto vazio\n");
	printf("==============================");
	do
	{	
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'R')
		{
		printf("Esse quarto ja esta reservado\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'O')
		{
		printf("Esse quarto ja esta ocupado\n");	
		continue;	
		}
	else
		{
		fcadastro(a, q, hotel);
		hotel[a-1][q-1].sit = 'O';
		fhotel(hotel);	
		printf("\nCheck-in realizado no quarto %d do andar %d!\n", q , a);
		}
	}while(a != 0);
}


void fcheckout(int a , int q, tipoApto hotel[][14])//fazer o check-out do quarto ocupado
{
	printf("\nCheck-Out\n");
	printf("=======================");
	do
	{	
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'R')
		{
		printf("Esse quarto esta reservado\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == '.')
		{
		printf("Esse quarto esta vazio\n");	
		continue;	
		}
	else
		{
		hotel[a-1][q-1].sit = '.';
		fhotel(hotel);	
		printf("\nCheck-out realizado no quarto %d do andar %d!\n", q , a);
		}
	}while(a != 0);
}


void fcancelares(int a , int q, tipoApto hotel[][14]) // funcao de cancelamento de reserva
{
	printf("\nCancelamento de reserva\n");
	printf("=======================");
	do
	{	
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'O')
		{
		printf("Esse quarto esta ocupado\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == '.')
		{
		printf("Esse quarto esta vazio\n");	
		continue;	
		}
	else
		{
		hotel[a-1][q-1].sit = '.';
		fhotel(hotel);	
		printf("\nReserva cancelada no quarto %d do andar %d!\n", q , a);
		}
	}while(a != 0);
}


void flotacao(int a , int q, tipoApto hotel[][14]) //funcao de calculo de lotacao
{
	int res, ocup, vazio , i , j , total;
	float porcentres , porcentocup , porcentvazio;
	res = 0;
	ocup = 0;
	
	for(i = 0; i < 20 ; i++)
		for(j = 0; j < 14; j++)
			if(hotel[i][j].sit == 'R')
				res++;
			else if(hotel[i][j].sit == 'O')
				ocup++;
	
	total = 20 * 14 ;
	vazio = total - res - ocup ;
	porcentres = (res * 100.0/ total) ;
	porcentocup = (ocup * 100.0/ total) ;
	porcentvazio = 100.0 - (porcentocup + porcentres);
	

	printf("\nExistem %d quartos reservados(%.3f%%), %d quartos ocupados(%.3f%%) e %d quartos vazios(%.3f%%).", res , porcentres , ocup , porcentocup , vazio , porcentvazio );
}


void fcadastro(int a , int q, tipoApto hotel[][14]) //funcao para cadastrar o usuario
{
	fclear();
	printf("Cadastramento\n");
	printf("===============\n");
	printf("\nQuarto %d do andar %d\n", q , a);
	printf("Nome Completo: ");
	gets(hotel[a-1][q-1].nome);	
	printf("\nCPF: ");
	gets(hotel[a-1][q-1].cpf);
	printf("\nTelefone: ");
	gets(hotel[a-1][q-1].tel);
	printf("\nEmail: ");
	gets(hotel[a-1][q-1].email);
	printf("\nEndereco: \n\n");
	printf("  Estado: ");
	gets(hotel[a-1][q-1].UF);
	printf("\n  Cidade: ");
	gets(hotel[a-1][q-1].munic);
}

void finfo(int a , int q, tipoApto hotel[][14])//funcao para mostrar a situacao de um apto
{
	do
	{
	printf("\nAndar: (0 para sair): ");
	scanf("%d", &a);
	
	if(a == 0)
		break;
	
	if(a < 0||a > 20)
		{
		printf("Andar inexistente\n");
		continue;
		}
	
	
	printf("\nQuarto: ");
	scanf("%d", &q);
	
	if(q > 14 || q < 0)
		{
		printf("Quarto inexistente\n");
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'O')
		{
		puts("Informacoes cadastradas:");
		printf("Quarto: %d\n", q);
		printf("Andar: %d\n", a);
		printf("Nome Completo: %s\n", hotel[a-1][q-1].nome);
		printf("CPF: %s\n", hotel[a-1][q-1].cpf);
		printf("Telefone: %s\n", hotel[a-1][q-1].tel);
		printf("Email: %s\n", hotel[a-1][q-1].email);
		printf("Estado: %s\n", hotel[a-1][q-1].UF);
		printf("Cidade: %s\n", hotel[a-1][q-1].munic);
		continue;
		}
	else if(hotel[a-1][q-1].sit == 'R')
		{
		printf("Esse quarto esta reservado.\n");	
		continue;	
		}
	else if(hotel[a-1][q-1].sit == '.')
		{
		printf("Esse quarto esta vazio.\n");
		continue;	
		}
	
	
	}while(a != 0);
}

void fclear() 
{	
	char carac; 
	while((carac = fgetc(stdin)) != EOF && carac != '\n') {}
}

