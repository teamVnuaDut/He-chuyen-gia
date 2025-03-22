#include "InferenceEngine.h"
#include <iostream>

using namespace std;

void InferenceEngine::infer(const KnowledgeBase& kb)
{
	cout << "Inference Engine dang xu ly..." << endl;

	if (kb.hasFact("Có hàng") && kb.hasFact("Còn trong kho"))
	{
		cout << "Bên kho chúng tôi có sẵn hàng để gửi cho bạn xem!!!" << endl;
	}
	else
	{
		cout << "Bên kho chúng tôi không có hàng mẫu để bạn xem" << endl;
	}
}