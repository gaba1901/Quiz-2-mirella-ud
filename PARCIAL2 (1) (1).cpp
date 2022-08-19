#include <iostream>
#include <string>
#include <stdlib.h>
#include <String>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <sstream>
using namespace std;
	//LE=level osea nivel
    int LE= 0;
    int LE2= 0;
    //LI=Lifes osea vidas
    int LI = 0;
    //TR=try osea intento
    int TR = 0;
    //RO=ROW osea fila
    int RO =0;
    //CO=Column osea Columna
    int CO =0;
    //Game over=juego terminado 
    bool Gameover= true;
    bool C1=false,C2=false;
    int aux;
int main() {
	setlocale(LC_ALL, "spanish");
	START:
    cout<<endl;
    cout<<"        Bienvenidos a PARCIAL"<<endl;
    cout<<endl;
    cout<<"   Descripción:"<<endl;
    cout<<"   Este juego consiste en seleccionar"<<endl;
    cout<<"   todos los bloques sin explotar las minas"<<endl;
     cout<<"  y debes de destruir los aviones enemigos"<<endl;
    cout<<endl;
    LEVEL:
    cout<<endl;
    cout<<"   Selecciona el nivel de juego"<<endl;
    cout<<endl;
    cout<<"   Nivel             Vidas           Escribe"<<endl;
    cout<<endl;
    cout<<"   Practica        10               1"<<endl;
    cout<<"   Facil            8               2"<<endl;
    cout<<"   Medio            5               3"<<endl;
    cout<<"   Dificil          3               4"<<endl;
    cout<<"   Muy Dificil      1               5"<<endl;
    cout<<endl;
    cout<<"   Ingresa el tu Nivel: ";scanf("%d",&LE2);cout<<endl;
	
	switch (LE2) {
        case 1:
            LE = 11;
            LI = 10;
            Gameover = false;
            TR=0;
            system("cls");
            break;
        case 2:
            LE = 11;
            LI = 8;
            Gameover = false;
            TR=0;
            system("cls");
            break;
        case 3:
            LE = 11;
            LI = 5;
            Gameover = false;
            TR=0;
            system("cls");
            break;
        case 4:
            LE = 11;
            LI = 3;
            Gameover = false;
            TR=0;
            system("cls");
            break;
        case 5:
            LE = 11;
            LI = 1;
            Gameover = false;
            TR=0;
            system("cls");
            break;
        default:
            system("cls");
            cout<<"   Escribe un numero valido entre 1 y 5"<<endl;
            goto START;
            break;
    }
    //Definimos la MATRIZ
    int m[LE][LE];
    int m2[LE][LE];
    int m4[LE][LE];
    int m5[LE][LE];
    int m3[LE][LE];
    string mT[LE][LE];
    srand(time(NULL));//usamos esta funcion para poder utilizar la funcion de rand
    //char qq="1";
    mT[0][0]=" ";
	//Generamos la matriz que controla la logica del juego 
 for (int i = 1;i<2;i++) {
    for (int j = 1;j<2; j++){
    	
	m2[i][j]=rand()% 10;
			aux=1+rand()%(11 - 1);
			m2[aux][j]='A';
            m2[aux][j++]='A';
            m2[aux][j++]='A';
		}
			
			}
			
 for (int i = 1;i<2;i++) {
    for (int j = 1;j<2; j++){
    	
	m2[i][j]=rand()% 10;
			aux=1+rand()%(11 - 1);
			m2[aux][j]='A';
            m2[aux][j++]='A';
            m2[aux][j++]='A';
		}
			}
    for (int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++){
            m[i][j]=rand()%(2)+(i * 100)+(j*10);
    }
}


    //Esta es la matriz que le vamos a mostar a el usuario
     for (int i = 0;i<LE;i++) {
     	mT[0][0]=" ";
    
        for (int j=0;j<LE;j++){
        	
            mT[i][j]="#";
            mT[0][j]=to_string(j);
        }
        mT[i][0]=to_string(i); 
    }
    
    mT[0][0]=" ";
    //Mostramos la matriz
    cout<<"               PARCIAL:" <<LE2<<endl;
    cout<<"     Intentos:"<<TR<<"      Vidas: "<<LI-1<<endl;
    for (int i = 0;i < LE; i++) {
        cout<<endl;
        for (int j =0; j < LE; j++){
            cout<<" | "<<mT[i][j]<<" | ";
        }
        cout<<endl;
    }
   cout<<endl;
   //Logica del juego
   while (Gameover == false) {
        FILA:
        cout<<"   Digite la fila entre 1 y "<<LE-1<<" ";cin>>RO;cout<<endl;
        if (((RO <= 0 || RO > LE-1)or RO==0)) {
            cout<<"   escribe un numero entre 1 y "<<LE-1<<" "<<endl;
            goto FILA;
        }
        COLU:
        cout<<"   Digite la columna entre 1 y "<<LE-1<<" ";cin>>CO;cout<<endl;
        if ((CO <= 0 || CO > LE-1)or CO==0){
            cout<<"   escribe un numero entre 1 y "<<LE-1<<" "<<endl;
            goto COLU;
        }
mT[RO][CO] = " ";
	if(m[RO][CO]%2==1){
		C1=true;
		 mT[RO][CO]="1";
            LI--;
            if (LI==0) {
                Gameover=true;
            }
	}
	if(m2[RO][CO]/2>0){
		mT[RO][CO]="A";	
		C2=true;
	}
			
	
    
	TR++;   
    
  


        system("cls");
        if (Gameover==false) {
            cout<<"                 PARCIAL:"<<LE2<<endl;
            cout<<"     Intentos:"<<TR<<"      Vidas: "<<LI-1<<endl;
            for (int i = 0;i < LE; i++) {
                cout<<endl;
                for (int j = 0; j < LE; j++){
                cout<<" | "<<mT[i][j]<<" | ";
                }
                
                cout<<endl;
            }
    if (C1==false and C2==true) {
    	cout<<endl;
            cout<<"LE DISTE A UN AVION, SIGUE ASI"<<endl;
            	}
    if (C1==true and C2==false) {
    	cout<<endl;
            cout<<"PERDISTE UNA VIDA"<<endl;
            }
    if(C1==false and C2==false)
    {
    	cout<<endl;
      cout<<"PERDISTE UNA BALA"<<endl;
	}


            cout<<endl;
        }
        if (Gameover == true) {
            cout<<"                 PARCIAL"<<LI<<endl;
            cout<<"     Intentos:"<<TR<<"      Vidas: "<<LI<<endl;
            cout<<endl;
            cout<<"                     GAME OVER"<<endl;
            cout<<"                     Has perdido"<<endl;
            cout<<endl;
            
            cout<<endl;
            
            cout<<endl;
         system("PAUSE");
        cout<<endl;
    
            Sleep(2000);
            system("cls");
            cout<<"Intentalo nuevamente"<<endl;
            Sleep(1000);
            system("cls");
            
            goto START;
        
        }
    }
        
        
    


  return 0;
}


