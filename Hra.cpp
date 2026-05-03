#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
string Zahajeni;
string jmeno;
bool classconfirm = 0;
int classvyber;
int main(){
    cout << "RPG HRA - HLAVNI MENU" << endl << "Zapiste cokoliv a stistknete Enter pro zahajeni hry.";
    cin >> Zahajeni;
    system ("cls");
    do {
    cout << "Vyberte si Classu" << endl << "1) Rytir" << endl << "2) Paladin" << endl << "3) Mag" << endl << "4) Lupic" << endl << "5) Lovec" << endl << "6) Assassin";
    cin >> classvyber;
    switch(classvyber) {
        case 1:
            system ("cls");
            cout << "Rytir" << endl << "Rytir je vsestranna postava, ktera v nicem neexceluje ale ani nepostrada";
            cout << endl << "Zivoty: 10" << endl << "Utok: 3" << endl << "Mana: 10" << endl << "Zbran: Mec" << endl << "Zakladni schopnost: Dvojity svih" << endl << "Svihnete dvakrat po nepritely s mecem pro vetsi poskozeni." << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 2:
            system ("cls");
            cout << "Paladin" << endl << "Paladin je postava zamerena na zivoty a schopnost vzit do sebe co nejvice utoku";
            cout << endl << "Zivoty: 20" << endl << "Utok: 4" << endl << "Mana: 5" << endl << "Zbran: Kladivo" << endl << "Zakladni schopnost: Obrana" << endl << "Obrante se pred nepritely a znizte pozkozeni ktere dostanete tohle kolo." << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 3:
            system ("cls");
            cout << "Mag" << endl << "Mag vyuziva manu naplno pro silne utoky, neni ale fyzicky silny a ma malo zivotu.";
            cout << endl << "Zivoty: 6" << endl << "Utok: 4" << endl << "Mana: 20" << endl << "Zbran: Hul" << endl << "Zakladni schopnost: Ohniva koule" << endl << "Sezehnete nepratele silnou ohnivou kouli." << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 4:
            system ("cls");
            cout << "Lupic" << endl << "Lupic je svizna postava, ktera dokaze okrast nepritele i v chaosu boje.";
            cout << endl << "Zivoty: 8" << endl << "Utok: 3" << endl << "Mana: 10" << endl << "Zbran: Dyka" << endl << "Zakladni schopnost: Kradez" << endl << "Okradnete nepratele a ziskejte pocet zlataku" << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 5:
            system ("cls");
            cout << "Lovec" << endl << "Lovec je ozbrojen s kusi, schopny zpusobit velke pozkozeni s utoky, ale potrebuje prebijet a dokaze utocit pouze po prebyti kuse.";
            cout << endl << "Zivoty: 10" << endl << "Utok: 9" << endl << "Mana: 10" << endl << "Zbran: Kuse" << endl << "Zakladni schopnost: Rychla palba" << endl << "Vystrelte nekolik sipu davajici poskozeni." << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 6:
            system ("cls");
            cout << "Assassin" << endl << "Assassin se skryva ve stinech a ceka na spravnou chvili pro zpusobeni devastujiciho utoku";
            cout << endl << "Zivoty: 8" << endl << "Utok: 6" << endl << "Mana: 10" << endl << "Zbran: Dvojite dyky" << endl << "Zakladni schopnost: Neviditelnost" << endl << "Zneviditelnete se a stante se nachvily neschopny byt poskozen nepratelemi" << endl;
            do {
            cout << "Potvrdit Vyber? (0 - Ne, 1 - Ano)";
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatna Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            default:
            system ("cls");
            cout << "Neplatna Hodnota, Zadejte Hodnotu 1-6";
            }
}while (classvyber<1&&classvyber>6&&classconfirm==false);
return 0;
}