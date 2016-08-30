#include <iostream>
#include <regex>

int main()
{
	setlocale(LC_ALL, "");
	std::string input; //входная строка, в которой будет поиск
	std::regex integer("(\\+|-)?[[:digit:]]+"); //запись регулярного выражения

	while (true)
	{
		std::cout << "ВВедите число" << std::endl;
		std::cin >> input;

		if (input == "q") //выходим, если будет введен символ q
			break;
		if (std::regex_match(input, integer)) // проверка на соответствие регулярному выражению
			std::cout << "Целое число" << std::endl;
		else
			std::cout << "Неверный ввод" << std::endl;
	}

    return 0;
