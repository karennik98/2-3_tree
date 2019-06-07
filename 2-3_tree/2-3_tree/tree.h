#pragma once

#include "I_tree.h"
#include "tree_node.h"

#include <list>
#include <iterator>
#include <initializer_list>


template<typename T>
class tree 
{
public:
	// ............ usings ............ //
	using node_type     = node<T>;
	using node_ref_type = node<T>&;
	using node_ptr_type = node<T>*; 
	using val_ptr_type  = T*;
	using val_ref_type  = T&;
	using val_type      = T;
	//using self_type     = tree<T>;

public:
	// ............... citors ............... //
	tree() = default;
	tree(std::initializer_list<T> list);

public:
	// ............... public member functions ............... //
	void insert(val_type value);
	//void find();
	//void erase(const T& value);
	//void clear();
	//void size();
	void level_order_traversal();

private:
	// ............... private member functions ............... //

	node_ptr_type split_node(node_ptr_type node);

	//node_ptr_type left_subtree_min(node_ptr_type node);

	node_ptr_type insert(node_ptr_type root, T value);


private:
	// ............... tree root ............... //
	node_ptr_type m_root = nullptr;
	
};

#include "tree_impl.h"