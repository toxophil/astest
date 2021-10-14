#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

float X_SPEED = 0.3;
float Y_SPEED = 0.3;

class Drawable{
protected:
    sf::CircleShape sprite;


public:
    Drawable(){
        sprite.setRadius(0.2f);
        sprite.setPosition(0, 0);
    }


    Drawable(float circleSize, float x, float y){
        sprite.setRadius(circleSize);
        sprite.setPosition(x, y);
    }

    sf::CircleShape getSprite() const{
        return sprite;
    }

};

class Projectile : public Drawable{
private:

    float x, y;
    float vX, vY;


public:

    Projectile(){
        x = 0; y =0; vX = 1; vY = 1;
        Drawable(0.1f, x, y);
    }

    /*
    Projectile(float x, float y, float vX, float vY){
        this->vX = vX;
        this->vY = vY;
        this->x = x;
        this->y = y;
        sprite.setRadius(.1f);
        sprite.setPosition(x, y);
    }
    */

    Projectile(float x, float y, float angle, float vitesse){
        this->vX = std::cos(angle) * vitesse;
        this->vY = std::sin(angle) * vitesse;
        this->x = x;
        this->y = y;
        sprite.setRadius(.1f);
        sprite.setPosition(x, y);
    }

    void move(){
        sprite.move(vX, vY);
    }

};

class Camera{
private:

    std::vector<Drawable> entity;

public:

    void addEntity(Drawable &drawEntity){
        entity.push_back(drawEntity);
    }

    void draw(sf::RenderWindow &window) const{
        for(auto i=0; i < entity.size(); i++){
            window.draw(entity[i].getSprite());
        }
    }

};


class Player : public Drawable{
private :
    float x, y;
    float vX = 0, vY = 0;
    float left = 0, right = 0, up = 0, down = 0;
    float shotSpeed = 2;


    sf::CircleShape sprite;

public:

    static bool maFonction(){
        return true;
    }

    Player(){
        x = 400.f;
        y = 400.f;
        sprite.setRadius(25.f);
        sprite.setPosition(x, y);
    }

    void computeMove(Camera &cam, sf::RenderWindow &window){
        left = 0;
        right = 0;
        up = 0;
        down = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            left = -X_SPEED;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            right = X_SPEED;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            up = -Y_SPEED;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            down = Y_SPEED;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            float angle = std::tan((x-mousePosition.x)/(y-mousePosition.y));
            Projectile proj(x, y, angle, shotSpeed);
            cam.addEntity(proj);
        }
        vX = left + right;
        vY = up + down;
    }

    void move(){
        sprite.move(vX, vY);
    }

    sf::CircleShape getSprite() const{
        return sprite;
    }


};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Magenta);

    Player player;

    Camera cam;

    cam.addEntity(player);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(window.hasFocus()){
                player.computeMove(cam, window);
            }
        }

        player.move();

        //commande d'affichage
        window.clear();
        cam.draw(window);
        window.display();

    }

    return 0;
}
