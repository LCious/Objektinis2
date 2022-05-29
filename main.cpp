#include "functions.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;

	vector <Studentas> studentas;
	vector <Studentas> winner;
	vector <Studentas> loser;

	cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if(Checker()){
		cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
		choiceCheck(rt);																		// 		GREICIO ANALIZE \/
		cout << endl << "Failas kursiokai1000.txt" << endl;
		generateStud(1000, "kursiokai1000.txt");
		Ivestis(studentas, "kursiokai1000.txt");
		calcFinal(studentas, rt);
		group(studentas, winner, loser);
		sort(studentas.begin(), studentas.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai1000.txt");

		cout << endl << "Failas kursiokai10000.txt" << endl;
		generateStud(10000, "kursiokai10000.txt");
		Ivestis(studentas, "kursiokai10000.txt");
		calcFinal(studentas, rt);
		group(studentas, winner, loser);
		sort(studentas.begin(), studentas.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai10000.txt");

		cout << endl << "Failas kursiokai100000.txt" << endl;
		generateStud(100000, "kursiokai100000.txt");
		Ivestis(studentas, "kursiokai100000.txt");
		calcFinal(studentas, rt);
		group(studentas, winner, loser);
		sort(studentas.begin(), studentas.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai100000.txt");

		cout << endl << "Failas kursiokai1000000.txt" << endl;
		generateStud(1000000, "kursiokai1000000.txt");
		Ivestis(studentas, "kursiokai1000000.txt");
		calcFinal(studentas, rt);
		group(studentas, winner, loser);
		sort(studentas.begin(), studentas.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai1000000.txt");

	}else{						// iprasta programos eiga \/
		if(FileExist()){
			cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";
			if(Checker()){
				Ivestis(studentas, "kursiokai.txt");
			}else{
				do{
					NewStudent(studentas);
					cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
				} while(Checker());
			}
		}else {			// only manual input
			cout << "Failas nerastas. Duomenys privalo buti ivesti rankiniu budu." << endl << endl;
			do{
				NewStudent(studentas);
				cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
			} while(Checker());
		}
		sort(studentas.begin(), studentas.end(), studComp);
		cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
		choiceCheck(rt);
		isvestis(studentas, rt);
	}
	system("PAUSE");
}
