#include <SFML/Graphics.hpp>
#include "Classes/Header/GameMaster.hpp"
#include "Classes/Header/Player.hpp"


int main()
{
    
    GameMaster& gm = GameMaster::getInstance();

    gm.runGame();

    return 0;
}