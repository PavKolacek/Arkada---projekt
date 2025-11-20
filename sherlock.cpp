#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Lokace {
    public:
    string nazev;
    string popis;
    vector<string>sousede;
    string dukaz;
    string postava;
    string rozhovor;

    Lokace(string n, string p, vector<string> s, string d = "", string osoba = "", string r = "")
        : nazev(n), popis(p), sousede(s), dukaz(d), postava(osoba), rozhovor(r) {}

    void zobraz_popis() {
        cout << "\n== " << nazev << " ==\n" << popis << "\n" << endl;
    }

    void zobraz_menu() {
        cout << "Co chces delat?"<< endl;
        cout << "1. Prozkoumat" << endl;
        if (postava != "") cout << "2. Mluvit s " << postava << endl;
        cout << "3. Jit jinam" << endl;
        cout << "4. Konec hry" << endl;
    }

    void prozkoumat() {
        if (dukaz != "")
            cout << "Prozkoumavas okoli... " << dukaz << endl;
        else
            cout << "Nevidis nic zvlatniho." << endl;
    }

    void mluvit() {
        if (postava != "")
            cout << postava << ": \"" << rozhovor << "\"" << endl;
        else
            cout << "Nikdo tu neni." << endl;
    }
    void zobraz_sousedy() {
        cout << "\nKam chces jit dal?" << endl;
        for (int i = 0; i < sousede.size(); i++) {
            cout << i + 1 << ". " << sousede[i] << endl;
        }
    }
};

void namesti() {
    cout << R"(
Nachazis se na malem zasnezenem namesti,
kteremu dominuje velky ozdobeny strom.
Ve vzduchu je citit vune perniku, smazeneho kapra a svaraku.
Lide jsou ovsem nervozni a odevsad se ozyva septani. Zvon o pulnoci nezavonil a zvonik zmizel.
)" << endl;
}
void kostel() {
    cout <<R"(
Kostel sv. Gabriela je stary kamenny kostel.
Sala z nej chlad, ktery jen umocnuje pocit, ze skyta tajemstvi.
Jedine svetlo je svetlo svici a pochodni. V pravem rohu se nachazi masivni casem omsele dvere.)" << endl;
}
void fara() {
    cout << R"(
Fara je mala stisenna mistnost s psacim stolem, krucifixem a hromadouknih.
Mistnosti se tahne vune vosku a stareho pergamenu.)" << endl;
}
void hospoda() {
    cout << R"(Hospoda je jako kazda jina rusna rozlehla mistnost s par okny a nekolika stoly se zidlemi.
Z venku je videt teple svetlo linouci se z oken.Za zdech visi stare fotografie mesta.)" << endl;
}
void vez() {
    cout << R"(Do veze kostela vede uzke tocite schodiste. Pri kazdem kroku lze pozorovat zvedajici se prach."
V samotne vezi panuje hrobove ticho. Zaroven se zde nachazi znamky po boji.)" << endl;
}
void krypta() {
    cout << R"(Do krypty vedou kamenne schody dolu.)";
}
void archiv() {
    cout << R"(Nachazis se v teple mistnosti plne knih, kronik a starych dokumentu.)";
}

void D1_latka() {
    cout << R"(Na ramu dveri je roztrzeny kus cerne latky. Vypada draze, mozna soucast kabatu, nebo habitu.
Na okraji je neco vysiteho. Mozna maly zlaty kriz.)" << endl;
}

void D3_spis() {
    cout << R"(V krabici najdes sadu starych dopisu mezi byvalym fararem a starostou.

'Musime to ututlat. Lide by to neunesli.
Smrt ucednika pri odlevani zvonu nesmi vyjit najevo.
Napiseme, ze sel o nehodu pri praci a tim to skonci.'

'Zvonar o tom vi prilis mnoho. Nema pristup do podzemnich prostor,
takze se tam nedostane bez klice. Klic necham u sebe.'

'Jestli se o tom znovu zmimi, zakrocime.'

Mezi dopisy lezi stary mosazny klic s vyrazenym pismenem K.
Vypada to jako klic k podzemni krypte pod kostelem.
)" << endl;
}

