template <class T>
class Array
{
public:
	Array(int size) : m_number(0), m_size(0)
	{
		m_array = new T[size];
		m_size = size;
	};
	~Array()
	{
		if(m_array){
			delete[] m_array;
			m_array = nullptr;
		}
	};

	Array(const Array &array) 
	{
		m_size = array.m_size;
		m_number = array.m_number;
		m_array = new T[m_size];
		for(int i = 0; i < m_number; ++i)
		{
			m_array[i] = array.m_array[i];
		}
		//m_array = array.m_array;
	}

	int add(T data)
	{
		if (m_number > m_size)
			return -1;
		m_array[m_number] = data;
		m_number++;
		return 0;
	}

	void reSize(int newSize)
	{
		//если размер массива совпадает с размером на который хотим изменить, то ничего не делаем
		if (newSize == m_size)
			return;


		if(!newSize){
			//здесь вызываете конструктор не удалив старую память
			//Array <T> (0);
			//лучше сделать очистку память в clear() и его вызывать
			delete []m_array;
			m_array = nullptr;
			m_number = 0;
			m_size = 0;
			return;
		}

		//недопустимый размер массива, ниего не делаем. или можем выводить сообщение об ошибке
		if(newSize < 0){
			return;
		}

		Array <T> tmpArray(*this);
		//очистить память, которая сейчас выделена под m_array
		delete []m_array;

		//выделяем новый кусок памяти нужного размера
		m_array = new T[newSize];

		//int copySize = 0;
		//if (newSize > m_size)
		//	copySize = m_size;
		//else
		//	copySize = newSize;

		m_size = newSize;
		if(m_number > m_size)
			m_number = m_size;
		for (int i = 0; i < m_number; i++)
			m_array[i] = tmpArray[i];
	}

	void delElement(int idx)
	{
		std::cout << "Deleting " << idx << " element..." << std::endl;
		if (idx < m_size-1 && m_size > 1) //входит ли удаляемый элемент в размер массива
		{
			for (int i = idx; i < m_size-1; i++)	//смещаем находящиеся справа элементы на место начиная с idx
				std::swap(m_array[i], m_array[i + 1]);
			reSize(m_size - 1); //изменяем размер массива
		}
	}

	T& operator [] (int index)
	{
		return m_array[index];
	}

	void clear()
	{
		m_array = new T[0];
		m_number = 0;
		m_size = 0;
	}

	void print()
	{
		std::cout << "Print all: ";
		for (int i = 0; i < m_number; i++)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	T *m_array;
	int m_number;
	int m_size;
};


int main()
{
	Array<int> MyArray(6);
	MyArray.add(3);
	MyArray.add(7);
	MyArray.add(6);
	MyArray.add(3);
	MyArray.add(1);
	MyArray.add(8);
	MyArray.print();

	std::cout << MyArray[2] << "   ";
	std::cout << MyArray[5] << std::endl;
	MyArray.delElement(4);
	MyArray.print();

	MyArray.reSize(7);
	//std::cout << "Clearing..." << std::endl;
	//MyArray.clear();
	MyArray.print();

	MyArray.reSize(8);
	MyArray.print();

	MyArray.reSize(3);
	MyArray.print();

	MyArray.reSize(0);
	MyArray.print();

	Array<int> array_2(MyArray);
	array_2.print();
	MyArray.~Array();
	array_2.print();
	return 0;
}

