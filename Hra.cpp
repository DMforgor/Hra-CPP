#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
string pokracovat;
string jmeno;
int input;
bool jmenoconfirm = 0;
bool classconfirm = 0;
int classvyber;
string classjmeno;
int hracmaxhp;
int hrachp;
int hracatk;
int hracmaxmana;
int hracmana;
string hraczbran;
int spell;
bool spellunlock[3];
string spellname[4];
int level = 1;
int experience = 0;
int stage;
int monsterID;
string monstername[] = {"Slimak", "Troll", "Goblin", "Lupic"};
bool bossfight = 0;
bool pribehskip =0;
int miniboss;
string minibossname[] = {""};
int armorlvl = 0;
int armorupg[6][3] = {{5, 1, 1},
                      {8, 1, 1},
                      {3, 1, 1},
                      {4, 1, 1},
                      {5, 1, 1},
                      {4, 1, 1}};

int stagecheck (int stage) {
if (stage==1) {return 1;}
else if (stage==2)  {return 2;}
else if (stage==3)  {return 3;}
else if (stage==4)  {return 4;}
else if (stage==5)  {return 5;}
else {return 0;}

}
void statcheck(string jmeno, int maxhp, int hp, int atk, int maxmana, int mana, string zbran, int spell, bool spellunlock[], string spellname[], int level, int experience, int stage) {
cout << "Jmeno: " << jmeno << endl;
cout << "Stage: " << stage << endl;
cout << "Level: " << level << endl << "Exp: " << experience << endl;
cout << "Maximalni zivoty: " << maxhp << endl << "Zivoty: " << hp << endl;
cout << "Utok: " << atk << endl;
cout << "Maximalni mana: " << maxmana << endl << "Mana: " << mana << endl;
cout << "Zbran: " << zbran << endl;
cout << "Spelly: " << spellname[0] << endl;
for (int i; i<=3; i++) {
    if (spellunlock[i]==true) {
        cout << spellname[i+1] << endl;
    }
}
}


bool odejit = 0;
string stagename[] = {"Zacatecnicka vesnice", "Plane"};
int main(){
    int stagetype;
    int stage = 1;
    cout << "RPG HRA - HLAVNI MENU" << endl << "Zapiste cokoliv a stistknete Enter pro zahajeni hry.";
    cin >> pokracovat;
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
            cout << endl << "Zivoty: 10" << endl << "Utok: 9" << endl << "Mana: 10" << endl << "Zbran: Kuse" << endl << "Zakladni schopnost: Rychla Palba" << endl << "Vystrelte nekolik sipu davajici poskozeni." << endl;
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
}while (classvyber<1||classvyber>6&&classconfirm==false);
switch(classvyber) {
    case 1: classjmeno = "Rytir"; hracmaxhp = 10; hrachp = 10; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Mec"; spellname[0] = "Dvojity Svih"; break;
    case 2: classjmeno = "Paladin"; hracmaxhp = 20; hrachp = 20; hracatk =4; hracmaxmana = 5; hracmana = 5; hraczbran = "Kladivo"; spellname[0] = "Obrana"; break;
    case 3: classjmeno = "Mag"; hracmaxhp = 6; hrachp = 6; hracatk =4; hracmaxmana = 20; hracmana = 20; hraczbran = "Hul"; spellname[0] = "Ohniva Koule"; break;
    case 4: classjmeno = "Lupic"; hracmaxhp = 8; hrachp = 8; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Dyka"; spellname[0] = "Kradez"; break;
    case 5: classjmeno = "Lovec"; hracmaxhp = 10; hrachp = 10; hracatk =9; hracmaxmana = 10; hracmana = 10; hraczbran = "Kuse"; spellname[0] = "Rychla Palba"; break;
    case 6: classjmeno = "Assassin"; hracmaxhp = 8; hrachp = 8; hracatk =6; hracmaxmana = 10; hracmana = 10; hraczbran = "Dvojite Dyky"; spellname[0] = "Neviditelnost"; break;
}
do {
cout << "Zadejte vase jmeno: "; cin >> jmeno;
cout << jmeno << " je to takhle spravne? (0 - Ne, 1 - Ano)";
cin >> jmenoconfirm;
}while (jmenoconfirm==0);
system("cls");
do {
cout << "Chcete si vyslechnou pribeh teto zemì? (0 - Ne 1 - Ano)";
cin >> pribehskip;
}while(pribehskip!=0&&pribehskip!=1);
if (pribehskip==1) {
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Pred davnymi lety byvalo vsechno mirumilovne a klidne," << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "bohuzel ale jednoho dne nastala katastrofa." << endl;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Obloha se rozzarila a zdevastovala horu." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Vsechno pobliz hory bylo pokryto ledem a nic nezbylo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Tim ale pribeh nekonci," << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Ledova kletba se zacala dale sirit a monstra se zacala objevovat a utocit na lidstvo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Kletba se pomalu, ale jiste blizi k dalsim vesnicim a pohlcuje lidstvo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokracovani)" << endl << "Kdy se objevi hrdina co kletbu ukonci?" << endl;
cin >> pokracovat;
system ("cls");
}
stagetype = stagecheck(stage);
if (stagetype==1) {
    do {
        cout << stagename[stage-1] << endl;
        cout << "Co chcete podniknout ve vesnici?" << endl << "";
        cin >> input;
        if (input==1) {
            statcheck(jmeno, hracmaxhp, hrachp, hracatk, hracmaxmana, hracmana, hraczbran, spell, spellunlock, spellname, level, experience, stage);
        }
    }while(odejit==0);
}
return 0;
}
