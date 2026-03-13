#include <iostream>
using namespace std;

class Player {
    public:

    int hp = 100;

    
};

class Enemy {
    public:
    int damage = 20;

    void attack(Player* target){
        target->hp -= damage;
    }
};

void damage(Player* target){
    target->hp -= 25;
}

void heal(Player* target){
    target->hp += 20;
}

int main(){

    Player hero;
    Enemy slime;

    cout << "Hp awal: " << hero.hp << endl;

    damage(&hero);

    cout << "Hp setelah diserang: " << hero.hp << endl;

    heal(&hero);

    cout << "Hp setelah heal: " << hero.hp << endl;

    slime.attack(&hero);

    cout << "Slime menyerang!" << endl;

    cout << "Memberikan damage: " << slime.damage << " Hp player: " << hero.hp << endl;

}