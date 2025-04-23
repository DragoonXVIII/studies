import React from "react";

export default function MainArea({ fontSize, fontColor }) {
  return (
    <div className="main-area">
      <p style={{ fontSize: `${fontSize}px`, color: fontColor }}>
        Szkielety programistyczne w aplikacjach internetowych: Node, MongoDB, Express, React.
      </p>
    </div>
  );
}
