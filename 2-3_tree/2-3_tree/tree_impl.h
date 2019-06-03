#pragma once

#include "tree.h"

// .......................................... tree defination .......................................... //
template<typename T>
tree<T>::tree(std::initializer_list<T> list)
{

}

template<typename T>
void tree<T>::insert(tree<T>::val_type value)
{
	if (m_root == nullptr)
	{
		m_root = new node_ptr_type();
		m_root->set_first_key(value);
	}
	
	else if (m_root != nullptr && is_leaf(m_root))
	{
		if (m_root->get_key_count() == 1)
		{
			m_root->set_second_key(value)
		}

		else
		{
			split_node(m_root);
		}
	}

}

template<typename T>
void tree<T>::find()
{

}

template<typename T>
void tree<T>::erase(const T& value)
{

}

template<typename T>
void tree<T>::clear()
{

}

template<typename T>
void tree<T>::size()
{

}

// ..................... private member functions implementation ..................... //
template<typename T>
bool tree<T>::is_leaf(const node_ref_type value)const
{
	return (value.num == 0);
}

template<typename T>
void tree<T>::split_node(node_ref_type node)
{
	
}

template<typename T>
tree<T>::node_ptr_type tree<T>::left_subtree_min(node_ptr_type node)
{
	tree<T>::iterator itr = node;
	while (itre.next())
	{

	}
}

// .......................................... end tree defination .......................................... //