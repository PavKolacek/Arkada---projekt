#include "bomb.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <limits>
#include "../fungovani_automatu/animace.h"
#include "../fungovani_automatu/backend_automatu.h"
using namespace std;

int konec_hry8(){
    int rozhodnuti;
    std::cout << "Hra je u konce" << std::endl << "1 -> Hrát znovu\n2-> Chci hrát něco jiného\n 3-> Ukončit a vypnout automat";
    std::cin >> rozhodnuti;
    switch (rozhodnuti)
    {
    case 1:
        bomb();
        break;
    case 2:
        vyber_hry_animace();
        vyber_hry1();
        break;
    case 3:
        vypnuti();
    default:
        break;
    }
    return 0;
}
// TADY jsou *definice* globálních proměnných
atomic<bool> timeUp(false);
int currentDifficulty = 1;
mutex coutMutex;

void countdown(int seconds) {
    while (seconds > 0 && !timeUp) {
        {
            lock_guard<mutex> lock(coutMutex);
            cout << "\033[s";          // uložit kurzor
            cout << "\033[1;1H";       // na začátek
            cout << "\033[2K";         // smazat řádek
            cout << "⏳ Zbývá čas: " << seconds << " s" << flush;
            cout << "\033[u" << flush; // obnovit kurzor
        }
        this_thread::sleep_for(chrono::seconds(1));
        seconds--;
    }

    if (!timeUp) {
        timeUp = true;
        lock_guard<mutex> lock(coutMutex);
        cout << "\033[s";
        cout << "\033[1;1H";
        cout << "\033[2K";
        cout << "⏰ Čas vypršel!";
        cout << "\033[u" << flush;
    }
}

void clearScreen2() {
    cout << "\033[2J\033[1;1H";
}

int showMenu(){
    int choice;

    cout << "=============================\n";
    cout << "💣Vítej ve hře Bomb Defuser💣\n";
    cout << "         MAIN MENU\n";
    cout << "=============================\n";
    cout << "1. Začít hru\n";
    cout << "2. Pravidla\n";
    cout << "3. Obtížnost\n";
    cout << "4. Konec\n";
    cout << "Vyber možnost: ";
    
    cin >> choice;
    return choice;
}

void showRules(){
    clearScreen2();
    cout << "===== 📃PRAVIDLA HRY📃 =====\n";
    cout << "- Nejprve musíš vyřešit hádanku.\n";
    cout << "- Pak se dostaneš k bombě.\n";
    cout << "- Musíš podle nápovědy uhodnout správný drát.\n";
    cout << "- Musíš to vše stihnout do uplynutí času.\n";
    cout << "- Když se netrefíš a nebo ti dojde čas, 💥BOOM💥\n\n";

    cout << "Zadej cokoliv pro vrácení do menu.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string back;
    getline(cin, back); 
}

int chooseDifficulty(){
    clearScreen2();
    int difficulty = 1;
    cout << "==== 😱VÝBĚR OBTÍŽNOSTI😱 ====\n";
    cout << "- 1 = Nejlehčí obtížnost😴\n";
    cout << "- 2 = Střední obtížnost🤔\n";
    cout << "- 3 = Nejtežší obtížnost🤯\n";

    cin >> difficulty;
    while (difficulty < 1 || difficulty > 3)
    {
        cout << "Neplatná obtížnost! Zadej číslo 1-3\n";
        cin >> difficulty;
    }

    currentDifficulty = difficulty;

    cout << "Obtížnost je nastavená na: " << currentDifficulty <<endl;
    cout << "Zadej cokoliv pro vrácení do menu.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string back;
    getline(cin, back); 

    return currentDifficulty;
}

