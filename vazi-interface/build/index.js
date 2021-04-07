"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var robotjs_1 = __importDefault(require("robotjs"));
var serialport_1 = __importDefault(require("serialport"));
console.log("Hello world!");
// robot.moveMouseSmooth(50, 5);
var port = new serialport_1.default("/dev/cu.usbserial-0001", {
    baudRate: 115200,
});
var handleSerialInput = function (data) {
    var _a = data.split("-"), action = _a[0], button = _a[1];
    console.log(action, button);
    var key = "w";
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
    robotjs_1.default.keyTap(key);
};
var lineStream = port.pipe(new serialport_1.default.parsers.Readline({ delimiter: "\n" }));
lineStream.on("data", handleSerialInput);
