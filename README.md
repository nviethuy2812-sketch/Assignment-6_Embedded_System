# Assignment-7_Embedded_System  
## Giao tiếp SPI và UART trên STM32F103

### 🧾 Giới thiệu

Dự án này minh họa cách cấu hình vi điều khiển **STM32F103C8T6** để giao tiếp dữ liệu qua **SPI** và hiển thị kết quả qua **UART**. Cụ thể:

- Vi điều khiển gửi một byte dữ liệu (`0x44`) qua SPI đến một thiết bị Slave.
- Nhận lại dữ liệu phản hồi.
- Hiển thị dữ liệu gửi và nhận qua UART lên terminal trên máy tính.

Ứng dụng giúp hiểu rõ cách hoạt động của **SPI (Master Mode)** và **UART (Serial Debugging)**, hai giao thức rất phổ biến trong các hệ thống nhúng.

---

### 🎯 Tính năng chính

- **Cấu hình UART (USART1)** để gửi chuỗi dữ liệu đến terminal.
- **Cấu hình SPI1 (Master)** để truyền và nhận dữ liệu với thiết bị ngoại vi.
- **Điều khiển chân NSS (PA4)** thủ công để kích hoạt giao tiếp SPI.
- **Gửi/nhận và hiển thị dữ liệu tuần tự**, delay mỗi lần truyền.

---

### ⚙️ Hoạt động của chương trình

1. Khởi tạo USART1 và SPI1.
2. Trong vòng lặp:
   - Kéo chân **PA4** xuống mức thấp (chọn Slave).
   - Gửi byte `0x44` và nhận lại dữ liệu qua SPI.
   - Kéo PA4 lên lại (ngắt kết nối Slave).
   - Hiển thị kết quả gửi/nhận qua UART.
   - Delay khoảng ~1 giây.

Ví dụ output trên terminal:

