#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int sum = 0;
	int points = 0;
	cout << "The game 'Guess the word'\n";
	cout << "Press the button for to start\n";
	string guess;
	do
	{
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"lion"," king of beasts"},
			{"moon","earth satellite"},
			{"mars","planet and chocolate have the same name"},
			{"pegelman", "smart mathematician"},
			{"baikonur","Russian cosmodrome"},
			{"nasa","space agency"},
			{"venus","the 2nd planet by distance from the sun"},
			{"lunokhod","soviet lunar robot car"},
			{"makarova", "pistol model"},
			{"vovochka","the boy from the joke"}
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
		cout << "\nDecipher the word: ";
		cout << "\nType 'hint' if you want to take a hint \n";
		cout << "\n 'q' to exit\n";
		cout << jumble;
		cin >> guess;
		if (guess == theWord)
		{
			cout << "\nYou guessed it!\n";
			cout << "\n Earned: ";
			sum = sum + theWord.size();
			cout << sum;
		}
		if (guess == "hint")
		{
			cout << theHint;
			points += 2;
			cout << "\nPenalty 2 points for a hint\n";
			while (guess != theWord)
			{
				cin >> guess;
				system("pause");
				if (guess == theWord)
				{
					cout << "You guessed it!";
					cout << "  \nEarned:";
					sum = sum + theWord.size();
					cout << sum - points;
				}
			}
		}
		if (guess == "q")
		{
			cout << "Earned: " << sum - points << " points";
			cout << "\n Bye ";
		}
	} while (guess != "q");
	cout << "\nPoints earned = " << "\n";
	cout << sum - points;
	cout << "\nGame over";
	system("pause>nul");
	return 0;
}