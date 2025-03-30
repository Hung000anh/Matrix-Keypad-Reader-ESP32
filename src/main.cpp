#include <Keypad.h>

// Kích thước bàn phím (4 hàng x 4 cột)
const byte ROWS = 4; 
const byte COLS = 4; 

// Định nghĩa ký tự cho từng nút trên bàn phím
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Chân GPIO ESP32 kết nối với các hàng và cột của bàn phím
byte rowPins[ROWS] = {13, 12, 14, 27}; // Chân hàng
byte colPins[COLS] = {26, 25, 33, 32}; // Chân cột

// Khởi tạo đối tượng Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
}

void loop() {
  char key = keypad.getKey(); // Đọc phím bấm

  if (key) {
    Serial.print("Nút bấm: ");
    Serial.println(key);
  }
}
