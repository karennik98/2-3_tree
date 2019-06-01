#pragma once

template <typename T>
class I_tree
{
public:
	virtual void insert(T val) = 0;
	virtual void find() = 0;
	virtual void erase() = 0;
	virtual void clear() = 0;
	virtual void size() = 0;
};