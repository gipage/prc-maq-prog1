#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ingresante.h"
#include "lista_ingresante.h"

#define numColumnas 3
#define dist_columnas 60
#define cod_terminar_input -1

//Codigos de estado (preinscripto / aspirante / inscripto):
#define cod_pre_inscripto 1
#define cod_aspirante 2
#define cod_inscripto 3

//Codigos de ingreso (aprobado / desaprobado):
#define cod_ingreso_aprobado 1
#define cod_ingreso_desaprobado 0

//Esta funcion cambia el color de los caracteres impresos en la pantalla a rojo
void titilar_pantalla_rojo()
{
    system("COLOR 04");
    system("COLOR 04");
    system("COLOR 04");
    system("COLOR 04");
    system("COLOR 07");
}

//Esta funcion alterna, durante unos milisegundos, el color de los caracteres impresos
//en la pantalla en blanco y verde.
void titilar_pantalla_verde()
{
    system("COLOR 02");
    system("COLOR 02");
    system("COLOR 02");
    system("COLOR 02");
    system("COLOR 07");
}

//Copia en nombre_carrera[] el nombre de la carrera cuyo codigo es cod_carrera.
//Copia "NULL" en caso de que cod_carrera sea un codigo incorrecto.
void obtener_nombre_carrera(char nom_carrera[], int cod_carrera)
{
    switch (cod_carrera)
    {
        case 1:
            strcpy(nom_carrera,"Ing. Electronica con orientacion en sistemas digitales");
            break;
        case 2:
            strcpy(nom_carrera,"Ing. Computacion");
            break;
        case 3:
            strcpy(nom_carrera,"Ing. Informatica");
            break;
        case 4:
            strcpy(nom_carrera,"Ing. Minas");
            break;
        case 5:
            strcpy(nom_carrera,"Lic. Ciencias de la Computacion");
            break;
        case 6:
            strcpy(nom_carrera,"Lic. Ciencias Geologicas");
            break;
        case 7:
            strcpy(nom_carrera,"Lic. Ciencias Matematicas");
            break;
        case 8:
            strcpy(nom_carrera,"Lic. Fisica");
            break;
        case 9:
            strcpy(nom_carrera,"Lic. Matematica Aplicada");
            break;
        case 10:
            strcpy(nom_carrera,"Prof. Ciencias de la Computacion");
            break;
        case 11:
            strcpy(nom_carrera,"Prof. Fisica");
            break;
        case 12:
            strcpy(nom_carrera,"Prof. Matematica");
            break;
        case 13:
            strcpy(nom_carrera,"Prof. Tecnologia Electronica");
            break;
        case 14:
            strcpy(nom_carrera,"Tecnicatura Electronica");
            break;
        case 15:
            strcpy(nom_carrera,"Tecnicatura Energias Renovables");
            break;
        case 16:
            strcpy(nom_carrera,"Tecnicatura Exploracion Minera");
            break;
        case 17:
            strcpy(nom_carrera,"Tecnicatura Geoinformatica");
            break;
        case 18:
            strcpy(nom_carrera,"Tecnicatura Obras Viales");
            break;
        case 19:
            strcpy(nom_carrera,"Tecnicatura Procesamiento Minerales");
            break;
        case 20:
            strcpy(nom_carrera,"Tecnicatura Redes de Computadoras");
            break;
        case 21:
            strcpy(nom_carrera,"Tecnicatura Telecomunicaciones");
            break;
        case 22:
            strcpy(nom_carrera,"Tecnicatura Web");
            break;
        case 23:
            strcpy(nom_carrera,"Tecnicatura Fotografia");
            break;
        default:
            strcpy(nom_carrera, "NULL");
    }
}

//Copia en nombre_carrera[] el nombre de la carrera cuyo codigo es cod_carrera.
//Copia "NULL" en caso de que cod_carrera sea un codigo incorrecto.
void obtener_nombre_estado(char str[], int cod_estado)
{
    switch(cod_estado)
    {
        case 1:
            strcpy(str, "Preinscripto");
            break;
        case 2:
            strcpy(str,"Aspirante");
            break;
        case 3:
            strcpy(str,"Inscripto");
            break;
        default:
            strcpy(str, "NULL");
    }
}


//Imprime codigo y nombre de todas las carreras que ofrece la UNSL:
void imprimir_carreras_disponibles()
{
    int tam_nom;
    char nom_carrera[max_chars];

    //Imprimir barra horizonal:
    for(int i = 1; i <= numColumnas*dist_columnas; i++)
        printf("-");
    printf("\n");

    //Imprimir nombres de carreras con sus respectivos codigos.
    //Se imprimen en numColumnas columnas, cada columna distanciada
    //en dist_columnas espacios:
    for(int i = 1; i <= numCarreras; i++)
    {
        obtener_nombre_carrera(nom_carrera, i);
        printf("<%d> %s", i, nom_carrera);
        tam_nom = strlen(nom_carrera);

        //Imprimir los espacios que faltan para llegar a la otra columna:
        for(int i = 1; i <= dist_columnas - tam_nom; i++)
            printf(" ");

        if(i % numColumnas == 0)
            printf("\n");
    }
    printf("\n");

    //Imprimir barra horizontal:
    for(int i = 1; i <= numColumnas*dist_columnas; i++)
        printf("-");
    printf("\n");
}

