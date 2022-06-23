#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int sum = 0;
	int points = 0;

	system("chcp 1251>nul");
	cout << "Игра 'Отгадай слово'\n";
	cout << "Нажми кнопку для  для начала\n";
	string guess;
	do
	{
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"лев"," царь зверей "},
			{"луна"," спутник земли "},
			{"марс"," планета и шоколад имеет одно название "},
			{"пегельман"," умный математик "},
			{"байконур"," русский космодром "},
			{"наса"," космическое агенство "},
			{"венера"," 2 планета по удалённости от солнца "},
			{"луноход"," советский лунный робот автомобиль "},
			{"макарова", " модель пистолета "},
			{"вовочка"," мальчик из анекдота "}
		};
		int choice;
		srand(time(0));
		choice = (rand() % NUM_WORDS);

		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];
		string jumble = theWord;

		int lenght = jumble.size();
		for (int i = 0; i <= lenght; i++)
		{
			int index_1 = rand() % lenght;
			int index_2 = rand() % lenght;
			char temp = jumble[index_1];
			jumble[index_1] = jumble[index_2];
			jumble[index_2] = temp;
		}
		cout << "\nРасшифруй слово: ";
		cout << "\nНабери 'hint' если хочешь взять подсказку \n";
		cout << "\n 'q' для выхода\n";
		cout << jumble;
		cin >> guess;
		if (guess == theWord)
		{
			cout << "Ты угадал!";
			cout << " Заработано: ";
			sum = sum + theWord.size();
			cout << sum;
		}
		if (guess == "hint")
		{
			cout << theHint;
			points += 2;
			cout << "\nШтраф 2 бала за подсказку\n";
			while (guess != theWord)
			{
				cin >> guess;
				system("pause");
				if (guess == theWord)
				{
					cout << "Ты угадал!";
					cout << " Заработано: ";
					sum = sum + theWord.size();
					cout << sum - points;
				}
			}
		}
		if (guess == "q")
		{
			cout << " Заработано " << sum - points << " баллов";
			cout << "\n Пока ";
		}
	} while (guess != "q");
	cout << "\nЗаработано очков = " << "\n";
	cout << sum - points;
	cout << "\nКонец игры";
	system("pause>nul");
	return 0;
}