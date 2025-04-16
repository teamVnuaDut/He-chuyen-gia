#include "StringUtils.h"
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> splitByDelimiter(const string& str, const string& delimiter) {
	vector<string> tokens;
	size_t start = 0, pos = 0;
	while ((pos = str.find(delimiter, start)) != string::npos) {
		tokens.push_back(str.substr(start, pos - start));
		start = pos + delimiter.length();
	}
	tokens.push_back(str.substr(start));
	return tokens;
}
string trim(const string& s) {
	string result = s;
	result.erase(result.begin(), find_if(result.begin(), result.end(), [](unsigned char ch) { return !isspace(ch); }));
	result.erase(find_if(result.rbegin(), result.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), result.end());
	return result;
}