//(B) Retorna 1 si encunetra un ingresante dentro de lis cuyo dni
//sea 'dni'. Retorna 0 en caso contrario.  En caso de que lo encuentre,
//el cursor de la lista queda apuntando al ingresante buscado.
int busca_ingresante_dni(Lista_ingresante* lis, int dni)
{
    reset(lis);
    while(!isOos(*lis))
    {
        Ingresante ingre = copiar(*lis);
        if (ver_documento(ingre) == dni)
            return 1;
        adelante(lis);
    }
    return 0;
}

//(B) Retorna 1 si encunetra un ingresante dentro de lis cuyo numero de inscripcion
//sea 'num_inscripcion'. Retorna 0 en caso contrario. En caso de que lo encuentre,
//el cursor de la lista queda apuntando al ingresante buscado.
int busca_ingresante_inscripcion(Lista_ingresante* lis, int num_inscripcion)
{
    reset(lis);
    while(!isOos(*lis))
    {
        Ingresante ingre = copiar(*lis);
        if (ver_inscripcion(ingre) == num_inscripcion)
            return 1;
        adelante(lis);
    }
    return 0;
}

// Si dni no esta entre 1000000 y 99999999, imprime un cartel
// de advertencia y retorna 0. Devuelve 1 en caso contrario:
int controlar_dni(int dni, Lista_ingresante lis)
{
    if(dni >= 1000000 && dni <= 99999999)
    {
        if(busca_ingresante_dni(&lis, dni) == 1)
        {
            titilar_pantalla_rojo();
            printf("Error: Ya se encuentra inscripto un ingresante con dni %d.\n", dni);
            printf("Ingrese el dni nuevamente:\n");
            return 0;
        }
        else
            return 1;
    }
    titilar_pantalla_rojo();
    printf("Error: El dni que acaba de ingresar no es un numero entre 1000000 y 99999999.\n");
    printf("Ingrese el dni nuevamente:\n");
    return 0;
}

// Si encuentra un caracter que no sea una letra en nombre[], imprime un cartel
// de advertencia y retorna 0.
// Devuelve 1 en caso contrario.
 int controlar_nombre(char nombre[], int tamArr)
 {
     int i;
     for(i = 0; i < tamArr; i++)
     {
         if(isalpha(nombre[i]) == 0 && nombre[i] != ' ')
        {
            titilar_pantalla_rojo();
            printf("Error: El nombre de los ingresantes no puede contener caracteres que no sean letras.\n");
            printf("Ingrese el nombre nuevamente:\n");
            return 0;
        }
     }
     return 1;
 }

// Si encuentra un caracter que no sea una letra en apellido[], imprime un cartel
// de advertencia y retorna 0.
// Devuelve 1 en caso contrario.
 int controlar_apellido(char apellido[], int tamArr)
 {
     int i;
     for(i = 0; i < tamArr; i++)
     {
         if(isalpha(apellido[i]) == 0 && apellido[i] != ' ')
        {
            titilar_pantalla_rojo();
            printf("Error: El apellido de los ingresantes no puede contener caracteres que no sean letras.\n");
            printf("Ingrese el apellido nuevamente:\n");
            return 0;
        }
     }
     return 1;
 }

//Retorna 0 e imprime un cartel de advertencia si:
//   El codigo pais de cel no tiene 2 o 3 digitos.
//   El codigo provincia de cel no tiene entre 2 y 4 digitos.
//   El numero de celular  no tiene 6 digitos.
//Retorna 1 si no ocurre ninguno de estos tres casos.
int controlar_celular(Celular cel)
{
    if(ver_cod_pais(cel) < 10 || ver_cod_pais(cel) > 999)
    {
        titilar_pantalla_rojo();
        printf("Error: el codigo pais debe estar entre 10 y 999.\n");
        printf("Intente nuevamente:\n");
        return 0;
    }
    else if (ver_cod_provincia(cel) < 10 || ver_cod_provincia(cel) > 9999)
    {
        titilar_pantalla_rojo();
        printf("Error: el codigo provincia debe estar entre 10 y 9999.\n");
        printf("Intente nuevamente:\n");
        return 0;
    }
    else if (ver_num_celular(cel) < 100000 || ver_num_celular(cel) > 999999)
    {
        titilar_pantalla_rojo();
        printf("Error: el numero de celular debe tener 6 digitos.\n");
        printf("Intente nuevamente:\n");
        return 0;
    }
    return 1;
}

//Si cod_carrera esta fuera de rango o corresponde a Fotografia, imprime un
//cartel de advertencia y devuelve 0. Devuelve 1 en caso contrario:
int controlar_carrera(int cod_carrera)
{
    if((cod_carrera < 1 || cod_carrera > numCarreras) && cod_carrera !=  cod_terminar_input)
    {
        titilar_pantalla_rojo();
        printf("Error: No existe una carrera con codigo <%d>.\n", cod_carrera);
        printf("Intente nuevamente:\n");
        return 0;
    }
    else if(cod_carrera == 23) //Si el codigo corresponde a Fotografia
    {
        titilar_pantalla_rojo();
        printf("Error: No puede inscribirse a la carrera de Fotografia en 2021.\n");
        printf("Elija otra carrera:\n");
        return 0;
    }
    return 1;
}

