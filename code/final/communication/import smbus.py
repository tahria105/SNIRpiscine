import smbus
import time
import pymysql

# Configuration I2C
bus = smbus.SMBus(1)
address = 0x08  # Adresse I2C de l'Arduino

# Configuration de la base de données
connection = pymysql.connect(
    host='127.0.0.1',
    user='root',  # Remplacez par le nom d'utilisateur MySQL que vous avez créé
    password='your_password',  # Remplacez par le mot de passe MySQL que vous avez créé
    database='piscine'
)

def read_from_arduino():
    try:
        data = bus.read_i2c_block_data(address, 0, 32)
        data_str = ''.join(chr(i) for i in data).strip()
        temperature, humidity = map(float, data_str.split(','))
        return temperature, humidity
    except Exception as e:
        print(f"Erreur de lecture I2C: {e}")
        return None, None

def insert_into_db(temperature, humidity):
    try:
        with connection.cursor() as cursor:
            sql = "INSERT INTO readings (temperature, humidity) VALUES (%s, %s)"
            cursor.execute(sql, (temperature, humidity))
        connection.commit()
    except Exception as e:
        print(f"Erreur d'insertion dans la BDD: {e}")

while True:
    temp, hum = read_from_arduino()
    if temp is not None and hum is not None:
        insert_into_db(temp, hum)
        print(f"Inséré dans la BDD: Temp={temp}, Hum={hum}")
    time.sleep(1)
