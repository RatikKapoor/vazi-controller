import React, { useState } from 'react';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import robot from 'robotjs';
import icon from '../assets/icon.svg';
import './App.global.css';

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

const Main = () => {
  const [avgColour, setAvgColour] = useState<QuadrantColours>();
  const { height, width } = robot.screen.capture();

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
        ></button>
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
