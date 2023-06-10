#include<iostream>
#include <locale> // Para usar caracteres especiales
using namespace std;

// Estructuras
struct Venta {
    string nombre_producto;
    float precio_producto;
    float cantidad_producto;
    float monto_producto;
};

struct Boleta {
    Venta productos[10];
    float monto_total;    
};

struct Clientes {
    string nombre;
    string DNI;
    Boleta historial[10];
};

struct Productos {
    string nombre;
    string codigo;
    string tipo;
    float precio;
    float stock;
    
};
struct Global{
	
	Venta venta[100];
	Boleta boleta[100];
	Clientes cliente[100];
	Productos producto[100];
}g;


//Prototipos

char menuMediosPago();
void revisarCarritoDeCompras(Global global);


//Funcion principal

int main() {
    
    /*
    Producto de Prueba
    */
    g.venta[0].nombre_producto = "Papas";
    g.venta[0].precio_producto = 8;
    g.venta[0].cantidad_producto = 2;
    

    revisarCarritoDeCompras(g);

}




//menu principal









//Cliente








//Menu cliente registrado







//Revisar carrito de compras

void revisarCarritoDeCompras(Global global){
    cout << "Carrito de compras" << endl;
    cout << "------------------" << endl;
    cout << "Producto   " << "Cantidad  " << "Precio    " << endl;
    for (int i = 0; i < 50; i++) {
        if (global.venta[i].nombre_producto == "") {
            break;
        }
        cout << global.venta[i].nombre_producto << "      " << global.venta[i].cantidad_producto << "         " << global.venta[i].precio_producto << endl;
    }

}




//Realizar compra






//Menu Administrador




















//Funcion de medios de pago

char menuMediosPago() {
    cout << "Seleccione un medio de pago:" << endl;
    cout << "1. Medios de pago en efectivo:" << endl;
    cout << "   a. Efectivo (moneda nacional)" << endl;
    cout << "   b. Moneda extranjera" << endl;
    cout << "2. Tarjetas bancarias:" << endl;
    cout << "   a. Tarjeta bancaria (cr�dito o d�bito)" << endl;
    cout << "   b. Tarjeta online (pagos electr�nicos)" << endl;
    cout << "3. Vales y tarjetas de beneficios:" << endl;
    cout << "   a. Vale escolar" << endl;
    cout << "   b. Vale de mercader�a" << endl;
    cout << "   c. Vale de alimento" << endl;

    char opcion;
    cout << "Ingrese la opci�n deseada: ";
    cin >> opcion;

    return opcion;
}
