#pragma once

template <typename T>
class node
{
public:
	using ptr_type = node<T>*;

	node() = default;
	node(T first = T(), T second = T())
		: m_first(first)
		, m_second(second)
	{
	}

	void set_second_key(T value)
	{
		m_second = value;

		if (m_first > m_second)
		{
			std::swap(m_first, m_second);
		}
	}
	void set_first_key(T value)      { m_first = value; }
	T get_firts_key()const           { return m_first;  }
	T get_second_key()const          { return m_second; }

	size_t   get_keys_conut()const   { return m_count;  }
	
	ptr_type get_parent()const       { return m_parent; }
	ptr_type get_left_child()const   { return m_left;   }
	ptr_type get_middle_child()const { return m_middle; }
	ptr_type get_right_child()const  { return m_right;  }

	bool is_leaf()const 
	{ 
		return (m_left == nullptr && m_middle == nullptr && m_right == nullptr);
	}

private:
	ptr_type m_parent = nullptr;

	ptr_type m_left = nullptr;
	ptr_type m_middle = nullptr;
	ptr_type m_right = nullptr;

	T m_first = T();
	T m_second = T();

	size_t m_count = 0;
};
