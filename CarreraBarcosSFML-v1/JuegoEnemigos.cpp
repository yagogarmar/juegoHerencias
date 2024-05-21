
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Personaje.h"
#include "Enemigo.h"
#include "EnemigoFinal.h"

#include <chrono>
#include <thread>

using namespace std;
using namespace sf;
using namespace std::this_thread; 
using namespace std::chrono; 

int x = 3;
int y = 0;
int turno = 1;
int killCount = 0;
int ene = -1;
int fase = 1;
sf::Text output;
bool batalla = false;
int curas = 1;
int magia = 2;

void calcBatle(Personaje& heroe, Enemigo& enemigo, bool& move) {
    if (turno > 1){
        if (turno % 2 == 0){
            int daño = rand() % enemigo.getAttack() +5;
            heroe.setHp(heroe.getHp() - daño);
            output.setString("El "+ enemigo.getName() + " te ha hecho  " + to_string(daño) + " de daño");
            turno += 1;
            move = false;
        }
    }

    if (enemigo.getHp() <= 0) {
        turno = 1;
        killCount += 1;
        batalla = false;
        move = false;
        ene = -1;
        output.setString("Has eliminado a  " + enemigo.getName());
        int posibilidad = rand() % 100 + 1;
        if (posibilidad >7){
            curas += 1;
        }
        else {
            magia += 1;
        }
        
        enemigo.setVisble(false);
    }
}

