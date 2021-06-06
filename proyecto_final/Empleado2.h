#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Empleado.h"
#include <string>
using namespace std;
class Empleado2 : Empleado
{
public:
	Empleado2() {
	}
	Empleado2(string no, string ap, string dic, string tf, string pi, string ge, string fc, string id_p, string FIL, string IF) : Empleado(no, ap, dic, tf, pi, ge, fc, id_p, FIL, IF) {
	}
	//METODOS
	//SET (MODIFICAR)
	void setNOMBRES(string no) { nombres = no; }
	void setAPELLIDOS(string ap) { apellidos = ap; }
	void setDireccion(string dic) { direccion = dic;}
	void setTelefono(string tf) { telefono = tf; }
	void setDPI(string pi) { dpi = pi; }
	void setGENERO(string ge) { genero = ge; }
	void setFECHA_NACIMINTO(string fc) { fecha_nacimiento = fc; }
	void setID_PUESTO(string id_p) { id_puesto = id_p;}
	void setFECHA_INICIO_LABORES(string FIL) { fecha_inicio_labores = FIL;}
	void setFECHAINGRESO(string IF) { fechaingreso = IF; }
	//Get 
	string getNOMBRES() { return nombres; }
	string getAPELLIDOS() { return apellidos; }
	string getDireccion() { return direccion; }
	string getTelefono() { return  telefono; }
	string getDPI() { return dpi; }
	string getGENERO(){ return genero; }
	string getFECHA_NACIMINTO() { return fecha_nacimiento; }
	string getID_PUESTO() { return id_puesto; }
	string getFECHA_INICIO_LABORES() { return fecha_inicio_labores; }
	string getFECHAINGRESO() { return fechaingreso; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_labores,fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "'," + dpi + ",'" + genero + "','" + fecha_nacimiento + "','" + id_puesto + "','" + fecha_inicio_labores + "','" + fechaingreso + "')";
			const char* e = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), e);
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
			string consulta = "select * from empleados";
			const char* e = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << endl;
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

