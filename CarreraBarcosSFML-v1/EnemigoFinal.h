#include "Personaje.h"
#include <SFML/Graphics.hpp>



class EnemigoFinal : public Personaje {

private:
	int attackFinal;
	int attackUltimate;

public:
	EnemigoFinal(const std::string& textureFile, int pX, int pY, std::string p_name, int p_atk, int p_hp, bool p_visible, int p_attackFinal, int p_attackUltimate);
	

	void setAttackFinal(int p_attack);
	void setAttackUltimate(int p_attack);


	int getAttackFinal();
	int getAttackUltimate();

};