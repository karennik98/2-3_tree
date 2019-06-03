#pragma once

#include "I_tree.h"
#include "tree_node.h"

#include <memory>
#include <iterator>
#include <initializer_list>

template<typename T>
class tree : public I_tree<T>
{
public:
	// ............ usings ............ //
	using node_type     = node<T>;
	using node_ref_type = node<T>&;
	using node_ptr_type = node<T>*;
	using val_ptr_type  = T*;
	using val_ref_type  = T&;
	using val_type      = T;
	using self_type     = tree<T>;

public:
	// ............... citors ............... //
	tree() = default;
	tree(std::initializer_list<T> list);

public:
	// ............... public member functions ............... //
	void insert(val_type value);
	void find();
	void erase(const T& value);
	void clear();
	void size();

private:
	// ............... private member functions ............... //
	bool is_leaf(const node_ref_type)const;
	void split_node(node_ref_type);
	node_ptr_type left_subtree_min(node_ptr_type node);

private:
	// ............... tree root ............... //
	node_ptr_type m_root = nullptr;
};