import React from "react";

export default function Footer({ updateTextStyle, like }) {
  return (
    <footer className="footer">
      <p>
        <strong>Stopka</strong> 
        <button onClick={() => updateTextStyle(30)}>Ustaw parametry tekstu na 30px, a kolor pozostaw bez zmian.</button>
      </p>
      <p>
        <button onClick={like}>Polub tę stronę!</button>
      </p>
    </footer>
  );
}