//Solicita al usuario el dni de ingre y guarda el dato en la estructura:
void pedir_dni_ingresante(Ingresante* ingre, Lista_ingresante lis)
{
    int dni;
    printf("Ingrese el numero de dni. ");
    printf("(Debe ser un numero entre 1000000 y 99999999)\n");
    do
    {
        printf("> ");
        scanf("%d", &dni);
    }while(controlar_dni(dni, lis) != 1);
    titilar_pantalla_verde();
    carga_documento(ingre, dni);
}

//Solicita al usuario el nombre de ingre y guarda el dato en la estructura:
void pedir_nombre_ingresante(Ingresante* ingre)
{
    char nom[max_chars];
    printf("Ingrese el nombre: (No puede contener numeros o caracteres especiales)\n");
    do
    {
        printf("> ");
        fflush(stdin);
        scanf("%29[^\n]s", nom);
        fflush(stdin);
    }while(controlar_nombre(nom, strlen(nom)) != 1);
    titilar_pantalla_verde();
    carga_nombre(ingre, nom);
}

//Solicita al usuario el apellido de ingre y guarda el dato en la estructura:
void pedir_apellido_ingresante(Ingresante* ingre)
{
    char ape[max_chars];
    printf("Ingrese el apellido: (No puede contener numeros o caracteres especiales)\n");
    do
    {
        printf("> ");
        fflush(stdin);
        scanf("%29[^\n]s", ape);
        fflush(stdin);
    }while(controlar_apellido(ape, strlen(ape)) != 1);
    titilar_pantalla_verde();
    carga_apellido(ingre, ape);
}

//Solocita al usuario las carreras a las cual quiere inscribirse ingre y guarda los datos en la estructura:
void pedir_carreras_ingresante(Ingresante* ingre)
{
    int cant_carreras = 0; //Cuenta en cuantas carreras se va inscribiendo ingre.
    int cod_carrera; //Utilizada para guardar el input del usuario.
    char nom_carrera[max_chars];

    imprimir_carreras_disponibles();
    printf("Ingrese los codigos de las carreras a las cuales quiere inscribirse.\n");
    printf("Ingrese el codigo '%d' para terminar de inscribirse.\n", cod_terminar_input);
   do
    {
        printf("> ");
        scanf("%d", &cod_carrera);
        if(controlar_carrera(cod_carrera) == 1 && cod_carrera != cod_terminar_input)
        {
            titilar_pantalla_verde();
            cant_carreras++;
            obtener_nombre_carrera(nom_carrera, cod_carrera);
            printf("Se inscribio en la carrera: %s\n", nom_carrera);
            carga_carrera(ingre, cod_carrera-1);
        }
        if(cod_carrera == cod_terminar_input && cant_carreras == 0)
        {
            titilar_pantalla_rojo();
            printf("Error: Debe inscribirse en al menos una carrera.\n");
        }
    }
    while(cod_carrera != cod_terminar_input || cant_carreras == 0);
    titilar_pantalla_verde();
}

//Solocita al usuario el numero de celular de ingre y guarda los datos en la estructura:
void pedir_celular_ingresante(Ingresante* ingre)
{
    int cod_pais, cod_provincia, num_celular;
    Celular cel;
    iniciar_celular(&cel);
    do
    {
        printf("Ingrese caracteristica pais de su celular:\n> ");
        scanf("%d", &cod_pais);
        titilar_pantalla_verde();
        printf("Ingrese caracteristica provincia de su celular:\n> ");
        scanf("%d", &cod_provincia);
        titilar_pantalla_verde();
        printf("Ingrese teminacion de su celular:\n> ");
        scanf("%d", &num_celular);
        carga_cod_pais(&cel ,cod_pais);
        carga_cod_provincia(&cel ,cod_provincia);
        carga_num_celular(&cel, num_celular);
    }while(controlar_celular(cel) != 1);
    titilar_pantalla_verde();
    carga_celular(ingre, cel);
}

//Pregunta al usuario si ingre aprobo o no el ingreso y guarda el dato en la estructura:
void pedir_ingreso_ingresante(Ingresante* ingre)
{
    char respuesta_ingreso;
    do
    {
        printf("¿El alumno aprobo el ingreso? (S/N):\n> ");
        fflush(stdin);
        scanf("%c", &respuesta_ingreso);
        fflush(stdin);
        if(respuesta_ingreso != 's' && respuesta_ingreso != 'S' && respuesta_ingreso != 'n' && respuesta_ingreso != 'N')
            titilar_pantalla_rojo();
    }while(respuesta_ingreso != 's' && respuesta_ingreso != 'S' && respuesta_ingreso != 'n' && respuesta_ingreso != 'N');
    titilar_pantalla_verde();
    if(respuesta_ingreso == 's' || respuesta_ingreso == 'S')
        modificar_ingreso(ingre, cod_ingreso_aprobado);
    else
        modificar_ingreso(ingre, cod_ingreso_desaprobado);
}

//Pregunta al usuario si ingre entrego los papeles. Devuelve 's' si la respuesta es si y 'n' en caso contrario:
char pedir_papeles_ingresante(Ingresante* ingre)
{
    char respuesta_papeles;
    do
    {
        printf("¿El alumno entrego los papeles? (S/N):\n> ");
        fflush(stdin);
        scanf(" %c", &respuesta_papeles);
        fflush(stdin);
        if(respuesta_papeles != 's' && respuesta_papeles != 'S' && respuesta_papeles != 'n' && respuesta_papeles != 'N')
            titilar_pantalla_rojo();
    }while(respuesta_papeles != 's' && respuesta_papeles != 'S' && respuesta_papeles != 'n' && respuesta_papeles != 'N');
    titilar_pantalla_verde();
    return respuesta_papeles;
}

