document.addEventListener('DOMContentLoaded', () => { 
    getAllProducts(); 
    var bdodaj = document.getElementById('add'); 
    bdodaj.addEventListener("click", () => { 
        //Dodawanie 
        dodaj(); 
    }); 
    // Kolejne instrukcje do modyfikacji danych 
    // . . .  
}); 
 
function dodaj() { 
    console.log("Dodawanie nowego produktu"); 
    var st = {}; 
    st.name = document.getElementById('name').value; 
    st.price = parseInt(document.getElementById('price').value); 
    fetch("http://localhost:8000/products", { 
        method: "post", 
        body: JSON.stringify(st), 
        headers: { 
            "Content-type": "application/json; charset=UTF-8", 
            "Accept": "application/json" 
        } 
    }).then(response => { 
        if (!response.ok) { //status odpowiedzi różny od 2xx 
            return Promise.reject('Problem z dodaniem danych!'); 
        } 
        return response.json(); 
    }) .then(response => { 
        console.log("Dodano produkt:"); 
        console.log(response); 
        getAllProducts(); 
        document.getElementById('name').value = ""; 
        document.getElementById('price').value = ""; 
        console.log("Koniec dodawania"); 
    }).catch((error) => { 
        console.log(error); 
        err.innerHTML=error;//ustawienie komunikatu błędu w elemencie o id=err 
    }); 
} 
 
function edytuj(id, name, price) { 
    var x = document.getElementById("divedit"); 
    document.getElementById('editId').value = id; 
    document.getElementById('editName').value = name; 
    document.getElementById('editPrice').value = price; 
    x.style.visibility = "visible"; 
} 
 

function update() { 
    var id = document.getElementById('editId').value;
    var name = document.getElementById('editName').value;
    var price = document.getElementById('editPrice').value;

    if (!name || isNaN(price)) {
        console.log("Niepoprawne dane");
        err.innerHTML = "Niepoprawne dane";
        return;
    }

    var st = { name: name, price: price };

    fetch("http://localhost:8000/products/" + id, { 
        method: "put", 
        body: JSON.stringify(st), 
        headers: { 
            "Content-type": "application/json; charset=UTF-8", 
            "Accept": "application/json" 
        } 
    }).then(response => { 
        if (!response.ok) { 
            return Promise.reject('Problem z aktualizacją danych!'); 
        } 
        return response.json(); 
    }).then(response => { 
        console.log("Zaktualizowano produkt:"); 
        console.log(response); 
        getAllProducts(); 
        document.getElementById('editId').value = ""; 
        document.getElementById('editName').value = ""; 
        document.getElementById('editPrice').value = ""; 
        document.getElementById("divedit").style.visibility = "hidden"; 
        console.log("Koniec aktualizacji"); 
    }).catch((error) => { 
        console.log(error); 
        err.innerHTML = error; 
    }); 
}
 
function getAllProducts() { 
    fetch("http://localhost:8000/products") 
        .then((response) => { 
            if (!response.ok) { 
                return Promise.reject('Coś poszło nie tak!'); 
            } 
            return response.json(); 
        }) 
        .then((data) => { 
            pokazTabele(data); 
            console.log(data); 
        }) 
        .catch((error) => { 
            console.log(error); 
            err.innerHTML=error; 
        }); 
} 
 


 
function usun(id) { 
    fetch("http://localhost:8000/products/" + id, { 
        method: "delete", 
        headers: { "Content-type": "application/json; charset=UTF-8" } 
    }).then(response => { 
        if (!response.ok) { 
            return Promise.reject('Problem z usunięciem danych!'); 
        } 
        return response.json(); 
    }).then(response => { 
        console.log("Usunięto produkt o id:" + id); 
        console.log(response); 
        getAllProducts(); 
    }).catch((error) => { 
        console.log(error); 
        err.innerHTML=error; 
    }); 
} 
 
function pokazTabele(response) { 
    var main = document.getElementById('main'); 
    var content = "<table border='1'> <thead> <tr> <th>Id</th><th> Name</th>"+ 
                   "<th>Price</th></tr></thead><tbody>"; 
    for (var st in response) { 
        var name = response[st].name; 
        var price = response[st].price; 
        var id = response[st].id; 
        content += "<tr><td>" + id + "</td><td>" + name + "</td><td>"  
                   + price + "</td>"; 
        content += "<td><button onclick='usun(" + id +  
                         ")'>Usuń</button></td>"; 
        content += "<td> <button onclick='edytuj(" + id + ",\""  
                    + name + "\"," + price + ")'>Edytuj</button></td></tr>"; 
    } 
    content += "</tbody></table>"; 
    main.innerHTML = content; 
} 