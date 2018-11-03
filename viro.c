#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
//Programa para automatizar os cálculos para as PCRs
//Passos futuros: incluir protocolos de diversos virus

//Estruturas a serem usadas
struct reagentes25
{
	float buffer;
	float sal;
	float nucleotideos;
	float polimerase;
	float rna1;
	float rna2;
	float agua;
};
struct reagentes25 CHIKV25 , MAYV25 , ZIKA25 , OROV25 , EEV25 , DEN125 , DEN225 , DEN425 , ILHV25;

struct reagentes50
{
	float buffer;
	float sal;
	float nucleotideos;
	float polimerase;
	float rna1;
	float rna2;
	float agua;
};
struct reagentes50 CHIKV50 , MAYV50 , ZIKAV50 , OROV50, EEV50 , DEN150 , DEN250 , DEN450 , ILHV50;


struct reagentes100
{
	float buffer;
	float sal;
	float nucleotideos;
	float polimerase;
	float rna1;
	float rna2;
	float agua;
};
struct reagentes100 CHIKV100 , MAYV100 , ZIKAV100 , OROV100, EEV100 , DEN1100 , DEN2100 , DEN4100 , ILHV100;

//Funções a serem usadas
short int op_invalida (short int errado , short int limtinf , short int limtsup)
{
  do {
  printf("\nOpção inválida! Por favor, escolha apenas uma das opções indicadas.\n");
  scanf("%hd", &errado);
  getchar();
} while(errado < limtinf || errado > limtsup);
return errado;
}

char char_invalida (char errado)
{
  do {
    printf("\nOpção inválida! Por favor, escolha apenas uma das opções indicadas.\n");
    scanf("%c", &errado);
    getchar();
  } while(errado != 's' && errado != 'n');
	return errado;
}

short int amostras_invalida (short int errado)
{
  do {
    printf("Valor inválido! Por favor, digite um número maior que 0\n");
    scanf("%hd", &errado);
  } while(errado <= 0);
  return errado;
}

void nova_reacao (void)
{
  char newsample = ' ';
  //Dá ao usuário a possibilidade de fazer uma nova reação
  printf("\nGostaria de fazer outra reação?");
  printf("\nDigite s para sim e n para não\n");
  scanf("%c", &newsample);
  getchar();
  //Checa por uma opção válida. Caso o usuário tecle 's', o loop
  //reinicia sozinho, sem a necessidade de outro if
  if (newsample != 's' && newsample != 'n')
  {
    newsample = char_invalida(newsample);
  }
  //Sai do programa
  if (newsample == 'n')
    exit(0);
}

