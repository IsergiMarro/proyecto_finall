#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Ventas.h"
#include <string>
#include<iostream>
using namespace std;
class VENTAS2 : Ventas
{
public:
	VENTAS2() {
	}
	VENTAS2(string nf, string se, string ff, string fg) : Ventas(nf, se, ff, fg) {

	}
	// METODOS
	//set (modificar)
	void setNOFACTURA(string nf) { nofactura = nf; }
	void setSERIE(string se) { serie = se; }
	void setFeCHAFACTURA(string ff) { fechafactura = ff; }
	void setFECHAInGRESO(string fg) { fechaIngreso = fg; }
	//get (mostrar)
	string getNOFACTURA() { return nofactura; }
	string getSERIE() { return serie; }
	string getFeCHAFACTURA() { return fechafactura; }
	string getFECHAInGRESO() { return fechaIngreso; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()){
			string insertar = "INSET INTO ventas(nofactura,serie,fechafactura,fechaIngreso)VALUES(('" + nofactura + "','" + serie + "','" + fechafactura + "','" + fechaIngreso + "')";
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

		cout << "------------ Datos de ventas ------------" << endl;
		string consulta = "select * from ventas";
		const char* d = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(),d );
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

