#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>

using namespace std;

void introducirDatosIniciales();

void condicionesTiempoCero();

void vaciarMatriz();

void calculoDeTemperaturas(int,int,int);

void DominioCircular();

void malladoMatlab();

void iteradorYarchivador();

void flujoDeCalor();

double funcionTemporal(int,int,int);

void detector();

double calor_x_t[400][400][2],flujo_x_y[400][400];

	const double e=2.71828182845904523536;
	const double pi=3.14159265358979323846;
	
	double longitudx=0,longitudy=0,tiempo=0,hx=0,hy=0,ht=0,k=0,fx0=0,fxl=0,ax0=0,axl=0,fy0=0,fyl=0,ay0=0,ayl=0,densidad=0,cp=0;
	
	double aux=0,aux1=0,aux2=0,coefa=0,coefb=0,coefc=0,alfa=0,estabilidad=0,temp1[4]={0,0,0,0},temp2[4]={0,0,0,0},temp3[4]={0,0,0,0},temp4[4]={0,0,0,0};
	
	int pasosx=0,pasosy=0,pasost=0,eleccionxi=0,eleccionxd=0,eleccionyi=0,eleccionyd=0,eleccion=0,eleccionFuncion=0,contador=0,eleccionTemp[4]={0,0,0,0};
	
	int main(){

	
		vaciarMatriz();
	
		introducirDatosIniciales();
	
		condicionesTiempoCero();
	
		flujoDeCalor();
	
		malladoMatlab();
	
		getch();
		return 0;

	}

