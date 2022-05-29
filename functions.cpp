#include "functions.hpp"
using namespace std;

bool Checker(){							// Y/N tikrinimas
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' || ats == 'Y') return true;
		else if(ats == 'n' || ats == 'N') return false;
		else cout <<"Wrong input. Try again." << endl;
	}
}

char choiceCheck(char &rt){				//rt-resultType naudojamas vidurkio isvedimui pasirinkti 1/2/3
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2' || rt == '3')
			return rt; 
		else{
			cout << "Wrong input. Try again. " << endl;
		}
	}
}

char choiceCheck2(char &rt){
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2')
			return rt; 
		else{
			cout << "Wrong input. Try again. " << endl;
		}
	}
}

int numCheck(){							//Skaiciu inputo tikrinimas
	int num = 0;
	while(true){
		cin >> num;
		if(num == -1) return -1;
		else if(num <= 0 || cin.fail()) {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Wrong input. Try again." << endl;
		}
		else return num;
	}
}

void gradeCheck(int &grade){			// grade checkup
	while(true){
		if(grade <= 10 && grade > 0) break;
		else cout << "Wrong input. Try again.";
		grade = numCheck();
	}
}

void NewStudent(vector <Studentas> &studentas){			//Studento duomenu ivedimas (manualinis)				//WORKING
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
	while(loser.size() > 0){
		lout << left << setw(20) << loser.front().vardas << setw(20) << loser.front().pavarde << setw(18);
		lout << fixed << setprecision(2) << round(loser.front().final) << endl;
		loser.erase(loser.begin());
	}		
	lout.close();
	while(winner.size() > 0){			
		wout << left << setw(20) << winner.front().vardas << setw(20) << winner.front().pavarde << setw(18);
		wout << fixed << setprecision(2) << round(winner.front().final) << endl;
		winner.erase(winner.begin());
	}
	wout.close();
}

template <class T>
void print(T studentas, char rt, string outFileName){
	string galutinis;
	if(rt == '1') string galutinis = "Galutinis (med.)";
	else if (rt == '2') string galutinis = "Galutinis (vid.)";
	ofstream out(outFileName);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18) << galutinis << endl
	<< "----------------------------------------------------------------------" << endl;
	for(auto stud : studentas){
		out << left << setw(20) << stud.vardas << 
		setw(20) << stud.pavarde << 
		setw(18) << fixed << setprecision(2) << stud.final << endl;
	}
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File 'kursiokai.txt' detected." << endl << endl;
		return 1;}
}

bool studComp(Studentas a, Studentas b){			// rusiavimas
	if(a.vardas < b.vardas) return true;
	else return false;
}