//Llama a las funciones pedi_ingreso_ingresante() y pedir_papeles_ingresante().
//Si ingre aprobo el ingreso y entrego los papeles, su estado es inscripto.
//Si ingre aprobo el ingreso y no entrego los papeles, su estado es aspirante.
//Si ingre no aprobo el ingreso y entrego los papeles, su estadp es aspirante.
//Si ingre no aprobo el ingreso y no entrego los papeles, su estado es pre inscripto.
void pedir_estado_ingresante(Ingresante* ingre)
{
    char respuesta_papeles;
    pedir_ingreso_ingresante(ingre);
    respuesta_papeles = pedir_papeles_ingresante(ingre);
    if(ver_ingreso(*ingre) == cod_ingreso_aprobado)
    {
        if(respuesta_papeles == 's' || respuesta_papeles == 'S')
            modificarEstado(ingre, cod_inscripto);
        else
            modificarEstado(ingre, cod_aspirante);
    }
    else
    {
        if(respuesta_papeles == 's' || respuesta_papeles == 'S')
            modificarEstado(ingre, cod_aspirante);
        else
            modificarEstado(ingre, cod_pre_inscripto);
    }
}

//(A) Solicita al usuario informacion de n ingresantes y los inserta en lis
//    Imprime un cartel de advertencia en caso de que lis este llena:
void carga_n_ingresantes(Lista_ingresante *lis, int n)
{
    /*
    int num_aleatorio = rand();
    while(busca_ingresante_inscripcion(lis, num_aleatorio == 1)
            num_aleatorio = rand();
    */

    int i;
    for (i = 0; i < n; i++)
    {
        if(isFull(*lis) == 1)
        {
            titilar_pantalla_rojo();
            printf("Error: la lista está llena y no podemos ingresar mas datos.\n");
            printf("Suprima a un estudiante del sistema.\n");
            return;
        }
        //Controlar que el numero de inscripcion no se repita:
        int num_aleatorio = rand();
        while(busca_ingresante_inscripcion(lis, num_aleatorio) == 1)
        {
            num_aleatorio = rand();
        }

        char nombre_estado[max_chars];
        Ingresante ingre;
        inicializar_ingresante(&ingre, num_aleatorio);
        printf("Ingrese los datos del ingresante %d:\n", i+1);
        pedir_dni_ingresante(&ingre, *lis);
        pedir_nombre_ingresante(&ingre);
        pedir_apellido_ingresante(&ingre);
        pedir_carreras_ingresante(&ingre);
        pedir_celular_ingresante(&ingre);
        pedir_estado_ingresante(&ingre);
        obtener_nombre_estado(nombre_estado, ver_estado(ingre));
        printf("El nuevo estado del alumno es: %s\n", nombre_estado);
        printf("El numero de inscripcion del alumno es: %d\n", ver_inscripcion(ingre));
        printf("Los datos del alumno con dni %d se han cargado correctamente.\n", ver_documento(ingre));
        if(isOos(*lis) == 0)
            adelante(lis);
        insertar(lis, ingre);
    }
    printf("La carga de ingresantes se ha realizado con exito.\n");
}

//Imprime en out todos los datos de ingre:
void ver_un_ingresante(Ingresante ingre, FILE* out)
{
    char nom_carrera[max_chars];
    char nom_estado[max_chars];
    int *arr_carreras;
    Celular cel;
    int i;

    obtener_nombre_estado(nom_estado, ver_estado(ingre));
    cel = ver_celular(ingre);
    arr_carreras = ver_carreras(ingre);

    fprintf(out, "------------------------------------------------\n");
    fprintf(out, "Numero de inscripcion: %d\n", ver_inscripcion(ingre));
    fprintf(out, "Nombre:   %s\n", ver_nombre(ingre));
    fprintf(out, "Apellido: %s\n", ver_apellido(ingre));
    fprintf(out, "DNI:      %d\n", ver_documento(ingre));
    fprintf(out, "Carreras:\n");

    for(i = 0; i < numCarreras; i++)
    {
        if(arr_carreras[i] == 1)
        {
            obtener_nombre_carrera(nom_carrera, i + 1);
            fprintf(out, "  <%d> %s\n", i + 1, nom_carrera);
        }
    }
    if(ver_ingreso(ingre) == cod_ingreso_aprobado)
        fprintf(out, "Aprobo ingreso? Si\n");
    else
        fprintf(out, "Aprobo ingreso? No\n");
    fprintf(out, "Estado: %s\n", nom_estado);
    fprintf(out, "Celular: %d+%d%d\n", ver_cod_pais(cel), ver_cod_provincia(cel), ver_num_celular(cel));
    fprintf(out, "------------------------------------------------\n\n");
}

