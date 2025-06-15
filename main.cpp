#include <iostream>
#include <string>
#include <conio.h> 
#include <Windows.h>
#include <time.h>
using namespace std;
//globalne zmienne
int coins = 1000; //monety
int mnoznik = 1;
int kliknieciadoeventu;
bool aktywnyevent = false;
bool doubleclick = false; // no czy sie liczy za 2 monety czy nie
bool glock = false; // czy masz glocka
bool kalach = false; // czy masz kalacha
bool czekolada = false;// czy masz czekolade
bool pasta = false; 
//czy dodano mnoznik, zeby tylko raz dzialalo
bool kalachm = false;
bool glockm = false;
bool doubleclickm = false;
//funkcje
void jakiMnoznik() {
    if (doubleclick && doubleclickm == false) {
        mnoznik++;
        doubleclickm = true;
    }
    if (glock && glockm == false) {
        mnoznik++;
        glockm = true;
    }
    if (kalach && kalachm == false) {
        mnoznik = mnoznik + 2;
        kalachm = true;
    }
    cout << "Twoj mnoznik teraz wynosi: " << mnoznik << endl;
    Sleep(1000);
    system("cls");
}
void sklep() {
    char input;
    char wybor;
    cout << "1 - Saloon" << endl << "2 - Gunsmith" << endl << "3 - General";
    input = _getch();
    switch (input) {
    case '1': {
        cout << "Witaj w Saloonie - za 100 monet obetniemy ci wlosy (+1 do mnoznika klikniec) - koszt 100 monet" << endl;
        cout << "t by kupic, n by wrocic do gry" << endl;
        wybor = _getch();
        if (wybor == 't' || wybor == 'T') {
            if (doubleclick)
                cout << "Juz masz obciete wlosy, tylko raz mozesz" << endl;
            if (coins > 100) {
                cout << "Obciales sobie wlosy - twoje klikniecia teraz licza sie podwojnie" << endl;
                doubleclick = true;
                coins = coins - 100;
            }
            else {
                cout << "Nie masz wystarczajaco monet jeszcze" << endl;
            }
        }
        if (wybor == 'n' || wybor == 'N')
            cout << "Nie marnuj naszego czasu!!!" << endl;

        else
            cout << "Zly guzik. t lub n." << endl;

        break;
    }
    case '2': {
        cout << "Witaj u Gunsmitha - tutaj mozesz kupic rozne bronie. (pomagaja z napadami i zwiększaja liczbe monet za klikniecie)" << endl;
        cout << "1 - Rewolwer (pistolet) (+1 do mnoznika klikniec) - koszt 200 monet" << endl << "2 - Karabin (+2 do mnoznika) - koszt 500 monet" << endl;
        char wy = _getch();
        if (wy == '1') {
            cout << "Chcesz kupic Rewolwer za 200 monet? (t/n)" << endl;
            input = _getch();
            if (input == 't' ||input == 'T') {
                if (coins > 200) {
                    coins = coins - 200;
                    glock = true;
                    cout << "Otrzymales rewolwer." << endl;
                }
                else if (glock)
                    cout << "Juz masz rewolwer, nie mozesz miec dwoch" << endl;

                else
                    cout << "Nie masz wystarczajaco monet" << endl;


            }
            else if (input == 'n' || input == 'N') {
                cout << "Nie marnuj mi czasu, gostku! Nie chcesz, to nie!" << endl;
            }
            else {
                cout << "T/N!!!" << endl;
            }
        }
        else if (wy == '2') {
            cout << "Chcesz kupic Kalacha za 500 monet? (t/n)" << endl;
            input = _getch();
            if (input == 't' || input == 'T') {
                if (coins > 500) {
                    coins = coins - 500;
                    kalach = true;
                    cout << "Otrzymales kalacha" << endl;
                }
                else if (kalach)
                    cout << "Juz masz kalacha, nie mozna miec dwoch." << endl;


                else
                    cout << "Nie masz tyle monet." << endl;

            }
            else if (input == 'n' || input == 'N')
                cout << "Nie marnuj mi czasu. Nie, to nie. Bedziesz zalowac." << endl;

            else
                cout << "Nie ma takiej opcji. T/N. Wracasz do gry" << endl;
        
        }
        break;
    }
    case '3': {
        cout << "Witaj w Generalu! Tutaj mozesz kupic produkty, ktore pomoga ci na krotki czas." << endl;
        cout << "1 - Czekolada (podwaja zysk na kolejne 20 klikniec) - 50 monet" << endl << "2 - Pasta do butów (dodaje 5 monet do zysku przez kolejne 10 klikniec) - 40 monet" << endl << "3 - Fasola w puszce (zmniejsza liczbe potrzebnych klikniec do eventu o 10) - 150 monet " << endl;
        input = _getch();
        if (input == '1') {
            cout << "Czy na pewno chcesz kupic czekolade? (t/n)" << endl;
            char wy = _getch();
            if (wy == 't' || wy == 'T') {
                if (coins > 50) {
                    czekolada = true;
                    cout << "Dostales czekolade smacznego" << endl;
                }
                else {
                    cout << "Ty biedaku nie stac cie na czekolade" << endl;
                }
            }
            else if (wy == 'n' || wy == 'N') {
                cout << "No to nie kupisz czekolady jak nie chcesz!!!" << endl;
            }
            else {
                cout << "Zly wybor. T/N." << endl;
            }
        }
        else if (input == '2') {
            cout << "Czy chcesz kupic paste do butow? (t/n)" << endl;
            char wy = _getch();
                if(wy == 't' || wy == 'T') {
                    if (coins > 40) {
                        cout << "Kupiles paste do butow, mozesz teraz buty smarowac" << endl;
                        pasta = true;
                    }
                    else {
                        cout << "Nie stac cie na paste" << endl;
                    }
            }
                else if (wy == 'n' || wy == 'N') {
                    cout << "No nie to nie!" << endl;
                }
                else {
                    cout << "Zly wybor T/N" << endl;
                }
        }
        else if (input == '3') {
            cout << "Czy chcesz kupic fasolke? (T/N)" << endl;
            char wy = _getch();
                if (wy == 't' || wy == 'T') {
                    if (coins > 150 && kliknieciadoeventu > 20) {
                        cout << "Fasolka odjela 10 klikniec do wymogu!" << endl;
                        kliknieciadoeventu = kliknieciadoeventu - 10;
                    }
                    else if (kliknieciadoeventu <= 20) {
                        cout << "Masz tylko " << kliknieciadoeventu << "klikniec do eventu, fasolka juz nie zadziala." << endl;
                        cout << "Porada: Fasolka dziala tylko powyzej 20 klikniec do eventu" << endl;
                    }
                    else if (coins < 150) {
                        cout << "Masz za malo monet." << endl;
                    }
                }
                else if (wy == 'n' || wy == 'N') {
                    cout << "Masz za malo monet." << endl;
                }
                else {
                    cout << "Zly wybor. T/N" << endl;
                }
        }
        break;
    }
    default: {
        cout << "Nie ma takiego przedmiotu (jeszcze)" << endl;
        break;
    }
    }
           Sleep(1000);
           system("cls");
           jakiMnoznik();
           // te komunikaty do zmienienia na razie robie zeby dzialalo itd
    }
    void itemy() {
    if (doubleclick) 
        cout << "Doubleclick - posiadany" << endl;
    
    else 
        cout << "Doubleclick - nie posiadany" << endl;
    
    if (glock) 
        cout << "Rewolwer - posiadany" << endl;
    else 
        cout << "Rewolwer - nie posiadany" << endl;
    if (kalach) 
        cout << "Kalach - posiadany" << endl;
    else 
        cout << "Kalach - nie posiadany" << endl;
    if (czekolada)
        cout << "Czekolada - posiadana" << endl;
    else
        cout << "Czekolada - nie posiadana" << endl;
    if (pasta)
        cout << "Pasta do butow - posiadana" << endl;
    else
        cout << "Pasta do butow - nie posiadana" << endl;
    Sleep(3000);
    system("cls");
}
    int main()
    {
        int czekoladakliki = 0;
        int pastakliki = 0;
        srand(time(NULL));
        kliknieciadoeventu = rand() % 100;
        int losowyevent = 1;//(rand() % 5) + 1;
    char input;
    while (true) {
        cout << "Klikacz goscia na dzikim zachodzie" << endl;
        cout << "Wpisz spacje, by dostawac monety, s by wejsc do sklepu, e, by zobaczyc itemki, albo nacisnij q, zeby wyjsc." << endl;
        cout << "Obecna liczba monet : " << coins << " Mnoznik klikniec: " << mnoznik << " Nastepne wydarzenie losowe za: " << kliknieciadoeventu << " klikniec" << endl;
        if (czekolada)
            cout << "Klikniecia z czekolada: " << czekoladakliki << " wylacza sie przy 20 kliknieciach" << endl;
        else if (pasta)
            cout << "Klikniecia z pasta: " << pastakliki << " wylacza sie przy 10 kliknieciach" << endl;
        input = _getch(); // przez to liczy sie spacja najlepiej nie tykac bo enter nie moze byc bo sie z sklepem psulo
        if (input == ' ' && !aktywnyevent) {
            if (czekolada) {
                if (czekoladakliki < 20) {
                    coins = coins + mnoznik * 2;
                    czekoladakliki++;
                }
                if (czekoladakliki >= 20) {
                    czekolada = false;
                }
            }
            else if (pasta) {
                if (pastakliki < 10) {
                    coins = (coins + mnoznik) + 5;
                    pastakliki++;
                }
                if (pastakliki >= 10) {
                    pasta = false;
                }
            }

            else if (aktywnyevent) {
                cout << "Nie mozesz teraz klikac - event jest aktywny" << endl;
            }
            else
                coins = coins + mnoznik;
            kliknieciadoeventu = kliknieciadoeventu - 1;
            system("cls");
            if (kliknieciadoeventu <= 0) {
                switch (losowyevent) {
                case 1: {
                    int szansa;
                    cout << "Napad na dylizans - do zdobycia 1000 monet." << endl;
                    aktywnyevent = true;
                    if (kalach && glock) {
                        szansa = rand() % 10;
                    }
                    else if (glock) {
                        szansa = rand() % 25;
                    }
                    else if (kalach) {
                        szansa = rand() % 20;
                    }
                    else
                        szansa = rand() % 50;
                    if (szansa == 0) {
                        cout << "Napad sie udal - dostajesz 1000 monet." << endl;
                        coins = coins + 1000;
                        Sleep(3000);
                        system("cls");
                        aktywnyevent = false;
                        kliknieciadoeventu = rand() % 100;
                    }
                    else {
                        cout << "Nie udalo sie wykonac napadu. Zostajesz z niczym, a do tego kare 100 monet." << endl;
                        coins = coins - 100;
                        Sleep(3000);
                        system("cls");
                        aktywnyevent = false;
                        kliknieciadoeventu = rand() % 100;

                    }
                }
                }
            }
        }
        else if (input == 'q') {
            system("cls");
            cout << "Koniec gry, przez cala gre uzyskales "<< coins << " monet" << endl;
            break;
        }
        else if (input == 's') {
            system("cls");  
            sklep();
        }
        else if (input == 'e') {
            system("cls");
            itemy();
        }
        else {
            cout << "Guzik ktory nacisnales nie odpowiada za nic" << endl;
        }
    }
    return 0;
}
