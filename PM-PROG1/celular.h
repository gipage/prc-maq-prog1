#ifndef CELULAR_H_INCLUDED
#define CELULAR_H_INCLUDED

typedef struct
{
    int cod_pais;
    int cod_provincia;
    int num_celular;
} Celular;

void iniciar_celular(Celular *cel)
{
    (*cel).cod_pais = 0;
    (*cel).cod_provincia = 0;
    (*cel).num_celular=  0;
}
void carga_cod_pais(Celular *cel, int cod)
{
    (*cel).cod_pais = cod;
}

void carga_cod_provincia(Celular *cel, int cod)
{
    (*cel).cod_provincia = cod;
}

void carga_num_celular(Celular *cel, int cod)
{
    (*cel).num_celular = cod;
}

void modificar_cod_pais(Celular *cel, int cod)
{
    (*cel).cod_pais = cod;
}

void modificar_cod_provincia(Celular *cel, int cod)
{
    (*cel).cod_provincia = cod;
}

void modificar_num_celular(Celular *cel, int cod)
{
    (*cel).num_celular = cod;
}

int ver_cod_pais(Celular cel)
{
    return cel.cod_pais;
}

int ver_cod_provincia(Celular cel)
{
    return cel.cod_provincia;
}

int ver_num_celular(Celular cel)
{
    return cel.num_celular;
}

#endif // CELULAR_H_INCLUDED
