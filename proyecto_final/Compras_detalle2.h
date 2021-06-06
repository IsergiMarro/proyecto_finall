#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Compras_detalle.h"
using namespace std;
class Compras_detalle2 : Compras_detalle
{
public:
	Compras_detalle2() {
	}
	Compras_detalle2(string idCo, string  idpr, string CT, string po_u) : Compras_detalle(idCo, idpr, CT, po_u) {
	}
	void setIDCOMP(string idCo) { id_compra = idCo; }
	void setIDPRIDUC(string idpr) { id_producto = idpr; }
	void setCaTiDaD(string CT) { cantidad = CT; }
	void setPrECI_co_UN(string po_u) { precio_costo_unitario = po_u; }

	string getIDCOMP() { return id_compra; }
	string getIDPRIDUC() { return id_producto; }
	string getCaTiDaD() { return cantidad; }
	string getPrECI_co_UN() { return precio_costo_unitario; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras_detalle(id_compra,id_producto,cantidad,precio_costo_unitario) VALUES ('" + id_compra + "','" + id_producto + "','" + cantidad + "','" + precio_costo_unitario + "')";
			const char* j= insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), j);
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

			cout << "------------ Datos de compras detalle ------------" << endl;
			string consulta = "select * from compras_detalle";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
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

