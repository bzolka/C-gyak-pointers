// CppApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void PrefixAndPostFix_PlusPlus();
void Pointer_alapok();
void Pointerek_aritmetika_illetve_tömbök();
void Pointerek_PlusPlus();
void Pointerek_Haladobb();

int main()
{
	PrefixAndPostFix_PlusPlus();
	Pointer_alapok();
	Pointerek_aritmetika_illetve_tömbök();
	Pointerek_PlusPlus();
	Pointerek_Haladobb();
}

void PrefixAndPostFix_PlusPlus()
{
	printf("PrefixAndPostFix_PlusPlus\r\n");
	// Alapelv: két dolog történik, de némiképpen másként a prefix ++ (pl. ++x)
	//  és postfix ++ (pl. x++) esetén:
	// - EGGYEL NÖVELI a változó értékét (ebben nincs különbség)
	// - KIÉRTÉKELŐDIK, vagyis lesz a kifejezésnek (pl. x++ vagy ++x-nek) valamilyen értéke
	// ez már másként viselkedik a két esetre, lásd alább. Olyan, mintha a ++ egy függvényhívás
	// lenne (pl. Increment(int x) néven, mely megkapja paraméterként a számot, és ez a függvény
	// amivel visszatér, az a kifejezés értéke).


	// PREFIX ++. Pl.: ++x
	// Egyészt eggyel megnöveli a változót, x eggyel nagyobb lesz.
	// A kirtékelődés során a ++x értéke már a megnövelt érték.
	// Az alábbiban x 11 lesz, ++x értéke pedig a növelt érték (11), ez íródik be y-ba
	{
		int x = 10;
		int y = ++x;
		printf("Prefix esete x: %d y: %d\r\n", x, y);
	}
	// A ++-ra úgy is lehet gondolni, mintha egy függvény lenne, mely egy számot vár paraméterként,
	// és itt a prefix ++ esetében ez az Increment a kapott számmal térne vissza, nem az eggyel növelttel.


	// POSTFIX ++. Pl.: x++
	// Egyészt eggyel megnöveli a változót, x eggyel nagyobb lesz (pont úgy, mint a prefixnél)
	// A kiértékelődés során az x++ értéke MÉG AZ EREDETI, NEM NÖVELT érték.
	// Az alábbiban x 11 lesz, x++ értéke pedig az eredeti (10) érték, ez íródik be y-ba;
	{
		int x = 10;
		int y = x++;
		printf("Postfix esete x: %d y: %d\r\n", x, y);
	}

	// Megjegyzés: amikor csak magában áll az x++ ill. ++x kifejezés, mindegy melyiket használjuk,
	// nincs különbség (hiszen a kifejezés értékét helyben nem használjuk ki). Pl.:
	{
		int x = 10;
		x++; // nem adjuk értékül semminek
		++x; // nem adjuk értékül semminek itt sem
	}
}

void Pointer_alapok()
{
	int x = 10;	// egy négybájtos szám valahol a memóriában
	int y = 12; // egy négybájtos szám valahol a memóriában
	int nums[10]; // 10 darab 4 bájtos int-nek foglal helyet

	/* Az alábbi p változó:
	 - Egy olyan típusu mutató/pointer, mely int-re tud mutatni.
	 - Itt nem adtunk neki értéket, nem tudjuk mi a változó tartalma,
	   nem tudjuk, hogy hova mutat;
	 - A pointer változóban dolgok címét tudjuk tárolni. 32 bites környezetben
	   a poinrter változó (itt p) mérete 4 bájt, 64 bites környezetben 8 bájt.
	*/
	int* p;
	// Itt a & a "vedd a változó memóriacímét" operátor!!! &x az x változó címe, vagyis
	// helye a memóriában. Ezt beleírjuk p-be, hiszen az egy pointer, melybe
	// változók címét lehet beleírni
	p = &x; // pl. 32 bites környezetben valami ilyesmi: 0xac234bff;

	// Itt a * jelentése: ahova a pointer mutat, vagyis a p által mutatott hely!!!
	// Ahova p mutat (x-re mutat), oda beleír 11-et, így x értéke is 11 lesz.
	*p = 11;
	// Lényeges volt, hogy p int-re mutató pointer volt, így *p egy négybájtos
	// rekeszt jelent (mert int 4 bájt). Ha p típusa char* lett volna, akkor
	// *p csak egy egybájtos rekeszbe ír, mert a char mérete 1 bájt. Ez fontos!!!

	// A NULL egy speciális érték, melyre a pointerek értéke állítható.
	// Hasonló a C# null-hoz, de itt nagybetűvel kell írni.
	// A színfalak mögött a pointer értéke nulla lesz (pl. 0x00000000 32 biten).
	int* p1 = NULL;
}

