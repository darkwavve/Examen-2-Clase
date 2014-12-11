#include "Lista.h"
#include "ArbolTrinario.h"
#include "Evaluador.h"
#include <fstream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

//1 a realizar estan ubicados en el archivo Lista.h

float obtenerPromedio(std::list<float> mi_lista)
{
    int cont = 0;
    float valor = 0;
    float total = 0;

    for(list<float>::iterator i = mi_lista.begin();
        i != mi_lista.end();
        i++)
        {
            valor += *i;
            cont++;
        }

        total = valor / cont;

        return total;
}

int obtenerMediana(std::vector<int> mi_vector)
{
    int  num = ((mi_vector.size()/2) + 0.5);
    std::sort(mi_vector.begin(),mi_vector.end());
    return mi_vector[num];
}

bool existeEnArchivo(string nombre_archivo, string cadena)
{
    ifstream in (nombre_archivo.c_str());
    string txt;
    while (in >> txt)
    {
        if(txt == cadena)
            return true;
    }

    return false;
}

char obtenerUltimaLetra(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    char c;
    while(in >> c)
    {
    }
    return c;
}

int contarEnArbol(NodoTrinario* raiz, int num)
{
    int cont = 0;
    if(raiz == NULL)
        return 0;

    if(raiz->num == num)
        cont++;

    if(contarEnArbol(raiz->der, num) > 0)
        cont += contarEnArbol(raiz->der, num);

    if(contarEnArbol(raiz->medio, num) > 0)
        cont += contarEnArbol(raiz->medio, num);

    if(contarEnArbol(raiz->izq, num) > 0)
        cont += contarEnArbol(raiz->izq, num);

    return cont;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

