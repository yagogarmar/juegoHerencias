#pragma once
#include "Personaje.h"
#include <SFML/Graphics.hpp>

class Enemigo : public Personaje {



public:
	Enemigo(const std::string& textureFile, std::string p_name, int p_atk, int p_hp, bool p_visible);
	bool checkCol(int pX, int pY);


};