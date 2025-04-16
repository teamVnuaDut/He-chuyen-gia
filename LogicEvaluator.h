#ifndef LOGIC_EVALUATOR_H
#define LOGIC_EVALUATOR_H

#include <string>
#include "KnowledgeBase.h"		//de su dung kb.hasFact()

//hm danh gia bieu thuc logic don gian
bool evaluateBooleanExpression(const std::string& expression, const KnowledgeBase& kb);

#endif // !LOGIC_EVALUATOR_H

