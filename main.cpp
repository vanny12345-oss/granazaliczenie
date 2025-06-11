#include <iostream>
#include <string>
#include <conio.h> 
#include <Windows.h>
using namespace std;
//globalne zmienne
int coins = 1000; //monety
int mnoznik = 1;
bool doubleclick = false; // no czy sie liczy za 2 monety czy nie
bool glock = false; // czy masz glocka
bool kalach = false; // czy masz kalacha
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
    cout << "Twoj mnoznik teraz wynosi:" << mnoznik << endl;
    Sleep(1000);
    system("cls");
}
void sklep() { // dokonczyc sklepy potem
    char input;
    char wybor;
    cout << "1 - Saloon" << endl << "2 - Gunsmith" << endl << "3 - General" << endl << "4 - Doctor" << endl << "5 - Stajnia" << endl;
    input = _getch();
    switch (input) {
    case '1': {
        cout << "Witaj w Saloonie - za 100 monet obetniemy ci wlosy (+1 do mnoznika klikniec) - koszt 100 monet" << endl;
        cout << "t by kupic, n by wrocic do gry" << endl;
        wybor = _getch();
        if (wybor == 't') {
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
        if (wybor == 'n') 
            cout << "Nie marnuj naszego czasu!!!" << endl;
        
        else 
            cout << "Zly guzik. t lub n." << endl;
        
        break;
    }
    case '2': {
        cout << "Witaj u Gunsmitha - tutaj mozesz kupic rozne bronie. (pomagaja z napadami i zwiększaja liczbe monet za klikniecie)" << endl;
        cout << "1 - Rewolwer (pistolet) (+1 do mnoznika klikniec) - koszt 200 monet" << endl << "2 - Karabin (+2 do mnoznika) - koszt 500 monet" << endl;
        char wy = _getch();
        switch (wy) {
        case '1': {
            cout << "Chcesz kupic Rewolwer za 200 monet? (t/n)" << endl;
            input = _getch();
            if (input == 't') {
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
            if (input == 'n') {
                cout << "Nie marnuj mi czasu, gostku! Nie chcesz, to nie!" << endl;
            }
            break;
        }
        case '2': {
            cout << "Chcesz kupic Kalacha za 500 monet? (t/n)" << endl;
            input = _getch(); 
            if (input == 't') {
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
            if (input == 'n') 
                cout << "Nie marnuj mi czasu. Nie, to nie. Bedziesz zalowac." << endl;
            
            else
                cout << "Nie ma takiej opcji. T/N. Wracasz do gry" << endl;
            break;
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
    Sleep(3000);
    system("cls");
}
int main()
{
    //Do dodania: ten cykl nocy i dnai i eventy losowe i zapisywanie
    string input;
    while (true) {
        cout << "Klikacz goscia na dzikim zachodzie" << endl;
        cout << "Wpisz spacje, by dostawac monety, s by wejsc do sklepu, e, by zobaczyc itemki, albo nacisnij q, zeby wyjsc." << endl;
        cout << "Obecna liczba monet : " << coins << " Mnoznik klikniec: " << mnoznik << endl;
        input = _getch(); // przez to liczy sie spacja najlepiej nie tykac bo enter nie moze byc bo sie z sklepem psulo
        if (input == " ") {
            coins = coins + mnoznik;
                system("cls"); // czysci ci ekran zeby sie nie pojawialo non stop to samo
        }
        else if (input == "q") {
            system("cls");
            cout << "Koniec gry, przez cala gre uzyskales "<< coins << " monet" << endl;
            break;
        }
        else if (input == "s") {
            system("cls");  
            sklep();
        }
        else if (input == "e") {
            system("cls");
            itemy();
        }
        else {
            cout << "Guzik ktory nacisnales nie odpowiada za nic" << endl;
        }
    }
    return 0;
}
