#include "Controller.h"
#include "NewGame.h"
#include <thread>

int main()
{
    try
    {
    srand(time(NULL));
        Controller c;
        c.run();
    }

    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}
