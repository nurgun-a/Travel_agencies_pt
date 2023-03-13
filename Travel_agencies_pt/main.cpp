#include "Travel.h"

void main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CompositeTravel* tour = new CompositeTravel;
    bool key = 1;
    do
    {
        tour->addObj(MyTour());
        tour->Print();
        cout << "Игого: " << tour->Get_p() << " рублей" << endl;
        system("pause");

        double num1 = 0;
        cout << "Внесите деньги: ";
        cin >> num1;
        if (num1 < tour->Get_p())
        {
            cout << "Недостаточно средств" << endl;
            system("pause");
        }
        else if (num1 > tour->Get_p())
        {
            system("cls");
            cout << "Вы приобрели путевку" << endl;
            tour->Print();
            cout << "Сдача: " << num1 - tour->Get_p() << " руб" << endl;
            break;           
        }
        else
        {
            system("cls");
            cout << "Вы приобрели путевку" << endl;
            tour->Print();
            break;
        }
        tour->ClearH();
    } while (key);
}

