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
    int stock;
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
void MnClntReg();
int OpcClntReg();
void MnEscgrProd(Venta* PreProducto, int& PosProd);
int OpcEscgrProd();
void MnLimp(Venta* PreProducto, int& PosProd);
int OpcLimp();
void MnTec(Venta* PreProducto, int& PosProd);
int OpcTec();
void MnHog(Venta* PreProducto, int& PosProd);
int OpcHog();
void MnVerd(Venta* PreProducto, int& PosProd);
int OpcVerd();
void MnFrut(Venta* PreProducto, int& PosProd);
int OpcFrut();

		//Prototipos Menu
		int menu_adm();
		int administracion(Global &G);
		void mostrar_boleta(int b,Global G);
//Funcion principal

int main() {
    
    /*
    Producto de Prueba
    */
    cout<<"\nPrueba Nacho\n";
    
    g.venta[0].nombre_producto = "Papas";
    g.venta[0].precio_producto = 8;
    g.venta[0].cantidad_producto = 2;
	
    revisarCarritoDeCompras(g);
    g.cliente[0].nombre="jack zavaleta";
	g.cliente[1].nombre="luis miguel";
	g.cliente[0].DNI="71157781";
	g.cliente[1].DNI="09056371";
	

	
	g.cliente[0].historial[0].productos[0].nombre_producto="atun";
	g.cliente[0].historial[0].productos[0].precio_producto=134;
	g.cliente[0].historial[0].productos[0].cantidad_producto=12;
	g.cliente[0].historial[0].productos[0].monto_producto=1608;
	
	g.cliente[0].historial[0].productos[1].nombre_producto="melocoton";
	g.cliente[0].historial[0].productos[1].precio_producto=135;
	g.cliente[0].historial[0].productos[1].cantidad_producto=12;
	g.cliente[0].historial[0].productos[1].monto_producto=1620;
	
	g.cliente[0].historial[0].monto_total=3228;
	
	g.cliente[0].historial[1].productos[0].nombre_producto="Naranjas";
	g.cliente[0].historial[1].productos[0].precio_producto=21;
	g.cliente[0].historial[1].productos[0].cantidad_producto=5;
	g.cliente[0].historial[1].productos[0].monto_producto=125;
	
	g.cliente[0].historial[1].productos[1].nombre_producto="toronjas";
	g.cliente[0].historial[1].productos[1].precio_producto=100;
	g.cliente[0].historial[1].productos[1].cantidad_producto=5;
	g.cliente[0].historial[1].productos[1].monto_producto=500;
	
	g.cliente[0].historial[1].monto_total=625;
	
	
	g.cliente[1].historial[0].productos[0].nombre_producto="cerezas";
	g.cliente[1].historial[0].productos[0].precio_producto=15;
	g.cliente[1].historial[0].productos[0].cantidad_producto=5;
	g.cliente[1].historial[0].productos[0].monto_producto=75;
	
	g.cliente[1].historial[0].productos[1].nombre_producto="limon";
	g.cliente[1].historial[0].productos[1].precio_producto=12;
	g.cliente[1].historial[0].productos[1].cantidad_producto=100;
	g.cliente[1].historial[0].productos[1].monto_producto=1200;
	
	g.cliente[1].historial[0].monto_total=1275;
	
	g.cliente[1].historial[1].productos[0].nombre_producto="pizza";
	g.cliente[1].historial[1].productos[0].precio_producto=50;
	g.cliente[1].historial[1].productos[0].cantidad_producto=5;
	g.cliente[1].historial[1].productos[0].monto_producto=250;
	
	g.cliente[1].historial[1].productos[0].nombre_producto="tumama";
	g.cliente[1].historial[1].productos[0].precio_producto=100;
	g.cliente[1].historial[1].productos[0].cantidad_producto=5;
	g.cliente[1].historial[1].productos[0].monto_producto=500;
	
	g.cliente[1].historial[1].monto_total=750;	
	
	g.producto[0].nombre="atun";
	g.producto[0].codigo="0506";
	g.producto[0].tipo="conserva";
	g.producto[0].precio=134;
	g.producto[0].stock=39;
	
	g.producto[1].nombre="limon";
	g.producto[1].codigo="0055";
	g.producto[1].tipo="fruta";
	g.producto[1].precio=12;
	g.producto[1].stock=36;
	
	g.producto[2].nombre="tumama";
	g.producto[2].codigo="0505";
	g.producto[2].tipo="qqq";
	g.producto[2].precio=39;
	g.producto[2].stock=39;
	
	
	//PRUEBA MENU DE ZAVALETA
	
	cout<<"\n\n\nPrueba Zavaleta\n\n";
	
	int valor=1,a=0,opc=1;
	do{
	cout<<"-------------Digite la opcion----------";
	cout<<"\n\n1.- blablablabalblaballba";
	cout<<"\n2.- Administracion\n";
	cin>>opc;
	
	if(opc==1 or opc==2)
	{
		if(opc==1)
		{
		cout<<"\n\nmasblablabla";
		}	
		else
		{
		do
			{
				system("cls");
				valor=administracion(g);
				
				if(valor==1)
				{
					a=1;
				}
				
			}while(valor==0);
		}	
	}
	else{
		a=1;
	}
}while(a==1);
	
}





