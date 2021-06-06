#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Puesto.h"
using namespace std;
class Puestos2 : Puesto
{
public:
	Puestos2() {
	}
	Puestos2(string P) : Puesto(P) {
	}
	// METODOS
	//set (modificar)
	void setPUESTO(string P) { puesto = P; }
	//get(mostrar)
	string getPUESTO() { return puesto; }
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
			if (cn.getConectar()) {
				string insertar = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "')";
				const char* z = insertar.c_str();
				// executar el query
				q_estado = mysql_query(cn.getConectar(), z);
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

			cout << "------------ Datos puestos ------------" << endl;
			string consulta = "select * from puestos";
			const char* z = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), z);
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

