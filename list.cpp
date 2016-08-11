// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "clist.h"

int main()
{
	cslist list;
	list.push(1);
	list.push(2);
	list.push(5);

	list.print_list();

	return 0;
}

