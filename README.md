# Embedded_System_PTIT_Exercise_7

## Giao Tiếp I2C Master trên STM32F1

### Giới thiệu  
Dự án này tập trung vào việc triển khai giao thức I²C (Inter-Integrated Circuit) trên vi điều khiển STM32F103C8T6. Trong bài tập này, STM32 sẽ được cấu hình làm thiết bị Master để giao tiếp với một cảm biến Slave (ví dụ: MPU-6050). Chương trình sẽ đọc dữ liệu từ cảm biến và gửi thông tin này lên máy tính thông qua giao tiếp UART để hiển thị trên terminal và giám sát quá trình.

Đây là một kỹ năng quan trọng trong lập trình nhúng, cho phép vi điều khiển giao tiếp với hàng nghìn loại cảm biến, bộ nhớ và các thiết bị ngoại vi khác chỉ với hai dây tín hiệu.

### Yêu cầu & Tính Năng Chính 
- **Cấu hình I2C Master**: Khởi tạo và cấu hình giao tiếp I2C1 của STM32 để hoạt động ở chế độ Master.
  
- **Giao tiếp với Slave**: Viết các hàm cấp thấp để thực hiện việc đọc dữ liệu từ một địa chỉ thanh ghi cụ thể của thiết bị Slave.

- **Giám sát qua UART**: Dữ liệu được đọc từ cảm biến sẽ được định dạng và gửi lên PC thông qua giao tiếp USART1 (9600 baud, 8-bit, không chẵn lẻ, 1 stop bit) để hiển thị trên terminal.

- **Báo hiệu trạng thái**: Sử dụng một đèn LED để báo hiệu trạng thái của chương trình (ví dụ: LED nhấp nháy mỗi khi dữ liệu được đọc thành công từ cảm biến).

### Phần Cứng Sử Dụng 🛠
- **Board STM32F103C8T6** ("Blue Pill").
- **Cảm biến I2C MPU-6050** (Gia tốc kế & Con quay hồi chuyển).
- **Mạch chuyển USB-to-TTL** (CP2102 hoặc FT232).
- **Mạch nạp ST-Link V2**.
- **1x LED** và **điện trở hạn dòng** (~220Ω).
- **Dây cắm** và **breadboard**.

### Hướng Dẫn Cài Đặt & Chạy

1. **Cài đặt môi trường phát triển**:
   - Cài đặt **Keil** hoặc **STM32CubeIDE** cho việc phát triển ứng dụng.
   - Cài đặt các trình điều khiển cần thiết cho **ST-Link** và **USB-to-TTL**.

2. **Cấu hình phần mềm**:
   - Tạo dự án mới và chọn STM32F103C8T6 làm vi điều khiển.
   - Cấu hình giao tiếp I2C và USART trong phần mềm.
   - Cài đặt và flash chương trình lên board STM32F103.

3. **Kết nối phần cứng**:
   - Kết nối **MPU-6050** với STM32F103C8T6 qua giao tiếp I2C.
   - Kết nối **USB-to-TTL** với máy tính để giám sát qua UART.
   - Kết nối **LED** với một chân GPIO của STM32 để báo hiệu trạng thái.

4. **Chạy chương trình**:
   - Sau khi chương trình được tải lên board, mở terminal (ví dụ: **PuTTY**, **Tera Term**) và kết nối qua cổng COM.
   - Chương trình sẽ hiển thị dữ liệu đọc được từ cảm biến trên terminal.
   - LED sẽ nhấp nháy mỗi khi dữ liệu được đọc thành công.

### Giấy Phép
Dự án này được cấp phép theo **MIT License**. Xem file [LICENSE](LICENSE) để biết thêm chi tiết.
