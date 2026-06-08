# Hra-CPP
Jedná se o základní RPG hru s 6 třídami (classami), přičemž každá třída má až čtyři schopnosti. Hra není zcela vybalancovaná, ale pokud by měl hráč potíže, doporučil bych použít třídu Assassin.

## Vesnice
Ve vesnici může hráč obnovit životy, zvýšit své maximální životy a útok, zakoupit lektvary nebo se naučit nové kouzlo (spell).

## Boj
Hráč bojuje s jedním monstrem. Může použít útok, lektvary nebo kouzlo (spell).

## Boj se 2 monstry
Hráč nově bojuje se dvěma monstry. Boj funguje stejně jako předtím, ale hráč musí navíc vybrat cíl a každé monstrum útočí jednou za tah.

## Boj se 3 monstry
Stejný princip jako boj se dvěma monstry, ale monstra jsou celkem 3.

## Miniboss a boss
Na rozdíl od hráče začínají tah jako první a mají několik předdefinovaných útoků.

## Použité kousky kódu a zdroje
* **Knihovna `<cstdlib>` a `system("cls")`** – zdroj: Chtěl jsem už při tvorbě minulé hry vymazat obrazovku a našel jsem toto řešení.
* **`system("color 79")`** – zdroj: Ukazovali jsme si na hodině.
* **`SetConsoleOutputCP(CP_UTF8)` a `SetConsoleCP(CP_UTF8)`** – zdroj: Google AI sumarizace, povolí v konzoli českou diakritiku.
* **`continue`** – zdroj: Při implementaci boje se 2 a 3 monstry (a částečně u minibossů a bosse) mi pomohl model Gemini, který tuto funkci využil. Zjednodušeně řečeno v kódu ukončuje boj, pokud hráčovy životy klesnou na 0.
