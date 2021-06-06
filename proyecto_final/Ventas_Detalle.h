#pragma once
#include <iostream>
using namespace std;
class Ventas_Detalle
{
protected: string id_venta, id_producto, cantidad, precio_unitario;
protected:
	Ventas_Detalle() {
	}
	Ventas_Detalle(string IV, string IDP, string CD, string PU){
		id_venta = IV;
		id_producto = IDP;
		cantidad = CD;
		precio_unitario = PU;
	}   
};

