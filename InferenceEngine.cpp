#include "InferenceEngine.h"
#include "StringUtils.h"
#include "LogicEvaluator.h"
#include "Rule.h"
#include <sstream>
#include <iostream>

using namespace std;

//ham helper de noi cac phan cua rule.premises co nhieu phan 
string joinPremises(const vector<string>& premises, const string &delemiter = " AND ")
{
	ostringstream oss;
	for (size_t i = 0; i < premises.size(); ++i)
	{
		oss << premises[i];
		if (i != premises.size() - 1)
			oss << delemiter;
	}
	return oss.str();
}

void InferenceEngine::infer(const KnowledgeBase& kb)
{
	cout << "Inference Engine dang xu ly cac rule nang cao ..." << endl;

	const auto& rules = kb.getRules();
	for (const auto& rule : rules)
	{
		string expression;
		if (rule.premises.size() == 1)
		{
			expression = rule.premises[0];
		}
		else
		{
			expression = joinPremises(rule.premises);
		}

		//gia su evaluateBooleanExpression duoc dinh nghia o day hoac o noi khac
		if (evaluateBooleanExpression(expression, kb))
		{
			cout << "Ket luan: " << rule.conclusion << endl;
		}
	}
	if (kb.hasFact("Có hàng") && kb.hasFact("Còn trong kho"))
	{
		cout << "Bên kho chúng tôi có sẵn hàng để gửi cho bạn xem!!!" << endl;
	}
	else
	{
		cout << "Bên kho chúng tôi không có hàng mẫu để bạn xem" << endl;
	}
}