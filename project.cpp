#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <locale>
#include <windows.h> // Para usar caracteres especiales
#include <clocale>	 // Para usar caracteres especiales
#include <fstream>
#include <filesystem> //agregado por problemas de rutas
#include <conio.h>
using namespace std;

// Estructuras
struct Venta
{
	string nombre_producto;
	float precio_producto;
	int cantidad_producto;
	float monto_producto;
} compra[50];
int posicionDelProducto = 0;

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
}clientes[100];
int posicionDelCliente = 0;

struct Productos
{
	string nombre;
	string codigo;
	string tipo;
	float precio;
	int stock;
} limpieza[10], tecnologia[10], hogar[10], verduras[10], frutas[10];

// Prototipos
string *obtenerStringsEnumerados(const string &nombreArchivo, int &cantidadStrings);
//Prototipo del inventario productos
Productos *infoProductos(const string &nombreArchivo, int cantidadProductos);

void usuario();
void cargarProductos();
void menuTipo(Venta producto[], string archivoMenu, Productos vector[], int &i);
int mostrarMenu(const string &archivo);
int solicitarCantidad();
void menuMediosPago();
void revisarCarritoDeCompras(Venta *venta);
void MnClntReg();
void MnEscgrProd();
void modificarCarritoDeCompras();

// Prototipos Menu
// int administracion(Global &G);
// void mostrar_boleta(int b, Global G);
int menu_adm_1();
// Funcion principal

int main()
{

	SetConsoleOutputCP(CP_UTF8);
	locale::global(locale(""));

	wcout.imbue(locale());

	cargarProductos();

	int opc;
	do
	{
		cout << "-------------Digite la opcion----------";
		cout << "\n\n1.- Clientes";
		cout << "\n2.- Administracion\n";
		cin >> opc;

	} while (opc > 2 or opc < 1);

	if (opc == 1)
	{
		usuario();
	}
	else
	{
		// administracion;
	}
}

// Menu cliente registrado

