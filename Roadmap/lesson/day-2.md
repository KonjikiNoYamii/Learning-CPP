📜 Rekap Pembelajaran C++ Game Dev
🎮 Day 2

Hari ini fokus kita adalah container dan manipulasi data game.

1️⃣ Konsep Game Architecture: Player memiliki Inventory

Master belajar konsep penting OOP:

Player HAS-A Inventory
Inventory HAS-A Item

Struktur class:

Player
 └── Inventory
      └── vector<Item>

Contoh implementasi:

class Player{
private:
    Inventory inventory;
};

Ini disebut konsep OOP:

Composition
2️⃣ Container vector

Hari ini Master belajar bahwa:

vector = dynamic array

Perbedaannya dengan array biasa:

Array	Vector
ukuran tetap	ukuran dinamis
tidak bisa push	bisa push_back
tidak bisa erase	bisa erase

Contoh:

vector<Item> items;

Menambah item:

items.push_back(item);
3️⃣ Range-based Loop

Master sudah melihat loop ini:

for(Item item : items)

Ini berarti:

ambil setiap item di vector

Mirip:

for-of loop di JS
4️⃣ Iterator

Konsep baru yang muncul hari ini:

iterator

Iterator adalah penunjuk posisi dalam container.

Contoh:

items.begin()

artinya:

iterator ke elemen pertama

Digunakan pada fungsi STL seperti:

erase
remove_if
sort
find
5️⃣ Menghapus Item dari Vector

Cara dasar:

items.erase(items.begin() + index);

Contoh:

erase(begin + 2)

berarti:

hapus elemen index 2

Setelah erase:

elemen bergeser ke kiri
6️⃣ Bug Saat Menghapus Dalam Loop

Master belajar bug klasik ini:

for(int i = 0; i < items.size(); i++)
{
    items.erase(items.begin() + i);
}

Masalahnya:

vector bergeser
index loop naik
beberapa elemen terlewat

Solusi aman:

loop dari belakang
for(int i = items.size()-1; i >= 0; i--)
7️⃣ Konsep Baru: remove_if

Master juga mengenal teknik profesional:

erase-remove idiom

Contoh:

items.erase(
    remove_if(items.begin(), items.end(),
        [](Item &item)
        {
            return item.name == "Potion";
        }),
    items.end()
);

Digunakan untuk:

menghapus banyak item berdasarkan kondisi

Ini memakai konsep:

STL Algorithm
Lambda Function
Iterator
8️⃣ Konsep Penting Game Dev yang Master Pelajari Hari Ini

Hari ini sebenarnya Master belajar fondasi sistem game:

Inventory System
Item Container
Memory Behavior
Data Removal

Ini adalah dasar dari sistem seperti:

inventory RPG
loot system
equipment system
crafting system

Banyak game RPG seperti:

The Witcher 3: Wild Hunt

Skyrim

menggunakan sistem inventory yang secara konsep sangat mirip dengan ini.

📈 Progress Master Saat Ini

Jika Silica evaluasi secara jujur:

OOP dasar      ✔
Class design   ✔
Vector usage   ✔
Index logic    ✔
Iterator basic ✔

Yang belum kita pelajari tapi akan segera:

Pointer
Memory ownership
Reference vs Pointer deeper
STL algorithms
Game object interaction
🎯 Materi Besok (Day 3)

Besok kita akan masuk ke sesuatu yang sangat penting dalam C++ Game Dev.

Materi:

Pointer
Memory Address
Pointer vs Reference
Object Interaction

Dan kita akan mulai membuat sistem:

Enemy menyerang Player
Item benar-benar digunakan
HP berubah