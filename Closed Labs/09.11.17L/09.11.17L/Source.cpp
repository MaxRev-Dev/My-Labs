#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

//TEMPEATURE STATES
#define T_CELL_NORMAL 36.6
#define T_CELL_MAX_COLLAPSE 42.0
#define T_CELL_MIN_COLLAPSE 30.0

//ANTIBODIES STATES
#define CELL_AB_NORMAL 100
#define CELL_AB_DIE 0

using namespace std;
 class Virus;
 class Cell {
 protected:
	 double Temperature;
	 double Stamina;
	 bool isAlive;
 };
class HealthyCell:public Cell{
	friend class Virus;
protected:
	int Antibodies;
	int AntibodyPower;
public:
	HealthyCell() {
		this->Temperature = T_CELL_NORMAL;
		this->Antibodies = CELL_AB_NORMAL;
		this->AntibodyPower = 100;
	}
	HealthyCell(int ab,int ab_p) {
		this->Temperature = T_CELL_NORMAL;
		this->Antibodies = ab;
		this->AntibodyPower = ab_p;
	}
	void GetCellStamina() {
		double TStatePercent = (Temperature-T_CELL_MIN_COLLAPSE) * ((T_CELL_MAX_COLLAPSE - T_CELL_MIN_COLLAPSE) / 100)*100;
		if (TStatePercent > 140)cout << "\nCELL > CELL TEMPERATURE IS HIGH!!!";
		double ABStatePercent = Antibodies * (CELL_AB_NORMAL - CELL_AB_DIE) / 100;
		if (ABStatePercent < 50) cout << "\nCELL > Antibodies malfunction!";
		cout << "\nCELL: Stamina: " << ((1-TStatePercent/100)+ABStatePercent/100)*100<<"\n\tTemp: "<<TStatePercent << "%" <<"\n\tAB count: "<<ABStatePercent<<"%"<<endl;
	}
	/*
	double GetCellAntibodiesPower() {
		return Antibodies*AntibodyPower;
	}
	int GetCellAntibodiesCount() {
		return Antibodies;
	}*/
	bool isHealthy() {
		return (Antibodies > CELL_AB_NORMAL-20 && AntibodyPower> 100-20);
	}
	bool isAlive() {
		return (Antibodies > CELL_AB_DIE&&Temperature<T_CELL_MAX_COLLAPSE&&Temperature>T_CELL_MIN_COLLAPSE);
	}

};

class Virus : Cell {
protected:
	 int Power;
public:
	Virus(HealthyCell &x) {
		this->Power = 4;
		x.AntibodyPower -= Power;
		x.Temperature += 0.8;
		this->isAlive = true;
	}
	bool CanExpand(HealthyCell &x) {
		return (x.Antibodies > 0 && this->Power > x.AntibodyPower);
	}
	void DoWork_On(HealthyCell &x) {
			x.AntibodyPower -= Power;
			x.Antibodies -= 20;
			Power += 10;
			x.Temperature += 1.5;
		if (CanExpand(x)) {
			cout << "\nWARNING: CELL IS DYING!\nVirus is stronger than cell AB!\n";
			cout << "\nVIRUS > DEATH is SOON!!\n";
		}
		else { cout << "\nVIRUS > It needs more time\n"; }
	}
	void KillCell(HealthyCell &x) {
		if (x.Antibodies <= CELL_AB_DIE||x.AntibodyPower<=0||
			x.Temperature<=T_CELL_MIN_COLLAPSE||x.Temperature>=T_CELL_MAX_COLLAPSE) {
			x.AntibodyPower = 0;
			x.Antibodies = 0;
			x.Temperature = 0;
			cout << "\nVIRUS > CELL KILLED = > (x_x)\n";
		}
		else {
			cout << "\nVIRUS > Virus is not strong enough. Work harder!\n";
		}
	}
};
int main() {
	SetConsoleOutputCP(1251);
	while (true) {
		int day = 0,abcount,abpower;
		cout << "Enter cell parameters\nNormal antibodies(AB) count is 100 [0/100]\nNormal AB power is 100\n AB Count >>> ";
		cin >> abcount;
		cout << "AB Power >>> ";
		cin >> abpower; cin.get();
		cout << "\nTEST STARTED\n";
		HealthyCell *cell = new HealthyCell(abcount,abpower);
		cout << "Cell is " << (cell->isHealthy() ? "healty!" : "ill") << endl;
		
		Virus *v = new Virus(*cell);
		while (cell->isAlive()) {
			cout << "\n\nDAY " << ++day;
			cout << "\nVIRUS > Working...";
			v->DoWork_On(*cell);
			cout << "Cell is " << (cell->isHealthy() ? "healty!" : "ill") << endl;
			cell->GetCellStamina();
			cout << "\nVIRUS > Trying to kill it...";
			v->KillCell(*cell);
			Sleep(1000);
		}
		cout << "\nEND OF TEST\n";
		cout << "\nINFO : Make another stress test?? [y/n] ";
		
		char*buff = new char[20];
		cin.getline(buff,20);
		string input(buff);
		if (input != "yes" && input != "YES" && input != "Y" && input != "y") {
			break;
		}
	}
	return 0;
}