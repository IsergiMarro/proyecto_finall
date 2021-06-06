#pragma once
#include <iostream>
using namespace std;
class Ventas
{
	// atributos
protected: string nofactura, serie, fechafactura, fechaIngreso;
		 int telefono = 0;
		 // costructor
protected:
	Ventas() {
	}
	Ventas(string nf, string se, string ff, string fg) {
		nofactura = nf;
		serie = se;
		fechafactura = ff;
		fechaIngreso = fg;
		
	}
};


