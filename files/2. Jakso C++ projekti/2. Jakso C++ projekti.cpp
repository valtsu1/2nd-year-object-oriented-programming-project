// 2. Jakso C++ projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Question.h"
#include <fstream>
#define nQuestions 5

void printMenu() {
	cout << "1) Take Quiz (" << nQuestions << " questions minimium required)\n2) Add Questions\n3) Show All Questions\n4) Save Questions to File\n5) Load Questions from File\n9) Clear All Questions\n0) Exit\n";
}


void game(vector <Question> &v) {
	int points = 0;
	bool running;
	vector <int> used;
	for (int i = 0; i < nQuestions; i++) {
		running = true;
		while (running) {
			int random = rand() % v.size();
			bool exists = find(begin(used), end(used), random) != end(used);

			if (exists == false) {
				used.push_back(random);
				if (v[random].askQuestion()) {
					points++;
				}
				running = false;
			}
		}
	}

	cout << "you got " << points << " points" << endl;
	if (points == nQuestions) {
		cout << "congratulations you got all questions right" << endl;
	}
	system("pause");
}


int main()
{
	srand(time(NULL));
	vector <Question> questionList;
	bool keepGoing = true;
	char mark;
	while (keepGoing) {
		printMenu();
		cin >> mark;
		switch (mark) {
		case '1':
			cout << "you chose to take the quiz" << endl;
			if (questionList.size() < nQuestions) {
				cout << "you need at least " << nQuestions << " questions, you currently have " << questionList.size() << " questions" << endl;
			}
			else {
				game(questionList);
			}
			break;
		case '2':
			cout << "you chose to add question" << endl;
			{
				Question q;
				q.addQuestion();
				questionList.push_back(q);
			}
			break;
		case '3':
			for (int i = 0; i < questionList.size(); i++) {
				cout << questionList[i].getQuestion() << endl;
			}
			break;
		case '4':
			cout << "you chose to save your questions to file" << endl;
			{
				ofstream oFile("q&a.txt");
				for (int i = 0; i < questionList.size();i++) {
					oFile << questionList[i];
				}
				oFile.close();
			}
			break;
		case '5':
			cout << "you chose to load your questions from file" << endl;
			{
				Question q;
				ifstream iFile("q&a.txt");
				while (iFile >> q) {
					questionList.push_back(q);
				}
				iFile.close();
			}
			break;
		case '9':
			cout << "you chose to clear questions" << endl;
			questionList.clear();
			{
				ofstream oFile;
				oFile.open("q&a.txt", ofstream::out | ofstream::trunc);
				oFile.close();
			}
			break;
		case '0':
			keepGoing = false;
			break;
		default:
			cout << "BAD INPUT" << endl;
			break;
		}
	}
}

