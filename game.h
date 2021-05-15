#ifndef GAME_H
#define GAME_H

class game{
	private:
		char field[8][8];   //game field
		bool turn;
		bool upgrade;   //if upgrade a piece
		bool status;   //win or lose status
	public:
		game();
		
		void setTurn(const bool);
		void setUpgrade();
		void setStatus(const bool);
		
		bool getTurn() const{return turn;}
		bool getUpgrade() const{return upgrade;}
		bool getStatus() const{return status;}
		
		void moveRight(const bool,int ,int ,bool);
		void moveLeft(const bool,int ,int ,bool);
		void eatRight(const bool,int ,int ,bool);
		void eatLeft(const bool,int ,int ,bool);
	
		void checkWin();
		
		void draw();	
		
};

#endif