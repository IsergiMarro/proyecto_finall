#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Ventas_Detalle.h"
class Ventas_Detalle2 :  Ventas_Detalle
{
public:
	Ventas_Detalle2() {
	}
	Ventas_Detalle2(string IV, string IDP, string CD, string PU) : Ventas_Detalle(IV, IDP, CD, PU) {
	}
	// METODOS
	//set (modificar)
	void setID_veNta(string IV) { id_venta = IV; }
	void setID_PRODUC(string IDP) { id_producto = IDP; }
	void setCANTIdad(string CD) { cantidad = CD; }
	void setPRECIO_unitario(string PU) { precio_unitario = PU; }
	//get (mostrar)
	string getID_veNta() { return  id_venta; }
	string getID_PRODUC() { return id_producto; }
	string getCANTIdad() { return cantidad; }
	string getPRECIO_unitario() { return precio_unitario; }
	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas_detalle(id_venta,id_producto,cantidad,precio_unitario ) VALUES ('" + id_venta + "','" + id_producto + "','" + cantidad + "','" + precio_unitario + "')";
			const char* w = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), w);
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
			string consulta = "select * from ventas_detalle";
			const char* w = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), w);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] <<  endl;
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


