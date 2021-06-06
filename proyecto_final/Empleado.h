#pragma once
#include <iostream>
using namespace std;
class Empleado
{
	// atributos
protected: string nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fechaingreso;
		 // costructor
protected:
	Empleado() {
	}
	Empleado(string no, string ap, string dic,string tf, string pi, string ge, string fc, string id_p, string FIL, string IF) {
		nombres = no;
		apellidos = ap;
		direccion = dic;
		telefono  = tf;
		dpi = pi;
		genero = ge;
		fecha_nacimiento = fc;
		id_puesto = id_p;
		fecha_inicio_labores = FIL;
		fechaingreso = IF;
	}
};

