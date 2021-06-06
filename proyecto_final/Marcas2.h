#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Marcas.h"
using namespace std;
class Marcas2 : Marcas
{
	//constructor
public:
	Marcas2() {
	}
	Marcas2(string MA) : Marcas(MA) {
	}
	//metodos
	//set
	void setMARCAS(string MA) { marca = MA; }
	//get
	string getMARCAS() { return marca; }
	//metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO marcas(marca) VALUES ('" + marca + "')";
			const char* x = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), x);
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
			string consulta = "select * from marcas";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
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

