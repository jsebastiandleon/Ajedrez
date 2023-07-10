
#include <iostream>
#include <string.h>
using namespace std;
struct ficha
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
// DECLARACIONES DE FUNCIONES

coordenadas decodificar (char movimiento[]);
void imprimir(ficha **ajedrez);
void inicializacion(ficha **ajedrez);
bool peon(ficha **ajedrez, char movimiento[],int conta);
void mover(ficha **ajedrez,char movimiento[]);
bool torre(ficha **ajedrez,char movimiento[]);
bool rey(ficha **ajedrez, char movimiento[]);
bool caballo(ficha **ajedrez,char movimiento[]);
bool alfil(ficha **ajedrez,char movimiento[]);
bool reina(ficha **ajedrez,char movimiento[]);
bool jugada(ficha **ajedrez,char movimiento[],int conta);
void menu(ficha **ajedrez, int conta);


bool rey(ficha **ajedrez, char movimiento[])
{
	int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;
    bool aux=true;
    coordenadas retorno=decodificar(movimiento);
    *fila=retorno.f;
    *columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

	if(ajedrez[*fila_f][*columna_f].color != ajedrez[*fila][*columna].color || ajedrez[*fila_f][*columna_f].representacion== "  ")
 	{
	   if(*fila_f == *(fila)+1  || *fila_f==*(fila)-1 && *columna_f==*columna)
        return true;

       if(*columna_f == *(columna)+1 || *columna_f==*(columna)-1 && *fila==*fila_f)
        return true;

       if(*fila < *fila_f)
       {
        if( *columna_f == *columna+1 || *columna == *columna-1)
            return true;
   	   }
       if(*fila > *fila_f)
       	{
		 	if( *columna_f == *columna+1 || *columna_f== *columna-1)
            return true;
	 	}
	   else
	   		return false;
   }
   else
   	    return false;

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;

}
bool caballo(ficha **ajedrez,char movimiento[])
{
    int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;

	coordenadas retorno=decodificar(movimiento);

	*fila=retorno.f;
    *columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

    if(ajedrez[*fila_f][*columna_f].color != ajedrez[*fila][*columna].color || ajedrez[*fila_f][*columna_f].representacion== "  ")
 	{
       if((abs(*fila_f-*fila)==2 && abs(*columna_f-*columna)==1 || abs(*fila_f-*fila)==1 && abs(*columna_f-*columna)==2) && *columna_f>=0 && *fila_f>=0 && *columna_f<=7 && *fila_f<=7)
        {
           return true;
        }
       else
           return false;
 	}
 	else
	 {

        return false;
     }

	delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
}

bool alfil(ficha **ajedrez,char movimiento[])
{
    int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;
    bool aux;
    coordenadas retorno= decodificar(movimiento);

	*fila=retorno.f;
	*columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

    if(ajedrez[*fila_f][*columna_f].color != ajedrez[*fila][*columna].color || ajedrez[*fila_f][*columna_f].representacion== "  ")
 	{

        if((*fila_f+*columna_f==*fila+*columna || *fila_f - *fila==*columna_f-*columna) && *columna_f>=0 && *fila_f>=0 && *columna_f<=7 && *fila_f<=7 && *fila_f!=*fila && *columna_f!=*columna)
            {
                if(*columna_f>*columna && *fila_f>*fila)
                    {
                        *fila=*fila+1;
                        *columna=*columna+1;
                        while(*columna!= *columna_f)
					       {
						   	  if(ajedrez[*fila][*columna].representacion == "  "){
								 aux=true;}
							  else
							  	  {
					   		  	     aux=false;
					   		  	     break;
								  }
							*columna=*columna+1;
                            *fila=*fila+1;
					       }
       				return aux;
					}

					if(*columna_f>*columna && *fila_f<*fila)
                    {
						*fila=*fila-1;
                        *columna=*columna+1;

                        while(*columna!= *columna_f && *fila != *fila_f)
					       {
						   	  if(ajedrez[*fila][*columna].representacion == "  ")
								 aux=true;
							  else
							  	  {
					   		  	     aux=false;
					   		  	     break;
								  }
							*columna=*columna+1;
                            *fila=*fila-1;
					       }
       				return aux;
					}

					if(*columna_f<*columna && *fila_f<*fila)
                    {
                        *fila=*fila-1;
                        *columna=*columna-1;
                        while(*columna!= *columna_f)
					       {
						   	  if(ajedrez[*fila][*columna].representacion == "  "){
								 aux=true;}
							  else
							  	  {
					   		  	     aux=false;
					   		  	     break;
								  }
							*columna=*columna-1;
                            *fila=*fila-1;
					       }
       				return aux;
					}

					if(*columna_f<*columna && *fila_f>*fila)
                    {
                        *fila=*fila+1;
                        *columna=*columna-1;
                        while(*columna!= *columna_f)
					       {
						   	  if(ajedrez[*fila][*columna].representacion == "  "){
								 aux=true;}
							  else
							  	  {
					   		  	     aux=false;
					   		  	     break;
								  }
							*columna=*columna-1;
                            *fila=*fila+1;
					       }
       				return aux;
					}
                    else
                        return false;
            }

        }
        else
            {
                return false;
            }

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
}

