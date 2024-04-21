var currentSource = ""; // Zmienna przechowująca obecne źródło iframe

  function sourceSwap() {
    // Pobierz plik JSON z linkami
    $.getJSON('videos.json', function(data) {
      var newSource = currentSource; // Inicjalizuj nowe źródło jako obecne źródło
      
      // Losuj nowe źródło, dopóki nie będzie różne od obecnego
      while (newSource === currentSource) {
        var randomIndex = Math.floor(Math.random() * data.links.length);
        newSource = data.links[randomIndex];
      }
      
      // Aktualizuj obecne źródło
      currentSource = newSource;
      
      // Pobierz element iframe
      var iframe = document.getElementById('yt-player');
      // Zmień źródło iframe na nowe źródło
      iframe.src = newSource;
    });
  }
  
$(document).ready(function() {
    fetch("https://api.lanyard.rest/v1/users/313026957044350977")
    .then(response => response.json())
    .then(data => {
      // Sprawdź, czy istnieje pole "discord_user" i "username" w danych
      if (data.data && data.data.discord_user && data.data.discord_user.username) {
          // Jeśli istnieje, ustaw wartość w elemencie HTML
          var username = data.data.discord_user.username;
          var nameElement = document.getElementById("nickname");
          nameElement.innerHTML = username;
      } else {
          // Jeśli nie istnieje, wyświetl komunikat o błędzie w konsoli
          console.error('Nie znaleziono pola "discord_user.username" w danych:', data);
      }
    })
    .then(console.log)
    .catch(error => console.error('Błąd podczas pobierania danych:', error));
    
    var pfp = document.getElementById("pfp");
    pfp.src = "https://api.lanyard.rest/313026957044350977.png";
});
  //src="https://www.youtube.com/embed/WrGTu8-30SI" 
