#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

class UnitConverter {
public:
	void add_fact(const std::string &u1, const std::string &u2, const float &v1, const float &v2);

	float calculate(const std::string&, const std::string&, const float &) const;

private:
	std::vector<std::string> m_units;
	std::map<std::pair<int, int>, float> m_relations;

	std::pair<int, int> get_or_create_ids(const std::string&, const std::string&);
	std::pair<int, int> get_ids(const std::string&, const std::string&) const;
	float step(int, int) const;
};