bool reina(ficha **ajedrez,char movimiento[])
{
	if (torre(ajedrez,movimiento)==true || alfil(ajedrez,movimiento)==true ||rey(ajedrez,movimiento)==true || peon(ajedrez,movimiento,3)==true)
		return true;
	else
		return false;
}

bool jugada(ficha **ajedrez,char movimiento[],int conta)
{
    int *fila=new int;
    int *columna=new int;
    int *columna_f= new int;
    int *fila_f=new int;
    bool respuesta=false;
    char algo;
    coordenadas retorno= decodificar(movimiento);

    *fila=retorno.f;
    *columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

    if( ajedrez[*fila][*columna].tipo == "peon")
    {
        respuesta= peon(ajedrez,movimiento,conta);
    }
    if(ajedrez[*fila][*columna].tipo=="torre")
    {
        respuesta=torre(ajedrez,movimiento);
    }
    if(ajedrez[*fila][*columna].tipo=="caballo")
    {
        respuesta=caballo(ajedrez,movimiento);
    }
    if(ajedrez[*fila][*columna].tipo=="alfil")
    {
        respuesta=alfil(ajedrez,movimiento);
    }
    if(ajedrez[*fila][*columna].tipo=="rey")
    {
        respuesta=rey(ajedrez,movimiento);
    }
    if(ajedrez[*fila][*columna].tipo=="reina")
    {
        respuesta=reina(ajedrez,movimiento);
    }

    return respuesta;

    delete columna;
    columna=NULL;
    delete fila;
    fila=NULL;
}

void menu(ficha **ajedrez, int conta)
{
    int op;
    char movimiento[5];
    cout<< "Opcion 1: Mover ficha"<<endl;
    cout<< "Opcion 2: Ver progreso del tablero"<<endl;
    cout<< "Digite su opcion";
    cin>>op;

    switch(op)
    {
    case 1:
            imprimir(ajedrez);
            cout<< "Digite su jugada"<<endl;
            cin>>movimiento;
            if(jugada(ajedrez,movimiento,conta)== true)
                {
                    mover(ajedrez,movimiento);
                }
            else
                    cout<< "perdio el turno la jugada no es posible"<<endl;
        break;
    case 2:
            //imprimir la evolucion del tablero;
            cout<< "Digite su jugada"<<endl;
            cin>>movimiento;
        break;

    default:
            cout<<"su opcion es incorrecta";
        break;
    }
}
bool torre(ficha **ajedrez,char movimiento[])
{
    int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;
    bool aux=true;
    coordenadas retorno=decodificar(movimiento);
	*fila=retorno.f;
    *columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

    if (ajedrez[*fila_f][*columna_f].representacion== "  " || ajedrez[*fila][*columna].color != ajedrez[*fila_f][*columna_f].color)
	{
 	   if(*fila != *fila_f && *columna==*columna_f)
  		 {
	        if(*fila_f>*fila)//+++++++
 	         {
			       *fila=*fila+1;

 				    while(*fila != *fila_f)
				     {
   				 	    if (ajedrez[*fila][*columna].representacion == "  ")
   				 	       aux = true;

			   			else
						   {
						   	   aux = false;
		   	   			   	   break;
						   }
					  *fila=*fila+1;
					 }

			  return aux;
		     }
		     else if (*fila>*fila_f) //+++++
 			 	  	 {
  				 	  	*fila=*fila-1;
 					    while(*fila!=*fila_f)
					 	{
   				 	        if (ajedrez[*fila][*columna].representacion == "  ")
   				 	       	   aux = true;
			   				else
					   			{
			   	 	  			   aux = false;
								   break;
							    }
						*fila=*fila-1;
						}
					   return aux;
				      }
       }
 	   else if(*fila == *fila_f && *columna!=*columna_f)
 	          {
      		     if(*columna_f>*columna)//+++++
					{
					  *columna=*columna+1;
				      while(*columna!= *columna_f)
					       {
						   	  if(ajedrez[*fila][*columna].representacion == "  "){
								 aux=true;}
							  else
							  	  {

					   		  	     aux=false;
					   		  	     break;
								  }
							*columna=*columna+1;
					       }
       				return aux;
					}
				  else if (*columna>*columna_f)//+++++
				  	       {
		   				     *columna_f=*columna_f+1;
		   				     while(*columna!=*columna_f)
						           {
								   	  if(ajedrez[*fila][*columna_f].representacion == "  ")
										 aux=true;
								   	  else
										 {
								   	  	    aux=false;
										 	break;
										 }
	   							      *columna_f=*columna_f+1;
					 				}
							return aux;
			   			   }
   	    	  }
}
else
	{
      return false;
    }

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
}

