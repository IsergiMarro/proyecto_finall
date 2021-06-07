#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Compras.h"
class Compras2 : Compras
{
public:
	Compras2() {
	}
	Compras2(string Nor, string IV, string FEO, string FG) : Compras(Nor,IV,FEO,FG) {
	}
	void serNO_ORDEN_CO(string Nor) { no_orden_compra = Nor; }
	void setID_PROveedor(string IV) { id_proveedor = IV; }
	void setFECHA_ORD(string IV) { fecha_orden = IV; }
	void setFECHAin(string FG) { fechaingreso = FG; }

	string getNO_ORDEN_CO() { return no_orden_compra; }
	string getID_PROveedor() { return id_proveedor; }
	string getFECHA_ORD() { return fecha_orden; }
	string getFECHAin() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras(no_orden_compra,id_proveedor,fecha_orden,fechaingreso) VALUES ('" + no_orden_compra + "','" + id_proveedor + "','" + fecha_orden + "','" + fechaingreso + "')";
			const char* a = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), a);
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

			cout << "------------ Datos de Maestro detalle de compras ------------" << endl;
			string consulta = "select * from compras";
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

