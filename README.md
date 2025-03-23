```markdown
# Hệ Chuyên Gia (Expert System)

## Giới thiệu

Hệ chuyên gia (Expert System) là một ứng dụng mô phỏng suy luận và ra quyết định của các chuyên gia trong một lĩnh vực cụ thể. Dự án này được xây dựng bằng **C++**, chạy trên console, nhằm mục đích giải quyết vấn đề dựa trên tập hợp các luật (rules) và cơ sở tri thức (knowledge base) đã được định nghĩa trước. Đây là ứng dụng phù hợp để minh họa cách hoạt động của trí tuệ nhân tạo dạng quy tắc.

**Tính năng chính:**
- Xây dựng cơ sở tri thức theo định dạng các quy tắc (IF-THEN).
- Suy diễn tiến (Forward chaining) hoặc suy diễn lùi (Backward chaining).
- Gợi ý quyết định dựa trên dữ liệu đầu vào từ người dùng.

---

## Yêu cầu hệ thống

- **Hệ điều hành:** Windows, macOS, hoặc Linux.
- **Trình biên dịch C++:** GCC (g++), MSVC, hoặc Clang (hỗ trợ C++11 trở lên).
- **CMake:** Để build và quản lý dự án.
- **RAM:** 1GB hoặc cao hơn.

---

## Hướng dẫn cài đặt

### 1. Clone repository
Clone mã nguồn từ GitHub về máy:
```bash
git clone https://github.com/your-username/He-chuyen-gia.git
cd He-chuyen-gia
```

### 2. Build project
Sử dụng **CMake** để tạo build directory và biên dịch dự án:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### 3. Chạy chương trình
Sau khi build xong, bạn có thể chạy chương trình bằng lệnh:
```bash
./build/ExpertSystem
```

---

## Hướng dẫn sử dụng

1. **Khởi chạy hệ chuyên gia:**
   - Sau khi chạy chương trình, bạn sẽ được yêu cầu nhập thông tin đầu vào (facts) hoặc câu hỏi liên quan đến vấn đề bạn muốn giải quyết.

2. **Cấu hình cơ sở tri thức (Knowledge Base):**
   - Cơ sở tri thức được lưu trong một tệp `.txt`. Người dùng có thể chỉnh sửa hoặc cập nhật các luật bằng cách mở tệp này trong trình soạn thảo văn bản.
   - Định dạng luật cơ bản:
     ```
     IF <condition> THEN <result>
     ```

3. **Các chế độ suy diễn:**
   - **Forward chaining:** Tự động suy diễn dựa trên dữ liệu đầu vào.
   - **Backward chaining:** Người dùng đặt câu hỏi, hệ thống suy luận dựa trên câu hỏi để đưa ra kết quả.

4. **Ví dụ sử dụng:**
   - Hệ chuyên gia về chẩn đoán bệnh:
     ```
     IF temperature > 38 THEN fever
     IF fever AND cough THEN flu
     ```

5. **Xem kết quả:**
   - Kết quả sẽ được hiển thị trên console, cùng với chuỗi suy luận (reasoning trace) cho thấy hệ thống đã đi đến kết luận như thế nào.

---

## Đóng góp

Chúng tôi hoan nghênh mọi đóng góp từ cộng đồng để cải thiện hệ thống:
1. Fork repository.
2. Tạo nhánh mới (`git checkout -b feature-name`).
3. Commit và push thay đổi của bạn.
4. Tạo pull request trên GitHub.

---

## Giấy phép

Dự án này được phát hành dưới giấy phép **MIT License**. Vui lòng tham khảo file `LICENSE` để biết thêm chi tiết.
```

---
