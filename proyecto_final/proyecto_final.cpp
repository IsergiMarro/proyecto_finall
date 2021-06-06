#include "Cliente.h"
#include "VENTAS2.h"
#include "Puestos2.h"
#include "Empleado2.h"
#include "Marcas2.h"
#include "Productos2.h"
#include "Ventas_Detalle2.h"
#include "Compras2.h"
#include "Proveedores2.h"
#include "Compras_detalle2.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace  std;

int main()
{
	string Nombres, Apellidos, Genero, Telefono, Correo_Electronico, Fecha_Ingreso, Nit;
	cout << "ingrese Nombres:";
	getline(cin, Nombres);
	cout << "ingrese Apellidos:";
	getline(cin, Apellidos);
	cout << "ingrese Nit:";
	getline(cin, Nit);
	cout << "ingrese Genero:";
	getline(cin, Genero);
	cout << "ingrese Telefono:";
	getline(cin, Telefono);
	cout << "ingrese Correo_Electronico:";
	getline(cin, Correo_Electronico);
	cout << "ingrese Fecha_Ingreso:";
	getline(cin, Fecha_Ingreso);
	Cliente c = Cliente(Nombres, Apellidos, Genero, Telefono, Correo_Electronico, Fecha_Ingreso, Nit);
	c.crear();
	c.leer();
	system("pause");
	//ventas
	string nofactura, serie, fechafactura, id_cliente, fechaIngreso;
	cout << "ingrese NO. de factura:";
	getline(cin, nofactura);
	cin.ignore();
	cout << "ingrese serie:";
	getline(cin, serie);
	cin.ignore();
	cout << "ingrese la fecha de factura:";
	getline(cin, fechafactura);
	cin.ignore();
	cout << "ingrese el ID del cliente:";
	getline(cin, id_cliente);
	cin.ignore();
	cout << "ingrese el fecha de ingrese:";
	getline(cin, fechaIngreso);
	cin.ignore();

	VENTAS2 b = VENTAS2(nofactura, serie, fechafactura, id_cliente, fechaIngreso);
	b.crear();
	b.leer();
	system("pause"); 
	//puestos
	string puesto;
	cout << "ingrese Puesto:";
	getline(cin, puesto);
	cin.ignore();
	Puestos2 z = Puestos2(puesto);
	z.crear();
	z.leer();
	system("pause");
	//empleados
	string nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fechaingreso;
	cout << "ingrese Nombre del empledado:";
	getline(cin, nombres);
	cout << "ingrese Apellidos del empleado:";
	getline(cin, apellidos);
	cout << "ingrese direccion del empleado:";
	getline(cin, direccion);
	cout << "ingrese Telefono del empleado:";
	getline(cin, telefono);
	cout << "ingrese el dpi del empleado:";
	getline(cin, dpi);
	cout << "ingrese Genero:";
	getline(cin, genero);
	cout << "ingrese la fecha de nacimiento del empleado:";
	getline(cin, fecha_nacimiento);
	cout << "ingrese el ID Puesto:";
	getline(cin, id_puesto);
	cout << "ingrese el la fecha de inicio de labores:";
	getline(cin, fecha_inicio_labores);
	cout << "ingrese la fecha de ingresio del empleado:";
	getline(cin, fechaingreso);

	Empleado2 e = Empleado2(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fechaingreso);
	e.crear();
	e.leer();
	system("pause");
    //MARCAS
	string MARCAS;
	cout << "ingrese Marcas:";
	getline(cin, MARCAS);
	cin.ignore();
	Marcas2 x = Marcas2(MARCAS);
	x.crear();
	x.leer();
	system("pause");
	//productos 
	string PRoducto, ID_Marca, DeScripcion, IMagen, PerciO_Costo, PrecIo_Venta, ExisTencia, FechaInGresO;
	cout << "ingrese productos:";
	getline(cin, PRoducto);
	cin.ignore();
	cout << "ingrese ID_Marcas:";
	getline(cin, ID_Marca);
	cin.ignore();
	cout << "ingrese la descripcion:";
	getline(cin, DeScripcion);
	cin.ignore();
	cout << "ingrese nombre de la imagen :";
	getline(cin, IMagen);
	cin.ignore();
	cout << "ingrese percio costo:";
	getline(cin, PerciO_Costo);
	cin.ignore();
	cout << "ingrese percio ventas:";
	getline(cin, PrecIo_Venta);
	cin.ignore();
	cout << "ingrese existencia:";
	getline(cin, ExisTencia);
	cin.ignore();
	cout << "ingrese fecha de ingreso:";
	getline(cin, FechaInGresO);
	cin.ignore();
	Productos2 h = Productos2(PRoducto, ID_Marca, DeScripcion, IMagen, PerciO_Costo, PrecIo_Venta, ExisTencia, FechaInGresO);
	h.crear();
	h.leer();
	system("pause");
	//ventas detalle
	string ID_veNta, ID_PRODUC, CANTIdad, PRECIO_unitario;
	cout << "ingrese el NO VENTAS:";
	getline(cin, ID_veNta);
	cin.ignore();
	cout << "ingrese NO DE PRDUCTO:";
	getline(cin, ID_PRODUC);
	cin.ignore();
	cout << "ingrese la CANTIDAD:";
	getline(cin, CANTIdad);
	cin.ignore();
	cout << "ingrese nombre PRECIO POR UNIDAD :";
	getline(cin, PRECIO_unitario);
	cin.ignore();
	Ventas_Detalle2 W = Ventas_Detalle2(ID_veNta, ID_PRODUC, CANTIdad, PRECIO_unitario);
	W.crear();
	W.leer();
	system("pause");
	///compras
	string NO_ORDEN_CO, ID_PROveedor, FECHA_ORD, FECHAin;
	cout << "ingrese el NO.orden:";
	getline(cin, NO_ORDEN_CO);
	cin.ignore();
	cout << "ingrese NO.Proveedor:";
	getline(cin, ID_PROveedor);
	cin.ignore();
	cout << "ingrese fecha de orden:";
	getline(cin, FECHA_ORD);
	cin.ignore();
	cout << "ingrese fecha de ingreso :";
	getline(cin, FECHAin);
	cin.ignore();
	Compras2 a = Compras2(NO_ORDEN_CO, ID_PROveedor, FECHA_ORD, FECHAin);
	a.crear();
	a.leer();
	system("pause");
	//Proveedores
	string PROVEdor, NiT, DIRECCION, TELEfono;
	cout << "ingrese el provedor:";
	getline(cin, PROVEdor);
	cin.ignore();
	cout << "ingrese el NIT:";
	getline(cin, NiT);
	cin.ignore();
	cout << "ingrese LA DIRECCION:";
	getline(cin, DIRECCION);
	cin.ignore();
	cout << "ingrese el telefono :";
	getline(cin, TELEfono);
	cin.ignore();
	Proveedores2 d = Proveedores2(PROVEdor, NiT, DIRECCION, TELEfono);
	d.crear();
	d.leer();
	system("pause");
	//compras detalle
	string IDCOMP, IDPRIDUC, CaTiDaD, PrECI_co_UN;
	cout << "ingrese el id compra:";
	getline(cin, IDCOMP);
	cin.ignore();
	cout << "ingrese el id producto:";
	getline(cin, IDPRIDUC);
	cin.ignore();
	cout << "ingrese la cantidad:";
	getline(cin, CaTiDaD);
	cin.ignore();
	cout << "ingrese el precio unitario:";
	getline(cin, PrECI_co_UN);
	cin.ignore();
	Compras_detalle2 j = Compras_detalle2(IDCOMP, IDPRIDUC, CaTiDaD, PrECI_co_UN);
	j.crear();
	j.leer();
	system("pause");
}