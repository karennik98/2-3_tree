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
	using node_ptr_type = std::shared_ptr<node<T>>;
	using val_ptr_type  = std::shared_ptr<T>;
	using val_ref_type  = T&;
	using val_type      = T;
	using self_type     = tree<T>;

public:
	// ............... iterator for tree ............... //
	using base_iterator = std::iterator<std::forward_iterator_tag, node_ptr_type>;

	class iterator : public base_iterator
	{
	public:
		iterator&          operator++();
		iterator           operator++(int);
		val_ref_type       operator*();
		val_ptr_type       operator->();
		const val_ptr_type operator->() const;
		bool               operator==(const iterator& itr) const;
		bool               operator!=(const iterator& itr) const;
	private:
		node_ptr_type itr = nullptr;
	};

public:
	// ............... citors ............... //
	tree() = default;
	tree(std::initializer_list<T> list);
public:
	// ............... public member functions ............... //
	void insert(val_type value);
	void find();
	void erase();
	void clear();
	void size();

	iterator begin();
	iterator end();
	
private:
	// ............... private member functions ............... //
	bool is_leaf(const node_ref_type)const;
	void split_node(node_ref_type);

private:
	// ............... tree root ............... //
	node_ptr_type m_root = nullptr;
};