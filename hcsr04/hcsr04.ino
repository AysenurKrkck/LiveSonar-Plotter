// --- Pin Tanımlamaları / Pin Definitions ---
#define TRIG_PIN 4      // TR: Ultrasonik sensörün tetikleme (Trig) pini | EN: Trigger pin of the ultrasonic sensor
#define ECHO_PIN 3      // TR: Ultrasonik sensörün yankı alıcı (Echo) pini | EN: Echo pin of the ultrasonic sensor
#define red_led 8       // TR: Kırmızı LED pini | EN: Red LED pin
#define yellow_led 9    // TR: Sarı LED pini | EN: Yellow LED pin
#define green_led 10    // TR: Yeşil LED pini | EN: Green LED pin
#define buzzer 11       // TR: Buzzer pini | EN: Buzzer pin

// --- Kurulum Bölümü / Setup Section (Runs once) ---
void setup() {
  Serial.begin(9600);   // TR: Seri portu başlat (9600 baud) | EN: Start serial communication at 9600 baud
  
  // TR: Giriş/Çıkış modlarını belirleme | EN: Configure pin modes
  pinMode(TRIG_PIN, OUTPUT);  // TR: Trig çıkış pini | EN: Trig as OUTPUT
  pinMode(ECHO_PIN, INPUT);   // TR: Echo giriş pini | EN: Echo as INPUT
  pinMode(red_led, OUTPUT);   // TR: LED'ler çıkış pini | EN: LEDs as OUTPUTs
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(buzzer, OUTPUT);    // TR: Buzzer çıkış pini | EN: Buzzer as OUTPUT
}

// --- Ana Döngü / Main Loop (Repeats continuously) ---
void loop() {
  // TR: Tetikleme sinyali gönderme | EN: Triggering the sensor (sending sound wave)
  digitalWrite(TRIG_PIN, LOW);        // TR: Trig pinini sıfırla | EN: Clear the trig pin
  delayMicroseconds(5);               // TR: 5 us bekle | EN: Wait 5 us
  digitalWrite(TRIG_PIN, HIGH);       // TR: 10 us'lik sinyal gönder | EN: Send 10 us high pulse
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);        // TR: Sinyali kes | EN: Stop the trigger pulse
  
  // TR: Her döngü başında tüm bileşenleri sıfırla (kapat)
  // EN: Reset (turn off) all LEDs and the buzzer at the start of each loop
  digitalWrite(red_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(buzzer, LOW);

  // TR: Geri dönen dalganın süresini ölç | EN: Measure the travel time of the returning wave
  long sure = pulseIn(ECHO_PIN, HIGH);

  // TR: Süreyi santimetreye (cm) çevir | EN: Convert the travel time into centimeters (cm)
  // (Formula: Speed of sound = 340 m/s -> 0.034 cm/us. Divided by 2 for round trip)
  long mesafe = sure * 0.034 / 2;

  // TR: Ölçülen mesafeyi seri ekrana yazdır | EN: Print the measured distance to the Serial Monitor
  Serial.println(mesafe);

  // --- Mesafe Kontrolü / Distance Evaluation ---

  // TR: Durum 1 - Güvenli Bölge (>10 cm veya hata durumu 0 cm)
  // EN: Case 1 - Safe Zone (>10 cm or reading error 0 cm)
  if (mesafe > 10 || mesafe == 0) {
    digitalWrite(red_led, LOW);      // TR: Kırmızı kapalı | EN: Red OFF
    digitalWrite(yellow_led, LOW);   // TR: Sarı kapalı | EN: Yellow OFF
    digitalWrite(green_led, HIGH);   // TR: Yeşil açık | EN: Green ON
    digitalWrite(buzzer, LOW);       // TR: Buzzer kapalı | EN: Buzzer OFF
  }

  // TR: Durum 2 - Uyarı Bölgesi (5 cm ile 10 cm arası)
  // EN: Case 2 - Warning Zone (Between 5 cm and 10 cm)
  else if (mesafe <= 10 && mesafe > 5) { 
    digitalWrite(red_led, LOW);      // TR: Kırmızı kapalı | EN: Red OFF
    digitalWrite(yellow_led, HIGH);  // TR: Sarı açık | EN: Yellow ON
    digitalWrite(green_led, LOW);    // TR: Yeşil kapalı | EN: Green OFF
    
    // TR: Kısa uyarı sesi | EN: Short beep sound
    digitalWrite(buzzer, HIGH); 
    delay(50); 
    digitalWrite(buzzer, LOW); 
  } 

  // TR: Durum 3 - Tehlike Bölgesi (0 cm ile 5 cm arası)
  // EN: Case 3 - Danger Zone (Between 0 cm and 5 cm)
  else if (mesafe <= 5 && mesafe > 0) { 
    digitalWrite(green_led, LOW);    // TR: Yeşil kapalı | EN: Green OFF
    digitalWrite(yellow_led, LOW);   // TR: Sarı kapalı | EN: Yellow OFF
    digitalWrite(red_led, HIGH);     // TR: Kırmızı açık | EN: Red ON
    
    // TR: Sürekli acı tonlu ses | EN: Continuous warning tone
    digitalWrite(buzzer, HIGH); 
   
    
  }
  
  // TR: Bir sonraki ölçümden önce 500 ms bekle | EN: Wait 500 ms before the next measurement
  delay(500);
}
