#include <iostream>

/*
Создать абстрактный класс CVehicle. На его основе реализовать классы CPlane, ССаr и CShip. 
Классы должны иметь возможность задавать и получать координаты, параметры средств передвижения 
(цена, скорость, год выпуска). Для самолета должна быть определена высота, для самолета и корабля — 
количество пассажиров. Для корабля — порт приписки. Написать программу, создающую список объектов этих 
классов в динамической памяти. Программа должна содержать меню, позволяющее осуществить проверку всех 
методов классов.

*/
struct Coord
{
	double x;
	double y;
};

struct ParamVehicle
{
	double cost;
	double speed;
	double year_of_issue;
	double height;
	int  num_pass;
	char port_registry[125];
};

class CVehicle
{
public:
	CVehicle(char *cost, double year_issue) :
		m_year_issue(year_issue), m_speed(0)
	{
		m_coord.x = 0;
		m_coord.y = 0;
		strcpy_s(m_cost, 64, cost);
	}

	virtual ~CVehicle() {};
	
	void setCoord(Coord coord)
	{
		m_coord.x = coord.x;
		m_coord.y = coord.y;
	}

	void setSpeed(double speed)
	{
		m_speed = speed;
	}

	void getCoord(Coord &coord)
	{
		coord.x = m_coord.x;
		coord.y = m_coord.y;
	}

	double getSpeed()
	{
		return m_speed;
	}

	//virtual void setParam(ParamVehicle param) = 0;
	virtual void printParam() = 0;

protected:
	void printCoord()
	{
		std::cout << "coord_x = " << m_coord.x << "; coord_y = " << m_coord.y << std::endl; 
	}

	void printSpeed()
	{
		std::cout << "speed = " << m_speed << std::endl; 
	}

	void printGeneralParam()
	{
		std::cout << "cost = " << m_cost << "; year_issue = " << m_year_issue;
	}

private:
	Coord m_coord;
	char m_cost[64];
	double m_speed;
	double m_year_issue;
};

class CPlane : public CVehicle
{
public:
	CPlane(char *cost, double year_issue, double height, int num_pass) : 
		CVehicle(cost, year_issue), m_height(height), m_num_pass(num_pass)
	{
	}
	void printParam()
	{
		std::cout << "class CPlane" << std::endl;
		printCoord();
		printGeneralParam();
		std::cout << "; height = " << m_height << "; num_pass = " << m_num_pass << "\n \n" <<std::endl;
	}

private:
	double m_height;
	int  m_num_pass;
};

class ССаr : public CVehicle
{
public:
	ССаr(char *cost, double year_issue) : 
		CVehicle(cost, year_issue)
	{
	}

	void printParam()
	{
		std::cout << "class ССаr" << std::endl;
		printCoord();
		printGeneralParam();
		std::cout << "\n \n" <<std::endl;
	}
};

class CShip : public CVehicle
{
public:
	CShip(char *cost, double year_issue, char *port_registry, int num_pass) : 
		CVehicle(cost, year_issue), m_num_pass(num_pass)
	{
		strcpy_s(m_port_registry, 125, port_registry);
	}

	void printParam()
	{
		std::cout << "class CShip" << std::endl;
		printSpeed();
		printCoord();
		printGeneralParam();
		std::cout << "; port_registry = " << m_port_registry << "; num_pass = " << m_num_pass << "\n \n" <<std::endl;
	}

private:
	int  m_num_pass;
	char m_port_registry[125];
};

int main ()
{
	CVehicle *vehicle = new CShip("1234,887 @", 2005, "Spb", 30);
	Coord coord = {123.45, 65.56};
	vehicle->setCoord(coord);
	vehicle->setSpeed(456.9);
	vehicle->printParam();
}

