#include <iostream>
#include <vector>
using namespace std;

class Player;

class Item
{
public:
    string name;
    int healAmount;

public:
    Item(string itemName, int heal)
    {
        name = itemName;
        healAmount = heal;
    }

    void use(Player &target);
};

class Inventory
{
private:
    vector<Item> items;

public:
    void addItem(Item item)
    {
        items.push_back(item);
    }

    Item getItem(int index){
        return items[index];
    }

    void showInventory()
    {
        cout << "Item yg dimiliki: " << endl;

        for (int i = 0 ; i < items.size() ; i++)
        {
            cout << items[i].name << endl;
        }
    }
};

class Player
{
private:
    Inventory inventory;
    int hp = 0;
    int maxHp = 500;

public:
    void addItem(Item item)
    {
        inventory.addItem(item);
    }

    void heal(int amount){
        hp += amount;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
    }

    void showInventory()
    {
        inventory.showInventory();
    }

    Inventory& getInventory(){
        return inventory;
    }

    void showStatus(){
        cout << hp << "/" << maxHp << endl;
    }

};

void Item::use(Player &target){
    cout << "Player menggunakan: " << name << endl;
    
    if (healAmount > 0)
    {
        target.heal(healAmount);
    }
    
}
int main()
{
    Player hero;

    Item potion("Potion", 50);
    Item sword("Sword", 0);
    Item megaPotion("Mega Potion", 100);

    hero.addItem(potion);
    hero.addItem(potion);
    hero.addItem(megaPotion);
    hero.addItem(sword);

    hero.showInventory();

    Item item = hero.getInventory().getItem(0);
    item.use(hero);

    hero.showStatus();
}