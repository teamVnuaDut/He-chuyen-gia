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
	const vector<Rule>& getRules() const;
	void displayRules() const;

	//ham lay cac fact cho nguoi dung
	const vector<string>& getFacts() const;

	//ham xu l file
	bool loadFromFile(const string& filename);
	bool saveToFile(const string& filename) const;

	//ham update fact va rule
	bool updateFact(const string& oldFact, const string& newFact);
	bool updateRule(const string& ruleIdentifier, const Rule& newRule);

private:
	vector<string> facts;
	vector<Rule> rules;
};

#endif // !KNOWLEDGEBASE_H
