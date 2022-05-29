#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "functions.hpp"

using namespace std;

int main(){
	srand(time(NULL));
	int studNum = 0; char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;
	Studentas* studentas = new Studentas[studNum];
	try{
		if(FileExist()){
		cout << "Ka norite daryti? Skaityti duomenis is failo ar duomenis ivesti? (y - file / n - manual): ";
		if(Checker()){
			Studentas stud;
			Ivestis(stud, studentas, studNum);
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
		throw 1;
		do{
			Studentas stud;
			NewStudent(stud);
			processStudent(stud, studentas, studNum);
			cout << endl << "Ar norite prideti studenta? (Y/N) ";
		} while(Checker());
	}
	}catch(int e){
		switch(e){
			case 1:
			cout << "Failas nerastas. Prasome duomenis ivesti rankiniu budu" << endl << endl;
			break;
		}
		exit(1);
	}
	
	sort(studentas, studentas + studNum, studComp);				//rusiavimas pagal varda
	cout << endl << "Ka noretumete apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
	choiceCheck(rt);
	isvedimas(studentas, rt, studNum);
}
