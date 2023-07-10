#include <cstdlib>
#include <iostream>
#include <string.h>
#include "libreria.h"

using namespace std;

/*struct ficha
{
string tipo;
char color;
int numero;
string representacion;
};

struct coordenadas
{
    int f;
    int c;
    int f_f;
    int c_f;
};
*/
int main(int argc, char *argv[])
{

 	ficha **ajedrez=new ficha *[8];
    char movimiento[5];
    int conta=0;
	for(int i=0;i<8;i++)
    {
        *(ajedrez+i)=new ficha [8];
    }
    inicializacion(ajedrez);
    int forza;
    cout<< "Para jugar digite un numero diferente de cero"<<endl;
    cin>>forza;
    while (forza=!0)
        {
            menu(ajedrez,conta);
            imprimir(ajedrez);
            cout<< "Digite un numero diferente de cero para seguir jugando";
            cin>>forza;
        }
    inicializacion(ajedrez);
	imprimir (ajedrez);

	for(int i=0;i<8;i++)
        delete []*(ajedrez+i);
	delete[] ajedrez;
	ajedrez=NULL;
}
