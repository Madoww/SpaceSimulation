#include <stdio.h>
#include "UserInterface.h"

UserInterface::UserInterface()
{
    windows.push_back(new PlanetCreationWindow());
}