//Solicita al usuario el dni o numero de inscripcion del ingresante que quiere buscar.
//Si busca_ingresante_dni() o busca_ingresante_inscripcion() encuntra al alumno,
//copia sus datos en ingre y retorna 1.
//Retorna 0 en caso contrario de que no lo encuentre.
int obtener_ingresante_buscado(Ingresante* ingre, Lista_ingresante* lis)
{
    char operacion;
    int num, res_busqueda;
    printf("Ingrese <1> si quiere buscar al ingresante por dni y <2> si quiere buscarlo por numero de inscripcion.\n");
    do
    {
        printf("> ");
        fflush(stdin);
        scanf(" %c", &operacion);
        fflush(stdin);
        switch(operacion)
        {
        case '1':
            titilar_pantalla_verde();
            printf("Ingrese el dni:\n");
            printf("> ");
            scanf("%d", &num);
            titilar_pantalla_verde();
            res_busqueda = busca_ingresante_dni(lis, num);
            break;
        case '2':
            titilar_pantalla_verde();
            printf("Ingrese el numero de inscripcion:\n");
            printf("> ");
            scanf("%d", &num);
            titilar_pantalla_verde();
            res_busqueda = busca_ingresante_inscripcion(lis, num);
            break;
        default:
            titilar_pantalla_rojo();
        }
    }while(operacion != '1' && operacion != '2');
    if(res_busqueda == 1)
        *ingre = copiar(*lis);
    return res_busqueda;
}

//(C) Muestra los datos de un ingresante buscado por dni o numero de inscripcion:
void muestra_ingresante_buscado(Lista_ingresante lis)
{
    Ingresante ingre;
    if(obtener_ingresante_buscado(&ingre, &lis) == 1)
        ver_un_ingresante(ingre, stdout);
    else
        printf("No fue posible encontrar el ingresante\n");
}

//(D) Muestra todos los ingresantes de una carrera determinada:
//La funcion asume que lis no esta vacia.
void muestra_ingresantes_carrera(Lista_ingresante lis)
{
    int contador = 0;
    int cod_carrera;
    int *arr_carreras;
    char nom_carrera[max_chars];
    Ingresante ingre;

    imprimir_carreras_disponibles();
    printf("Ingrese una carrera y mostrare a los ingresantes inscriptos en ella.\n");
    do
    {
        printf("> ");
        scanf("%d", &cod_carrera);
    }while(controlar_carrera(cod_carrera) != 1);
    titilar_pantalla_verde();
    obtener_nombre_carrera(nom_carrera, cod_carrera);

    printf("Los ingresantes inscriptos en %s son:\n\n", nom_carrera);
    reset(&lis);
    while(isOos(lis) == 0)
    {
        ingre = copiar(lis);
        arr_carreras = ver_carreras(ingre);
        if(arr_carreras == NULL)
        {
            printf("Error en muestra_ingresantes_carrera(): arr_carreras no tiene asignada memoria.\n");
            exit(1);
        }
        if(arr_carreras[cod_carrera-1] == 1)
        {
            contador++;
            printf("DNI: %d\n", ver_documento(ingre));
            printf("Nombre: %s\n", ver_nombre(ingre));
            printf("Apellido: %s\n\n", ver_apellido(ingre));
        }
        adelante(&lis);
        free((void*)arr_carreras);
    }
    if(contador == 0)
        printf("No se han encontrado alumnos de %s.\n", nom_carrera);
}

//(E) Muestra todos los ingresantes dentro de lis.
// La funcion asume que lis no esta vacia.
void muestra_lista(Lista_ingresante lis)
{
    reset(&lis);
    while(isOos(lis) == 0)
    {
        Ingresante ingre;
        ingre = copiar(lis);
        ver_un_ingresante(ingre, stdout);
        adelante(&lis);
    }
}

//(F) Busca a un alumno mediante obtener_ingresante_buscado() y llama a la funcion pedir_estado_ingresante()
//para actualizar sus datos.
// La funcion asume que lis no esta vacia.
void modificar_ingreso_estado(Lista_ingresante* lis)
{
    Ingresante ingre;
    char nombre_estado[max_chars];
    inicializar_ingresante(&ingre, 0);

    if(obtener_ingresante_buscado(&ingre, lis) == 0)
    {
        printf("No hemos encontrado al ingresante solicitado.\n");
        return;
    }
    pedir_estado_ingresante(&ingre);
    obtener_nombre_estado(nombre_estado, ver_estado(ingre));
    printf("El nuevo estado del alumno es: %s\n", nombre_estado);

    borrar(lis);
    insertar(lis, ingre);
    printf("Los datos se modificaron con exito.\n");
}

//(G) Busca a un alumno mediante obtener_ingresante_buscado() y lo inscribe en alguna carrera.
// La funcion asume que lis no esta vacia.
void inscribe_en_carrera(Lista_ingresante* lis)
{
    Ingresante ingre;
    int cod_carrera;
    char nombre_carrera[max_chars];
    int* arr_carreras;
    inicializar_ingresante(&ingre, 0);

    if(obtener_ingresante_buscado(&ingre, lis) == 0)
    {
        printf("No hemos encontrado al ingresante solicitado.\n");
        return;
    }
    arr_carreras = ver_carreras(ingre);
    if(arr_carreras == NULL)
    {
        printf("Error en inscribir_encarrera(): arr_carreras no tiene asignada memoria.\n");
        exit(1);
    }

    imprimir_carreras_disponibles();
    printf("Ingrese la carrera a la que quiere inscribirse: (Ingrese una sola carrera)\n");
    do
    {
        printf("> ");
        scanf("%d", &cod_carrera);
    }while(controlar_carrera(cod_carrera) != 1);
    titilar_pantalla_verde();

    obtener_nombre_carrera(nombre_carrera, cod_carrera);
    if(arr_carreras[cod_carrera-1] == 1)
        printf("Ya estaba inscripto en la carrera %s.\n", nombre_carrera);
    else
    {
        printf("Se inscribio satisfactoriamente en la carrera %s.\n", nombre_carrera);
        modificarCarrera(&ingre, cod_carrera-1, 1);
        borrar(lis);
        insertar(lis, ingre);
    }
    free((void*)arr_carreras);
}