void generateStud(int fStudSize, string fileName){						// failo kurimas
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

double calcFinal(vector <int> pazymiai, int exam, int homeworkNum, char rt){
	double final;
	if(rt == '2'){
					//calc vid
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
	final = round(final);
	return final;
}

// --------------------------------------------------------------------------------
// GRUPAVIMAS

template <class T>
void group_strat1(T studentas, T &winner, T &loser, int studNum){						// 2 new containers
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	copy_if(studentas.begin(), studentas.end(), back_inserter(winner), [](Studentas const& stud) {return stud.final >= 5; });
	copy_if(studentas.begin(), studentas.end(), back_inserter(loser), [](Studentas const& stud) {return stud.final < 5; });  
	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

						// working
template <class T>
void group_strat2(T &studentas, T &loser, int studNum){									// 1 new and 1 existing containers
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	auto it = stable_partition(studentas.begin(), studentas.end(), [](Studentas const& stud) {return stud.final >= 5;});
	loser.assign(it, studentas.end());
	studentas.erase(it, studentas.end());
	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

template <class T>
void group_optimised_vector(T &studentas, T &loser, int studNum){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	copy_if(studentas.begin(), studentas.end(), back_inserter(loser), [](Studentas const& stud) {return stud.final < 5; });
	studentas.erase(remove_if(studentas.begin(), studentas.end(), [](Studentas const& stud) {return stud.final < 5; }), studentas.end());

	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

// ----------------------------------------------- \/ GREICIO ANALIZE \/ ------------------------------------------

template <class T>
void mainFunc(T studentas, T winner, T loser, bool genStud, char rt, char strat){
	int a = 5;			// size dydis
	int size[5] = {1000, 10000, 100000, 1000000, 10000000};
	if(strat == '1'){
		for(int i = 0; i < a; i++){
			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			Ivestis(studentas, kursiokai, rt, true);
			sort(studentas.begin(), studentas.end(), studComp);
			group_strat1(studentas, winner, loser, size[i]);
			print(winner, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}

	else if(strat == '2'){
		for(int i = 0; i < a; i++){
			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			Ivestis(studentas, kursiokai, rt, true);
			sort(studentas.begin(), studentas.end(), studComp);
			group_strat2(studentas, loser, size[i]);
			print(studentas, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}

	else if(strat == '3'){
		for(int i = 0; i < a; i++){
			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			Ivestis(studentas, kursiokai, rt, true);
			sort(studentas.begin(), studentas.end(), studComp);
			group_optimised_vector(studentas, loser, size[i]);
			print(studentas, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
}

template <class T>
void mainFuncForList(T studentas, T winner, T loser, bool genStud, char rt, char strat){
	int a = 5;
	int size[5] = {1000, 10000, 100000, 1000000, 10000000};
	if(strat == '1'){
		for(int i = 0; i < a; i++){
			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			Ivestis(studentas, kursiokai, rt, true);
			studentas.sort(studComp);
			group_strat1(studentas, winner, loser, size[i]);
			print(winner, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
	
	if(strat == '2'){
		for(int i = 0; i < a; i++){
			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			Ivestis(studentas, kursiokai, rt, true);
			studentas.sort(studComp);
			group_strat2(studentas, loser, size[i]);
			print(studentas, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
}

// -------------------------------------------------- \/ BENCHMARKING \/ ----------------------------------

void benchmarkingVector(bool genStud, char rt, char strat){
	vector <Studentas> studentas;
	vector <Studentas> winner;
	vector <Studentas> loser;
	mainFunc(studentas, winner, loser, genStud, rt, strat);
	studentas.clear();
	winner.clear();
	loser.clear();
}

void benchmarkingDeque(bool genStud, char rt, char strat){
	deque <Studentas> studentas;
	deque <Studentas> winner;
	deque <Studentas> loser;
	mainFunc(studentas, winner, loser, genStud, rt, strat);
	studentas.clear();
	winner.clear();
	loser.clear();
}

void benchmarkingList(bool genStud, char rt, char strat){
	list <Studentas> studentas;
	list <Studentas> winner;
	list <Studentas> loser;
	mainFuncForList(studentas, winner, loser, genStud, rt, strat);
	studentas.clear();
	winner.clear();
	loser.clear();
}

void benchmark(){
	bool genStud;
	char conType = '0', rt = '0';
	char strat;
	cout << endl << "Pasirinkite testavimo strategija (1 / 2 / 3): " << endl
	<< "(1 - studentai yra skaidomi i du naujus konteinerius) " << endl
	<< "(2 - studentai yra skaidomi panaudojant tik viena nauja konteineri)" << endl
	<< "(3 - programos veikimo spartos palyginimas naudojant optimizuota ir paprasta vector konteineri (naudojantis 2 strategija))" << endl;
	choiceCheck(strat); 
	cout << endl << "Ar norite sugeneruoti studentu failus? (Y/N): ";
	if(Checker()) genStud = 1;
		else genStud = 0;
	cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
	choiceCheck2(rt);
	if(strat == '1') {
		cout << "NAUDOJAMA 1 STRATEGIJA. " << endl;

		cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, strat);

		cout << endl << "-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------" << endl;
		benchmarkingDeque(genStud, rt, strat);

		cout << endl << "----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------" << endl;
		benchmarkingList(genStud, rt, strat);
	}
	else if(strat == '2') {
		cout << "NAUDOJAMA 2 STRATEGIJA. " << endl;

		cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, strat);

		cout << endl << "-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------" << endl;
		benchmarkingDeque(genStud, rt, strat);

		cout << endl << "----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------" << endl;
		benchmarkingList(genStud, rt, strat);
	}
	else {
		cout << "VYKDOMAS VECTOR VEIKIMO SPARTOS PALYGINIMAS. " << endl
		<< "(Palyginimui naudojama antroji strategija) " << endl;

		cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, '2');

		cout << endl << "--------------------------- Pradedamas testavimas naudojant optimizuota vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, '3');
	}
}