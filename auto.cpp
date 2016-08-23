int main()
{
	int someInt;
	decltype(someInt) otherIntegerVariable = 5;

	std::vector<int> myvec;
	for (std::vector<int>::const_iterator itr = myvec.cbegin(); itr != myvec.cend(); ++itr)
	{
	}

	//Тип, помеченный как decltype, может отличаться от типа выведенного с помощью auto.
	const std::vector<int> v(1);
	auto a = v[0];			// тип a - int  
	decltype(v[0]) b = 1;	// тип b - const int& (возвращаемое значение
							// std::vector<int>::operator[](size_type) const)
	auto c = 0;				// тип c - int   
	auto d = c;				// тип d - int            
	decltype(c) e;			// тип e - int, тип сущности, именованной как c 
	decltype((c)) f = c;	// тип f - int&, так как (c) является lvalue
	decltype(0) g;			// тип g - int, так как 0 является rvalue
	
	return 0;
}
