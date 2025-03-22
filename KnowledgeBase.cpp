#include "KnowledgeBase.h"
#include <iostream>

using namespace std;

void KnowledgeBase::addFact(const string& fact)
{
	facts.push_back(fact);
}

void KnowledgeBase::displayFacts() const
{
	cout << "Cac fact hien co: " << endl;
	for (const auto& fact : facts)
	{
		cout << " - " << fact << endl;
	}
}

bool KnowledgeBase::hasFact(const string& fact) const
{
	for (const auto& f : facts)
	{
		if (f == fact)
		{
			return true;
		}
	}
	return false;
}