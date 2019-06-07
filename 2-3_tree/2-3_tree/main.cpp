#include <iostream>

#include "tree.h"

int main()
{
	tree<int> tree_2_3{ 11,8,1,7,1,2 };
	tree_2_3.level_order_traversal();
	system("pause");
	return 0;
}