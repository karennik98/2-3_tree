//#pragma once
//#include <iterator>
//
//	// ............... iterator for tree ............... //
//	using base_iterator = std::iterator<std::forward_iterator_tag, node_ptr_type>;
//
//	class iterator : public base_iterator
//	{
//	public:
//
//		//iterator&          operator++();
//		//iterator           operator++(int);
//		bool has_next()const;
//		iterator& next();
//		val_ref_type       operator*();
//		val_ptr_type       operator->();
//		const val_ptr_type operator->() const;
//		bool               operator==(const iterator& itr) const;
//		bool               operator!=(const iterator& itr) const;
//	private:
//		node_ptr_type m_itr = nullptr;
//	};
//
//
//// .......................................... iteratir defination .......................................... //
//template<typename T>
//bool tree<T>::iterator::has_next()const
//{
//	return m_itr->is_leaf();
//}
//
//template<typename T>
//tree<T>::iterator& tree<T>::iterator::next()
//{
//	if (m_itr->is_leaf())
//	{
//		return m_itr;
//	}
//
//
//}
//
//template<typename T>
//tree<T>::val_ref_type tree<T>::iterator::operator*()
//{
//
//}
//
//template<typename T>
//tree<T>::val_ptr_type tree<T>::iterator::operator->()
//{
//
//}
//
//template<typename T>
//const tree<T>::val_ptr_type tree<T>::iterator::operator->() const
//{
//
//}
//
////template<typename T>
////tree<T>::iterator& tree<T>::iterator::operator++()
////{
////	std::queue<node_ptr_type> queue;
////
////	if (!m_itr)
////	{
////		return *this;
////	}
////
////	queue.push(m_itr);
////
////	node_ptr_type tmp_node = nullptr;
////
////	while (!queue.empty())
////	{
////		tmp_node = queue.front();
////		queue.pop();
////		if(tmp_node->get_child())
////	}
////
////}
//
////template<typename T>
////tree<T>::iterator tree<T>::iterator::operator++(int)
////{
////
////}
//
//template<typename T>
//bool tree<T>::iterator::operator==(const tree<T>::iterator& itr)const
//{
//
//}
//
//template<typename T>
//bool tree<T>::iterator::operator!=(const tree<T>::iterator& itr)const
//{
//
//}
//// .......................................... end iteratir defination .......................................... //
