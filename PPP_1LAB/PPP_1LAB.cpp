#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

char BufRus[256];
char* Rus(const char* text)
{
    CharToOemA(text, BufRus);
    return BufRus;
}

bool isNumber(string str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

class airport {
private:
    string Name;
    int TicketCost;
    int AllSpace;
    int SoldTickets;
public:
    airport() : Name("DefaultAirport"), TicketCost(3500), AllSpace(850), SoldTickets(30)
        { }
    airport(int TC, int AS, int ST) : TicketCost(TC), AllSpace(AS), SoldTickets(ST)
    {
        inputName();
    }
    void inputName() {
        cout << Rus("Введите название авиакомпании - ");
        cin.get();
        getline(cin, Name);
    }
    int benefit() {
        return TicketCost * SoldTickets;
    }
    void prtLine() {
        printf("| %15s | %10s | %10s | %10s |\n", "Name", "Ticket Cost", "All Space", "Sold Tickets");
        printf("|_________________|_____________|____________|______________|\n");
        printf("| %15s | %11d | %10d | %12d |\n", Name.c_str(), TicketCost, AllSpace, SoldTickets);
        printf("|___________________________________________________________|\n");
    }
};

int main() {
    string wntd;

        do {
            cout << Rus("Список комманд:\n1 - Вывести на экран класс по умолчанию\n2 - Создать класс по желанию и вывести на экран\n3 - Выйти\n");
            cout << Rus("Введите комманду: ");
            cin >> wntd;
            cout << "\n";
            if (!(wntd == "1" || wntd == "2" || wntd == "3")) wntd = "0";
            if (wntd == "0") {
                cout << Rus("Неправильная команда\n");
            }
            else if (wntd == "1") {
                airport DefaultAir;
                DefaultAir.prtLine();
                cout << Rus("Общая стоимость всех проданных билетов - ") << DefaultAir.benefit() << endl;
            }
            else if (wntd == "2") {
                airport CustomAir(12, 23, 34);
                CustomAir.prtLine();
                cout << Rus("Общая стоимость всех проданных билетов - ") << CustomAir.benefit() << endl;
            }
        } while (wntd != "3");
        printf(Rus("\n\n\n\tСПАСИБО ЗА ВНИМАНИЕ\n\n\n"));

    return 0;
}
