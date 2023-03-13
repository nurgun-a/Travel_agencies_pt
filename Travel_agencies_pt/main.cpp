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
        cout << "�����: " << tour->Get_p() << " ������" << endl;
        system("pause");

        double num1 = 0;
        cout << "������� ������: ";
        cin >> num1;
        if (num1 < tour->Get_p())
        {
            cout << "������������ �������" << endl;
            system("pause");
        }
        else if (num1 > tour->Get_p())
        {
            system("cls");
            cout << "�� ��������� �������" << endl;
            tour->Print();
            cout << "�����: " << num1 - tour->Get_p() << " ���" << endl;
            break;           
        }
        else
        {
            system("cls");
            cout << "�� ��������� �������" << endl;
            tour->Print();
            break;
        }
        tour->ClearH();
    } while (key);
}

