#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <iostream>


   using namespace std;
int main(){
    int var,ter,pro,i,j,l,respuesta,positiva,desigual,epsilon=0;
   char terminales[5];
   char produccion[pro];
  char variable,terminal,produ,mayus,simbolo,minusc;


   do{
        //EXPLICACIÓN SOBRE LAS GRAMÁTICAS
	cout<<"Gramaticas Libres de Contexto\nDefinicion:\nG=(V,T,P,S)\nDonde:\nV:variables\nT:terminales\nP:producciones\nS:simbolo inicial."<<endl;
    cout<<"\nUna produccion es el conjunto de simbolos que genera una variable, pudiendo ser una o varias terminales y/o variables.\nLas producciones pueden contener un simbolo especial llamado epsilon, que representa un conjunto vacio."<<endl;
    cout<<"\nCuando se utilizan varios simbolos pueden aparecer concatenados o con un operador llamado OR.\nLa concatenacion nos dice que ambos simbolos aparecen en esa misma operacion.\nEl OR nos indica que han aparecido varias producciones en una misma variable."<<endl;
	cout<<"\n Por ejemplo A-->a|Ab\nA y b estan concatenadas y la produccion a con la produccion Ab estan indicadas por el simbolo OR"<<endl;
	cout<<"Las gramaticas siempre tienen una variable inicial (S), que es por donde siempre se va a iniciar."<<endl;
       cout<<"\n\nPara hacer eficiente una GLC se realiza una limpieza para poder generar un lenguaje, en el que no existan simbolos sin utilizar ni cosas por el estilo.\n Para eso se dice que la gram�tica tiene que ser positiva y admisible.\nPositividad: que no exista ningun simbolo especial o epsilon\nAdmisible:que todas las variables definidas a la derecha (en la produccion) esten definidas tambien a la izquierda (en las variables)"<<endl;
   cout<<"Existen dos formas de representar las GLC una vez hechas admisibles y positivas: Forma Normal de Chomsky (FNC) y Forma Normal de Greibach (FNG)"<<endl;
   cout<<"FNC:se representa por una terminal o dos variables A-->a|AB\nFNG: se representa por una terminal seguida de cero o m�s variables A-->a|aA|aAB...\n"<<endl;
   cout<<"\nPaso 1: Hacer positiva la gramatica.\nDebemos eliminar el simbolo especial o epsilon.\n1.-Identificamos la variable que contenga el simbolo.\n2.-Identificamos las producciones que contengan dicha variable\n3.-Sustituimos en la produccion la variable por su equivalente\n4.-Volvemos a escribir la produccion con la variable y sin la variable, utilizando OR para separalo.\n5.-Se repite hasta eliminar epsilon de la gramatica."<<endl;
   cout<<"\n1.-A-->a\nB-->A|C\nC-->{\n2.-La variable que contiene el simbolo es C\n3.-A-->a\nB-->A|C|{\n\nA-->a\nB-->A|C\n\nPodemos ver que se elimino { y la variable que la tenia, asi que esta gramatica ya es positiva. Ahora hay que hacerla admisible"<<endl;
   cout<<"\nPara hacerla admisible solo hay que eliminar las variables que no aparecen en ambos lados.\nA-->a\nEsta gramatica ya es positiva, adisible y esta en su forma normal de Greibach y de Chomsky"<<endl;
	cout<<"Un automata de pila es una septupla AP([,T,Q,Ao,qo,f,F)\nDonde:\n[=Simbolos de entrada\nT=Simbolos de pila\nQ=Conjunto de estados\nAo=Simbolo inicial\nqo=Estado inicial\nf=Funcion de transicion\nF=Estados finales"<<endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//INGRESO DE DATOS PARA CONSTRUIR LA GRAMÁTICA(VARIABLES, TERMINALES) i j
		    cout<<"Ingresa la variable (mayuscula)\n"<<endl;
			cin>>variable;
			cout<<"\n\nIngresa el numero de TERMINALES(maximo 5):"<<endl;
			cin>>ter;
		if(ter==1){
			cout<<"Ingresa la terminal (letra minuscula)"<<endl;
			cin>>terminal;
		}
		if(ter>1){
			for(i=0;i<ter;i++){
			cout<<"Ingresa la terminal "<<i+1<<" de la variable (letra minuscula)"<<endl;
			cin>>terminales[i];
			}
	}
            cout<<"Ingresa el numero de producciones de la variable"<<endl;
			cin>>pro;
			produccion[0]=variable;
			cout<<"\nNOTA:Si vas a ingresar el conjunto vacio o epsilon, ingresa ({)"<<endl;
		for(i=1;i<=pro;i++){
			    cout<<"Ingresa la produccion "<<i<<"de la variable"<<endl;
				cin>>produccion[i];
			}
		cout<<"\n"<<produccion[0]<<"-->";
        for(j=1;j<=pro;j++){
   		    cout<<produccion[j]<<"|";
	        }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//DETERMINA SI LA GRAMATICA ES POSITIVA p q

        positiva=0;

    for(i=1;i<=pro;i++){
        if(produccion[i]=='{'){
             cout<<"Tu gramatica no es positiva, hay una epsilon ({)en "<<produccion[0]<<endl;
             epsilon=1;
    }
    else{
    	positiva++;
	}
    
   }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //SI LA GRAMATICA ES POSITIVA, DETERMINA SI ES ADMISIBLE a b

      if(positiva==pro){

        simbolo=produccion[0];
        for(i=1;i<=pro;i++){
            if(produccion[i]>='A'&&produccion[i]<='Z'){
                mayus=produccion[i];
                cout<<mayus;
                if(mayus!=simbolo){
                        desigual++;
                }
                         }
             else if(produccion[i]>='a'&&produccion[i]<='z')
             {
             	desigual=0;
			 }
            
        }
        if(desigual==0){
            cout<<"\nFelicidades, tu gramatica ya es positiva y admisible"<<endl;
        }
        else{
            cout<<"Tu gramatica aun no es admisible"<<endl;
        }
    }

    


            cout<<"\n[="<<produccion[0];
            cout<<"\n";
    if(ter==1){
        cout<<"T="<<terminal<<endl;
    }
    else if(ter>1){
            cout<<"T=";
    for(i=0;i<ter;i++){
        cout<<terminales[i]<<", ";
    }
    }
    cout<<"\nS="<<simbolo<<endl;
    cout<<"Q=";
    cout<<"\n"<<produccion[0]<<"-->";
        for(j=1;j<=pro;j++){
   		    cout<<produccion[j]<<"|";
	        }


   cout<<"\nQué deseas hacer?\n1.-Iniciar gramatica\n2.-Salir"<<endl;
   cin>>respuesta;
   }
   while(respuesta!=2);

   getch();
   return 0;}

