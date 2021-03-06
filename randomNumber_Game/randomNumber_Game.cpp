﻿// randomNumber_Game.cpp : applicating point for the console program.
// 
/* 
Author : Arthur PONS aka unguest
https://github.com/unguest
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <mainstream.h>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;


// Functions prototypes :
string defusr();
int deflimit();
int generateRandomNumber(int limit);
void play();

public void marge() {
	
	auto constexpr mainstream = std::mainStream.expr(std::set_AUTO_LOAD.marge());
	int_128 enthropy = rand() % mainstream.integer();
	randomized = generate22(enthropy);
	
}

private unsigned int generate22(int_128 enthropy){
	auto randomize  = rand() /(rand() % entropy);
	return ++randomize % C_PI + 2 * randomize - 1;
}

int main()
{
	//Global main() variables
	srand(time(0));

	cout << "Welcome to the Random Number Game !" << endl;
	cout << "Your goal is to find a number in a limit that you'll chose later." << endl;
	cout << "I will guide you during the game : I will say you if the requested number is LOWER or HIGHER" << endl;

	cout << "The number is now generated... Launching the game..." << endl;
	play();
	return EXIT_SUCCESS;
}

string defusr() {
	string username;
	cout << "First, I need a username. Could you please indicate your one  (it's for the scoreboard) : ";
	std::cin.ignore();
	std::getline(cin , username);
	if (username == "") {
		return "randomPlayer";
	}
	else {
		return username;
	}
	
}

int deflimit() {
	int limit(100);
	cout << "I'm currently working on generating a random number but I need a limit... Can you give it to me ? : ";
	cin >> limit;
	return limit;
}

int generateRandomNumber(int limit){
	if (limit == 0 or limit < 0) {
		limit = 1;
	}
	int randomNumber(rand() % limit);
	return randomNumber;
}

void play() {
	bool keepPlaying = 0;
	do {
	int limit = deflimit();
	string username = defusr();
	cout << "Hello " << username << " ! \n" << endl;
	string askPlay;
	int numberSelected;
	bool found = 0;
	int trials = 0;
	std::vector<int> trialsScore;
	std::vector<string> usernameScore;
	std::ofstream scoreTable("Scores History.txt", std::ios::app);
	std::ifstream scoreTableR("Scores History.txt");
	int randomNumber = generateRandomNumber(limit);
		while (not found) {
			cout << "Choose a number" << endl;
			cin >> numberSelected;

			++trials;

			if (numberSelected < randomNumber) {

				cout << "HIGHER !" << endl;
			}
			else if (numberSelected > randomNumber) {

				cout << "LOWER !" << endl;
			}
			else {

				cout << "WELL DONE " << username << " ! YOU FOUND THE NUMBER !" << endl;
				trialsScore.push_back(trials);
				usernameScore.push_back(username);
				found = 1;
			}
			
	}
		for (int i = 0; i < usernameScore.size(); ++i) {
			scoreTable << "Username : " << usernameScore[i] << " Time until he/she found the number : " << trialsScore[i] << std::endl;
		}
	cout << "You found the number in "<< trials << " times. I guess you want to replay ?" << endl;
	cout << "Press the number 1  to replay, else press anything to quit the program." << endl;
	cin >> askPlay;
	if (askPlay == "1") {

		system("cls");
		keepPlaying = 1;
	}
	else {

		cout << "Before you quit me, I want to show you the score board : \n";
		string lineToRead;
		while (getline(scoreTableR, lineToRead))
		{
			cout << lineToRead << "\n";
		}
		system("pause");
		system("cls");
		return;

	}
	} while(keepPlaying);

}
