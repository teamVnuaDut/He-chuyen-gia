#include <iostream>
#include "KnowledgeBase.h"
#include "InferenceEngine.h"
#include "ExplanationEngine.h"

using namespace std;

int main()
{
	cout << "Khởi tạo hệ chuyên gia!!!";

	//Tao cac doi tuong module
	KnowledgeBase kb;
	InferenceEngine ie;
	ExplanationEngine ee;

	//them some fact vao knowledgeBase
	kb.addFact("Có hàng");
	kb.addFact("Còn trong kho");

	//Hien thi cac fact hien co
	kb.displayFacts();

	//thuc hien suy dien dua tren KB
	ie.infer(kb);

	//giai thich qua trinh suy dien
	ee.explain();

	return 0;
}