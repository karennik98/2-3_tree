#pragma once
#include <memory>

template <typename T>
class node
{
public:
	// ........ usings ........ //
	using ptr_type = std::shared_ptr<node<T>>;
public:
	// ........ citors ........ //
	node() = default;

	// ........ setter ........ //
	void set_first_key(T value)
	{
		m_first = value;
	}
	void set_second_key(T value)
	{
		m_second = value;

		if (m_first > m_second)
		{
			std::swap(m_first, m_second);
		}
	}

	// ........ getter ........ //
	size_t get_keys_conut()const
	{
		return m_count;
	}
	ptr_type get_parent()const
	{
		return m_parent;
	}

	// ........ is based methods ........ //
	bool is_leaf()const { return m_is_leaf; }

private:
	// ........ pointer to parent ........ //
	ptr_type m_parent = nullptr;
	// ........ pointers to children ........ //
	ptr_type m_left = nullptr;
	ptr_type m_middle = nullptr;
	ptr_type m_right = nullptr;
	// ........ node values ........ //
	T m_first = T();
	T m_second = T();
	// ........ values count ........ //
	size_t m_count = 0;
};
