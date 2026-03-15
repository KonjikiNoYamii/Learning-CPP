🎮 Rekap Pembelajaran C++ Game Dev
Day 4 — Object Interaction & Memory Ownership

Hari ini fokus utama kita adalah:

interaksi object game
dan cara menyimpan object di container dengan aman

Ini adalah fondasi sistem game seperti:

combat system

enemy system

entity management

1️⃣ Object Interaction

Game pada dasarnya adalah object yang saling mempengaruhi.

Contoh sederhana:

Player menyerang Enemy
Enemy menyerang Player

Contoh implementasi:

class Player
{
public:
    int hp;
    int damage;

    void attack(Enemy &enemy);
};

dan

class Enemy
{
public:
    int hp;
    int damage;

    void attack(Player &player);
};

Ini disebut:

object interaction

Object dapat mengubah state object lain.

2️⃣ Reference Parameter

Master melihat syntax seperti ini:

void attack(Enemy &target)

& berarti:

reference

Artinya:

function menerima object asli
bukan copy

Contoh:

hero.attack(enemy);

yang dimodifikasi adalah:

enemy asli

bukan salinan.

3️⃣ Pointer vs Reference (Ringkasan Penting)

Pointer

Enemy* enemy

dipanggil dengan:

enemy->hp

Reference

Enemy& enemy

dipanggil dengan:

enemy.hp

Perbedaan utama:

Pointer	Reference
bisa null	tidak bisa null
perlu dereference	langsung akses
dipakai untuk ownership	dipakai untuk parameter

Dalam game biasanya:

parameter → reference
ownership → pointer
4️⃣ Forward Declaration

Master juga melihat hal ini:

class Enemy;

Ini disebut:

forward declaration

Digunakan karena:

Player perlu tahu Enemy
Enemy juga perlu tahu Player

Agar compiler tidak bingung.

5️⃣ Smart Pointer

Hari ini Master mulai memakai:

unique_ptr

Contoh:

vector<unique_ptr<Enemy>> enemies;

Artinya:

vector memiliki semua Enemy

Jika enemy dihapus dari vector:

enemy otomatis dihancurkan

Ini bagian dari konsep RAII dalam C++.

6️⃣ Membuat Enemy

Enemy dibuat dengan:

make_unique<Enemy>(100,20)

Contoh:

enemies.push_back(make_unique<Enemy>(100,20));

Keuntungan:

lebih aman
lebih modern
tidak perlu delete manual
7️⃣ Dereference Smart Pointer

Karena enemy adalah:

unique_ptr<Enemy>

maka untuk mendapatkan objectnya:

*enemy

Contoh:

hero.attack(*enemy);

Penjelasan:

enemy = pointer
*enemy = object Enemy
8️⃣ Menghapus Enemy Mati

Enemy yang mati harus dihapus dari container.

Cara profesional:

enemies.erase(
    remove_if(
        enemies.begin(),
        enemies.end(),
        [](const unique_ptr<Enemy>& enemy)
        {
            return enemy->hp <= 0;
        }
    ),
    enemies.end()
);

Ini disebut:

erase-remove idiom

Digunakan untuk:

menghapus banyak elemen berdasarkan kondisi
9️⃣ Lambda Function

Master juga melihat syntax ini:

[](const unique_ptr<Enemy>& enemy)
{
    return enemy->hp <= 0;
}

Ini disebut:

lambda function

Artinya:

function kecil tanpa nama

Biasanya dipakai di:

remove_if

sort

find

🔟 Game Loop Battle

Master membuat battle loop seperti ini:

while(hero.hp > 0 && enemies.size() > 0)

Ini berarti:

battle berlangsung sampai
hero mati atau semua enemy mati

Di dalamnya terjadi:

enemy menyerang hero
hero menyerang enemy
enemy mati dihapus

Ini adalah mini combat simulator.

🧠 Konsep Game Dev Yang Master Pelajari Hari Ini

Hari ini sebenarnya Master belajar fondasi penting game engine.

Object interaction
Entity container
Memory ownership
Smart pointer
Entity removal
Game loop

Ini adalah dasar dari sistem seperti:

combat system

enemy manager

entity system