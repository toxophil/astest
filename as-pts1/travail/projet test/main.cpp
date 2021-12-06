#include <SFML/Graphics.hpp>
#include "Classes/Header/GameMaster.hpp"
#include "Classes/Header/Player.hpp"
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
    srand(time(NULL));
    /* start music)*/
    Music music;
    if (!music.openFromFile("Ressources/ana.ogg"))
        return -1; // error
     
     music.setPitch(1);           // increase the pitch
     music.setVolume(100);         // reduce the volume
     music.setLoop(true);         // make it loop
     music.play();

    GameMaster& gm = GameMaster::getInstance();

    gm.runGame();

    return 0;
}