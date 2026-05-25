#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;
string pokracovat;
string jmeno;
int input;
bool jmenoconfirm = 0;
bool classconfirm = 0;
int classvyber;
string classjmeno;
int gold = 100;
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
string monstername[] = {"Slimák", "Troll", "Goblin", "Lupič"};
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
int armorupgcost[3] = {20, 40, 60};

int stagecheck (int stage) {
if (stage==1) {return 1;}
else if (stage==2)  {return 2;}
else if (stage==3)  {return 3;}
else if (stage==4)  {return 4;}
else if (stage==5)  {return 5;}
else {return 0;}

}
void statcheck(string jmeno, int maxhp, int hp, int atk, int maxmana, int mana, string zbran, int spell, bool spellunlock[], string spellname[], int level, int experience, int stage, int gold) {
cout << "Jméno: " << jmeno << endl;
cout << "Stage: " << stage << endl;
cout << "Zlaťáky: " << gold << endl;
cout << "Level: " << level << endl << "Exp: " << experience << endl;
cout << "Maximalní životy: " << maxhp << endl << "Životy: " << hp << endl;
cout << "Útok: " << atk << endl;
cout << "Maximalní mana: " << maxmana << endl << "Mana: " << mana << endl;
cout << "Zbraň: " << zbran << endl;
cout << "Spelly: " << spellname[0] << endl;
for (int i; i<=3; i++) {
    if (spellunlock[i]==true) {
        cout << spellname[i+1] << endl;
    }
}
cout << endl;
}


