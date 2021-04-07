import React, { useEffect, useState } from 'react';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import robot from 'robotjs';
import icon from '../assets/icon.svg';
import './App.global.css';
import SerialPort, { list, PortInfo } from 'serialport';
import Select from 'react-select';
import _ from 'lodash';

// enum Quadrant {
//   TopLeft,
//   TopRight,
//   BottomLeft,
//   BottomRight,
// }

interface QuadrantColours {
  topLeft: string;
  topRight: string;
  bottomLeft: string;
  bottomRight: string;
}

interface ValueLabelPair {
  value: string;
  label: string;
}

let port: SerialPort;

const Main = () => {
  const [avgColour, setAvgColour] = useState<QuadrantColours>();
  const { height, width } = robot.getScreenSize();
  const [serialPorts, setSerialPorts] = useState<PortInfo[]>();
  const [selectedPort, setSelectedPort] = useState<string>();
  const [toUARTSend, setToUARTSend] = useState<string>('');
  let lineStream: SerialPort.parsers.Readline;
  const Readline = SerialPort.parsers.Readline;

  const rgbEncode = (rgb: string | undefined): string => {
    if (rgb == undefined) return '';
    const r_temp: number = Math.round(
      (parseInt('0x' + rgb.substr(0, 2), 16) / 255) * 100
    );
    const b_temp: number = Math.round(
      (parseInt('0x' + rgb.substr(2, 2), 16) / 255) * 100
    );
    const g_temp: number = Math.round(
      (parseInt('0x' + rgb.substr(4, 2), 16) / 255) * 100
    );
    console.log('RGB Encode Reading:', r_temp, b_temp, g_temp);
    return (
      r_temp.toString().padStart(2, '0') +
      g_temp.toString().padStart(2, '0') +
      b_temp.toString().padStart(2, '0')
    );
  };

  useEffect(() => {
    list().then((ports) => {
      console.log(ports);
      setSerialPorts(ports);
    });

    return () => {};
  }, []);

  const getPortValueLabel = (): ValueLabelPair[] => {
    let result: ValueLabelPair[] = [];
    serialPorts?.forEach((port) => {
      result.push({ value: port.path, label: port.path });
    });
    return result;
  };

  const calculateQuadrantColours = () => {
    let topLeft: string = robot.screen.capture().colorAt(width / 4, height / 4);
    let topRight: string = robot.screen
      .capture()
      .colorAt((width * 3) / 4, height / 4);
    let bottomLeft: string = robot.screen
      .capture()
      .colorAt(width / 4, (height * 3) / 4);
    let bottomRight: string = robot.screen
      .capture()
      .colorAt((width * 3) / 4, (height * 3) / 4);
    setAvgColour({
      topLeft: topLeft,
      topRight: topRight,
      bottomLeft: bottomLeft,
      bottomRight: bottomRight,
    });
    console.log(avgColour);
    sendSerialData(rgbEncode(avgColour?.topLeft));
  };

  const handleSerialInput = (data: string) => {
    // console.log('GOT DATA', data);
    const [action, button] = data.split('-');
    console.log(action, button);
    // if (data.includes('bp')) {
    //   data.split
    //   robot.typeString('w');
    // }
    let key = 'w';
    switch (button) {
      case 'up':
        key = 'w';
        break;

      case 'down':
        key = 's';
        break;

      case 'left':
        key = 'a';
        break;

      case 'right':
        key = 'd';
        break;

      case 'select':
        key = 'q';
        break;

      case 'start':
        key = 'escape';
        break;

      case 'a':
        key = 'space';
        break;

      case 'b':
        key = 'e';
        break;

      default:
        break;
    }
    console.log(key);
    robot.keyToggle(key, action == 'bp' ? 'down' : 'up');
  };

  const connectSerialPort = () => {
    if (selectedPort != undefined && selectedPort.length > 1) {
      port = new SerialPort(selectedPort, {
        baudRate: 115200,
        lock: false,
      });
      lineStream = port.pipe(new Readline({ delimiter: '\n' }));
      console.log('Setup done');
      lineStream.on('data', handleSerialInput);
    }
  };

  const disconnectSerialPort = () => {
    if (port != undefined) {
      port.close();
      lineStream.destroy();
    }
  };

  const sendSerialData = (data: string) => {
    console.log('ABOUT TO SEND: ' + data, port);
    if (port != undefined) {
      port.write(data, (err) => {
        if (err) {
          console.warn(err);
        }
        console.log('Good!');
      });
    }
  };

  return (
    <div>
      {/* <div className="Main">
        <img width="200px" alt="icon" src={icon} />
      </div> */}
      <h1 className="Name">Vazi Controller Companion App</h1>
      <div className="Main">
        <button
          type="button"
          onClick={() => {
            calculateQuadrantColours();
          }}
        >
          Get and update colour
        </button>
        <div className="SerialPort">
          <h2>Port location</h2>
          <Select
            options={getPortValueLabel()}
            className="Select"
            onChange={(e) => {
              setSelectedPort(e?.value);
              console.log(e);
            }}
          />
        </div>
        <div className="SerialActions">
          <h2>Serial port status: </h2>
          <h3>{port ? 'Connected' : 'Disconnected'}</h3>
          <button onClick={() => connectSerialPort()}>Connect</button>
          <button onClick={() => disconnectSerialPort()}>Disconnect</button>
        </div>
        <div className="SerialSend">
          <input
            value={toUARTSend}
            onChange={(e) => setToUARTSend(e.target.value)}
          />
          <button onClick={() => sendSerialData(toUARTSend)}>
            Send to Serial
          </button>
        </div>
      </div>
    </div>
  );
};

export default function App() {
  return (
    <Router>
      <Switch>
        <Route path="/" component={Main} />
      </Switch>
    </Router>
  );
}