void introducirDatosIniciales(){
	

	
		cout<<"Por favor introduzca si la condiciones del contorno 'izquierdo' para la dimension 'x' seran del 1er, 2do o 3er tipo"<<endl;
		cout<<"1___________1er tipo = temperatura definida como funcion del tiempo en el limite izquierdo."<<endl;
		cout<<"2___________2do tipo = (-k)d(T)/dx = Q0 (convencion de signos: + flujo entrante ; - flujo saliente)"<<endl;
		cout<<"3___________3er tipo = (k)d(T)/dx = h(Tambiente - T)"<<endl;
		cout<<"0____________SALIR"<<endl;
		
		cin>>eleccionxi;
		if(eleccionxi==2||eleccionxi==3||eleccionxi==1){
			
			switch (eleccionxi){
				case 1:
					cout<<"Por favor introduzca si la temperatura será, constante o tendrá una funcion T(t): \n";
					cout<<"1________ T(t) = constante."<<endl;
					cout<<"2________ T(t) = A . (t^B) + C"<<endl;
					cout<<"3________ T(t) = A . (sen(t.B))^C + D"<<endl;
					cout<<"4________ T(t) = A . e^(t.B) + C"<<endl;
					cin>>eleccionTemp[0];
					switch(eleccionTemp[0]){
						case 1:	
							cout<<"Por favor introduzca el valor de la temperatura en el limite izquierdo"<<endl;
							cin>>ax0;
						break;
						
						case 2:
							cout<<"\nA = ";
							cin>>temp1[0];
							cout<<"\nB = ";
							cin>>temp2[0];
							cout<<"\nC = ";
							cin>>temp4[0];
						break;
						
						case 3:
							cout<<"\nA = ";
							cin>>temp1[0];
							cout<<"\nB = ";
							cin>>temp2[0];
							cout<<"\nC = ";
							cin>>temp3[0];
							cout<<"\nD = ";
							cin>>temp4[0];
							break;
							
						case 4:
							cout<<"\nA = ";
							cin>>temp1[0];
							cout<<"\nB = ";
							cin>>temp2[0];
							cout<<"\nC = ";
							cin>>temp4[0];
							break;
					}
					break;
				case 2:
					ax0=0;
					cout<<"por favor introduzca el valor del flujo de calor en el limite izquierdo"<<endl;
					cin>>fx0;
				break;
		
				case 3:
					cout<<"por favor introduzca el valor de la constante h de conveccion en el limite 'izquierdo'"<<endl;
					cin>>ax0;
					cout<<"por favor introduzca el valor de la temperatura del fluido en el limite 'izquierdo'"<<endl;
					cin>>fx0;
					fx0=fx0*ax0;
				break; 
			}	
		}
		cout<<"Por favor introduzca si la condiciones del contorno derecho para la dimension x seran del 1er, 2do o 3er tipo"<<endl;
		cout<<"1___________1er tipo = temperatura definida como funcion del tiempo en el limite derecho."<<endl;
		cout<<"2___________2do tipo = (-k)d(T)/dx = Q0(convencion de signos: + flujo entrante ; - flujo saliente)"<<endl;
		cout<<"3___________3er tipo = (k)d(T)/dx = h(Tambiente - T)"<<endl;
		cout<<"0____________SALIR"<<endl;	
		cin>>eleccionxd;
		if(eleccionxd==2||eleccionxd==3||eleccionxd==1){
		
			switch (eleccionxd){
					case 1:
						
					cout<<"Por favor introduzca si la temperatura será, constante o tendrá una funcion T(t): \n";
					cout<<"1________ T(t) = constante."<<endl;
					cout<<"2________ T(t) = A . (t^B) + C"<<endl;
					cout<<"3________ T(t) = A . (sen(t.B))^C + D"<<endl;
					cout<<"4________ T(t) = A . e^(t.B) + C"<<endl;
					cin>>eleccionTemp[1];
					switch(eleccionTemp[1]){
						case 1:	
							cout<<"Por favor introduzca el valor de la temperatura en el limite izquierdo"<<endl;
							cin>>axl;
						break;
						
						case 2:
							cout<<"\nA = ";
							cin>>temp1[1];
							cout<<"\nB = ";
							cin>>temp2[1];
							cout<<"\nC = ";
							cin>>temp4[1];
						break;
						
						case 3:
							cout<<"\nA = ";
							cin>>temp1[1];
							cout<<"\nB = ";
							cin>>temp2[1];
							cout<<"\nC = ";
							cin>>temp3[1];
							cout<<"\nD = ";
							cin>>temp4[1];
							break;
							
						case 4:
							cout<<"\nA = ";
							cin>>temp1[1];
							cout<<"\nB = ";
							cin>>temp2[1];
							cout<<"\nC = ";
							cin>>temp4[1];
							break;
					}
					break;
					case 2:
						axl=0;
						cout<<"por favor introduzca el valor del flujo de calor en el limite 'derecho'"<<endl;
						cin>>fxl;
					break;
			
					case 3:
						cout<<"por favor introduzca el valor de la constante h de conveccion en el limite 'derecho'"<<endl;
						cin>>axl;
						cout<<"por favor introduzca el valor de la temperatura del fluido en el limite 'derecho'"<<endl;
						cin>>fxl;
						fxl=fxl*axl;
					break; 
			}
		}
		
		cout<<"Por favor introduzca si la condiciones del contorno 'izquierdo' para la dimension y seran del 1er, 2do o 3er tipo"<<endl;
		cout<<"1___________1er tipo = temperatura definida como funcion del tiempo en el limite izquierdo."<<endl;
		cout<<"2___________2do tipo = (-k)d(T)/dy = Q0 (convencion de signos: + flujo entrante ; - flujo saliente)"<<endl;
		cout<<"3___________3er tipo = (k)d(T)/dy = h(Tambiente - T)"<<endl;
		cout<<"0____________SALIR"<<endl;
		
		cin>>eleccionyi;
		if(eleccionyi==2||eleccionyi==3||eleccionyi==1){
			
			switch (eleccionyi){
				case 1:
					
					cout<<"Por favor introduzca si la temperatura será, constante o tendrá una funcion T(t): \n";
					cout<<"1________ T(t) = constante."<<endl;
					cout<<"2________ T(t) = A . (t^B) + C"<<endl;
					cout<<"3________ T(t) = A . (sen(t.B))^C + D"<<endl;
					cout<<"4________ T(t) = A . e^(t.B) + C"<<endl;
					cin>>eleccionTemp[2];
					switch(eleccionTemp[2]){
						case 1:	
							cout<<"Por favor introduzca el valor de la temperatura en el limite izquierdo"<<endl;
							cin>>ay0;
						break;
						
						case 2:
							cout<<"\nA = ";
							cin>>temp1[2];
							cout<<"\nB = ";
							cin>>temp2[2];
							cout<<"\nC = ";
							cin>>temp4[2];
						break;
						
						case 3:
							cout<<"\nA = ";
							cin>>temp1[2];
							cout<<"\nB = ";
							cin>>temp2[2];
							cout<<"\nC = ";
							cin>>temp3[2];
							cout<<"\nD = ";
							cin>>temp4[2];
							break;
							
						case 4:
							cout<<"\nA = ";
							cin>>temp1[2];
							cout<<"\nB = ";
							cin>>temp2[2];
							cout<<"\nC = ";
							cin>>temp4[2];
							break;
					}
					break;
					
				case 2:
					ay0=0;
					cout<<"por favor introduzca el valor del flujo de calor en el limite 'izquierdo'"<<endl;
					cin>>fy0;
				break;
		
				case 3:
					cout<<"por favor introduzca el valor de la constante h de conveccion en el limite 'izquierdo'"<<endl;
					cin>>ay0;
					cout<<"por favor introduzca el valor de la temperatura del fluido en el limite 'izquierdo'"<<endl;
					cin>>fy0;
					fy0=fy0*ay0;
				break; 
			}	
		}
		cout<<"Por favor introduzca si la condiciones del contorno 'derecho' para la dimension y seran del 1er, 2do o 3er tipo"<<endl;
		cout<<"1___________1er tipo = temperatura definida como funcion del tiempo en el limite derecho."<<endl;
		cout<<"2___________2do tipo = (-k)d(T)/dy = Q0(convencion de signos: + flujo entrante ; - flujo saliente)"<<endl;
		cout<<"3___________3er tipo = (k)d(T)/dy = h(Tambiente - T)"<<endl;
		cout<<"0____________SALIR"<<endl;	
		cin>>eleccionyd;
		if(eleccionyd==2||eleccionyd==3||eleccionyd==1){
		
			switch (eleccionyd){
					case 1:
						
					cout<<"Por favor introduzca si la temperatura será, constante o tendrá una funcion T(t): \n";
					cout<<"1________ T(t) = constante."<<endl;
					cout<<"2________ T(t) = A . (t^B) + C"<<endl;
					cout<<"3________ T(t) = A . (sen(t.B))^C + D"<<endl;
					cout<<"4________ T(t) = A . e^(t.B) + C"<<endl;
					cin>>eleccionTemp[3];
					switch(eleccionTemp[3]){
						case 1:	
							cout<<"Por favor introduzca el valor de la temperatura en el limite izquierdo"<<endl;
							cin>>ayl;
						break;
						
						case 2:
							cout<<"\nA = ";
							cin>>temp1[3];
							cout<<"\nB = ";
							cin>>temp2[3];
							cout<<"\nC = ";
							cin>>temp4[3];
						break;
						
						case 3:
							cout<<"\nA = ";
							cin>>temp1[3];
							cout<<"\nB = ";
							cin>>temp2[3];
							cout<<"\nC = ";
							cin>>temp3[3];
							cout<<"\nD = ";
							cin>>temp4[3];
							break;
							
						case 4:
							cout<<"\nA = ";
							cin>>temp1[3];
							cout<<"\nB = ";
							cin>>temp2[3];
							cout<<"\nC = ";
							cin>>temp4[3];
							break;
					}
					break;
					case 2:
						ayl=0;
						cout<<"por favor introduzca el valor del flujo de calor en el limite 'derecho'"<<endl;
						cin>>fyl;
					break;
			
					case 3:
						cout<<"por favor introduzca el valor de la constante h de conveccion en el limite 'derecho'"<<endl;
						cin>>ayl;
						cout<<"por favor introduzca el valor de la temperatura del fluido en el limite 'derecho'"<<endl;
						cin>>fyl;
						fyl=fyl*ayl;
					break; 
			}
		}
	if((eleccionxi<=3||eleccionxi>=1)&&(eleccionxd<=3||eleccionxd>=1)&&(eleccionyi<=3||eleccionyi>=1)&&(eleccionyd<=3||eleccionyd>=1)){
		do{
			cout<<"\nPor favor introducir el largo del dominio en x"<<endl;
			cin>>longitudx;
			cout<<"\nPor favor introducir el largo del dominio en y"<<endl;
			cin>>longitudy;
			cout<<"\nPor favor introducir el largo del dominio temporal (hasta que tiempo desde cero)"<<endl;
			cin>>tiempo;
			cout<<"\nPor favor introducir la cantidad de nodos del dominio en la dimension espacial y"<<endl;
			cin>>pasosy;
			cout<<"\nPor favor introducir la cantidad de nodos del dominio en la dimension espacial x"<<endl;
			cin>>pasosx;
			cout<<"\nPor favor introducir la cantidad de nodos del dominio en la dimension temporal t"<<endl;
			cin>>pasost;
			//cout<<"\nPor favor introducir el valor de la constante k"<<endl;
			//cin>>k;
			k=1;
			//cout<<"\nPor favor introducir el valor de la densidad del material"<<endl;
			//cin>>densidad;
			densidad=1;
			//cout<<"\nPor favor introducir el valor Cp del material"<<endl;
			//cin>>cp;
			cp=1;
			alfa=k/(cp*densidad);
			
			hx=longitudx/double (pasosx);
			hy=longitudy/double (pasosy);
			ht=tiempo/double(pasost);
			estabilidad= ((2*alfa*ht)/(hx*hx))+((2*alfa*ht)/(hy*hy));
			if(estabilidad>1){
				cout<<"\nPor favor revise las pasos de mallado entre el tiempo y la variable espacial debido a que la aproximacion fallara."<<endl;
			}
			
		}while(estabilidad>1);
	}
}