void Pointerek_aritmetika_illetve_tömbök()
{
	// Szabály: a tömb neve az első elem címe!!!

	// A nums itt 10 darab 4 bájtos int egymás mellett.
	 int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// Lényeges, hogy a nums az első elem címét JELENTI (de csak JELENTI, a nums nem egy különálló
	// pointer, így külön 4 bájtos pointer NEM foglalódik neki - ez fontos!)

	// Az alábbiakban p1 és p2 egy-egy pointer (négybájtos 32 biten), ebbe beleírjuk a nums
	// tömb első elemének a címét, vagyis a pointer a nums tömb elejére mutat.
	int* p1 = &nums[0];
	int* p2 = nums; // ez ekvivalens az előzővel, így szoktuk


	// Gyakorlás: rajzold le, hogy mi a memóriakép a nums és a p vonatkozásában!


	// POINTER ARITMETIKA
	// Ez arról szól, mi történik akkor, ha egy pointer értékét megnöveljük
	// vagy csökkentjük.
	// Szabály: amikor egy pointer értékét eggyel megnöveljük, az értéke annyival nő
	// ami a pointer alaptípusának a mérete. Pl. int* esetén 4-gyel (mert int 4 bájt),
	// char* esetén eggyel nő, double* esetén 8-cal, vagy ha egy struktúrára mutat, akkor
	// az adott struktúra méretével. Úgy is lehet gondolkodni, hogy pl. int* p esetén
	// p-t eggyel növelve p egy "int"-nyivel mutat nagyobb helyre.

	// A fenti nums és p kapcsán
	int* p = nums;
	int x = *p; // x a tömb első elemével lesz egyenlő
	x = *(p + 1); // x a tömb második elemével lesz egyenlő (p-t eggyel növeljük, egy int-tel mutat nagyobb helyre, ami pont az első elem)
	x = *(p + 2); // x a tömb harmadik elemével egyenő
	x = *(p + 9); // x a tömb UTOLSÓ, vagyis 9. elemével egyenő

	// Szabály: a tömbök nevére is érvényes a pointer artimetika (hiszen a tömb neve az első elem címe),
	// illetve a pointerekre is lehet tömbindexelést használni. A pontos szabály (ezt NAGYON KELL tudni,
	// de logikus is):
	// p[i] ekv. nums[i] ekv. *(p + i) ekv.  ekv. *(nums + i)

	// Példák, ezek mind egyenértékűek:
	x = nums[2];
	x = p[2];
	x = *(p + 2);
	x = *(nums + 2);

	// A pointer értéke meg is változtatható, ezt csináljuk is gyakran:
	p = nums; // Ez már volt, a tömb első elemére mutat p
	++p;	  // p a tömb második elemére mutat
	--p;	  // p a tömb első elemére mutat

	// Ami viszont különbség a pointerek és a tömbök között: a tömb olyan "pointer", ami nem megváltoztatható!
	// Oka: a tömb neve az első elem címét JELENTI, de csak JELENTI. De mivel nincs a címnek külön hely, nem igazi pointer
	// nem lehet megváltoztatni!!! Ezek pl. hibásak:
	// nums++;
	// nums += 2;

	// Pointer aritmetikához tartozik még:
	// Két pointert ki is lehet vonni egymásból. Megkapjuk a címük különbségét, de nem bájtban, hanem hogy hány
	// "elemnyivel" nagyobb az egyik pointer a másiknál. Pl:
	int* p11 = &nums[1];
	int* p22 = &nums[3];
	int diff = p22 - p11; // diff értéke 2 lesz, mert két int-nyivel nagyobb p2 p1-nél (bájtban nagyobb a különbség)


	// Gyakorló kérdés: int** p; pointert eggyel növelve mennyivel nő a pointer értéke?
	// Válasz: p egy int* változóra mutat.  int* pedig egy pointer, mérete 32 bites
	// környezetben 4, 64 bites környezetben 8 bájt.
	// Így 32 bites környezetben 4-gyel, 64 bites környezetben
	// 8 bájttal nő p értéke (de összegészében egy pointernyi hellyel lesz nagyobb, így szoktunk gondolkodni).

	// Gyakorló kérdés: nevezz meg két különbséget a tömbök és pointerek között.
	// Megoldás:
	// 1. Egy tömb változó definiálásakor (pl. int tomb[10] az elemeknek foglalódik hely, de külön pointernek nem foglalódik hely.
	//    A pointer változó defini
}

