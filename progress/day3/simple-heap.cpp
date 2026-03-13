#include <iostream>
using namespace std;

class Player {
    public:
    int hp;

    Player(int hp){
        this->hp = hp;
    }
};

class Enemy {
    public:
    int damage = 20;

    void attack(Player* target){
        target->hp -= damage;
    }
};

int main (){
    Player hero(100);

    Enemy* slime = new Enemy();

    cout << "Slime menyerang!" << endl;
    slime->attack(&hero);
    cout << "Damage slime sebesar: " << slime->damage << endl;

    Enemy* goblin = new Enemy();

    cout << "Goblin menyerang!" << endl;
    goblin->attack(&hero);
    cout << "Damage goblin sebesar: " << goblin->damage << endl;

    delete slime;
    delete goblin;
}