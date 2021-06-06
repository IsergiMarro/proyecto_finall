#pragma once
#include <iostream>
using namespace std;
class Compras
{
protected: string no_orden_compra, id_proveedor, fecha_orden, fechaingreso;
protected:
	Compras() {
	}
	Compras(string Nor, string IV, string FEO, string FG) {
		no_orden_compra = Nor;
		id_proveedor = IV;
		fecha_orden = FEO;
		fechaingreso = FG;
	}
};

