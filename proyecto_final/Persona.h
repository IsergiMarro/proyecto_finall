#pragma once
#include <iostream>
using namespace std;
class Persona
{
	// atributos
protected: string nombres, apellidos, genero, telefono, correo_electronico, fechaingreso;
		 // costructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string gen, string tel, string ce ,string fi) {
		nombres = nom;
		apellidos = ape;
		genero = gen;
		telefono = tel;
		correo_electronico = ce;
		fechaingreso = fi;
	}
};

