
#include "Personaje.h"

Personaje::Personaje(const std::string& textureFile, int pX, int pY, std::string p_name, int p_atk, int p_hp,int p_magia, bool p_visible) {
    if (!texture.loadFromFile(textureFile)) {
       
    }
    sprite.setSize(sf::Vector2f(52.5, 52.5));
    sprite.setTexture(&texture);
    x = POSICIONES[pY][pX][0] - 23.25;
    y = POSICIONES[pY][pX][1] - 23.25;
    virtualX = pX;
    virtualY = pY;


    sprite.setPosition(x, y);
    visible = p_visible;
    name = p_name;
    attack = p_atk;
    attackMagia = p_magia;
    hp = p_hp;
}


void Personaje::draw(sf::RenderWindow& window) {
    if (visible)
    {
        window.draw(sprite);
    }
}

void Personaje::setPosition(int newX, int newY) {
    x = POSICIONES[newY][newX][0] - 23.25;
    y = POSICIONES[newY][newX][1] - 23.25;
    virtualX = newX;
    virtualY = newY;

    sprite.setPosition(x, y);
}

void Personaje::setX(int pX) {
    x = pX;
}
void Personaje::setY(int pY) {
    y = pY;
}
void Personaje::setHp(int php) {
    hp = php;
}
void Personaje::setVisble(bool p_visble) {
    visible = p_visble;
}

int Personaje::getX() {
    return x;
}
int Personaje::getY() {
    return y;
}
int Personaje::getHp() {
    return hp;
}
int Personaje::getAttack() {
    return attack;
}
int Personaje::getAttackMagia() {
    return attackMagia;
}
std::string Personaje::getName() {
    return name;
}
int Personaje::getVirtualX() {
    return virtualX;
}
int Personaje::getVirtualY() {
    return virtualY;
}
bool Personaje::getVisible() {
    return visible;
}


void Personaje::setName(std::string pname) {
    name = pname;
}
void Personaje::setAttack(int pattack) {
    attack = pattack;
}
void Personaje::setAttackMagia(int pattack) {
    attackMagia = pattack;
}