bool generatePuzzle(int difficulty){
    int num1, num2;
    char op;
    int result;
    int answer;
    if(difficulty == 1){
        num1 = (rand() % 50) + 1;
        num2 = (rand() % 50) + 1;
        switch (rand() % 4 + 1)
        {
        case 1:
            result = num1 + num2;
            op = '+';
            break;
        case 2:
            result = num1 - num2;
            op = '-';
            break;

        case 3:
            num1 = (rand() % 10) + 1;
            num2 = (rand() % 10) + 1;
            result = num1 * num2;
            op = '*';
            break;
        case 4:
        {
            num2 = (rand() % 10) + 1;
            int factor = (rand() % 10) + 1; 
            num1 = num2 * factor; 
            result = num1 / num2;
            op = '/';
            break;
        }
        }
    }else if(difficulty == 2){
        num1 = (rand() % 300) + 1;
        num2 = (rand() % 300) + 1;
        switch (rand() % 5 + 1)
        {
        case 1:
            result = num1 + num2;
            op = '+';
            break;
        case 2:
            result = num1 - num2;
            op = '-';
            break;
        case 3:
            num1 = (rand() % 50) + 1;
            num2 = (rand() % 50) + 1;
            result = num1 * num2;
            op = '*';
            break;
        case 4: {  
            num2 = (rand() % 50) + 1;             
            int maxFactor = 300 / num2;            
            int factor = (rand() % maxFactor) + 1; 
            num1 = num2 * factor;                  
            result = factor;                        
            op = '/';
            break;
        }
        case 5: 
            num1 = (rand() % 20) + 1;
            result = num1 * num1;
            op = '^';
            num2 = 2;
            break;
        }
    }else if(difficulty == 3){
        switch (rand() % 5 + 1)
        {
        case 1:{
            num2 = (rand() % 181) + 20;
            int factor = (rand()  % 16) + 5;
            num1 = num2 * factor;
            result = num1 / num2;
            op = '/';
            break;
        }
        case 2:
            num1 = (rand() % 900) + 100;
            num2 = (rand() % 11) + 5;
            result = num1 * num2;
            op = '*';
            break;
        case 3:
            num1 = (rand() % 9) + 2;
            result = num1 * num1 * num1;
            op = '^';
            num2 = 3;
            break;
        case 4:
            num1 = (rand() % 500) + 500; 
            num2 = (rand() % 500) + 500;   
            op = '+';
            result = num1 + num2;
            break;
        case 5:
            num1 = (rand() % 1000) + 200; 
            num2 = (rand() % 300) + 50;    
            op = '-';
            result = num1 - num2;
            break;
        }
    }

    cout << "Vyřeš tuto hádanku: " << num1 << " " << op << " " << num2 << endl;
    cout << "Tvoje odpověď: ";
    cin >> answer;
    
    return answer == result;
}

bool saveChance(int correctWire){
    int choice;
    cin >> choice;
    return choice == correctWire;
}

