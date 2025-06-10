#include <iostream>
#include <string>
#include <conio.h> 
#include <Windows.h>
using namespace std;
//globalne zmienne
int coins = 100; //monety
bool doubleclick = false; // no czy sie liczy za 2 monety czy nie
void sklep() { // mozna jeszcze rozne sklepy zrobic itp ale to taka podstawka 
    char input;
    char wybor;
    cout << "Wpisz cyfre od 1 do 10 i pokaze ci sie przedmiot piekny" << endl;
    input = _getch();
    switch (input) {
    case '1': {
        cout << "Entery sie licza jako 2 monety - koszt 100 monet" << endl;
        cout << "t by kupic, n by wrocic do giereczki" << endl;
        wybor = _getch();
        if (wybor == 't') {
            if (coins > 100) {
                cout << "Masz teraz double clicka gostku" << endl;
                doubleclick = true;
                coins = coins - 100;
            }
            else {
                cout << "Nie masz wystarczajaco monet jeszcze" << endl;
            }
        }
        if (wybor == 'n') {
            cout << "No nie to nie dobra nie ja tam szanuje" << endl;
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
    // te komunikaty do zmienienia na razie robie zeby dzialalo itd
}
int main()
{
    //Do dodania: ten cykl nocy i dnai i eventy losowe i zapisywanie
    string input;
    while (true) {
        cout << "Klikacz goscia na dzikim zachodzie" << endl;
        cout << "Wpisz spacje, by dostawac monety, s by wejsc do sklepu, albo nacisnij q, zeby wyjsc." << endl;
        cout << "Obecna liczba monet : " << coins << endl;
        input = _getch(); // przez to liczy sie spacja najlepiej nie tykac bo enter nie moze byc bo sie z sklepem psulo
        if (input == " ") {
            if (doubleclick) {
                coins += 2;
                system("cls");
            }
            else {
                coins++;
                system("cls"); // czysci ci ekran zeby sie nie pojawialo non stop to samo
            }
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
        else {
            cout << "Guzik ktory nacisnales nie odpowiada za nic" << endl;
        }
    }
    return 0;
}
