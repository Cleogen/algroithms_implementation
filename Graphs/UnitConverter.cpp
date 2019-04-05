#include "UnitConverter.h"

UnitConverter::UnitConverter() {
	m_units = std::vector<std::string>();
	m_relations = std::map<std::pair<int, int>, float>();
}

void UnitConverter::add_fact(const std::string &u1, const std::string &u2, const float &v1, const double &v2) {
	auto rel = get_or_create_ids(u1, u2);
	float ratio = v2 / v1;
	auto item = m_relations.find(rel);

	if (item == m_relations.end())
		m_relations.insert(std::make_pair(rel, ratio));
	else
		(*item).second = ratio;
}

const std::pair<int, int> UnitConverter::get_or_create_ids(const std::string &u1, const std::string &u2) {
	auto rel = get_ids(u1, u2);
	if (rel.first == -1) {
		m_units.push_back(u1);
		rel.first = m_units.size() - 1;
	}
	if (rel.second == -1) {
		m_units.push_back(u2);
		rel.second = m_units.size() - 1;
	}
	return rel;
}

float UnitConverter::calculate(const std::string &u1, const std::string &u2, const double &v1) const {
	auto rel = get_ids(u1, u2);
	return v1 * step(rel.first, rel.second);
}

float UnitConverter::step(int s, int e)  const {
	std::map<int, float> path;
	path.insert(std::make_pair(s,1));
	auto v = std::make_pair(0, 1.0f);
	auto relations = m_relations;
	auto p_end = path.end();
	auto r_end = relations.end();
	auto p_iter = path.begin();
	auto r_iter = relations.begin();

	while (!path.empty()) {
		while (p_iter != p_end) {
			while (r_iter != r_end) {
				if ((*r_iter).first.first == (*p_iter).first)
					v = {(*r_iter).first.second, (*p_iter).second * (*r_iter).second};
				else if ((*r_iter).first.second == (*p_iter).first)
					v = {(*r_iter).first.first, (*p_iter).second / (*r_iter).second};
				else{
					r_iter++;
					continue;
				}
				if (v.first == e)
					return v.second;
				if (path.find(v.first) == path.end())
					path.insert(v);
				r_iter = relations.erase(r_iter);
			}
			p_iter = path.erase(p_iter);
			r_iter = relations.begin();
		}
		p_iter = path.begin();
	}
	return 0;
}

std::pair<int, int> UnitConverter::get_ids(const std::string &u1, const std::string &u2) const {
	int one_i = -1, two_i = -1;
	for (int i = 0; i < m_units.size(); ++i) {
		if (m_units[i] == u1)
			one_i = i;
		else if (m_units[i] == u2)
			two_i = i;
		if (one_i > 0 && two_i > 0)
			break;
	}
	return std::pair<int, int>(one_i, two_i);
}
