#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Proveedores.h"
using namespace std;
class Proveedores2 : Proveedores
{
private: string nit;
	   // constructor
public:
	Proveedores2() {
	}
	Proveedores2(string PVD, string N , string drr, string cel) :Proveedores(PVD,N,drr,cel) {
		nit = N;
	}
	void setPROVEdor(string PVD) { proveedor = PVD; }
	void setNiT(string N) { nit = N; }
	void setDIRECCION(string drr) { direccion = drr; }
	void setTELEfono(string cel) {telefono = cel; }

	string getPROVEdor() { return proveedor; }
	string getNiT() { return nit; }
	string getDIRECCION() { return direccion; }
	string getTELEfono() { return telefono; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO proveedores(proveedor, nit, direccion ,telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
			const char* d = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), d);
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
		string consulta = "select * from proveedores";
		const char* d = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(), d);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
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


