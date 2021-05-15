#include "game.h"
#include<iostream>
#include<iomanip>

using namespace std;

game::game(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2==0){
				field[i][j]='e';  //empty space 
			}else{
				field[i][j]='u';  //effective squares for piece
			}
		}
	}
	turn=true;  //white start
	upgrade=false;  //no one piece is upgrade
	status=false;  //the game start
	
	//field
	for(int i=0;i<3;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2!=0){
				field[i][j]='b';  //black
			}
		}
	}
	for(int i=5;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2!=0){
				field[i][j]='w';  //white
			}
		}
	}
}

void game::setTurn(const bool t){
	turn=t;
}

void game::setUpgrade(){
	for(int j=0;j<8;j++){
		if(field[0][j]=='w'){  //top of screen
			upgrade=true;
			field[0][j]='W';  //upgrade if white piece is on the top
		}else{
			upgrade=false;
		}
	}
	for(int j=0;j<8;j++){
		if(field[7][j]=='b'){  //bottom
			upgrade=true;
			field[7][j]='B';  //upgrade
		}else{
			upgrade=false;
		}
	}
}

void game::setStatus(const bool s){
	status=s;
}

void game::moveRight(const bool t,int x,int y,bool dir){
	if(t==true){  //white turn   
		if(field[y][x]=='w' && (x!=7 || y!=0) && field[y-1][x+1]=='u'){   //set of the moving piece
			field[y][x]='u';
			field[y-1][x+1]='w';
		}
		else if(field[y][x]=='W' && field[y-1][x+1]=='u' && field[y+1][x+1]=='u'){   //if is upgrade
			field[y][x]='u';
			if(dir==true && x!=7 && y!=7)  //move to top
			field[y-1][x+1]='W';
			if(dir==false && x!=7 && y!=0)  //move to bottom
			field[y+1][x+1]='W';
		}else{
			throw "invalid position";
		}
	    
		
	}if(t==false){  //black turn
		if(field[y][x]=='b' && (x!=7 || y!=7) && field[y+1][x+1]=='u'){   //set of the moving piece
			field[y][x]='u';
			field[y+1][x+1]='b';
		}
		else if(field[y][x]=='B' && field[y+1][x+1]=='u' && field[y-1][x+1]=='u'){   //if is upgrade
			field[y][x]='u';
			if(dir==true && x!=7 && y!=0)  //move to top
			field[y+1][x+1]='B';
			if(dir==false && x!=7 && y!=7)  //move to bottom
			field[y-1][x+1]='B';
		}else{
			throw "invalid position";
	    }
    }
	    
    
}

void game::moveLeft(const bool t,int x,int y,bool dir){
	
	if(t==true){    
		if(field[y][x]=='w' && (x!=0 || y!=0) && field[y-1][x-1]=='u'){   
			field[y][x]='u';
			field[y-1][x-1]='w';
		}
		else if(field[y][x]=='W' && field[y-1][x-1]=='u' && field[y+1][x-1]=='u'){   
			field[y][x]='u';
			if(dir==true && x!=0 && y!=0)  
			field[y-1][x-1]='W';
			if(dir==false && x!=0 && y!=7)  
			field[y+1][x-1]='W';
		}else{
			throw "invalid position";
		}
	}
	
	if(t==false){  
		if(field[y][x]=='b' && (x!=0 || y!=7) && field[y+1][x-1]=='u'){   
			field[y][x]='u';
			field[y+1][x-1]='b';
		}
		else if(field[y][x]=='B' && field[y+1][x-1]=='u' && field[y-1][x-1]=='u'){   
			field[y][x]='u';
			if(dir==true && x!=0 && y!=7)  
			field[y+1][x-1]='B';
			if(dir==false && x!=0 && y!=0)  
			field[y-1][x-1]='B';
		}else{
			throw "invalid position";
    	}
    }
}

