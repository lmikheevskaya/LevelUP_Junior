#pragma once

#include <iostream>

struct Node
{
	Node() :val(), next(nullptr) 
	{
	};

	int val;
	Node *next;
};

class cslist
{
public:
    typedef Node* iterator;
        
	cslist()
	{
	};

	cslist(int data)
	{
		Node *node = new_item();
		node->val = data;

		m_head_list = node;
	}

	cslist(const cslist &_list)
	{
            clear();
			for (Node *it = _list.m_head_list; it != nullptr; it = it->next ){
                push(it->val);
            }   
	}

	cslist& operator = (const cslist &_list) 
        {
            clear();
			for (Node *it = _list.m_head_list; it != nullptr; it = it->next ){
                push(it->val);
            }    

            return *this;
        }

	~cslist() 
	{
            clear();
	};

	void push(const int &val)
	{
		Node *node = new_item();
		node->val = val;
		node->next = m_head_list;

		m_head_list = node;
	}

	int erase(Node *node)
	{
        if (m_head_list == node){
			m_head_list = m_head_list->next;
        } else {
			Node *tmp;
			for (tmp = m_head_list; tmp->next != nullptr && tmp->next != node; tmp = tmp->next);
			
			if (tmp->next == nullptr){
				return -1;
			} 
                
			tmp->next = node->next;
		}
        delete node;
        return 0;
	};

	void clear() 
	{
            delete_list();
	}

	bool empty() const
	{	
        return (!m_head_list);
	}

	size_t size() const
	{	
        size_t size(0);
		for (Node *it = m_head_list; it != nullptr; it = it->next )
		{
			size++;
        }
        return size;
	}

	Node *find_item(int val)
	{
		Node *it;
		for ( it = m_head_list; it != NULL; it = it->next ) {
			if (it->val == val) {
				return it;
			}
		}
		return NULL;
	}
        
    Node *head_list()
    {
		return  m_head_list;
    }
        
    bool delete_item(int val) 
    {
		Node *it = nullptr; 
		Node *prev_it = nullptr;
		for (it = m_head_list; it != nullptr; prev_it = it, it = it->next ) 
		{
            if ( it->val == val ) 
            {
				if ( prev_it != nullptr ) 
                    prev_it->next = it->next;
				else
                    m_head_list = it->next;
                
				delete it;
				it = nullptr;
				return true;
            }
		}
		return false;
    }

	void print_list()
	{
		for (Node *it = m_head_list; it != nullptr; it = it->next ) 
		{
			std::cout << it->val << std::endl;
		}
	}

protected:
	Node *new_item() 
	{
		Node *tmp = new Node;
		tmp->next = nullptr;
		return tmp;
	}

	void delete_items(Node *it) 
	{
		if (it != nullptr) {
			if (it->next != nullptr) {
				delete_items(it->next);
			}
			delete it;
			it = nullptr;
        }
	}

	void delete_list() 
	{
		if (m_head_list != nullptr) {
			delete_items(m_head_list);
        }
        m_head_list = nullptr;
	}

protected:
	Node *m_head_list;
};
