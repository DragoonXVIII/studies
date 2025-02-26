//const dane = require('./dane.js')
import {listaZadan, poniedzialek, wtorek, firmy} from "./dane.js";
//console.log("HelloWorld")

/*
Na podstawie kodu z Listingu 2.1 napisać funkcję sumator(), która przyjmie dowolną 
liczbę argumentów dzięki zastosowaniu parametru resztowego. Funkcja w miejscu 
wywołania powinna zwracać podane argumenty oraz ich sumę, w postaci tekstu 
Suma liczb: 1, 2, 3 wynosi 6. Do uzyskania tego efektu należy wykorzystać szablon ciągu 
tekstowego.
*/

function sumator(...args) 
{
    let sum = 0;
    args.forEach(element => {
        if(!isNaN(element))
            sum += element;
    });
    return `Suma liczb: ${args.join(', ')} wynosi ${sum}.`;
}

function zad1()
{
    console.log(sumator(4,14,"sg",-5,61,67));
}

/*
a) Używając metody forEach() wyświetl wszystkie właściwości tekst z obiektów będących 
elementami tablicy. 
b) Wykorzystując metodę map() utwórz nowa tablicę składającą się z tekstów będących 
elementami obiektów tablicy listaZadan. 
c) Za pomocą metody filter() utwórz tablicę zawierającą teksty pochodzące z obiektów 
składających się na tablicę listaZadan, wyłącznie dla zadań zrealizowanych.
*/

function zad2()
{
    console.log("a: \n")
    dane.listaZadan.forEach(element=>{
        console.log(element.tekst)
    })

    console.log("b: \n")
    const teksty = listaZadan.map(element => element.tekst);
    console.log(teksty);

    console.log("c: \n")
    const zrealizowaneTeksty = listaZadan.filter(element => element.zrealizowano).map(element => element.tekst);
    console.log(zrealizowaneTeksty);
}

//zad2();

/*
Mocną cechą metod map(), filter() i reduce() jest możliwość ich łączenia w łańcuch. 
Używając właściwości łączenia metod w łańcuch należy wykonać kolejno następujące 
czynności: 
1. umieścić zadania z dwóch dni w jednej tablicy (reduce), 
2. pobrać czasy trwania zadania i przekonwertować je z minut na godziny (map), 
3. odfiltrować czasy, które są większe niż 2 godziny (filter), 
4. pomnożyć czasy przez stawkę godzinową wynoszącą 35 zł (map), 
5. zsumować wszystkie kwoty (reduce), 
6. sformatować kwotę poprzez dodanie 2 miejsc dziesiętnych oraz symbolu waluty PLN 
(map), 
7. wyjąć wartość z tablicy (reduce). 
W punkcie 5 używając metody reduce() wartości parametrów funkcji anonimowej należy ująć 
w nawiasy zwykłe i poprzedzić znakiem +, aby wymusić konwersję na liczbę: 
reduce(function (acc, curr) { 
return [(+acc) + (+curr)]; 
}) 
*/

function zad3()
{
    const stawkaGodzinowa = 35;
    //const zadania = [...dane.poniedzialek, ...dane.wtorek];
    const wynik = poniedzialek.concat(wtorek)
        .map(zadanie => zadanie.czas / 60)
        .filter(czas => czas > 2)
        .map(czas => czas * stawkaGodzinowa)
        .reduce((acc, curr) => [+acc + curr])
        .map(kwota => kwota.toFixed(2) + ' PLN')
        .reduce(acc => acc);
    
    console.log(wynik);
}

zad3();

/*
a) Napisz program z użyciem metody filter(), który spowoduje wyświetlenie firm z branży 
IT. 
b) Używając metody filter() oraz funkcji strzałkowej, wyświetl firmy, które powstały 
i zakończyły swoją działalność w latach dziewięćdziesiątych. 
c) Wyświetl firmy, które funkcjonowały na rynku dłużej niż 10 lat.
*/

function zad4()
{

}

zad4();