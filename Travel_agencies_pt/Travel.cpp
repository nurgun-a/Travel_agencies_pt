#include "Travel.h"
vector <string> countrys{ "Алжир","Армения","Венесуэла","Египет",
"Израиль","Индия","Куба","Мальдивы","ОАЭ","Турция"};
vector <string> hotels{ "**","***","****","*****"};
vector <string> transfers{ "Такси","Автобус" };
vector <string> Yn{ "Да","Нет" };

map <string, double> countrys1
{
	{ countrys[0],12139},{ countrys[1],10185},{ countrys[2],32238},{ countrys[3],23509},
	{ countrys[4],31139},{ countrys[5],21190},{ countrys[6],70716},{ countrys[7],42869},
	{ countrys[8],23272},{ countrys[9],15632}
};


void Country::Set_n()
{
	string tmp = "Выберите страну:";
	name = Show_menu(countrys,tmp);
	for (auto it : countrys1)
	{
		if (name == it.first)Set_p(it.second);
	}
}

void Country::Set_p(double p)
{		
	price = p*2;
}

double Country::Get_p()
{	
	return price;
}

void Country::Print() { cout <<"Авиабилет: " << name << " - " << price << " руб (туда-обратно)" << endl; }


void Hotel::Set_n()
{
	string tmp = "Выберите отель:";
	name = Show_menu(hotels,tmp);
	if		(name == hotels[0])Set_p(2000);
	else if (name == hotels[1])Set_p(4000);
	else if (name == hotels[2])Set_p(8000);
	else if (name == hotels[3])Set_p(12000);
}

void Hotel::Set_p(double p)
{	
	price = p*7;
}

double Hotel::Get_p()
{
	return price;
}

void Hotel::Print()
{
	cout << "Гостиница "<< name << " - " << price <<" руб (7 дней)" << endl;
}

void Transfer::Set_n()
{
	string tmp = "Выберите вид трансфера:";
	name=Show_menu(transfers,tmp);
	if (name == transfers[0])Set_p(2800);
	else if (name == transfers[1])Set_p(4600);
}

void Transfer::Set_p(double p)
{
	
	price = p;
}

double Transfer::Get_p()
{
	return price;
}

void Transfer::Print()
{
	cout <<"Трансфер: "<< name << " - " << price << " руб" << endl;
}

void Excursion::Set_n()
{
	string _name = "Экскурсионная программа";
	name = _name;
	Set_p(850);
}

void Excursion::Set_p(double p)
{	
	price = p;
}

double Excursion::Get_p()
{
	return price;
}

void Excursion::Print()
{
	cout << name << " - " << price << " руб" << endl;
}

CompositeTravel* MyTour()
{
	CountryFactory* Country_Factory = new CountryFactory;
	HotelFactory* Hotel_Factory = new HotelFactory;
	TransferFactory* Transfer_Factory = new TransferFactory;
	ExcursionFactory* Excursion_Factory = new ExcursionFactory;

	CompositeTravel* Tour = new CompositeTravel;

	string tmp = " ";
	string tmp1 = " ";

	Tour->addObj(Country_Factory->createTravel());

	Tour->addObj(Hotel_Factory->createTravel());
	tmp1 = "Хотите добавить трансфер в путевку?";

	tmp=Show_menu(Yn,tmp1);
	if (tmp==Yn[0])	Tour->addObj(Transfer_Factory->createTravel());
	
	tmp1 = "Хотите добавить экскурсионную программу в путевку?";
	tmp = Show_menu(Yn,tmp1);
	if (tmp == Yn[0])Tour->addObj(Excursion_Factory->createTravel());

	return Tour;
}

string Show_menu(vector<string> st, string str)
{

	int index = 0;
	bool key = 1;
	do
	{
		system("cls");
		cout << str << endl;
		cout << "----------------------------------------" << endl;
		for (int i = 0; i < st.size(); i++)
		{
			if (i == index)cout << i + 1 << ") --> " << st[i] << " <--" << endl;
			else cout << i + 1 << ") " << st[i] << endl;
		}
		cout << "----------------------------------------" << endl;
		switch (static_cast <Keys> (_getch())) // ждёт нажатия на клаву без Enter после этого
		{
		case Keys::TOP:
		{
			if (index > 0) index--;
		}break;
		case Keys::DOWN:
		{
			if (st.size() - 1 > index) index++;
		}break;
		case Keys::ENTER:
		{
			return st[index];
		}break;
		/*case Keys::ESC:
			key = 0;
			break;*/
		}

	} while (key);
	return NULL;
}
