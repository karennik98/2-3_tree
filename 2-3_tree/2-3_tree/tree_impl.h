#pragma once

#include "tree.h"

#include <queue>

// .......................................... tree defination .......................................... //
template<typename t>
tree<t>::tree(std::initializer_list<t> list)
{
	for (const auto& it : list)
	{
		insert(it);
	}
}

template<typename T>
typename tree<T>::node_ptr_type tree<T>::insert(tree<T>::node_ptr_type root, T value)
{
	if (root == nullptr)
	{
		root = new node_type;
		root->set_key(value);

		return root;
	}

	if (root->is_leaf())
	{
		root->set_key(value);
	}

	else if (value <= root->m_first)
	{
		insert(root->m_left, value);
	}

	else if (root->m_count == 1 || (root->m_count == 2 && value >= root->m_second))
	{
		insert(root->m_right, value);
	}

	else
	{
		insert(root->m_middle, value);
	}

	return split_node(root);
}

template<typename T>
void tree<T>::insert(tree<T>::val_type value)
{
	m_root = insert(m_root, value);
}

//template<typename T>
//void tree<T>::find()
//{
//
//}
//
//template<typename T>
//void tree<T>::erase(const T& value)
//{
//
//}
//
//template<typename T>
//void tree<T>::clear()
//{
//
//}
//
//template<typename T>
//void tree<T>::size()
//{
//
//}

template<typename T>
void tree<T>::level_order_traversal()
{
	std::queue<node_ptr_type> Q;
	Q.push(m_root);
	node_ptr_type node;

	while (!Q.empty())
	{
		node = Q.front();
		Q.pop();
		if (node->m_left)   Q.push(node->m_left);
		if (node->m_middle) Q.push(node->m_middle);
		if (node->m_right)  Q.push(node->m_right);
		node->show();
	}
}

// ..................... private member functions implementation ..................... //

template<typename T>
typename tree<T>::node_ptr_type tree<T>::split_node(tree<T>::node_ptr_type node)
{
	if (node->m_count < 3) return node;

	node_ptr_type node_1 = new node_type(node->m_first, node->m_left, nullptr, node->m_middle, nullptr, node->m_parent); 
	node_ptr_type node_2 = new node_type(node->m_third, node->m_right, nullptr, node->m_temp, nullptr, node->m_parent);

	if (node_1->m_left)
	{
		node_1->m_left->m_parent = node_1;
	}
	if (node_1->m_right)
	{
		node_1->m_right->m_parent = node_1;
	}
	if (node_2->m_left)
	{
		node_2->m_left->m_parent = node_2;
	}
	if (node_2->m_right)
	{
		node_2->m_right->m_parent = node_2;
	}

	if (node->m_parent)
	{
		node->m_parent->set_key(node->m_second);

		if (node->m_parent->m_left == node)
		{
			node->m_parent->m_left = nullptr;
		}
		else if (node->m_parent->m_middle == node)
		{
			node->m_parent->m_middle = nullptr;
		}
		else if (node->m_parent->m_right == node)
		{
			node->m_parent->m_right = nullptr;
		}

		if (node->m_parent->m_left == nullptr)
		{
			if (node->m_parent->m_middle == nullptr)
			{
				node->m_parent->m_middle = node_2;
				node->m_parent->m_left = node_1;
			}
			else
			{
				node->m_parent->m_temp = node->m_parent->m_right;
				node->m_parent->m_right = node->m_parent->m_middle;
				node->m_parent->m_middle = node_2;
				node->m_parent->m_left = node_1;
			}
		}
		else if (node->m_parent->m_middle == nullptr)
		{
			node->m_parent->m_temp = node->m_parent->m_right;
			node->m_parent->m_right = node_2;
			node->m_parent->m_middle = node_1;
		}
		else
		{
			node->m_parent->m_temp = node_2;
			node->m_parent->m_right = node_1;
		}

		node_ptr_type temp = node->m_parent;
		delete node;
		return temp;
	}
	else 
	{
		node_1->m_parent = node;
		node_2->m_parent = node;

		node->become_two_node(node->m_second, node_1, node_2);
		return node;
	}
}

//template<typename T>
//tree<T>::node_ptr_type tree<T>::left_subtree_min(tree<T>::node_ptr_type node)
//{
//}

// .......................................... end tree defination .......................................... //