#pragma once
#include <iostream>
using namespace std;
class Proveedores
{
protected: string proveedor, nit, direccion, telefono;
protected:
	Proveedores() {
	}
	Proveedores(string PVD, string N, string drr, string cel) {
		proveedor = PVD;
		nit = N;
		direccion = drr;
		telefono = cel;
	}
};

