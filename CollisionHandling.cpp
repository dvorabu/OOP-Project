#include "CollisionHandling.h"
#include "ProtectionGift.h"
#include "ShotGift.h"
#include "Money.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "ProtectionState.h"
#include "Wall.h"
#include "Leaves.h"
#include "Stop.h"
namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    void playerGuard(Object&pl , Object& gu)
    {
         Guard& guard = dynamic_cast<Guard&>(gu);
         Player&  player  = dynamic_cast<Player&>(pl);
         if (player.getProtection())
         {
             player.NotifyObserversPlayer(guard.getIndex(),false);
             return;
         }
             
         if (gu.objectGlobal().y > pl.objectGlobal().y)
         {
             player.setScore(10);
             player.NotifyObserversPlayer(guard.getIndex(), false);
             return;
         }
         player.setLife(-1);
         player.NotifyObserversPlayer(guard.getIndex(), true);
         return;

    }
    void guardFloor(Object& gu, Object& fl)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Floor& floor = dynamic_cast<Floor&>(fl);
        guard.setMove(Dirc::DEFAULT);
    }
    void guardMoney(Object& gu, Object& mo)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Money& money = dynamic_cast<Money&>(mo);
    }
    void guardDoor(Object& gu, Object& d)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Door& money = dynamic_cast<Door&>(d);
    }
    void guardStop(Object& gu, Object& d)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Stop& money = dynamic_cast<Stop&>(d);
    }
    void guardLeaves(Object& gu, Object& d)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Leaves& money = dynamic_cast<Leaves&>(d);
    }
    void guardWall(Object& gu, Object& d)
    {
        Guard& guard = dynamic_cast<Guard&>(gu);
        Wall& money = dynamic_cast<Wall&>(d);
    }
    void playerFloor(Object& pl, Object& fl)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Floor& floor = dynamic_cast<Floor&>(fl);
        player.setFall(false);
    }
    void playerStop(Object& pl, Object& fl)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Stop& floor = dynamic_cast<Stop&>(fl);
        player.setDirc(DIRCTHION[Dirc::DEFAULT]);
        player.setEnd(true);
    }
    void playerWall(Object& pl, Object& wa)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Wall& floor = dynamic_cast<Wall&>(wa);
        player.setFall(false);
    }
    void playerLeaves(Object& pl, Object& wa)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Leaves& leaves = dynamic_cast<Leaves&>(wa);
        player.setFall(true);
    }
    void playerDoor(Object& pl, Object& d)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Door& door = dynamic_cast<Door&>(d);
        player.NotifyObserversDoor(true);
        player.setScore(20);
    }
    void playerScoreGift(Object& pl, Object& gi)
    {
        Player& player = dynamic_cast<Player&>(pl);
       ScoreGift& score = dynamic_cast<ScoreGift&>(gi);
        player.setScore(20);
        player.NotifyObservers(score.getIndex());
    }
    void playerShotGift(Object& pl, Object& gi)
    {
        Player& player = dynamic_cast<Player&>(pl);
        ShotGift& shot = dynamic_cast<ShotGift&>(gi);
        player.setShot(true);
        player.NotifyObservers(shot.getIndex());	
        player.getSprite().setTexture(ResourceManager::instance().getImage(Shape::PLAYERSHOT));


    }
    void playerProtectionGift(Object& pl, Object& gi)
    {
        Player& player = dynamic_cast<Player&>(pl);
        ProtectionGift& protection = dynamic_cast<ProtectionGift&>(gi);
        player.setState(std::make_unique<ProtectionState>());
        player.enterState();
        player.NotifyObservers(protection.getIndex());

    }
    void playerLifeGift(Object& pl, Object& gi)
    {
        Player& player = dynamic_cast<Player&>(pl);
        LifeGift& life = dynamic_cast<LifeGift&>(gi);
        player.setLife(1);
        player.NotifyObservers(life.getIndex());

    }
    void playerMoney(Object& pl, Object& mo)
    {
        Player& player = dynamic_cast<Player&>(pl);
        Money& money = dynamic_cast<Money&>(mo);
        money.setDelete();
        player.setScore(10);
    }


    //...

    using HitFunctionPtr = void (*)(Object&, Object&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Guard), typeid(Money))] = &guardMoney;
        phm[Key(typeid(Guard), typeid(Door))] = &guardDoor;
        phm[Key(typeid(Guard), typeid(Stop))] = &guardStop;
        phm[Key(typeid(Guard), typeid(Floor))] = &guardFloor;
        phm[Key(typeid(Guard), typeid(Leaves))] = &guardLeaves;
        phm[Key(typeid(Guard), typeid(Wall))] = &guardWall;
        phm[Key(typeid(Player), typeid(Guard))] = &playerGuard;
        phm[Key(typeid(Player), typeid(Floor))] = &playerFloor;
        phm[Key(typeid(Player), typeid(Stop))] = &playerStop;
        phm[Key(typeid(Player), typeid(Leaves))] = &playerLeaves;
        phm[Key(typeid(Player), typeid(Wall))] = &playerWall;
        phm[Key(typeid(Player), typeid(ScoreGift))] = &playerScoreGift;
        phm[Key(typeid(Player), typeid(ShotGift))] = &playerShotGift;
        phm[Key(typeid(Player), typeid(ProtectionGift))] = &playerProtectionGift;
        phm[Key(typeid(Player), typeid(LifeGift))] = &playerLifeGift;
        phm[Key(typeid(Player), typeid(Door))] = &playerDoor;
        phm[Key(typeid(Player), typeid(Money))] = &playerMoney;

        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
