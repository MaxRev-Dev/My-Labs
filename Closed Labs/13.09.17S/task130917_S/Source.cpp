#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <conio.h>
using namespace std;
class Dimentions  {
	protected:	
		int length;
		int width;
		int heigth;
	public:
		Dimentions(int length,int width,int heigth){
			this->length = length;
			this->heigth = heigth;
			this->width = width;
		}
	};
class Plane : public Dimentions {

private:
	double fuel;
	string weapons;
	bool isReady;

public:
	string location;
	string type;
	string color;
	Plane(int length, int width, int heigth):Dimentions(length,width, heigth) {

	}
	void set(double fuel,string weapon,bool isready) {
		this->fuel = fuel;
		this->weapons = weapon;
		this->isReady = isready;
	}
	Dimentions *dim;
	string Status(){
		return "˳���: " + this->type + "\n̳���������������: " + this->location + "\n������ �����: " +
			static_cast<ostringstream*>(&(ostringstream() << this->length))->str() + "x"+
				static_cast<ostringstream*>(&(ostringstream() << this->width))->str()+"x"+
					static_cast<ostringstream*>(&(ostringstream() << this->heigth))->str() 
			+ "\n����: " + this->color +
			+"\n������ ���: \n" +"\t������: "+ static_cast<ostringstream*>(&(ostringstream()<<this->fuel))->str()+
			"\n\t�����: "+this->weapons+"\n\t���������: "+(this->isReady?"�������":"� ������");
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	Plane *x = new Plane(300, 23, 234);
	x->color = "White";
	x->location = "Borispol,Kiev";
	x->type = "Aurobus 320";
	x->set()
	cout <<	x->Status();

	_getch();
	return 0;
}
