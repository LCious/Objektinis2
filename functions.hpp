#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;

// struct Studentai{
// 	string vardas;
// 	string pavarde;
// 	int homeworkNum;
// 	vector <int> grades;
// 	int exam;
// 	double final;
// };

class Studentas {
private:
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> grades;
	int exam;
	double final;
public:
	Studentas() : final(0) { } // def konstruktorius
	Studentas(std::string name, std::string surname);
	// -------------------- Getteriai ----------------------
	inline std::string getVardas() const { return vardas; }
	inline std::string getPavarde() const { return pavarde; }
	inline std::vector<int> getGrades() const { return grades; }
	inline int getExam() const { return exam; }
	inline int getHomeworkNum() const { return homeworkNum; }
	inline int getFinal() const { return final; }

	// -------------------- Setteriai -----------------------
	inline void setVardas(std::string vardas) { Studentas::vardas = vardas; }
	inline void setPavarde(std::string pavarde) { Studentas::pavarde = pavarde; }
	// inline void set1grade(int g) { grades.push_back(g); }
	inline void setGrades(std::vector<int> nd) { Studentas::grades = nd; }
	inline void setExam(int exam) { Studentas::exam = exam; }
	inline void setHomeworkNum(int homeworkNum) { Studentas::homeworkNum = homeworkNum; }
	inline void setFinal(double final) { Studentas::final = final; }
};

bool Checker();
char choiceCheck(char&);
char choiceCheck2(char&);
int numInput();
int gradeInput();
void checkGrade(int&);

void NewStudent(vector <Studentas>&);

template <class T>
void Ivestis(T&, string, char, bool);

void isvestis(vector <Studentas>, char);

template <class T>
void fileOutput(T, T, char, string);

template <class T>
void print(T, char, string);

bool FileExist();
bool studComp(Studentas, Studentas);
void generateStud(int, string);

double calcFinal(vector <int>, int, int, char);			// update this in normal function of program

template <class T>
void group_strat1(T, T&, T&, int);

template <class T>
void group_strat2(T&, T&, int);

template <class T>
void group_optimised_vector(T&, T&, int);

template <class T>
void mainFunc(T, T, T, bool, char, char);

template <class T>
void mainFuncForList(T, T, T, bool, char, char);

void benchmarkingVector(bool, char, char);
void benchmarkingDeque(bool, char, char);
void benchmarkingList(bool, char, char);

void benchmark();

#endif