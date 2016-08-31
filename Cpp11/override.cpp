#include <iostream>

//D::f переопределяет B::f. Однако они имеют разную сигнатуру, один метод принимает short, другой — int, 
//поэтому B::f — это просто другой метод с тем же именем, перегруженный, а не переопределенный. 
//Таким образом, работая через указатель на базовый класс, Вы можете вызвать f() и ожидать вывода 
//«переопределенного» вами метода: «D::f», однако вывод будет «B::f». 
class B 
{
public:
	virtual void f(short) {std::cout << "B::f" << std::endl;}
};

class D : public B
{
public:
	virtual void f(int) {std::cout << "D::f" << std::endl;}
};

//идентификатор override указывает, что метод является переопределением виртуального метода в базовом классе
class B 
{
public:
	virtual void f(short) {std::cout << "B::f" << std::endl;}
};

class D : public B
{
public:
	//вызовет ошибку при компиляции
	virtual void f(int) override {std::cout << "D::f" << std::endl;}
};

int main()
{
}
