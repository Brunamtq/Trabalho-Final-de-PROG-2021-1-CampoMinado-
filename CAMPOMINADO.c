#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void iniciante( void );
void avancado( void );
void dificuldade( void );
void intermediario( void );
void costumizar( void );
void printar_mina( void );
void boom( void );
void printar_mina_final( void );
void vencer( void );
void jogar_novamente( void );
void fim_de_jogo( void );
void gerador_de_minas( void );
void hipotese( void );

int x, y;
int M, N;
float dif;
int total_de_minas = 0;
int minas = 0;
int campominado[30][30];                                      
int campominado_vazio[30][30];                                
int campominado_final[30][30];

int main()
{
    printf("\t\tBEM VINDO AO CAMPO MINADO\n");
    dificuldade();
    return 0;
}

void dificuldade( void )                                     
{
    dif = 0;
    while( (dif != 1) && (dif != 2) && (dif != 3) && (dif != 4))
    {
        printf("\t\tEscolha o nível de dificuldade(1-3) ou 4 para customizar:");
        scanf("%f", &dif);
        fflush(stdin);

        if( (dif != 1) && (dif != 2) && (dif != 3) && (dif != 4))
        {
            printf("\t\tPor favor insira 1, 2, 3 ou 4   \n");
        }
    }

    if( dif == 1 )                                        
    {
        iniciante();
    }
    else if( dif == 2 )
    {
        intermediario();
    }
    else if( dif == 3 )
    {
        avancado();
    }
    else if( dif == 4)
    {
        costumizar();
    }
}

void iniciante( void )                                       
{
    M = 9;
    N = 9;
    total_de_minas = 10;
    gerador_de_minas();
    hipotese();
}

void intermediario( void )                                   
{
    M = 16;
    N = 16;
    total_de_minas = 40;
    gerador_de_minas();
    hipotese();
}

void avancado( void )                                         
{
    M = 16;
    N = 30;
    total_de_minas = 99;
    gerador_de_minas();
    hipotese();
}

void costumizar( void )
{
    M = 0;
    N = 0;
    total_de_minas = 0;
    printf("\t\tInsira as dimensões que você deseja para o jogo\n");
    printf("\t\tInsira a quantidade de colunas:\n");
    scanf("%d", &M);
    printf("\t\tInsira a quantidade de linhas:\n");
    scanf("%d", &N);
    printf("\t\tInsira o número de minas que você deseja\n");
    scanf("%d", &total_de_minas);
    gerador_de_minas();
    hipotese();
}

void gerador_de_minas( void )                            
{
    int i = 0, j = 0;

    srand( time( NULL ) );                                  

    while( j < N )                                          
    {
        while( i < M)
        {
            campominado[i][j] = '-';
            campominado_vazio[i][j] = campominado[i][j];
            campominado_final[i][j] = campominado[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    minas = 0;
    while( minas < total_de_minas )                            
    {
        i = rand()%(M);
        j = rand()%(N);
        if( campominado[i][j] != '*')                         
        {
            campominado[i][j] = '*';
            campominado_final[i][j] = campominado[i][j];
            minas++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          
    {
        while( i < M)
        {
            if( campominado[i][j] != '*')
            {
                campominado[i][j] = 0;
            }
            if((campominado[i-1][j-1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i-1][j] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i][j-1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i-1][j+1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i+1][j-1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i+1][j] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i][j+1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            if((campominado[i+1][j+1] == '*') && (campominado[i][j] != '*'))
            {
                campominado[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}

void printar_mina(void)                                  
{
    int i = 0, j = 0, z = 0;
    while( z < M )                                          
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( campominado_vazio[i][j] == '-')
            {
                printf("|%c|\t", campominado_vazio[i][j]);

            }
            else if( campominado[i][j] == 0 )                 
            {
                campominado_vazio[i][j] = 'B';
                printf("|%c|\t", campominado_vazio[i][j]);
            }
            else
            {
                printf("|%d|\t", campominado_vazio[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void hipotese( void )
{
    
    int q = 0, i=0, j=0, bloco_aberto=0;

    printar_mina();
       while( j < N )                                          
    {
        while( i < M )
        {
             switch(campominado_vazio[i][j])
         {
                case 'B' : bloco_aberto++; break;
                case 1 : bloco_aberto++; break;
                case 2 : bloco_aberto++; break;
                case 3 : bloco_aberto++; break;
                case 4 : bloco_aberto++; break;
                case 5 : bloco_aberto++; break;
                case 6 : bloco_aberto++; break;
                case 7 : bloco_aberto++; break;
                case 8 : bloco_aberto++; break;
                default: break;
            }
            i++;
        }/**/
        i = 0;
        j++;
    }
    if( bloco_aberto == (( M * N ) - total_de_minas))                
    {
        vencer();
    }



    printf("\nInsira o valor de x e y separados por espaço:");
    scanf("%d %d", &x, &y);                                 
    fflush(stdin);
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nInsira uma cordenada válida\n");
        hipotese();
    }
    if( campominado[x][y] == '*' )                            
    {
        boom();
    }
    if( campominado_vazio[x][y] != '-' )
    {
        printf("\nVocê já inseriu essa coordenada, tente navamente\n");
        hipotese();
    }

    else                                                
    {
        campominado_vazio[x][y] = campominado[x][y];
        if( campominado[x][y] == 0 )
        {
            if( campominado[x-1][y-1] == 0 )
            {
                campominado_vazio[x-1][y-1] = campominado[x-1][y];
            }
            if( campominado[x-1][y] == 0 )
            {
                campominado_vazio[x-1][y] = campominado[x-1][y];
            }
            if( campominado[x][y-1] == 0 )
            {
                campominado_vazio[x][y-1] = campominado[x][y-1];
            }
            if( campominado[x-1][y+1] == 0 )
            {
                campominado_vazio[x-1][y+1] = campominado[x-1][y+1];
            }
            if( campominado[x+1][y-1] == 0 )
            {
                campominado_vazio[x+1][y-1] = campominado[x+1][y-1];
            }
            if( campominado[x+1][y] == 0 )
            {
                campominado_vazio[x+1][y] = campominado[x+1][y];
            }
            if( campominado[x][y+1] == 0 )
            {
                campominado_vazio[x][y+1] = campominado[x][y+1];
            }
            if( campominado[x+1][y+1] == 0 )
            {
                campominado_vazio[x+1][y+1] = campominado[x+1][y+1];
            }
        }
        hipotese();
    }
}

void boom( void )                                       
{
    printar_mina_final();
    printf("\n\t\tVocê atingiu a mina em %d,%d\n\t\tVOCÊ PERDEU!!!!", x, y);
    jogar_novamente();
}

void printar_mina_final( void )                      
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", campominado_final[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void vencer( void )                                        
{
    printf("\n\n\n\t\t\tVOCÊ GANHOU!!!!!\n\n\n");
    jogar_novamente();
}

void jogar_novamente( void )                                 
{
    int alternativa;
    

    printf("\n\t\tGostaria de jogar navamente(1 = Sim /0 = Não)?:");
    scanf("%d", &alternativa);
    fflush(stdin);
        switch(alternativa) {
          //case 'S' :
          case 1 : dificuldade(); break;
          //case 'N' :
          case 0 : fim_de_jogo(); break;
             default : printf("Por favor insira 1 ou 0"); jogar_novamente();  
        }
    
   
}

void fim_de_jogo( void )                                  
{
    printf("\n\n\t\tO jogo acabou!");
    exit(1);
}
