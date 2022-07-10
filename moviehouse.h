// Copyright (C) 2019 <Dario Lanfranco Ruffener, Franco Anibal Rodriguez, Esteban Salvay Dilena> <dariolanfrancoruffener@gmail.com, francorod47@gmail.com, estebansaldil22@gmail.com>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#ifndef MOVIEHOUSE_H
#define MOVIEHOUSE_H

#include <stdio.h>

#define N 80
#define SIZE 200

typedef enum{
			Action,Comedy,Adventure,Drama,Horror,SciFi,Fantasy,Animation
}TGenero;

typedef enum{ 
			Color,BW

}TColor;



//Registro con información de una pelicula

typedef struct{ 
			int id;
			char titulo[N];
			char director[N];
			TGenero genero;
			int likes;
			int cant_votantes;
			float voto_promedio;
			int lanzamiento;
			float costo;
			TColor color;
			float rating;        
			
}Movie;

//LSE de Movie
struct Nodo{
	Movie pelicula;
	struct Nodo *next; 
};

//Puntero al primer elemento de la LSE
typedef struct{
	struct Nodo *head;
}Lista;

//Arreglo de peliculas con cantidad
typedef struct{
	 Movie peliculas[SIZE];
	 int cant;
}Arreglo;



/**
	Operaciones sobre lista
**/

//Inicializa la lista
void Inicializar(Lista *l);

//Crea un elemento para agregar a la lista
struct Nodo * CrearNodo(FILE* f);

//Inserta un nodo al comienzo de la lista
void Insertar(Lista *l,FILE* h);

//Muestra toda la lista
void MostrarLista(Lista l);

//Transforma el texto copiado del archivo a TGenero
void AsigGenero(char cadena[N],Movie *peli);

//Transforma el texto copiado del archivo a TColor
void AsigColor(char cadena[N],Movie *peli);

// CARGA LISTA A UN ARREGLO
void ArregColor(Lista l, Arreglo *pelisC);




/*
	Acciones auxiliares
*/

//Ordena el ARREGLO segun la cantidad de Likes
void OrdenarPop(Arreglo *arre);

//Ordenamiento segun director
void OrdDirec(Arreglo *arre);

//Ordenamiento por lanzamiento
void OrdLanz(Arreglo *arre);


//Ordenamiento por costo
void OrdCost(Arreglo *arre);

//Ordenamiento por genero(p4)
void OrdGen(Arreglo *arre);

//Accion recursiva para mostrar titulos del genero dado
void GeneroRecursivo(Arreglo pelisC, int gen, int i);

//Ordena el arreglo segun el rating
void OrdRating(Arreglo *arre);

//Accion que ordena por voto_promedio
void OrdVoto(Arreglo *arre);

//Funcion que devuelve un elemento de tipo TGenero
char* FGenero(TGenero g);

//Funcion que devuelve un elemento de tipo TColor
char* FColor(TColor c);


/**
	Funcionalidades del proyecto
**/

//Dado un archivo de texto con la información de las peliculas, 
//guarda en la lista todas las pelicuas usando el registro Movie
void DeTxtALista(Lista *l, FILE *h);

//Acción que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a);

//Funcion que muestra la cantidad de peliculas por director
void CantPeliculas(Arreglo pelisC);

//Muestra las m peliculas mas costosas de cada lanzamiento
void MostrarCostLanz(Arreglo pelisC);

//Accion que muestra todas las peliculas dependiendo el genero
void MostrarGenero(Arreglo pelisC);

//Accion que muestra las 10 peliculas con mejor voto promedio dependiendo del genero ingresado por el usuario
void MostVotoPromedio(Arreglo pelisC);

//Muestra las 10 peliculas con mejor rating
void MostRating(Arreglo pelisC);

//Accion exportar peliculas 
void Exportar(Arreglo pelisC, FILE *e);

//Accion que lista los elementos del archivo binario
void Listar(FILE *f, Arreglo pelisC);





#endif
