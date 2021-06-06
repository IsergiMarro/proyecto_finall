#pragma once
#include <iostream>
using namespace std;
class Productos
{
	//atributos
protected:
	string producto, id_marca, descripcion, imagen, percio_costo, precio_venta, existencia, fecha_ingreso;
	// costructor 
protected:
	Productos(){
	}
	Productos(string PD, string IM, string dec, string IMG, string PCO, string PV, string EXIS, string FiG) {
		producto = PD;
		id_marca = IM;
		descripcion = dec;
		imagen = IMG;
		percio_costo = PCO;
		precio_venta = PV;
		existencia = EXIS;
		fecha_ingreso = FiG;
	}
};

