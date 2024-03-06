#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 using namespace std;

struct pilas
{
	int d;
	pilas *a;
}*c,*e;

void ingresar (void)
{

 if(!c)
 {
	 c=new(pilas);
	 cout<<"Ingrese elemento: ";
	 cin>>c->d;
	
	 c->a=NULL;
	 return;
 }
 
	 e=new(pilas);
	 cout<<"\nIngrese elemento: ";
	 cin>>e->d;
	 e->a=c;
	 c=e;
}

void ultimo(void)
{
	if(c == NULL){
		cout << "La pila esta vacia";
	}else{
		e = c;
		while(e != NULL)
		{
			if(e->a == NULL)
			{
				cout << "el primer dato ingresado fue: " << e->d;
			}
			e = e->a;
		}
	}
}

void sacar(void)
{
 if(!c)
 {
	 cout<<"\n\nNo hay elementos!!";
	 return;
 }
 
	 e=new(pilas);
	 e=c;
	 cout<<"\n\nElemento eliminado: " <<e->d;
	 c=e->a;
	 delete(e);
	 
}


void actualizar_pila(void)
{
 int y=2,i,ca=0;
 e=c;
 while(e)
 {
	 ca++;
	 e=e->a;
 	}
 
	for(i=0;i<=ca;i++)
 {
 	cout<<" ";
 }
 //muestro lo que tiene la pila!!
 i=0;
 e=c;
 while(e)
 {
	 cout<<"\n";
	 cout<<++i<<" - "<<e->d;
	 e=e->a;
 }
}

bool verifica(void){
	if(c == NULL){
		return true;
	}else{
		return false;
	}
}

int contarElementos(void){
	int contar = 0;
	pilas* temp = c;
	while(temp != NULL){
		contar++;
		temp = temp -> a;
	}
	return contar;
}

void vaciar(void){
	while(c !=NULL){
		pilas* temp = c;
		c = c->a;
		delete temp;
	}
	cout << endl;
	cout << "La pila a sido borrada.";
}

 void menu(void)
{
 int y,opc;
 for(;;)
	 {
	 cout<<"\n1. Ingresar datos";
	 cout<<"\n2. extraer datos";
	 cout<<"\n3. el ultimo salir";
	 cout<<"\n4. Verificar la lista";
	 cout<<"\n5. Contar los datos de la pila";
	 cout<<"\n6. Vaciar la pila";
	 cout<<"\n0. Terminar";
	 cout<<"\n\n Ingrese opcion: ";
	 cin>>opc;
	 switch(opc)
		 {
			 case 1:
			 ingresar();
			 break;
			 case 2: 
			 sacar();
			 break;
			 case 3: 
			 ultimo();
			 break; 
			 case 4:
                if (verifica())
                    cout << "\nLa pila esta vacia\n";
                else
                    cout << "\nLa pila NO! esta vacia\n";
                break;
             case 5:
             	cout << "La cantidad de elementos que hay en la pila es de: " << contarElementos();
             break;
             case 6:
             	vaciar();
             break;
			 case 0: 
			 exit(1);
			 default: cout<<"\n Opcion no valida!!"; break;
		 }
	 
		actualizar_pila();
		cout<<"\n\nOprima una tecla para continuar";
		getch();
		 }
}
 
 
	main()
{
	menu();
}