void D4_denik() {
    cout << R"( Farar se na chvili odejde. Vsimnes si, ze na stole lezi stary sesit s tvrdymi deskami. Pismo je upravene, pevne.

'Nasel jsem stare dokumenty.
Nejdriv jsem tomu nechtel verit. Vse bylo zameteno, nikde o tom neni ani slovo.

Rekl jsem to F. Rikal mi, at do toho neryju, pry je to davno a lidem by to jen ublizilo.
Ale ja nemuzu mlcet. Nechci zit ve meste plnem lzi.

Zitra to reknu. Vsem. Pri pulnocnim zvoneni.'

Posledni zapis je kratky, kostrbaty:

'F. se zlobil. Rikal, ze tomu nerozumim.
Ale ja musim rict pravdu.'
)" << endl;
}

void D5_zapas() {
    cout << R"(Na kamenne podlaze je rozbita lucerna a tmava skvrna.
Kovove zabradli je ohnute.)" << endl;
}

void D6_telo() {
    cout << R"(Kamenne schody vedou dolu do tmy. Nachazi se zde spoustu hrobek.
Vice vzadu je nahrnuta hlina. Ocividne na rychlo nahazena. Pod hlinou je telo.
Pracovni odev, ruce zkrizene, oci zavrezene. Nekdo ho narychlo pohrbil. V ruce drzi pomačkany pergamen. Pismo je roztrepane, ale citelne:

'Nemuzu uz ustupovat. Lide musi vedet, co se stalo pri vyrobe zvonu.
Nikdo uz nesmi mlcet.

Jestli se nevratim nahoru, at tenhle dopis najdou.

Pravda se neda schovat navzdy.'
 )" << endl;
}

void svedectvi_Anna() {
    cout << R"(Byla jsem v kostele pred pulnoci. Modlila jsem se.
A pak jsem slysela vykrik. Znelo to z veze.
Ale kdyz jsem tam prisla, bylo ticho. Myslela jsem, ze se mi to zdalo.)" << endl;
}

void info_kovar() {
    cout << R"(Muj praded pomahal s odlevanim zvonu.
Rikal, ze ten zvon byl proklety.
Pri vyrobe pry zemrel mlady ucen a pak to vsechno zakryli.
Nechteli aby mestem otrasl dalsi skandal.)" << endl;
}

bool hra_bezi = true;
bool krypta_odemcena = false;
bool naselTelo = false;
bool naselDenik = false;
bool viOZapase = false;
bool viONehode = false;
bool cetlDopisy = false;
bool naselLatku = false;

void vypoved_farare() {

    if (naselTelo) {
        cout << "Farar je bledy a odvraci zrak. 'To musi byt omyl... ja... ja o tom nic nevim.'" << endl;
        return;
    }

    if (naselDenik) {
        cout << R"(Hrac: "Cetl jsem zvonikuuv denik."
Farar: "On psal spoustu veci. Ctil se ukrivdeny.
Prehanel, vymyslel si.
Snazil jsem se s nim mluvit, ale posledni tydny nebyl v poradku."
)" << endl;
        return;
    }

    if (cetlDopisy || viONehode) {
        cout << R"(Hrac: "Nasel jsem dopisy z archivu."
Farar: "Slysim, co lide rikaji...
Ano, v minulosti se staly veci, ktere by otrasyly mestem.
Smrt pri odlevani zvonu byla zametena pod koberec.

Ale to nema nic spolecneho se zvonikem.
Byl podrazdeny, pohadal se s lidmi.
Mozna se mu neco prihodilo. Ja nevim."
)" << endl;
        return;
    }

    if (naselLatku) {
        cout << R"(Hrac: "Videl jset v posledich dnech zvonika? Nasel jsem kousek cerne latky. Patril vam?"
Farar: "To bude muj plast...
Byl jsem tam vecer. Mluvili jsme spolu... kratce.
Mozna jsem se o neco zachytil, nevim.
Nedelejte z toho vic, nez to je."
)" << endl;
        return;
    }

    cout << R"(Farar: "Zdravim vas.
