#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Ventas.h"
using namespace std;
class VENTAS2 : Ventas
{
public:
	VENTAS2() {
	}
	VENTAS2(string nf, string se, string ff, string idc,string FI) : Ventas(nf, se, ff, idc,FI) {

	}
	// METODOS
	//set (modificar)
	void setNOFACTURA(string nf) { nofactura = nf; }
	void setSERIE(string se) { serie = se; }
	void setFeCHAFACTURA(string ff) { fechafactura = ff; }
	void serID_CLIENTE(string idc) { id_cliente = idc; }
	void setFECHAINGRESO(string FI) { fechaIngreso = FI; }
	

	//get (mostrar)
	string getNOFACTURA() { return nofactura; }
	string getSERIE() { return serie; }
	string getFeCHAFACTURA() { return fechafactura; }
	string getID_CLIENTE() { return id_cliente; }
	string getFECHAINGRESO() { return fechaIngreso; }
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()){
			string insertar = "INSERT INTO ventas(nofactura,serie,fechafactura,id_cliente,fechaIngreso) VALUES ('" + nofactura + "','" + serie + "','" + fechafactura + "','" + id_cliente +"','"+ fechaIngreso +"')";
			const char* b = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), b);
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

		cout << "------------ Datos de Maestro detalle de ventas ------------" << endl;
		string consulta = "select * from ventas";
		const char* b = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(),b );
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << endl;
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

