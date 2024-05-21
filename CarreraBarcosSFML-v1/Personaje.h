#pragma once
#include <SFML/Graphics.hpp>

class Personaje {


protected:
	int POSICIONES[6][7][2] = { {{42,42},{126,42},{210,42},{294,42},{378,42},{462,42},{546,42}},
						  {{42,126},{126,126},{210,126},{294,126},{378,126},{462,126},{546,126}},
						  {{42,210},{126,210},{210,210},{294,210},{378,210},{462,210},{546,210}},
						  {{42,294},{126,294},{210,294},{294,294},{378,294},{462,294},{546,294}},
						  {{42,378},{126,378},{210,378},{294,378},{378,378},{462,378},{546,378}},
						  {{42,462},{126,462},{210,462},{294,462},{378,462},{462,462},{546,462}} };
private:
	int hp;
	std::string name;
	int attack;
	int attackMagia;
	int x;
	int y;
	int virtualX;
	int virtualY;
	bool visible;
	sf::RectangleShape sprite;
	sf::Texture texture;


public:
	//Constructor
	Personaje(const std::string& textureFile, int pX, int pY, std::string p_name, int p_atk, int p_hp,int p_magia,bool  p_visible);


	// Getters
	int getHp();
	std::string getName();
	int getAttack();
	int getAttackMagia();
	int getX();
	int getY();	
	int getVirtualX();
	int getVirtualY();
	bool getVisible();
	// Setters
	void setHp(int php);
	void setName(std::string pname);
	void setAttack(int pattack);
	void setAttackMagia(int pattack);
	void setX(int pX);
	void setY(int pY);
	void setVisble(bool p_visible);

	// metodos propios
	virtual void draw(sf::RenderWindow& window);
	void setPosition(int newX, int newY);
};