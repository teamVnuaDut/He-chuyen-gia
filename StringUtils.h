#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>
using namespace std;

//ham tach chuoi theo delimiter
vector<string> splitByDelimiter(const string& str, const string& delimiter);

//ham cat khoang trang dau va cuoi chuoi
string trim(const string& str);

#endif // !STRING_UTILS_H
