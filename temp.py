import board
import adafruit_dht
import time

# Set up DHT sensor
DHT_PIN = board.D16  # Use GPIO 16 for the data pin
dht_device = adafruit_dht.DHT11(DHT_PIN)  # Change to DHT11 if using DHT11

try:
    while True:
        # Read temperature and humidity
        temperature_c = dht_device.temperature
        humidity = dht_device.humidity
        
        if temperature_c is not None and humidity is not None:
            print(f'Temperature: {temperature_c:.1f} °C')
            print(f'Humidity: {humidity:.1f} %')
        else:
            print("Failed to retrieve data from sensor")

        # Wait before the next reading
        time.sleep(2)

except:
    dht_device.exit()  # Clean up the device if needed
