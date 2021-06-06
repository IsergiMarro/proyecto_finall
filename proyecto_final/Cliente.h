#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Persona.h"
#include <string>
using namespace std;
class Cliente : Persona
{
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string gen, string tel, string ce, string fi, string n) : Persona(nom, ape, gen, tel, ce, fi) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setGenero(string gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo_Electronico(string ce) { correo_electronico = ce; }
	void setFecha_Ingreso(string fi) { fechaingreso = fi; }
	void setNit(string n) { nit = n; }
	//get (mostrar)
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getCorreo_Electronico() { return correo_electronico; }
	string getFecha_Ingreso() { fechaingreso; }
	string getNit() { return nit; }


	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "'," + telefono + ",'" + correo_electronico + "','" + fechaingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};
