from flask import Flask, render_template
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/on')
def turn_on():
    ser.write(b'1')
    return "Φως ON"

@app.route('/off')
def turn_off():
    ser.write(b'0')
    return "Φως OFF"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
