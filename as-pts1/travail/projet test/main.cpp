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
    if (!music.openFromFile("Ressources/music/menu/background/epic.ogg"))
        return -1; // error
     
    music.setPitch(1);           // increase the pitch
    music.setVolume(140);        
    music.setLoop(true);         // make it loop
    music.play();

    // Cr�er la View par default
    GameMaster& gm = GameMaster::getInstance();

    gm.runGame();

    return 0;
}