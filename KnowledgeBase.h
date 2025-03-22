#pragma once
#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H

#include <string>
#include <vector>
#include "Rule.h"

using namespace std;

//tao lop knowledge
class KnowledgeBase {
public:
	// ham them 1 fact vao co so tri thuc
	void addFact(const string& fact);

	//hien thi cac fact co trong kb
	void displayFacts() const;

	//kiem tra su ton tai cua 1 fact
	bool hasFact(const string& fact) const;

	//tao cho rule
	void addRule(const Rule& rule);
	const vector<Rule>& getRules();
	void displayRules() const;

private:
	vector<string> facts;
	vector<Rule> rules;
};

#endif // !KNOWLEDGEBASE_H
