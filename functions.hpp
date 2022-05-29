#ifndef functions_h
#define functions_h

using namespace std;

struct Studentas{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> pazymiai;
	int exam;
};

bool Checker();
char choiceCheck(char&);
int numCheck();
void gradeCheck(int&);
void NewStudent(Studentas&);
void processStudent(Studentas, Studentas*&, int&);
void Ivestis(Studentas&, Studentas*&, int&);
void isvedimas(Studentas*, char, int);
bool FileExist();
bool studComp(Studentas, Studentas);

#endif