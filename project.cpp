#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <locale> // Para usar caracteres especiales
#include <fstream>
#include <filesystem> //agregado por problemas de rutas
using namespace std;


// Estructuras
struct Venta
{
	string nombre_producto;
	float precio_producto;
	int cantidad_producto;
	float monto_producto;
};

struct Boleta
{
	Venta productos[10];
	float monto_total;
};

struct Clientes
{
	string nombre;
	string DNI;
	Boleta historial[10];
};

struct Productos
{
	string nombre;
	string codigo;
	string tipo;
	float precio;
	int stock;
};
struct Global
{
	Venta venta[100];
	Boleta boleta[100];
	Clientes cliente[100];
	Productos producto[100];
} g;

// Prototipos


int mostrarMenu(const string& archivo);
int solicitarCantidad();
char menuMediosPago();
void revisarCarritoDeCompras(Global global);
void MnClntReg();
void MnEscgrProd(Venta *PreProducto, int &PosProd);
void MnLimp(Venta *PreProducto, int &PosProd);
void MnTec(Venta *PreProducto, int &PosProd);
void MnHog(Venta *PreProducto, int &PosProd);
void MnVerd(Venta *PreProducto, int &PosProd);
void MnFrut(Venta *PreProducto, int &PosProd);

// Prototipos Menu
//int administracion(Global &G);
void mostrar_boleta(int b, Global G);
// Funcion principal

int main()
{

	setlocale(LC_CTYPE, "Spanish");




	g.cliente[0].nombre = "jack zavaleta";
	g.cliente[1].nombre = "luis miguel";
	g.cliente[0].DNI = "71157781";
	g.cliente[1].DNI = "09056371";

	g.cliente[0].historial[0].productos[0].nombre_producto = "atun";
	g.cliente[0].historial[0].productos[0].precio_producto = 134;
	g.cliente[0].historial[0].productos[0].cantidad_producto = 12;
	g.cliente[0].historial[0].productos[0].monto_producto = 1608;

	g.cliente[0].historial[0].productos[1].nombre_producto = "melocoton";
	g.cliente[0].historial[0].productos[1].precio_producto = 135;
	g.cliente[0].historial[0].productos[1].cantidad_producto = 12;
	g.cliente[0].historial[0].productos[1].monto_producto = 1620;

	g.cliente[0].historial[0].monto_total = 3228;

	g.cliente[0].historial[1].productos[0].nombre_producto = "Naranjas";
	g.cliente[0].historial[1].productos[0].precio_producto = 21;
	g.cliente[0].historial[1].productos[0].cantidad_producto = 5;
	g.cliente[0].historial[1].productos[0].monto_producto = 125;

	g.cliente[0].historial[1].productos[1].nombre_producto = "toronjas";
	g.cliente[0].historial[1].productos[1].precio_producto = 100;
	g.cliente[0].historial[1].productos[1].cantidad_producto = 5;
	g.cliente[0].historial[1].productos[1].monto_producto = 500;

	g.cliente[0].historial[1].monto_total = 625;

	g.cliente[1].historial[0].productos[0].nombre_producto = "cerezas";
	g.cliente[1].historial[0].productos[0].precio_producto = 15;
	g.cliente[1].historial[0].productos[0].cantidad_producto = 5;
	g.cliente[1].historial[0].productos[0].monto_producto = 75;

	g.cliente[1].historial[0].productos[1].nombre_producto = "limon";
	g.cliente[1].historial[0].productos[1].precio_producto = 12;
	g.cliente[1].historial[0].productos[1].cantidad_producto = 100;
	g.cliente[1].historial[0].productos[1].monto_producto = 1200;

	g.cliente[1].historial[0].monto_total = 1275;

	g.cliente[1].historial[1].productos[0].nombre_producto = "pizza";
	g.cliente[1].historial[1].productos[0].precio_producto = 50;
	g.cliente[1].historial[1].productos[0].cantidad_producto = 5;
	g.cliente[1].historial[1].productos[0].monto_producto = 250;

	g.cliente[1].historial[1].productos[0].nombre_producto = "tumama";
	g.cliente[1].historial[1].productos[0].precio_producto = 100;
	g.cliente[1].historial[1].productos[0].cantidad_producto = 5;
	g.cliente[1].historial[1].productos[0].monto_producto = 500;

	g.cliente[1].historial[1].monto_total = 750;

	g.producto[0].nombre = "atun";
	g.producto[0].codigo = "0506";
	g.producto[0].tipo = "conserva";
	g.producto[0].precio = 134;
	g.producto[0].stock = 39;

	g.producto[1].nombre = "limon";
	g.producto[1].codigo = "0055";
	g.producto[1].tipo = "fruta";
	g.producto[1].precio = 12;
	g.producto[1].stock = 36;

	g.producto[2].nombre = "tumama";
	g.producto[2].codigo = "0505";
	g.producto[2].tipo = "qqq";
	g.producto[2].precio = 39;
	g.producto[2].stock = 39;

	// PRUEBA MENU DE ZAVALETA

	cout << "\n\n\nPrueba Zavaleta\n\n";

	int valor = 1, a = 0, opc;
	do
	{
		cout << "-------------Digite la opcion----------";
		cout << "\n\n1.- Clientes";
		cout << "\n2.- Administracion\n";
		cin >> opc;

		if (opc == 1 or opc == 2)
		{
			if (opc == 1)
			{
				cout << "\n\nmasblablabla";
				MnClntReg();
			}
			else
			{
				do
				{
					system("cls");
					

					if (valor == 1)
					{
						a = 1;
					}

				} while (valor == 0);
			}
		}
		else
		{
			a = 1;
		}
	} while (a == 1);
}

