#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Studentas{
	string vardas;
	string pavarde;
	int homeworkNum;
	int *pazymiai;
	int exam;
};

bool Checker(){
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' or ats == 'Y') return true;
		else if(ats == 'n' or ats == 'N') return false;
		else cout <<"Blogai ivedete, badykite dar kart." << endl;
	}				// Y/N tikrinimas
}

int numCheck(){										//Skaiciu inputo tikrinimas
	int num = 0;
	while(true){
		cin >> num;
		if(num == -1) return -1;
		else if(num <= 0 or cin.fail()) {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Blogai ivedete, badykite dar kart." << endl;
		}
		else return num;
	}
}

void gradeCheck(int &grade){						//Pazymiu inputo tikrinimas
	while(true){
		if(grade <= 10 and grade > 0) break;
		else cout << "Blogai ivedete, badykite dar kart.";
		grade = numCheck();
	}
}

void NewStudent(Studentas &stud){
	bool knownGradesNum, randomGrades;			//gg f false for testing
	int gradeNum;
	cout << "Iveskite studento varda: "; cin >> stud.vardas; cout << endl;
	cout << "Iveskite studento pavarde: "; cin >> stud.pavarde; cout << endl;
	cout << "Ar zinote atliktu namu darbu kieki? (Y/N): ";
	knownGradesNum = Checker();
	if(knownGradesNum){
		cout << endl << "Iveskite atliktu namu darbu kieki: ";
		stud.homeworkNum = numCheck();
		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		randomGrades = Checker();
		if(randomGrades){							// random number generation
			gradeNum = stud.homeworkNum;
			stud.pazymiai = new int[gradeNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
			}
			stud.exam = rand() % 10 + 1;
		}
		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.pazymiai = new int[stud.homeworkNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = numCheck();
				gradeCheck(stud.pazymiai[i]);
			}
			cout << endl << "Iveskite egzamino pazymi: ";
			stud.exam = numCheck();
			gradeCheck(stud.exam);
		}
	}
	else{
		stud.homeworkNum = rand() % 25 + 1;				// homework number range: 1-25
		cout << endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.homeworkNum << endl;
		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		randomGrades = Checker();
		if(randomGrades){								// random number
			gradeNum = stud.homeworkNum;
			stud.pazymiai = new int[gradeNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
			}
			stud.exam = rand() % 10 + 1;
		}
		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.pazymiai = new int[stud.homeworkNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = numCheck();
				gradeCheck(stud.pazymiai[i]);
			}
			cout << endl << "Iveskite egzamino pazymi: ";
			stud.exam = numCheck();
			gradeCheck(stud.exam);
		}
	}
}

void processStudent(Studentas stud, Studentas *&studentas, int &studNum){
	Studentas* arr = new Studentas[studNum+1];
	for(int i = 0; i < studNum; i++) arr[i] = studentas[i];
	delete[] studentas;
	studentas = arr;
	studNum = studNum + 1;
	studentas[studNum - 1] = stud;
}

void isvedimas(Studentas *studentas, bool vid, int studNum){
	cout << "\n\n\n\n\n";
	cout << left << setw(10) << "Vardas" << setw(15) << "Pavarde" << setw(13);
	if(vid) cout << "Galutinis (vid.)" << endl;
	else cout << "Galutinis (med.)" << endl;
	cout << "------------------------------------------------" << endl;
	for(int i = 0; i < studNum; i++){
		double galutinis = 0;
		if(vid){
			double sum = 0;
			int size = studentas[i].homeworkNum-1;
			for(int j = 0; j < size; j++){
				sum = sum + studentas[i].pazymiai[j];
			}
			double average = sum / size;
			galutinis = studentas[i].exam*0.6 + average*0.4;
		}
		else{
			int vidI = (studentas[i].homeworkNum/2)-1;
			sort(studentas[i].pazymiai, studentas[i].pazymiai + studentas[i].homeworkNum);
			if(studentas[i].homeworkNum != 0) galutinis = studentas[i].pazymiai[vidI]*0.4 + studentas[i].exam*0.6;
			else galutinis = ((studentas[i].pazymiai[vidI] + studentas[i].pazymiai[vidI+1])/2)*0.4 + studentas[i].exam*0.6;
		}
		cout << left << setw(10) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(13) << fixed << setprecision(2) << galutinis << endl;
	}
}

int main(){
	srand(time(NULL));
	int studNum = 0;
	bool vid;
	Studentas* studentas = new Studentas[studNum];
	do{
		Studentas stud;
		NewStudent(stud);
		processStudent(stud, studentas, studNum);
		cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
	} while(Checker());
	cout << endl << "Ar norite apskaiciuoti mediana? (Y - med / N - vid): ";
	if(Checker()) vid = false;
	else vid = true;
	isvedimas(studentas, vid, studNum);
}
