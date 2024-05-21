
#include "enemigo.h"
#include <stdlib.h>

Enemigo::Enemigo(const std::string& textureFile, std::string p_name, int p_atk, int p_hp,bool p_visible) : Personaje(textureFile,  0, 0, p_name,p_atk,p_hp,0,p_visible) {
	
	
	int x = rand() % 6;
	int y = rand() % 4 + 1;

	setPosition(x, y);

}
bool compareArrays(int arr1[], int arr2[]) {
	for (int i = 0; i < 2; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

bool Enemigo::checkCol(int pX, int pY) {
	
	
	int x = getVirtualX();
	int y = getVirtualY();

	int jugadorPos[2] = { pX, pY };
	int casillasAct[8][2] = {{x-1,y-1},{x,y-1},{x+1,y-1},
							 {x-1,y},      {x+1,y},
							 {x-1,y+1},{x,y+1},{x+1,y+1}};

	for (int i = 0; i < 8; i++){
		
		if (compareArrays(casillasAct[i], jugadorPos)){
			return true;
		}
	}

	return false;
}