void game::eatRight(const bool t,int x,int y,bool dir){

	if(t==true){  //white turn
		if(field[y][x]=='w' && field[y-1][x+1]=='b' && field[y-2][x+2]=='u'){  //normal piece
			field[y][x]='u';
			field[y-1][x+1]='u';
			field[y-2][x+2]='w';
		}
		else if(dir==true && field[y][x]=='W'){ //upgrade piece
			if(field[y][x]=='W' && (field[y-1][x+1]=='b' || field[y-1][x+1]=='B') && field[y-2][x+2]=='u'){
				field[y][x]='u';
			    field[y-1][x+1]='u';
			    field[y-2][x+2]='W';
			}else{
			    throw "can t eat";
		    }
		}
		else if(dir==false && field[y][x]=='W'){  //upgrade piece
		    if(field[y][x]=='W' && (field[y+1][x+1]=='b' || field[y+1][x+1]=='B') && field[y+2][x+2]=='u'){
				field[y][x]='u';
			    field[y+1][x+1]='u';
			    field[y+2][x+2]='W';
			}else{
			    throw "can t eat";
	    	}
	    }else{
			    throw "can t eat";
			}
	}
	
	if(t==false){   //black turn
		if(field[y][x]=='b' && field[y+1][x+1]=='w' && field[y+2][x+2]=='u'){  //normal piece
			field[y][x]='u';
			field[y+1][x+1]='u';
			field[y+2][x+2]='b';
		}
		else if(dir==true && field[y][x]=='B'){ //upgrade piece
			if(field[y][x]=='B' && (field[y+1][x+1]=='w' || field[y+1][x+1]=='W') && field[y+2][x+2]=='u'){
				field[y][x]='u';
			    field[y-1][x+1]='u';
			    field[y-2][x+2]='B';
			}else{
			    throw "can t eat";
		    }
		}
		else if(dir==false && field[y][x]=='B'){  //upgrade piece
		    if(field[y][x]=='B' && (field[y-1][x+1]=='w' || field[y-1][x+1]=='W') && field[y-2][x+2]=='u'){
				field[y][x]='u';
			    field[y-1][x+1]='u';
			    field[y-2][x+2]='B';
			}else{
			    throw "can t eat";
	    	}
	    }else{
			throw "can t eat";
		}
	}
}

void game::eatLeft(const bool t,int x,int y,bool dir){
	
	if(t==true){  
		if(field[y][x]=='w' && field[y-1][x-1]=='b' && field[y-2][x-2]=='u'){  
			field[y][x]='u';
			field[y-1][x-1]='u';
			field[y-2][x-2]='w';
		}
		else if(dir==true){ 
			if(field[y][x]=='W' && (field[y-1][x-1]=='b' || field[y-1][x-1]=='B') && field[y-2][x-2]=='u'){
				field[y][x]='u';
			    field[y-1][x-1]='u';
			    field[y-2][x-2]='W';
			}else{
			    throw "can t eat";
		    }
		}
		else if(dir==false){  
		    if(field[y][x]=='W' && (field[y+1][x-1]=='b' || field[y+1][x-1]=='B') && field[y+2][x-2]=='u'){
				field[y][x]='u';
			    field[y+1][x-1]='u';
			    field[y+2][x-2]='W';
			}else{
			    throw "can t eat";
	    	}
	    }else{
			throw "can t eat";
		}
	}
	
	if(t==false){   
		if(field[y][x]=='b' && field[y+1][x-1]=='w' && field[y+2][x-2]=='u'){  
			field[y][x]='u';
			field[y+1][x-1]='u';
			field[y+2][x-2]='b';
		}
		else if(dir==true){ 
			if(field[y][x]=='B' && (field[y+1][x-1]=='w' || field[y+1][x-1]=='W') && field[y+2][x-2]=='u'){
				field[y][x]='u';
			    field[y-1][x-1]='u';
			    field[y-2][x-2]='B';
			}else{
			    throw "can t eat";
		    }
		}
		else if(dir==false){  
		    if(field[y][x]=='B' && (field[y-1][x-1]=='w' || field[y-1][x-1]=='W') && field[y-2][x-2]=='u'){
				field[y][x]='u';
			    field[y-1][x-1]='u';
			    field[y-2][x-2]='B';
			}else{
			    throw "can t eat";
	    	}
	    }else{
			throw "can t eat";
		}
	}
	
}

void game::checkWin(){
	int countb=0;
	int countn=0;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(field[i][j]=='w' || field[i][j]=='W')
			countb++;
			if(field[i][j]=='b' || field[i][j]=='B')
			countn++;
		}
	}
	if(countb==0){
		setStatus(true);
		throw "black win";
	}
	
	if(countn==0){
		setStatus(true);
		throw "white win";
	}
}

void game::draw(){
	cout<<endl;
	for(int i=0;i<8;i++){
		cout<<setw(6)<<i;
	}cout<<endl;
	
	for(int i=0;i<8;i++){
		cout<<setfill('_')<<endl;
		for(int j=0;j<8;j++){
			if((i+j)%2!=0){
				if(field[i][j]=='w'){
					cout<<"|"<<setw(3)<<"()"<<setw(3);
				}if(field[i][j]=='b'){
					cout<<"|"<<setw(3)<<"0"<<setw(3);
				}if(field[i][j]=='W'){
					cout<<"|"<<setw(3)<<"(D)"<<setw(3);
				}if(field[i][j]=='B'){
					cout<<"|"<<setw(3)<<"0D"<<setw(3);
				}if(field[i][j]=='u'){
					cout<<"|"<<setw(6);
				}
			}else{
				cout<<"|"<<setw(6);
			}
		}cout<<"|"<<"   "<<i<<endl;
	}cout<<endl;
}