bool odejit = 0;
string stagename[] = {"Začátečnická vesnice", "Pláně"};
int main(){
    system("color 79");
    SetConsoleOutputCP(CP_UTF8); // povolení diakritky v konzoli
    SetConsoleCP(CP_UTF8);
    int stagetype;
    int stage = 1;
    cout << "RPG HRA - HLAVNI MENU" << endl << "Zapište cokoliv a stistkněte Enter pro zahajení hry.";
    cin >> pokracovat;
    system ("cls");
    do {
    cout << "Vyberte si Classu" << endl << "1) Rytíř" << endl << "2) Paladin" << endl << "3) Mág" << endl << "4) Lupič" << endl << "5) Lovec" << endl << "6) Assassin" << endl;
    cin >> classvyber;
    switch(classvyber) {
        case 1:
            system ("cls");
            cout << "Rytir" << endl << "Rytíř je všestranná postava, která v ničem neexceluje, ale ani nepostrádá";
            cout << endl << "Životy: 10" << endl << "Útok: 3" << endl << "Mana: 10" << endl << "Zbraň: Meč" << endl << "Základni schopnost: Dvojitý švih" << endl << "Švihněte dvakrát po nepřítely s mečem pro větší poškození." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 2:
            system ("cls");
            cout << "Paladin" << endl << "Paladin je postava zaměřená na životy a schopnost vzít do sebe co nejvíce útoku";
            cout << endl << "Životy: 20" << endl << "Útok: 4" << endl << "Mana: 5" << endl << "Zbraň: Kladivo" << endl << "Základní schopnost: Obrana" << endl << "Obraňte se před nepřítely a znižte poškození, které dostanete tohle kolo." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 3:
            system ("cls");
            cout << "Mág" << endl << "Mág využívá manu naplno pro silné útoky, není ale fyzicky silný a má málo životů.";
            cout << endl << "Životy: 6" << endl << "Útok: 4" << endl << "Mana: 20" << endl << "Zbraň: Hůl" << endl << "Základní schopnost: Ohnivá koule" << endl << "Sežehněte nepřátele silnou ohnivou koulí." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 4:
            system ("cls");
            cout << "Lupič" << endl << "Lupič je svižná postava, která dokáže okrást nepřítele i v chaosu boje.";
            cout << endl << "Životy: 8" << endl << "Útok: 3" << endl << "Mana: 10" << endl << "Zbraň: Dýka" << endl << "Základní schopnost: Krádež" << endl << "Okradněte nepřítele a získejte počet zlaťáků." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 5:
            system ("cls");
            cout << "Lovec" << endl << "Lovec je ozbrojen s kuší, schopný způsobit velké poškození s útoky, ale potřebuje přebíjet a dokáže útočit pouze po přebití kuše.";
            cout << endl << "Životy: 10" << endl << "Útok: 9" << endl << "Mana: 10" << endl << "Zbraň: Kuše" << endl << "Základní schopnost: Rychlá Palba" << endl << "Vystřelte několik šípů dávající poškození." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            case 6:
            system ("cls");
            cout << "Assassin" << endl << "Assassin se skrývá ve stínech a čeká na správnou chvíli pro způsobení devastujícího útoku.";
            cout << endl << "Životy: 8" << endl << "Útok: 6" << endl << "Mana: 10" << endl << "Zbraň: Dvojité dýky" << endl << "Základní schopnost: Neviditelnost" << endl << "Zneviditelněte se a staňte se nachvíly neschopný být poškozen nepřáteli." << endl;
            do {
            cout << "Potvrdit Výběr? (0 - Ne, 1 - Ano)" << endl;
            cin >> classconfirm;
            if (classconfirm!=0&&classconfirm!=1) {
                cout << "Neplatná Hodnota, Zadejte Hodnotu 0, nebo 1: ";
            }
            }while(classconfirm!=0&&classconfirm!=1);
            break;
            default:
            system ("cls");
            cout << "Neplatná Hodnota, Zadejte Hodnotu 1-6";
            }
}while (classvyber<1||classvyber>6||classconfirm==0);
switch(classvyber) {
    case 1: classjmeno = "Rytíř"; hracmaxhp = 10; hrachp = 10; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Meč"; spellname[0] = "Dvojitý švih"; break;
    case 2: classjmeno = "Paladin"; hracmaxhp = 20; hrachp = 20; hracatk =4; hracmaxmana = 5; hracmana = 5; hraczbran = "Kladivo"; spellname[0] = "Obrana"; break;
    case 3: classjmeno = "Mág"; hracmaxhp = 6; hrachp = 6; hracatk =4; hracmaxmana = 20; hracmana = 20; hraczbran = "Hůl"; spellname[0] = "Ohnivá koule"; break;
    case 4: classjmeno = "Lupič"; hracmaxhp = 8; hrachp = 8; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Dýka"; spellname[0] = "Krádež"; break;
    case 5: classjmeno = "Lovec"; hracmaxhp = 10; hrachp = 10; hracatk =9; hracmaxmana = 10; hracmana = 10; hraczbran = "Kuše"; spellname[0] = "Rychlá palba"; break;
    case 6: classjmeno = "Assassin"; hracmaxhp = 8; hrachp = 8; hracatk =6; hracmaxmana = 10; hracmana = 10; hraczbran = "Dvojité Dýky"; spellname[0] = "Neviditelnost"; break;
}
do {
cout << "Zadejte vaše jméno: "; cin >> jmeno;
cout << jmeno << " je to takhle správně? (0 - Ne, 1 - Ano)" << endl;
cin >> jmenoconfirm;
}while (jmenoconfirm==0);
system("cls");
do {
cout << "Chcete si vyslechnout příběh této země? (0 - Ne 1 - Ano)" << endl;
cin >> pribehskip;
}while(pribehskip!=0&&pribehskip!=1);
if (pribehskip==1) {
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Před dávnými lety bývalo všechno mírumilovné a klidné," << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "bohužel ale jednoho dne nastala katastrofa." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Obloha se rozzářila a zdevastovala horu." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Všechno poblíž hory bylo pokryto ledem a nic nezbylo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Tím ale příběh nekončí," << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Ledová kletba se začala dále šířit a monstra se začala objevovat a útočit na lidstvo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Kletba se pomalu, ale jistě blíží k dalším vesnicím a pohlcuje lidstvo." << endl;
cin >> pokracovat;
system ("cls");
cout << "(Zadejte cokoliv + enter pro pokračování)" << endl << "Kdy se objeví hrdina co kletbu ukončí?" << endl;
cin >> pokracovat;
system ("cls");
}
stagetype = stagecheck(stage);
if (stagetype==1) {
    do {
        cout << stagename[stage-1] << endl;
        cout << "Co chcete podniknout ve vesnici?" << endl << "1) Vylepšit zbroj" << endl << "2) Zakoupit lektvary" << endl << "3) Uzdravit se" << endl << "4) Naučit se nový spell" << endl << "5) Zhlédnout staty" << endl << "6) Odejít" << endl;
        cin >> input;
        switch(input) {
        case 1:
            system("cls");
            cout << "Chcete si vylepsit brnění nebo zbraň? (0 - brnění, 1 - zbraň)" << endl;
            cin >> input;
            if (input==0) {
                cout << "Chcete si vylepsit brnění za " << armorupgcost[armorlvl] << " zlatých? Životy se vám zvýší o " << armorupg[classvyber][armorlvl] << "." << endl;

            }else if (input==1) {

            }else {
            break;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            system("cls");
            cout << "Zapište cokoliv + Enter k navrácení do výběru." << endl;
            statcheck(jmeno, hracmaxhp, hrachp, hracatk, hracmaxmana, hracmana, hraczbran, spell, spellunlock, spellname, level, experience, stage, gold);
            cin >> pokracovat;
            break;
        case 6:
            break;
        default:
            system ("cls");
            cout << "Neplatná Hodnota, Zadejte Hodnotu 1-6" << endl;
        }
    }while(odejit==0);
}
return 0;
}
