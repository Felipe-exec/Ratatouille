#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#define MAX 15


void cria(char l[MAX][MAX]){
    int i,j,x,y;
    srand(time(NULL));
    for(i=0;i<MAX;i++)
    {
        for (j = 0; j < MAX; j++) 
        {
            if ((rand() % 5) == 1)
            {
                l[i][j] = '|';
            }
            else
            {
                l[i][j] = '.';
            }
        }
    }
    for(i=0;i<MAX;i++)
    {
        l[0][i]='*';
        l[MAX-1][i]='*';
        l[i][0]='*';
        l[i][MAX-1]='*';
    }

    x=  rand() % MAX;
    y=  rand() % MAX;
    l[x][y]='Q';
}
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int col){
    int i,j;
    for ( i = 0; i < linha; i++)
    {
        printf("\n");
        for ( j = 0; j < col; j++)
        {
            printf(" %c ", mat[i][j]);
        }
    }
}
     
 int funcaoRatatouille(char lab[MAX][MAX],int i, int j)
 {
     tpilha linha, coluna;

     inicializa(& linha);
     inicializa(&coluna);

     while (lab[i][j] != 'Q')
     {
         lab[i][j] = 'R';

         if (lab[i][j + 1] == '.' || lab[i][j + 1] == 'Q')  //direita
         {
             push(&linha, i);
             push(&coluna, j);
             j++;
         }
         else if (lab[i + 1][j] == '.' || lab[i + 1][j] == 'Q')  //baixo
         {
             push(&linha, i);
             push(&coluna, j);
             i++;
         }
         else if (lab[i][j - 1] == '.' || lab[i][j - 1] == 'Q') //esquerda
         {
             push(&linha, i);
             push(&coluna, j);
             j--;
         }
         else if (lab[i - 1][j] == '.' || lab[i - 1][j] == 'Q') //cima
         {
             push(&linha, i);
             push(&coluna, j);
             i--;
         }
         else
         {
             if (!isEmpty(linha) && !isEmpty(coluna))
             {
                 lab[i][j] = 'X';
                 i = pop(&linha);
                 j = pop(&coluna);
             }
             else
             {
                 printf("\nQueijo não encontrado!\n");
                 return;
             }
         }

         Sleep(300);
         system("cls");
         mostraLabirinto(lab, MAX, MAX);
     }

     printf("\nO queijo foi encontrado pelo ratatouille na posição: (%i, %i)\n", i, j);
 }



int main()
{
    setlocale(LC_ALL, "Portuguese");
    char labirinto[MAX][MAX];
    int x,y;
    cria(labirinto);
    mostraLabirinto(labirinto,MAX,MAX);
    printf("\nO ratatouille irá nascer em qual linha? ");
    scanf_s("%i",&x);
    printf("\nE em qual coluna? ");
    scanf_s("%i", &y);
    funcaoRatatouille(labirinto, x, y);
    getch();
}
