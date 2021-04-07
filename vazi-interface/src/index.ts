import robot from "robotjs";
import SerialPort from "serialport";

console.log("Hello world!");
// robot.moveMouseSmooth(50, 5);
const port = new SerialPort("/dev/cu.usbserial-0001", {
  baudRate: 115200,
});

const handleSerialInput = (data: string) => {
  const [action, button] = data.split("-");
  console.log(action, button);
  let key = "w";
  switch (button) {
    case "up":
      key = "up";
      break;

    case "down":
      key = "down";
      break;

    case "left":
      key = "left";
      break;

    case "right":
      key = "right";
      break;

    case "select":
      key = "right_shift";
      break;

    case "start":
      key = "enter";
      break;

    case "a":
      key = "a";
      break;

    case "b":
      key = "s";
      break;

    default:
      break;
  }
  // console.log(key);
  // robot.keyToggle(key,
  robot.keyTap(key);
};

const lineStream = port.pipe(
  new SerialPort.parsers.Readline({ delimiter: "\n" })
);

lineStream.on("data", handleSerialInput);
