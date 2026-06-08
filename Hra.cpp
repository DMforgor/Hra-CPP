#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;
string pokracovat;
string jmeno;
int input;
bool gameover;
bool win;
bool shield = false;
int glacithornbeforeshield;
bool freeze;
int slowness;
int turn;
bool fight =true;
bool loveccanatk =1;
int glacithornmaxhp = 80;
int glacithornhp;
int jmenoconfirm = 0;
int classconfirm = 0;
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
bool canguess = true;
int experience = 0;
int stage;
int vesnice;
int inventory[64];
int ItemID;
string itemname[] = {"", "Léčivý lektvar", "Lektvar many", "Smíšený lektvar", "Ultimátní Elixír"};
int monsterID;
int monsterID2;
int monsterID3;
int monster1poisoned;
int monster2poisoned;
int monster3poisoned;
string monstername[] = {"Slimák", "Troll", "Goblin", "Lupič", "Kostlivec", "Obrněný kostlivec", "Zombie", "Prokletý čaroděj", "Zmrzlý pocestný", "Zimní vlk", "Zimní tygr", "Ledový elementál", "Ledový obr", "Prokletý dobrodruh", "Zmrzlý čaroděj", "Zmrzlý kostlivec"};
int monstermaxhp[] = {6, 8, 9, 11, 10, 15, 11, 12, 12, 13, 13, 13, 25, 14, 13, 18};
int monsteratk[] = {2, 2, 3, 3, 4, 2, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6};
int monsterhp1;
int monsterhp2;
int monsterhp3;
int golddrop;
bool bossfight = 0;
bool pribehskip =0;
int miniboss;
int minibosshp;
int minibossmaxhp[] = {30, 60};
string minibossname[] = {"Zapomenutý rytíř", "Falešný hrdina"};
int armorlvl = 0;
int weaponlvl = 0;
int damagered;
int atkbuff;
int invis;
int spellmanacost[6][4] = {{4, 4, 4, 30},
                      {2, 5, 4, 15},
                      {5, 3, 4, 9},
                      {6, 8, 3, 5},
                      {5, 6, 7, 12},
                      {8, 3, 4, 15}};
int armorupg[6][3] = {{5, 8, 12},
                      {8, 12, 16},
                      {3, 6, 9},
                      {4, 7, 10},
                      {5, 7, 11},
                      {4, 6, 10}};
int armorupgcost[3] = {20, 40, 60};
int weaponupg[6][3] = {{2, 3, 1},
                      {2, 3, 4},
                      {3, 4, 4},
                      {3, 4, 4},
                      {4, 4, 4},
                      {3, 4, 4}};