void condicionesTiempoCero(){
	
	
		if((eleccionxi<=3||eleccionxi>=1)&&(eleccionxd<=3||eleccionxd>=1)&&(eleccionyi<=3||eleccionyi>=1)&&(eleccionyd<=3||eleccionyd>=1)){
			
			
				cout<<"\nPor favor elegir los valores de temperatura iniciales (en t=0) de el dominio"<<endl;
				cout<<"\n\t 2______________valor igual a una f(x,y) en el dominio";
				cout<<"\n\t 3______________elegir el valor uno por uno de cada nodo en t=0 del borde";
				cin>>eleccion;
			
				
				switch(eleccion){ //INTRODUCIENDO LOS DATOS DE LAS CONDICIONES INICIALES DE TEMPERATURA
					
					case 2:
						cout<<"Por favor elegir alguna de las siguientes funciones con las cuales se regirá la distribucion de temperatura"<<endl;
						cout<<"\n\t 1__________________ f(x) = a.(x+y)^b+c"<<endl;
						cout<<"\n\t 2__________________ f(x) = a.sen(x+y)^b+c"<<endl;
						cout<<"\n\t 3__________________ f(x) = a.e^(x+y)b+c"<<endl;
						cin>>eleccionFuncion;
						switch(eleccionFuncion){
							case 1:
							cout<<"\n\tPor favor digite los coeficientes, siendo primero a ,luego b y por ultimo c"<<endl;
							cin>>coefa;
							cin>>coefb;
							cin>>coefc;
							for(int y=0;y<pasosy;y++){
								for(int x=0;x<pasosx;x++){
									calor_x_t[x][y][0]=coefa*(pow(double((x*hx)+(y*hy)),coefb))+coefc;
								}
							}
							
							break;
							
							case 2:
							cout<<"\n\tPor favor digite los coeficientes, siendo primero a, luego b y por ultimo c"<<endl;
							cin>>coefa;
							cin>>coefb;
							cin>>coefc;
							for(int y=0;y<pasosy;y++){
								for(int x=0;x<pasosx;x++){
								
									calor_x_t[x][y][0]=coefa*(pow(sin(double((x*hx)+(y*hy))),coefb))+coefc;
								}
							}
								
							break;
							
							case 3:
							cout<<"\n\tPor favor digite los coeficientes, siendo primero a, luego b y por ultimo c"<<endl;
							cin>>coefa;
							cin>>coefb;
							cin>>coefc;
							for(int y=0;y<pasosy;y++){
								for(int x=0;x<pasosx;x++){
								
									calor_x_t[x][y][0]=coefa*(pow(e,(double((x*hx)+(y*hy)))*coefb))+coefc;
								}
							}
							
							break;
						}
					break;
					
					case 3:
						for(int y=0;y<pasosy;y++){
							for(int x=0;x<pasosx;x++){
							
							cout<<"\n\tPor favor introducir el valor de la temperatura en la posicion: "<<double(x)*hx<<" "<<double(y)*hy<<" "<<endl;
							cin>>calor_x_t[x][y][0];
							}
						}
						
					break;	
				} 
		}
		if(eleccionyd==1&&eleccionTemp[3]==1){		// condiciones para el borde en y "derecho"
			for(int x=0;x<pasosx;x++){
				
				calor_x_t[x][pasosy-1][0]=ayl;
			}
		}
		if(eleccionyd==1&&eleccionTemp[3]>1){
			for(int x=0;x<pasosx;x++){
				calor_x_t[x][pasosy-1][0]=temp4[3];
			}
		}
		if(eleccionyi==1&&eleccionTemp[2]==1){
			for(int x=0;x<pasosx;x++){ //condiciones para el borde en y izquierdo
				
				calor_x_t[x][0][0]=ay0;
			}
		}
		if(eleccionyi==1&&eleccionTemp[2]>1){
			for(int x=0;x<pasosx;x++){
				calor_x_t[x][0][0]=temp4[2];
			}
		}
		if(eleccionxi==1&&eleccionTemp[0]==1){ //condiciones para el borde x izquierdo
			for(int y=0;y<pasosy;y++){
				
				calor_x_t[0][y][0]=ax0;
			}
		}
		if(eleccionxi==1&&eleccionTemp[0]>1){
			for(int y=0;y<pasosy;y++){
				calor_x_t[0][y][0]=temp4[0];
			}
		}
		if(eleccionxd==1&&eleccionTemp[1]==1){
			for(int y=0;y<pasosy;y++){ //condiciones para el borde x derecho
				
				calor_x_t[pasosx-1][y][0]=axl;
			}
		}
		if(eleccionxd==1&&eleccionTemp[1]>1){
			for(int y=0;y<pasosy;y++){
				calor_x_t[pasosx-1][y][0]=temp4[1];
			}
		}
		
}

