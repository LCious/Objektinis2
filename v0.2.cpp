#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Studentas{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> pazymiai;
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

char choiceCheck(char &rt){						//rt-resultType naudojamas vidurkio isvedimui pasirinkti			
	while(true){
		cin >> rt;
		if(rt == '1' or rt == '2' or rt == '3')
			return rt;
		else{
			cout << "Blogai ivedete, badykite dar kart." << endl;
		}
	}
}

int numCheck(){											//Skaiciu inputo tikrinimas
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

void gradeCheck(int &grade){
	while(true){
		if(grade <= 10 and grade > 0) break;
		else cout << "Blogai ivedete, badykite dar kart.";
		grade = numCheck();
	}
}

void NewStudent(Studentas &stud){						//Studento duomenu ivedimas
	bool knownGradesNum, generateGrades;			
	int gradeNum;
	cout << "Iveskite varda: "; cin >> stud.vardas; cout << endl;
	cout << "Iveskite pavarde: "; cin >> stud.pavarde; cout << endl;
	cout << "Ar zinote namu darbu kieki? (Y/N): ";
	knownGradesNum = Checker();
	if(knownGradesNum){
		cout << endl << "Iveskite namu darbu kieki:";
		stud.homeworkNum = numCheck();
		stud.pazymiai.resize(stud.homeworkNum);
		cout << endl << "Ar norite, kad pazymiai butu generuojami automatiskai? (Y/N): ";
		generateGrades = Checker();
		if(generateGrades){							// random numberiu generavimas
			gradeNum = stud.homeworkNum;
			stud.pazymiai.resize(gradeNum);
			cout << endl << "Sugeneruoti studento pazymiai:";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
				cout << stud.pazymiai[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas:" << stud.exam;
		}
		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
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
		cout << endl << "Sugeneruotas atliktu namu darbu kiekis:" << stud.homeworkNum << endl;
		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = Checker();
		if(generateGrades){								// random number
			gradeNum = stud.homeworkNum;
			stud.pazymiai.resize(gradeNum);
			cout << endl << "Sugeneruoti pazymiai:";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
				cout << stud.pazymiai[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas:" << stud.exam;
		}
		else {
			cout << endl << "Iveskite namu darbu pazymius:" << endl;
			stud.pazymiai.resize(stud.homeworkNum);
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = numCheck();
				gradeCheck(stud.pazymiai[i]);
			}
			cout << endl << "Iveskite egzamino pazymi:";
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

void fileInput(Studentas &stud, Studentas *&studentas, int &studNum){			//working
	ifstream file;
	file.open("kursiokai.txt");
	string line;
	getline(file, line);
	while (getline(file, line)){
		Studentas stud;
		istringstream iss(line);
		iss >> stud.vardas >> stud.pavarde;
		int g;
		while (iss >> g){
			stud.pazymiai.push_back(g);
		}
		stud.pazymiai.pop_back();
		stud.exam = g;
		processStudent(stud, studentas, studNum);
	}
	file.close();
}

void isvedimas(Studentas *studentas, char rt, int studNum){

	cout << "\n\n\n\n\n";
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(18);
	if(rt == '2') cout << "Galutinis (vid.)" << endl;
	else if (rt == '1') cout << "Galutinis (med.)" << endl;													//Pagal resultType priklauso isvedimas
	else cout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') cout << "----------------------------------------------------------------" << endl;
	else cout << "-------------------------------------------" << endl;
	for(int i = 0; i < studNum; i++){
		double galutinisVid = 0;
		double galutinisMed = 0;
		double sum = 0;		//calc vid
		int size = studentas[i].pazymiai.size();
		for(int j = 0; j < size; j++){
			sum = sum + studentas[i].pazymiai[j];
		}
		double average = sum / size;
		galutinisVid = studentas[i].exam*0.6 + average*0.4;
		int vidI = (size/2)-1;			//calc med
		sort(studentas[i].pazymiai.begin(), studentas[i].pazymiai.end());
		if(size != 0) galutinisMed = studentas[i].pazymiai[vidI]*0.4 + studentas[i].exam*0.6;
		else galutinisMed = ((studentas[i].pazymiai[vidI] + studentas[i].pazymiai[vidI+1])/2)*0.4 + studentas[i].exam*0.6;
		//galutinis isvedimas
		cout << left << setw(15) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(18);
		if(rt == '1')	cout << fixed << setprecision(2) << galutinisMed << endl;
		else if (rt == '2')	cout << fixed << setprecision(2) << galutinisVid << endl;
		else cout << fixed << setprecision(2) << galutinisVid << setw(18) << setprecision(2) << galutinisMed << endl;
	}
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File detected." << endl << endl;
		return 1;}
}

bool studComp(Studentas a, Studentas b){
	if(a.vardas < b.vardas) return true;
	else return false;
}

int main(){
	srand(time(NULL));
	int studNum = 0; char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;
	Studentas* studentas = new Studentas[studNum];
	if(FileExist()){
		cout << "Ka norite daryti? Skaityti duomenis is failo ar duomenis ivesti? (y - file / n - manual): ";
		if(Checker()){
			Studentas stud;
			fileInput(stud, studentas, studNum);
		}
		else{
			do{
				Studentas stud;
				NewStudent(stud);
				processStudent(stud, studentas, studNum);
				cout << endl << "Ar norite prideti studenta? (Y/N) ";
			} while(Checker());
		}
	}
	else {			// Manual input
		cout << "Failas nerastas. Prasome duomenis ivesti rankiniu budu" << endl << endl;
		do{
			Studentas stud;
			NewStudent(stud);
			processStudent(stud, studentas, studNum);
			cout << endl << "Ar norite prideti studenta? (Y/N) ";
		} while(Checker());
	}
	sort(studentas, studentas + studNum, studComp);				//rusiavimas pagal varda
	cout << endl << "Ka noretumete apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
	choiceCheck(rt);
	isvedimas(studentas, rt, studNum);
}
