#include <iostream>
#include <memory>

template<typename T>
struct node
{
	node(T v) :val(v)
	{

	}
	T val;
	size_t num;
	~node()
	{
		std::cout << "~node" << std::endl;
	}
	std::shared_ptr<T> parent;

	std::shared_ptr<T> get_parent()const 
	{
		return parent;
	}
};

int main()
{
	std::shared_ptr<node<int>> ptr(new node<int>(4));
	std::shared_ptr<int> ptr3 = ptr->get_parent();
	system("pause");
	return 0;
}