/*
 * Copyright (C) 2016 IIT-ADVR
 * Author: Arturo Laurenzi, Luca Muratore
 * email:  arturo.laurenzi@iit.it, luca.muratore@iit.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <homing_example.h>

SHLIBPP_DEFINE_SHARED_SUBCLASS(HomingExample_factory, XBot::HomingExample, XBot::XBotControlPlugin);

namespace XBot {

HomingExample::HomingExample()
{

}

bool HomingExample::init_control_plugin(RobotInterface::Ptr robot)
{
    _robot = robot;
    
    _robot->getRobotState("home", _q_home);
    _robot->sense();
    _robot->getJointPosition(_q0);
    
    std::cout << "_qo from SRDF : " << _q0 << std::endl;
    _time = 0;

    return true;
}

void HomingExample::control_loop(double time, double period)
{
//     std::cout << "LOOPING..." << std::endl;
//     _robot->sense();
    _robot->setPositionReference(_q0 + 0.5*(1-std::cos(0.5*(_time)))*(_q_home-_q0));
    _robot->move();
    
    _time += 0.001;
}

bool HomingExample::close()
{
    return true;
}




    
    
}