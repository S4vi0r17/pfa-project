#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include <locale> // Para usar caracteres especiales
using namespace std;

// Estructuras
struct Venta {
    string nombre_producto;
    float precio_producto;
    int cantidad_producto;
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
    int stock;
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

    revisarCarritoDeCompras(venta);

}




//menu principal









//Cliente








//Menu cliente registrado
int OpcClntReg(int Opc){
	
	cout<<"\n Bienvenido";
	cout<<"\n ¿Qué desea realizar?";
	cout<<"\n 1. Escoger productos";
	cout<<"\n 2. Revisar carrito de compra";
	cout<<"\n 3. Realizar compra";
	cout<<"\n 4. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnClntReg(){

	int Opc, PosProd;
	
	Venta PreProducto[10];
	
	do{
		Opc=OpcClntReg(Opc);
		switch(Opc){
			case 1:
				MnEscgrProd(PreProducto, PosProd);	
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;		
		}
		system("pause");
		system("cls");
	}while(Opc!=4);

}

int OpcEscgrProd(int Opc){
	
	cout<<"\n ¿Qué tipo de producto desea comprar?\n";
	cout<<"\n 1. Articulos de limpieza";
	cout<<"\n 2. Tecnología";
	cout<<"\n 3. Productos para el hogar";
	cout<<"\n 4. Verduras";
	cout<<"\n 5. Frutas";
	cout<<"\n 6. ";
	cout<<"\n 7. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnEscgrProd(Venta* PreProducto, int& PosProd){
	
	int Opc, PosProd=0;
	
	do{
		
		Opc=OpcEscgrProd(Opc);
		switch(Opc){
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
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
		system("pause");
		system("cls");
	}while(Opc!=7);
}

void MnLimp(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		Opc=OpcLimp(Opc);
		switch(Opc){
			case 1:
				PreProducto[PosProd].nombre_producto="Set Escoba";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 2:
				PreProducto[PosProd].nombre_producto="Desinfectante 1Lt";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 3:
				PreProducto[PosProd].nombre_producto="Paños Reutilizables";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="Papel Higiénico";
				cout<<"\n Ingrese la cantidad que desea de este producto:";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;	
				break;
			case 5:
				PreProducto[PosProd].nombre_producto="Papel Toalla";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 6:
				PreProducto[PosProd].nombre_producto="Set Trapeador";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 7:
				PreProducto[PosProd].nombre_producto="Guantes de Latex";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 8:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=8);
}

int OpcLimp(int Opc){
	
	cout<<"\n ARTICULOS DE LIMPIEZA";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Set Escoba";
	cout<<"\n 2. Desinfectante 1Lt";
	cout<<"\n 3. Paños Reutilizables";
	cout<<"\n 4. Papel Higiénico";
	cout<<"\n 5. Papel Toalla";
	cout<<"\n 6. Set Trapeador";
	cout<<"\n 7. Guantes de Latex";
	cout<<"\n 8. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnTec(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		Opc=OpcTec(Opc);
		switch(Opc){
			case 1:
				PreProducto[PosProd].nombre_producto="Laptop Gamer Asus";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 2:
				PreProducto[PosProd].nombre_producto="Celular Android LG";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 3:
				PreProducto[PosProd].nombre_producto="SmartTV Samsung";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="Tablet Samsung";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 5:
				PreProducto[PosProd].nombre_producto="Set Gamer(Teclado, mouse y mousepad)";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 6:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=6);
	
}

int OpcTec(int Opc){
	
	cout<<"\n ÁREA DE TECNOLOGÍA";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Laptop Gamer Asus";
	cout<<"\n 2. Celular Android LG";
	cout<<"\n 3. SmartTV Samsung";
	cout<<"\n 4. Tablet Samsung";
	cout<<"\n 5. Set Gamer (Teclado, mouse y mousepad)";
	cout<<"\n 6. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnHog(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		Opc=OpcHog(Opc);
		switch(Opc){
			case 1:
				PreProducto[PosProd].nombre_producto="Set Utensilios de Cocina";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 2:
				PreProducto[PosProd].nombre_producto="Set Ventiladores de Techo";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 3:
				PreProducto[PosProd].nombre_producto="Silla Escritorio";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="Repisa de madera";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 5:
				PreProducto[PosProd].nombre_producto="Juego de Comedor(4 sillas 1 mesa)";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 6:
				PreProducto[PosProd].nombre_producto="Ropero";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 7:
				PreProducto[PosProd].nombre_producto="Cama de 2 plazas";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 8:
				PreProducto[PosProd].nombre_producto="Juego de Sofas";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 9:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=9);
	
}

int OpcHog(int Opc){
	
	cout<<"\n ÁREA HOGAR";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Set Utensilios de Cocina";
	cout<<"\n 2. Set Ventiladores de Techo";
	cout<<"\n 3. Silla Escritorio";
	cout<<"\n 4. Repisa de madera";
	cout<<"\n 5. Juego de Comedor (4 sillas 1 mesa)";
	cout<<"\n 6. Ropero";
	cout<<"\n 7. Cama de 2 plazas";
	cout<<"\n 8. Juego de Sofas";
	cout<<"\n 9. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnVerd(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		Opc=OpcVerd(Opc);
		switch(Opc){
			case 1:
				PreProducto[PosProd].nombre_producto="1kg Cebolla";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 2:
				PreProducto[PosProd].nombre_producto="Unid. Lechuga";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 3:
				PreProducto[PosProd].nombre_producto="1kg. Tomate";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="Unid. Aguacate";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 5:
				PreProducto[PosProd].nombre_producto="1kg. Papa";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 6:
				PreProducto[PosProd].nombre_producto="1kg. Zanahoria";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 7:
				PreProducto[PosProd].nombre_producto="Unid. Calabaza";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 8:
				PreProducto[PosProd].nombre_producto="Unid. Pepino";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 9:
				PreProducto[PosProd].nombre_producto="Unid. Pimiento";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 10:
				PreProducto[PosProd].nombre_producto="1kg. Limón";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 11:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=11);
	
}

int OpcVerd(int Opc){
	
	cout<<"\n ÁREA VERDURAS";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. 1kg Cebolla";
	cout<<"\n 2. Unid. Lechuga";
	cout<<"\n 3. 1kg. Tomate";
	cout<<"\n 4. Unid. Aguacate";
	cout<<"\n 5. 1kg. Papa";
	cout<<"\n 6. 1kg. Zanahoria";
	cout<<"\n 7. Unid. Calabaza";
	cout<<"\n 8. Unid. Pepino";
	cout<<"\n 9. Unid. Pimiento";
	cout<<"\n 10. 1kg. Limón";
	cout<<"\n 11. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}

void MnFrut(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		Opc=OpcFrut(Opc);
		switch(Opc){
			case 1:
				PreProducto[PosProd].nombre_producto="Mano de Platanos";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 2:
				PreProducto[PosProd].nombre_producto="1kg. Manzana";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 3:
				PreProducto[PosProd].nombre_producto="1kg. Fresas";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="1kg. Uva";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 5:
				PreProducto[PosProd].nombre_producto="1kg. Naranja";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 6:
				PreProducto[PosProd].nombre_producto="Unid Sandía";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 7:
				PreProducto[PosProd].nombre_producto="1kg. Mango";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 8:
				PreProducto[PosProd].nombre_producto="1kg. Mandarina";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 9:
				PreProducto[PosProd].nombre_producto="1kg. Manzana";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 10:
				PreProducto[PosProd].nombre_producto="Unid. Piña";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 11:
				break;
			default:
				cout<<"\n Opción inválida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=11);
}

int OpcFrut(int Opc){
	
	cout<<"\n ÁREA FRUTAS";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Mano de Platanos";
	cout<<"\n 2. 1kg. Manzana";
	cout<<"\n 3. 1kg. Fresas";
	cout<<"\n 4. 1kg. Uva";
	cout<<"\n 5. 1kg. Naranja";
	cout<<"\n 6. Unid Sandía";
	cout<<"\n 7. 1kg. Mango";
	cout<<"\n 8. 1kg. Mandarina";
	cout<<"\n 9. 1kg. Manzana";
	cout<<"\n 10. Unid. Piña";
	cout<<"\n 11. Salir";
	cout<<"\n Digite su elección: ";
	cin>>Opc;
	
	return Opc;
}






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