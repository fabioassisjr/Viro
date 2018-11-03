#include <stdio.h>

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

void valores (void)
{
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

}
