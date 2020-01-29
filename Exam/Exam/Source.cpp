//2. Написати програму «Автоматизована інформаційна система на
//залізничному вокзалі».Інформаційна система містить дані про відправлення
//поїздів дальнього сполучення.Для кожного потяга вказується : номер потяга,
//станція призначення, час відправлення.Програма повинна забезпечувати вибір за
//допомогою меню і виконання однієї наступних функцій :
// первісне введення даних в інформаційну систему(із клавіатури чи з
//	файлу);
// виведення даних про всі потяги;
// виведення даних по потяг з запитаним номером;
// виведення даних про ті потяги, що слідують до запитаної станції
//призначення.
//Збереження даних організувати з застосуванням контейнерного класу vector.


//                            Додати звідки поїзд
//                            Сортування по finish station
//                            Читання і запис у фал
//                            Видалення поїзду

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;
//class Train 
class Train
{
public:
	Train() {  };
	Train(int i)
	{
		cout << "Enter start station : ";
		cin >> this->start_station;
		cout << "Enter finish station : ";
		cin >> this->finish_station;
		cout << "Enter time departmen : ";
		cin >> this->time_started;
		cout << "Enter number train : ";
		cin >> this->number_train;
	};
	~Train() {};

	void Show() {
		cout << "                 Train" << endl;
		cout << " Start station :      " << this->start_station << endl;
		cout << " Finish station :     "<< this->finish_station<<endl;
		cout << "Time departmen :      "<<this->time_started<<endl;
		cout << "Number train :        "<< this->number_train<<endl<<endl;
	};

	int Get_number()											{ return this->number_train;					};
	string Get_rout()											{ return this->finish_station;					};	
	string Get_start_station()									{ return this->start_station;					};
	string Get_started_time()									{ return this->time_started;					};

	void Set_number(int number_train)							{ this->number_train = number_train; }
	void Set_rout(string finish_station)						{ this->finish_station = finish_station; }
	void Set_start_station (string start_station)				{ this->start_station = start_station; }
	void Set_started_time (string time_started)					{ this->time_started = time_started; }




private:

	string start_station;
	string finish_station;
	string time_started;
	int number_train;
};
//This is func out class, special for work with vector(array)
void Show_all(vector<Train> &avtovokzal) {
	cout << "                         *All TRAIN   " << endl;
	
	for (int i = 0; i < avtovokzal.size();i++)					 { 
		cout << "The train N " << i + 1 << ": " << endl;
		avtovokzal[i].Show()	;						}
	cout << "                         All TRAIN*   " << endl;
}


void Find_number(vector<Train> avtovokzal) {

	int finded_number;
	cout << "Enter the searching number train : ";
	cin >> finded_number;

	for (int i = 0;i< avtovokzal.size(); i++) {

		if (finded_number == avtovokzal[i].Get_number())		{ avtovokzal[i].Show();							}
		else if(i == avtovokzal.size()-1)						{ cout << "This number not found!" << endl;		}
	
	}
}

bool Sort_by_finish_station(Train &avtovokzal, Train &other) 
{
	return avtovokzal.Get_rout() < other.Get_rout();
}

void Sorting_by_finish_station(vector<Train> &avtovokzal)
{
	sort(avtovokzal.begin(), avtovokzal.end(), Sort_by_finish_station);
	Show_all(avtovokzal);

}



void Read_from_file(vector<Train> &avtovokzal)
{
	string path = "data1.txt";
	ifstream readFile;
	readFile.open(path);
	

	if (!readFile.is_open())
	{
		cout << "Can't open file " << endl;
	}


	else

	{
		cout << "File is open" << endl;
		
		
				
		while (!readFile.eof())
		{
			char temp[255];
			Train tmp;
			
			readFile.getline(temp, 255);
			tmp.Set_start_station(temp);
			readFile.getline(temp, 255);
			tmp.Set_rout(temp);
			readFile.getline(temp, 255);
			tmp.Set_started_time(temp);
			readFile.getline(temp, 255);
			tmp.Set_number(atoi(temp));
			avtovokzal.push_back(tmp);
			
		}
	
	
	}
	readFile.close();

}






void Write_to_file(vector<Train> avtovokzal)
{
	ofstream writeFile;
	string path = "data.txt";
	writeFile.open(path);
	if (!writeFile.is_open())
	{
		cout << "Can't write file" << endl;
	}
	else
	{
		writeFile << avtovokzal.size()-1 << endl;
		for (int i = 0; i < avtovokzal.size()-1; i++)
		{
			writeFile << "Train N" << i+1 << ": " << endl;
			writeFile << avtovokzal[i].Get_start_station() << endl;;
			writeFile << avtovokzal[i].Get_rout() << endl;
			writeFile << avtovokzal[i].Get_started_time() << endl;
			writeFile << avtovokzal[i].Get_number() << endl;
			

		}
		cout << "File is saved" << endl;
	}
}



void Find_rout(vector<Train> &avtovokzal) {

	string finded_rout;
	cout << "Enter the searching city : ";
	cin >> finded_rout;

	for (int i = 0; i < avtovokzal.size(); i++) {

		if (finded_rout == avtovokzal[i].Get_rout())			{ avtovokzal[i].Show();							}
		else if (i == avtovokzal.size() - 1)					{ cout << "This rout not found!" << endl;		}
	
	}
}

void DeleteTrain(vector<Train> &avtovokzal) {
	int number;
	bool flag = false;

	cout << "Enter the number of train do You want to delete: ";
	cin >> number;

	for (int i = 0; i < avtovokzal.size(); i++) {
		if (avtovokzal[i].Get_number () == number) {
			avtovokzal.erase(avtovokzal.begin() + i);
			cout << "Succesfull." << endl;
			flag = true;
			break;
		}
	}

	if (!flag) {
		cout << "Not found." << endl;
	}
}

//menu, bool special for eazy exit
bool menu() {

	int choise;
	vector <Train> avtovokzal;

	for (;;) {
		cout << endl << "                    MENU " << endl;
		cout << "1. Create route " << endl;
		cout << "2. Show all train " << endl;
		cout << "3. Find train " << endl;
		cout << "4. Show train route " << endl;
		cout << "5. Sorting by finish station " << endl;
		cout << "6. Read from file " << endl;
		cout << "7. Write in file " << endl;
		cout << "8. Delete train by number " << endl;
		cout << "0. Exit " << endl;
		cin >> choise;
		switch (choise)
		{
			case 1:
				system("cls");
				avtovokzal.push_back(Train(1));
				break;
			case 2:
				system("cls");
				Show_all(avtovokzal);
				break;
			case 3:
				system("cls");
				Find_number(avtovokzal);
				break;
			case 4:
				system("cls");
				Find_rout(avtovokzal);
				break;
			case 5:
				system("cls");
				Sorting_by_finish_station(avtovokzal);
				break;
			case 6:
				system("cls");
				Read_from_file(avtovokzal);
				break;
			case 7:
				system("cls");
				Write_to_file(avtovokzal);
				break;
			case 8:
				system("cls");
				DeleteTrain(avtovokzal);
				break;
			case 0:
				system("cls");
				return false;
				break;
		default:
			break;
		}
	}
}
//main func
int main() {
	menu();
	system("pause");
	return 0;
}