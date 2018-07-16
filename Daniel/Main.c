#include <stdlib.h>
#include  <stdio.h>
#include   <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Randomize__(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

int main() 
{
	char* Instructions__ = "Instrucciones:\nSe generaran 3 valores, cada uno correspondiente a un color en especifico, inserta un valor, a continuacion deberas introducir la posicion en el que se encuentra el valor, si ganas te espera una sorpresa en el directorio desde el cual ejecutaste el juego.\nLos valores posibles son:\n(A)zul\n(V)erde\n(R)ojo\n(N)egro\n(B)lanco\nGood Luck!\n";
	char* Message_1__ = "Ingresa la inicial de un color: ";
	char* Message_2__ = "Ingresa la posicion del color: ";

    int Game_State__;
    int Lifes__;
    char Colors__[4] = {'B','N','R','V','A'};

    do
    {
    	char Random_Colors__[2];
        
        int Array__[5] = {0, 1, 2, 3, 4};
        int Array_Size__ = sizeof(Array__)/ sizeof(Array__[0]);
        
        int Win_Flag__ = 0;
        
        char Input_1__;
        int Input_2__;
        
        char Play_Again_Flag__;
        
        Game_State__ = 0;
        Lifes__ = 2;

        printf(Instructions__);
        Randomize__(Array__, Array_Size__);
        for(int i = 0; i <= ((sizeof(Random_Colors__))/(sizeof(Random_Colors__[0]))); i++)
        {
        	int Index_ = Array__[i];
        	Random_Colors__[i] = Colors__[Index_];
        }

        do
        {	    
            printf(Message_1__);
            scanf(" %c", &Input_1__);
            fflush(stdin);
            printf(Message_2__);
            scanf(" %d", &Input_2__);
            fflush(stdin);

            for(int i = 0; i <= ((sizeof(Random_Colors__))/(sizeof(Random_Colors__[0]))); i++)
            {
            	if((Random_Colors__[i] == Input_1__) && (Win_Flag__ != 0))
            	{
            		if(Random_Colors__[Input_2__] == Input_2__)
            		{
            			Win_Flag__ = 2;
                        printf("Acertaste un color junto con su posicion.\n");
                    } else {
                        printf("Acertaste un color, pero no su posicion.\n");
                        Win_Flag__ = 1;
                    }
                }
            }

            
            if(Win_Flag__ == 0)
            {
                Lifes__ = Lifes__ - 1;
                printf("Has perdido una vida.\n");
            } 
        } while(Lifes__);
        for(int i = 0; i <= ((sizeof(Random_Colors__))/(sizeof(Random_Colors__[0]))); i++)
        {
            printf("Los resultados eran: %d - %c\n", i, Random_Colors__[i]);
        }
        printf("Quieres continuar jugando? (y/n): ");
        scanf(" %c", &Play_Again_Flag__);
        if(Play_Again_Flag__ == 'y')
        {
            Game_State__ = 1;
        } else if(Play_Again_Flag__ == 'n') {
            Game_State__ = 0;
        }
    } while(Game_State__);
    return 0;
}
