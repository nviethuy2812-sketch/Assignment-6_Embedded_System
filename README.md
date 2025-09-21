# Embedded_System_PTIT_Exercise_7
## Giới thiệu  
Dự án này sử dụng vi điều khiển STM32F103C8T6 để giao tiếp với cảm biến ánh sáng **BH1750** thông qua chuẩn I2C. Dữ liệu cường độ ánh sáng (đơn vị: lux) được đọc từ cảm biến và hiển thị lên máy tính thông qua giao tiếp UART.

Ứng dụng phù hợp cho các bài học nền tảng về I2C, UART và cảm biến môi trường trong các hệ thống nhúng.

## Yêu Cầu & Chức Năng 🎯
- **Khởi tạo giao tiếp I2C**: Cấu hình I2C để giao tiếp với cảm biến BH1750.
- **UART để giám sát dữ liệu**: Sử dụng USART1 để in kết quả đọc được từ cảm biến ra terminal trên PC.
- **Giao tiếp với cảm biến BH1750**:
  - Khởi động cảm biến bằng lệnh `BH1750_Init()`.
  - Đọc dữ liệu ánh sáng thông qua `BH1750_ReadLight()` và in ra bằng `printf()`.
- **Sử dụng Timer và Delay**: Dùng Timer để tạo delay chính xác giữa các lần đọc dữ liệu.

## Cảm Biến BH1750
- Là cảm biến đo cường độ ánh sáng kỹ thuật số, giao tiếp I2C.
- Đơn vị đo: Lux (Lx).
- Địa chỉ I2C mặc định: `0x23` hoặc `0x5C` tùy vào chân ADD.

## Phần Cứng Sử Dụng 🛠️
- **STM32F103C8T6** (Blue Pill)
- **Cảm biến BH1750**
- **Mạch chuyển USB-to-TTL** (CP2102, FT232, CH340, ...)
- **ST-Link V2**
- **Breadboard, dây cắm**
- **Nguồn 3.3V hoặc 5V tùy vào module cảm biến**

## Kết Nối Phần Cứng 🔌

| BH1750     | STM32F103     |
|------------|---------------|
| VCC        | 3.3V hoặc 5V   |
| GND        | GND           |
| SDA        | PB7           |
| SCL        | PB6           |
