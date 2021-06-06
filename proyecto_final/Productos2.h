#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Productos.h"
using namespace std;
class Productos2 : Productos
{
public:
	Productos2() {
	}
	Productos2(string PD, string IM, string dec, string IMG, string PCO, string PV, string EXIS, string FiG) : Productos(PD, IM, dec, IMG, PCO, PV, EXIS, FiG) {
	}
	//Metodos
	//set
	void setPRoducto(string PD) { producto = PD; }
	void setID_Marca(string IM) { id_marca = IM; }
	void setDeScripcion(string dec) { descripcion = dec; }
	void setIMagen(string IMG) { imagen = IMG; }
	void setPerciO_Costo(string PCO) { percio_costo = PCO; }
	void setPrecIo_Venta(string PV) { precio_venta = PV; }
	void setExisTencia(string EXIS) { existencia = EXIS; }
	void setFechaInGresO(string FiG) { fecha_ingreso = FiG; }
	//get
	string getPRoducto() { return producto; }
	string getID_Marca() { return id_marca; }
	string getDeScripcion() { return descripcion; }
	string getIMagen() { return imagen; }
	string getPerciO_Costo() { return percio_costo; }
	string getPrecIo_Venta() { return precio_venta; }
	string getExisTencia() { return existencia; }
	string getFechaInGresO() { return fecha_ingreso; }
	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,id_marca,descripcion,imagen,percio_costo,precio_venta,existencia,fecha_ingreso ) VALUES ('" + producto + "','" + id_marca + "','" + descripcion + "','" + imagen + "'," + percio_costo + ",'" + precio_venta + "','" + existencia + "','"+ fecha_ingreso +"')";
			const char* h = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), h);
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
			string consulta = "select * from productos";
			const char* h = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), h);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
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