void mover(ficha **ajedrez,char movimiento[])
{
	int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;

    coordenadas retorno= decodificar(movimiento);

	*fila=retorno.f;
	*columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

	ficha aux;

    aux.color=ajedrez[*fila][*columna].color;
    aux.numero=ajedrez[*fila][*columna].numero;
    aux.representacion=ajedrez[*fila][*columna].representacion;
    aux.tipo=ajedrez[*fila][*columna].tipo;

    ajedrez[*fila][*columna].color='d';
    ajedrez[*fila][*columna].numero=0;
    ajedrez[*fila][*columna].representacion="  ";
    ajedrez[*fila][*columna].tipo= "  ";

    ajedrez[*fila_f][*columna_f].color=aux.color;
    ajedrez[*fila_f][*columna_f].numero=aux.numero;
    ajedrez[*fila_f][*columna_f].representacion=aux.representacion;
    ajedrez[*fila_f][*columna_f].tipo=aux.tipo;

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
}
bool peon(ficha **ajedrez, char movimiento[],int conta)
{
    int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;
    coordenadas retorno=decodificar(movimiento);
	*fila=retorno.f;
    *columna=retorno.c;
    *fila_f=retorno.f_f;
    *columna_f=retorno.c_f;

    if (conta== 0 || conta== 1)
    {
        if( *fila_f==*(fila)+1  || *fila_f==*(fila)+2 && *columna_f==*columna )
        {
        return true;
        }
        else if ( *fila_f==*(fila)-1  || *fila_f== *(fila)-2 && *columna_f==*columna)
            {
            return true;
            }
        else
            return false;

    }

    if(conta>=2)
    {
        if(*fila_f>(*fila)+1 || *fila_f<(*fila)-1)
            return false;
        else if (*fila_f==*(fila)+1  || *fila_f==*(fila)-1 && *columna_f==*columna && ajedrez[*fila_f][*columna_f].representacion== "  ")
        {
            return true;
        }
            else if (*fila_f==*(fila)+1 && *columna_f==*(columna)+1 || *fila_f==*(fila)+1 && *columna_f==*(columna)-1 && ajedrez[*fila_f][*columna_f].color!=ajedrez[*fila][*columna].color&& ajedrez[*fila_f][*columna_f].representacion!= "  ")
                {
                    return true;
                }
                else if (fila_f==fila-1 && columna_f==columna+1 || fila_f==fila-1 && columna_f==columna-1 && ajedrez[*fila_f][*columna_f].color!=ajedrez[*fila][*columna].color && ajedrez[*fila_f][*columna_f].representacion!= "  ")
                    return true;
                    else
                        return false;
    }

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
}
void inicializacion(ficha **ajedrez)
{
for(int i=0;i<8;i++)
    {
    for(int j=0;j<8;j++)
        ajedrez[i][j].representacion="  ";
    }

//Blancas
    ajedrez[0][0].representacion="ti";
    ajedrez[0][0].tipo= "torre";
    ajedrez[0][1].representacion="ci";
    ajedrez[0][1].tipo= "caballo";
    ajedrez[0][2].representacion="ai";
    ajedrez[0][2].tipo= "alfil";
    ajedrez[0][3].representacion="ry";
    ajedrez[0][3].tipo= "rey";
    ajedrez[0][4].representacion="ra";
    ajedrez[0][4].tipo= "reina";
    ajedrez[0][5].representacion="ad";
    ajedrez[0][5].tipo = "alfil";
    ajedrez[0][6].representacion="cd";
    ajedrez[0][6].tipo= "caballo";
    ajedrez[0][7].representacion="td";
    ajedrez[0][7].tipo= "torre";
    ajedrez[1][0].representacion="p1";
    ajedrez[1][0].tipo="peon";
    ajedrez[1][1].representacion="p2";
    ajedrez[1][1].tipo="peon";
    ajedrez[1][2].representacion="p3";
    ajedrez[1][2].tipo="peon";
    ajedrez[1][3].representacion="p4";
    ajedrez[1][3].tipo="peon";
    ajedrez[1][4].representacion="p5";
    ajedrez[1][4].tipo="peon";
    ajedrez[1][5].representacion="p6";
    ajedrez[1][5].tipo="peon";
    ajedrez[1][6].representacion="p7";
    ajedrez[1][6].tipo="peon";
    ajedrez[1][7].representacion="p8";
    ajedrez[1][7].tipo="peon";

    ajedrez[0][0].numero=1;
    ajedrez[0][1].numero=2;
    ajedrez[0][2].numero=3;
    ajedrez[0][3].numero=4;
    ajedrez[0][4].numero=5;
    ajedrez[0][5].numero=6;
    ajedrez[0][6].numero=7;
    ajedrez[0][7].numero=8;
    ajedrez[1][0].numero=9;
    ajedrez[1][1].numero=10;
    ajedrez[1][2].numero=11;
    ajedrez[1][3].numero=12;
    ajedrez[1][4].numero=13;
    ajedrez[1][5].numero=14;
    ajedrez[1][6].numero=15;
    ajedrez[1][7].numero=16;

    ajedrez[0][0].color='b';
    ajedrez[0][1].color='b';
    ajedrez[0][2].color='b';
    ajedrez[0][3].color='b';
    ajedrez[0][4].color='b';
    ajedrez[0][5].color='b';
    ajedrez[0][6].color='b';
    ajedrez[0][7].color='b';
    ajedrez[1][0].color='b';
    ajedrez[1][1].color='b';
    ajedrez[1][2].color='b';
    ajedrez[1][3].color='b';
    ajedrez[1][4].color='b';
    ajedrez[1][5].color='b';
    ajedrez[1][6].color='b';
    ajedrez[1][7].color='b';

//negras
    ajedrez[6][0].representacion="P1";
    ajedrez[6][0].tipo="peon";
    ajedrez[6][1].representacion="P2";
    ajedrez[6][1].tipo="peon";
    ajedrez[6][2].representacion="P3";
    ajedrez[6][2].tipo="peon";
    ajedrez[6][3].representacion="P4";
    ajedrez[6][3].tipo="peon";
    ajedrez[6][4].representacion="P5";
    ajedrez[6][4].tipo="peon";
    ajedrez[6][5].representacion="P6";
    ajedrez[6][5].tipo="peon";
    ajedrez[6][6].representacion="P7";
    ajedrez[6][6].tipo="peon";
    ajedrez[6][7].representacion="P8";
    ajedrez[6][7].tipo="peon";
    ajedrez[7][0].representacion="TI";
    ajedrez[7][0].tipo="torre";
    ajedrez[7][1].representacion="CI";
    ajedrez[7][1].tipo= "caballo";
    ajedrez[7][2].representacion="AY";
    ajedrez[7][2].tipo= "alfil";
    ajedrez[7][3].representacion="RY";
    ajedrez[7][3].tipo= "rey";
    ajedrez[7][4].representacion="RA";
    ajedrez[7][4].tipo= "reina";
    ajedrez[7][5].representacion="AD";
    ajedrez[7][5].tipo= "alfil";
    ajedrez[7][6].representacion="CD";
    ajedrez[7][6].tipo= "caballo";
    ajedrez[7][7].representacion="TD";
    ajedrez[7][7].tipo= "torre";

	ajedrez[6][0].color='n';
    ajedrez[6][1].color='n';
    ajedrez[6][2].color='n';
    ajedrez[6][3].color='n';
    ajedrez[6][4].color='n';
    ajedrez[6][5].color='n';
    ajedrez[6][6].color='n';
    ajedrez[6][7].color='n';
    ajedrez[7][0].color='n';
    ajedrez[7][1].color='n';
    ajedrez[7][2].color='n';
    ajedrez[7][3].color='n';
    ajedrez[7][4].color='n';
    ajedrez[7][5].color='n';
    ajedrez[7][6].color='n';
    ajedrez[7][7].color='n';

    ajedrez[6][0].numero=17;
    ajedrez[6][1].numero=18;
    ajedrez[6][2].numero=19;
    ajedrez[6][3].numero=20;
    ajedrez[6][4].numero=21;
    ajedrez[6][5].numero=22;
    ajedrez[6][6].numero=23;
    ajedrez[6][7].numero=24;
    ajedrez[7][0].numero=25;
    ajedrez[7][1].numero=26;
    ajedrez[7][2].numero=27;
    ajedrez[7][3].numero=28;
    ajedrez[7][4].numero=29;
    ajedrez[7][5].numero=30;
    ajedrez[7][6].numero=31;
    ajedrez[7][7].numero=32;
}

