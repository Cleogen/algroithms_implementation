#include "SeqList.h"
#include <iostream>

std::ostream & operator<<(std::ostream& out,const SeqList &seqList)
{
	out << "\n[";
	for (int i = 0; i <= seqList.m_index; i++)
	{
		out << seqList[i] << ", ";
	}
	out << "]\n";

	return out;
}

SeqList::SeqList(int maxsize)
	:m_maxsize(maxsize)
	,m_index(0)
	,m_data(nullptr)
{
	m_data = new int[m_maxsize];
}

SeqList::~SeqList()
{
	delete[] m_data;
}

SeqList::SeqList(const SeqList &seqList)
	:m_maxsize(seqList.m_maxsize)
	,m_index(seqList.m_index)
	,m_data(nullptr)
{
	m_data = new int[m_maxsize];
	for (int i = 0; i < m_index; ++i)
	{
		m_data[i] = seqList[i];
	}
}

SeqList& SeqList::operator=(const SeqList& seqList)
{
	if (this != &seqList) {
		m_maxsize = seqList.m_maxsize;
		m_index = seqList.m_index;
		delete[] m_data;
		m_data = new int[m_maxsize];
		for (int i = 0; i < m_index; ++i)
		{
			m_data[i] = seqList[i];
		}
	}
	return *this;
}

int& SeqList::operator[](const int &index)
{
	if (index > size() || index < 0) {
		throw std::out_of_range("Index Invalid!");
	}
	return m_data[index];
}

const int& SeqList::operator[](const int &index) const
{
	if (index > size() || index < 0) {
		throw std::out_of_range("Index Invalid!");
	}
	return m_data[index];
}

int SeqList::size() const
{
	return m_index + 1;
}

void SeqList::push_back(const int &x)
{
	if (size() == m_maxsize) {
		extend();
	}
	m_data[++m_index] = x;
}

void SeqList::add(const int &index, const int &x)
{
	if (index > size() || index < 0) {
		throw std::out_of_range("Index Invalid!");
	}
	else
	{
		push_back(x);
		for (int i = m_index; i > index; --i)
		{
			int temp = m_data[i];
			m_data[i] = m_data[i - 1];
			m_data[i - 1] = temp;
		}
	}
}

void SeqList::pop_back()
{
	if (size() != 0)
		--m_index;
	else
		std::cout << "List is empty!\n";
}

void SeqList::remove(const int &index)
{
	if (size != 0) {
		for (int i = index; i < m_index; --i)
		{
			m_data[i] = m_data[i + 1];
		}
		--m_index;
	}
	else {
		std::cout << "List is empty!\n";
	}
}

void SeqList::removeAll(const int &x)
{
	for (int i = 0; i < size(); ++i)
	{
		if (m_data[i] == x)
			remove(i);
	}
}

void SeqList::extend()
{
	m_maxsize *= 2;
	int* temp = new int[m_maxsize];
	for (int i = 0; i < size(); ++i)
	{
		temp[i] = m_data[i];
	}
	delete[] m_data;
	m_data = temp;
}

