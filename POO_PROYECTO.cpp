/* PROYECTO FERRETERIA CHICHOX
lENGUAJE PROGRAMACION ORIENTADA A OBJETOS
INTEGRANTES: 
             PEREZ SEQUEIROS, DAVID GABRIEL
             PALOMINO LIPA, ARTURO LUIGI 
             SERECEDA PANDURO, FLOR ALEXA 
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

struct articulo{
	string nombre;
	string proveedor;
	float precio;
	int cantidad;
	int vendido;
};

struct cliente{
	string nombre;
	string apellidos;
	string cargo;
	int dni;
	string codigo;
};

class Factura{
	private:
		cliente C;
		articulo A;
		float cantidad;
		float total;
	public:
		Factura(cliente _C,articulo _A,float _cantidad,float _total){
			C=_C;
			A=_A;
			cantidad=_cantidad;
			total=_total;
		}
		void mostrarDetalles(){
			system("cls");
			cout<<endl;
			cout<<"--- FACTURA DE VENTA ---"<<endl;
			cout<<endl;
			cout<<"FECHA          : 18 de diciembre del 2022"<<endl;
			cout<<"VENDEDOR       : "<<C.nombre<<" "<<C.apellidos<<endl;
			cout<<"NUMERO FACTURA : "<<rand()%(9999-1000+1)+1000<<endl;
			cout<<endl;
			cout<<"--- PRODUCTO VENDIDO ---"<<endl;
			cout<<"NOMBRE         : "<<A.nombre<<endl;
			cout<<"PROVEEDOR      : "<<A.proveedor<<endl;
			cout<<"PRECIO         : "<<A.precio<<endl;
			cout<<"CANTIDAD       : "<<cantidad<<endl;
			cout<<endl;
			cout<<"IMPORTE BRUTO     : "<<total<<endl;
			cout<<"DESC NAVIDAD(10%) : "<<total*10.0/100.0<<endl;
			cout<<"IMPORTE PAGAR     : "<<total-(total*10.0/100.0)<<endl;
		}
};

//prototipos 

int  agregarVendedor(cliente V[],int v);
int  agregarArticulo(articulo A[],int a);
void mostrarProductos(articulo A[],int a);
void buscarVendedor(cliente V[],int v);
int eliminarVendedor(cliente V[],int v);
void buscarArticulo(articulo A[],int a);
void stockProductos(articulo A[],int a);
void mostrarVendedor(cliente V[],int v);
void editar_vendedor(cliente V[],int v);
void venderArticulo(articulo A[],int a,cliente V[],int v);
void masVendidos(articulo A[],int a);
void menu_principal();

int main(){
	
	srand(time(NULL));   
	menu_principal();	
	
	return 0;
}

int agregarVendedor(cliente V[],int v){
	cliente temp;
	system("cls");
	cout<<endl;
	cout<<"--- AGREGAR EMPLEADO ---"<<endl;
	cout<<endl;
	cout<<"Digite nombres   : ";
	fflush(stdin);
	getline(cin,temp.nombre);
	cout<<"Digite apellidos : ";
	fflush(stdin);
	getline(cin,temp.apellidos);
	cout<<"Digite cargo     : ";
	fflush(stdin);
	getline(cin,temp.cargo);
	cout<<"Digite dni       : ";
	cin>>temp.dni;
	cout<<"Digite codigo    : ";
	cin>>temp.codigo;
	cout<<endl;
	cout<<"--- EMPLEADO REGISTRADO CON EXITO ---"<<endl;
	V[v]=temp;
	v+=1;
	return v;
}

int agregarArticulo(articulo A[],int a){
	articulo temp;
	temp.vendido=0;
	system("cls");
	cout<<endl;
	cout<<"--- AGREGAR ARTICULO ---"<<endl;
	cout<<endl;
	cout<<"Digite nombre          : ";
	fflush(stdin);
	getline(cin,temp.nombre);
	cout<<"Digite proveedor       : ";
	fflush(stdin);
	getline(cin,temp.proveedor);
	cout<<"Digite precio unitario : ";
	cin>>temp.precio;
	cout<<"Digite cantidad        : ";
	cin>>temp.cantidad;
	cout<<endl;
	cout<<"--- ARTICULO REGISTRADO CON EXITO ---"<<endl;
	A[a]=temp;
	a+=1;
	return a;
}

void mostrarProductos(articulo A[],int a){
	system("cls");
	cout<<endl;
	cout<<"--- LISTA DE ARTICULOS ---"<<endl;
	cout<<endl;
	if(a>0){
		for(int i=0;i<a;i++){
			cout<<"NOMBRE    : "<<A[i].nombre<<endl;
			cout<<"PROVEEDOR : "<<A[i].proveedor<<endl;
			cout<<"PRECIO    : "<<A[i].precio<<endl;
			cout<<"CANTIDAD  : "<<A[i].cantidad<<endl;
			cout<<"VENDIDOS  : "<<A[i].vendido<<endl;
			cout<<endl;
		}
	}
	else cout<<"--- LISTA DE ARTICULOS VACIA ---"<<endl;
}

void buscarVendedor(cliente V[],int v){
	string nombre;
	system("cls");
	cout<<endl;
	cout<<"--- BUSCAR VENDEDOR ---"<<endl;
	cout<<endl;
	if(v>0){
		cout<<"Digite nombre: ";
		fflush(stdin);
		getline(cin,nombre);
		cout<<endl;
		for(int i=0;i<v;i++){
			if(V[i].nombre==nombre){
				cout<<"NOMBRE    : "<<V[i].nombre<<endl;
				cout<<"APELLIDOS : "<<V[i].apellidos<<endl;
				cout<<"CARGO     : "<<V[i].cargo<<endl;
				cout<<"DNI       : "<<V[i].dni<<endl;
				cout<<"CODIGO    : "<<V[i].codigo<<endl;
				return;
			}
		}
		cout<<"--- NO SE ENCONTRO VENDEDOR CON ESE NOMBRE ---"<<endl;
	}
	else cout<<"--- LISTA DE VENDEDORES VACIA ---"<<endl;
}

void buscarArticulo(articulo A[],int a){
	string nombre;
	system("cls");
	cout<<endl;
	cout<<"--- BUSCAR ARTICULO ---"<<endl;
	cout<<endl;
	if(a>0){
		cout<<"Digite nombre: ";
		fflush(stdin);
		getline(cin,nombre);
		cout<<endl;
		for(int i=0;i<a;i++){
			if(A[i].nombre==nombre){
				cout<<"NOMBRE    : "<<A[i].nombre<<endl;
				cout<<"PROVEEDOR : "<<A[i].proveedor<<endl;
				cout<<"PRECIO    : "<<A[i].precio<<endl;
				cout<<"CANTIDAD  : "<<A[i].cantidad<<endl;
				cout<<"VENDIDOS  : "<<A[i].vendido<<endl;
				return;
			}
		}
		cout<<"--- NO SE ENCONTRO ARTICULO CON ESE NOMBRE ---"<<endl;
	}
	else cout<<"--- LISTA DE PRODUCTOS VACIA ---"<<endl;
}

void stockProductos(articulo A[],int a){
	system("cls");
	cout<<endl;
	cout<<"--- STOCK DE ARTICULOS ---"<<endl;
	cout<<endl;
	if(a>0){
		for(int i=0;i<a;i++){
			cout<<"NOMBRE    : "<<A[i].nombre<<" -> STOCK  : "<<A[i].cantidad<<endl;
		}
	}
	else cout<<"--- LISTA DE ARTICULOS VACIA ---"<<endl;
}

void mostrarVendedor(cliente V[],int v){
	system("cls");
	cout<<endl;
	cout<<"--- LISTA DE VENDEDORES ---"<<endl;
	cout<<endl;
	if(v>0){
		for(int i=0;i<v;i++){
			cout<<"NOMBRE    : "<<V[i].nombre<<endl;
			cout<<"APELLIDOS : "<<V[i].apellidos<<endl;
			cout<<"CARGO     : "<<V[i].cargo<<endl;
			cout<<"DNI       : "<<V[i].dni<<endl;
			cout<<"CODIGO    : "<<V[i].codigo<<endl;
			cout<<endl;
		}
	}
	else cout<<"--- LISTA DE EMPLEADOS VACIA ---"<<endl;
}

void editar_vendedor(cliente V[],int v){
	int dni;

	system("cls");
	cout<<endl;
	cout<<"---------- EDITAR TRABAJADOR ----------"<<endl;
	cout<<endl;
	cout<<"  Digite DNI: ";
	cin>>dni;
	for(int i=0;i<v;i++){
		if(V[i].dni==dni){
			system("cls");
			cout<<endl;
			cout<<"--------- EDITAR EMPLEADO ---------"<<endl;
			cout<<endl;
			cout<<"  -> DATOS ACTUALES"<<endl;
			cout<<endl;
			cout<<"NOMBRE    : "<<V[i].nombre<<endl;
			cout<<"APELLIDOS : "<<V[i].apellidos<<endl;
			cout<<"CARGO     : "<<V[i].cargo<<endl;
			cout<<"DNI       : "<<V[i].dni<<endl;
			cout<<"CODIGO    : "<<V[i].codigo<<endl;
			cout<<endl;
			cout<<"  -> NUEVOS DATOS"<<endl;
			cout<<"Digite nombres   : ";
			fflush(stdin);
			getline(cin,V[i].nombre);
			cout<<"Digite apellidos : ";
			fflush(stdin);
			getline(cin,V[i].apellidos);
			cout<<"Digite cargo     : ";
			fflush(stdin);
			getline(cin,V[i].cargo);
			cout<<"Digite dni       : ";
			cin>>V[i].dni;
			cout<<"Digite codigo    : ";
			cin>>V[i].codigo;
			cout<<endl;
			return;
		}
	}
	cout<<endl;
	cout<<"  ------- NO SE ENCONTRO VENDEDOR CON ESE DNI -------"<<endl;
}

int eliminarVendedor(cliente V[],int v){
	int opcion,dni;
	system("cls");
	cout<<endl;
	cout<<"--------- ELIMINAR VENDEDOR ---------"<<endl;
	cout<<endl;
	cout<<"  Digite DNI: ";
	cin>>dni;
	
	for(int i=0;i<v;i++){
		if(V[i].dni==dni){
			system("cls");
			cout<<endl;
			cout<<"============================================"<<endl;
			cout<<"             ELIMINAR VENDEDOR              "<<endl;
			cout<<"============================================"<<endl;
			cout<<endl;
			cout<<"NOMBRE    : "<<V[i].nombre<<endl;
			cout<<"APELLIDOS : "<<V[i].apellidos<<endl;
			cout<<"CARGO     : "<<V[i].cargo<<endl;
			cout<<"DNI       : "<<V[i].dni<<endl;
			cout<<"CODIGO    : "<<V[i].codigo<<endl;
			cout<<endl;
			cout<<"  [1]: ELIMINAR"<<endl;
			cout<<"  [2]: CANCELAR"<<endl;
			cout<<endl;
			do{
				cout<<"  Digite numero de opcion: ";
				cin>>opcion;
			}while(opcion!=1 && opcion!=2);
			
			if(opcion==1){
				system("cls");
				cout<<endl;
				cout<<"---------- VENDEDOR ELIMINADO CON EXITO ----------"<<endl;
				cout<<endl;
				cout<<"NOMBRE    : "<<V[i].nombre<<endl;
				cout<<"APELLIDOS : "<<V[i].apellidos<<endl;
				cout<<"CARGO     : "<<V[i].cargo<<endl;
				cout<<"DNI       : "<<V[i].dni<<endl;
				cout<<"CODIGO    : "<<V[i].codigo<<endl;
				cout<<endl;	
				for(int j=i;j<v-1;j++){
					V[j]=V[j+1];
				}
				return v-1;	
			}
			return v;
		}
	}
	cout<<endl;
	cout<<"---------- NO EXISTE VENDEDOR CON ESE DNI ----------"<<endl;
	return v;
}

void venderArticulo(articulo A[],int a,cliente V[],int v){
	string nombre;
	int cantidad;
	system("cls");
	cout<<endl;
	cout<<"--- VENDER ARTICULO ---"<<endl;
	cout<<endl;
	if(v==0){
		cout<<"--- ACTUALMENTE NO HAY NINGUN VENDEDOR, VUELVA DESPUES ---"<<endl;
		return;
	}
	int index=rand()%((v-1)-0+1)+0; 
	cout<<"============================================"<<endl;
	cout<<"VENDEDOR = "<<V[index].nombre<<" "<<V[index].apellidos<<endl;
	cout<<"============================================"<<endl;	
	cout<<endl;
	cout<<"Digite nombre de articulo a vender : ";
	fflush(stdin);
	getline(cin,nombre);
	for(int i=0;i<a;i++){
		if(A[i].nombre==nombre){
			cout<<endl;
			cout<<"PROVEEDOR : "<<A[i].proveedor<<endl;
			cout<<"PRECIO    : "<<A[i].precio<<endl;
			cout<<"CANTIDAD  : "<<A[i].cantidad<<endl;
			cout<<"VENDIDOS  : "<<A[i].vendido<<endl;
			cout<<endl;
			do{
				
				cout<<"Digite cantidad de productos       : ";
				cin>>cantidad;
			}while(cantidad<0);
			if(A[i].cantidad-cantidad>=0){
				Factura F(V[index],A[i],cantidad,cantidad*A[i].precio);
				F.mostrarDetalles();
				A[i].vendido+=cantidad;	
				A[i].cantidad-=cantidad; 
			}
			else cout<<endl<<"--- NO CONTAMOS CON ESA CANTIDAD ---"<<endl;
			return;
		}
	}
	cout<<endl;
	cout<<"--- NO SE ENCONTRO EL ARTICULO ---"<<endl;
}

void masVendidos(articulo A[],int a){
	articulo array[100];
	for(int i=0;i<a;i++) array[i]=A[i];
	
	for(int i=0;i<a;i++){
		for(int j=0;j<a-1;j++){
			if(array[j].vendido<array[j+1].vendido){
				articulo aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
	
	system("cls");
	cout<<endl;
	cout<<"--- LISTA DE ARTICULOS MAS VENDIDOS ---"<<endl;
	cout<<endl;
	if(a==0) cout<<"--- LISTA DE ARTICULOS VACIA ---"<<endl;
	else{
		for(int i=0;i<a;i++){
			cout<<"Puesto "<<i+1<<") "<<setw(15)<<array[i].nombre<<setw(20)<<" ===> Cantidad = "<<array[i].vendido<<endl;
		}
	}
}


void menu_principal(){
	string opcion;
	
	//articulos
	articulo ARTICULOS[100]; 
	int a=0;
	
	//vendedores
	cliente VENDEDORES[100];
	int v=0;
	
	do{
		system("color 1F");
		system("cls");
		cout<<endl;
		cout<<"======================================================"<<endl;
		cout<<"-------------  FERRETERIA MADRE DE DIOS   ------------"<<endl;
		cout<<"======================================================"<<endl;
		cout<<endl;
        cout<<"[1]: AGREGAR TRABAJADOR"<<endl;		
        cout<<"[2]: AGREGAR PRODUCTO"<<endl; 		
        cout<<"[3]: VENDER"<<endl;
		cout<<"[4]: BUSCAR PRODUCTO"<<endl;
		cout<<"[5]: BUSCAR TRABAJADOR"<<endl;
		cout<<"[6]: MOSTRAR PRODUCTOS"<<endl;
		cout<<"[8]: MOSTRAR TRABAJADOR"<<endl;
		cout<<"[9]: EDITAR TRABAJADOR"<<endl;
		cout<<"[10]: ELIMINAR TRABAJADOR"<<endl;
	    cout<<"[11]: PRODUCTO MAS VENDIDO"<<endl;
	    cout<<"[12]: STOCK DE PRODUCTO"<<endl;
		cout<<"[0]: SALIR"<<endl;
		cout<<endl;
		cout<<"Digite opcion: ";
		fflush(stdin);
		cin>>opcion;
			
		if(opcion=="1") v=agregarVendedor(VENDEDORES,v);
		if(opcion=="2") a=agregarArticulo(ARTICULOS,a);  
		if(opcion=="3") venderArticulo(ARTICULOS,a,VENDEDORES,v);
		if(opcion=="4") buscarArticulo(ARTICULOS,a);
		if(opcion=="5") buscarVendedor(VENDEDORES,v);
		if(opcion=="6") mostrarProductos(ARTICULOS,a);
		if(opcion=="8") mostrarVendedor(VENDEDORES,v);
		if(opcion=="9") editar_vendedor(VENDEDORES,v);
		if(opcion=="10") v=eliminarVendedor(VENDEDORES,v);
		if(opcion=="11") masVendidos(ARTICULOS,a);
		if(opcion=="12") stockProductos(ARTICULOS,a);
		
		if(opcion=="0") return;
		
		cout<<endl<<endl;
		system("pause");
	}while(opcion!="0");
}