void vaciarMatriz(){
	for(int x=0;x<300;x++){
		for(int y=0;y<300;y++){
			for(int t=0;t<2;t++){
				calor_x_t[x][y][t]=0;
				flujo_x_y[x][y]=0;
			}
		}
	}
}

void iteradorYarchivador(){
	
	ofstream archivo;                         
	
	archivo.open("DominioPlano.txt",ios::out);//abre un archivo con ese nombre
	
	for(int y=0;y<pasosy;y++){
		for(int x=0;x<pasosx;x++){
			cout<<" "<<calor_x_t[x][y][0];                                                         
		}
		cout<<endl;
	}
	cout<<"\n\n";
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";                                                           
		exit(1);
	}
	else{
		for(int t=0;t<=pasost;t++){//calculo el siguiente paso temporal
			for(int y=0;y<pasosy;y++){
				for(int x=0;x<pasosx;x++){
					calculoDeTemperaturas(x,y,t);
					archivo<<" "<<calor_x_t[x][y][0];
				}
				cout<<endl;
				archivo<<endl;
			}
			
			cout<<"\n\n";
			
			
			for(int y=0;y<pasosy;y++){  //igualo el nuevo tiempo conseguido al anterior para seguir al siguiente
				for(int x=0;x<pasosx;x++){
					calor_x_t[x][y][0]=calor_x_t[x][y][1];
				}
			}
		}
		cout<<"\n\n";
	}
	archivo.close();
	cout<<"\nEl archivo se ha guardado exitosamente"<<endl ;
}