int main(){
    srand(time(NULL));
    int HEIGHT = 600;
    int WIDTH = 700;
    bool presionada = false;
    string tecla = "";

    bool move = false;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Juego Enemigos  >_<");
    sf::Font fuente;
    if (!fuente.loadFromFile("data/terminal.ttf")){
        return EXIT_FAILURE;
    }
    output.setFont(fuente);
    output.setCharacterSize(27);
    output.setPosition(20, 530);

    sf::Text vida;
    vida.setFont(fuente);
    vida.setCharacterSize(30);
    vida.setPosition(630, 65);

    sf::Text kills;
    kills.setFont(fuente);
    kills.setCharacterSize(30);
    kills.setPosition(641, 177);
    
    sf::Text curaLabel;
    curaLabel.setFont(fuente);
    curaLabel.setCharacterSize(30);
    curaLabel.setPosition(665, 422);


    sf::Text magiaLabel;
    magiaLabel.setString("x3");
    magiaLabel.setFont(fuente);
    magiaLabel.setCharacterSize(30);
    magiaLabel.setPosition(665, 347);

    Texture f;
    f.loadFromFile("sprites/fondo2.png");
    RectangleShape fondo(sf::Vector2f(WIDTH, HEIGHT));
    fondo.setTexture(&f);

    RectangleShape botonAtk(sf::Vector2f(67, 59));
    botonAtk.setPosition(613, 245);
    botonAtk.setFillColor(Color(255, 0, 0, 0));

    RectangleShape botonHeal(sf::Vector2f(67, 59));
    botonHeal.setPosition(613, 393);
    botonHeal.setFillColor(Color(255, 0, 0, 0));

    RectangleShape botonMagia(sf::Vector2f(67, 59));
    botonMagia.setPosition(613, 318);
    botonMagia.setFillColor(Color(255, 0, 0, 0));

    RectangleShape botonCont(sf::Vector2f(67, 40));
    botonCont.setPosition(613, 466);
    botonCont.setFillColor(Color(255, 0, 0, 0));

    // INSTANCIA HEROE
    Personaje heroe("sprites/persona.png", 0, 3, "heroe", 30, 150,40, true);
    // QUITAR
    //x = 3;
    //y = 1;

    // SALIDA 
    Personaje guarida("sprites/guarida.png", rand()% 6, 5, "salida", 0, 0, 0, true);

    // INSTANCIAS ENEMIGOS
    Enemigo enemigo1("sprites/enemigo.png", "Bokoblin", 20, 80, false);
    Enemigo enemigo2("sprites/enemigo.png", "Bokoblin", 20, 60, false);
    Enemigo enemigo3("sprites/enemigo.png", "Bokoblin", 20, 90, false);
    Enemigo enemigo4("sprites/enemigo.png", "Bokoblin", 20, 60, false);
    
    // INSTANCIA ENEMIGO FINAL
    EnemigoFinal enemigoFinal("sprites/enemigoFinal.png", 3, 3, "Ganondorf", 20, 150, true,50,70);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::W) && !presionada && !batalla && fase == 1) {
                if (y > 0){
                    y -= 1;
                }
                presionada = true;
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::A) && !presionada && !batalla && fase == 1) {
                presionada = true;
                if (x > 0){
                    x -= 1;
                }
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::S) && !presionada && !batalla && fase == 1) {
                if (y < 5){
                    y += 1;
                }
                presionada = true;
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::D) && !presionada && !batalla && fase == 1) {
                presionada = true;
                if (x < 6){
                    x += 1;
                }
            }

            if (event.type == Event::KeyReleased) {
                sleep_for(nanoseconds(1000));
                presionada = false;
                
                if (enemigo1.checkCol(heroe.getVirtualX(), heroe.getVirtualY()) && !batalla && enemigo1.getHp() > 0 && fase == 1) {
                    output.setString("Te has encontrado con " + enemigo1.getName());
                    enemigo1.setVisble(true);
                    batalla = true;
                    turno = 1;
                    ene = 1;
                }else if (enemigo2.checkCol(heroe.getVirtualX(), heroe.getVirtualY()) && !batalla && enemigo2.getHp() > 0 && fase == 1) {
                    output.setString("Te has encontrado con " + enemigo2.getName());
                    enemigo2.setVisble(true);
                    batalla = true;
                    turno = 1;
                    ene = 2;
                }else if (enemigo3.checkCol(heroe.getVirtualX(), heroe.getVirtualY()) && !batalla && enemigo3.getHp() > 0 && fase == 1) {
                    output.setString("Te has encontrado con " + enemigo3.getName());
                    enemigo3.setVisble(true);
                    batalla = true;
                    turno = 1;
                    ene = 3;
                }else if (enemigo4.checkCol(heroe.getVirtualX(), heroe.getVirtualY()) && !batalla && enemigo4.getHp() > 0 && fase == 1) {
                    output.setString("Te has encontrado con " + enemigo4.getName());
                    enemigo4.setVisble(true);
                    batalla = true;
                    turno = 1;
                    ene = 4;
                }if (guarida.getVirtualX() == heroe.getVirtualX() && guarida.getVirtualY() == heroe.getVirtualY() && fase == 1)
                {
                    cout << "Fase 1 completada";
                    output.setString("Has avanzado a la fase 2, te has encontrado con" + enemigoFinal.getName());
                    x = 3;
                    y = 1;
                    fase = 2;
                    batalla = true;
                    turno = 1;
                }
                //cout << heroe.getVirtualX() << heroe.getVirtualY();
            }
            if (event.type == Event::MouseButtonPressed) {
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                if (botonAtk.getGlobalBounds().contains(mousePos) && batalla && turno % 2 != 0 && !move && turno > 1) {

                    int daño = rand() % heroe.getAttack() + 15;
                    cout << daño;
                    if (fase == 1){
                        if (ene == 1) {
                            enemigo1.setHp(enemigo1.getHp() - daño);
                        }
                        else if (ene == 2) {
                            enemigo2.setHp(enemigo2.getHp() - daño);
                        }
                        else if (ene == 3) {
                            enemigo3.setHp(enemigo3.getHp() - daño);
                        }
                        else if (ene == 4) {
                            enemigo4.setHp(enemigo4.getHp() - daño);
                        }
                    }else if (fase == 2){
                        enemigoFinal.setHp(enemigoFinal.getHp() - daño);
                    }
                    

                    output.setString("Has realizado " + to_string(daño) + " punto de daño con espada");
                    move = true;
                    
                }
                if (botonMagia.getGlobalBounds().contains(mousePos) && batalla && turno % 2 != 0 && !move && turno > 1 && magia > 0) {

                    int daño = rand() % heroe.getAttackMagia() + 25;
                    cout << daño;
                    if (fase == 1) {
                        if (ene == 1) {
                            enemigo1.setHp(enemigo1.getHp() - daño);
                        }
                        else if (ene == 2) {
                            enemigo2.setHp(enemigo2.getHp() - daño);
                        }
                        else if (ene == 3) {
                            enemigo3.setHp(enemigo3.getHp() - daño);
                        }
                        else if (ene == 4) {
                            enemigo4.setHp(enemigo4.getHp() - daño);
                        }
                    }
                    else if (fase == 2) {
                        enemigoFinal.setHp(enemigoFinal.getHp() - daño);
                    }
                    output.setString("Has realizado " + to_string(daño) + " punto de daño con magia");
                    move = true;
                    magia -= 1;
                }
                if (botonHeal.getGlobalBounds().contains(mousePos) && batalla && turno % 2 != 0 && !move && turno > 1 && curas > 0) {
                    int valorCuras = rand() % 65 + 15;
                    
                    heroe.setHp(heroe.getHp() + valorCuras);
                    move = true;
                    curas -= 1;
                    output.setString("Has usado una cura -> +" + to_string(valorCuras));
                }
                if (botonCont.getGlobalBounds().contains(mousePos) && batalla && heroe.getHp() > 0) {

                    turno += 1;

                }
            }
        }
        if (batalla){
            if (fase == 1)
            {
                if (ene == 1) {
                    calcBatle(heroe, enemigo1, move);
                }
                else if (ene == 2) {
                    calcBatle(heroe, enemigo2, move);
                }
                else if (ene == 3) {
                    calcBatle(heroe, enemigo3, move);
                }
                else if (ene == 4) {
                    calcBatle(heroe, enemigo4, move);
                }
            }else if (fase == 2){
                if (turno > 1){
                    if (turno % 2 == 0){
                        int daño;
                        string txt = "";
                        int dado = rand() % 100;

                        if (dado > 60){
                            daño = rand() % enemigoFinal.getAttack();
                        }else if (dado > 85){
                            daño = rand() % enemigoFinal.getAttackFinal();
                            txt = " con su ataque final";
                        }else {
                            daño = rand() % enemigoFinal.getAttackUltimate();
                            txt = " con su ultimate";
                        }

                        

                        heroe.setHp(heroe.getHp() - daño);
                        output.setString("El " + enemigoFinal.getName() + " te ha hecho  " + to_string(daño) + " de daño" + txt);
                        turno += 1;
                        move = false;

                        cout << enemigoFinal.getHp();
                    }

                    if (enemigoFinal.getHp() <= 0) {
                        turno = 1;
                        killCount += 1;
                        batalla = false;
                        move = false;
                        ene = -1;
                        output.setString("Has eliminado a  " + enemigoFinal.getName() + "has completado le juego");
                        curas += 1;
                        enemigoFinal.setVisble(false);
                    }
                }

            }

        }

        heroe.setPosition(x ,y);

        // ACTUALIZAR INFO
        if (heroe.getHp() < 0){
            output.setString("GAME OVER");
            heroe.setHp(0);
        }

        if (heroe.getHp() >= 100){
            vida.setPosition(630, 65);
        }else {
            vida.setPosition(635, 65);
        }
        vida.setString(to_string(heroe.getHp()));
        kills.setString(to_string(killCount));
        curaLabel.setString("x" + to_string(curas));
        magiaLabel.setString("x" + to_string(magia));

        window.clear(Color(102, 153, 255));
        window.draw(fondo);
        if (fase == 1)
        {
            if (heroe.getHp() > 0)
            {
                heroe.draw(window);
                enemigo1.draw(window);
                enemigo2.draw(window);
                enemigo3.draw(window);
                enemigo4.draw(window);

                guarida.draw(window);
            }
        }
        else if(fase == 2) {
            heroe.draw(window);
            enemigoFinal.draw(window);
        }
        
        

        // BOTONES
        window.draw(botonAtk);
        window.draw(botonHeal);
        window.draw(botonCont);
        window.draw(botonMagia);
        

        // INFO
        window.draw(output);
        window.draw(vida);
        window.draw(kills);
        window.draw(curaLabel);
        window.draw(magiaLabel);


        window.display();
    }
    
    return 0;
}