//menu principal









//Cliente








//Menu cliente registrado
int OpcClntReg(){
	
	int Opc;
	cout<<"\n Bienvenido";
	cout<<"\n �Qu� desea realizar?";
	cout<<"\n 1. Escoger productos";
	cout<<"\n 2. Revisar carrito de compra";
	cout<<"\n 3. Realizar compra";
	cout<<"\n 4. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnClntReg(){

	int Opc,PosProd;
	
	Venta PreProducto[10];
	
	do{
		switch(OpcClntReg()){
			case 1:
				MnEscgrProd(PreProducto, PosProd);	
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				Opc=4;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;		
		}
		system("pause");
		system("cls");
	}while(Opc!=4);

}

int OpcEscgrProd(){
	
	int Opc;
	cout<<"\n ¿Qué tipo de producto desea comprar?\n";
	cout<<"\n 1. Articulos de limpieza";
	cout<<"\n 2. Tecnolog�a";
	cout<<"\n 3. Productos para el hogar";
	cout<<"\n 4. Verduras";
	cout<<"\n 5. Frutas";
	cout<<"\n 6. ";
	cout<<"\n 7. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnEscgrProd(Venta* PreProducto, int& PosProd){
	
	int Opc;
    PosProd=0;
	
	do{
		switch(OpcEscgrProd()){
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
				Opc=7;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
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
		switch(OpcLimp()){
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
				PreProducto[PosProd].nombre_producto="Pa�os Reutilizables";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;		
				break;
			case 4:
				PreProducto[PosProd].nombre_producto="Papel Higi�nico";
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
				Opc=8;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=8);
}

int OpcLimp(){
	int Opc;
	cout<<"\n ARTICULOS DE LIMPIEZA";
	cout<<"\n �Qu� desea comprar?\n";
	cout<<"\n 1. Set Escoba";
	cout<<"\n 2. Desinfectante 1Lt";
	cout<<"\n 3. Pa�os Reutilizables";
	cout<<"\n 4. Papel Higi�nico";
	cout<<"\n 5. Papel Toalla";
	cout<<"\n 6. Set Trapeador";
	cout<<"\n 7. Guantes de Latex";
	cout<<"\n 8. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnTec(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		
		switch(OpcTec()){
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
				Opc=6;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=6);
	
}

int OpcTec(){
	int Opc;
	cout<<"\n ÁREA DE TECNOLOGÍA";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Laptop Gamer Asus";
	cout<<"\n 2. Celular Android LG";
	cout<<"\n 3. SmartTV Samsung";
	cout<<"\n 4. Tablet Samsung";
	cout<<"\n 5. Set Gamer (Teclado, mouse y mousepad)";
	cout<<"\n 6. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnHog(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
	
		switch(OpcHog()){
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
				Opc=9;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=9);
	
}

int OpcHog(){
	int Opc;
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
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnVerd(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		
		switch(OpcVerd()){
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
				PreProducto[PosProd].nombre_producto="1kg. Lim�n";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 11:
				Opc=11;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=11);
	
}

int OpcVerd(){
	int Opc;
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
	cout<<"\n 10. 1kg. Lim�n";
	cout<<"\n 11. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}

void MnFrut(Venta* PreProducto, int& PosProd){
	
	int Opc;
	
	do{
		switch(OpcFrut()){
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
				PreProducto[PosProd].nombre_producto="Unid Sand�a";
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
				PreProducto[PosProd].nombre_producto="Unid. Pi�a";
				cout<<"\n Ingrese la cantidad que desea de este producto: ";
				cin>>PreProducto[PosProd].cantidad_producto;
				PosProd++;
				break;
			case 11:
				Opc=11;
				break;
			default:
				cout<<"\n Opci�n inv�lida";
				cout<<"\n Vuelva a intentarlo\n\n ";
				break;
		}
	}while(Opc!=11);
}

int OpcFrut(){
	int Opc;
	cout<<"\n ÁREA FRUTAS";
	cout<<"\n ¿Qué desea comprar?\n";
	cout<<"\n 1. Mano de Platanos";
	cout<<"\n 2. 1kg. Manzana";
	cout<<"\n 3. 1kg. Fresas";
	cout<<"\n 4. 1kg. Uva";
	cout<<"\n 5. 1kg. Naranja";
	cout<<"\n 6. Unid Sand�a";
	cout<<"\n 7. 1kg. Mango";
	cout<<"\n 8. 1kg. Mandarina";
	cout<<"\n 9. 1kg. Manzana";
	cout<<"\n 10. Unid. Pi�a";
	cout<<"\n 11. Salir";
	cout<<"\n Digite su elecci�n: ";
	cin>>Opc;
	
	return Opc;
}






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

int menu_adm_1(){
	
	int a=1,opc;
	
	do{
	a=1;
	cout<<"-------------Digite la opcion----------";
	cout<<"\n\n1.- Reporte de Boletas";
	cout<<"\n2.- Reporte de Producto";
	cout<<"\n3.- Modifinar Producto";
	cout<<"\n4.- Agregar Producto";
	cout<<"\n5.- Eliminar Producto";
	cout<<"\n6.- Retornar Menu Principal";
	cout<<"\n7.- Salir del programa\n\n";
		
	cin>>opc;
	
	if(opc>7 or opc<1)
	{
		a=0;
		cout<<"Opcion Invalidad\n\n";
	}
	
    }while(a==0);
    
    return opc;
	   	
}



void mostrar_boleta(int b, Global G)
	{
	
		    for (int i = 0; i < 100; i++) {
		    	system("cls");
		    	if (G.cliente[b-1].historial[i].monto_total==0) {
		    		system("cls");
		        	cout<<"-------------El cliente no tiene mas boletas-------------";
		            break;
		        }
		    	cout << "----------------Boleta de Venta---------------" << endl;
				cout << "-----------------------------------------------" << endl<<"\n\n\n";
				cout << "Nombre de Cliente  : "<< G.cliente[b-1].nombre << "      DNI: "<< G.cliente[b-1].DNI<<"\n\n"; 
			    cout << "Producto              " << "Cantidad             " << "Precio               "<< "            IMPORTE " << endl;
		    	for(int j = 0; j < 100; j++)
		    	{				
		        if (G.cliente[b-1].historial[i].productos[j].nombre_producto == "") {
		        	
		            break;
		        }
		        cout << G.cliente[b-1].historial[i].productos[j].nombre_producto << "                 " << G.cliente[b-1].historial[i].productos[j].precio_producto << "                    " << G.cliente[b-1].historial[i].productos[j].cantidad_producto<< "                 " << G.cliente[b-1].historial[i].productos[j].monto_producto << endl;
			}
		    cout << "                      " << "                      " << "           TOTAL:    "<< G.cliente[b-1].historial[i].monto_total  << endl;
		    system("pause");
		    	    
		}		
	}


int administracion(Global &G){
	
	//------------------------------------------------------------------------------------------
	int opc,y;
	int c;
 	opc=menu_adm_1();
	switch(opc)
	{
		case 1:
			{			
			int band,valor,opc,a=0,b=0,cond=1,cond_1=1;
			do{
			cond=1;
				do{
					band=1;
					system("cls");
					cout<<"-------------Digite la opcion----------";
					cout<<"\n\n1.- Boleta por Nombre";
					cout<<"\n2.- Boleta por DNI";	
					cout<<"\n3.- Retornar\n\n";
					cin>>a;
					if(a>3 or a<1)
					{
						cout<<"\n\nOpcion Invalida\n\n";
						band=0;
					}
					}while(band==0);
			system("cls");
	
			switch(a)
			{
				case 1:	
					cout<<"Seleccione el nombre del cliente";
					for (int i = 0; i < 100; i++) 
					{
					if(G.cliente[i].nombre=="")
					{
						break;
					}
					cout<<"\n\n"<<i+1<<".-"<<G.cliente[i].nombre;	
					}
					cout<<"\n\n";	cin>>b;	
					cout<<"\n\n";	mostrar_boleta(b,G);cout<<"\n\n";
		
					do{			
						cond_1=1;
						cout<<"\n\n1.- Retornar";
						cout<<"\n2.- Salir\n\n";	
						cin>>c;
						if(c>2 or c<1)
						{
							cout<<"\n\nOpcion Invalida\n\n";
							cond_1=0;
						}
						}while(cond_1==0);			
						system("cls");
								
							switch(c)
							{
							case 1:
								
								return 0;
								
								break;
							
							case 2:
								exit(0);
								break;
							}
				break;
				
				case 2:
					cout<<"Seleccione el DNI del cliente";
						for (int j = 0; j < 100; j++) 
						{
							if(G.cliente[j].DNI=="")
							{
								break;
							}
							cout<<"\n\n"<<j+1<<".-"<<G.cliente[j].DNI;		
						}
						cin>>b;
						cout<<"\n\n";
						mostrar_boleta(b,G);
						break;
				
				case 3:
					return 0;
					break;	
			}	
			}while(cond==0);		
		break;}
//------------------------------------------------------------------------------------------
		
		case 2:
			{			
			int band,valor,opc,a=0,b=0,cond=1,cond_1=1;
			system("cls");
			do{
			cond=1;
				do{
					int t=0;
					band=1;					
					cout<<"-------------Seleccione el Producto----------";
					cout<<"\n\n";
					for (t; t < 100; t++) 
					{
					if(G.producto[t].nombre=="")
					{
						break;
					}
					cout<<"\n"<<t+1<<".-"<<G.producto[t].nombre;	
					}
					cout<<"\n";
					cin>>a;
					if(a>t || a<0)
					{
						cout<<"\n\nOpcion Invalida\n\n";
						band=0;
					}
					}while(band==0);
				
				system("pause");
				system("cls");
				cout<<"\n----------------Especificaciones del Producto------------------------ ";	
				cout<<"\n\n\nNombre de producto: "<<G.producto[a-1].nombre;
				cout<<"\nCodigo de producto: "<<G.producto[a-1].codigo;
				cout<<"\nTipo de producto: "<<G.producto[a-1].tipo;
				cout<<"\nPrecio de producto: "<<G.producto[a-1].precio;
				cout<<"\nStock del producto: "<<G.producto[a-1].stock;
				
				do{
				cout<<"\n\n\n\n1.-Retornar";
				cout<<"\n2.-Menu Administrador";
				cout<<"\n3.-Salir\n\n";
				cin>>valor;
			    }while(valor>3&&valor<1);
				cout<<"\n";
				if(valor==1){cond=0;}
				else
				{if(valor==2){return 0;}
				 else{exit(0);}}
				cout<<"\n";
				system("pause");
				system("cls");
					
		}while(cond==0);
	
			
		
			break;}
//------------------------------------------------------------------------------------------
			
		case 3:
			
		{			
			int band,valor,opc,z=0,b=0,cond,cond_1;
			system("cls");
			do{
			cond=1;
				do{
					int t=0;
					band=1;					
					cout<<"-------------Seleccione el Producto a Modificar----------";
					cout<<"\n\n";
					for (t; t < 100; t++) 
					{
					if(G.producto[t].nombre=="")
					{
						break;
					}
					cout<<"\n"<<t+1<<".-"<<G.producto[t].nombre;	
					}
					cout<<"\n";
					cin>>z;
					if(z>t || z<0)
					{
						cout<<"\n\nOpcion Invalida\n\n";
						band=0;
					}
					}while(band==0);
				
				system("pause");
				system("cls");
				do{	
				cout<<"\n----------------Seleccione que modificar del Producto------------------------ ";
				cout<<"\n\n\n1.-Nombre de producto: "<<G.producto[z-1].nombre;
				cout<<"\n2.-Codigo de producto: "<<G.producto[z-1].codigo;
				cout<<"\n3.-Tipo de producto: "<<G.producto[z-1].tipo;
				cout<<"\n4.-Precio de producto: "<<G.producto[z-1].precio;
				cout<<"\n5.-Stock del producto: "<<G.producto[z-1].stock;
				cout<<"\n6.Cancelar";
				cout<<"\n7.Menu Administrador"<<"\n\n";
				cin>>cond_1;
				}while(cond_1>7&&cond_1<1);
				
				if(cond_1==6 or cond_1==7)
				{
					if(cond_1==6){cond=0;}	
					else{return 0;
					}
				}
				else
				{
				switch(cond_1)
					{
						case 1:{
						
						    string palabra;
						    fflush(stdin);
						    cout<<"\n-----------------Modificando el nombre del Producto-------------\n\n";
						    cout<<"Escriba el nuevo nombre del Producto: ";
						    getline(cin,palabra);
						    G.producto[z-1].nombre=palabra;
						    
							break;
						}
						case 2:
							{
						
						    string cod;
						    fflush(stdin);
						    cout<<"\n-----------------Modificando el codigo del producto-------------\n\n";
						    cout<<"Escriba el nuevo codigo del Producto: ";
						    getline(cin,cod);
						    G.producto[z-1].codigo=cod;
							break;
						}
							
						case 3:
							{
						
						    string tip;
						    fflush(stdin);
						    cout<<"\n-----------------Modificando el tipo del producto-------------\n\n";
						    cout<<"Escriba el nuevo tipo del Producto: ";
						    getline(cin,tip);
						    G.producto[z-1].tipo=tip;
							break;
						}
						case 4:
							{
						    float precio_1;
						    cout<<"\n-----------------Modificando el precio del producto-------------\n\n";
						    cout<<"Escriba el nuevo precio del Producto: ";
						    cin>>precio_1;
						    G.producto[z-1].precio=precio_1;
							break;
						}
						case 5:
							{
						    float stock_1;
						    cout<<"\n-----------------Modificando el stock del producto-------------\n\n";
						    cout<<"Escriba el nuevo stock del Producto: ";
						    cin>>stock_1;
						    G.producto[z-1].stock=stock_1;
							break;
						}						
					}
			cout<<"\n\n-Especificaciones del producto modificado-------------\n\n\n";
						    cout<<"\n\n\nNombre de producto: "<<G.producto[z-1].nombre;
							cout<<"\nCodigo de producto: "<<G.producto[z-1].codigo;
							cout<<"\nTipo de producto: "<<G.producto[z-1].tipo;
							cout<<"\nPrecio de producto: "<<G.producto[z-1].precio;
							cout<<"\nStock del producto: "<<G.producto[z-1].stock;
							cout<<"\n\n";	
							system("pause");			
			}
				
			cout<<"\ncond: "<<cond<<"\n";		
			if(cond==1)
			{
				do{
				cout<<"\n\n\n\n1.-Retornar";
				cout<<"\n2.-Menu Administrador";
				cout<<"\n3.-Salir\n\n";
				cin>>valor;
			    }while(valor>3&&valor<1);
				cout<<"\n";
				
				if(valor==1)
					{cond=0;}
				else
					{if(valor==2)
						{return 0;}
					else
					{exit(0);}}
				cout<<"\n";
				system("pause");
				system("cls");
					}
			else{
				system("cls");
			}		
						
					
							
					
		}while(cond==0);

			
		
			break;}
//------------------------------------------------------------------------------------------
		case 4:
			{			
			int band,valor,opc,z=0,b=0,cond,cond_1=1,t;
			system("cls");
			do{
			cond=1;
				do{
					t=0;
					band=1;	
					cout<<"\n\n";
					for (t; t < 100; t++) 
					{
					if(G.producto[t].nombre=="")
					{
						break;
					}	
					}
					}while(band==0);
				
				system("cls");
				do{	
				cout<<"\n--------------------------------------------- \n\n\n";
				cout<<"\nSeleccione";
				cout<<"\n\n\n1.-Ingresar datos del nuevo producto ";
				cout<<"\n2.Menu Administrador"<<"\n\n";
				cin>>cond_1;
				}while(cond_1>2&&cond_1<1);
				
				if(cond_1==2)
				{
					return 0;
				}
				else
				{
				
						    string pal,tipo_1,cod_1;
						    float precio_2,stock_2;
						    
						   
						    
						    fflush(stdin);
						    cout<<"\n-----------------Nombre del Producto-------------\n\n";
						    cout<<"Escriba el nuevo nombre del Producto: ";
						    getline(cin,pal);
						    G.producto[t-1].nombre=pal;
						 	
						 	 fflush(stdin);
						 	cout<<"\n-----------------Codigo del producto-------------\n\n";
						    cout<<"Escriba el nuevo codigo del Producto: ";
						    getline(cin,cod_1);
						    G.producto[t-1].codigo=cod_1;
						 
						 	fflush(stdin);
						    cout<<"\n-----------------Tipo del producto-------------\n\n";
						    cout<<"Escriba el nuevo tipo del Producto: ";
						    getline(cin,tipo_1);
						    G.producto[t-1].tipo=tipo_1;
						 
						 	fflush(stdin);
						    cout<<"\n-----------------Precio del producto-------------\n\n";
						    cout<<"Escriba el nuevo precio del Producto: ";
						    cin>>precio_2;
						    G.producto[t-1].precio=precio_2;
						    
							fflush(stdin);
						    cout<<"\n-----------------Stock del producto-------------\n\n";
						    cout<<"Escriba el nuevo stock del Producto: ";
						    cin>>stock_2;
						    G.producto[t-1].stock=stock_2;
						    
						    cout<<"\n\n";
				system("pause");
				system("cls");
				cout<<"\n\n-Nuevo producto-------------\n\n\n";
						    cout<<"\n\n\nNombre de producto: "<<G.producto[t-1].nombre;
							cout<<"\nCodigo de producto: "<<G.producto[t-1].codigo;
							cout<<"\nTipo de producto: "<<G.producto[t-1].tipo;
							cout<<"\nPrecio de producto: "<<G.producto[t-1].precio;
							cout<<"\nStock del producto: "<<G.producto[t-1].stock;
							cout<<"\n\n";												
					}	
					
					
				if(cond==1)
				{
					do{
				cout<<"\n\n\n\n1.-Retornar";
				cout<<"\n2.-Menu Administrador";
				cout<<"\n3.-Salir\n\n";
				cin>>valor;
			    }while(valor>3&&valor<1);
				cout<<"\n";
				
				if(valor==1)
					{cond=0;}
				else
					{if(valor==2)
						{return 0;}
					else
					{exit(0);}}
				cout<<"\n";
				system("pause");
				system("cls");
					}	
				else
				{system("cls");}		
					
				}while(cond==0);
		
			break;}
//------------------------------------------------------------------------------------------
		case 5:
		{			
			int band,valor,opc,a,b=0,cond,cond_1=1,t;
			system("cls");
			do{
			cond=1;
				do{
					t=0;
					band=1;					
					cout<<"-------------Seleccione el Producto a eliminar----------";
					cout<<"\n\n";
					for (t; t < 100; t++) 
					{
					if(G.producto[t].nombre=="")
					{
						break;
					}
					cout<<"\n"<<t+1<<".-"<<G.producto[t].nombre;	
					}
					cout<<"\n";
					cin>>a;
					if(a>t || a<0)
					{
						cout<<"\n\nOpcion Invalida\n\n";
						band=0;
					}
					}while(band==0);
				t=a;
				system("cls");
				do{	
					cout<<"\n--------------------------------------------- \n\n\n";
					cout<<"\nSeleccione";
					cout<<"\n\n\n1.-Eliminar ";
					cout<<"\n2.Cancelar";
					cout<<"\n3.Menu Administrador"<<"\n\n";
					cin>>cond_1;
					}while(cond_1>3&&cond_1<1);
				
				
				
				if(cond_1!=1)
				{
					if(cond_1==2){cond=0;}	
					else{return 0;
					}
				}
				else
				{		for(t;t<99;t++)
						{  G.producto[t-1].nombre=G.producto[t].nombre;						 							 	
						    G.producto[t-1].codigo=G.producto[t].codigo;												 	
						    G.producto[t-1].tipo=G.producto[t].tipo;						 	
						    G.producto[t-1].precio= G.producto[t].precio;
						    G.producto[t-1].stock=G.producto[t].stock;
					    }
					    system("cls");
					    cout<<"---------------Producto eliminado---------------";
						    cout<<"\n\n\n";
																
					}	
					
				if(cond==1)
				{
						do{
							
							cout<<"Que se hara acontinuacion?";
							cout<<"\n\n\n1.-Seleccionar nuevo producto a eliminar";
							cout<<"\n2.-Menu Administrador";
							cout<<"\n3.-Salir\n\n";
							cin>>valor;
						    }while(valor>3&&valor<1);
						cout<<"\n";
					
					if(valor==1)
						{cond=0;}
					else
						{if(valor==2)
							{return 0;}
						else
						{exit(0);}}
					cout<<"\n";
					system("pause");
					system("cls");
					}	
				else
				{system("cls");}		
					
				}while(cond==0);
		
			break;}
//------------------------------------------------------------------------------------------
		case 6:
		{
		system("cls");
		return 1;
		break;}
		
		case 7:
		{
		exit(0);
		break;}
		
	}
	
}


//Funcion de medios de pago

char menuMediosPago() {
    cout << "Seleccione un medio de pago:" << endl;
    cout << "1. Medios de pago en efectivo:" << endl;
    cout << "   a. Efectivo (moneda nacional)" << endl;
    cout << "   b. Moneda extranjera" << endl;
    cout << "2. Tarjetas bancarias:" << endl;
    cout << "   a. Tarjeta bancaria (cr?dito o d?bito)" << endl;
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