void Pointerek_PlusPlus()
{
	int nums[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	int* p = nums;
	int x;

	// Határozd meg alább minden sorra (megoldások pár sorral lejjebb, de magadtól próbáld megoldani):
	// - mi lesz p értéke
	// - mi lesz x értéke
	// - mi változik a nums tömbben
	x = ++ * p;
	x = *p++; // a ++ operátor precenedenciája nagyobb, mint a * operátoré, így ez x = *(p++) -szal ekvivalens
	x = (*p)++;
	x = *++p;

	// Megoldások
	x = ++ * p; // Ahova p mutat, növeld meg eggyel. x-be a növel érték kerül.
	x = *p++;  // p-t növeld meg eggyel, de p++ kifejkezés értéke még az eredeti p (nem megnövelt). Vagyis ahova p mutat, az kerül x-be.
	x = (*p)++; // Vedd azt a rekeszt, ahova p mutat, ezt növeld meg eggyel, de a rekesz növelés előtti értékét vedd és írd x-be.
	x = *++p;	// A p pointer értékét növeld meg, ahova ez a növelt mutató mutat, azt vedd és írd x-be
}

void Pointerek_Haladobb()
{
	{
	// Pointerek pointerekre (mutatók mutatókra)
	// Egy pointer mutathat bármire: intre, char-ra, de akár egy másik pointerre is
	// Pl. ez egy olyan mutató, mely egy int mutatóra mutat:
	int x;
	int* p = &x;
	int** pp = &p; // Itt p egy olyan mutató, mely egy int mutatóra mutat.
	// p-ben x címe, pp-ben p címe van, így talán könyebb elképzelni.
	// Három memóriarekeszünk van: egy x-nek, egy p-nek, egy pp-nek.
	}

	{
	// Itt a pointerek egy olyan tömb, melynek elemei pointerek. Ezek itt még "összevissza" mutatnak.
	int* tomb[10];
	int x = 1;
	tomb[0] = &x; // A tomb első eleme egy pointer, mutasson x-re
	*tomb[0] = 10; // A [] precenedicája nagyobb, mitn a *-é (ezt tudni kell), így ez a következő sorral ekvivalens:
	*(tomb[0]) = 10; // Vedd a tömb első elemét. Ez egy pointer. Ahova ez mutat, írj 10-et (x-re mutat, x értéke 10 lesz).
	// *tomb[1] = 100; // Ahova a tömb első eleme mutat, írjunk 100-at: hibás lenne, mert ezt nem állítottuk érvényes helyre.

	int y = 10;
	tomb[1] = &y;
	int** pt = tomb; // A tomb neve, az első elem címe. Esetünkben egy mutató egy int*-ra, vagyis int** a típusa.

	// A kovetkező sorok ekvivalensek, alkalamazzuk a korábbi szabályunkat (pointerek és tömbök kapcsolata valamint pointer aritmetika)
	// Mind y-ba ír 100-at (mert az első eleme a tömbnek y-ra mutat)
	*tomb[1] = 100;
	*pt[1] = 100;
	**(pt + 1) = 100;
	**(tomb + 1) = 100;
	}
}


