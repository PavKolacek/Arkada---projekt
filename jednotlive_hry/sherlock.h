#pragma once

int konec_hry3();

#include <string>
#include <vector>

using std::string;
using std::vector;
class Lokace {
public:
    string nazev;
    string popis;
    vector<string> sousede;
    string dukaz;
    string postava;
    string rozhovor;

    // Konstruktor
    Lokace(string n, string p, vector<string> s, string d = "", string osoba = "", string r = "");

    // Metody (jen deklarace)
    void zobraz_popis();
    void zobraz_menu();
    void prozkoumat();
    void mluvit();
    void zobraz_sousedy();
};

void namesti();

void kostel();

void fara();

void hospoda();

void vez();

void krypta();

void archiv();

void D1_latka();

void D3_spis();

void D4_denik();

void D5_zapas();

void D6_telo();

void svedectvi_Anna();

void info_kovar();

extern bool hra_bezi;

extern bool krypta_odemcena;

extern bool naselTelo;

extern bool naselDenik;

extern bool viOZapase;

extern bool viONehode;

extern bool cetlDopisy;

extern bool naselLatku;

void vypoved_farare();

void zpracujDukaz();

void obvineni();

void zpracujDukaz();

int sherlock();