void malladoMatlab(){
	ofstream archivo2;
	
	archivo2.open("malladoMatlab.txt",ios::out);
	if(archivo2.fail()){
		cout<<"El archivo 'malladoMatlab.txt' no ha podido guardarse";
		exit(1);
	}
	else{
		archivo2<<pasosx<<" "<<pasosy<<" "<<pasost;
	}
	archivo2.close();
	cout<<"El archivo del mallado ha podido guardarse exitosamente";
	
	
}

void calculoDeTemperaturas(int x,int y,int t){

			
			if(x>0&&x<pasosx-1&&y>0&&y<pasosy-1){ //Formula para el centro del dominio
				calor_x_t[x][y][1]=ht*((((alfa/(hx*hx))*(calor_x_t[x+1][y][0]+calor_x_t[x-1][y][0]))+((alfa/(hy*hy))*((calor_x_t[x][y+1][0]+calor_x_t[x][y-1][0]))))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))-(1/ht))*calor_x_t[x][y][0]));
				cout<<" "<<calor_x_t[x][y][1];
			}
			//.......................................................................................................
			
			if(x==0&&eleccionxi==1&&eleccionTemp[0]==1){ // Formula para el borde en x a la izquierda para una temperatura constante
				calor_x_t[x][y][1]=calor_x_t[x][y][0];
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(x==pasosx-1&&eleccionxd==1&&eleccionTemp[1]==1){  // Formula para el borde en x a la derecha para una temperatura constante
				calor_x_t[x][y][1]=calor_x_t[x][y][0];
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(y==0&&eleccionyi==1&&eleccionTemp[2]==1){  // Formula para el borde izquierdo en y para una temperatura constante
				calor_x_t[x][y][1]=calor_x_t[x][y][0];
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(y==pasosy-1&&eleccionyd==1&&eleccionTemp[3]==1){  // Formula para el borde derecho en y para una temperatura constante
				calor_x_t[x][y][1]=calor_x_t[x][y][0];
				cout<<" "<<calor_x_t[x][y][0];
			}
			
			//.............................................................................................
			
			if(x==0&&eleccionxi==1&&eleccionTemp[0]>1){ // Formula para el borde en x a la izquierda para una temperatura en funcion del tiempo
				calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[0],0);
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(x==pasosx-1&&eleccionxd==1&&eleccionTemp[1]>1){ // Formula para el borde en x a la derecha para una temperatura en funcion del tiempo
				calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[1],1);
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(y==0&&eleccionyi==1&&eleccionTemp[2]>1){  // Formula para el borde izquierdo en y para una temperatura en funcion del tiempo
				calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[2],2);
				cout<<" "<<calor_x_t[x][y][0];
			}
			if(y==pasosy-1&&eleccionyd==1&&eleccionTemp[3]>1){  // Formula para el borde derecho en y para una temperatura en funcion del tiempo
				calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[3],3);
				cout<<" "<<calor_x_t[x][y][0];
			}
			
			//............................................................................................. Para condiciones 2 o 3
			
			if(x==0&&y<pasosy-1&&y>0&&eleccionxi!=1){ //borde en x a la izquierda para condiciones del tipo 2 o 3 sin la punta
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x+1][y][0]))+((alfa/(hy*hy))*((calor_x_t[x][y+1][0]+calor_x_t[x][y-1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*ax0)/(k*hx))-(1/ht))*calor_x_t[x][y][0])+
				((2*alfa*fx0)/(k*hx)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(x==pasosx-1&&y<pasosy-1&&y>0&&eleccionxd!=1){ //borde en x a la derecha para condiciones del tipo 2 o 3 sin la punta
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x-1][y][0]))+((alfa/(hy*hy))*((calor_x_t[x][y+1][0]+calor_x_t[x][y-1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*axl)/(k*hx))-(1/ht))*calor_x_t[x][y][0])  +
				((2*alfa*fxl)/(k*hx)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(y==0&&x<pasosx-1&&x>0&&eleccionyi!=1){ //Borde en y a la izquierda para condiciones del tipo 2 o 3 sin la punta
				calor_x_t[x][y][1]=ht*((((alfa/(hx*hx))*(calor_x_t[x+1][y][0]+calor_x_t[x-1][y][0]))+(((2*alfa)/(hy*hy))*((calor_x_t[x][y+1][0]))))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*ay0)/(k*hy))-(1/ht))*calor_x_t[x][y][0]) + 
				((2*alfa*fy0)/(k*hy)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(y==pasosy-1&&x<pasosx-1&&x>0&&eleccionyd!=1){  // Borde en y a la derecha para condiciones del tipo 2 o 3 sin la punta
				calor_x_t[x][y][1]=ht*((((alfa/(hx*hx))*(calor_x_t[x+1][y][0]+calor_x_t[x-1][y][0]))+(((2*alfa)/(hy*hy))*((calor_x_t[x][y-1][0]))))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*ayl)/(k*hy))-(1/ht))*calor_x_t[x][y][0]) + 
				((2*alfa*fyl)/(k*hy)));
			}
			//.......................................................................................................... Esquinas.
			
			
			if(x==0&&y==0&&eleccionxi!=1&&eleccionyi!=1){ // condicion para la esquina x=0 y=0 y condicion de contorno para x e y de tipo 2 o 3.
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x+1][y][0]))+((2*alfa/(hy*hy))*((calor_x_t[x][y+1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*ax0)/(k*hx))+((2*alfa*ay0)/(k*hy))-(1/ht))*calor_x_t[x][y][0])+
				((2*alfa*fx0)/(k*hx))+((2*alfa*fy0)/(k*hy)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(x==0&&y==pasosy-1&&eleccionxi!=1&&eleccionyd!=1){ // Condicion para la esquina x=0 y=longitudy y condicion de contorno para x e y de tipo 2 o 3.
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x+1][y][0]))+((2*alfa/(hy*hy))*((calor_x_t[x][y-1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*ax0)/(k*hx))+((2*alfa*ayl)/(k*hy))-(1/ht))*calor_x_t[x][y][0])+
				((2*alfa*fx0)/(k*hx))+((2*alfa*fyl)/(k*hy)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(x==pasosx-1&&y==0&&eleccionxd!=1&&eleccionyi!=1){ // Condicion para la esquina x=longitudx y=0 y condicion de contorno para x e y de tipo 2 o 3. 
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x-1][y][0]))+((2*alfa/(hy*hy))*((calor_x_t[x][y+1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*axl)/(k*hx))+((2*alfa*ay0)/(k*hy))-(1/ht))*calor_x_t[x][y][0])+
				((2*alfa*fxl)/(k*hx))+((2*alfa*fy0)/(k*hy)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			if(x==pasosx-1&&y==pasosy-1&&eleccionxd!=1&&eleccionyd!=1){ // Condicion para la esquina x= longitudx y=longitudy y condicion de contorno para x e y de tipo 2 o 3.
				calor_x_t[x][y][1]=ht*(((2*alfa/(hx*hx))*(calor_x_t[x-1][y][0]))+((2*alfa/(hy*hy))*((calor_x_t[x][y-1][0])))  -
				((((2*alfa)/(hx*hx))+((2*alfa)/(hy*hy))+((2*alfa*axl)/(k*hx))+((2*alfa*ayl)/(k*hy))-(1/ht))*calor_x_t[x][y][0])+
				((2*alfa*fxl)/(k*hx))+((2*alfa*fyl)/(k*hy)));
				cout<<" "<<calor_x_t[x][y][1];
			}
			
			
}

