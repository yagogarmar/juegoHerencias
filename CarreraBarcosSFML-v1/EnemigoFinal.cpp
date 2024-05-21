
#include "EnemigoFinal.h"
#include <stdlib.h>


EnemigoFinal::EnemigoFinal(const std::string& textureFile, int pX, int pY, std::string p_name, int p_atk, int p_hp, bool p_visible, int p_attackFinal, int p_attackUltimate) : Personaje(textureFile, pX, pY, p_name, p_atk, p_hp,0, p_visible) {

	attackFinal = p_attackFinal;
	attackUltimate = p_attackUltimate;
}




void EnemigoFinal::setAttackFinal(int p_attack) {
	attackFinal = p_attack;
}
void EnemigoFinal::setAttackUltimate(int p_attack) {
	attackUltimate = p_attack;
}


int EnemigoFinal::getAttackFinal() {
	return attackFinal;
}
int EnemigoFinal::getAttackUltimate() {
	return attackUltimate;
}