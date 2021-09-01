#include <stdlib.h>
#include <string.h>
#include "evento_pesca.h"
#define LECTURA "r"
#define ESCRITURA "w"
#define LECTURA_LISTA "%[^;];%i;%i;%[^\n]\n"
#define ESCRITURA_LISTA "%s;%i;%i;%s\n"
#define NOMBRE_AUX "archivo_aux.txt"
#define MAX_LETRAS 50
const static  char FIN_STRING = '\0';
const int CONTADOR_INICIAL = 0;
const int CANT_LEIDOS = 4;
const int ERROR = -1;
const int FUNCIONO = 0;
/*
POST: elimina el primer caracter el vector recibido.
*/
void eliminar_ordenadamente(char vector[MAX_LETRAS], int* tope){
	for (int i = CONTADOR_INICIAL; i < *tope - 1; ++i){
		vector[i] = vector[i + 1];
	}
	(*tope)--;
	vector[*tope] = FIN_STRING;
}
/*
POST: retorna true si el archivo recibido es uno con extencion .txt.
*/
bool es_archivo_valido(const char* ruta_archivo){
	int tope = (int)strlen(ruta_archivo);
	char extencion[MAX_LETRAS];
	strcpy(extencion, ruta_archivo);
	while((extencion[0] != '.') && (tope > 2)){
		eliminar_ordenadamente(extencion, &tope);
	}
	if(strcmp(extencion, ".txt") == 0){
		return true;
	}else return false;

}

arrecife_t* crear_arrecife(const char* ruta_archivo){
	arrecife_t * arrecife = malloc(sizeof(arrecife_t));
	if(!arrecife){
		printf("no se pudo reservar memoria para el vector de pokemones del arrecife\n");
		return NULL;
	}
	if(!es_archivo_valido(ruta_archivo)){
		printf("archivo no valido...\n");
		free(arrecife);
		return NULL;
	}
	pokemon_t pokemon_nuevo;
	FILE * lista_pokemon = fopen(ruta_archivo, LECTURA);
	if(!lista_pokemon){
		printf("No se pudo abrir el archivo!!!\n");
		free(arrecife);
		return NULL;
	}
	(*arrecife).cantidad_pokemon = CONTADOR_INICIAL;
	(*arrecife).pokemon = malloc((size_t)((*arrecife).cantidad_pokemon + 1) * (sizeof(pokemon_t)));
	int leidos = fscanf(lista_pokemon, LECTURA_LISTA, pokemon_nuevo.especie, &(pokemon_nuevo.velocidad), &(pokemon_nuevo.peso), pokemon_nuevo.color);
	pokemon_t* pokemones = NULL;
	bool error = false;
	while((leidos == CANT_LEIDOS) && (!error)){
		(*arrecife).pokemon[(*arrecife).cantidad_pokemon] = pokemon_nuevo;
		(*arrecife).cantidad_pokemon++;
		pokemones = realloc((*arrecife).pokemon, (size_t)((*arrecife).cantidad_pokemon + 1) * (sizeof(pokemon_t)));
		if(pokemones == NULL){
			error = true;
		}else{
			(*arrecife).pokemon = pokemones;
			leidos = fscanf(lista_pokemon, LECTURA_LISTA, pokemon_nuevo.especie, &(pokemon_nuevo.velocidad), &(pokemon_nuevo.peso), pokemon_nuevo.color);
		}
	}
	fclose(lista_pokemon);
	if((error) || ((*arrecife).cantidad_pokemon == 0)){
		free((*arrecife).pokemon);
		free(arrecife);
		return NULL;
	}
	return arrecife;
}

acuario_t* crear_acuario(){
	acuario_t * acuario = NULL;
	acuario = malloc(sizeof(acuario_t));
	if(acuario == NULL){
		return NULL;
	}
	(*acuario).pokemon = malloc(sizeof(pokemon_t));
	if((*acuario).pokemon == NULL){
		return NULL;
	}
	(*acuario).cantidad_pokemon = CONTADOR_INICIAL;
	return acuario;
}

/*
POST: retorna la cantidad de pokemones que cumplen con el requisito pedido
*/
int contador_pokemon(pokemon_t * pokemon, int tope_pokemon, bool (seleccionar_pokemon)(pokemon_t*)){
	pokemon_t* pokemon_aux = NULL;
	int contador = CONTADOR_INICIAL;
	for (int i = 0; i < tope_pokemon; ++i){
		pokemon_aux = &(pokemon[i]);
		if(seleccionar_pokemon(pokemon_aux)){
			contador++;
		}
	}
	return contador;
}

/*
PRE: deben haber las pokemones que cumplan el requisito en el arrecife que la cantidad a sacar.
POST: retorna true si pudo copiar el pokemon a trasladar al vector del acuario, caso contraio, retorna false.
*/
bool trasladar(arrecife_t* arrecife, acuario_t* acuario, int lugar){
	int tope_actual = (*acuario).cantidad_pokemon;
	(*acuario).pokemon[tope_actual] = (*arrecife).pokemon[lugar];
	tope_actual++;
	(*acuario).cantidad_pokemon = tope_actual;
	pokemon_t * pokemon_aux = NULL;
	pokemon_aux = realloc((*acuario).pokemon, (size_t)((*acuario).cantidad_pokemon + 1) * (sizeof(pokemon_t)));
	if(pokemon_aux == NULL){
		printf("no se pudo agrandar la memoria para el vector del acuario\n");
		return false;
	}
	(*acuario).pokemon = pokemon_aux;
	return true;
}

