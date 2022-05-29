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

class Person{
protected:
	string vardas;
	string pavarde;
public:
	Person() { };
	//--
	inline std::string getVardas() const {return vardas;}
	inline std::string getPavarde() const {return pavarde;}
	//--
	inline void setVardas(std::string _vardas) {vardas=_vardas;}
	inline void setPavarde(std::string _pavarde) {pavarde=_pavarde;}
	~Person() {};
};


class Studentas : public Person {
private:
	int homeworkNum;
	vector <int> grades;
	int exam;
	double final;
public:
	Studentas() : final(0) { } // def konstruktorius
	Studentas(std::string name, std::string surname);
	// -------------------- Getteriai ----------------------
	inline std::vector<int> getGrades() const { return grades; }
	inline int getExam() const { return exam; }
	inline int getHomeworkNum() const { return homeworkNum; }
	inline int getFinal() const { return final; }

	// -------------------- Setteriai -----------------------
	inline void setGrades(std::vector<int> _nd) { Studentas::grades = _nd; }
	inline void setExam(int _exam) { Studentas::exam = _exam; }
	inline void setHomeworkNum(int _homeworkNum) { Studentas::homeworkNum = _homeworkNum; }
	inline void setFinal(double _final) { Studentas::final = _final; }

	Studentas(const Studentas& other) :					// copy constructor
		grades(other.grades), exam(other.exam),
		homeworkNum(other.homeworkNum), final(other.final) {
			vardas = other.getVardas();
			pavarde = other.getPavarde();
		}

	Studentas& operator = (const Studentas& other){		//copy assignment operator
		vardas = other.vardas;
		pavarde = other.pavarde;
		grades = other.grades;
		exam = other.exam;
		homeworkNum = other.homeworkNum;
		final = other.final;
		return *this;
	}

	~Studentas() {}; //Destructor
};

bool Checker();
char choiceCheck(char&);
char choiceCheck2(char&);
int numInput();
int gradeInput();
void checkGrade(int&);

void NewStudent(vector <Studentas>&, char);

template <class T>
void Ivestis(T&, string, char, bool);

void isvestis(vector <Studentas>, char);

/*template <class T>
void fileOutput(T, T, char, string);*/

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