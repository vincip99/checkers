#include <iostream>
#include<string>
#include "game.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	game gg;
	string b;
	
	do{
		
		system("color 3");
	
	cout<<"checkers game"<<endl;
	cout<<"white start"<<endl;
	
	
	cout<<"FIELD: "<<endl;
	gg.draw();
	cout<<"WHITE on the BOTTOM and BLACK on the TOP "<<endl;
	cout<<"TO MOVE A PIECE SELECT: Y for ROW and X for COLON)"<<endl;
	cout<<"to MOVE RIGHT use D, to MOVE LEFT use A (right and left of the screen) "<<endl;
	cout<<"to EAT a piece on the RIGHT use M and then D, to EAT on the LEFT use M than A on the RIGHT(right and left of the screen)"<<endl;
	cout<<"upgrade pieces can move in every direction, D or MD e A or MA , W to move to top, S to the bottom"<<endl;
	
	cout<<"CONTINUE? ok / no"<<endl;
	cin>>b;
	
	system("cls");
		
	}while(b=="no");
	
	int x,y;
	const char *m;
	
	do{

		gg.draw();
		
		gg.setTurn(true);
		
		l1:
		
		cout<<"white: "<<endl;
		cout<<"x: ";
		cin>>x;
		cout<<"y: ";
		cin>>y;
		cout<<endl;
		
		string buff;
		
		cout<<"press D to move to the right or A to move left,"<<endl;
		cout<<"MD or MA to eat(if possibile),W or S only if upgrade piece"<<endl;
		cin>>buff;
		
		try{
			if(buff=="a"){
				gg.moveLeft(true,x,y,true);
			}if(buff=="d"){
				gg.moveRight(true,x,y,true);
			}if(buff=="ma"){
				gg.eatLeft(true,x,y,true);
			}if(buff=="md"){
				gg.eatRight(true,x,y,true);
		    }if(buff=="aw"){
		    	gg.moveLeft(true,x,y,true);
			}if(buff=="dw"){
				gg.moveRight(true,x,y,true);
			}if(buff=="as"){
				gg.moveLeft(true,x,y,false);
			}if(buff=="ds"){
				gg.moveRight(true,x,y,false);
			}if(buff=="maw"){
				gg.eatLeft(true,x,y,true);
			}if(buff=="mas"){
				gg.eatLeft(true,x,y,false);
			}
		}catch(const char* m){
			goto l1;
		}
		
		system("cls");
		gg.draw();
		
		gg.getUpgrade();
		gg.checkWin();
		
		gg.setTurn(false);
		
		l2:
		
		cout<<"black: "<<endl;
		cout<<"x: ";
		cin>>x;
		cout<<"y: ";
		cin>>y;
		cout<<endl;
		
		cout<<"press D to move to the right or A to move left,"<<endl;
		cout<<"MD or MA to eat(if possibile),W or S only if upgrade piece"<<endl;
		cin>>buff;	
			
		
		try{
			if(buff=="a"){
				gg.moveLeft(false,x,y,true);
			}if(buff=="d"){
				gg.moveRight(false,x,y,true);
			}if(buff=="ma"){
				gg.eatLeft(false,x,y,true);
			}if(buff=="md"){
				gg.eatRight(false,x,y,true);
		    }if(buff=="aw"){
		    	gg.moveLeft(false,x,y,true);
			}if(buff=="dw"){
				gg.moveRight(false,x,y,true);
			}if(buff=="as"){
				gg.moveLeft(false,x,y,false);
			}if(buff=="ds"){
				gg.moveRight(false,x,y,false);
			}if(buff=="maw"){
				gg.eatLeft(false,x,y,true);
			}if(buff=="mas"){
				gg.eatLeft(false,x,y,false);
			}
		}catch(const char* m ){
			goto l2;
		}
		
		system("cls");
		gg.draw();
		
		gg.getUpgrade();
		gg.checkWin();
		system("cls");
		
		
	}while(true);
	
	return 0;
}