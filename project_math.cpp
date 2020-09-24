#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

using namespace std;

void crear_tabla(int ini,int fin){
	
	int cont_gl=0;
	int acum_gl=0;
	int contador_1=0;
	int limit = 1;
	int ciclo = 0;
	int op_1=0;
	int op_2=1;
	int res;
	
	inicio:
	
	while(contador_1<fin){
		
		cout<<"Tabla del <"<<ini<<">\t";
		contador_1++;
		cont_gl++;
		acum_gl++; //No lo usamos internamente.
		ini++;
		
		if(cont_gl%5==0){
			goto tablas;
		}
	}
	
	tablas:	
	cout<<endl;
	cont_gl=0;
		
	while(op_2<=10){
		
		op_1++;
		
		if(ciclo>0){
			op_1+=ciclo*5;
		}
		
		res=op_1*op_2;
		cout<<op_1<<" x "<<op_2<<" = "<<res<<"\t";
		
		if(ciclo>0){
			op_1-=ciclo*5;
		}
		
		if(op_1%5==0){
			cout<<endl;
			op_2++;
			op_1=0;
		}
	}
	
	cout<<endl;
	
	if(acum_gl<fin){
		
		ciclo++;
		op_2=1;
		goto inicio;
	}
	
	system("PAUSE");
}

int crear_nivel(int rango, string dificultad){
	
	int num1,num2,resul;
	int dato=0;
	srand(time(NULL));
	
	int intentos=3;
	int puntos=0;
	
	for(int i=1;i<11;i++){
		
		if (intentos==0){
			
			system("cls");
			cout<<"bichito de luz , has muerto";
		
			for (int j=0;j<1;j++){
				
				Sleep(1000);
			}
			break;
		}
		
	num1=1+rand()%(rango+1);
	num2=1+rand()%(rango+1);
	resul=num1*num2;
	
	cout<<"Dificultad: "<<dificultad<<"\t\t";
	cout<<"Intentos: "<<intentos<<"\t\t";
	cout<<"Puntaje: "<<puntos<<"\n\n";	
	
	cout<<"Ingresar el resultado correcto de la operacion"<<" "<<i<<"\n\n";
	cout<<num1<<"x"<<num2<<": ";	
	cin>>dato;
	fflush(stdin);	
	
	if (dato==resul){
			
		cout<<"\t<Respuesta Correcta>\n\n";	
		puntos+=100;		
		
	}else if(dato!=resul){
			
		cout<<"Incorrecto: Pierdes Vida";
		intentos--;
		}
		
	Sleep(1000);
	system("cls");	
	}
			
	system("cls");
	return puntos;
}
	
void submenu(){
	int elec;
	cin>>elec;
	
	fflush(stdin);
	
	switch (elec){
		
			case 1: 
				system("cls");
				crear_nivel(4,"Facil");
			
			case 2:
				system("cls");
				crear_nivel(7,"Intermedio");	
			
			case 3:
				system("cls");
				crear_nivel(9,"Dificil");
		}		
}
	
main(){
	
	setlocale(LC_ALL, "");
	
	int op;
	string nick;
	
	cout<<"Bienvenido! Ingresa tu nombre para continuar: ";
	cin>>nick;
	fflush(stdin);
	
	do{
		
		system("cls");
	
		cout<<"Hola "<<nick<<", bienvenido!!!\n\n";
		cout<<"Con esta aplicación podrás ejercitar tus conocimientos en matemáticas, practicar y divertirte a lo grande!\n\n";
		cout<<"Por favor selecciona la opción deseada, del menú...\n\n";
		cout<<"Opcion 1: Ver Tablas."<<endl;
		cout<<"Opcion 2: Modo desafio."<<endl;
		cout<<"Opcion 3: Salir.\n\n";
		cin>>op;
		fflush(stdin);
	
		switch(op){
		
			case 1:
		
				system("cls");
				cout<<"User: "<<nick<<".\n\n";
				crear_tabla(1,10);
				break;
			
			case 2:
				
				system("cls");
				cout<<"User: "<<nick<<".\n\n";
				cout<<"Bienvenido a la opcion desafio, esperamos que te diviertas tanto como nosotros"<<endl;
				cout<<"Elige el grado de dificultad"<<endl;
				cout<<"Opcion 1: Facil"<<endl;
				cout<<"Opcion 2: Intermedio"<<endl;
				cout<<"Opcion 3: Dificil"<<endl;
				submenu();
				break;
				
			case 3:	
				break;	
			}
		
	}while(op!=3);
			
	cout<<"\n";
	system("PAUSE");
	return EXIT_SUCCESS;	
}



