import vosk
import sounddevice as sd
import queue
import serial
import json

ser = serial.Serial('/dev/ttyUSB0', 9600)
q = queue.Queue()

model = vosk.Model("model")
rec = vosk.KaldiRecognizer(model, 16000)

def callback(indata, frames, time, status):
    q.put(bytes(indata))

with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback):
    while True:
        data = q.get()
        if rec.AcceptWaveform(data):
            result = json.loads(rec.Result())
            text = result.get("text", "")
            print(f"Είπες: {text}")
            if "άναψε" in text or "φως" in text:
                ser.write(b'1')
            elif "σβήσε" in text:
                ser.write(b'0')
