#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <locale>
#include <windows.h>// Para usar caracteres especiales
#include <clocale> // Para usar caracteres especiales
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
}limpieza[10], tecnologia[10], hogar[10], verduras[10], frutas[10];

// Prototipos

string* obtenerStringsEnumerados(const string& nombreArchivo, int& cantidadStrings) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        cantidadStrings = 0;
        return nullptr;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            if (isdigit(linea[0]) && linea.find(".") != string::npos) {
                contador++;
            }
        }
    }

    archivo.clear();
    archivo.seekg(0);

    string* stringsEnumerados = new string[contador];
    int index = 0;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            if (isdigit(linea[0]) && linea.find(".") != string::npos) {
                if (index < contador - 1) {  // Excluir la última línea
                    string substring = linea.substr(linea.find(".") + 1);
                    stringsEnumerados[index] = substring;
                    index++;
                }
            }
        }
    }

    archivo.close();
    cantidadStrings = contador - 1;  // Actualizar la cantidad de strings
    return stringsEnumerados;
}

void cargarProductos();

int mostrarMenu(const string& archivo);
int solicitarCantidad();
char menuMediosPago();
void revisarCarritoDeCompras(Venta *venta);
void MnClntReg();
void MnEscgrProd(Venta *PreProducto, int &PosProd);
void MnLimp(Venta *PreProducto, int &PosProd);
void MnTec(Venta *PreProducto, int &PosProd);
void MnHog(Venta *PreProducto, int &PosProd);
void MnVerd(Venta *PreProducto, int &PosProd);
void MnFrut(Venta *PreProducto, int &PosProd);

// Prototipos Menu
//int administracion(Global &G);
//void mostrar_boleta(int b, Global G);
int menu_adm_1();
// Funcion principal

int main()
{

	SetConsoleOutputCP(CP_UTF8);
    locale::global(locale(""));

    wcout.imbue(locale());

	cargarProductos();
	for (int i = 0; i < 10; i++)
	{
		cout << limpieza[i].nombre << endl;
	}
	

	int opc;
	do
	{
		cout << "-------------Digite la opcion----------";
		cout << "\n\n1.- Clientes";
		cout << "\n2.- Administracion\n";
		cin >> opc;

	}while(opc > 2 or opc < 1);
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
			revisarCarritoDeCompras(PreProducto);
			break;
		case 3:

			break;
		case 4:
			Opc = 4;
			break;
		default:
			cout << "\n Opci�n inv�lida";
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
			Opc = 6;
			break;
		default:
			cout << "\n Opci�n inv�lida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
		system("pause");
		system("cls");
	} while (Opc != 6);
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
			PreProducto[PosProd].nombre_producto = "Pa�os Reutilizables";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 4:
			PreProducto[PosProd].nombre_producto = "Papel Higi�nico";
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
			cout << "\n Opci�n inv�lida";
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
			cout << "\n Opci�n inv�lida";
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
			cout << "\n Opci�nn inv�lida";
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
			PreProducto[PosProd].nombre_producto = "1kg. Lim�n";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 11:
			Opc = 11;
			break;
		default:
			cout << "\n Opci�n inv�lida";
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
			PreProducto[PosProd].nombre_producto = "Unid Sand�a";
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
			PreProducto[PosProd].nombre_producto = "Unid. Pi�a";
			cout << "\n Ingrese la cantidad que desea de este producto: ";
			cin >> PreProducto[PosProd].cantidad_producto;
			PosProd++;
			break;
		case 11:
			Opc = 11;
			break;
		default:
			cout << "\n Opci�n inv�lida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
	} while (Opc != 11);
}

// Revisar carrito de compras

void revisarCarritoDeCompras(Venta *venta)
{
	cout << "Carrito de compras" << endl;
	cout << "------------------" << endl;
	cout << "Producto   "
		 << "Cantidad  "
		 << "Precio    " << endl;
	for (int i = 0; i < 50; i++)
	{
		if (venta[i].nombre_producto == "")
		{
			break;
		}
		cout << venta[i].nombre_producto << "      " << venta[i].cantidad_producto << "         " << venta[i].precio_producto << endl;
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
/*
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
*/

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

    cout << "\nDigite su elecci�n: ";
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
	cout << "   a. Tarjeta bancaria (cr�dito o d�bito)" << endl;
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


void cargarProductos(){
	int cantidadStringsLimpieza = 0, cantidadStringsTecnologia = 0, cantidadStringsHogar = 0, cantidadStringsVerduras = 0, cantidadStringsFrutas = 0;
	
	string *stringsEnumeradosLimpieza = obtenerStringsEnumerados("../archivos/menuLimpieza.txt", cantidadStringsLimpieza);
	string *stringsEnumeradosTecnologia = obtenerStringsEnumerados("../archivos/menuTecnologia.txt", cantidadStringsTecnologia);
	string *stringsEnumeradosHogar = obtenerStringsEnumerados("../archivos/menuHogar.txt", cantidadStringsHogar);
	string *stringsEnumeradosVerduras = obtenerStringsEnumerados("../archivos/menuVerduras.txt", cantidadStringsVerduras);
	string *stringsEnumeradosFrutas = obtenerStringsEnumerados("../archivos/menuFrutas.txt", cantidadStringsFrutas);

	for (int i = 0; i < cantidadStringsLimpieza; i++) {
		limpieza[i].nombre = stringsEnumeradosLimpieza[i];
	}
	for (int i = 0; i < cantidadStringsTecnologia; i++) {
		tecnologia[i].nombre = stringsEnumeradosTecnologia[i];
	}
	for (int i = 0; i < cantidadStringsHogar; i++) {
		hogar[i].nombre = stringsEnumeradosHogar[i];
	}
	for (int i = 0; i < cantidadStringsVerduras; i++) {
		verduras[i].nombre = stringsEnumeradosVerduras[i];
	}
	for (int i = 0; i < cantidadStringsFrutas; i++) {
		frutas[i].nombre = stringsEnumeradosFrutas[i];
	}

	delete[] stringsEnumeradosLimpieza;
	delete[] stringsEnumeradosTecnologia;
	delete[] stringsEnumeradosHogar;
	delete[] stringsEnumeradosVerduras;
	delete[] stringsEnumeradosFrutas;
}
