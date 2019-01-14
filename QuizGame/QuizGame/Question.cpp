#include "pch.h"
#include "Question.h"

//constructor
Question::Question()
{
	question = "";
	for (int i = 0; i < nAnswers; i++) {
		answers[i] = "";
	}
	correctAnswer = 0;
}

//kysytään tarvittavat tiedot, katsotaan ettei oikeaksi vastaukseksi voi laittaa non Int tyyppiä
void Question::addQuestion() {
	cin.ignore();
	cout << "enter question: ";
	getline(cin, question);
	cout << "enter answers 1-4" << endl;
	for (int i = 0; i < nAnswers; i++) {
		cout << i + 1 << ")";
		getline(cin, answers[i]);
	}
	cout << "enter the number of correct answer (1-4):";
	cin >> correctAnswer;
	while (cin.fail() || (correctAnswer > 4) || correctAnswer < 1) {
		cin.clear();
		cin.ignore();
		cout << "enter the number of correct answer (1-4): ";
		cin >> correctAnswer;
	}
}

//kysyy kysymyksen, palauttaa True, jos vastaus on oikeen
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

//save
ostream &operator<<(ostream &out, const Question &q) {

	out << q.question << endl;
	out << q.answers[0] << endl;
	out << q.answers[1] << endl;
	out << q.answers[2] << endl;
	out << q.answers[3] << endl;
	out << q.correctAnswer << endl << endl;
	return out;
}

//load
istream &operator>>(istream &in, Question &q) {
	getline(in, q.question);
	getline(in, q.answers[0]);
	getline(in, q.answers[1]);
	getline(in, q.answers[2]);
	getline(in, q.answers[3]);
	in >> q.correctAnswer;
	in.ignore(); //liikutetaan filepointeria kaksi riviä alaspäin
	in.ignore();
	return in;
}
