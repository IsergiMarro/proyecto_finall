#include "Cliente.h"
#include <iostream>
#include <string>
using namespace  std;

int main()
{

	string nombres, apellidos, nit, genero, correo_electronico, fechaingreso;
	int telefono;
	cout << "ingrese Nombres:";
	getline(cin, nombres);
	cout << "ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "ingrese Nit:";
	getline(cin, nit);
	cout << "ingrese Genero:";
	getline(cin, genero);
	cout << "ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese Correo_Electronico:";
	getline(cin, correo_electronico);
	cout << "ingrese Fecha_Ingreso:";
	getline(cin, fechaingreso);

	Cliente c = Cliente(nombres,apellidos,genero,telefono,correo_electronico,fechaingreso,nit);

	c.crear();
	c.leer();

	system("pause");
	return 0;

}