//(H) Busca a un alumno mediante obtener_ingresante_buscado() y borra su inscripcion en alguna carrera.
//La funcion asume que lis no esta vacia. En caso de que el alumno no quede inscripto en alguna carrera
//lo borra de la lista.
void borrar_inscripcion(Lista_ingresante* lis)
{
    int cod_carrera, contador_inscriptas = 0,i;
    Ingresante ingre;
    char nom_carrera[max_chars];
    int* arr_carreras;
    inicializar_ingresante(&ingre, 0);

    if(obtener_ingresante_buscado(&ingre, lis) == 0)
    {
        printf("No hemos encontrado al ingresante solicitado.\n");
        return;
    }

    ingre = copiar(*lis);
    arr_carreras = ver_carreras(ingre);
    if(arr_carreras == NULL)
    {
        printf("Error en inscribir(): arr_carreras no tiene asignada memoria.\n");
        exit(1);
    }

    printf("Las carreras en la cual el alumno esta inscripto son:\n");
    for(i = 0; i < numCarreras; i++)
    {
        if(arr_carreras[i] == 1)
        {
            obtener_nombre_carrera(nom_carrera, i+1);
            printf("    <%d> %s\n", i+1, nom_carrera);
            contador_inscriptas++;
        }
    }

    printf("Ingrese la carrera que quiere borrar.\n");
    printf("Presione <%d> para borrar todas las inscripciones.\n", cod_terminar_input);
    printf("Advertencia: si el alumno no queda inscripto en alguna carrera lo borraremos del sistema.\n");
    do
    {
        printf("> ");
        scanf("%d", &cod_carrera);
        if((cod_carrera < 1 || cod_carrera > 23) && cod_carrera != cod_terminar_input)
            titilar_pantalla_rojo();
    }while((cod_carrera < 1 || cod_carrera > 23) && cod_carrera != cod_terminar_input);
    titilar_pantalla_verde();

    if(cod_carrera != cod_terminar_input)
    {
        obtener_nombre_carrera(nom_carrera, cod_carrera);
        if(arr_carreras[cod_carrera-1] == 0)
            printf("No estaba inscripto en la carrera %s.\n", nom_carrera);
        else
        {
            printf("Borro su inscripcion de la carrera %s.\n", nom_carrera);
            modificarCarrera(&ingre, cod_carrera-1, 0);
            contador_inscriptas--;
        }
    }

    borrar(lis);
    if(contador_inscriptas > 0 && cod_carrera != cod_terminar_input)
    {
        insertar(lis, ingre);
        printf("Se modificaron los datos satisfactoriamente.\n");
    }
    else
        printf("Se borro al alumno del sistema.\n");

    free((void*)arr_carreras);
}

//contador[0] es el contador de aspirantes en la carrera con codigo 1.
//contador[5] es el contador de aspirantes en la carrera con codigo 6.

//(I) Calcular la cantidad de ingresantes por carrera que aún están en el estado de aspirante
void contar_aspirantes(Lista_ingresante lis)
{
    int aspirante_encontrado = 0,i;
    char nom_carrera[max_chars];
    int contador[numCarreras];
    for(i = 0; i < numCarreras; i++)
        contador[i] = 0;

    reset(&lis);
    while(!isOos(lis))
    {
        Ingresante ingre = copiar(lis);
        int* arr_carreras = ver_carreras(ingre);
        if(ver_estado(ingre) == cod_aspirante)
        {
            aspirante_encontrado = 1;
            for(i = 0; i < numCarreras; i++)
            {
                if(arr_carreras[i] == 1)
                    contador[i]++;
            }
        }
        adelante(&lis);
    }

    for(i = 0; i < numCarreras; i++)
    {
        if(contador[i] > 0)
        {
            obtener_nombre_carrera(nom_carrera, i+1);
            printf("%s: %d\n", nom_carrera, contador[i]);
        }
    }
    if(aspirante_encontrado == 0)
        printf("No se han encontrado aspirantes en ninguna carrera.\n");
}

//(J) Muestra los datos de ingresantes que aprobaron el ingreso de una carrera dada (realizar en forma recursiva).
// La funcion asume que lis no esta vacia y que cod_carrera es correcto.
void muestra_aprobados_carrera(Lista_ingresante lis, Ingresante ingre, int* arr_carrera, int cod_carrera)
{
    if(isOos(lis) == 1)
    {
        printf("La muestra de datos se ha efectuado correctamente.\n");
        return;
    }
    ingre = copiar(lis);
    arr_carrera = ver_carreras(ingre);
    if(arr_carrera == NULL)
    {
        printf("Error en mostrar_aprobados_carrera(); arr_carrera no tiene asignada memoria.\n");
        exit(1);
    }
    if(arr_carrera[cod_carrera - 1] == 1 && ver_ingreso(ingre) == cod_ingreso_aprobado)
        ver_un_ingresante(ingre, stdout);
    adelante(&lis);
    free((void*)arr_carrera);
    muestra_aprobados_carrera(lis, ingre, arr_carrera, cod_carrera);
}

