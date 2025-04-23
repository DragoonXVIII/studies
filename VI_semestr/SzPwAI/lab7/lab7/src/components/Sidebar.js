import React, { useState } from "react";

export default function Sidebar({ fontSize, fontColor, updateTextStyle }) {
  const [size, setSize] = useState(fontSize);
  const [color, setColor] = useState(fontColor);

  return (
    <div className="sidebar">
      <input type="text" value={size} onChange={e => setSize(e.target.value)} />
      <input type="text" value={color} onChange={e => setColor(e.target.value)} />
      <button onClick={() => updateTextStyle(size, color)}>
        Ustaw parametry tekstu: {size}px, {color}
      </button>
    </div>
  );
}
