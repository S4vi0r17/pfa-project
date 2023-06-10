#include<iostream>
#include <locale> // Para usar caracteres especiales
using namespace std;

// Estructuras
struct Venta {
    string nombre_producto;
    float precio_producto;
    float cantidad_producto;
    float monto_producto;
}venta[50];

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



//Prototipos

char menuMediosPago();
void revisarCarritoDeCompras(Venta vector[]);


//Funcion principal

int main() {
    
    /*
    Producto de Prueba
    */
    venta[0].nombre_producto = "Papas";
    venta[0].precio_producto = 8;
    venta[0].cantidad_producto = 2;
    
    cout<<"\n Hola Mundo";

    revisarCarritoDeCompras(venta);

}




//menu principal









//Cliente








//Menu cliente registrado







//Revisar carrito de compras

void revisarCarritoDeCompras(Venta vector[]){
    cout << "Carrito de compras" << endl;
    cout << "------------------" << endl;
    cout << "Producto   " << "Cantidad  " << "Precio    " << endl;
    for (int i = 0; i < 50; i++) {
        if (vector[i].nombre_producto == "") {
            break;
        }
        cout << vector[i].nombre_producto << "      " << vector[i].cantidad_producto << "         " << vector[i].precio_producto << endl;
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
    cout << "   a. Tarjeta bancaria (crédito o débito)" << endl;
    cout << "   b. Tarjeta online (pagos electrónicos)" << endl;
    cout << "3. Vales y tarjetas de beneficios:" << endl;
    cout << "   a. Vale escolar" << endl;
    cout << "   b. Vale de mercadería" << endl;
    cout << "   c. Vale de alimento" << endl;

    char opcion;
    cout << "Ingrese la opción deseada: ";
    cin >> opcion;

    return opcion;
}