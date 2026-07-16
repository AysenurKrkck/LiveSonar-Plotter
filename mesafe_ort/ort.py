import serial
import numpy as np
import matplotlib.pyplot as plt

# TR: Seri haberleşme portunu başlat (Port: COM3, Hız: 9600)
# EN: Initialize serial communication port (Port: COM3, Baud rate: 9600)
ser = serial.Serial('COM3', 9600)
ser.flushInput()  # TR: Seri port tampon belleğini temizle | EN: Clear the serial port input buffer

data_liste = []  # TR: Gelen verileri depolamak için boş liste | EN: Empty list to store incoming data

try:
    while True:
        # TR: Seri portta okunmayı bekleyen veri var mı kontrol et
        # EN: Check if there is incoming data waiting in the serial buffer
        if ser.in_waiting > 0:
            # TR: Gelen veriyi oku, çöz (decode) ve boşlukları temizle
            # EN: Read the incoming line, decode to string, and strip whitespace
            data = ser.readline().decode('utf-8').strip()
            
            # TR: Gelen metin verisini ondalıklı sayıya (float) çevir
            # EN: Convert the incoming text data to a float
            mesafe = float(data)
            data_liste.append(mesafe)  # TR: Veriyi listeye ekle | EN: Append the data to the list
            
            # TR: Listede 10'dan fazla veri biriktiğinde analiz etmeye başla
            # EN: Start analysis once there are more than 10 data points in the list
            if len(data_liste) > 10:
                # NOT: Sadece son 10 ölçümü almak için data_liste[-10:] kullanabilirsin.
                # NOTE: To analyze only the last 10 measurements, you can use data_liste[-10:].
                ortalama = np.mean(data_liste)  # TR: Tüm listenin ortalaması | EN: Mean of the entire list
                std = np.std(data_liste)        # TR: Standart sapma | EN: Standard deviation
                max_data = np.max(data_liste)   # TR: En yüksek değer | EN: Maximum value
                min_data = np.min(data_liste)   # TR: En düşük değer | EN: Minimum value
                
                # TR: Sonuçları konsola yazdır | EN: Print results to the console
                print("MESAFE: ", mesafe)
                print(f"Son 10 ölçüm - Ort: {ortalama:.2f} cm, Std Sapma: {std:.2f} cm")
                print(f"Min: {min_data} cm, Max: {max_data} cm")
                
                # --- Grafik Çizimi / Data Plotting ---
                plt.clf()  # TR: Önceki grafiği temizle | EN: Clear the current figure
                
                # TR: Mesafe verilerini çizdir | EN: Plot the distance data
                plt.plot(data_liste, label='Mesafe (cm)') 
                
                # TR: Ortalama değerini kesikli kırmızı çizgiyle göster
                # EN: Draw a dashed red horizontal line representing the average
                plt.axhline(ortalama, color='red', linestyle='--', label='Ortalama')
                
                plt.legend()       # TR: Göstergeyi ekle | EN: Show the legend
                plt.pause(0.1)     # TR: Grafiği güncellemek için kısa bir mola ver | EN: Pause to update the plot

except KeyboardInterrupt:
    # TR: Kullanıcı CTRL+C tuşlarına bastığında çalışır
    # EN: Triggered when the user presses CTRL+C (Keyboard Interrupt)
    print("\nProgram durduruluyor... / Stopping the program...")
    ser.close()  # TR: Seri port bağlantısını güvenli bir şekilde kapat | EN: Safely close the serial port
    plt.show()   # TR: Son grafiği ekranda sabit tut | EN: Keep the final plot displayed on screen