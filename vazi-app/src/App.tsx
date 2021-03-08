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
    console.log('GOT DATA', data);
    if (data.includes('bp')) {
      robot.typeString('w');
    }
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
      <div className="Main">
        <img width="200px" alt="icon" src={icon} />
      </div>
      <h1>Vazi Controller Companion App</h1>
      <div className="Main">
        <button
          type="button"
          onClick={() => {
            calculateQuadrantColours();
          }}
        >
          Colours
        </button>
        <Select
          options={getPortValueLabel()}
          className="Select"
          onChange={(e) => {
            setSelectedPort(e?.value);
            console.log(e);
          }}
        />
        <button onClick={() => connectSerialPort()}>Connect</button>
        <button onClick={() => disconnectSerialPort()}>Disconnect</button>
        <input
          value={toUARTSend}
          onChange={(e) => setToUARTSend(e.target.value)}
        />
        <button onClick={() => sendSerialData(toUARTSend)}></button>
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
