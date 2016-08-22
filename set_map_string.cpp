#include <map>
#include <iostream>
#include <set>
#include <algorithm>

/* map*/
/*
int main()
{
	std::map<int, std::string> myMap = { { 2, "Beta" }, ///явная инициализация map
										 { 1, "Alpha"  },
										 { 3, "Gamma"  } };

	///присвоение элементам map новых значений
	myMap.at(2) = "Beta2";
	myMap.at(1) = "Alpha2";
	myMap.at(3) = "Gamma2";

	std::cout << "myMap contains:\n";
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		std::cout << it->first << " : " << it->second.c_str() << std::endl;///вывод на экран
	}

	std::multimap <char, int> myMultimap;///объявили multimap

									///заполняем myMultimap
	myMultimap.insert(std::pair<char, int>('q', 111));
	myMultimap.insert(std::pair<char, int>('u', 201));
	myMultimap.insert(std::pair<char, int>('h', 301));

	std::cout << "\nmyMultimap contains:\n";
	for (auto it = myMultimap.begin(); it != myMultimap.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}

	myMap.clear();
	myMultimap.clear();

	///новая инициализация myMap
	myMap = { {  40, "Mike" },
	{ 999, "Walle" },
	{ 17, "Cloude" } };

	///новая инициализация myMultimap
	myMultimap.insert(std::pair<char, int>('q', 222));
	myMultimap.insert(std::pair<char, int>('u', 223));
	myMultimap.insert(std::pair<char, int>('h', 221));

	auto itMap = myMap.begin();///создаем итератор на начало myМap
	auto itMultimap = myMultimap.begin();///создаем итератор на начало myMultimap
	std::cout << "\nmyMap after clear contains: \t myMultimap after clear contains:\n";

	///вывод на экран myMap и myMultimap
	for (itMap = myMap.begin(), itMultimap = myMultimap.begin(); itMultimap != myMultimap.end(); itMap++, itMultimap++)
	{
		std::cout << "\t" << itMap->first << " : ";
		std::cout << itMap->second.c_str() << "\t\t\t\t" << itMultimap->first << " : " << itMultimap->second << std::endl;
	}
	return 0;
}
*/


//--добавить элемент в рассматриваемое множество, при этом исключая возможность появления дублей;
//--удалить элемент из множества;
//--узнать количество(различных) элементов в контейнере;
//--проверить, присутствует ли в контейнере некоторый элемент.
//set
/*
int main()
{
	std::set<int> s;

	for (int i = 1; i <= 100; i++) { // добавим сто первых натуральных чисел
		int tmp = rand() % 100;
		s.insert(tmp);
	}


	
	//for (int i = 1; i <= 100; i++) { // добавим сто первых натуральных чисел
	//	s.insert(i);
	//}
	//s.insert(42); // ничего не произойдёт --- 
				  // элемент 42 уже присутствует в множестве
	

	for (int i = 2; i <= 100; i += 2) {
		s.erase(i);
	}

	//std::remove(s.begin(), s.end(), i); // удалим чётные числа

	// set::size() имеет тип unsigned int
	int N = int(s.size()); // N будет равно 50
}
*/

int main()
{
	std::string str("Test string");
	char tmp_at = str.at(2); //доступ к определенному символу в строке
	char tmp_2 = str[3]; //доступ к определенному символу в строке
	char tmp_front = str.front();
	char tmp_back = str.back();
	int size = str.size();
	int lenght = str.length();

	int cap = str.capacity(); //возвращает количество символов, которые могут содержаться в текущем выделенном хранилище 
	str.shrink_to_fit(); //уменьшает использование памяти, освобождая неиспользуемую память
	cap = str.capacity(); 
	if (!str.compare("Test string")){ //сравнивает две строки
		std::cout << "the strings are equal" << std::endl;
	}

	str.assign("New string");  //назначает символы строке 
	std::cout << str.c_str() << std::endl;

	str.append(" Add string"); //добавляет символы в конец строки 
	std::cout << str.c_str() << std::endl;

	std::string sub2 = str.substr(5, 3); //возвращает подстроку 

										 
	std::string::size_type n = str.find("Add");// поиск с начала строки
	std::cout << n << std::endl;

	// поиск с позиции 5
	n = str.find("Add", 5);
	std::cout << n << std::endl;

	std::string::iterator ii = str.begin();
	char tmp = *ii;
}
