#pragma once
#include <iostream>
using namespace std;
class Compras_detalle
{
protected: string id_compra, id_producto, cantidad, precio_costo_unitario;
protected:
	Compras_detalle() {
}
		 Compras_detalle(string idCo, string  idpr, string CT, string po_u) {
			 id_compra = idCo;
			 id_producto = idpr;
			 cantidad = CT;
			 precio_costo_unitario = po_u;
	}
};

