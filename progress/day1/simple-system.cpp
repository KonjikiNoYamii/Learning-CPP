#include <iostream>
using namespace std;

class Player
{
private:
    int hp;
    int maxHp;

public:
    Player()
    {
        maxHp = 300;
        hp = maxHp;
    }

    void takeDamage(int damage)
    {
        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    void heal(int amount)
    {
        hp += amount;

        if (hp > maxHp)
        {
            hp = maxHp;
        }
    }

    void showStatus()
    {
        cout << "Hp saat ini " << hp << "/" << maxHp << endl;
    }

    bool isDead()
    {
        return hp == 0;
    }
};

class Enemy {
    private:
    int damage;

    public:
    Enemy()
    {
        damage = 50;
    }

    void attack(Player &target){
        cout << "Damage: " << damage << endl;
        target.takeDamage(damage);
    };
};

int main()
{
    Player hero;
    Enemy maou;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Musuh menyerang!" << endl;
        maou.attack(hero);
        cout << "Player terkena serangan " << i << "x" << endl;
        if (hero.isDead())
        {
            cout << "Player mati" << endl;
            break;
        }
        else
        {
            hero.heal(5);
            hero.showStatus();
        }
    }
}

