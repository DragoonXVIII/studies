import React from "react";

export default function Header({ fontSize, fontColor, likes }) {
  return (
    <div className="header">
      <h1>Nagłówek</h1>
      <p>Aktualny rozmiar czcionki: <strong>{fontSize}</strong></p>
      <p>Aktualny kolor czcionki: <strong>{fontColor}</strong></p>
      <p>Liczba lajków: <strong>{likes}</strong></p>
    </div>
  );
}
