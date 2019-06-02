#pragma once

#include "tree.h"

// .......................................... iteratir defination .......................................... //
template<typename T>
tree<T>::val_ref_type tree<T>::iterator::operator*()
{

}

template<typename T>
tree<T>::val_ptr_type tree<T>::iterator::operator->()
{

}

template<typename T>
const tree<T>::val_ptr_type tree<T>::iterator::operator->() const
{

}

template<typename T>
tree<T>::iterator& tree<T>::iterator::operator++()
{

}

template<typename T>
tree<T>::iterator tree<T>::iterator::operator++(int)
{

}

template<typename T>
bool tree<T>::iterator::operator==(const tree<T>::iterator& itr)const
{

}

template<typename T>
bool tree<T>::iterator::operator!=(const tree<T>::iterator& itr)const
{

}
// .......................................... end iteratir defination .......................................... //

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
		m_root = std::make_unique<tree<T>::val_type>(value);
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
void tree<T>::erase()
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

template<typename T>
tree<T>::iterator tree<T>::begin()
{

}

template<typename T>
tree<T>::iterator tree<T>::end()
{

}

// ..................... private member functions implementation ..................... //
template<typename T>
bool tree<T>::is_leaf(const tree<T>::node_ref_type value)const
{
	return (value.num == 0);
}

template<typename T>
void tree<T>::split_node(node_ref_type node)
{
	
}

// .......................................... end tree defination .......................................... //