double funcionTemporal(int t,int eleccionTemp,int i){
	double resultado=0,td;
	td=double(t)*ht;
	switch(eleccionTemp){
		case 2:
			resultado = temp1[i]*(pow(td,temp2[i]))+temp4[i];
		break;
		case 3:
			resultado = temp1[i]*(pow(cos(temp2[i]*td),temp3[i]))+temp4[i];
			break;
		case 4:
			resultado = temp1[i]*pow(e,temp2[i]*td)+temp4[i];
			break;
	}
	return resultado;
}

void DominioCircular(){
	double circuloInterior=0,circuloExterior;
	ofstream archivo;
	                         
	
	archivo.open("DominioCircular.txt",ios::out);//abre un archivo con ese nombre
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";                                                           
		exit(1);
	}
	else{
		for(int t=0;t<=pasost;t++){//calculo el siguiente paso temporal
			for(int y=0;y<51;y++){
				for(int x=0;x<51;x++){
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)>24){
						calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[0],0);
					}
					
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)<=24){
						
						calculoDeTemperaturas(x,y,t);
						
					}
					archivo<<calor_x_t[x][y][1]<<" ";
				}
				cout<<endl;
				archivo<<endl;
			}
			
			cout<<"\n\n";
			
			
			for(int y=0;y<pasosy;y++){  //igualo el nuevo tiempo conseguido al anterior para seguir al siguiente
				for(int x=0;x<pasosx;x++){
					calor_x_t[x][y][0]=calor_x_t[x][y][1];
				}
			}
		}
		cout<<"\n\n";
	}
	archivo.close();
	cout<<"\nEl archivo se ha guardado exitosamente"<<endl ;
}

