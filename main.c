// Copyright (C) 2019 <Dario Lanfranco Ruffener, Franco Anibal Rodriguez, Esteban Salvay Dilena> <dariolanfrancoruffener@gmail.com, francorod47@gmail.com, estebansaldil22@gmail.com>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include "moviehouse.h"

Lista list;
FILE* g;
int op;
Arreglo a;


//Muestra por pantalla el menu principal
void MenuPrincipal();

//Muestra un mensaje al salir del programa
void CartelSalir();


//Programa Principal
int main(){
	
    Inicializar(&list);
	DeTxtALista(&list,g);
   // MostrarLista(list);
	ArregColor(list,&a);

	do{
		MenuPrincipal();
		scanf("%d",&op);
		switch(op){
			case 1: {
                printf("--------------------------\n");
				MasPopulares(a);
				break;
			};
			case 2: {
                printf("--------------------------\n");
				CantPeliculas(a);
				break;
			}
			case 3: {
                printf("--------------------------\n");
				MostrarCostLanz(a);
				break;
			}
			case 4: {
                printf("--------------------------\n");
				MostrarGenero(a);
				break;
			}
			case 5: {
                printf("--------------------------\n");
                MostVotoPromedio(a);
				break;
			}
			case 6: {
                printf("--------------------------\n");
				MostRating(a);
				break;
			}
			case 7: {
                printf("--------------------------\n");
                Exportar(a,g);
				break;
			}
   			case 8: {
                printf("--------------------------\n");
				Listar(g,a);
				break;
            }
			case 9: {
                printf("--------------------------\n");
				CartelSalir();
				break;
			}
			default: {
                printf("--------------------------\n");
				printf("Ingrese un valor entre 1 y 9.\n");
			}	

		}
	}while(op != 9);



}

//Muestra por pantalla el menu principal
void MenuPrincipal(){
    printf("\n");
	printf("|-------------------|\n");
	printf("|    Movie House    |\n");
	printf("| Elige una opcion: |\n");
	printf("|-------------------|\n\n");
	printf("1: ->  Peliculas mas populares\n");
	printf("2: ->  Cantidad de peliculas por director\n");
	printf("3: ->  Mostrar las peliculas mas caras por epoca de lanzamiento\n");
	printf("4: ->  Mostrar peliculas por genero\n");
	printf("5: ->  Peliculas mas votadas por genero\n");
	printf("6: ->  Mostrar por Rating\n");
	printf("7: ->  Exportar a un archivo binario\n");
    printf("8: ->  Listar archivo binario\n");
	printf("9: ->  Salir\n");
}

//Muestra un mensaje al salir del programa
void CartelSalir(){
	printf("---------------------------------------|\n");
	printf("|  ¡Gracias por usar movie moviehouse!  |\n");
	printf("---------------------------------------|\n");
}














