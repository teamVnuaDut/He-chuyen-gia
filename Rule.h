#pragma once
#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
using namespace std;

struct Rule
{
	vector<string> premises;		//danh sach dieu kien can kiem tra
	string conclusion;				//ket luan neu tat ca dieu kien dung

	//khoi tao rule
	Rule(const vector<string>& p, const string& c)
		: premises(p), conclusion(c) {
	}
};
#endif // !RULE_H
