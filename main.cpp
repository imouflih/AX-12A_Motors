#include "Actuators.hpp"
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv)
{
    // if (argc != 4)
    // {
    //     std::cerr << "Usage: " << argv[0] << " <dynamixel_id> <goal_position> <speed>" << std::endl;
    //     return 1;
    // }

    int dxlID1 = 1;
    int dxlID2 = 2;
    // int speed1 = std::stoi(argv[1]);
    // int speed2 = std::stoi(argv[2]);
    // int goalPosition1 = std::stoi(argv[3]);
    // int goalPosition2 = std::stoi(argv[4]);

    Actuators actuator1(dxlID1);
    Actuators actuator2(dxlID2);

    std::cout << "Setting goal position in second motor" << std::endl;

    if (!actuator1.setMovingSpeed(1023))
    {
        std::cerr << "Failed to set moving speed in the ax-12a : 1" << std::endl;
        return 1;
    }

    if (!actuator1.setGoalPosition(875))
    {
        std::cerr << "Failed to set goal position in the ax-12a : 1" << std::endl;
        return 1;
    }

    sleep(2);

    std::cout << "Setting goal position 2" << std::endl;

    if (!actuator1.setGoalPosition(705))
    {
        std::cerr << "Failed to set goal position in the ax-12a : 1" << std::endl;
        return 1;
    }

    sleep(1);

    std::cout << "Setting goal position in second motor" << std::endl;

    if (!actuator2.setMovingSpeed(50))
    {
        std::cerr << "Failed to set moving speed in the ax-12a : 2" << std::endl;
        return 1;
    }

    if (!actuator2.setGoalPosition(0))
    {
        std::cerr << "Failed to set goal position in the ax-12a : 2" << std::endl;
        return 1;
    }

    sleep(11);

    std::cout << "Setting goal position 2" << std::endl;

    if (!actuator2.setGoalPosition(1023))
    {
        std::cerr << "Failed to set goal position in the ax-12a : 2" << std::endl;
        return 1;
    }

    return 0;
}