#include <iostream>
#include <string>

struct POINT
{
	int x;
	int y;
};

class Point
{
public:
	Point() {};
	~Point() {};
	void setData(POINT coord)
	{
		m_coord.x = coord.x;
		m_coord.y = coord.y;
	}

protected:
	POINT m_coord;
};

class graphicPoint : public Point
{
public:
	graphicPoint(const char *color)
	{
		m_color.assign(color);
	}

	void paintPoint()
	{
		std::cout << "Paint point x = " << m_coord.x << ", y = " << m_coord.y << "; color = " <<  m_color.c_str() << std::endl;
	}

private:
	std::string m_color;
};


int main()
{
	graphicPoint graphic_point("green");
	POINT coord = {5, 2};
	graphic_point.setData(coord);
	graphic_point.paintPoint();
	return 0;
}

