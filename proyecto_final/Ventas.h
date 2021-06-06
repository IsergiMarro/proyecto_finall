#pragma once
#include <iostream>
using namespace std;
class Ventas
{
	// atributos
protected: string nofactura, serie, fechafactura, id_cliente, fechaIngreso;
		 // costructor
protected:
	Ventas() {
	}
	Ventas(string nf, string se, string ff, string idc, string FI) {
		nofactura = nf;
		serie = se;
		fechafactura = ff;
		id_cliente = idc;
		fechaIngreso = FI;
	}
};