bool defuseBomb(int difficulty){
    int wireCount;
    vector<string> wireColors = {"cervena", "modra", "zelena", "zluta", "cerna", "bila", "fialova"};

    map<string, string> easyHints = {
        {"cervena", "Barva jako jablko 🍎"},
        {"modra", "Barva jako obloha nebo moře 🌊"},
        {"zelena", "Barva jako listy stromů 🌿"},
        {"zluta", "Barva jako slunce ☀️"},
        {"cerna", "Barva jako noc 🌙"},
        {"bila", "Barva jako sníh ❄️"},
        {"fialova", "Barva jako lilek 🍆"}
    };

    map<string, string> mediumHints = {
        {"cervena", "Barva, která často znamená STOP nebo nebezpečí"},
        {"modra", "Barva vody a klidu"},
        {"zelena", "Barva přírody, často spojovaná s bezpečím"},
        {"zluta", "Barva často spojovaná s pozor nebo varováním"},
        {"cerna", "Barva noci a tajemství"},
        {"bila", "Barva čistoty a začátku"},
        {"fialova", "Barva králů a magie"}
    };

    map<string, string> hardHints = {
        {"cervena", "Barva, která symbolizuje vášeň, hněv a krev"},
        {"modra", "Barva nekonečných hlubin, klidu a smutku"},
        {"zelena", "Barva života, růstu a všeho, co dýchá"},
        {"zluta", "Barva, která září a udává tempo světu"},
        {"cerna", "Barva tajemství, konce a stínů"},
        {"bila", "Barva prázdnoty, světla a nevinnosti"},
        {"fialova", "Barva moci, mystiky a aristokracie"}
    };

    map<string, string> secondHints = {
        {"cervena", "#FF0000 a nebo (255,0,0)"},
        {"modra", "#0000FF a nebo (0,0,255)"},
        {"zelena", "#008000 a nebo (0,128,0)"},
        {"zluta", "#FFFF00 a nebo (255,255,0)"},
        {"cerna", "#000000 a nebo (0,0,0)"},
        {"bila", "#FFFFFF a nebo (255,255,255)"},
        {"fialova", "#800080 a nebo (128,0,128)"}
    };

    if(difficulty == 1){
        wireCount = 3;
    }else if(difficulty == 2){
        wireCount = 5;
    }else{
        wireCount = 7;
    }

    wireColors.resize(wireCount);
    int correctWire = (rand() % wireCount) + 1;
    string correctColor = wireColors[correctWire - 1];

    cout << "Super zvládl si překonat první část bomby🤩" << endl;
    cout << "Zde máš " << wireCount << "drátů v bombě.👀\n";
    cout << "Nápověda ke správnému drátu:\n";
    
    if(difficulty == 1){
        cout << easyHints[correctColor] << "\n\n";
    }else if(difficulty == 2){
        cout << mediumHints[correctColor] << "\n\n";
    }else{
        cout << hardHints[correctColor] << "\n\n";
    }
    
    vector<string> colorCodes = {
        "\033[31m",
        "\033[34m",
        "\033[32m",
        "\033[33m",
        "\033[30m",
        "\033[37m",
        "\033[35m"
    };

    for (int i = 1; i <= wireCount; i++)
    {
         cout << i << ". " << colorCodes[i-1] << wireColors[i-1] << "\033[0m" << endl;
    }

    cout << "Jaký chceš přeštípnout?(⊙_⊙;) \n";
    
    int choice;
    cin >> choice;

    if(choice == correctWire) return true;

    bool secondChance = false;
    if(difficulty == 3) secondChance = (rand() % 100) < 50;

    if(!secondChance) return false;

    cout << "\nŠpatně! Ale máš poslední šanci!\n";
    cout << "Dodatečná nápověda: " << secondHints[correctColor] << endl << endl;

    for(int i = 1; i <= wireCount; i++){
        cout << i << ". " << colorCodes[i-1] << wireColors[i-1] << "\033[0m" << endl;
    }

    return saveChance(correctWire);
}

void startGame(int difficulty){
    clearScreen2();
    int timer;
    
    if (difficulty == 1) {
        timer = 30;
    } else if (difficulty == 2) {
        timer = 60;
    } else {
        timer = 90;
    }

    timeUp = false;
    thread t(countdown, timer);
    
    cout << "===== 🧩 ZAČÍNÁME! 🧩 =====\n";
    cout << "Obtížnost: " << difficulty << endl;
    cout << "Nejprve musíš vyřešit hádanku...\n\n";
    
    if(!generatePuzzle(difficulty)){
        timeUp = true;
        
        cout << "💥BOOM💥\n";
        cout << "Odpověděl si špatně!!(╯°□°）╯︵ ┻━┻\n\n";

        t.join();
        cout << "Zadej cokoliv pro vrácení do menu.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        string back;
        getline(cin, back); 
        return;
    }

    clearScreen2();
    cout << "✅Správně✅\n";
    cout << "Dostal jses dál!💦\n\n";

    if(timeUp || !defuseBomb(difficulty)){
        timeUp = true;

        cout << "💥BOOM💥\n";
        cout << "Špatný kabel!!(╯°□°）╯︵ ┻━┻\n\n";
        
        t.join();
        cout << "Zadej cokoliv pro vrácení do menu.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        string back;
        getline(cin, back); 
        return;
    }

    cout << "✅Správně✅\n";
    cout << "Zneškodnil si bombu!( ´･･)ﾉ(._.`)\n\n";
    timeUp = true;
    t.join();

    cout << "Zadej cokoliv pro vrácení do menu.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string back;
    getline(cin, back); 
}

int bomb(){
    srand(time(0));
    while (true) {
        clearScreen2();
        int choiceMenu = showMenu();

        switch (choiceMenu)
        {
            case 1:
                startGame(currentDifficulty);
                break;

            case 2:
                showRules();
                break;

            case 3:
                chooseDifficulty();
                break;

            case 4:
                cout << "Ukončuji hru. Díky za hraní!\n";
                return 0; 

            default:
                cout << "Neplatná volba!\n";
        }

        cout << "\n";
    }
    konec_hry8();
}
