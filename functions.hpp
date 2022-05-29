#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
struct Studentas{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> pazymiai;
	int exam;
	double final;
};
bool Checker();
char choiceCheck(char&);
int numCheck();
void gradeCheck(int&);
void NewStudent(vector <Studentas>&);
void Ivestis(vector <Studentas>&, string);
void isvestis(vector <Studentas>, char);
void fileOutput(vector <Studentas>, vector<Studentas>, char, string);
bool FileExist();
bool studComp(Studentas, Studentas);
void generateStud(int, string);
void calcFinal(vector <Studentas>&, char);
void group(vector <Studentas>, vector <Studentas>&, vector <Studentas>&);
#endif