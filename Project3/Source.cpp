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
	cout << "���� '������� �����'\n";
	cout << "����� ������ ���  ��� ������\n";
	string guess;
	do
	{
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"���"," ���� ������ "},
			{"����"," ������� ����� "},
			{"����"," ������� � ������� ����� ���� �������� "},
			{"���������"," ����� ��������� "},
			{"��������"," ������� ��������� "},
			{"����"," ����������� �������� "},
			{"������"," 2 ������� �� ���������� �� ������ "},
			{"�������"," ��������� ������ ����� ���������� "},
			{"��������", " ������ ��������� "},
			{"�������"," ������� �� �������� "}
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
		cout << "\n��������� �����: ";
		cout << "\n������ 'hint' ���� ������ ����� ��������� \n";
		cout << "\n 'q' ��� ������\n";
		cout << jumble;
		cin >> guess;
		if (guess == theWord)
		{
			cout << "�� ������!";
			cout << " ����������: ";
			sum = sum + theWord.size();
			cout << sum;
		}
		if (guess == "hint")
		{
			cout << theHint;
			points += 2;
			cout << "\n����� 2 ���� �� ���������\n";
			while (guess != theWord)
			{
				cin >> guess;
				system("pause");
				if (guess == theWord)
				{
					cout << "�� ������!";
					cout << " ����������: ";
					sum = sum + theWord.size();
					cout << sum - points;
				}
			}
		}
		if (guess == "q")
		{
			cout << " ���������� " << sum - points << " ������";
			cout << "\n ���� ";
		}
	} while (guess != "q");
	cout << "\n���������� ����� = " << "\n";
	cout << sum - points;
	cout << "\n����� ����";
	system("pause>nul");
	return 0;
}