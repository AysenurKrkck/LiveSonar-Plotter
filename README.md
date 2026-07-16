# LiveSonar-Plotter: Real-Time Data Visualization with Arduino & Python
## (Arduino + Python ile Gerçek Zamanlı Veri Görselleştirme ve Analiz)

[![Arduino](https://img.shields.io/badge/Hardware-Arduino-00979D?style=flat-for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Python](https://img.shields.io/badge/Software-Python%203.x-3776AB?style=flat-for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-for-the-badge)](https://opensource.org/licenses/MIT)

LiveSonar-Plotter is a physical computing and live data analytics project. It captures high-frequency distance measurements from an HC-SR04 ultrasonic sensor via Arduino and streams them to a Python-driven dashboard for instantaneous mathematical analysis and dynamic visualization.

LiveSonar-Plotter, fiziksel programlama ve canlı veri analitiği projesidir. HC-SR04 ultrasonik sensörden alınan yüksek frekanslı mesafe ölçümlerini Arduino üzerinden yakalar ve anlık matematiksel analiz ile dinamik görselleştirme için Python tabanlı bir kontrol paneline aktarır.

---

## 📖 Table of Contents / İçindekiler
- [Key Features / Öne Çıkan Özellikler](#-key-features--öne-çıkan-özellikler)
- [Hardware Schematic & Components / Donanım Şeması ve Bileşenler](#-hardware-schematic--components--donanım-şeması-ve-bileşenler)
- [Software Implementation / Yazılım Kurulumu](#-software-implementation--yazılım-kurulumu)

---

## 🌟 Key Features / Öne Çıkan Özellikler

### Türkçe (TR)
- **Anlık Analiz:** Son 10 ölçümün ortalaması (Mean) ve standart sapması (Standard Deviation) terminal ekranında anlık olarak hesaplanır.
- **Dinamik Görselleştirme:** Gelen veriler `Matplotlib` kütüphanesi kullanılarak canlı olarak grafikleştirilir ve ortalama çizgisi kesikli hatla gösterilir.
- **Fiziksel Geri Bildirim:** Engel yaklaştıkça hızlanan buzzer uyarısı ve 3 kademeli durum LED'leri (Yeşil, Sarı, Kırmızı) devreye girer.

### English (EN)
- **Live Stats:** Instantly calculates and displays the mean and standard deviation of the last 10 readings directly in the terminal.
- **Dynamic Plotting:** Live distance data is visually plotted using Python's `Matplotlib` library, complete with a dashed horizontal statistical mean line.
- **Feedback System:** Features integrated physical feedback using status LEDs and a buzzer that beeps progressively faster as the obstacle gets closer.

---

## 🔌 Hardware Schematic / Donanım Şeması

| Component / Bileşen | Quantity / Adet | Connection Pin (Arduino Uno) / Bağlantı Pini |
| :--- | :---: | :--- |
| **Arduino Uno** | 1 | Main Microcontroller / Ana Denetleyici |
| **HC-SR04** Ultrasonic Sensor | 1 | `TRIG_PIN` -> Pin 4, `ECHO_PIN` -> Pin 3 |
| **Green LED** / Yeşil LED | 1 | Pin 10 (with Resistor) |
| **Yellow LED** / Sarı LED | 1 | Pin 9 (with Resistor) |
| **Red LED** / Kırmızı LED | 1 | Pin 8 (with Resistor) |
| **Active Buzzer** / Aktif Buzzer | 1 | Pin 11 |

---

## 💻 Software Implementation / Yazılım Kurulumu

**Türkçe (TR)**

**⚠️ Önemli Not:** Proje dosyalarını bilgisayarınıza direkt kopyala-yapıştır yapınca çalışmaz. Öncelikle sisteminizde gerekli kütüphanelerin kurulu olması gerekir.

1.Arduino Yüklemesi: İlk önce hcsr04 klasöründeki hcsr04.inoyu Arduino'ya yüklüyoruz.

2.Projeyi Açma: Daha sonra mesafe_ort dosyasındaki ort.pyyi VS Code ile çalıştırıyoruz.

3.Kütüphanelerin Kurulumu: Kütüphaneleri kuruyoruz (direkt kopyala yapıştır yapınca çalışmaz). VS Code terminalini açıp aşağıdaki komutu yazarak gerekli kütüphaneleri yüklüyoruz:

```
  pip install pyserial numpy matplotlib
```

4. Çalıştırma: Daha sonra terminale aşağıdaki komutu yazıp çalıştırıyoruz:

```
  py ort.py
```

**English (EN)**

**⚠️ Important Note:** The project will not work directly by just copying and pasting the files. You must install the required libraries beforehand.

1.Arduino Upload: First, upload the hcsr04.ino file inside the hcsr04 folder to your Arduino board.

2.Open Project: Next, open and run the ort.py file inside the mesafe_ort folder using VS Code.

3.Library Installation: Install the required libraries (it won't work by just copying and pasting). Open your VS Code terminal and execute the following command to install them:

```
  pip install pyserial numpy matplotlib
```

4. Execution: Finally, run the following command in the terminal to start the application:

```
  py ort.py
```

## 👩‍💻 Developer / Geliştirici
Developed with ❤️ by **[Ayşenur KARAKÜÇÜK](https://github.com/AysenurKrkck)** 🚀

*   **Instagram:** [@techbyaysenur](https://www.instagram.com/techbyaysenur/)