/*
PRE: deben haber las pokemones que cumplan el requisito en el arrecife que la 
	cantidad a sacar.
POST: elimina el pokemon que se encuentra en el vector del acuario del vector que se 	encuentra en el arrecife. 
*/
bool eliminar_pokemon(arrecife_t * arrecife, int lugar){
	if((*arrecife).cantidad_pokemon > 1){
		(*arrecife).pokemon[lugar] = (*arrecife).pokemon[(*arrecife).cantidad_pokemon - 1];
		pokemon_t * pokemon_aux = NULL;
		pokemon_aux = realloc((*arrecife).pokemon, (size_t)((*arrecife).cantidad_pokemon - 1) * (sizeof(pokemon_t)));
		if(pokemon_aux == NULL){
		printf("no se pudo achicar la memoria para el vector del arrecife\n");
		return false;
		}
		(*arrecife).pokemon = pokemon_aux;
		(*arrecife).cantidad_pokemon--;
		return true;		
	}else{
		(*arrecife).cantidad_pokemon--;
		return true;
	} 
}
int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion){
	if((*arrecife).cantidad_pokemon < cant_seleccion){
		printf("insuficientes pokemones dentro del arrecife...\n");
		return ERROR;
	}
	int cant_a_sacar = contador_pokemon((*arrecife).pokemon,(*arrecife).cantidad_pokemon, seleccionar_pokemon);
	if(cant_a_sacar < cant_seleccion){
		printf("insuficientes pokemones que cumplan el requisito pedido...\n");
		return ERROR;
	}
	cant_a_sacar = cant_seleccion;
	bool error = false;
	while((cant_a_sacar > CONTADOR_INICIAL) && (!error)){
		bool encontro = false;
		int i = 0;
		int lugar = 0;
		while((i < (*arrecife).cantidad_pokemon) &&(!encontro) && (!error)){
			if(seleccionar_pokemon((*arrecife).pokemon+i)){
				encontro = true;
				lugar = i;
			}
			i++;
		}
		if(encontro == true){
			if((!trasladar(arrecife, acuario, lugar)) || (!eliminar_pokemon(arrecife, lugar))){
				error = true;
			}else cant_a_sacar--;
		}
	}
	if(error){
		return ERROR;
	}else return FUNCIONO;
}
void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)){
	for (int i = 0; i < (*arrecife).cantidad_pokemon; ++i){
		mostrar_pokemon((*arrecife).pokemon+i);
	}
}
int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo){
	FILE * archivo_acuario = fopen(nombre_archivo, LECTURA);
	if(!archivo_acuario){
		FILE * archivo_nuevo = fopen(nombre_archivo, ESCRITURA);
		if(!archivo_nuevo){
			printf("no se pudo crear archivo nuevo..\n");
			fclose(archivo_acuario);
			return ERROR;
		}
		pokemon_t pokemon_aux;
		int i = CONTADOR_INICIAL;
		while(i < (*acuario).cantidad_pokemon){
			pokemon_aux = (*acuario).pokemon[i];
			fprintf(archivo_nuevo, ESCRITURA_LISTA, pokemon_aux.especie, pokemon_aux.velocidad, pokemon_aux.peso, pokemon_aux.color);
			i++;
		}
		fclose(archivo_nuevo);
	}else{
		FILE * archivo_nuevo = fopen(NOMBRE_AUX, ESCRITURA);
		if(!archivo_nuevo){
			printf("no se pudo crear archivo nuevo..\n");
			fclose(archivo_acuario);
			return ERROR;
		}
		pokemon_t pokemon_acuario;
		pokemon_t pokemon_aux;
		int leidos = fscanf(archivo_acuario, LECTURA_LISTA, pokemon_acuario.especie, &(pokemon_acuario.velocidad), &(pokemon_acuario.peso), pokemon_acuario.color);
		while(leidos == CANT_LEIDOS){
			fprintf(archivo_nuevo, ESCRITURA_LISTA, pokemon_acuario.especie, pokemon_acuario.velocidad, pokemon_acuario.peso, pokemon_acuario.color);
			leidos = fscanf(archivo_acuario, LECTURA_LISTA, pokemon_acuario.especie, &(pokemon_acuario.velocidad), &(pokemon_acuario.peso), pokemon_acuario.color);
		}
		int i = CONTADOR_INICIAL;
		while(i < (*acuario).cantidad_pokemon){
			pokemon_aux = (*acuario).pokemon[i];
			fprintf(archivo_nuevo, ESCRITURA_LISTA, pokemon_aux.especie, pokemon_aux.velocidad, pokemon_aux.peso, pokemon_aux.color);
			i++;
		}
		fclose(archivo_acuario);
		fclose(archivo_nuevo);
		rename(NOMBRE_AUX, nombre_archivo);
	}
	return FUNCIONO;
}
void liberar_acuario(acuario_t* acuario){
	free((*acuario).pokemon);
	free(acuario);
}

void liberar_arrecife(arrecife_t* arrecife){
	free((*arrecife).pokemon);
	free(arrecife);
}
