#include "LogicEvaluator.h"
#include "StringUtils.h"  // Bao gồm các hàm splitByDelimiter và trim
#include <vector>

// Hàm evaluateBooleanExpression nhận vào một biểu thức chuỗi và đối tượng KnowledgeBase.
// Nó thực hiện các bước sau:
// 1. Tách biểu thức thành các phần theo " OR ".
// 2. Với mỗi nhánh của OR, tách theo " AND ".
// 3. Kiểm tra từng token: nếu có tiền tố "NOT ", đảo kết quả.
// 4. Nếu tất cả các điều kiện của một nhánh AND đều đúng, thì biểu thức trả về true.
bool evaluateBooleanExpression(const std::string& expr, const KnowledgeBase& kb) {
    // Tách theo " OR " (vì OR có độ ưu tiên thấp hơn AND)
    std::vector<std::string> orTokens = splitByDelimiter(expr, " OR ");

    for (const auto& orPart : orTokens) {
        // Với từng nhánh OR, tách theo " AND "
        std::vector<std::string> andTokens = splitByDelimiter(orPart, " AND ");
        bool branchTrue = true;

        for (auto token : andTokens) {
            // Loại bỏ khoảng trắng thừa
            token = trim(token);
            bool negate = false;

            // Kiểm tra nếu token có bắt đầu bằng "NOT "
            if (token.find("NOT ") == 0) {
                negate = true;
                token = trim(token.substr(4)); // Bỏ phần "NOT " và cắt khoảng trắng
            }

            // Kiểm tra xem fact có tồn tại trong KnowledgeBase không
            bool factExists = kb.hasFact(token);
            if (negate) {
                factExists = !factExists;
            }

            if (!factExists) {
                branchTrue = false;
                break;
            }
        }

        // Nếu bất kỳ nhánh OR nào trả về true thì tổng thể biểu thức đúng
        if (branchTrue)
            return true;
    }

    return false;
}