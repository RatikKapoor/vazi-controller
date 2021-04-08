from pynput.keyboard import Key, Controller
import serial
from PIL import ImageGrab


def rgbToDec(n: int) -> int:
    return int(n / 255 * 99)


keyboard = Controller()

ser = serial.Serial('/dev/cu.usbserial-0001', 115200)

while True:
    [action, button] = ser.readline().decode("utf-8").strip().split("-")
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

    if action == "bp" and key == Key.shift_r:
        screenshot = ImageGrab.grab()

        pixel = screenshot.getpixel(
            (screenshot.width / 4, screenshot.height / 4))

        (r, g, b, a) = map(rgbToDec, pixel)

        print(r, g, b)

        res = str.encode(str(r)) + str.encode(str(g)) + str.encode(str(b))
        print(res * 4)

        ser.write(res * 4)

# keyboard.press(Key.right)
# time.sleep(1)
# keyboard.release(Key.right)
