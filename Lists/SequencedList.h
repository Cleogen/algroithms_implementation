#pragma once
#include <ostream>

const int g_maxsize = 100;

class SequencedList {
	friend std::ostream &operator<<(std::ostream &, const SequencedList &);

public:
	SequencedList(int = g_maxsize);
	~SequencedList();
	SequencedList(const SequencedList &);
	SequencedList &operator=(const SequencedList &);
	int& operator[](const int&);
	const int& operator[](const int&) const;

	int size() const;
	void push_back(const int&);
	void add(const int&, const int&);
	void pop_back();
	void remove(const int&);
	void removeAll(const int&);

private:
	void extend();
	int m_maxsize;
	int m_index;
	int* m_data;
};