//Funcion auxiliar que se invoca antes de utilizar muestra_aprobados_carrera():
void preludio_muestra_aprobados(Lista_ingresante lis)
{
    Ingresante ingre;
    int cod_carrera;
    char nom_carrera[max_chars];
    int* arr_carrera;

    imprimir_carreras_disponibles();
    printf("Ingrese una carrera:\n");
    do
    {
        printf("> ");
        scanf("%d", &cod_carrera);
    }while(controlar_carrera(cod_carrera) != 1);
    titilar_pantalla_verde();
    obtener_nombre_carrera(nom_carrera, cod_carrera);
    printf("Los alumnos de %s que aprobaron el ingreso son:\n", nom_carrera);
    reset(&lis);
    muestra_aprobados_carrera(lis, ingre, arr_carrera, cod_carrera);
}

//(K)almacenar en un archivo nombre, apellido, dni, carreras y celular de los ingresantes que pasan al TFA
//(son aquellos que no aprobaron el ingreso). La funcion asume que lis no esta vacia.
void almacena_archivo_tfa(Lista_ingresante lis)
{
    FILE* archivo_salida;
    char nombre_archivo[max_chars];
    char respuesta_archivo;
    int contador_tfa = 0;

    printf("Ingrese el nombre del archivo donde quiere almacenar los datos:\n");
    scanf("%29[^\n]s", nombre_archivo);
    titilar_pantalla_verde();
    do
    {
        printf("¿En caso de que el archivo exista, quiere borrar la informacion dentro de %s\n", nombre_archivo);
        printf("antes de copiar los nuevos datos? (S/N)\n> ");
        fflush(stdin);
        scanf(" %c", &respuesta_archivo);
        fflush(stdin);
        if(respuesta_archivo != 's' && respuesta_archivo != 'S' && respuesta_archivo != 'n' && respuesta_archivo != 'N')
            titilar_pantalla_rojo();
    }while(respuesta_archivo != 's' && respuesta_archivo != 'S' && respuesta_archivo != 'n' && respuesta_archivo != 'N');
    titilar_pantalla_verde();

    if(respuesta_archivo == 's' || respuesta_archivo == 'S')
        archivo_salida = fopen(nombre_archivo, "w");
    else
        archivo_salida = fopen(nombre_archivo, "a");
    if(archivo_salida == NULL)
    {
        titilar_pantalla_rojo();
        printf("Error: no pudimos abrir el archivo %s.\n", nombre_archivo);
        return;
    }

    reset(&lis);
    while(!isOos(lis))
    {
        Ingresante ingre = copiar(lis);
        if(ver_ingreso(ingre) == cod_ingreso_desaprobado)
        {
            contador_tfa++;
            ver_un_ingresante(ingre, archivo_salida);
        }
        adelante(&lis);
    }
    if(contador_tfa == 0)
        printf("No hay alumnos que hayan desaprobado el ingreso.\n");
    else
        printf("Los datos se copiaron satisfactoriamente.\n");
    fclose(archivo_salida);
}

void calcular_estado(Ingresante* ingre, int respuesta_ingreso, int respuesta_papeles)
{
    if(respuesta_ingreso == 1)
    {
        modificar_ingreso(ingre, cod_ingreso_aprobado);
        if(respuesta_papeles == 1)
            modificarEstado(ingre, cod_inscripto);
        else
            modificarEstado(ingre, cod_aspirante);
    }
    else
    {
        modificar_ingreso(ingre, cod_ingreso_desaprobado);
        if(respuesta_papeles == 1)
            modificarEstado(ingre, cod_aspirante);
        else
            modificarEstado(ingre, cod_pre_inscripto);
    }
}

void leer_de_archivo(Lista_ingresante *l)
{
    int i;
    FILE* f;
    char nom[max_chars];
    printf("Ingrese el nombre del archivo de lectura:\n> ");
    scanf("%s", nom);
    f = fopen(nom, "r");
    if(f == NULL)
    {
        titilar_pantalla_rojo();
        printf("Error: no existe el archivo %s.\n", nom);
        return;
    }
    titilar_pantalla_verde();
    rewind(f);
    while(!feof(f))
    {
        Ingresante ingre;
        inicializar_ingresante(&ingre, rand());

        int dni, cod_pais, cod_prov, num_celular, respuesta_ingre, respuesta_pape;
        char nom[max_chars], ape[max_chars];
        Celular cel;

        fscanf(f, "%s %s %d", nom, ape, &dni);
        for(i  = 0; i < numCarreras; i++)
        {
            int n;
            fscanf(f, "%d", &n);
            modificarCarrera(&ingre, i, n);
        }
        fscanf(f, "%d %d %d %d %d", &cod_pais, &cod_prov, &num_celular, &respuesta_ingre, &respuesta_pape);

        carga_documento(&ingre, dni);
        carga_nombre(&ingre, nom);
        carga_apellido(&ingre, ape);
        carga_cod_pais(&cel, cod_pais);
        carga_cod_provincia(&cel, cod_prov);
        carga_num_celular(&cel, num_celular);
        carga_celular(&ingre, cel);
        calcular_estado(&ingre, respuesta_ingre, respuesta_pape);
        insertar(l, ingre);
    }
    fclose(f);
    //borrar(l); //trucazo
    printf("La carga se realizo con exito.\n");
}