void MnClntReg()
{
	system("cls");
	int Opc;

	do
	{
		switch (mostrarMenu("../archivos/menuClntReg.txt"))
		{
		case 1:
			MnEscgrProd();
			break;
		case 2:
			revisarCarritoDeCompras(compra);
			break;
		case 3:
			//Compra
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

void MnEscgrProd()
{
	system("cls");
	int Opc;

	do
	{
		switch (mostrarMenu("../archivos/menuEscgrProd.txt"))
		{
		case 1:
			menuTipo(compra, "../archivos/menuLimpieza.txt", limpieza, posicionDelProducto);
			break;
		case 2:
			menuTipo(compra, "../archivos/menuTecnologia.txt", tecnologia, posicionDelProducto);
			break;
		case 3:
			menuTipo(compra, "../archivos/menuHogar.txt", hogar, posicionDelProducto);
			break;
		case 4:
			menuTipo(compra, "../archivos/menuVerduras.txt", verduras, posicionDelProducto);
			break;
		case 5:
			menuTipo(compra, "../archivos/menuFrutas.txt", frutas, posicionDelProducto);
			break;
		case 6:
			Opc = 6;
			break;
		default:
			cout << "\n Opcion invalida";
			cout << "\n Vuelva a intentarlo\n\n ";
			break;
		}
		system("pause");
		system("cls");
	} while (Opc != 6);
}

void menuTipo(Venta producto[], string archivoMenu, Productos vector[], int &i)
{
	int opcion;
	do
	{
		switch (mostrarMenu(archivoMenu))
		{
		case 1:
			producto[i].nombre_producto = vector[0].nombre;
			producto[i].precio_producto = vector[0].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 2:
			producto[i].nombre_producto = vector[1].nombre;
			producto[i].precio_producto = vector[1].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 3:
			producto[i].nombre_producto = vector[2].nombre;
			producto[i].precio_producto = vector[2].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 4:
			producto[i].nombre_producto = vector[3].nombre;
			producto[i].precio_producto = vector[3].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 5:
			producto[i].nombre_producto = vector[4].nombre;
			producto[i].precio_producto = vector[4].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 6:
			producto[i].nombre_producto = vector[5].nombre;
			producto[i].precio_producto = vector[5].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 7:
			producto[i].nombre_producto = vector[6].nombre;
			producto[i].precio_producto = vector[6].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 8:
			producto[i].nombre_producto = vector[7].nombre;
			producto[i].precio_producto = vector[7].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 9:
			producto[i].nombre_producto = vector[8].nombre;
			producto[i].precio_producto = vector[8].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 10:
			producto[i].nombre_producto = vector[9].nombre;
			producto[i].precio_producto = vector[9].precio;
			producto[i].cantidad_producto = solicitarCantidad();
			i++;
			break;
		case 11:
			opcion = 11;
			break;
		default:
			cout << "\n Opcion invalida, vuelva a intentarlo\n\n ";
			break;
		}

	} while (opcion != 11);
}

// Revisar carrito de compras(Para elegir si modificar algo)
void revisarCarritoDeCompras(Venta *venta)
{
	cout << "        Carrito de compras         " << endl;
	cout << "        ==================         " << endl;
	/*cout << "Producto                     "
		 << "Cantidad                     "
		 << "Precio                       " << endl;*/
	for (int i = 0; i < 50; i++)
	{
		if (venta[i].nombre_producto == "")
		{
			break;
		}
		//cout << venta[i].nombre_producto << "      " << venta[i].cantidad_producto << "         " << venta[i].precio_producto << endl;
		cout<<"Producto:\t"<<venta[i].nombre_producto<<endl;
		cout<<"Cantidad:\t"<<venta[i].cantidad_producto<<endl;
		cout<<"Precio:\t"<<venta[i].precio_producto<<endl;
		cout<<"Monto:\t"<<venta[i].monto_producto<<endl;
		cout<<"        ==================         "<<endl;
	}
	modificarCarritoDeCompras();
}

int menuModifCompra(int Opc)
{
	cout<<"¿Que desea modificar de su carrito de compra?";
	cout<<"\n1. Eliminar producto"<<endl;
	cout<<"2. Modificar cantidad de algun producto"<<endl;
	cout<<"3. Nada (Salir)"<<endl;
	cin>>Opc;
	return Opc;
}

void mostrarCarritoDeCompras(Venta *venta)
{
	cout << "        CARRITO DE COMPRAS         " << endl;
	cout << "        ==================         " << endl;
	for (int i = 0; i < posicionDelProducto; i++)
	{
		cout<<"Producto:\t"<<venta[i].nombre_producto<<endl;
		cout<<"Cantidad:\t"<<venta[i].cantidad_producto<<endl;
		cout<<"Precio:\t"<<venta[i].precio_producto<<endl;
		cout<<"Monto:\t"<<venta[i].monto_producto<<endl;
		cout<<"        ==================         "<<endl;
	}
}

void eliminarProductoCarCompra()
{
	int pos;
	do{
		mostrarCarritoDeCompras(compra);
		cout<<"Digite el número del producto que desea elminar (Digite '0' para Salir): ";
		cin>>pos;
		if (pos != 0 && pos >= 1 && pos <= posicionDelProducto) {
			for (int i = pos - 1; i < posicionDelProducto - 1; i++) {
				compra[i] = compra[i + 1];
			}
			posicionDelProducto--;
		}
	}while(pos!=0);
}

void modificarCantCarCompra()
{
	int pos;
	int cantidad;
	do{
		mostrarCarritoDeCompras(compra);
		cout<<"Digite el número del producto que desee cambiar su cantidad (Digite '0' para salir): ";
		cin>>pos;
		cout<<"Digite la cantidad que desee del producto: ";
		cin>>cantidad;
		if(pos!=0){
			compra[pos-1].cantidad_producto=cantidad;
		}
		system("cls");
	}while(pos!=0);
}

//Modificar Carrito de Compra
void modificarCarritoDeCompras()
{
	int Opc;
	do{
		Opc=menuModifCompra(Opc);
		switch(Opc){
			case 1:
				eliminarProductoCarCompra();
				break;
			case 2:
				modificarCantCarCompra();
				break;
			case 3:
				break;
			default:
				cout<<"\n La opción digitada es inválida";
				cout<<"\n Vuelva a intentarlo\n\n";
				system("pause");
				system("cls");
				break;
		}
	}while(Opc!=3);
} 

// Generar boleta
void generarBoletaVenta(const Venta* venta, int num_ventas, const string& cliente, double total, const string& archivo_salida)
{
    ofstream archivo(archivo_salida);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "         Boleta de Venta          " << endl;
    archivo << "        ------------------        " << endl;
    archivo << "Cliente: " << cliente << endl;
    archivo << "-------------------------------" << endl;
    archivo << "Producto          Cantidad   Precio" << endl;
    archivo << "-------------------------------" << endl;

    for (int i = 0; i < num_ventas; i++)
    {
        archivo << venta[i].nombre_producto << "      " << venta[i].cantidad_producto << "         " << venta[i].precio_producto << endl;
    }

    archivo << "-------------------------------" << endl;
    archivo << "Total:            " << total << endl;

    archivo.close();
}

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
		cout << "Digite una opcion:";

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


// Muestra cualquier menu solo con pasarle archivos con ruta relativa
int mostrarMenu(const string &archivo)
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



void cargarProductos()
{
	int cantidadStringsLimpieza = 0, cantidadStringsTecnologia = 0, cantidadStringsHogar = 0, cantidadStringsVerduras = 0, cantidadStringsFrutas = 0;

	string *stringsEnumeradosLimpieza = obtenerStringsEnumerados("../archivos/menuLimpieza.txt", cantidadStringsLimpieza);
	string *stringsEnumeradosTecnologia = obtenerStringsEnumerados("../archivos/menuTecnologia.txt", cantidadStringsTecnologia);
	string *stringsEnumeradosHogar = obtenerStringsEnumerados("../archivos/menuHogar.txt", cantidadStringsHogar);
	string *stringsEnumeradosVerduras = obtenerStringsEnumerados("../archivos/menuVerduras.txt", cantidadStringsVerduras);
	string *stringsEnumeradosFrutas = obtenerStringsEnumerados("../archivos/menuFrutas.txt", cantidadStringsFrutas);

	Productos *productosLimpieza = infoProductos("../archivos/productosLimpieza.txt", cantidadStringsLimpieza);
	Productos *productosTecnologia = infoProductos("../archivos/productosTecnologia.txt", cantidadStringsTecnologia);
	Productos *productosHogar = infoProductos("../archivos/productosHogar.txt", cantidadStringsHogar);
	Productos *productosVerduras = infoProductos("../archivos/productosVerduras.txt", cantidadStringsVerduras);
	Productos *productosFrutas = infoProductos("../archivos/productosFrutas.txt", cantidadStringsFrutas);

	for (int i = 0; i < cantidadStringsLimpieza; i++)
	{
		limpieza[i].nombre = stringsEnumeradosLimpieza[i];
		limpieza[i].codigo = productosLimpieza[i].codigo;
		limpieza[i].tipo = productosLimpieza[i].tipo;
		limpieza[i].precio = productosLimpieza[i].precio;
		limpieza[i].stock = productosLimpieza[i].stock;
	}
	for (int i = 0; i < cantidadStringsTecnologia; i++)
	{
		tecnologia[i].nombre = stringsEnumeradosTecnologia[i];
	}
	for (int i = 0; i < cantidadStringsHogar; i++)
	{
		hogar[i].nombre = stringsEnumeradosHogar[i];
	}
	for (int i = 0; i < cantidadStringsVerduras; i++)
	{
		verduras[i].nombre = stringsEnumeradosVerduras[i];
	}
	for (int i = 0; i < cantidadStringsFrutas; i++)
	{
		frutas[i].nombre = stringsEnumeradosFrutas[i];
	}

	delete[] stringsEnumeradosLimpieza;
	delete[] stringsEnumeradosTecnologia;
	delete[] stringsEnumeradosHogar;
	delete[] stringsEnumeradosVerduras;
	delete[] stringsEnumeradosFrutas;

	delete[] productosLimpieza;
}

// Obtiene un arreglo de strings a partir de un archivo de texto y los almacena en una posicion contigua de memoria
string *obtenerStringsEnumerados(const string &nombreArchivo, int &cantidadStrings)
{
	ifstream archivo(nombreArchivo);
	if (!archivo)
	{
		cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
		cantidadStrings = 0;
		return nullptr;
	}

	string linea;
	int contador = 0;

	while (getline(archivo, linea))
	{
		if (!linea.empty())
		{
			if (isdigit(linea[0]) && linea.find(".") != string::npos)
			{
				contador++;
			}
		}
	}

	archivo.clear();
	archivo.seekg(0);

	string *stringsEnumerados = new string[contador];
	int index = 0;

	while (getline(archivo, linea))
	{
		if (!linea.empty())
		{
			if (isdigit(linea[0]) && linea.find(".") != string::npos)
			{
				if (index < contador - 1)
				{ // Excluir la última línea
					string substring = linea.substr(linea.find(".") + 1);
					stringsEnumerados[index] = substring;
					index++;
				}
			}
		}
	}

	archivo.close();
	cantidadStrings = contador - 1; // Excluir Salir
	return stringsEnumerados;
}

// Menu clientes
void usuario(){

	string docDNI;
	bool encontrado = false;
	int posisicion;
	cout << "Bienvenido a la tienda" << endl;
	fflush(stdin);
	cout << "Ingrese su DNI: ";
	getline(cin, docDNI);
	for (int i = 0; i < 100; i++)
	{
		if (clientes[i].DNI == docDNI)
		{
			encontrado = true;
			posisicion = i;
			cout << "Bienvenido " << clientes[i].nombre << endl;
			getch();
			MnClntReg();
			break;
		}
	
	}
	if (encontrado == false)
	{
		cout << "No se encontro el DNI" << endl;
		cout << "Ingrese su nombre: ";
		getline(cin, clientes[posicionDelCliente].nombre);
		clientes[posicionDelCliente].DNI = docDNI;
		cout << "Bienvenido " << clientes[posicionDelCliente].nombre << endl;
		getch();
		MnClntReg();
	}
}

//Realizar compra
void menuMediosPago()
{
	char Opc;
	cout << "Seleccione un medio de pago:" << endl;
	cout << "Medios de pago en efectivo:" << endl;
	cout << "   1. Efectivo (moneda nacional)" << endl;
	cout << "   2. Moneda extranjera" << endl;
	cout << "Tarjetas bancarias:" << endl;
	cout << "   3. Tarjeta bancaria (crédito o débito)" << endl;
	cout << "   4. Tarjeta online (pagos electrónicos)" << endl;
	cout << "Vales y tarjetas de beneficios:" << endl;
	cout << "   5. Vale escolar" << endl;
	cout << "   6. Vale de mercader?a" << endl;
	cout << "   7. Vale de alimento" << endl;

	cin >> Opc;
	
	generarBoletaVenta(compra, posicionDelProducto, clientes[posicionDelCliente].nombre, 0, "../archivos/boleta.txt");
	
}

//Obtendre un struct con la informacion de los productos
Productos *infoProductos(const string &nombreArchivo, int cantidadProductos){

	ifstream archivo(nombreArchivo);

	if (!archivo)
	{
		cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
		return nullptr;
	}

	string linea;

	Productos* listaProductos = new Productos[cantidadProductos]; 

	int index = 0, contador = 0 ; 

	while (getline(archivo, linea))
	{
		switch(contador % 4){
			case 0:
				listaProductos[index].codigo = linea;
				break;
			case 1:
				listaProductos[index].tipo = linea;
				break;
			case 2:
				listaProductos[index].precio = stof(linea);
				break;
			case 3:
				listaProductos[index].stock = stoi(linea);
				break;
		}

		contador++;

		if(contador % 4 == 0){
			index++;
		}
	
	}

	archivo.close();

	return listaProductos;
}
