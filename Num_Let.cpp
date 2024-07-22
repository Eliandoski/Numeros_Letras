//Estudiante: Cifuentes González Elian
//Fecha de entrega: 21/07/2024
//Curso: 1ro de TI

//Programa que transforma un número entero en su equivalente en letras 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Arrays de string que contienen las unidades, decenas y centenas
const string unidades[]={"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Once", "Doce", 
"Trece","Catorce", "Quince", "Dieciséis", "Diecisiete", "Dieciocho", "Diecinueve"};

const string decenas[]{"", "Diez", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa"};

const string centenas[]{"", "Ciento", "Doscientos", "Trescientos", "Cuatrocientos", "Quinientos", "Seiscientos", "Setecientos", "Ochocientos", "Novecientos"};

// Funciones para convertir los números a letras
string GetUnidades(int num)
{
    return unidades[num];
}

//Función para obtener las decenas
string GetDecenas(int num)
{
    int x = num / 10;
    int resto = num % 10;
    string aux = "";

    if(num < 20)
    {
        aux = GetUnidades(num);
    }
    else
    {
        aux = decenas[x];
        aux = resto > 0 ? aux + " y " + GetUnidades(resto): aux;
    }
    return aux;
}

//Función para obtener las centenas
string GetCentenas(int num)
{
    int x = num / 100;
    int resto = num % 100;
    string aux = "";

    if(num < 100)
    {
        aux = GetDecenas(num);
    }
    else
    {
        if (x == 1 && resto == 0)
        {
            aux = "Cien";
        }
        else
        {
            aux = centenas[x];
            aux = resto > 0 ? aux + " " + GetDecenas(resto): aux;
        }
    }
    return aux;
}

//Función para obtener los miles
string GetMiles(int num)
{
    int x = num / 1000;
    int resto = num % 1000;
    string aux = "";

    if(num < 1000)
    {
        aux = GetCentenas(num);
    }
    else
    {
        if (x == 1 && resto == 0)
        {
            aux = "Mil";
        }
        else
        {
            aux = GetCentenas(x) + " Mil";
            aux = resto > 0 ? aux + " " + GetCentenas(resto): aux;
        }
    }
    return aux;
}

//Función para obtener los números en letras
string GetNumeroEnLetras(int num)
{
    int x = num / 1000;
    int resto = num % 1000;
    string aux = "";

    if (num < 1000000)
    {
        if (x == 0)
        {
            aux = GetCentenas(num);
        }
        else
        {
            aux = GetMiles(num);
        }
    }
    return aux;
}

// Función para generar 100 números aleatorios y convertirlos a letras
void GenerarNumerosAleatorios()
{
    srand(time(0)); 
    for (int i = 0; i < 100; i++)
    {
        int numero = rand() % 999999 + 1; 
        string numeroEnLetras = GetNumeroEnLetras(numero);
        cout << numero << ": " << numeroEnLetras << endl;
    }
}

int main()
{
    // Generar 100 números aleatorios y mostrarlos en letras
    cout << "Números Aleatorios en Letras (100 Números):";
    GenerarNumerosAleatorios();

    return 0;
}
