from pynput.keyboard import Key, Controller
import serial
import time

keyboard = Controller()

ser = serial.Serial('/dev/cu.usbserial-0001', 115200)

while True:
    [action, button] = ser.readline().decode("utf-8").strip().split("-")
    # print(action)
    # print(button)
    key = Key.up
    if button == 'a':
        key = 'a'
    if button == 'b':
        key = 'b'
    if button == 'up':
        key = Key.up
    if button == 'down':
        key = Key.down
    if button == 'left':
        key = Key.left
    if button == 'right':
        key = Key.right
    if button == 'start':
        key = Key.enter
    if button == 'select':
        key = Key.shift_r

    if action == "bp":
        keyboard.press(key)
    else:
        keyboard.release(key)

# keyboard.press(Key.right)
# time.sleep(1)
# keyboard.release(Key.right)