//Imprime en pantalla todas las operaciones que puede realizar el usuario.
void imprime_menu_opciones()
{
    printf("Las operaciones disponibles son las siguientes:\n");
    printf("    <0> Para cargar n ingresantes.\n");
    printf("    <1> Para mostrar los datos de un ingresante buscado por dni o numero de inscripcion.\n");
    printf("    <2> Para mostrar todos los ingresantes de alguna carrera.\n");
    printf("    <3> Para mostrar todos los ingresantes del sistema.\n");
    printf("    <4> Para modificar el estado de un ingresante.\n"); //
    printf("    <5> Para inscribir a algun alumno en una carrera.\n");
    printf("    <6> Para borrar inscripcion a carrera de un ingresante.\n");
    printf("    <7> Para calcular cantidad de aspirantes por carrera.\n");
    printf("    <8> Para mostrar los datos de ingresantes que aprobaron el ingreso de una carrera dada.\n");
    printf("    <9> Para imprimir en un archivo los ingresantes que pasan al TFA.\n");
    printf("    <l> Para leer ingresantes desde archivo\n"); //
    printf("    <m> Para mostrar el menu.\n");
    printf("    <X> Para salir del programa.\n");
}

void iniciar_sesion()
{
    char pass[max_chars];

    printf("-----------------------------------------------------\nBienvenido al sistema de administracion de la FCFMyN.\n-----------------------------------------------------\n");
    printf("*Usuario: Administrador.\n");
    do
    {
        printf("*Ingrese la contrasena: ");
        scanf("%s", pass);
        if(strcmp(pass, "disfruta") != 0)
        {
            titilar_pantalla_rojo();
            printf("\nLa contrasena ingresada es incorrecta, por favor reintente.\n\n");
        }
    }while(strcmp(pass, "disfruta") != 0);
    titilar_pantalla_verde();
    printf("\nIniciando sesion (Administrador) ......");
    system("PAUSE");
    printf("\n\n");
}

int main()
{
     srand(time(NULL));
     int n;
     char operacion;
     Lista_ingresante lis;
     init(&lis);

     iniciar_sesion();
     imprime_menu_opciones();
     do
     {
         printf("Ingrese una operacion. (<m> para ver menu de opciones)\n");
         printf("> ");
         fflush(stdin);
         scanf(" %c", &operacion);
         fflush(stdin);
         switch(operacion)
         {
         case '0':
             titilar_pantalla_verde();
             printf("Ingrese la cantidad de ingresantes que quiere cargar.\n");
             do
             {
                printf("> ");
                scanf("%d", &n);
                if(n < 1)
                    titilar_pantalla_rojo();
             }while(n < 1);
             titilar_pantalla_verde();
             carga_n_ingresantes(&lis, n);
             break;
         case '1':
            if(isEmpty(lis) == 0)
            {
                titilar_pantalla_verde();
                muestra_ingresante_buscado(lis);
            }
            else
            {
                titilar_pantalla_rojo();
                printf("Error: El sistema no tiene cargado alumnos.\n");
            }
            break;
         case '2':
            if(isEmpty(lis) == 0)
            {
                titilar_pantalla_verde();
                muestra_ingresantes_carrera(lis);
            }
            else
            {
                titilar_pantalla_rojo();
                printf("Error: El sistema no tiene cargado alumnos.\n");
            }
            break;
         case '3':
             if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 printf("Los ingresantes cargados en el sistema son:\n");
                 muestra_lista(lis);
             }
             else
             {
                 titilar_pantalla_rojo();
                 printf("Error: El sistema no tiene cargado alumnos.\n");
             }
             break;
        case '4':
             if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 modificar_ingreso_estado(&lis);
             }
             else
             {
                 titilar_pantalla_rojo();
                 printf("Error: El sistema no tiene cargado alumnos.\n");
             }
             break;
         case '5':
            if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 inscribe_en_carrera(&lis);
             }
             else
             {
                 titilar_pantalla_rojo();
                 printf("Error: El sistema no tiene cargado alumnos.\n");
             }
             break;
         case '6':
            if(isEmpty(lis) == 0)
            {
                titilar_pantalla_verde();
                borrar_inscripcion(&lis);
            }
            else
            {
                titilar_pantalla_rojo();
                printf("Error: El sistema no tiene cargado alumnos.\n");
            }
            break;
         case '7':
             if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 printf("La cantidad de aspirantes por carrera son:\n");
                 contar_aspirantes(lis);
             }
             else
             {
                titilar_pantalla_rojo();
                printf("Error: El sistema no tiene cargado alumnos.\n");
             }
             break;
         case '8':
            if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 preludio_muestra_aprobados(lis);
             }
             else
             {
                titilar_pantalla_rojo();
                printf("Error: El sistema no tiene cargado alumnos.\n");
             }
            break;
         case '9':
             if(isEmpty(lis) == 0)
             {
                 titilar_pantalla_verde();
                 almacena_archivo_tfa(lis);
             }
             else
             {
                 titilar_pantalla_rojo();
                 printf("Error: El sistema no tiene cargado alumnos.\n");
             }
             break;
         case 'l':
            titilar_pantalla_verde();
            leer_de_archivo(&lis);
            break;
         case 'm':
            titilar_pantalla_verde();
            imprime_menu_opciones();
            break;
         case 'X':
            titilar_pantalla_verde();
            printf("Gracias por usar el programa.\n");
            break;
         default:
            titilar_pantalla_rojo();
            printf("Error: no reconocemos la operacion %c.\n", operacion);
         }
     }while(operacion != 'X');
}
