#pragma once


template <typename T>
class node
{
public:
	using ptr_type = node<T>*;

	node() = default;
	node(T first, ptr_type left, ptr_type middle, ptr_type right, ptr_type temp, ptr_type parent)
		: m_first(first)
		, m_left(left)
		, m_middle(middle)
		, m_right(right)
		, m_temp(temp)
		, m_parent(parent)
	{
		m_count = 1;
	}

	bool is_leaf()const
	{
		return !this->m_left;
	}

	void set_key(T value)
	{
		if (m_count == 0)
		{
			m_first = value;
			m_count++;
			return;
		}

		else if (m_count == 1)
		{
			m_second = value;
			m_count++;
			if (m_first > m_second)
			{
				std::swap(m_first, m_second);
			}
			return;
		}

		if (m_count == 2)
		{
			m_third = value;
			m_count++;
			sort();
			return;
		}
	}

	void become_two_node(T value, ptr_type node_1, ptr_type node_2)
	{
		m_first = value;
		m_second = T();
		m_third = T();

		m_left = node_1;
		m_right = node_2;
		m_middle = nullptr;
		m_temp = nullptr;

		m_count = 1;
	}

	void show()
	{
		if (m_count == 1)
		{
			std::cout <<"( "<<m_first << " )";
		}

		else if (m_count == 2)
		{
			std::cout << "( " << m_first << ", " << m_second << " )";
		}
		std::cout << std::endl;
	}

private:
	void sort()
	{
		if (m_first > m_second)
		{
			std::swap(m_first, m_second);
			if (m_second > m_third)
			{
				std::swap(m_second, m_third);
			}
		}

		else if (m_second > m_third)
		{
			std::swap(m_second, m_third);
			if (m_first > m_second)
			{
				std::swap(m_first, m_second);
			}
		}
	}

public:
	ptr_type m_parent = nullptr;

	ptr_type m_left = nullptr;
	ptr_type m_middle = nullptr;
	ptr_type m_right = nullptr;
	ptr_type m_temp = nullptr;

	T m_first = T();
	T m_second = T();
	T m_third = T();

	size_t m_count = 0;
};
