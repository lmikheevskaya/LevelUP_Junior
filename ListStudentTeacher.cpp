#include <iostream>
#include <list>


/*
Создать список студентов и преподаватель вперемешку. 
При вызове метода ShowData на экран должно выводится: если тип студент - имя, фамилию, средний бал студента, 
факультет; 
преподаватель - имя, фамилию, число публикаций преподавателя, 
должность ( преподаватель, старший преподаватель, доцент, профессор), возраст. 
Метод ShowData вызывается в цикле по всему списку.
*/

class Human
{
public:
	Human(char *name, char *surname)
	{
		strcpy_s(m_name, name);
		strcpy_s(m_surname, surname);
	}

	virtual ~Human() {};

	virtual void ShowData() = 0;

protected:
	void ShowFullName()
	{
		std::cout << "Full name - " << m_surname << " " << m_name;
	}

private:
	char m_name[125];
	char m_surname[125];
};

class Student : public Human
{
public:
	Student(char *name, char *surname,  double average_mark, char *faculty) : 
		Human(name, surname), m_average_mark(average_mark)
	{
		strcpy_s(m_faculty, faculty);
	}

	 void ShowData()
	 {
		 std::cout << "Student : ";
		 ShowFullName();
		 std::cout << "; average mark = " << m_average_mark << "; faculty - " << m_faculty << std::endl;
	 }

private:
	double m_average_mark;
	char m_faculty[125];
};

class Teacher : public Human
{
public:
	Teacher(char *name, char *surname, int age) : 
		Human(name, surname), m_age(age)
	{

	}

	void ShowData()
	{
		std::cout << "Teacher : ";
		ShowFullName();
		std::cout << "; age = " << m_age << std::endl;
	}

private: 
	int m_age;
};

class mylist
{
public:
	mylist()
	{		
	}

	~mylist()
	{
		for(auto ii = m_list.begin(); ii != m_list.end(); ++ii)
		{
			delete *ii;
		}

		m_list.clear();
	}

	void add(Human *data)
	{
		m_list.push_back(data);
	}

	void show()
	{
		for(auto ii = m_list.begin(); ii != m_list.end(); ++ii)
		{
			(*ii)->ShowData();
		}
	}

private:
	std::list<Human *> m_list;
};

int main()
{
	mylist list_human;
	list_human.add(new Teacher("liza", "mih", 28));
	list_human.add(new Teacher("denis", "step", 30));
	list_human.add(new Student("ivan", "ivanov", 4.8, "inform"));
	list_human.show();
	return 0;
}
