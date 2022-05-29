#include "functions.hpp"
using namespace std;

bool Checker(){							// Y/N tikrinimas
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' || ats == 'Y') return true;
		else if(ats == 'n' || ats == 'N') return false;
		else cout <<"Blogai ivedete, badykite dar kart." << endl;
	}
}

char choiceCheck(char &rt){				//rt-resultType naudojamas vidurkio isvedimui pasirinkti 1/2/3
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2' || rt == '3')
			return rt; 
		else{
			cout << "Blogai ivedete, badykite dar kart. " << endl;
		}
	}
}

char choiceCheck2(char &rt){							
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2')
			return rt; 
		else{
			cout << "Blogai ivedete, badykite dar kart. " << endl;
		}
	}
}

int numCheck(){							//Skaiciu inputo tikrinimas
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

void gradeCheck(int &grade){			// grade checkup
	while(true){
		if(grade <= 10 and grade > 0) break;
		else cout << "Blogai ivedete, badykite dar kart.";
		grade = numCheck();
	}
}

void NewStudent(vector <Studentas> &studentas){			//Studento duomenu ivedimas (manualinis)
	bool knownGradesNum, generateGrades;
	int gradeNum;
	Studentas stud;
	cout << "Iveskite studento varda: "; cin >> stud.vardas; cout << endl;
	cout << "Iveskite studento pavarde: "; cin >> stud.pavarde; cout << endl;
	cout << "Ar zinote atliktu namu darbu kieki? (Y/N): ";
	knownGradesNum = Checker();
	if(knownGradesNum){
		cout << endl << "Iveskite atliktu namu darbu kieki: ";
		stud.homeworkNum = numCheck();
		stud.pazymiai.resize(stud.homeworkNum);

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = Checker();
		if(generateGrades){							// random skaiciu generavimas
			gradeNum = stud.homeworkNum;
			stud.pazymiai.resize(gradeNum);
			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
				cout << stud.pazymiai[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas: " << stud.exam;
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
		cout << endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.homeworkNum << endl;
		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = Checker();
		if(generateGrades){								// random skaiciu generavimas
			gradeNum = stud.homeworkNum;
			stud.pazymiai.resize(gradeNum);
			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = rand() % 10 + 1;
				cout << stud.pazymiai[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas: " << stud.exam;
		}
		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.pazymiai.resize(stud.homeworkNum);
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.pazymiai[i] = numCheck();
				gradeCheck(stud.pazymiai[i]);
			}

			cout << endl << "Iveskite egzamino pazymi: ";
			stud.exam = numCheck();
			gradeCheck(stud.exam);
		}
	}
	studentas.push_back(stud);
	stud.pazymiai.clear();
}

template <class T>
void Ivestis(T &studentas, string fileName, char rt, bool timeOut){			// ivestis
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	ifstream file;
	try{
		file.open(fileName);
		if (!file) throw 1;
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
			if (stud.pazymiai.size() == 0) throw 2;
	
			stud.pazymiai.pop_back();
			stud.exam = g;
			stud.homeworkNum = stud.pazymiai.size();
			stud.final = calcFinal(stud.pazymiai, stud.exam, stud.homeworkNum, rt);
			studentas.push_back(stud);
		}
	}
	catch (int e){
		switch (e) {
		case 1:
			cout << "Failas nerastas." << endl << endl << "Baigiamas programos veikimas." << endl;
			break;
		case 2:
			cout << "Failas nuskaitytas netinkamai." << endl;
			break;
		}
		exit(1);
	}
	file.close();
	if(timeOut == true)
	cout << "Duomenu nuskaitymas is failo uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

void isvestis(vector <Studentas> studentas, char rt){						// isvestis i konsole		
	cout << "\n\n\n\n\n";
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(18);
	if(rt == '2') cout << "Galutinis (vid.)" << endl;
	else if (rt == '1') cout << "Galutinis (med.)" << endl;
	else cout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') cout << "----------------------------------------------------------------" << endl;
	else cout << "-----------------------------------------------" << endl;
	for(int i = 0; i < studentas.size(); i++){
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
		//galutinis outputui
		cout << left << setw(15) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(18);
		if(rt == '1')	cout << fixed << setprecision(2) << galutinisMed << endl;
		else if (rt == '2')	cout << fixed << setprecision(2) << galutinisVid << endl;
		else cout << fixed << setprecision(2) << galutinisVid << setw(18) << setprecision(2) << galutinisMed << endl;
	}
}

template <class T>
void fileOutput(T winner, T loser, char rt, string outFileName){					
	string wfile = "Winner_" + outFileName;
	string lfile = "Loser_" + outFileName;
	ofstream wout(wfile);
	ofstream lout(lfile);
	wout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18);
	if(rt == '2') wout << "Galutinis (vid.)" << endl;
	else if (rt == '1') wout << "Galutinis (med.)" << endl;
	else wout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') wout << "-----------------------------------------------------------------------------------------------------" << endl;
	else wout << "-------------------------------------------------------------------" << endl;
	lout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18);
	if(rt == '2') lout << "Galutinis (vid.)" << endl;
	else if (rt == '1') lout << "Galutinis (med.)" << endl;
	else lout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') lout << "-----------------------------------------------------------------------------------------------------" << endl;
	else lout << "-------------------------------------------------------------------" << endl;
	for(auto &a:loser){
		lout << left << setw(20) << a.vardas << setw(20) << a.pavarde << setw(18);
		lout << fixed << setprecision(2) << round(a.final) << endl;
		///loser.erase(loser.begin());
	}		
	lout.close();
	for(auto &a:winner){			
		lout << left << setw(20) << a.vardas << setw(20) << a.pavarde << setw(18);
		lout << fixed << setprecision(2) << round(a.final) << endl;
		///winner.erase(winner.begin());
	}
	wout.close();
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File 'kursiokai.txt' detected." << endl << endl;
		return 1;}
}

