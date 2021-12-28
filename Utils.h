#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const int MAX_NUM_OF_ROW = 40;
const int MAX_NUM_OF_COL = 40;
const int MAX_NUM_OF_LEVAL = 3;
int const CELL = 100;
const int NUM_OF_TEXTURES = 25;
const double MENU_WIDTH = 260;
const int START_WINDOW = 20;
const int MENU_HIGHT = 560;
const int SELL = 40;//שוליים
const int BUTTON_FIRST = 30;
const int BUTTON_SPACE = 90;
const int DEFULT_SIZE = 0;
const int START_BOARD = 0;
const int START_LEVEL = 1;
const int LIFE_START = 3;
const int IMAGE_SIZE = 90;
const int PLAYER_JUMP_HEIGHT = 200;
const std::string FILENAME = "Board.txt";
const sf::Vector2f DEFULT_POSITOION = { 0,0 };
const sf::Vector2f WINDOW_SIZE = {1500,900 };
const sf::Vector2f BUTTON_SIZE = {200,70 };
const sf::VideoMode WINDOW__DEFULT_SIZE = {1500,900 };
const sf::Vector2f GAME_MENU_SIZE = {1500,110};
const sf::Vector2f BOARD_SIZE = { WINDOW_SIZE.x,WINDOW_SIZE.y - GAME_MENU_SIZE.y};
const sf::Vector2f PLAYER_LOCATION = { 130,780 };
const int SCOUR_START = 0;
const int NUM_OF_STEPS=5;
const char PLAY = '@';
const char GUARDS = '%';
const char WALLS = '-';
const char FLOORS = '#';
const char LADDERS = 'H';
const char MONE = '*';
const char PRESENT = '+';
const char DOOR = '/';
const char LEAVE = '!';
const char STOP = '^';
enum Dirc
{
	RIGHT, LEFT, DOWN,UP,DEFAULT
};
const std::vector <sf::Vector2f> DIRCTHION = { { 1, 0 } ,{ -1, 0 } , { 0, 1 } , { 0, -1 } ,{0,0} };
enum Shape
{
	SRAET_GAME, BACKGROUND1, BACKGROUND2, BACKGROUND3, FLOOR, FLOOR1,WALL,PLAYER, PLAYERSHOT, GUARD ,SCOREGIFT,LIFEGIFT,SHOTGIFT, PROTECTIONGIFT,SADPLAYER,ENDLEVEL,
	ENDLEVEL1, PROTECTION,MONEY,
	SHOT,WIN, LEAVES,HELP,STOPP,END_GAME
};