// Menu cliente registrado

void MnClntReg()
{

	int Opc, PosProd;

	Venta PreProducto[10];

	do
	{
		switch (mostrarMenu("../archivos/menuClntReg.txt"))
		{
		case 1:
			MnEscgrProd(PreProducto, PosProd);
			break;
		case 2:
			revisarCarritoDeCompras(g);
			break;
		case 3:

			break;
		case 4:
			Opc = 4;
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
		system("pause");
		system("cls");
	} while (Opc != 4);
}

int solicitarCantidad()
{
    int cantidad;
    cout << "\n Ingrese la cantidad que desea de este producto: ";
    cin >> cantidad;
    return cantidad;
}


void escogerProducto(Global g, string archivo, int& varCliente){

	g.venta[0].nombre_producto = "atun";
	g.venta[0].cantidad_producto = 12;

}

void MnEscgrProd(Venta *PreProducto, int &PosProd)
{

	int Opc;
	PosProd = 0;

	do
	{
		switch (mostrarMenu("../archivos/menuEscgrProd.txt"))
		{
		case 1:
			MnLimp(PreProducto, PosProd);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			Opc = 7;
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
		system("pause");
		system("cls");
	} while (Opc != 7);
}

void MnLimp(Venta *PreProducto, int &PosProd)
{

	int Opc;

	do
	{
		switch (mostrarMenu("../archivos/menuLimpieza.txt"))
		{
		case 1:
			PreProducto[PosProd].nombre_producto = "Set Escoba";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 2:
			PreProducto[PosProd].nombre_producto = "Desinfectante 1Lt";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 3:
			PreProducto[PosProd].nombre_producto = "Paños Reutilizables";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "Papel Higiénico";
			cout << "\n Ingrese la cantidad que desea de este producto:";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 5:
			PreProducto[PosProd].nombre_producto = "Papel Toalla";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 6:
			PreProducto[PosProd].nombre_producto = "Set Trapeador";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 7:
			PreProducto[PosProd].nombre_producto = "Guantes de Latex";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 8:
			Opc = 8;
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (Opc != 8);
}

void MnTec(Venta *PreProducto, int &PosProd)
{
	do
	{

		switch (mostrarMenu("../archivos/menuTecnologia.txt"))
		{
		case 1:
			PreProducto[PosProd].nombre_producto = "Laptop Gamer Asus";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 2:
			PreProducto[PosProd].nombre_producto = "Celular Android LG";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 3:
			PreProducto[PosProd].nombre_producto = "SmartTV Samsung";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "Tablet Samsung";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 5:
			PreProducto[PosProd].nombre_producto = "Set Gamer(Teclado, mouse y mousepad)";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 6:
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (true);
}

void MnHog(Venta *PreProducto, int &PosProd)
{

	int Opc;

	do
	{

		switch (mostrarMenu("../archivos/menuHogar.txt"))
		{
		case 1:
			PreProducto[PosProd].nombre_producto = "Set Utensilios de Cocina";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 2:
			PreProducto[PosProd].nombre_producto = "Set Ventiladores de Techo";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 3:
			PreProducto[PosProd].nombre_producto = "Silla Escritorio";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "Repisa de madera";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 5:
			PreProducto[PosProd].nombre_producto = "Juego de Comedor(4 sillas 1 mesa)";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 6:
			PreProducto[PosProd].nombre_producto = "Ropero";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 7:
			PreProducto[PosProd].nombre_producto = "Cama de 2 plazas";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 8:
			PreProducto[PosProd].nombre_producto = "Juego de Sofas";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 9:
			Opc = 9;
			break;
		default:
			cout << "\n Opciónn inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (Opc != 9);
}

void MnVerd(Venta *PreProducto, int &PosProd)
{

	int Opc;

	do
	{

		switch (mostrarMenu("../archivos/menuVerduras.txt"))
		{
		case 1:
			PreProducto[PosProd].nombre_producto = "1kg Cebolla";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 2:
			PreProducto[PosProd].nombre_producto = "Unid. Lechuga";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 3:
			PreProducto[PosProd].nombre_producto = "1kg. Tomate";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "Unid. Aguacate";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 5:
			PreProducto[PosProd].nombre_producto = "1kg. Papa";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 6:
			PreProducto[PosProd].nombre_producto = "1kg. Zanahoria";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 7:
			PreProducto[PosProd].nombre_producto = "Unid. Calabaza";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 8:
			PreProducto[PosProd].nombre_producto = "Unid. Pepino";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 9:
			PreProducto[PosProd].nombre_producto = "Unid. Pimiento";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 10:
			PreProducto[PosProd].nombre_producto = "1kg. Limón";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 11:
			Opc = 11;
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (Opc != 11);
}

void MnFrut(Venta *PreProducto, int &PosProd)
{

	int Opc;

	do
	{
		switch (mostrarMenu("../archivos/menuFrutas.txt"))
		{
		case 1:
			PreProducto[PosProd].nombre_producto = "Mano de Platanos";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 2:
			PreProducto[PosProd].nombre_producto = "1kg. Manzana";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 3:
			PreProducto[PosProd].nombre_producto = "1kg. Fresas";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "1kg. Uva";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 5:
			PreProducto[PosProd].nombre_producto = "1kg. Naranja";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 6:
			PreProducto[PosProd].nombre_producto = "Unid Sandía";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 7:
			PreProducto[PosProd].nombre_producto = "1kg. Mango";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 8:
			PreProducto[PosProd].nombre_producto = "1kg. Mandarina";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 9:
			PreProducto[PosProd].nombre_producto = "1kg. Manzana";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 10:
			PreProducto[PosProd].nombre_producto = "Unid. Piña";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 11:
			Opc = 11;
			break;
		default:
			cout << "\n Opción inválida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (Opc != 11);
}

// Revisar carrito de compras

void revisarCarritoDeCompras(Global global)
{
	cout << "Carrito de compras" << endl;
	cout << "------------------" << endl;
	cout << "Producto   "
		 << "Cantidad  "
		 << "Precio    " << endl;
	for (int i = 0; i < 50; i++)
	{
		if (global.venta[i].nombre_producto == "")
		{
			break;
		}
		cout << global.venta[i].nombre_producto << "      " << global.venta[i].cantidad_producto << "         " << global.venta[i].precio_producto << endl;
	}
}

// Realizar compra

// Menu Administrador

int menu_adm_1()
{

	int opc;

	do
	{
		cout << "-------------Digite la opcion----------";
		cout << "\n\n1.- Reporte de Boletas";
		cout << "\n2.- Reporte de Producto";
		cout << "\n3.- Modifinar Producto";
		cout << "\n4.- Agregar Producto";
		cout << "\n5.- Eliminar Producto";
		cout << "\n6.- Retornar Menu Principal";
		cout << "\n7.- Salir del programa\n";
		cout <<"Digite una opcion:";

		cin >> opc;

		if (opc > 7 or opc < 1)
		{
			cout << "\nOpcion Invalidad\n";
		}
		else
		{
			break;
		}

	} while (true);

	return opc;
}

void mostrar_boleta(int b, Global G)
{

	for (int i = 0; i < 100; i++)
	{
		system("cls");
		if (G.cliente[b - 1].historial[i].monto_total == 0)
		{
			system("cls");
			cout << "-------------El cliente no tiene mas boletas-------------";
			break;
		}
		cout << "----------------Boleta de Venta---------------" << endl;
		cout << "-----------------------------------------------" << endl
			 << "\n\n\n";
		cout << "Nombre de Cliente  : " << G.cliente[b - 1].nombre << "      DNI: " << G.cliente[b - 1].DNI << "\n\n";
		cout << "Producto              "
			 << "Cantidad             "
			 << "Precio               "
			 << "            IMPORTE " << endl;
		for (int j = 0; j < 100; j++)
		{
			if (G.cliente[b - 1].historial[i].productos[j].nombre_producto == "")
			{

				break;
			}
			cout << G.cliente[b - 1].historial[i].productos[j].nombre_producto << "                 " << G.cliente[b - 1].historial[i].productos[j].precio_producto << "                    " << G.cliente[b - 1].historial[i].productos[j].cantidad_producto << "                 " << G.cliente[b - 1].historial[i].productos[j].monto_producto << endl;
		}
		cout << "                      "
			 << "                      "
			 << "           TOTAL:    " << G.cliente[b - 1].historial[i].monto_total << endl;
		system("pause");
	}

}
//Muestra cualquier menu solo con pasarle archivos con ruta relativa
int mostrarMenu(const string& archivo)
{
    int Opc;
    ifstream menuFile(archivo);

    if (menuFile.is_open())
    {
        string line;
        while (getline(menuFile, line))
        {
            cout << line << endl;
        }

        menuFile.close();
    }
    else
    {
        cout << "Error al abrir el archivo!" << endl;
    }

    cout << "\nDigite su elección: ";
    cin >> Opc;

    return Opc;
}

// Funcion de medios de pago

char menuMediosPago()
{
	cout << "Seleccione un medio de pago:" << endl;
	cout << "1. Medios de pago en efectivo:" << endl;
	cout << "   a. Efectivo (moneda nacional)" << endl;
	cout << "   b. Moneda extranjera" << endl;
	cout << "2. Tarjetas bancarias:" << endl;
	cout << "   a. Tarjeta bancaria (crédito o débito)" << endl;
	cout << "   b. Tarjeta online (pagos electr?nicos)" << endl;
	cout << "3. Vales y tarjetas de beneficios:" << endl;
	cout << "   a. Vale escolar" << endl;
	cout << "   b. Vale de mercader?a" << endl;
	cout << "   c. Vale de alimento" << endl;

	char opcion;
	cout << "Ingrese la opci?n deseada: ";
	cin >> opcion;

	return opcion;
}
