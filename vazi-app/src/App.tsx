import React, { useEffect, useState } from 'react';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import robot from 'robotjs';
import icon from '../assets/icon.svg';
import './App.global.css';
import SerialPort, {list, PortInfo} from 'serialport';
import Select from "react-select";

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

const Main = () => {
  const [avgColour, setAvgColour] = useState<QuadrantColours>();
  const { height, width } = robot.getScreenSize();
  const [serialPorts, setSerialPorts] = useState<PortInfo[]>();
  const [selectedPort, setSelectedPort] = useState<string>();
  let port:SerialPort;
  let lineStream:SerialPort.parsers.Readline;
  const Readline = SerialPort.parsers.Readline;
  // const sp = new serialport('/dev/tty.SLAB_USBtoUART', {
  //   baudRate: 115200,
  // });

  useEffect(() => {
    list().then((ports) => {
      console.log(ports)
      setSerialPorts(ports);
    })
  }, [])

  const getPortValueLabel = ():ValueLabelPair[] => {
    let result: ValueLabelPair[] = [];
    serialPorts?.forEach(port => {
      result.push({value: port.path, label: port.path})
    })
    return result;
  }

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
  };

  const connectSerialPort = () => {
    if (selectedPort != undefined && selectedPort.length > 1) {
      port = new SerialPort(selectedPort, {
        baudRate: 115200
      });
      lineStream = port.pipe(new Readline({delimiter: '\r\n'}));
    }
  }

  const disconnectSerialPort = () => {
    if (port != undefined) {
      port.destroy();
      lineStream.destroy();
    }
  }

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
        ></button>
        <Select options={getPortValueLabel()} className="Select" onChange={e => {setSelectedPort(e?.value); console.log(e)}} />
        <button onClick={() => connectSerialPort()} >Connect</button>
        <button onClick={() => connectSerialPort()} >Disconnect</button>
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
