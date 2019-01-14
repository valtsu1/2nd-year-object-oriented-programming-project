#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator> 
#include "pch.h"

#define nAnswers 4

using namespace std;

class Question
{
	friend ostream &operator<<(ostream &out, const Question &q);
	friend istream &operator>>(istream &in, Question &q);
public:
	Question();
	string getQuestion() const { return question; }
	void addQuestion();
	bool askQuestion();

private:
	string question;
	string answers[nAnswers];
	int correctAnswer;
};