int main ()
{
//setlocale(LC_ALL, "Portuguese");
//Declara os valores dos reagentes para CHIKV25
CHIKV25.buffer = 2.5;
CHIKV25.sal = 1.0;
CHIKV25.nucleotideos = 0.5;
CHIKV25.polimerase = 0.1;
CHIKV25.rna1 = 0.5;
CHIKV25.rna2 = 0.5;
CHIKV25.agua = 15.4;
//Declara os valores dos reagentes para CHIKV50
CHIKV50.buffer = 5.0;
CHIKV50.sal = 2.0;
CHIKV50.nucleotideos = 1.0;
CHIKV50.polimerase = 0.2;
CHIKV50.rna1 = 1.0;
CHIKV50.rna2 = 1.0;
CHIKV50.agua = 33.8;
//Declara os valores dos reagentes para CHIKV100
CHIKV100.buffer = 10.0;
CHIKV100.sal = 4.0;
CHIKV100.nucleotideos = 2.0;
CHIKV100.polimerase = 0.4;
CHIKV100.rna1 = 2.0;
CHIKV100.rna2 = 2.0;
CHIKV100.agua = 73.6;
//------------------------------------------------------------------------------
// Declara os valores dos reagentes para MAYV50
MAYV50.buffer = 5.0;
MAYV50.sal = 2.0;
MAYV50.nucleotideos = 1.0;
MAYV50.polimerase = 0.2;
MAYV50.rna1 = 1.0;
MAYV50.rna2 = 1.0;
MAYV50.agua = 35.8;
//------------------------------------------------------------------------------
// Declara os valores dos reagentes para ZIKAV50
ZIKAV50.buffer = 5.0;
ZIKAV50. sal = 2.0;
ZIKAV50.nucleotideos = 1.0;
ZIKAV50.polimerase = 0.2;
ZIKAV50.rna1 = 1.0;
ZIKAV50.rna2 = 1.0;
ZIKAV50.agua = 35.8;
//------------------------------------------------------------------------------
// Declara os valores dos reagentes para OROV50
OROV50.buffer = 5.0;
OROV50.sal = 2.0;
OROV50.nucleotideos = 1.0;
OROV50.polimerase = 0.2;
OROV50.rna1 = 1.0;
OROV50.rna2 = 1.0;
OROV50.agua = 33.8;
//------------------------------------------------------------------------------
short int virus = 0;
short int option = 0;
short int amostras = 0;
while(1)
	{
	//Pergunta para o usuário, o tipo de vírus que ele usará
		printf("Digite o número correspondente ao vírus a ser testado:\n");
    printf("1-CHIKV\t2-MAYV\n3-ZIKAV\t4-OROV\n5-EEV\t6-DEN1\n7-DEN2\t8-DEN4\n9-ILHV\t");
    printf("0-Encerra o programa\n");
    scanf("%hd", &virus);
    getchar();
	//Testa por um valor válido
    if (virus < 0 || virus > 9)
    {
			virus = op_invalida(virus, 0 , 9);
    }
	//Encerra o programa
		if (virus == 0)
			break;
//Pergunta o tipo de reação que será feito com o vírus selecionado previamente
    printf("Digite o número correspondente ao tipo de reação que você quer fazer\n\n");
		printf("1-25\t2-50\n3-100\t");
		printf("0-Encerra o programa\n");
		scanf("%hd", &option);
    getchar();
//Testa se a opção escolhida está entre os opções dadas
		if (option < 0 || option > 3)
		{
			option = op_invalida(option, 0, 3);
		}
//Encerra o programa
		if (option == 0)
			break;
		//Número de amostras é importante para o cálculo de reagentes
		printf("Quantas amostras?\n");
		scanf("%hd", &amostras);
		getchar();
		//Testa por um número válido de amostras
		if (amostras <= 0)
			{
				amostras = amostras_invalida(amostras);
			}
//----------------------------------------------------------------------------------------
//Caso em que o usuário seleciona CHIKV
    if (virus == 1)
      {
				//Reação 25 para CHIKV
    		if (option == 1)
    			{
						printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
						printf("Buffer 10x\t\t%.2f\n", CHIKV25.buffer*amostras);
						printf("MgCl2 50mm\t\t%.2f\n", CHIKV25.sal*amostras);
						printf("dNTP 10mm\t\t%.2f\n", CHIKV25.nucleotideos*amostras);
						printf("TAQ DNA pol\t\t%.2f\n", CHIKV25.polimerase*amostras);
						printf("CHIKV env F 20pmol\t%.2f\n", CHIKV25.rna1*amostras);
						printf("CHIKV env R 20pmol\t%.2f\n", CHIKV25.rna2*amostras);
						printf("H2O\t\t\t%.2f\n", CHIKV25.agua*amostras);
						nova_reacao();
    			}
				//Reação 50 para CHIKV
    		if (option == 2)
    			{
    				    printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
    				    printf("Buffer 10x\t\t%.2f\n", CHIKV50.buffer*amostras);
    				    printf("MgCl2 50mm\t\t%.2f\n", CHIKV50.sal*amostras);
    				    printf("dNTP 10mm\t\t%.2f\n", CHIKV50.nucleotideos*amostras);
    				    printf("TAQ DNA pol\t\t%.2f\n", CHIKV50.polimerase*amostras);
    			      printf("CHIKV env F 20pmol\t%.2f\n", CHIKV50.rna1*amostras);
    				    printf("CHIKV env R 20pmol\t%.2f\n", CHIKV50.rna2*amostras);
                printf("H2O\t\t\t%.2f\n", CHIKV50.agua*amostras);
								nova_reacao();
    			}
				//Reação 100 para CHIKV
				if (option == 3)
    			{
						printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
						printf("Buffer 10x\t\t%.2f\n", CHIKV100.buffer*amostras);
						printf("MgCl2 50mm\t\t%.2f\n", CHIKV100.sal*amostras);
						printf("dNTP 10mm\t\t%.2f\n", CHIKV100.nucleotideos*amostras);
						printf("TAQ DNA pol\t\t%.2f\n", CHIKV100.polimerase*amostras);
						printf("CHIKV env F 20pmol\t%.2f\n", CHIKV100.rna1*amostras);
						printf("CHIKV env R 20pmol\t%.2f\n", CHIKV100.rna2*amostras);
						printf("H2O\t\t\t%.2f\n", CHIKV100.agua*amostras);
						nova_reacao();
    			}
      }
//-----------------------------------------------------------------------------------
			//Caso em que o usuário escolhe MAYV
      if(virus == 2)
        {
					//Reação 25 para MAYV
					if (option == 1)
	    			{

	    			}
					//Reação 50 para MAYV
	    		if (option == 2)
	    			{
	    				    printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
	    				    printf("Buffer 10x\t\t%.2f\n", MAYV50.buffer*amostras);
	    				    printf("MgCl2 50mm\t\t%.2f\n", MAYV50.sal*amostras);
	    				    printf("dNTP 10mm\t\t%.2f\n", MAYV50.nucleotideos*amostras);
	    				    printf("Platinum 5unid/ul\t%.2f\n", MAYV50.polimerase*amostras);
	    			      printf("CM3W 100pmol\t\t%.2f\n", MAYV50.rna1*amostras);
	    				    printf("MAYV 30pmol\t\t%.2f\n", MAYV50.rna2*amostras);
	                printf("H2O\t\t\t%.2f\n", MAYV50.agua*amostras);
									nova_reacao();
	    			}
					//Reação 100 para MAYV
	    		if (option == 3)
	    			{

	    			}
        }
//------------------------------------------------------------------------------------------
			//Caso o usuário escolha ZIKAV
			if (virus == 3)
        {
					//Reaçãp de 25 para ZIKAV
					if (option == 1)
	    			{

	    			}
					//Reação de 50 para ZIKAV
	    		if (option == 2)
	    			{
	    				    printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
	    				    printf("Buffer 10x\t%.2f\n", ZIKAV50.buffer*amostras);
	    				    printf("MgCl2 50mm\t%.2f\n", ZIKAV50.sal*amostras);
	    				    printf("dNTP 10mm\t%.2f\n", ZIKAV50.nucleotideos*amostras);
	    				    printf("TAQ DNA pol\t%.2f\n", ZIKAV50.polimerase*amostras);
	    			      printf("ZIKA F 30pmol\t%.2f\n", ZIKAV50.rna1*amostras);
	    				    printf("ZIKA R 30pmol\t%.2f\n", ZIKAV50.rna2*amostras);
	                printf("H2O\t\t%.2f\n", ZIKAV50.agua*amostras);
									nova_reacao();
	    			}
					//Reação de 100 para ZIKAV
					if (option == 3)
	    			{

	    			}
        }
//-------------------------------------------------------------------------------------
			//Caso o usuário escolha OROV
			if(virus == 4)
        {
					//Reação 25 para OROV
					if (option == 1)
	    			{

	    			}
					//Reação 50 para OROV
	    		if (option == 2)
	    			{
	    				    printf("\nVocê deve usar as seguintes quantidades de reagentes:\n");
	    				    printf("Buffer 10x\t\t%.2f\n", OROV50.buffer*amostras);
	    				    printf("MgCl2 50mm\t\t%.2f\n", OROV50.sal*amostras);
	    				    printf("dNTP 10mm\t\t%.2f\n", OROV50.nucleotideos*amostras);
	    				    printf("TAQ DNA pol\t\t%.2f\n", OROV50.polimerase*amostras);
	    			      printf("BS IS\t%.2f\n", OROV50.rna1*amostras);
	    				    printf("BS IC\t%.2f\n", OROV50.rna2*amostras);
	                printf("H2O\t\t\t%.2f\n", OROV50.agua*amostras);
									nova_reacao();
	    			}
					//Reação 100 para OROV
					if (option == 3)
	    			{

	    			}
        }
	}
		//Encerra o programa
		return 0;
}