bool studComp(Studentas a, Studentas b){				// rusiavimas
	if(a.vardas < b.vardas) return true;
	else return false;
}
void generateStud(int fStudSize, string fileName){					// failo kurimas
	int a = 10;
	ofstream out(fileName);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
	for(int i = 0; i < a; i++) out << setw(8) << "ND" + to_string(i+1);
	out << setw(8) << "Egz." << endl;

	for(int i = 0; i < fStudSize; i++){
		out << left << setw(20) << "Vardenis" + to_string(i+1) << setw(20) << "Pavardenis" + to_string(i+1);
		for(int j = 0; j <= a; j++) {
			out << setw(8) << rand() % 10 + 1;
		}
		out << endl;
	}
	out.close();
}

double calcFinal(vector <int> pazymiai, int exam, int homeworkNum, char rt){		//galutiniai skaiciavimai
	double final;
	if(rt == '2'){					//calc vid
		int sum;
		sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
		final = (sum * 1.0 / homeworkNum) * 0.4 + exam * 0.6;
	}
	else if(rt == '1'){
		int vidI = (homeworkNum /2)-1;			//calc med
		sort(pazymiai.begin(), pazymiai.end());
		if(homeworkNum != 0) final = pazymiai[vidI]*0.4 + exam*0.6;
		else final = ((pazymiai[vidI] + pazymiai[vidI+1])/2)*0.4 + exam*0.6;
	}
	return final;
}

template <class T>
void group(T studentas, T &winner, T &loser, int studNum){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < studNum; i++){
		if (studentas.front().final < 5){ loser.push_back(studentas.front());
			studentas.erase(studentas.begin());
		}
		else {winner.push_back(studentas.front());
			studentas.erase(studentas.begin());
		}
	}
	studentas.clear();
	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}
template <class T>
void mainFunc(T studentas, T winner, T loser, bool genStud, char rt, char conType){																								// GREICIO ANALIZE 
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai1000.txt" << endl;
	if (genStud == 1)
	generateStud(1000, "kursiokai1000.txt");
	Ivestis(studentas, "kursiokai1000.txt", rt, true);
	group(studentas, winner, loser, 1000);
	fileOutput(winner, loser, rt, "kursiokai1000.txt");
	cout << "Bendras failo kursiokai1000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai10000.txt" << endl;
	if (genStud == 1)
	generateStud(10000, "kursiokai10000.txt");
	Ivestis(studentas, "kursiokai10000.txt", rt, true);
	group(studentas, winner, loser, 10000);
	fileOutput(winner, loser, rt, "kursiokai10000.txt");
	cout << "Bendras failo kursiokai10000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t2).count() / 1000. << "s." << endl;
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai100000.txt" << endl;
	if (genStud == 1)
	generateStud(100000, "kursiokai100000.txt");
	Ivestis(studentas, "kursiokai100000.txt", rt, true);
	group(studentas, winner, loser, 100000);
	fileOutput(winner, loser, rt, "kursiokai100000.txt");
	cout << "Bendras failo kursiokai100000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t3).count() / 1000. << "s." << endl;
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai1000000.txt" << endl;
	if (genStud == 1)
	generateStud(1000000, "kursiokai1000000.txt");
	Ivestis(studentas, "kursiokai1000000.txt", rt, true);
	group(studentas, winner, loser, 1000000);
	fileOutput(winner, loser, rt, "kursiokai1000000.txt");
	cout << "Bendras failo kursiokai1000000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t4).count() / 1000. << "s." << endl;
	high_resolution_clock::time_point t5 = high_resolution_clock::now();
		if (genStud == 1)
	generateStud(10000000, "kursiokai10000000.txt");
	Ivestis(studentas, "kursiokai10000000.txt", rt, true);
	group(studentas, winner, loser, 10000000);
	fileOutput(winner, loser, rt, "kursiokai10000000.txt");
	cout << "Bendras failo kursiokai10000000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t5).count() / 1000. << "s." << endl;
}

void benchmark(){
	bool genStud;
	char conType = '0', rt = '0';
	cout << "Pasirinkite konteinerio tipa" << endl
		<< "(1) Vector / (2) Deque / (3) List : ";
	choiceCheck(conType); 
	cout << endl << "Ar norite sugeneruoti studentu failus? (Y/N): ";
	if(Checker()) genStud = 1;
		else genStud = 0;
	cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
	choiceCheck2(rt);
	if(conType == '1') {
		vector <Studentas> studentas;
		vector <Studentas> winner;
		vector <Studentas> loser;
		cout << endl << "Pradedamas testavimas naudojant vector: " << endl;
		mainFunc(studentas, winner, loser, genStud, rt, conType);
	}
	else if(conType == '2') {
		deque <Studentas> studentas;
		deque <Studentas> winner;
		deque <Studentas> loser;
		cout << endl << "Pradedamas testavimas naudojant deque: " << endl;
		mainFunc(studentas, winner, loser, genStud, rt, conType);
	}
	else if (conType == '3') {
		list <Studentas> studentas;
		list <Studentas> winner;
		list <Studentas> loser;
		cout << endl << "Pradedamas testavimas naudojant list: " << endl;
		mainFunc(studentas, winner, loser, genStud, rt, conType);
	}
}