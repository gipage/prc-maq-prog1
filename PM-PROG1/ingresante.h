#ifndef INGRESANTE_H_INCLUDED
#define INGRESANTE_H_INCLUDED
#include "celular.h"

//Cantidad maxima de caracteres que pueden tener las variables strings:
#define max_chars 60

//Cantidad de carreras en la UNSL:
#define numCarreras 23

//Declaracion del tipo Ingresante:
typedef struct
{
    int num_inscripcion;
    int dni;
    char apellido[max_chars];
    char nombre[max_chars];

    //Si el campo arr_Carreras[i] es igual a 1, se interpreta que el alumno se inscribio en la carrera
    //con codigo i. Por otro lado, si arr_Carreras[i] es igual a 0, decimos que el alumno no esta inscripto
    //en la carrera i.
    int arr_Carreras[numCarreras];

    //'1' Si el alumno relizo el ingreso y '0' en caso contrario.
    int bool_ingreso;

    Celular cel;
    //'1' Si el ingresante es preinscripto.
    //'2' Si el ingresante es aspirante.
    //'3' Si el ingresante es inscripto.
    int cod_Estado;
} Ingresante;

//Inicializa el campo 'num_inscripcion' con el valor 'n'.
//Inicializa el campo 'cont_Inscriptas' con el valor 0.
//Asigna a todos los elementos de 'arr_Carreras' el valor 0.
void inicializar_ingresante(Ingresante* ingre, int n)
{
    iniciar_celular(&(*ingre).cel);
    (*ingre).num_inscripcion = n;
    for(int i = 0; i < numCarreras; i++)
        (*ingre).arr_Carreras[i] = 0;
    (*ingre).bool_ingreso = 0;
    (*ingre).cod_Estado = 1;
}

//Asigna el valor 'documento' al campo 'dni'.
void carga_documento(Ingresante* ingre, int documento)
{
    (*ingre).dni = documento;
}

//Asigna el valor 'nom[]' al campo 'nombre'.
void carga_nombre(Ingresante* ingre, char nom[])
{
    strcpy((*ingre).nombre, nom);
}

//Asigna el valor 'ape[]' al campo 'apellido'. .
void carga_apellido(Ingresante* ingre, char ape[])
{
    strcpy((*ingre).apellido, ape);
}

//Esta funcion recibe el codigo de una carrera, y asigna al campo arr_Carreras[codigoCarrera] el valor 1.
void carga_carrera(Ingresante* ingre, int codigoCarrera)
{
    (*ingre).arr_Carreras[codigoCarrera] = 1;
}

//Asigna el valor 'cel' al campo 'cel'.
void carga_celular(Ingresante* ingre, Celular cel)
{
    (*ingre).cel = cel;
}

//Asigna el valor 'ingreso' al campo 'bool_ingreso'.
//El parametro 'ingreso' debe tener el valor 0 o 1.
void carga_ingreso(Ingresante* ingre, int ingreso)
{
    (*ingre).bool_ingreso = ingreso;
}

//Asigna el valor 'est; al campo 'cod_Estado'.
//'est' debe tener el valor 1, 2, o 3.
void carga_estado(Ingresante* ingre, int est)
{
    (*ingre).cod_Estado = est;
}

//Asigna a 'arr_Carreras[codCarrera]' el valor 'boolInscripto'.
//Si 'boolInscripto' es igual a 1, el estudiante se inscribio a una carrera.
//Si 'boolInscripto' es igual a 0, el estudiante borro la inscripcion a una carrera.
void modificarCarrera(Ingresante* ingre, int codCarrera, int boolInscripto)
{
    (*ingre).arr_Carreras[codCarrera] = boolInscripto;
}

//Asigna a 'bool_ingreso' el valor 'boolIngre'.
//'boolIngre' debe tener el valor 0 o 1.
void modificar_ingreso(Ingresante* ingre, int boolIngre)
{
    (*ingre).bool_ingreso = boolIngre;
}

//Asigna el valor 'est; al campo 'cod_Estado'.
//'est' debe tener el valor 1, 2, o 3.
void modificarEstado(Ingresante* ingre, int est)
{
    (*ingre).cod_Estado = est;
}

//Devuelve el valor actual de 'dni'.
int ver_documento(Ingresante ingre)
{
    return ingre.dni;
}

//Devuelve el valor actual de 'numeroInscripccion'.
int ver_inscripcion(Ingresante ingre)
{
    return ingre.num_inscripcion;
}

//Devuelve el valor actual de 'nombre'.
char* ver_nombre(Ingresante ingre)
{
    char *aux;
    aux = (char*) malloc(sizeof(char)*max_chars);
    strcpy(aux, ingre.nombre);
    return aux;
}

//Devuelve el valor actual de 'apellido'.
char* ver_apellido(Ingresante ingre)
{
    char *aux;
    aux = (char*) malloc(sizeof(char)*max_chars);
    strcpy(aux, ingre.apellido);
    return aux;
}

// Devuelve el valor actual de 'arr_Carreras'.
int* ver_carreras(Ingresante ingre)
{
    int* aux;
    aux = (int*) malloc(sizeof(int)*numCarreras);
    for(int i = 0; i < numCarreras; i++)
        aux[i] = ingre.arr_Carreras[i];
    return aux;
}

//Devuelve el valor actual de 'cel'.
Celular ver_celular(Ingresante ingre)
{
    return ingre.cel;
}

//Devuelve el valor actual de 'bool_ingreso'.
int ver_ingreso(Ingresante ingre)
{
    return ingre.bool_ingreso;
}

//Devuelve el valor actual de 'cod_Estado'.
int ver_estado(Ingresante ingre)
{
    return ingre.cod_Estado;
}

#endif // INGRESANTE_H_INCLUDED
