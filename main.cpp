#include "functions.hpp"
using namespace std;
int main(){
	srand(time(NULL));
	char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid, timeOut;
	cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if(Checker())	benchmark();
	else{						// iprasta programos eiga
		vector <Studentas> studentas;
		vector <Studentas> winner;
		vector <Studentas> loser;
		if(FileExist()){
			cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";
			if(Checker()){
				Ivestis(studentas, "kursiokai.txt", rt, false);
			}
			else{
				do{
					NewStudent(studentas);
					cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
				} while(Checker());
			}
		}
		else {			// only manual input
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
	cout << endl;
	system("PAUSE");
}