Pokud hledate zvonika, nevidel jsem ho od vcerejsiho odpoledne.
Byl posledni dobou dost uzavreny.
Snazil jsem se s nim mluvit, ale nic nerekl.
Snad se to brzy vysvetli.")" << endl;
}

void zpracujDukaz(string kod);

void obvineni() {
    cout << R"(
1. Zvonika zabil farar.
2. Zvonika zabil kovar.
3. Zvonik spadl sam.
)" << endl;

    int moznost;
    cin >> moznost;

    if (moznost == 1) {
        cout << R"(
Farar se zhluboka nadychne a sklopi oci.
"Dobre... uz nema cenu nic skryvat.

Ano, pohadali jsme se ve vezi.
Bylo to kvuli tem dopisum a minulosti mesta.
Chtel je zverejnit pri pulnocnim zvoneni...

Chytil se zabradli... uklouzl.
Nebyl to umysl.

Ale bal jsem se. Nikdo by mi neuveril.
Schoval jsem telo do krypty.
Rano uz bylo pozde."
)" << endl;
        cout << "Spravne, vyresil jsi zahadu!\n";
        hra_bezi = false;
    }
    else {
        cout << "Nene, zkus to znovu.\n";
    }
}

int main() {
    string aktualni_misto = "Namesti";

    // Vytvoření všech lokací
    Lokace namestiL("Namesti", "Namesti ve meste Svaty Kriz", {"Kostel", "Hospoda", "Fara", "Archiv"}, "", "Anna");
    Lokace kostelL("Kostel", "Kostel sv. Gabriela", {"Vez", "Fara", "Namesti"}, "D1");
    Lokace faraL("Fara", "Fara u kostela", {"Kostel", "Namesti", "Krypta"}, "D4", "farar");
    Lokace hospodaL("Hospoda", "Hospoda u Krize", {"Namesti"}, "", "kovar");
    Lokace archivL("Archiv", "Mestsky archiv", {"Namesti"}, "D3");
    Lokace vezL("Vez", "Kostelni vez", {"Kostel", "Namesti"}, "D5");
    Lokace kryptaL("Krypta", "Podzemni krypta pod kostelem", {"Fara"}, "D6");

    cout << "Je Stedry den. Zasnezene mestecko Svaty Kriz je tiche. Az prilis tiche.\n"
         << "Vcera o pulnoci mel zaznit stary zvon z veze kostela sv. Gabriela,\n"
         << "ale tentokrat nezaznel. Poprve po sto letech.\n"
         << "Tvym ukolem je prijit na to proc.\n" << endl;

    cout << "Chces se seznamit s postavami?\n1. Ano\n2. Ne" << endl;
    int volba_uvod;
    cin >> volba_uvod;

    if (volba_uvod == 1) {
        cout << R"(
V tomto meste ziji tri lide, kteri ke zvoniku meli nejbliz.
Kazdy z nich ho znal jinak a kazdy z nich neco taji.

Anna – mlada divka z Namesti.
Ticha, opatrna, ale vsimava. Chodi casto do kostela a byva tam i vecer, kdyz je ve meste ticho.
Pusobi vystresene, ale neni lhar. Co vidi, to rekne.

Kovar – tvrdy chlap, ktery zna historii mesta lepe nez leckdo z archivu.
Je primy, mozna az prilis, a nerad mluvi o minulosti sve rodiny.
Jeho pradedecek pracoval na vyrobe zvonu a nesel o tom prijemne veci.

Farar – vazeny muz, ktery vede kostel uz mnoho let.
Sverujici, klidny, ale posledni dny pusobi napjaty.
Znal zvonika nejdele a s nikym o nem nemluvi tak ochotne, jak by mel.

A nakonec zvonik – mlady muz, oddany sve praci.
Posledni tyden se choval zvlastne.
Nikdo nevi proc, ale rikal, ze na Stedry den rekne neco duleziteho.

Dnes v noci nezaznel zvon.
A nekdo vi proc.
)" << endl;

        cout << "\nStiskni 1, pokud chces pokracovat do mesta." << endl;
        int pokracuj;
        cin >> pokracuj;
    }


    while (hra_bezi) {
        // Zavolání funkce s popisem podle aktuálního místa
        if (aktualni_misto == "Namesti") namesti();
        else if (aktualni_misto == "Kostel") kostel();
        else if (aktualni_misto == "Fara") fara();
        else if (aktualni_misto == "Hospoda") hospoda();
        else if (aktualni_misto == "Archiv") archiv();
        else if (aktualni_misto == "Vez") vez();
        else if (aktualni_misto == "Krypta") krypta();

        // Najdi odpovídající objekt Lokace
        Lokace* aktualni = nullptr;
        if (aktualni_misto == "Namesti") aktualni = &namestiL;
        else if (aktualni_misto == "Kostel") aktualni = &kostelL;
        else if (aktualni_misto == "Fara") aktualni = &faraL;
        else if (aktualni_misto == "Hospoda") aktualni = &hospodaL;
        else if (aktualni_misto == "Archiv") aktualni = &archivL;
        else if (aktualni_misto == "Vez") aktualni = &vezL;
        else if (aktualni_misto == "Krypta") aktualni = &kryptaL;

        if (naselTelo && naselDenik && cetlDopisy && viOZapase) {
            cout << "Mas dost dukazu. Chces ucinit zaver?\n1. Ano\n2. Ne\n";
            int volba;
            cin >> volba;

            if (volba == 1) {
                obvineni();
                continue;
            }
        }

        bool zustat = true;
        int akce;

        while (zustat){
            aktualni->zobraz_menu();
            cin >> akce;

            switch (akce){
                case 1: {
                    if (aktualni->dukaz != "")
                        zpracujDukaz(aktualni->dukaz);
                    else
                        aktualni->prozkoumat();
                    break;
                }

                case 2: {
                    if (aktualni->postava == "farar") {
                        vypoved_farare();
                    }
                    else if(aktualni->postava == "kovar") {
                        info_kovar();
                    }
                    else if(aktualni->postava == "Anna") {
                        svedectvi_Anna();
                    }
                    else{cout<< "Nikdo tu neni" << endl;}
                    break;
                }

                case 3: {
                    aktualni->zobraz_sousedy();
                    int cislo;
                    cin >> cislo;
                    if (cislo >= 1 && cislo <= aktualni->sousede.size()) {

                        string cil = aktualni->sousede[cislo - 1];

                        if (cil == "Krypta" && !krypta_odemcena) {
                            cout << "Dvere do krypty jsou zamcene. Potrebujes klic." << endl;
                            continue;   // zustan v aktualni lokaci
                        }

                        aktualni_misto = cil;
                    }
                    else {
                        cout << "Neplatna volba." << endl;
                    }
                    zustat = false;
                    break;
                }

                case 4: {
                    hra_bezi = false;
                    cout << "\nHra skoncila. Dekujeme, ze jsi hral(a)!" << endl;
                    return 0;
                }
            }
        }
    }
}

void zpracujDukaz(string d) {
    if (d == "D1") {
        D1_latka();
        naselLatku = true;
    }
    else if (d == "D3") {
        D3_spis();
        cetlDopisy = true;
        krypta_odemcena = true;   // 
        cout << "\nMezi dopisy jsi nasel i stary klic od podzemnich prostor kostela." << endl;
    }
    else if (d == "D4") {
        D4_denik();
        naselDenik = true;
    }
    else if (d == "D5") {
        D5_zapas();
        viOZapase = true;
    }
    else if (d == "D6") {
        D6_telo();
        naselTelo = true;
    }
}