#include "KnowledgeBase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void KnowledgeBase::addFact(const string& fact) {
    facts.push_back(fact);
}

void KnowledgeBase::displayFacts() const {
    cout << "Các facts hiện có:" << endl;
    for (const auto& fact : facts) {
        cout << " - " << fact << endl;
    }
}

bool KnowledgeBase::hasFact(const string& fact) const {
    for (const auto& f : facts) {
        if (f == fact)
            return true;
    }
    return false;
}

void KnowledgeBase::addRule(const Rule& rule) {
    rules.push_back(rule);
}

const std::vector<Rule>& KnowledgeBase::getRules() const {
    return rules;
}

void KnowledgeBase::displayRules() const {
    cout << "Các rules hiện có:" << endl;
    for (const auto& rule : rules) {
        cout << " - IF ";
        for (size_t i = 0; i < rule.premises.size(); ++i) {
            cout << rule.premises[i];
            if (i != rule.premises.size() - 1)
                cout << " AND ";
        }
        cout << " THEN " << rule.conclusion << endl;
    }
}

const vector<std::string>& KnowledgeBase::getFacts() const {
    return facts;
}

bool KnowledgeBase::loadFromFile(const string& filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "Khong mo duoc file " << filename << endl;
        return false;
    }

    string line;
    while (getline(infile, line))
    {
        //loai bo khoang trang dau va cuoi dong
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch)
            {
                return !isspace(ch);
            }));
        line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), line.end());
        
        if (line.empty()) continue;

        //dau dong bat dau bang FACT
        if (line.find("FACT:") == 0)
        {
            //bo fact
            string fact = line.substr(5);

            //loai bo khoang trang thua
            fact.erase(0, fact.find_first_of(" \t"));
            addFact(fact);
        }

        //dau dong bat dau bang rule
        if (line.find("RULE:") == 0)
        {
            //bo rule
            string ruleLine = line.substr(5);
            size_t ifPos = ruleLine.find("IF ");
            if (ifPos == std::string::npos) continue;
            ruleLine = ruleLine.substr(ifPos + 3);  // bỏ "IF "

            size_t thenPos = ruleLine.find(" THEN ");
            if (thenPos == std::string::npos) continue;

            std::string premisesStr = ruleLine.substr(0, thenPos);
            std::string conclusion = ruleLine.substr(thenPos + 6); // bỏ " THEN "

            // Xử lý danh sách premise, dùng " AND " làm dấu phân cách
            std::vector<std::string> premises;
            size_t start = 0, pos;
            while ((pos = premisesStr.find(" AND ", start)) != std::string::npos) {
                std::string token = premisesStr.substr(start, pos - start);
                token.erase(token.begin(), std::find_if(token.begin(), token.end(), [](unsigned char ch) { return !std::isspace(ch); }));
                token.erase(std::find_if(token.rbegin(), token.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), token.end());
                if (!token.empty())
                    premises.push_back(token);
                start = pos + 5; // độ dài của " AND "
            }
            // Lấy token cuối cùng
            std::string lastToken = premisesStr.substr(start);
            lastToken.erase(lastToken.begin(), std::find_if(lastToken.begin(), lastToken.end(), [](unsigned char ch) { return !std::isspace(ch); }));
            lastToken.erase(std::find_if(lastToken.rbegin(), lastToken.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), lastToken.end());
            if (!lastToken.empty())
                premises.push_back(lastToken);

            // Cũng loại bỏ khoảng trắng dư ở conclusion
            conclusion.erase(conclusion.begin(), std::find_if(conclusion.begin(), conclusion.end(), [](unsigned char ch) { return !std::isspace(ch); }));
            conclusion.erase(std::find_if(conclusion.rbegin(), conclusion.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), conclusion.end());

            Rule rule(premises, conclusion);
            addRule(rule);
        }
    }

    infile.close();
    return true;
}

// Hàm saveToFile: ghi toàn bộ facts và rules ra file theo định dạng chuẩn
bool KnowledgeBase::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Không mở được file để ghi: " << filename << std::endl;
        return false;
    }

    // Ghi facts
    for (const auto& fact : facts) {
        ofs << "FACT:" << fact << std::endl;
    }

    // Ghi rules
    for (const auto& rule : rules) {
        ofs << "RULE:IF ";
        for (size_t i = 0; i < rule.premises.size(); ++i) {
            ofs << rule.premises[i];
            if (i != rule.premises.size() - 1)
                ofs << " AND ";
        }
        ofs << " THEN " << rule.conclusion << std::endl;
    }

    ofs.close();
    return true;
}

bool KnowledgeBase::updateFact(const string& oldFact, const string& newFact)
{
    //tim trong du lieu
    for (auto& fact : facts)
    {
        if (fact == oldFact)
        {
            fact = newFact;
            return true;
        }
    }
    return false;
}

bool KnowledgeBase::updateRule(const string& ruleIdentifier, const Rule& newRule)
{
    for (auto& rule : rules)
    {
        if (rule.conclusion == ruleIdentifier)
        {
            rule = newRule;
            return true;
        }
    }
    return false;
}
