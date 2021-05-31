#pragma once
#include <iostream>
using namespace std;
class Persona
{
	// atributos
protected: string nombres, apellidos, genero, correo_electronico, fechaingreso;
		 int telefono = 0;
		 // costructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string gen, int tel, string ce ,string fi) {
		nombres = nom;
		apellidos = ape;
		genero = gen;
		telefono = tel;
		correo_electronico = ce;
		fechaingreso = fi;
	}
};

