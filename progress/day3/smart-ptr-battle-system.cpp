#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Enemy;

class Player {
    public:
    int hp;
    int damage;

    Player(int hp, int damage){
        this->hp = hp;
        this->damage = damage;
    }

    void attack(Enemy* target);
};

class Enemy{
    public:
    int hp;
    int damage;

    Enemy(int hp, int damage){
        this->hp = hp;
        this->damage = damage;
    }

    void attack(Player* target){
        target->hp -= damage;
        if (target->hp < 0)
        {
            target->hp = 0;
        }
        
    }
};

void Player::attack(Enemy* target){
    target->hp -= damage;

    if (target-> hp < 0)
    {
        target-> hp = 0;
    }
    
}

int main(){
    Player hero(100,101);

    vector<unique_ptr<Enemy>> enemies;

    enemies.push_back(make_unique<Enemy>(100, 20));
    enemies.push_back(make_unique<Enemy>(100, 30));
    enemies.push_back(make_unique<Enemy>(100, 10));

    cout << "Enemy menyerang!" << endl;


    for(auto& enemy: enemies){
        
        enemy->attack(&hero);

        cout << "Player menyerang!" << endl;
        hero.attack(enemy.get());
        cout << "Hp enemy: " << enemy->hp << endl;
        cout << "Hp hero: " << hero.hp << endl;

    }
    
    
}