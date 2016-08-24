#include <iostream>
#include <algorithm>

class String
{
public:
    String()
        :m_pData(nullptr),m_size(0)
    {
 
    }
 
    String(const char* pStr)
    {
        m_size = strlen(pStr);
        m_pData = new char[m_size+1];
        //std::copy(pStr, pStr + m_size, m_pData);
        m_pData[m_size] = 0;
    }
 
    ~String()
    {
        if(m_pData != nullptr)
            delete[] m_pData;
    }
 
    String(const String& str)
    {
        m_size = str.m_size;
        m_pData = new char[m_size+1];
 
        std::cout << "Copying data" << std::endl;
        std::copy(str.m_pData, str.m_pData + m_size, m_pData);
        m_pData[m_size] = 0;
    }
 
    size_t size() const
    {
        return m_size;
    }
 
    const String& operator=(const String& str)
    {
        if(this != &str)
        {
            if(m_pData != nullptr)
                delete m_pData;
             
            m_size = str.m_size;
            m_pData = new char[m_size+1];
             
            std::cout << "Copying data" << std::endl;
           // std::copy(str.m_pData, str.m_pData + m_size, m_pData);
            m_pData[m_size] = 0;
        }
 
        return *this;
    }
 
    friend String operator +(const String& str1, const String& str2)
    {
        String tmp;
 
        tmp.m_size = str1.m_size + str2.m_size;
        tmp.m_pData = new char[tmp.m_size+1];
 
        auto pos = std::copy(str1.m_pData, str1.m_pData + str1.m_size, tmp.m_pData);
        std::copy(str2.m_pData, str2.m_pData + str2.m_size, pos);
        tmp.m_pData[tmp.m_size] = 0;
 
        return tmp;
    }

	/*
	const String& operator=(String&& str)
	{
		if(this != &str)
		{
			std::cout << "Moving data" << std::endl;
			m_pData = str.m_pData;
			m_size = str.m_size;
 
			str.m_pData = nullptr;
			str.m_size = 0;
		}
         
		return *this;
	}

	String(String&& str)
	{
		std::cout << "Moving data" << std::endl;
		m_pData = str.m_pData;
		m_size = str.m_size;
 
		str.m_pData = nullptr;
		str.m_size = 0;
	}
	*/

	//String(String&& str)
	//{
	//	std::cout << "Moving data" << std::endl;
		//вызовет код оператора присваивания
	//	*this = std::move(str); 
	//}

 
private:
    char *m_pData;
    size_t m_size;
};

int main()
{
	String str1;
	String str2("Hello");
	String str3(",World!");
	str1 = str2 + str3;
}
