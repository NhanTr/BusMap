# BusMap
# 🚍 BusMap

**BusMap** là một ứng dụng C++ sử dụng thư viện [SFML](https://www.sfml-dev.org/) để mô phỏng bản đồ xe buýt trong thành phố. Ứng dụng cho phép người dùng tìm đường đi tối ưu giữa hai trạm xe buýt dựa trên dữ liệu thực tế.

---

## 📁 Cấu trúc thư mục

├── assets/ # Dữ liệu và tài nguyên (font, hình ảnh, file dữ liệu)
│ ├── data/ # File dữ liệu đồ thị (VD: danh sách trạm, tuyến)
│ ├── font/ # Phông chữ sử dụng trong giao diện
│ └── images/ # Ảnh hiển thị (bản đồ, icon,...)
├── inc/ # Header files (.h)
├── src/ # Source code chính (.cpp)
├── makefile # Tập tin build project
├── sfml-app # File thực thi sau khi build (bỏ qua khi push)
└── .gitignore # Bỏ qua file không cần thiết khi push


---

## 🛠 Cài đặt và chạy

- build chương trình bằng lệnh make
- chạy chương trình bằng lệnh ./sfml-app

### 🔧 Yêu cầu

- C++17 trở lên
- [SFML 3.0.0+](https://www.sfml-dev.org/download.php)

### 💻 Cài đặt SFML

#### Trên macOS (dùng Homebrew):
```bash
brew install sfml
