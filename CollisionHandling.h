#pragma once
#include "Object.h"
#include "Guard.h"
#include "Floor.h"
#include "Door.h"
#include "Player.h"
#include "Shot.h"
#include "ScoreGift.h";
#include "LifeGift.h";
#include "Utils.h"
#include <iostream>
#include <typeinfo>

struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(Object& a, Object& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {
    }
};

void processCollision(Object& object1, Object& object2);