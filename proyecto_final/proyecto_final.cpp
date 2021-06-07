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
#include <fstream>
using namespace  std;

int main()
{
	{
		int opcion;
		bool repetir = true;
		int inicio = 0;

		string Nombres, Apellidos, Genero, Telefono, Correo_Electronico, Fecha_Ingreso, Nit;
		Cliente c;
		string nofactura, serie, fechafactura, id_cliente, fechaIngreso;
		VENTAS2 b;
		string ID_veNta, ID_PRODUC, CANTIdad, PRECIO_unitario;
		Ventas_Detalle2 W;
		string puesto;
		Puestos2 z;
		string nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fechaingreso;
		Empleado2 e;
		string MARCAS;
		Marcas2 x;
		string PRoducto, ID_Marca, DeScripcion, IMagen, PerciO_Costo, PrecIo_Venta, ExisTencia, FechaInGresO;
		Productos2 h;
		string NO_ORDEN_CO, ID_PROveedor, FECHA_ORD, FECHAin;
		Compras2 a;
		string IDCOMP, IDPRIDUC, CaTiDaD, PrECI_co_UN;
		Compras_detalle2 j;
		string PROVEdor, NiT, DIRECCION, TELEfono;
		Proveedores2 d;
		do {
			cout << "Menu de Opciones" << endl;
			cout << "1. tabla Clintes" << endl;
			cout << "2. tabla Maestro detalle de ventas" << endl;
			cout << "3. tabla puestos" << endl;
			cout << "4. tabla empleados" << endl;
			cout << "5. tabla Marcas" << endl;
			cout << "6. tabla productos " << endl;
			cout << "7. tabla Maestro detalle de compras" << endl;
			cout << "8. tabla Proveedores " << endl;
			cout << "0. SALIR" << endl;

			cout << "Ingrese una opcion: ";
			cin >> opcion;
			switch (opcion) {
			case 1:
				cout << "ingrese Nombres:";
				cin >> Nombres;
				cout << "ingrese Apellidos:";
				cin >> Apellidos;
				cout << "ingrese Nit:";
				cin >> Nit;
				cout << "ingrese Genero : ";
				cin >> Genero;
				cout << "ingrese Telefono:";
				cin >> Telefono;
				cout << "ingrese Correo_Electronico:";
				cin >> Correo_Electronico;
				cout << "ingrese Fecha_Ingreso:";
				cin >> Fecha_Ingreso;
				c = Cliente(Nombres, Apellidos, Genero, Telefono, Correo_Electronico, Fecha_Ingreso, Nit);
				c.crear();
				c.leer();
				system("pause");
				break;
			    case 2:
				cout << "ingrese NO. de factura:";
				cin >> nofactura;
				cout << "ingrese serie:";
				cin >> serie;
				cout << "ingrese la fecha de factura : ";
				cin >> fechafactura;
				cout << "ingrese el ID del cliente:";
				cin >> id_cliente;
				cout << "ingrese el fecha de ingrese:";
				cin >> fechaIngreso;
				//ventas detalle
				cout << "ingrese el NO VENTAS:";
				cin >> ID_veNta;
				cout << "ingrese NO DE PRDUCTO:";
				cin >> ID_PRODUC;
				cout << "ingrese la CANTIDAD:";
				cin >> CANTIdad;
				cout << "ingrese nombre PRECIO POR UNIDAD :";
				cin >> PRECIO_unitario;
				b = VENTAS2(nofactura, serie, fechafactura, id_cliente, fechaIngreso);
				b.crear();
				b.leer();
				W = Ventas_Detalle2(ID_veNta, ID_PRODUC, CANTIdad, PRECIO_unitario);
				W.crear();
				W.leer();
				system("pause");
				break;
			    case 3:
				cout << "ingrese Puesto:";
				getline(cin, puesto);
				cin >> puesto;
				z = Puestos2(puesto);
				z.crear();
				z.leer();
				system("pause");
			    case 4:
				cout << "ingrese Nombre del empledado:";
				cin >> nombres;
				cout << "ingrese Apellidos del empleado:";
				cin >> apellidos;
				cout << "ingrese direccion del empleado:";
				cin >> direccion;
				cout << "ingrese Telefono del empleado:";
				cin >> telefono;
				cout << "ingrese el dpi del empleado:";
				cin >> dpi;
				cout << "ingrese Genero:";
				cin >> genero;
				cout << "ingrese la fecha de nacimiento del empleado:";
				cin >> fecha_nacimiento;
				cout << "ingrese el ID Puesto:";
				cin >> id_puesto;
				cout << "ingrese el la fecha de inicio de labores:";
				cin >> fecha_inicio_labores;
				cout << "ingrese la fecha de ingresio del empleado:";
				cin >> fechaingreso;
				e = Empleado2(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fechaingreso);
				e.crear();
				e.leer();
				system("pause");
			    case 5:
				cout << "ingrese Marcas:";
				cin >> MARCAS;
				x = Marcas2(MARCAS);
				x.crear();
				x.leer();
				system("pause");
				break;
			    case 6:
				cout << "ingrese productos:";
				cin >> PRoducto;
				cout << "ingrese ID_Marcas:";
				cin >> ID_Marca;
				cout << "ingrese la descripcion:";
				cin >> DeScripcion;
				cout << "ingrese nombre de la imagen :";
				cin >> IMagen;
				cout << "ingrese percio costo:";
				cin >> PerciO_Costo;
				cout << "ingrese percio ventas:";
				cin >> PrecIo_Venta;
				cout << "ingrese existencia:";
				cin >> ExisTencia;
				cout << "ingrese fecha de ingreso:";
				cin >> FechaInGresO;
				h = Productos2(PRoducto, ID_Marca, DeScripcion, IMagen, PerciO_Costo, PrecIo_Venta, ExisTencia, FechaInGresO);
				h.crear();
				h.leer();
				system("pause");
			    case 7:
				cout << "ingrese el NO.orden:";
				cin >> NO_ORDEN_CO;
				cout << "ingrese NO.Proveedor:";
				cin >> ID_PROveedor;
				cout << "ingrese fecha de orden:";
				cin >> FECHA_ORD;
				cout << "ingrese fecha de ingreso :";
				cin >> FECHAin;
				///compras detalle
				cout << "ingrese el id compra:";
				cin >> IDCOMP;
				cout << "ingrese el id producto:";
				cin >> IDPRIDUC;
				cout << "ingrese la cantidad:";
				cin >> CaTiDaD;
				cout << "ingrese el precio unitario:";
				cin >> PrECI_co_UN;
				a = Compras2(NO_ORDEN_CO, ID_PROveedor, FECHA_ORD, FECHAin);
				a.crear();
				a.leer();
				j = Compras_detalle2(IDCOMP, IDPRIDUC, CaTiDaD, PrECI_co_UN);
				j.crear();
				j.leer();
				system("pause");
			    case 8:
				string PROVEdor, NiT, DIRECCION, TELEfono;
				cout << "ingrese el provedor:";
				cin >> PROVEdor;
				cout << "ingrese el NIT:";
				cin >> NiT;
				cout << "ingrese LA DIRECCION:";
				cin >> DIRECCION;
				cout << "ingrese el telefono :";
				cin >> TELEfono;
				d = Proveedores2(PROVEdor, NiT, DIRECCION, TELEfono);
				d.crear();
				d.leer();
				system("pause");
			}
		} while (repetir);
		return 0;
	}
}