import React, { useState } from "react";

export default function Sidebar({ fontSize, fontColor, updateTextStyle }) {
  const [size, setSize] = useState(fontSize);
  const [color, setColor] = useState(fontColor);
  const [error, setError] = useState("");

  const validateAndApply = () => {
    const parsedSize = parseInt(size);
    const isSizeValid = !isNaN(parsedSize) && parsedSize > 0;

    const isColorValid = CSS.supports("color", color);

    if (isSizeValid && isColorValid) {
      updateTextStyle(parsedSize, color);
      setError("");
    } else {
      setError("Niepoprawny rozmiar lub kolor! Ustawiono domyślne wartości.");
      updateTextStyle(18, "green");
      setSize(18);
      setColor("green");
    }
  };

  return (
    <div className="sidebar">
      <input 
        type="text" 
        value={size} 
        onChange={e => setSize(e.target.value)} 
        placeholder="Rozmiar (np. 18)" 
      />
      <input 
        type="text" 
        value={color} 
        onChange={e => setColor(e.target.value)} 
        placeholder="Kolor (np. red)" 
      />
      <button onClick={validateAndApply}>
        Ustaw parametry tekstu: {size}px, {color}
      </button>
      {error && <p style={{ color: "red", marginTop: "10px" }}>{error}</p>}
    </div>
  );
}
