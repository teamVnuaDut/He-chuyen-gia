#pragma once
#ifndef INFERENCEENGINE_H
#define INFERENCEENGINE_H

#include "KnowledgeBase.h"

class InferenceEngine
{
public:
	//ham suy dien du tren du lieu cua he tri thuc
	void infer(const KnowledgeBase& kb);
};

#endif // !INFERENCEENGINE_H
