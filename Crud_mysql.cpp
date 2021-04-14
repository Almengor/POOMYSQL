// Crud_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<mysql.h>
#include "Cliente.h"
#include <iostream>
using namespace  std;

int main()
{
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << "Ingrese Nit:";
	getline(cin, nit);
	cout << "Ingrese Nombres:";
	getline(cin, nombres);
	cout << "Ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;

	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

	c.crear();
	c.leer();
	c.modificar();
	c.eliminar();

	system("pause");
	return 0;
}