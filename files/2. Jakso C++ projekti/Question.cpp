#include "Question.h"

Question::Question()
{
	question = "";
	for (int i = 0; i < nAnswers; i++) {
		answers[i] = "";
	}
	correctAnswer = 0;
}


Question::~Question()
{

}


void Question::addQuestion() {
	cin.ignore();
	cout << "enter question: ";
	getline(cin, question);
	cout << "enter answers 1-4" << endl;
	for (int i = 0; i < nAnswers; i++) {
		cout << i + 1 << ")";
		getline(cin, answers[i]);
	}
	cout << "which one of these was the correct one?:";
	cin >> correctAnswer;
}

bool Question::askQuestion() {
	system("CLS");
	cout.clear();
	cout << question << endl << answers[0] << endl << answers[1] << endl << answers[2] << endl << answers[3] << endl << "Your Answer:";
	int answer;
	bool correct = false;
	cin >> answer;
	if (answer == correctAnswer) {
		correct = true;
	}
	return correct;
}

ostream &operator<<(ostream &out, const Question &q) {

	out << q.question << endl;
	out << q.answers[0] << endl;
	out << q.answers[1] << endl;
	out << q.answers[2] << endl;
	out << q.answers[3] << endl;
	out << q.correctAnswer << endl << endl;
	return out;
}

istream &operator>>(istream &in, Question &que) {
	getline(in, que.question);
	getline(in, que.answers[0]);
	getline(in, que.answers[1]);
	getline(in, que.answers[2]);
	getline(in, que.answers[3]);
	in >> que.correctAnswer;
	in.ignore(); //To move filopointer 2 line to take input from next Question
	in.ignore();
	return in;
}
