#include <iostream>
using std::ostream;

template <class T> class stack;

template <class T>
struct Node
{
	Node() :val(), next(NULL) 
	{
	};

	T val;
	Node *next;
};

template<class T> ostream& operator<<(ostream& ostr, const stack<T> &_stack)
{
  for (Node<T> *it = _stack.m_head; it != NULL; it = it->next ){
    ostr << it->val << " ";  
  }   
  ostr << std::endl;
  return (ostr);
}

template <class T>
class stack
{
public:
	typedef Node<T>* iterator;

	friend ostream& operator<< <T>(ostream& ostr, const stack<T> &list);

	stack() : m_head(nullptr)
	{
	}

	stack(T data) : m_head(nullptr)
	{
		Node<T> *node = new_item();
		node->val = data;

		m_head = node;
	}

	stack<T>(const stack<T> &_stack) : m_head(nullptr)
	{
    clear();
		for (Node<T> *it = _stack.m_head; it != NULL; it = it->next ){
      push(it->val);
    }   
	}

	stack<T>& operator = (const stack<T> &_stack) 
  {
    clear();
    for (Node<T> *it = _stack.m_head; it != NULL; it = it->next ){
      push(it->val);
    }    

    return *this;
  }

  //в деструкторе очищаем стек 
  ~stack() 
  {
    clear();
  };

	//добавляем элемент в стэк
	void push(const T &val)
	{
	  //выделяем память под новый элемент стека
		Node<T> *node = new_item();
		node->val = val;
		node->next = m_head;

		m_head = node;
	}

	void clear() 
	{
		delete_stack();
	}

  //проверяем стек на пустоту
	bool empty() const
	{	
		return (!m_head);
	}

	//вычисляем размер стека
	//можно хранить size, как поле класса
	size_t size() const
	{	
		size_t size(0);
		for (Node<T> *it = m_head; it != NULL; it = it->next ){
			size++;
    }
    return size;
	}
  
  //возвращвем указатель на верхний элемент стека      
  Node<T> *top() 
  {
		return  m_head;
  }
  
  // удаляем верхний элемент стека
	void pop() 
	{
		Node<T> *it = m_head;
		m_head = it->next;
		delete it;
		it = NULL;
	}

  //оператор ставнения двух стеков
	bool operator == (stack<T> &_stack)
	{
		Node<T> *it;
		Node<T> *it2;
		for (it = m_head, it2 = _stack.m_head; it != NULL; it = it->next, it2 = it2->next) 
		{
			if(!it2){
				return false;
			}

			if(it->val != it2->val){
				return false;
			}
		}

		if(it2){
			return false;
		}

		return true;
	}

private:
	Node<T> *new_item() 
	{
		Node<T> *tmp = new Node<T>;
		tmp->next = NULL;
		return tmp;
	}

	void delete_items(Node<T> *it) 
	{
    if (it != NULL) {
			 if (it->next != NULL) {
				delete_items(it->next);
			}
			delete it;
			it = NULL;
    }
	}

	void delete_stack() 
	{
    if (m_head != NULL) {
			delete_items(m_head);
    }
    m_head = NULL;
	}

private:
	Node<T> *m_head;
};


int main ()
{
	stack<int> my_stack;
	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(4);
	my_stack.push(5);

	std::cout << my_stack;

	my_stack.pop();

	std::cout << my_stack;
}
