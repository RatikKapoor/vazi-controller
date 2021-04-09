from pynput.keyboard import Key, Controller
import serial
import threading
from PIL import ImageGrab

keyboard = Controller()

ser = serial.Serial('/dev/cu.usbserial-0001', 115200, timeout=0.05)


def rgbToDec(n: int) -> int:
    return int(n / 255 * 99)  # FIXME: Change 30 -> 99


def padRGB(rgba) -> bytes:
    (r, g, b, a) = rgba
    return str.encode(str(r).zfill(2)) + str.encode(
        str(g).zfill(2)) + str.encode(str(b).zfill(2))


def averageColours(image: list[int]):
    print(image)


def handleButton(line: str) -> None:
    [action, button] = line.decode().strip().split("-")

    key = None
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
        key = 'z'
    if button == 'select':
        key = Key.shift_r

    if action == "bp":
        keyboard.press(key)

    elif action == "br":
        keyboard.release(key)


def buttonThread() -> None:
    while True:
        line = ser.readline()
        if line.__len__() > 0:
            handleButton(line)


def colourThread() -> None:
    while True:
        screenshot = ImageGrab.grab()

        top_left = screenshot.crop([
            screenshot.width * 1 / 8, screenshot.height * 1 / 8,
            screenshot.width * 3 / 8, screenshot.height * 3 / 8
        ])
        top_right = screenshot.crop([
            screenshot.width * 5 / 8, screenshot.height * 1 / 8,
            screenshot.width * 7 / 8, screenshot.height * 3 / 8
        ])
        bottom_left = screenshot.crop([
            screenshot.width * 1 / 8, screenshot.height * 5 / 8,
            screenshot.width * 3 / 8, screenshot.height * 7 / 8
        ])
        bottom_right = screenshot.crop([
            screenshot.width * 5 / 8, screenshot.height * 5 / 8,
            screenshot.width * 7 / 8, screenshot.height * 7 / 8
        ])

        top_left = top_left.resize((1, 1)).getpixel((0, 0))
        top_right = top_right.resize((1, 1)).getpixel((0, 0))
        bottom_left = bottom_left.resize((1, 1)).getpixel((0, 0))
        bottom_right = bottom_right.resize((1, 1)).getpixel((0, 0))

        tl = map(rgbToDec, top_left)
        tr = map(rgbToDec, top_right)
        bl = map(rgbToDec, bottom_left)
        br = map(rgbToDec, bottom_right)

        tl = padRGB(tl)
        tr = padRGB(tr)
        bl = padRGB(bl)
        br = padRGB(br)

        ser.write(tr + tl + bl + br)


if __name__ == "__main__":
    button = threading.Thread(target=buttonThread)
    colour = threading.Thread(target=colourThread)
    button.start()
    colour.start()
