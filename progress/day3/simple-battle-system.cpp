#include <iostream>
using namespace std;

class Player
{
public:
    int hp = 100;
};

class Enemy
{
public:
    int damage = 20;

    void attack(Player *target)
    {
        target->hp -= damage;
    }
};

void heal(Player *target)
{
    target->hp += 20;
}

int main()
{
    Player hero;
    Enemy slime;
    Enemy goblin;

    cout << "Hero hp awal: " << hero.hp << endl;

    cout << "Slime menyerang!" << endl;
    slime.attack(&hero);
    cout << "Hp hero: " << hero.hp << endl;

    cout << "Goblin menyerang!" << endl;
    goblin.attack(&hero);
    cout << "Hp hero: " << hero.hp << endl;

    cout << "Hero menggunakan heal!" << endl;
    heal(&hero);
    cout << "Hp hero: " << hero.hp << endl;
}