int weaponupgcost[3] = {20, 40, 60};
int stagecheck (int stage) {
if (stage==1||stage==6||stage==11) {return 1;}
else if (stage==2||stage==3||stage==7)  {return 2;}
else if (stage==4||stage==8||stage==9||stage==12||stage==13)  {return 3;}
else if (stage==10)  {return 4;}
else if (stage==5||stage==14)  {return 5;}
else if (stage==15)  {return 6;}
else if (stage==16)  {return 7;}
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

void additem(int inventory[],int vel, int item) {
for (int i=0; i<vel; i++) {
    if (inventory[i]==0) {
        inventory[i] = item;
        break;
    }
}
}
void spell1(int &monsterhp, int &gold, int baseatk, int classvyber, int &mana, int manacost, string cont) {
if (classvyber==1&&mana>=manacost) {
    cout << "Dvakrát jste švihnul a dal nepřátely poškození za " << baseatk+4 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+4);
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==3&&mana>=manacost) {
    cout << "Sežehnul jste nepřátele a dal mu poškození za " << baseatk+6 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+6);
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==4&&mana>=manacost) {
    int goldgain = rand() % 10+1;
    cout << "Okradl jste nepřátele a získal " << goldgain << " zlaťáků." << endl;
    gold = gold+goldgain;
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==5&&mana>=manacost) {
    cout << "Střelil jste několik šipů a dal poškození za " << baseatk-2 << " hp." << endl;
    monsterhp = monsterhp - (baseatk-2);
    mana = mana-manacost;
    cin >> cont;
}else if (mana<manacost) {
cout << "Nedostatek many" << endl;
}
}
void spell2(int &monsterhp, int gold, int baseatk, int classvyber, int &mana, int manacost, string cont, int &invis, int &hrachp, int hracmaxhp, bool &loveccanatk) {
if (classvyber==2&&mana>=manacost) {
    cout << "Švihnul jste po nepřátely kladivem a dal poškození " << baseatk << " hp a získal jste zpátky "<< hracmaxhp/10 << " hp." << endl;
    monsterhp = monsterhp - baseatk;
    hrachp = hrachp+hracmaxhp/10;
    if (hrachp>hracmaxhp) {
        hrachp = hracmaxhp;
    }
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==3&&mana>=manacost) {
    cout << "Střelil jste blesk po nepřítely a dal poškození " << baseatk+4 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+4);
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==4&&mana>=manacost) {
    cout << "Seknul jste nepřitele svou dýkou za " << baseatk-4+(gold/15) << " hp." << endl;
    monsterhp = monsterhp - (baseatk-4+(gold/15));
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==5&&mana>=manacost) {
    cout << "Střelil jste šíp po nepřítely a dal poškození " << baseatk-3 << " hp, přebil jste si také kuš." << endl;
    monsterhp = monsterhp - (baseatk-3);
    loveccanatk=1;
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==6&&mana>=manacost) {
    if (invis==0){
    cout << "Zaútočil jste na nepřítele a dal poškození za " << baseatk+6 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+3);
    mana = mana-manacost;
    cin >> cont;
    }else if(invis>0) {
cout << "Zaútočil jste na nepřítele ze stínů a dal poškození za " << baseatk+invis*8 << " hp, neviditelnost vyprchala." << endl;
    monsterhp = monsterhp - (baseatk+invis*8);
    invis = 0;
    mana = mana-manacost;
    cin >> cont;}
}else if (mana<manacost) {
cout << "Nedostatek many" << endl;
}
}
void spell3(int &monsterhp,int baseatk,int classvyber, int &mana, int manacost, string cont, int &atkbuff, int &hp, int maxhp) {
if (classvyber==1&&mana>=manacost) {
    cout << "Švihnuli jste mečem po nepřítely za " << baseatk << "hp a zesílil jste svoje útoky." << endl;
    monsterhp = monsterhp - baseatk;
    atkbuff = 3;
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==2&&mana>=manacost) {
    cout << "Uzdravili jste se za " << maxhp/4 << " hp." << endl;
    hp = hp+maxhp/4;
    if (hp>maxhp) {
        hp = maxhp;
    }
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==3&&mana>=manacost) {
    cout << "Zesílili jste své útoky pomocí kouzla." << endl;
    atkbuff = 4;
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==4&&mana>=manacost) {
    cout << "Hodili jste dýku po nepřítely a dal poškození za " << baseatk+3 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+3);
    mana = mana-manacost;
    cin >> cont;
}else if (classvyber==5&&mana>=manacost) {
    cout << "Spustili jste na nepřitele déšť šípů za " << baseatk+1 << " hp." << endl;
    monsterhp = monsterhp - (baseatk+1);
    mana = mana-manacost;
    cin >> cont;
}else if (mana<manacost) {
cout << "Nedostatek many" << endl;
}
}
void spell4(int &monsterhp, int &gold, int baseatk, int classvyber, int &mana, int manacost, string cont, int &atkbuff, int &hp, int maxhp, int enemypoisoned, int &invis) {

    if (mana < manacost) {
        cout << "Nedostatek many" << endl;
        cin >> cont;
        return;
    }

    mana = mana - manacost;

    if (classvyber == 1) {
        cout << "Zasáhli jste nepřítele silným paprskem světla a dali poškození za " << baseatk * 3 << "hp." << endl;
        monsterhp = monsterhp - (baseatk * 3);
    }
    else if (classvyber == 2) {
        cout << "Zasáhli jste nepřítele kladivem za " << baseatk + (maxhp / 10) << "hp." << endl;
        monsterhp = monsterhp - (baseatk + (maxhp / 10));
    }
    else if (classvyber == 3) {
        cout << "Seslali jste na nepřítele meteor za " << baseatk * 2 + 5 << "hp." << endl;
        monsterhp = monsterhp - (baseatk * 2 + 5);
    }
    else if (classvyber == 4) {
        cout << "Střelili jste nepřítele svou bambitkou probitou zlaťáky za " << baseatk + (gold / 2) << " hp." << endl;
        monsterhp = monsterhp - (baseatk + (gold / 2));
        gold = gold / 2;
    }
    else if (classvyber == 5) {
        cout << "Střelili jste nepřítele silným šípem za " << baseatk + 6 << " hp." << endl;
        monsterhp = monsterhp - (baseatk + 6);
    }
    else if (classvyber == 6) {
        if (invis > 0 && enemypoisoned > 0) {
            cout << "Zasáhli jste nepřítele svýma dýkama za " << baseatk * 2 + 10 << " hp." << endl;
            monsterhp = monsterhp - (baseatk * 2 + 10);
        } else if (invis > 0 || enemypoisoned > 0) {
            cout << "Zasáhli jste nepřítele svýma dýkama za " << baseatk * 2 + 5 << " hp." << endl;
            monsterhp = monsterhp - (baseatk * 2 + 5);
        } else {
            cout << "Zasáhli jste nepřítele svýma dýkama za " << baseatk * 2 << " hp." << endl;
            monsterhp = monsterhp - (baseatk * 2);
        }
    }

    cin >> cont;
}
void minibossdialogue(int miniboss, int turn, string minibossname) {
    if (miniboss==1) {
        switch(turn) {
        case 1:
        cout << minibossname << ": ...." << endl;
        break;
        case 3:
        cout << minibossname << ": Neprojdeš." << endl;
        break;
        case 5:
        cout << minibossname << ": Proč se furt snažíš?" << endl;
        break;
        default:
        break;
        }
    }else if (miniboss==2) {
        switch(turn) {
        case 1:
        cout << minibossname << ": Copak tu tady ale máme?" << endl;
        break;
        case 2:
        cout << minibossname << ": To já zaženu tuhle kledbu, a ty mě nezastavíš!" << endl;
        break;
        case 4:
        cout << minibossname << ": Je čas se začít snažit." << endl;
        break;
        case 6:
        cout << minibossname << ": Vypadá to, že i s Frostpiercerem mi budeš dávat potíže!" << endl;
        break;
        default:
        break;
        }
    }
}
void minibossatk (int miniboss, int turn, int classvyber, string minibossname, int hracmaxhp, int &hrachp, int damagered, int invis) {
    if (miniboss==1) {
        if (turn%2 == 1) {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << minibossname << " švihá svým mečem a dáva poškození za " << 4 << " životy." << endl;
                    hrachp = hrachp - 4;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((4 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " švihá svým mečem a dáva poškození za " << 4 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (4 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((4 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " švihá svým mečem a dáva poškození za " << 4 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (4 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku jste se vyhli." << endl;
                cin >> pokracovat;
            }
            }else if (turn%2 == 0) {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << minibossname << " Nabíhá na vás s mečem a dává poškození za " << 6 << " životů." << endl;
                    hrachp = hrachp - 6;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((6 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " Nabíhá na vás s mečem a dává poškození za " << 6 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (6 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((6 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " Nabíhá na vás s mečem a dává poškození za " << 6 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (6 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku jste se vyhli." << endl;
                cin >> pokracovat;
            }
            }
}else if (miniboss==2) {
        if (turn%4 == 0) {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << minibossname << " vás silně bodne Frostpiercerem za " << 10 << " životů." << endl;
                    hrachp = hrachp - 10;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((10 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " vás silně bodne Frostpiercerem za  " << 10 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (10 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((10 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " vás silně bodne Frostpiercerem za  " << 10 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (10 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku jste se vyhli." << endl;
                cin >> pokracovat;
            }
            }else if (turn%3 == 0) {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << minibossname << " vás silně kopnul za " << 6 << " životů." << endl;
                    hrachp = hrachp - 6;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((6 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " vás silně kopnul " << 6 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (6 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((6 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " vás silně kopnul " << 6 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (6 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku jste se vyhli." << endl;
                cin >> pokracovat;
            }
            }else  {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << minibossname << " na vás s malou snahou švihl Frostpiercerem za " << 4 << " životů." << endl;
                    hrachp = hrachp - 4;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((4 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " na vás s malou snahou švihl Frostpiercerem za "  << 4 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (4 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((4 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokoval." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << minibossname << " na vás s malou snahou švihl Frostpiercerem za " << 4 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (4 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku jste se vyhli." << endl;
                cin >> pokracovat;
            }
            }
}
}
bool odejit = 0;
bool canupgarmor =1;
bool canupgweapon =1;
string stagename[] = {"Začátečnická vesnice", "Pláně", "Začátek lesa", "Hluboko v lese", "Most do zapomenuté vesnice", "Zapomenutá vesnice", "Vstup do jeskyně", "Začátek jeskyně", "Hluboko v jeskyni", "Okolí vesnice","Vesnice v jeskyni", "Výstup na horu", "Ledová jeskyně", "Hluboko v ledové jeskyni ", "Lektvarový obchod", "Jádro kletby"};
int main(){
    system("color 79");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));
    int stagetype;
    int stage = 1;
    cout << "RPG HRA - HLAVNI MENU" << endl << "Zapište cokoliv a stistkněte Enter pro zahájení hry.";
    cin >> pokracovat;
    system ("cls");
    do {
    cout << "Vyberte si Classu" << endl << "1) Rytíř" << endl << "2) Paladin" << endl << "3) Mág" << endl << "4) Lupič" << endl << "5) Lovec" << endl << "6) Assassin" << endl;
    cin >> classvyber;
    switch(classvyber) {
        case 1:
            system ("cls");
            cout << "Rytir" << endl << "Rytíř je všestranná postava, která v ničem neexceluje, ale ani nepostrádá";
            cout << endl << "Životy: 15" << endl << "Útok: 3" << endl << "Mana: 10" << endl << "Zbraň: Meč" << endl << "Základni schopnost: Dvojitý švih" << endl << "Švihněte dvakrát po nepřítely s mečem pro větší poškození." << endl;
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
            cout << endl << "Životy: 25" << endl << "Útok: 4" << endl << "Mana: 5" << endl << "Zbraň: Kladivo" << endl << "Základní schopnost: Obrana" << endl << "Obraňte se před nepřítely a znižte poškození, které dostanete tohle kolo." << endl;
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
            cout << endl << "Životy: 11" << endl << "Útok: 4" << endl << "Mana: 20" << endl << "Zbraň: Hůl" << endl << "Základní schopnost: Ohnivá koule" << endl << "Sežehněte nepřátele silnou ohnivou koulí." << endl;
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
            cout << endl << "Životy: 13" << endl << "Útok: 3" << endl << "Mana: 10" << endl << "Zbraň: Dýka" << endl << "Základní schopnost: Krádež" << endl << "Okradněte nepřítele a získejte počet zlaťáků." << endl;
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
            cout << endl << "Životy: 15" << endl << "Útok: 9" << endl << "Mana: 10" << endl << "Zbraň: Kuše" << endl << "Základní schopnost: Rychlá Palba" << endl << "Vystřelte několik šípů dávající poškození." << endl;
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
            cout << endl << "Životy: 13" << endl << "Útok: 6" << endl << "Mana: 10" << endl << "Zbraň: Dvojité dýky" << endl << "Základní schopnost: Neviditelnost" << endl << "Zneviditelněte se a staňte se nachvíly neschopný být poškozen nepřáteli." << endl;
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
    case 1: classjmeno = "Rytíř"; hracmaxhp = 15; hrachp = 15; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Meč"; spellname[0] = "Dvojitý švih"; break;
    case 2: classjmeno = "Paladin"; hracmaxhp = 25; hrachp = 25; hracatk =4; hracmaxmana = 5; hracmana = 5; hraczbran = "Kladivo"; spellname[0] = "Obrana"; break;
    case 3: classjmeno = "Mág"; hracmaxhp = 11; hrachp = 11; hracatk =4; hracmaxmana = 20; hracmana = 20; hraczbran = "Hůl"; spellname[0] = "Ohnivá koule"; break;
    case 4: classjmeno = "Lupič"; hracmaxhp = 13; hrachp = 13; hracatk =3; hracmaxmana = 10; hracmana = 10; hraczbran = "Dýka"; spellname[0] = "Krádež"; break;
    case 5: classjmeno = "Lovec"; hracmaxhp = 15; hrachp = 15; hracatk =9; hracmaxmana = 10; hracmana = 10; hraczbran = "Kuše"; spellname[0] = "Rychlá palba"; break;
    case 6: classjmeno = "Assassin"; hracmaxhp = 13; hrachp = 13; hracatk =6; hracmaxmana = 10; hracmana = 10; hraczbran = "Dvojité Dýky"; spellname[0] = "Neviditelnost"; break;
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
do {
if (hrachp==0) {
    gameover==true;
    break;
}
stagetype = stagecheck(stage);
if (stagetype==1) {
        vesnice++;
        odejit=0;
    do {
        cout << stagename[stage-1] << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Co chcete podniknout ve vesnici?" << endl << "1) Vylepšit zbroj" << endl << "2) Zakoupit lektvary" << endl << "3) Uzdravit se" << endl << "4) Naučit se nový spell" << endl << "5) Zhlédnout staty" << endl << "6) Odejít" << endl;
        cin >> input;
        switch(input) {
        case 1:
            system("cls");
            cout << "Chcete si vylepsit brnění nebo zbraň? (0 - brnění, 1 - zbraň)" << endl;
            cin >> input;
            if (input==0&&canupgarmor==1) {
                do {
                cout << "Chcete si vylepsit brnění za " << armorupgcost[armorlvl] << " zlatých? Životy se vám zvýší o " << armorupg[classvyber-1][armorlvl] << ". (0 - Ne, 1 - Ano)" << endl;
                cin >> input;
                if (input!=0&&input!=1) {
                    cout << "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                }else if(input==1) {
                if(gold>=armorupgcost[armorlvl])
                    gold = gold-armorupgcost[armorlvl];
                    hracmaxhp = hracmaxhp+armorupg[classvyber-1][armorlvl];
                    hrachp = hrachp+armorupg[classvyber-1][armorlvl];
                    canupgarmor = 0;
                    cout << "Životy se vám zvýšili o " << armorupg[classvyber-1][armorlvl] << " teď máte " << gold << " zlaťáků." << endl;
                    armorlvl++;
                }else if(gold<armorupgcost[armorlvl]) {
                    cout << "Nemáte dostatek zlaťáků, chybí vám " << armorupgcost[armorlvl]-gold << " zlaťáků." << endl;
                }
                }while(input!=0&&input!=1);
                }else if(input==0&&canupgarmor==0) {
                    cout << "Brnění je zde už vyprodáno." << endl;
            }else if (input==1&&canupgweapon==1) {
             do {
                cout << "Chcete si vylepsit zbraň za " << weaponupgcost[weaponlvl] << " zlatých? Útok se vám zvýší o " << weaponupg[classvyber-1][weaponlvl] << ". (0 - Ne, 1 - Ano)" << endl;
                cin >> input;
                if (input!=0&&input!=1) {
                    cout << "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                }else if(input==1) {
                if(gold>=weaponupgcost[weaponlvl])
                    gold = gold-weaponupgcost[weaponlvl];
                    hracatk = hracatk+weaponupg[classvyber-1][weaponlvl];
                    canupgweapon = 0;
                    cout << "Útok se vám zvýšil o " << weaponupg[classvyber-1][weaponlvl] << " teď máte " << gold << " zlaťáků." << endl;
                    weaponlvl++;
                }else if(gold<weaponupgcost[weaponlvl]) {
                    cout << "Nemáte dostatek zlaťáků, chybí vám " << weaponupgcost[weaponlvl]-gold << " zlaťáků." << endl;
                }
                }while(input!=0&&input!=1);
                }else if(input==1&&canupgweapon==0) {
                cout << "Zbraň je zde už vyprodána." << endl;
            }else {
            break;
            }
            break;
        case 2:
            system("cls");
            cout << "Jaké chcete zakoupit lektvary? (0 - Léčivý lektvar, 1 - Lektvar many, 2 - Smíšený lektvar)" << endl;
            cin >> input;
            if (input==0) {
                    cout << "Chcete zakoupit léčivý lektvar za " << vesnice*10 << " zlaťáků? (Obnoví 40% životů (zaokrouhleno nahorů) (0 . Ne, 1 - Ano)" << endl;;
                    do {
                        cin >> input;
                        if (input!=0&&input!=1) {
                            cout<< "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                        }else if(input==1&&gold>=vesnice*10) {
                        gold = gold-vesnice*10;
                        additem(inventory,64,1);
                        cout << "Zakoupili jste léčivý lektvar za" << vesnice*10 << " zlaťáků. Teď máte " << gold << " Zlaťáků." << endl;
                        }else if(input==1&&gold<vesnice*10) {
                        cout << "Nemáte dostatek zlaťáků, chybí vám " << vesnice*10-gold << " zlaťáků." << endl;
                        }
                    }while(input!=0&&input!=1);
            }else if(input==1){
                cout << "Chcete zakoupit lektvar many za " << vesnice*10 << " zlaťáků? (Obnoví 60% many (zaokrouhleno nahorů) (0 . Ne, 1 - Ano)" << endl;;
                                do {
                        cin >> input;
                        if (input!=0&&input!=1) {
                            cout<< "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                        }else if(input==1&&gold>=vesnice*10) {
                        gold = gold-vesnice*10;
                        additem(inventory,64,2);
                        cout << "Zakoupili jste lektvar many za" << vesnice*10 << " zlaťáků. Teď máte " << gold << " Zlaťáků." << endl;
                        }else if(input==1&&gold<vesnice*10) {
                        cout << "Nemáte dostatek zlaťáků, chybí vám " << vesnice*10-gold << " zlaťáků." << endl;
                        }
                    }while(input!=0&&input!=1);
            }else if(input==2){
                cout << "Chcete zakoupit smíšený lektvar za " << vesnice*10 << " zlaťáků? (Obnoví 30% životů a 40% many (zaokrouhleno nahorů) (0 . Ne, 1 - Ano)" << endl;
                                do {
                        cin >> input;
                        if (input!=0&&input!=1) {
                            cout<< "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                        }else if(input==1&&gold>=vesnice*10) {
                        gold = gold-vesnice*10;
                        additem(inventory,64,3);
                        cout << "Zakoupili jste lektvar many za" << vesnice*10 << " zlaťáků. Teď máte " << gold << " Zlaťáků." << endl;
                        }else if(input==1&&gold<vesnice*10) {
                        cout << "Nemáte dostatek zlaťáků, chybí vám " << vesnice*10-gold << " zlaťáků." << endl;
                        }
                    }while(input!=0&&input!=1);
            }else {
            break;
            }
            break;
        case 3:
            system("cls");
            cout << "Chcete se uzdravit za " << vesnice*8 << " zlaťáků? (Obnoví všechny životy a manu) (0 - Ne, 1 - Ano)" << endl;
            cin >> input;
            if(input==1&&gold>=vesnice*8&&(hrachp!=hracmaxhp||hracmana!=hracmaxmana)) {
                hrachp=hracmaxhp;
                hracmana = hracmaxmana;
                cout << "Byli jste uzdraveni a vaše životy a mana byly obnoveny. Teď máte " << gold << endl << " zlaťáků." << endl;
            }else if(input==1&&hrachp==hracmaxhp&&hracmana==hracmaxmana) {
                cout << "Životy i manu už máte plné." << endl;
            }else if(input==1&&gold<vesnice*8){
                cout << "Nemáte dostatek zlaťáků, chybí vám " << vesnice*8-gold << " zlaťáků." << endl;
            }else {
                break;
            }
            break;
        case 4:
            system("cls");
            cout << "Chcete se naučit nový spell za " << vesnice*15 << " zlaťáků? (0 - Ne, 1 - Ano)" << endl;
            cin >> input;
            if (input==1&&gold>=vesnice*15&&spellunlock[vesnice-1]==false) {
            if(vesnice==1){
                switch(classvyber) {
            case 1:
                cout << "Rytířská obrana - švihněte mečem na nepřítele a zmenčete poškození na další kola." << endl;
                spellunlock[0]=true;
                spellname[1] = "Rytířská obrana";
                gold = gold-15;
                break;
            case 2:
                cout << "Svaté kladivo - uhoďte nepřítele a získejte zpátky pár životů." << endl;
                spellunlock[0]=true;
                spellname[1] = "Svaté kladivo";
                gold = gold-15;
                break;
            case 3:
                cout << "Bleskové zaklínadlo - sežehněte nepřitele bleskem." << endl;
                spellunlock[0]=true;
                spellname[1] = "Bleskové zaklínadlo";
                gold = gold-15;
                break;
            case 4:
                cout << "Zlatá dýka - rízněte nepřítele s útokem, který dává poškození podle počtu zlaťáků." << endl;
                spellunlock[0]=true;
                spellname[1] = "Zlatá dýka";
                gold = gold-15;
                break;
            case 5:
                cout << "Přebíjecí střela - střelte po nepřítely a nabíjte normální útok." << endl;
                spellunlock[0]=true;
                spellname[1] = "Přebíjecí střela";
                gold = gold-15;
                break;
            case 6:
                cout << "Útok ze stínů - zaútočte na nepřítele, davá větší poškození pokud jste neviditelní ale zruší jí." << endl;
                spellunlock[0]=true;
                spellname[1] = "Útok ze stínů";
                break;
                }}
            if(vesnice==2){
                switch(classvyber) {
            case 1:
                cout << "Posílení - švihněte na nepřátele a zvyšte svůj útok." << endl;
                spellunlock[1]=true;
                spellname[2] = "Posílení";
                gold = gold-30;
                break;
            case 2:
                cout << "Oživení - získejte zpátky nějaké životy." << endl;
                spellunlock[1]=true;
                spellname[2] = "Oživení";
                gold = gold-30;
                break;
            case 3:
                cout << "Magické posílení - zvyšte svůj útok." << endl;
                spellunlock[1]=true;
                spellname[2] = "Magické posílení";
                gold = gold-30;
                break;
            case 4:
                cout << "Hod dýkou - hoďte svou dýku po nepřátely." << endl;
                spellunlock[1]=true;
                spellname[2] = "Hod dýkou";
                gold = gold-30;
                break;
            case 5:
                cout << "Déšť šipů - vystřelte několik šipů do oblak, které poškodí nepřítele, jakmile spadnou." << endl;
                spellunlock[1]=true;
                spellname[2] = "Déšť šípů";
                gold = gold-30;
                break;
            case 6:
                cout << "Otrávení - otravte nepřítele." << endl;
                spellunlock[1]=true;
                spellname[2] = "Otrávení";
                gold = gold-30;
                break;
                }}
            if(vesnice==3){
                switch(classvyber) {
            case 1:
                cout << "Svatý meč - Zasáhněte nepřátele silným paprskem světla." << endl;
                spellunlock[2]=true;
                spellname[3] = "Svatý meč";
                gold = gold-45;
                break;
            case 2:
                cout << "Kladivo života - Zasáhněte nepřátele kladivem, poškození roste s životama." << endl;
                spellunlock[2]=true;
                spellname[3] = "Kladivo života";
                gold = gold-45;
                break;
            case 3:
                cout << "Meteorové zasáhnutí - Zasáhněte nepřátele silným meteorem." << endl;
                spellunlock[2]=true;
                spellname[3] = "Meteorové zasáhnutí";
                gold = gold-45;
                break;
            case 4:
                cout << "Zlatá střela - Sestřelte nepřátele se svou bambitkou, dává velké poškození, které se zvětšuje se zlaťáky, ale sebere polovinu vlastněných zlaťáků." << endl;
                spellunlock[2]=true;
                spellname[3] = "Zlatá střela";
                gold = gold-45;
                break;
            case 5:
                cout << "Průrazný šíp - Střelte po nepřátely šíp, který dává velké poškození." << endl;
                spellunlock[2]=true;
                spellname[3] = "Průrazný šíp";
                gold = gold-45;
                break;
            case 6:
                cout << "Rudá čepel - Přesekněte nepřátele a dejte velké poškození, dává větší poškození v neviditelnosti a otráveným nepřátelům." << endl;;
                spellunlock[2]=true;
                spellname[3] = "Rudá čepel";
                gold = gold-45;
                break;
                }}
            }else if(input==1&&spellunlock[vesnice-1]==true){
                cout << "Tady jste se spell už naučili." << endl;
            }else if(input==1&&gold<vesnice*15){
                cout << "Nemáte dost zlaťáků, chybí vám " << vesnice*15-gold << " zlaťáků." << endl;
            }else {
            break;
            }
            break;
        case 5:
            system("cls");
            cout << "Zapište cokoliv + Enter k navrácení do výběru." << endl;
            statcheck(jmeno, hracmaxhp, hrachp, hracatk, hracmaxmana, hracmana, hraczbran, spell, spellunlock, spellname, level, experience, stage, gold);
            cin >> pokracovat;
            break;
        case 6:
            cout << "Chcete opustit vesnici? (0 - Ne, 1 - Ano)" << endl;
            cin >> input;
            if (input==1) {
                odejit = 1;
            }
            break;
        default:
            system ("cls");
            cout << "Neplatná Hodnota, Zadejte Hodnotu 1-6" << endl;
        }
    }while(odejit==0);
}
if (stagetype==2) {
    fight=true;
    system("cls");
    monsterID = rand() % stage;
    monsterhp1 = monstermaxhp[monsterID];
    while(fight==true) {
        system("cls");
        cout << stagename[stage-1] << endl;
        cout << "-------------------------------------------------" << endl << endl;
        cout << monstername[monsterID] << endl;
        cout << "Životy: " << monsterhp1 << "/" <<monstermaxhp[monsterID] << endl << endl;
        if (monster1poisoned>0) {
            cout << "Otrávený" << endl << endl;
        }
        cout << "-------------------------------------------------" << endl;
        cout << "Životy: " << hrachp << "/" << hracmaxhp << endl;
        cout << "Mana: " << hracmana << "/" << hracmaxmana << endl << endl;
        if (damagered>0) {
            cout << "Obrana: " << damagered << " tahy." << endl;
        }
        if (invis>0) {
            cout << "Neviditelnost: " << invis << " tahy." << endl;
        }
        do {
        if (monsterhp1<=0||hrachp==0) {
            break;
        }
        cout << "1) Útok" << endl << "2) Použít lektvary" << endl << "3) Spelly" << endl;
        cin >> input;
        switch(input) {
        case 1:
            if (classvyber!=5) {
                if (classvyber==1&&atkbuff>0) {
                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                monsterhp1=monsterhp1-(hracatk+2);
                cin >> pokracovat;
                }else if (classvyber==3&&atkbuff>0) {
                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                monsterhp1=monsterhp1-(hracatk+4);
                cin >> pokracovat;
                }else{
                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                monsterhp1=monsterhp1-hracatk;
                cin >> pokracovat;}
            }else if(classvyber==5) {
                if (loveccanatk==1) {
                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                monsterhp1=monsterhp1-hracatk;
                loveccanatk = 0;
                cin >> pokracovat;
                }else if(loveccanatk==0) {
                cout << "Přebili jste kuš." << endl;
                loveccanatk = 1;
                cin >> pokracovat;
                }

            }
            break;
        case 2:
            for (int i=0; i<=64; i++) {
                if (inventory[i]!= 0) {
                    cout << i+1 << ") " << itemname[inventory[i]] << endl;
                }
            }
            cin >> input;
            if (inventory[input-1]==1) {
                cout << "Použily jste Léčivý lektvar a uzdravili jste se." << endl;
                hrachp=hrachp+((hracmaxhp/10)*4);
                if (hrachp>hracmaxhp) {
                    hrachp = hracmaxhp;
                }
            (inventory[input-1]=0);
            cin >> pokracovat;
            }
            else if (inventory[input-1]==2) {
                cout << "Použili jste Lektvar many a obnovili jste manu." << endl;
                hracmana=hracmana+((hracmaxmana/10)*6);
                if (hracmana>hracmaxmana) {
                    hracmana = hracmaxmana;
                }
            (inventory[input-1]=0);
            }
            else if (inventory[input-1]==3) {
                cout << "Použili jste smíšený lektvar a obnovili jste manu a životy." << endl;
                hrachp=hrachp+((hracmaxhp/10)*3);
                if (hrachp>hracmaxhp) {
                    hrachp = hracmaxhp;
                }
                hracmana=hracmana+((hracmaxmana/10)*4);
                if (hracmana>hracmaxmana) {
                    hracmana = hracmaxmana;
                }
            (inventory[input-1]=0);
            cin >> pokracovat;
            }
            else if (inventory[input-1]==4) {
                cout << "Použili jste záhadný lektvar, vaše životy i mana byly plně obnoveny." << endl;
                hrachp=hracmaxhp;
                hracmana=hracmaxmana;
            (inventory[input-1]=0);
            cin >> pokracovat;
            }
            else if (inventory[input-1]==0||(inventory[input]!=1&&inventory[input]!=2&&inventory[input]!=3&&inventory[input]!=4)) {
            cout << "Šáhli jste to prázdné kapsy a nic nenašly, vskutku dobré využití vašeho tahu." << endl;
            cin >> pokracovat;
            }
            break;
        case 3:  do{
            cout << "Jaký spell chcete použít?" << endl;
            cout << "1) " << spellname[0] << " Spotřeba many: " << spellmanacost[classvyber][0] << endl;
            for (int i = 1; i<4; i++) {
                if (spellunlock[i-1] == true) {
                    cout << i+1 << ") " << spellname[i] << " Spotřeba many: " << spellmanacost[classvyber][i] << endl;
                }
            }
            cin >> input;
            if (input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false))) {
                cout << "Neplatná hodnota" << endl;
            }else if(input == 1&&!(classvyber == 2||classvyber == 6)) {
            spell1(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
            }else if(input==1&&classvyber==2&&hracmana>=spellmanacost[classvyber][0]) {
            damagered = 3;
            cout << "Obránili jste se a teď dostáváte menší damage na 3 kola." << endl;
            hracmana = hracmana - spellmanacost[classvyber][0];
            cin >> pokracovat;
            }else if(input==1&&classvyber==2&&hracmana<spellmanacost[classvyber][0]) {
                     cout << "Nedostatek many." << endl;
                     cin >> pokracovat;
            }else if(input==1&&classvyber==6&&hracmana>=spellmanacost[classvyber][0]) {
            invis = 3;
            cout << "Znevidili jste se na 3 kola." << endl;
            hracmana = hracmana - spellmanacost[classvyber][0];
            cin >> pokracovat;
            }else if(input==1&&classvyber==6&&hracmana<spellmanacost[classvyber][0]){
                    cout << "Nedostatek many." << endl;
                     cin >> pokracovat;
            }else if (input==2&&spellunlock[0]==true&&classvyber!=1) {
            spell2(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
            }else if (input==2&&spellunlock[0]==true&&classvyber==1) {
            cout << "Obránil jste se a švihnul po nepřátely za " << hracatk << " hp." << endl;
            monsterhp1 = monsterhp1 - hracatk;
            damagered = 3;
            }else if(input==3&&spellunlock[1]==true&&classvyber!=6) {
             spell3(monsterhp1,hracatk,classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
            }else if(input==3&&spellunlock[1]==true&&classvyber==6) {
            cout << "Zasáhl jste nepřatele dýkou za " << hracatk << " hp a otrávil je." << endl;
            monsterhp1 = monsterhp1 - hracatk;
            monster1poisoned = 3;
            }else if(input==4&&spellunlock[2]==true) {
            spell4(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster1poisoned, invis);
            }
            }while(input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false)));
            break;
        default:
            cout << "Neplatná hodnota, zadejte hodnotu (1-4)" << endl;
            break;

        }
        }while(input<1||input>4);
    if (monsterhp1>0) {
        if (invis==0) {
        if (damagered==0) {
        cout << monstername[monsterID] << " útočí a dává vám poškození za " << monsteratk[monsterID] << " životů." << endl;
        hrachp = hrachp-monsteratk[monsterID];
        cin >> pokracovat;
        }else if(damagered>0) {
        if (classvyber==1) {
        if (monsteratk[monsterID]-hracmaxhp/10<0) {
            cout << "Útok od monstra jste zablokoval." << endl;
            cin >> pokracovat;
        }else{
        cout << monstername[monsterID] << " útočí a dává vám poškození za " << monsteratk[monsterID]-(hracmaxhp/10) << " životů." << endl;
        hrachp = hrachp-(monsteratk[monsterID]-(hracmaxhp/10));
        cin >> pokracovat;
        }
        }else   if (classvyber==2) {
        if (monsteratk[monsterID]-hracmaxhp/6<0) {
            cout << "Útok od monstra jste zablokoval." << endl;
            cin >> pokracovat;
        }else{
        cout << monstername[monsterID] << " útočí a dává vám poškození za " << monsteratk[monsterID]-(hracmaxhp/6) << " životů." << endl;
        hrachp = hrachp-(monsteratk[monsterID]-(hracmaxhp/6));
        cin >> pokracovat;
        }
        }
        }
    }else if(invis>0) {
        cout << "Jste neviditelní a útoku jste se vyhli." << endl;
        cin >> pokracovat;
    }
    if (monster1poisoned>0) {
        monsterhp1 = monsterhp1-(monstermaxhp[monsterID]/10);
        cout << "Nepřítel je otrávený a doskal poškození za " << (monstermaxhp[monsterID]/10) << " hp." << endl;
    }
    }
    if (monsterhp1<=0) {
        loveccanatk =1;
        fight=false;
        cout<< "Vítezství! Získali jste " << stage*3 << " EXP!" << endl;
        hrachp = hrachp+2;
        if (hrachp>hracmaxhp) {
            hrachp = hracmaxhp;
        }
        hracmana=hracmana+4;
        if (hracmana>hracmaxmana) {
        hracmana = hracmaxmana;
        }
        experience = experience+stage*3;
        if (experience>=100) {
            cout << "Level up! Životy se vám zvýšili o 2, mana se vám zvýšila o 4, útok se vám zvýšil o 1!" << endl;
            hracmaxhp = hracmaxhp+2;
            hrachp = hrachp+2;
            hracmaxmana = hracmaxmana+4;
            hracmana = hracmana+4;
            hracatk = hracatk+1;
            experience = experience-100;
        }
        golddrop = rand() % 2;
        if (golddrop == 1) {
            gold = gold+stage*8;
            cout << "Získali jste " << stage*8 << " zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
        }
    cin >> pokracovat;
    }
    if (hrachp<=0) {
        fight = false;
        gameover = true;
        continue;
    }
    if (damagered>0) {
        damagered--;
    }
    if (invis>0) {
        invis--;
    }
    if (atkbuff > 0) {
            atkbuff--;
    }
    hracmana++;
    if (hracmana>hracmaxmana) {
        hracmana=hracmaxmana;
    }
    }
}
if (stagetype == 3) {
    fight = true;
    system("cls");
    monsterID = rand() % stage;
    monsterhp1 = monstermaxhp[monsterID];
    monster1poisoned = 0;
    monsterID2 = rand() % stage;
    monsterhp2 = monstermaxhp[monsterID2];
    monster2poisoned = 0;
    while (fight == true) {
        system("cls");
        cout << stagename[stage - 1] << endl;
        cout << "-------------------------------------------------" << endl << endl;
        if (monsterhp1 > 0) {
            cout << "1) " << monstername[monsterID] << endl;
            cout << "Životy: " << monsterhp1 << "/" << monstermaxhp[monsterID] << endl;
            if (monster1poisoned > 0) cout << "Otrávený (" << monster1poisoned << " tahy)" << endl;
        } else {
            cout << "1) " << monstername[monsterID] << " [MRTVÝ]" << endl;
        }
        cout << endl;
        if (monsterhp2 > 0) {
            cout << "2) " << monstername[monsterID2] << endl;
            cout << "Životy: " << monsterhp2 << "/" << monstermaxhp[monsterID2] << endl;
            if (monster2poisoned > 0) cout << "Otrávený (" << monster2poisoned << " tahy)" << endl;
        } else {
            cout << "2) " << monstername[monsterID2] << " [MRTVÝ]" << endl;
        }

        cout << "-------------------------------------------------" << endl;
        cout << "Životy: " << hrachp << "/" << hracmaxhp << endl;
        cout << "Mana: " << hracmana << "/" << hracmaxmana << endl << endl;

        if (damagered > 0) cout << "Obrana: " << damagered << " tahy." << endl;
        if (invis > 0) cout << "Neviditelnost: " << invis << " tahy." << endl;

        do {
            if ((monsterhp1 <= 0 && monsterhp2 <= 0) || hrachp <= 0) {
                break;
            }

            cout << "1) Útok" << endl << "2) Použít lektvary" << endl << "3) Spelly" << endl;
            cin >> input;

            switch (input) {
            case 1: {
                int cil = 1;
                if (monsterhp1 > 0 && monsterhp2 > 0) {
                    do {
                        cout << "Na které monstrum chceš zaútočit? (1 nebo 2): ";
                        cin >> cil;
                    if (cil!=1&&cil!=2) {
                        cout << "Neplatná hodnota" << endl;
                    }
                    } while (cil != 1 && cil != 2);
                } else {
                    cil = (monsterhp1 > 0) ? 1 : 2;
                }
                if (classvyber != 5) {
                    if (classvyber==1&&atkbuff>0) {
                    cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk+2 << endl;
                    if (cil == 1) monsterhp1 = monsterhp1 - (hracatk+2);
                    else monsterhp2 = monsterhp2 - (hracatk+2);
                    cin >> pokracovat;
                    }else if (classvyber==3&&atkbuff>0) {
                    cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk+4 << endl;
                    if (cil == 1) monsterhp1 = monsterhp1 - (hracatk+4);
                    else monsterhp2 = monsterhp2 - (hracatk+4);
                    cin >> pokracovat;
                    }else if(atkbuff== 0) {
                    cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                    if (cil == 1) monsterhp1 = monsterhp1 - hracatk;
                    else monsterhp2 = monsterhp2 - hracatk;
                    cin >> pokracovat;
                    }
                } else if (classvyber == 5) {
                    if (loveccanatk == 1) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                        if (cil == 1) monsterhp1 -= hracatk;
                        else monsterhp2 -= hracatk;
                        loveccanatk = 0;
                        cin >> pokracovat;
                    } else if (loveccanatk == 0) {
                        cout << "Přebili jste kuš." << endl;
                        loveccanatk = 1;
                        cin >> pokracovat;
                    }
                }
                break;
            }
            case 2:
                cin >> input;
                if (inventory[input - 1] == 1) {
                    cout << "Použili jste Léčivý lektvar a uzdravili jste se." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 4);
                    if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 2) {
                    cout << "Použili jste Lektvar many a obnovili jste manu." << endl;
                    hracmana = hracmana + ((hracmaxmana / 10) * 6);
                    if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 3) {
                    cout << "Použili jste smíšený lektvar a obnovili jste manu a životy." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 3);
                    if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                    hracmana = hracmana + ((hracmaxmana / 10) * 4);
                    if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 4) {
                    cout << "Použili jste záhadný lektvar, vaše životy i mana byly plně obnoveny." << endl;
                    hrachp = hracmaxhp;
                    hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else {
                    cout << "Sáhli jste do prázdné kapsy a nic nenašli, vskutku dobré využití vašeho tahu." << endl;
                    cin >> pokracovat;
                }
                break;

            case 3: {
                do {
                    cout << "Jaký spell chcete použít?" << endl;
                    cout << "1) " << spellname[0] << " Spotřeba many: " << spellmanacost[classvyber][0] << endl;
                    for (int i = 1; i < 4; i++) {
                        if (spellunlock[i - 1] == true) {
                            cout << i + 1 << ") " << spellname[i] << " Spotřeba many: " << spellmanacost[classvyber][i] << endl;
                        }
                    }
                    cin >> input;


                    if (input < 1 && input > 4 || (input == 2 && spellunlock[0] == false) || (input == 3 && spellunlock[1] == false) || (input == 4 && spellunlock[2] == false)) {
                        cout << "Neplatná hodnota" << endl;
                    } else {
                        bool potrebujeCil = true;
                        if (input == 1 && (classvyber == 2 || classvyber == 6)) {
                            potrebujeCil = false;
                        }

                        int cil = 1;
                        if (potrebujeCil) {
                            if (monsterhp1 > 0 && monsterhp2 > 0) {
                                do {
                                    cout << "Na které monstrum chcete zacílit spell? (1 nebo 2): ";
                                    cin >> cil;
                                } while (cil != 1 && cil != 2);
                            } else {
                                cil = (monsterhp1 > 0) ? 1 : 2;
                            }
                        }

                        if (input == 1 && !(classvyber == 2 || classvyber == 6)) {
                            if (cil == 1) spell1(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                            else spell1(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                        } else if (input == 1 && classvyber == 2 && hracmana >= spellmanacost[classvyber][0]) {
                            damagered = 3;
                            cout << "Obránili jste se a teď dostáváte menší damage na 3 kola." << endl;
                            hracmana = hracmana - spellmanacost[classvyber][0];
                            cin >> pokracovat;
                        } else if (input == 1 && classvyber == 2 && hracmana < spellmanacost[classvyber][0]) {
                            cout << "Nedostatek many." << endl; cin >> pokracovat;
                        } else if (input == 1 && classvyber == 6 && hracmana >= spellmanacost[classvyber][0]) {
                            invis = 3; cout << "Zneviditelnili jste se na 3 kola." << endl;
                            hracmana = hracmana - spellmanacost[classvyber][0];
                            cin >> pokracovat;
                        } else if (input == 1 && classvyber == 6 && hracmana < spellmanacost[classvyber][0]) {
                            cout << "Nedostatek many." << endl; cin >> pokracovat;
                        } else if (input == 2 && spellunlock[0] == true && classvyber != 1) {
                            if (cil == 1) spell2(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                            else spell2(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                        } else if (input == 2 && spellunlock[0] == true && classvyber == 1) {
                            cout << "Obránil jste se a švihnul po nepříteli za " << hracatk << " hp." << endl;
                            if (cil == 1) monsterhp1 -= hracatk; else monsterhp2 -= hracatk;
                            damagered = 3;
                            cin >> pokracovat;
                        } else if (input == 3 && spellunlock[1] == true && classvyber != 6) {
                            if (cil == 1) spell3(monsterhp1, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                            else spell3(monsterhp2, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                        } else if (input == 3 && spellunlock[1] == true && classvyber == 6) {
                            cout << "Zasáhl jste nepřítele dýkou za " << hracatk << " hp a otrávil ho." << endl;
                            if (cil == 1) { monsterhp1 -= hracatk; monster1poisoned = 3; }
                            else { monsterhp2 -= hracatk; monster2poisoned = 3; }
                            cin >> pokracovat;
                        } else if (input == 4 && spellunlock[2] == true) {
                            if (cil == 1) spell4(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster1poisoned, invis);
                            else spell4(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster2poisoned, invis);
                        }
                    }
                } while (input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false)));
                break;
            }
            default:
                cout << "Neplatná hodnota, zadejte hodnotu (1-3)" << endl;
                break;
            }
        } while (input < 1 || input > 3);

        for (int m = 1; m <= 2; m++) {
            int m_hp = (m == 1) ? monsterhp1 : monsterhp2;
            int m_id = (m == 1) ? monsterID : monsterID2;

            if (m_hp > 0 && hrachp > 0) {
                if (invis == 0) {
                    if (damagered == 0) {
                        cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] << " životů." << endl;
                        hrachp = hrachp - monsteratk[m_id];
                        cin >> pokracovat;
                    } else if (damagered > 0) {
                        if (classvyber == 1) {
                            if (monsteratk[m_id] - hracmaxhp / 10 <= 0) {
                                cout << "Útok od monstra " << monstername[m_id] << " jste zablokoval." << endl;
                                cin >> pokracovat;
                            } else {
                                cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] - (hracmaxhp / 10) << " životů." << endl;
                                hrachp = hrachp - (monsteratk[m_id] - (hracmaxhp / 10));
                                cin >> pokracovat;
                            }
                        } else if (classvyber == 2) {
                            if (monsteratk[m_id] - hracmaxhp / 6 <= 0) {
                                cout << "Útok od monstra " << monstername[m_id] << " jste zablokoval." << endl;
                                cin >> pokracovat;
                            } else {
                                cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] - (hracmaxhp / 6) << " životů." << endl;
                                hrachp = hrachp - (monsteratk[m_id] - (hracmaxhp / 6));
                                cin >> pokracovat;
                            }
                        }
                    }
                } else if (invis > 0) {
                    cout << "Jste neviditelní a útoku od " << monstername[m_id] << " jste se vyhli." << endl;
                    cin >> pokracovat;
                }
            }
        }

        if (monster1poisoned > 0 && monsterhp1 > 0) {
            monsterhp1 = monsterhp1 - (monstermaxhp[monsterID] / 10);
            cout << monstername[monsterID] << " je otrávený a dostal poškození za " << (monstermaxhp[monsterID] / 10) << " hp." << endl;
        }
        if (monster2poisoned > 0 && monsterhp2 > 0) {
            monsterhp2 = monsterhp2 - (monstermaxhp[monsterID2] / 10);
            cout << monstername[monsterID2] << " je otrávený a dostal poškození za " << (monstermaxhp[monsterID2] / 10) << " hp." << endl;
        }

        if (monsterhp1 <= 0 && monsterhp2 <= 0) {
            loveccanatk = 1;
            fight = false;
            cout << "Vítezství! Získali jste " << stage * 3 << " EXP!" << endl;
            hrachp = hrachp + 2;
            if (hrachp > hracmaxhp) hrachp = hracmaxhp;

            hracmana = hracmana + 4;
            if (hracmana > hracmaxmana) hracmana = hracmaxmana;

            experience = experience + stage * 3;
            if (experience >= 100) {
                cout << "Level up! Životy se vám zvýšily o 2, mana o 4, útok o 1!" << endl;
                hracmaxhp += 2; hrachp += 2;
                hracmaxmana += 4; hracmana += 4;
                hracatk += 1;
                experience -= 100;
            }
            golddrop = rand() % 2;
            if (golddrop == 1) {
                gold = gold + stage * 8;
                cout << "Získali jste " << stage * 8 << " zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
            }
            cin >> pokracovat;
        }

        if (hrachp <= 0) {
            fight = false;
            gameover = true;
        }
        if (damagered > 0) damagered--;
        if (invis > 0) invis--;
        if (atkbuff > 0) {
            atkbuff--;
        }
        if (monster1poisoned > 0) monster1poisoned--;
        if (monster2poisoned > 0) monster2poisoned--;

        hracmana++;
        if (hracmana > hracmaxmana) hracmana = hracmaxmana;
    }
}
if (stagetype == 4) {
    fight = true;
    system("cls");

    monsterID = rand() % stage;
    monsterhp1 = monstermaxhp[monsterID];
    monster1poisoned = 0;

    monsterID2 = rand() % stage;
    monsterhp2 = monstermaxhp[monsterID2];
    monster2poisoned = 0;

    monsterID3 = rand() % stage;
    monsterhp3 = monstermaxhp[monsterID3];
    monster3poisoned = 0;

    while (fight == true) {
        system("cls");
        cout << stagename[stage - 1] << endl;
        cout << "-------------------------------------------------" << endl << endl;

        if (monsterhp1 > 0) {
            cout << "1) " << monstername[monsterID] << endl;
            cout << "Životy: " << monsterhp1 << "/" << monstermaxhp[monsterID] << endl;
            if (monster1poisoned > 0) cout << "Otrávený (" << monster1poisoned << " tahy)" << endl;
        } else {
            cout << "1) " << monstername[monsterID] << " [MRTVÝ]" << endl;
        }
        cout << endl;

        if (monsterhp2 > 0) {
            cout << "2) " << monstername[monsterID2] << endl;
            cout << "Životy: " << monsterhp2 << "/" << monstermaxhp[monsterID2] << endl;
            if (monster2poisoned > 0) cout << "Otrávený (" << monster2poisoned << " tahy)" << endl;
        } else {
            cout << "2) " << monstername[monsterID2] << " [MRTVÝ]" << endl;
        }
        cout << endl;

        if (monsterhp3 > 0) {
            cout << "3) " << monstername[monsterID3] << endl;
            cout << "Životy: " << monsterhp3 << "/" << monstermaxhp[monsterID3] << endl;
            if (monster3poisoned > 0) cout << "Otrávený (" << monster3poisoned << " tahy)" << endl;
        } else {
            cout << "3) " << monstername[monsterID3] << " [MRTVÝ]" << endl;
        }

        cout << "-------------------------------------------------" << endl;
        cout << "Životy: " << hrachp << "/" << hracmaxhp << endl;
        cout << "Mana: " << hracmana << "/" << hracmaxmana << endl << endl;

        if (damagered > 0) cout << "Obrana: " << damagered << " tahy." << endl;
        if (invis > 0) cout << "Neviditelnost: " << invis << " tahy." << endl;

        do {
            if ((monsterhp1 <= 0 && monsterhp2 <= 0 && monsterhp3 <= 0) || hrachp <= 0) {
                break;
            }

            cout << "1) Útok" << endl << "2) Použít lektvary" << endl << "3) Spelly" << endl;
            cin >> input;

            switch (input) {
            case 1: {
                int cil = 1;
                int zivych = (monsterhp1 > 0 ? 1 : 0) + (monsterhp2 > 0 ? 1 : 0) + (monsterhp3 > 0 ? 1 : 0);

                if (zivych > 1) {
                    do {
                        cout << "Na které monstrum chceš zaútočit? (1, 2 nebo 3): ";
                        cin >> cil;
                    } while (cil < 1 || cil > 3 || (cil == 1 && monsterhp1 <= 0) || (cil == 2 && monsterhp2 <= 0) || (cil == 3 && monsterhp3 <= 0));
                } else {
                    if (monsterhp1 > 0) cil = 1;
                    else if (monsterhp2 > 0) cil = 2;
                    else cil = 3;
                }

                if (classvyber != 5) {
                    if (classvyber == 1 && atkbuff > 0) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 2 << endl;
                        if (cil == 1) monsterhp1 = monsterhp1 - (hracatk + 2);
                        else if (cil == 2) monsterhp2 = monsterhp2 - (hracatk + 2);
                        else monsterhp3 = monsterhp3 - (hracatk + 2);
                        cin >> pokracovat;
                    } else if (classvyber == 3 && atkbuff > 0) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 4 << endl;
                        if (cil == 1) monsterhp1 = monsterhp1 - (hracatk + 4);
                        else if (cil == 2) monsterhp2 = monsterhp2 - (hracatk + 4);
                        else monsterhp3 = monsterhp3 - (hracatk + 4);
                        cin >> pokracovat;
                    } else {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                        if (cil == 1) monsterhp1 = monsterhp1 - hracatk;
                        else if (cil == 2) monsterhp2 = monsterhp2 - hracatk;
                        else monsterhp3 = monsterhp3 - hracatk;
                        cin >> pokracovat;
                    }
                } else if (classvyber == 5) {
                    if (loveccanatk == 1) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                        if (cil == 1) monsterhp1 -= hracatk;
                        else if (cil == 2) monsterhp2 -= hracatk;
                        else monsterhp3 -= hracatk;
                        loveccanatk = 0;
                        cin >> pokracovat;
                    } else if (loveccanatk == 0) {
                        cout << "Přebili jste kuš." << endl;
                        loveccanatk = 1;
                        cin >> pokracovat;
                    }
                }
                break;
            }
            case 2:
                cin >> input;
                if (inventory[input - 1] == 1) {
                    cout << "Použili jste Léčivý lektvar a uzdravili jste se." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 4);
                    if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 2) {
                    cout << "Použili jste Lektvar many a obnovili jste manu." << endl;
                    hracmana = hracmana + ((hracmaxmana / 10) * 6);
                    if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 3) {
                    cout << "Použili jste smíšený lektvar a obnovili jste manu a životy." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 3);
                    if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                    hracmana = hracmana + ((hracmaxmana / 10) * 4);
                    if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 4) {
                    cout << "Použili jste záhadný lektvar, vaše životy i mana byly plně obnoveny." << endl;
                    hrachp = hracmaxhp;
                    hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else {
                    cout << "Sáhli jste do prázdné kapsy a nic nenašli, vskutku dobré využití vašeho tahu." << endl;
                    cin >> pokracovat;
                }
                break;

            case 3: {
                do {
                    cout << "Jaký spell chcete použít?" << endl;
                    cout << "1) " << spellname[0] << " Spotřeba many: " << spellmanacost[classvyber][0] << endl;
                    for (int i = 1; i < 4; i++) {
                        if (spellunlock[i - 1] == true) {
                            cout << i + 1 << ") " << spellname[i] << " Spotřeba many: " << spellmanacost[classvyber][i] << endl;
                        }
                    }
                    cin >> input;

                    if (input < 1 && input > 4 || (input == 2 && spellunlock[0] == false) || (input == 3 && spellunlock[1] == false) || (input == 4 && spellunlock[2] == false)) {
                        cout << "Neplatná hodnota" << endl;
                    } else {
                        bool potrebujeCil = true;
                        if (input == 1 && (classvyber == 2 || classvyber == 6)) {
                            potrebujeCil = false;
                        }

                        int cil = 1;
                        if (potrebujeCil) {
                            int zivych = (monsterhp1 > 0 ? 1 : 0) + (monsterhp2 > 0 ? 1 : 0) + (monsterhp3 > 0 ? 1 : 0);
                            if (zivych > 1) {
                                do {
                                    cout << "Na které monstrum chceš zacílit kouzlo? (1, 2 nebo 3): ";
                                    cin >> cil;
                                } while (cil < 1 || cil > 3 || (cil == 1 && monsterhp1 <= 0) || (cil == 2 && monsterhp2 <= 0) || (cil == 3 && monsterhp3 <= 0));
                            } else {
                                if (monsterhp1 > 0) cil = 1;
                                else if (monsterhp2 > 0) cil = 2;
                                else cil = 3;
                            }
                        }

                        if (input == 1 && !(classvyber == 2 || classvyber == 6)) {
                            if (cil == 1) spell1(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                            else if (cil == 2) spell1(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                            else spell1(monsterhp3, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                        } else if (input == 1 && classvyber == 2 && hracmana >= spellmanacost[classvyber][0]) {
                            damagered = 3;
                            cout << "Obránili jste se a teď dostáváte menší damage na 3 kola." << endl;
                            hracmana = hracmana - spellmanacost[classvyber][0];
                            cin >> pokracovat;
                        } else if (input == 1 && classvyber == 2 && hracmana < spellmanacost[classvyber][0]) {
                            cout << "Nedostatek many." << endl; cin >> pokracovat;
                        } else if (input == 1 && classvyber == 6 && hracmana >= spellmanacost[classvyber][0]) {
                            invis = 3; cout << "Zneviditelnili jste se na 3 kola." << endl;
                            hracmana = hracmana - spellmanacost[classvyber][0];
                            cin >> pokracovat;
                        } else if (input == 1 && classvyber == 6 && hracmana < spellmanacost[classvyber][0]) {
                            cout << "Nedostatek many." << endl; cin >> pokracovat;
                        } else if (input == 2 && spellunlock[0] == true && classvyber != 1) {
                            if (cil == 1) spell2(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                            else if (cil == 2) spell2(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                            else spell2(monsterhp3, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                        } else if (input == 2 && spellunlock[0] == true && classvyber == 1) {
                            cout << "Obránil jste se a švihnul po nepříteli za " << hracatk << " hp." << endl;
                            if (cil == 1) monsterhp1 -= hracatk;
                            else if (cil == 2) monsterhp2 -= hracatk;
                            else monsterhp3 -= hracatk;
                            damagered = 3;
                            cin >> pokracovat;
                        } else if (input == 3 && spellunlock[1] == true && classvyber != 6) {
                            if (cil == 1) spell3(monsterhp1, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                            else if (cil == 2) spell3(monsterhp2, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                            else spell3(monsterhp3, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                        } else if (input == 3 && spellunlock[1] == true && classvyber == 6) {
                            cout << "Zasáhl jste nepřítele dýkou za " << hracatk << " hp a otrávil ho." << endl;
                            if (cil == 1) { monsterhp1 -= hracatk; monster1poisoned = 3; }
                            else if (cil == 2) { monsterhp2 -= hracatk; monster2poisoned = 3; }
                            else { monsterhp3 -= hracatk; monster3poisoned = 3; }
                            cin >> pokracovat;
                        } else if (input == 4 && spellunlock[2] == true) {
                            if (cil == 1) spell4(monsterhp1, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster1poisoned, invis);
                            else if (cil == 2) spell4(monsterhp2, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster2poisoned, invis);
                            else spell4(monsterhp3, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster3poisoned, invis);
                        }
                    }
                } while (input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false)));
                break;
            }
            default:
                cout << "Neplatná hodnota, zadejte hodnotu (1-3)" << endl;
                break;
            }
        } while (input < 1 || input > 3);

        for (int m = 1; m <= 3; m++) {
            int m_hp = (m == 1) ? monsterhp1 : ((m == 2) ? monsterhp2 : monsterhp3);
            int m_id = (m == 1) ? monsterID : ((m == 2) ? monsterID2 : monsterID3);

            if (m_hp > 0 && hrachp > 0) {
                if (invis == 0) {
                    if (damagered == 0) {
                        cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] << " životů." << endl;
                        hrachp = hrachp - monsteratk[m_id];
                        cin >> pokracovat;
                    } else if (damagered > 0) {
                        if (classvyber == 1) {
                            if (monsteratk[m_id] - hracmaxhp / 10 <= 0) {
                                cout << "Útok od monstra " << monstername[m_id] << " jste zablokoval." << endl;
                                cin >> pokracovat;
                            } else {
                                cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] - (hracmaxhp / 10) << " životů." << endl;
                                hrachp = hrachp - (monsteratk[m_id] - (hracmaxhp / 10));
                                cin >> pokracovat;
                            }
                        } else if (classvyber == 2) {
                            if (monsteratk[m_id] - hracmaxhp / 6 <= 0) {
                                cout << "Útok od monstra " << monstername[m_id] << " jste zablokoval." << endl;
                                cin >> pokracovat;
                            } else {
                                cout << monstername[m_id] << " útočí a dává vám poškození za " << monsteratk[m_id] - (hracmaxhp / 6) << " životů." << endl;
                                hrachp = hrachp - (monsteratk[m_id] - (hracmaxhp / 6));
                                cin >> pokracovat;
                            }
                        }
                    }
                } else if (invis > 0) {
                    cout << "Jste neviditelní a útoku od " << monstername[m_id] << " jste se vyhli." << endl;
                    cin >> pokracovat;
                }
            }
        }

        if (monster1poisoned > 0 && monsterhp1 > 0) {
            monsterhp1 = monsterhp1 - (monstermaxhp[monsterID] / 10);
            cout << monstername[monsterID] << " je otrávený a dostal poškození za " << (monstermaxhp[monsterID] / 10) << " hp." << endl;
        }
        if (monster2poisoned > 0 && monsterhp2 > 0) {
            monsterhp2 = monsterhp2 - (monstermaxhp[monsterID2] / 10);
            cout << monstername[monsterID2] << " je otrávený a dostal poškození za " << (monstermaxhp[monsterID2] / 10) << " hp." << endl;
        }
        if (monster3poisoned > 0 && monsterhp3 > 0) {
            monsterhp3 = monsterhp3 - (monstermaxhp[monsterID3] / 10);
            cout << monstername[monsterID3] << " je otrávený a dostal poškození za " << (monstermaxhp[monsterID3] / 10) << " hp." << endl;
        }

        if (monsterhp1 <= 0 && monsterhp2 <= 0 && monsterhp3 <= 0) {
            loveccanatk = 1;
            fight = false;
            cout << "Vítezství! Získali jste " << stage * 3 << " EXP!" << endl;
            hrachp = hrachp + 2;
            if (hrachp > hracmaxhp) hrachp = hracmaxhp;

            hracmana = hracmana + 4;
            if (hracmana > hracmaxmana) hracmana = hracmaxmana;

            experience = experience + stage * 3;
            if (experience >= 100) {
                cout << "Level up! Životy se vám zvýšily o 2, mana o 4, útok o 1!" << endl;
                hracmaxhp += 2; hrachp += 2;
                hracmaxmana += 4; hracmana += 4;
                hracatk += 1;
                experience -= 100;
            }
            golddrop = rand() % 2;
            if (golddrop == 1) {
                gold = gold + stage * 8;
                cout << "Získali jste " << stage * 8 << " zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
            }
            cin >> pokracovat;
        }

        if (hrachp <= 0) {
            fight = false;
            gameover = true;
        }

        if (damagered > 0) damagered--;
        if (invis > 0) invis--;
        if (atkbuff > 0) {
            atkbuff--;
        }
        if (monster1poisoned > 0) monster1poisoned--;
        if (monster2poisoned > 0) monster2poisoned--;
        if (monster3poisoned > 0) monster3poisoned--;

        hracmana++;
        if (hracmana > hracmaxmana) hracmana = hracmaxmana;
    }
}
if (stagetype == 5) {
    fight = true;
    system("cls");
    miniboss++;
    minibosshp=minibossmaxhp[miniboss-1];
    while (fight == true) {
        turn++;
        system("cls");
        cout << stagename[stage - 1] << endl;
        cout << "-------------------------------------------------" << endl << endl;
        cout << minibossname[miniboss - 1] << endl;
        cout << "Životy: " << minibosshp << "/" << minibossmaxhp[miniboss - 1] << endl << endl;
        if (monster1poisoned > 0) {
            cout << "Otrávený" << endl << endl;
        }
        minibossdialogue(miniboss, turn, minibossname[miniboss - 1]);
        cout << "-------------------------------------------------" << endl;
        cout << "Životy: " << hrachp << "/" << hracmaxhp << endl;
        cout << "Mana: " << hracmana << "/" << hracmaxmana << endl << endl;
        if (damagered > 0) {
            cout << "Obrana: " << damagered << " tahy." << endl;
        }
        if (invis > 0) {
            cout << "Neviditelnost: " << invis << " tahy." << endl;
        }

        if (minibosshp > 0 && hrachp > 0) {
            minibossatk(miniboss, turn, classvyber, minibossname[miniboss - 1], hracmaxhp, hrachp, damagered, invis);
            if (monster1poisoned > 0) {
                int otravadamage = minibossmaxhp[miniboss - 1] / 10;
                minibosshp = minibosshp - otravadamage;
                cout << "Nepřítel je otrávený a dostal poškození za " << otravadamage << " hp." << endl;
                monster1poisoned--;
                cin >> pokracovat;
            }
        }
        if (atkbuff > 0) {
            atkbuff--;
        }
        if (damagered > 0) {
            damagered--;
        }
        if (invis > 0) {
            invis--;
        }

        if (hrachp <= 0) {
            fight = false;
            gameover = true;
            continue;
        }

        do {
            if (minibosshp <= 0) {
                break;
            }

            cout << "1) Útok" << endl << "2) Použít lektvary" << endl << "3) Spelly" << endl;
            cin >> input;
            switch (input) {
            case 1:
                if (classvyber != 5) {
                    if (classvyber == 1 && atkbuff > 0) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 2 << endl;
                        minibosshp = minibosshp - (hracatk + 2);
                        cin >> pokracovat;
                    } else if (classvyber == 3 && atkbuff > 0) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 4 << endl;
                        minibosshp = minibosshp - (hracatk + 4);
                        cin >> pokracovat;
                    } else {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                        minibosshp = minibosshp - hracatk;
                        cin >> pokracovat;
                    }
                } else if (classvyber == 5) {
                    if (loveccanatk == 1) {
                        cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                        minibosshp = minibosshp - hracatk;
                        loveccanatk = 0;
                        cin >> pokracovat;
                    } else if (loveccanatk == 0) {
                        cout << "Přebili jste kuš." << endl;
                        loveccanatk = 1;
                        cin >> pokracovat;
                    }
                }
                break;
            case 2:
                for (int i = 0; i <= 64; i++) {
                    if (inventory[i] != 0) {
                        cout << i + 1 << ") " << itemname[inventory[i]] << endl;
                    }
                }
                cin >> input;
                if (inventory[input - 1] == 1) {
                    cout << "Použili jste Léčivý lektvar a uzdravili jste se." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 4);
                    if (hrachp > hracmaxhp) {
                        hrachp = hracmaxhp;
                    }
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 2) {
                    cout << "Použili jste Lektvar many a obnovili jste manu." << endl;
                    hracmana = hracmana + ((hracmaxmana / 10) * 6);
                    if (hracmana > hracmaxmana) {
                        hracmana = hracmaxmana;
                    }
                    inventory[input - 1] = 0;
                } else if (inventory[input - 1] == 3) {
                    cout << "Použili jste smíšený lektvar a obnovili jste manu a životy." << endl;
                    hrachp = hrachp + ((hracmaxhp / 10) * 3);
                    if (hrachp > hracmaxhp) {
                        hrachp = hracmaxhp;
                    }
                    hracmana = hracmana + ((hracmaxmana / 10) * 4);
                    if (hracmana > hracmaxmana) {
                        hracmana = hracmaxmana;
                    }
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 4) {
                    cout << "Použili jste záhadný lektvar, vaše životy i mana byly plně obnoveny." << endl;
                    hrachp = hracmaxhp;
                    hracmana = hracmaxmana;
                    inventory[input - 1] = 0;
                    cin >> pokracovat;
                } else if (inventory[input - 1] == 0) {
                    cout << "Sáhli jste do prázdné kapsy a nic nenašli, vskutku dobré využití vašeho tahu." << endl;
                    cin >> pokracovat;
                }
                break;
            case 3:
                do {
                    cout << "Jaký spell chcete použít?" << endl;
                    cout << "1) " << spellname[0] << " Spotřeba many: " << spellmanacost[classvyber][0] << endl;
                    for (int i = 1; i < 4; i++) {
                        if (spellunlock[i - 1] == true) {
                            cout << i + 1 << ") " << spellname[i] << " Spotřeba many: " << spellmanacost[classvyber][i] << endl;
                        }
                    }
                    cin >> input;
                    if (input < 1 || input > 4 || (input == 2 && spellunlock[0] == false) || (input == 3 && spellunlock[1] == false) || (input == 4 && spellunlock[2] == false)) {
                        cout << "Neplatná hodnota" << endl;
                    } else if (input == 1 && !(classvyber == 2 || classvyber == 6)) {
                        spell1(minibosshp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
                    } else if (input == 1 && classvyber == 2 && hracmana >= spellmanacost[classvyber][0]) {
                        damagered = 3;
                        cout << "Obránili jste se a teď dostáváte menší damage na 3 kola." << endl;
                        hracmana = hracmana - spellmanacost[classvyber][0];
                        cin >> pokracovat;
                    } else if (input == 1 && classvyber == 2 && hracmana < spellmanacost[classvyber][0]) {
                        cout << "Nedostatek many." << endl;
                        cin >> pokracovat;
                    } else if (input == 1 && classvyber == 6 && hracmana >= spellmanacost[classvyber][0]) {
                        invis = 3;
                        cout << "Zneviditelnili jste se na 3 kola." << endl;
                        hracmana = hracmana - spellmanacost[classvyber][0];
                        cin >> pokracovat;
                    } else if (input == 1 && classvyber == 6 && hracmana < spellmanacost[classvyber][0]) {
                        cout << "Nedostatek many." << endl;
                        cin >> pokracovat;
                    } else if (input == 2 && spellunlock[0] == true && classvyber != 1) {
                        spell2(minibosshp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
                    } else if (input == 2 && spellunlock[0] == true && classvyber == 1) {
                        cout << "Obránil jste se a švihnul po nepříteli za " << hracatk << " hp." << endl;
                        minibosshp = minibosshp - hracatk;
                        damagered = 3;
                    } else if (input == 3 && spellunlock[1] == true && classvyber != 6) {
                        spell3(minibosshp, hracatk, classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
                    } else if (input == 3 && spellunlock[1] == true && classvyber == 6) {
                        cout << "Zasáhl jste nepřítele dýkou za " << hracatk << " hp a otrávil ho." << endl;
                        minibosshp = minibosshp - hracatk;
                        monster1poisoned = 3;
                    } else if (input == 4 && spellunlock[2] == true) {
                        spell4(minibosshp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster1poisoned, invis);
                    }
                }while(input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false)));
                break;
            default:
                cout << "Neplatná hodnota, zadejte hodnotu (1-4)" << endl;
                break;
            }
        } while (input < 1 || input > 3);


        if (minibosshp <= 0) {
            loveccanatk = 1;
            fight = false;
            cout << "Vítezství! Získali jste " << stage * 5 << " EXP!" << endl;
            hrachp = hrachp + 2;
            if (hrachp > hracmaxhp) {
                hrachp = hracmaxhp;
            }
            hracmana = hracmana + 4;
            if (hracmana > hracmaxmana) {
                hracmana = hracmaxmana;
            }
            experience = experience + stage * 3;
            if (experience >= 100) {
                cout << "Level up! Životy se vám zvýšily o 2, mana o 4, útok o 1!" << endl;
                hracmaxhp = hracmaxhp + 2;
                hrachp = hrachp + 2;
                hracmaxmana = hracmaxmana + 4;
                hracmana = hracmana + 4;
                hracatk = hracatk + 1;
                experience = experience - 100;
            }
            gold = gold + stage * 8;
            cout << "Získali jste " << stage * 8 << " zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
            cin >> pokracovat;
        }

        hracmana++;
        if (hracmana > hracmaxmana) {
            hracmana = hracmaxmana;
        }
    }
}
if (stagetype==6) {
    system("cls");
    cout << "Neznámý člověk: Wow! musím uznat ten boj byl fakt něco, normálně tohle nedělám, ale za tohle vás nechám dát pořádně uzdravit!" << endl;
    cout << "Životy a mana obnoveny." << endl;
    cin >> pokracovat;
    hrachp = hracmaxhp;
    hracmana = hracmaxmana;
    cout << "Mě se nemusíte bát, jsem pouhý obchodník s lektvary, který zde skončil." << endl;
    cin >> pokracovat;
    odejit = 0;
do {
    system("cls");
    cout << stagename[stage - 1] << endl;
    cout << "---------------------------" << endl;
    cout << "Co chcete podniknout?" << endl;
    cout << "1) Zakoupit lektvary" << endl;
    cout << "2) Zhlédnout staty" << endl;
    cout << "3) Hádat" << endl;
    cout << "4) Odejít" << endl;
    cin >> input;

    switch (input) {
    case 1:
        system("cls");
        cout << "Jaké chcete zakoupit lektvary? (0 - Léčivý lektvar, 1 - Lektvar many, 2 - Smíšený lektvar)" << endl;
        cin >> input;
        if (input == 0) {
            cout << "Chcete zakoupit léčivý lektvar za 50 zlaťáků? (Obnoví 40% životů (zaokrouhleno nahoru) (0 - Ne, 1 - Ano)" << endl;
            do {
                cin >> input;
                if (input != 0 && input != 1) {
                    cout << "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                } else if (input == 1 && gold >= 50) {
                    gold = gold - 50;
                    additem(inventory, 64, 1);
                    cout << "Zakoupili jste léčivý lektvar za 50 zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
                } else if (input == 1 && gold < 50) {
                    cout << "Nemáte dostatek zlaťáků, chybí vám " << 50 - gold << " zlaťáků." << endl;
                }
            } while (input != 0 && input != 1);

        } else if (input == 1) {
            cout << "Chcete zakoupit lektvar many za 50 zlaťáků? (Obnoví 60% many (zaokrouhleno nahoru) (0 - Ne, 1 - Ano)" << endl;
            do {
                cin >> input;
                if (input != 0 && input != 1) {
                    cout << "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                } else if (input == 1 && gold >= 50) {
                    gold = gold - 50;
                    additem(inventory, 64, 2);
                    cout << "Zakoupili jste lektvar many za 50 zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
                } else if (input == 1 && gold < 50) {
                    cout << "Nemáte dostatek zlaťáků, chybí vám " << 50 - gold << " zlaťáků." << endl;
                }
            } while (input != 0 && input != 1);

        } else if (input == 2) {
            cout << "Chcete zakoupit smíšený lektvar za 50 zlaťáků? (Obnoví 30% životů a 40% many (zaokrouhleno nahoru) (0 - Ne, 1 - Ano)" << endl;
            do {
                cin >> input;
                if (input != 0 && input != 1) {
                    cout << "Neplatná hodnota, zadejte hodnotu 0-1: " << endl;
                } else if (input == 1 && gold >= 50) {
                    gold = gold - 50;
                    additem(inventory, 64, 3);
                    cout << "Zakoupili jste smíšený lektvar za 50 zlaťáků. Teď máte " << gold << " zlaťáků." << endl;
                } else if (input == 1 && gold < 50) {
                    cout << "Nemáte dostatek zlaťáků, chybí vám " << 50 - gold << " zlaťáků." << endl;
                }
            } while (input != 0 && input != 1);
        }
        break;
    case 2:
        system("cls");
        cout << "Zapište cokoliv + Enter k navrácení do výběru." << endl;
        statcheck(jmeno, hracmaxhp, hrachp, hracatk, hracmaxmana, hracmana, hraczbran, spell, spellunlock, spellname, level, experience, stage, gold);
        cin >> pokracovat;
        break;
    case 3:
        if (canguess==true) {
        system("cls");
        cout << "Jak se jmenovala zbraň který falešný hrdina používal?" << endl;
        cin >> pokracovat;
        if (pokracovat=="Frostpiercer") {
        cout << "Správně";
            additem(inventory, 64, 4);
        cin >> pokracovat;
        }else {
        cout << "Bohužel špatně.";
        }}else if (canguess==false) {
        cout << "Už jste hádal." << endl;
        cin >> pokracovat;
        }
        canguess=false;
        break;
    case 4:
        cout << "Chcete opustit vesnici? (0 - Ne, 1 - Ano)" << endl;
        cin >> input;
        if (input == 1) {
            odejit = 1;
        }
        break;

    default:
        system("cls");
        cout << "Neplatná hodnota, zadejte hodnotu 1-4" << endl;
    }
} while (odejit == 0);
}
if (stagetype == 7) {
    turn=0;
    fight = true;
    system("cls");
    freeze = false;
    slowness = 0;
    shield = false;
    glacithornhp=glacithornmaxhp;
    while (fight == true) {
        turn++;
        system("cls");
        cout << stagename[stage - 1] << endl;
        cout << "-------------------------------------------------" << endl << endl;
        cout << "Glacithorn, Ledový titán" << endl;
        cout << "Životy: " << glacithornhp << "/" << glacithornmaxhp << endl << endl;
        if (monster1poisoned > 0) {
            cout << "Otrávený" << endl << endl;
        }
        cout << "-------------------------------------------------" << endl;
        cout << "Životy: " << hrachp << "/" << hracmaxhp << endl;
        cout << "Mana: " << hracmana << "/" << hracmaxmana << endl << endl;


        if (shield == true && glacithornbeforeshield == glacithornhp) {
            cout << "Nedokázali jste prolomit štít! Glacithorn získal zpátky 5 životů!" << endl;
            glacithornhp = glacithornhp + 5;
            if (glacithornhp > glacithornmaxhp) {
                glacithornhp = glacithornmaxhp;
            }
            shield = false;
            cin >> pokracovat;
        } else if (shield == true && glacithornbeforeshield > glacithornhp) {
            cout << "Úspěšně jste prolomili Glacithornův štít!" << endl;
            glacithornhp=glacithornbeforeshield;
            shield = false;
            cin >> pokracovat;
        }

        if (turn % 2 == 1) {
            cout << "Glacithorn se vás pokusil zpomalit!" << endl;
            slowness = rand() % 4 + 1;
        }

        if (turn % 6 == 0) {
            if (invis == 0) {
                if (damagered == 0) {
                    cout << "Glacithorn použil ledovou ránu a dal poškození za 10 životů." << endl;
                    hrachp = hrachp - 10;
                    cout << "Glacithorn udeřil přímo do srdce zimou věků!" << endl;
                    freeze = true;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((10 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokovali." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << "Glacithorn použil ledovou ránu a dal poškození za " << 10 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (10 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((10 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokovali." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << "Glacithorn použil ledovou ránu a dal poškození za " << 10 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (10 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else if (invis > 0) {
                cout << "Jste neviditelní a útoku ledovou ránou jste se vyhli." << endl;
                cin >> pokracovat;
            }
        }
        else if (turn % 3 == 0) {
            cout << "Glacithorn se ukryl za štítem, zaútočte na něho, abyste ho prolomili!" << endl;
            glacithornbeforeshield = glacithornhp;
            shield = true;
            cin >> pokracovat;
        }
        else {

            if (invis == 0) {
                if (damagered == 0) {
                    cout << "Glacithorn útočí za 7 životů." << endl;
                    hrachp = hrachp - 7;
                    cin >> pokracovat;
                } else if (damagered > 0) {
                    if (classvyber == 1) {
                        if ((7 - hracmaxhp / 10) < 0) {
                            cout << "Útok od monstra jste zablokovali." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << "Glacithorn útočí za " << 7 - (hracmaxhp / 10) << " životů." << endl;
                            hrachp = hrachp - (7 - (hracmaxhp / 10));
                            cin >> pokracovat;
                        }
                    } else if (classvyber == 2) {
                        if ((7 - hracmaxhp / 6) < 0) {
                            cout << "Útok od monstra jste zablokovali." << endl;
                            cin >> pokracovat;
                        } else {
                            cout << "Glacithorn útočí za " << 7 - (hracmaxhp / 6) << " životů." << endl;
                            hrachp = hrachp - (7 - (hracmaxhp / 6));
                            cin >> pokracovat;
                        }
                    }
                }
            } else {
                cout << "Jste neviditelní, Glacithorn vás minul." << endl;
                cin >> pokracovat;
            }
        }


        if (glacithornhp > 0 && hrachp > 0) {
            if (monster1poisoned > 0) {
                glacithornhp = glacithornhp - (glacithornmaxhp / 10);
                cout << "Glacithorn je otrávený a dostal poškození za " << (glacithornmaxhp / 10) << " hp." << endl;
                monster1poisoned--;
                cin >> pokracovat;
            }
        }


        if (hrachp <= 0) {
            fight = false;
            gameover = true;
            continue;
        }


        if (freeze == false) {
            if (slowness == 0) {
                do {
                    if (glacithornhp <= 0) {
                        break;
                    }
                    cout << "1) Útok" << endl << "2) Použít lektvary" << endl << "3) Spelly" << endl;
                    cin >> input;
                    switch (input) {
                    case 1:
                        if (classvyber != 5) {
                            if (classvyber == 1 && atkbuff > 0) {
                                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 2 << endl;
                                glacithornhp = glacithornhp - (hracatk + 2);
                                cin >> pokracovat;
                            } else if (classvyber == 3 && atkbuff > 0) {
                                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk + 4 << endl;
                                glacithornhp = glacithornhp - (hracatk + 4);
                                cin >> pokracovat;
                            } else {
                                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                                glacithornhp = glacithornhp - hracatk;
                                cin >> pokracovat;
                            }
                        } else if (classvyber == 5) {
                            if (loveccanatk == 1) {
                                cout << "Zaútočili jste na nepřítele a dali poškození " << hracatk << endl;
                                glacithornhp = glacithornhp - hracatk;
                                loveccanatk = 0;
                                cin >> pokracovat;
                            } else if (loveccanatk == 0) {
                                cout << "Přebili jste kuš." << endl;
                                loveccanatk = 1;
                                cin >> pokracovat;
                            }
                        }
                        break;
                    case 2:
                        for (int i = 0; i <= 64; i++) {
                            if (inventory[i] != 0) {
                                cout << i + 1 << ") " << itemname[inventory[i]] << endl;
                            }
                        }
                        cin >> input;
                        if (inventory[input - 1] == 1) {
                            cout << "Použili jste Léčivý lektvar a uzdravili jste se." << endl;
                            hrachp = hrachp + ((hracmaxhp / 10) * 4);
                            if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                            inventory[input - 1] = 0;
                            cin >> pokracovat;
                        } else if (inventory[input - 1] == 2) {
                            cout << "Použili jste Lektvar many a obnovili jste manu." << endl;
                            hracmana = hracmana + ((hracmaxmana / 10) * 6);
                            if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                            inventory[input - 1] = 0;
                            cin >> pokracovat;
                        } else if (inventory[input - 1] == 3) {
                            cout << "Použili jste smíšený lektvar." << endl;
                            hrachp = hrachp + ((hracmaxhp / 10) * 3);
                            if (hrachp > hracmaxhp) hrachp = hracmaxhp;
                            hracmana = hracmana + ((hracmaxmana / 10) * 4);
                            if (hracmana > hracmaxmana) hracmana = hracmaxmana;
                            inventory[input - 1] = 0;
                            cin >> pokracovat;
                        } else if (inventory[input - 1] == 4) {
                            cout << "Použili jste záhadný lektvar, vaše statistiky jsou plné." << endl;
                            hrachp = hracmaxhp;
                            hracmana = hracmaxmana;
                            inventory[input - 1] = 0;
                            cin >> pokracovat;
                        }
                        break;
                    case 3: do{
            cout << "Jaký spell chcete použít?" << endl;
            cout << "1) " << spellname[0] << " Spotřeba many: " << spellmanacost[classvyber][0] << endl;
            for (int i = 1; i<4; i++) {
                if (spellunlock[i-1] == true) {
                    cout << i+1 << ") " << spellname[i] << " Spotřeba many: " << spellmanacost[classvyber][i] << endl;
                }
            }
            cin >> input;
            if (input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false))) {
                cout << "Neplatná hodnota" << endl;
            }else if(input == 1&&!(classvyber == 2||classvyber == 6)) {
            spell1(glacithornhp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][0], pokracovat);
            }else if(input==1&&classvyber==2&&hracmana>=spellmanacost[classvyber][0]) {
            damagered = 3;
            cout << "Obránili jste se a teď dostáváte menší damage na 3 kola." << endl;
            hracmana = hracmana - spellmanacost[classvyber][0];
            cin >> pokracovat;
            }else if(input==1&&classvyber==2&&hracmana<spellmanacost[classvyber][0]) {
                     cout << "Nedostatek many." << endl;
                     cin >> pokracovat;
            }else if(input==1&&classvyber==6&&hracmana>=spellmanacost[classvyber][0]) {
            invis = 3;
            cout << "Znevidili jste se na 3 kola." << endl;
            hracmana = hracmana - spellmanacost[classvyber][0];
            cin >> pokracovat;
            }else if(input==1&&classvyber==6&&hracmana<spellmanacost[classvyber][0]){
                    cout << "Nedostatek many." << endl;
                     cin >> pokracovat;
            }else if (input==2&&spellunlock[0]==true&&classvyber!=1) {
            spell2(glacithornhp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][1], pokracovat, invis, hrachp, hracmaxhp, loveccanatk);
            }else if (input==2&&spellunlock[0]==true&&classvyber==1) {
            cout << "Obránil jste se a švihnul po nepřátely za " << hracatk << " hp." << endl;
            glacithornhp = glacithornhp - hracatk;
            damagered = 3;
            }else if(input==3&&spellunlock[1]==true&&classvyber!=6) {
             spell3(glacithornhp,hracatk,classvyber, hracmana, spellmanacost[classvyber][2], pokracovat, atkbuff, hrachp, hracmaxhp);
            }else if(input==3&&spellunlock[1]==true&&classvyber==6) {
            cout << "Zasáhl jste nepřatele dýkou za " << hracatk << " hp a otrávil je." << endl;
            glacithornhp = glacithornhp - hracatk;
            monster1poisoned = 3;
            }else if(input==4&&spellunlock[2]==true) {
            spell4(glacithornhp, gold, hracatk, classvyber, hracmana, spellmanacost[classvyber][3], pokracovat, atkbuff, hrachp, hracmaxhp, monster1poisoned, invis);
            }
            }while(input<1||input>4||((input==2&&spellunlock[0]==false)||(input==3&&spellunlock[1]==false)||(input==4&&spellunlock[2]==false)));
            break;
                    default:
                        cout << "Neplatná hodnota, zadejte hodnotu (1-4)" << endl;
                        break;
                    }
                } while (input < 1 || input > 3);
            } else {
                cout << "Jste zpomaleni a nemůžete toto kolo nic dělat!" << endl;
                slowness=0;
                cin >> pokracovat;
            }
        } else {
            cout << "Jste zamraženi a nemůžete nic dělat!" << endl;
            freeze = false;
            cin >> pokracovat;
        }

        if (damagered > 0) damagered--;
        if (invis > 0) invis--;
        if (atkbuff > 0) {atkbuff--;}
        if (glacithornhp <= 0) {
            loveccanatk = 1;
            fight = false;
            cout << "Vítezství! Porazili jste Glacithorna a získali jste " << stage * 5 << " EXP!" << endl;
            cin >> pokracovat;
        }

        hracmana++;
        if (hracmana > hracmaxmana) {
            hracmana = hracmaxmana;
        }
    }
}
stage++;
canupgweapon = 1;
canupgarmor = 1;
turn = 0;
invis = 0;
damagered =0;
atkbuff =0;
if (stage==17) {
    win == true;
}
}while(gameover==false&&win==false);
if (gameover==true) {
    system("cls");
    cout << "Prohráli jste.";
}
if (win==true) {
    system("cls");
    cout << "Vyhráli jste! úspěsně jste porazili Glacithorna a zachráli království!";
}
return 0;
}