void flujoDeCalor(){
		double circuloInterior=0,circuloExterior;
		int iterador=0;
	ofstream archivo;
	                         
	
	archivo.open("TemperaturasyFlujos.txt",ios::out);//abre un archivo con ese nombre
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";                                                           
		exit(1);
	}
	else{
		for(int t=0;t<=pasost;t++){//calculo el siguiente paso temporal
			for(int y=0;y<51;y++){
				for(int x=0;x<51;x++){
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)>24){
						calor_x_t[x][y][1]=funcionTemporal(t,eleccionTemp[0],0);
					}
					
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)<=24){
						calculoDeTemperaturas(x,y,t);
					}
					archivo<<calor_x_t[x][y][0]<<" ";
				}
				archivo<<endl;
			}
			
			for(int y=0;y<51;y++){                              //Escribe la matriz del flujo en x.
				for(int x=0;x<51;x++){
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)<=24){
						flujo_x_y[x][y]=(k)*((calor_x_t[x-1][y][0]-calor_x_t[x+1][y][0])/(2*hx));
						
					}
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)>24){
						flujo_x_y[x][y]=0;
					}
					archivo<<flujo_x_y[x][y]<<" ";
				}
				archivo<<endl;
			}
			
			for(int y=0;y<51;y++){                          //Escribe la matriz del flujo en y.
				for(int x=0;x<51;x++){
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)<=24){
						flujo_x_y[x][y]=(k)*((calor_x_t[x][y-1][0]-calor_x_t[x][y+1][0])/(2*hx));
						
					}
					if(pow((x-25)*(x-25)+(y-25)*(y-25),0.5)>24){
						flujo_x_y[x][y]=0;
					}
					archivo<<flujo_x_y[x][y]<<" ";
				}
				archivo<<endl;
			}

			
			for(int y=0;y<pasosy;y++){  //igualo el nuevo tiempo conseguido al anterior para seguir al siguiente
				for(int x=0;x<pasosx;x++){
					calor_x_t[x][y][0]=calor_x_t[x][y][1];
				}
			}
			iterador=iterador+1;
			cout<<iterador<<"\n";
		}
		cout<<"\n\n"<<iterador;
	}
	archivo.close();
	cout<<"\nEl archivo se ha guardado exitosamente"<<endl ;
}