void imprimir(ficha **ajedrez)
{
    cout<<"   "<< " a  b  c  d  e  f  g  h"<<endl;
    for (int i=0;i<8;i++)
	{
	 cout<<endl<<"   "<< "+--+--+--+--+--+--+--+--+"<<endl;
	 cout<<i+1<<"  ";
	 cout<< "|";
        for (int j=0;j<8;j++)
            cout<< ajedrez[i][j].representacion<<"|";
	 cout<<"   ";
	}
	cout<<endl<<"   "<< "+--+--+--+--+--+--+--+--+"<<endl;
}
coordenadas decodificar (char movimiento[])
{
    int *fila=new int;
    int *columna=new int;
    int *fila_f=new int;
    int *columna_f=new int;
    coordenadas retorno;
	*fila=0;
	*fila_f=0;
	*columna=0;
	*columna_f=0;

    if(movimiento[0]== 'a')
    {
        *columna = 0;
    }
    else if(movimiento[0]== 'b')
        {
            *columna = 1;
        }
        else if(movimiento[0]== 'c')
            {
                *columna = 2;
            }
            else if(movimiento[0]== 'd')
                {
                    *columna = 3;
                }
                else if(movimiento[0]== 'e')
                    {
                        *columna = 4;
                    }
                    else if(movimiento[0]== 'f')
                        {
                            *columna = 5;
                        }
                        else if(movimiento[0]== 'g')
                            {
                                *columna = 6;
                            }
                            else if(movimiento[0]== 'h')
                                    {
                                        *columna = 7;
                                    }
                            		else if(movimiento[0]== 'h')
                            	         {
                                        *columna = 7;
                       		             }
                                    else
                                        *columna=-1;


	if(movimiento[1] == '1')
    {
        *fila= 0;
    }
    else if(movimiento[1] == '2')
        {
            *fila= 1;
        }
        else if(movimiento[1] == '3')
            {
                *fila= 2;
            }
            else if(movimiento[1] == '4')
                {
                    *fila= 3;
                }
                else if(movimiento[1] == '5')
                    {
                        *fila= 4;
                    }
                    else if(movimiento[1] == '6')
                        {
                            *fila= 5;
                        }
                        else if(movimiento[1] == '7')
                            {
                                *fila= 6;
                            }
                            else if(movimiento[1] == '8')
                                    {
                                        *fila= 7;
                                    }
                                    else
                                        *fila=-1;


    if(movimiento[3]== 'a')
    {
        *columna_f= 0;
    }
    else if(movimiento[3]== 'b')
        {
            *columna_f = 1;
        }
        else if(movimiento[3]== 'c')
            {
                *columna_f = 2;
            }
            else if(movimiento[3]== 'd')
                {
                    *columna_f = 3;
                }
                else if(movimiento[3]== 'e')
                    {
                        *columna_f = 4;
                    }
                    else if(movimiento[3]== 'f')
                        {
                            *columna_f = 5;
                        }
                        else if(movimiento[3]== 'g')
                            {
                                *columna_f = 6;
                            }
                            else if(movimiento[3]== 'h')
                                    {
                                        *columna_f = 7;
                                    }
                                    else
	                                    *columna_f=-1;



    if(movimiento[4]== '1')
    {
        *fila_f = 0;
    }
    else if(movimiento[4]== '2')
        {
            *fila_f = 1;

        }
        else if(movimiento[4]== '3')
            {
                *fila_f = 2;
            }
            else if(movimiento[4]== '4')
                {
                    *fila_f = 3;
                }
                else if(movimiento[4]== '5')
                    {
                        *fila_f = 4;
                    }
                    else if(movimiento[4]== '6')
                        {
                            *fila_f = 5;
                        }
                        else if(movimiento[4]== '7')
                            {
                                *fila_f = 6;
                            }
                            else if(movimiento[4]== '8')
                                    {
                                        *fila_f = 7;
                                    }
                                    else
                                        *fila_f=-1;


retorno.f=*fila;
retorno.c=*columna;
retorno.f_f=*fila_f;
retorno.c_f=*columna_f;

    delete fila;
    fila=NULL;
    delete columna;
    columna=NULL;
    delete fila_f;
    fila_f=NULL;
    delete columna_f;
    columna_f=NULL;
return retorno;
}
