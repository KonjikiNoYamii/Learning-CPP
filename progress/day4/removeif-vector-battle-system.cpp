#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
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

    void attack(Enemy &target);

};

class Enemy{
    public:
    int hp;
    int damage;

    Enemy(int hp, int damage){
        this->hp = hp;
        this->damage = damage;
    }

    void attack(Player &target){
        target.hp -= damage;
        if (target.hp < 0)
        {
            target.hp = 0;
        }
        
    }
};

void Player::attack(Enemy &target){
    target.hp -= damage;
    if (target.hp < 0)
    {
        target.hp = 0;
    }
    
}

int main(){
    Player hero(100,50);

    vector<unique_ptr<Enemy>> enemies;

    enemies.push_back(make_unique<Enemy>(100,20));
    enemies.push_back(make_unique<Enemy>(100,30));
    enemies.push_back(make_unique<Enemy>(100,10));

    while (hero.hp > 0 && enemies.size() > 0)
    {
        for (auto &enemy : enemies)
        {
            enemy->attack(hero);
            hero.attack(*enemy);
        }

        enemies.erase(
            remove_if(
                enemies.begin(),
                enemies.end(),
                [](const unique_ptr<Enemy>& enemy){
                    return enemy->hp <= 0;
                }

            ),
            enemies.end()
        );

        cout << "Enemy tersisa: " << enemies.size() << endl;
        
    }
    
}