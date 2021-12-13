#include <SFML/Graphics.hpp>
#include "Classes/Header/GameMaster.hpp"
#include "Classes/Header/Player.hpp"
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
    srand(time(NULL));
    // Créer la View par default
    GameMaster& gm = GameMaster::getInstance();

    gm.runGame();

    return 0;
}