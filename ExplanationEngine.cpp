#include "ExplanationEngine.h"
#include <iostream>

using namespace std;

void ExplanationEngine::explain()
{
	cout << "Giải thích: Hệ thống kiểm tra sự tồn tại của các facts 'Có hàng sẵn' và 'Có hàng trong kho'" << endl;
	cout << "Nếu cả hai tồn tại, hệ sẽ kết luận rằng có hàng sẵn để cho khách hàng xem!" << endl;
}
