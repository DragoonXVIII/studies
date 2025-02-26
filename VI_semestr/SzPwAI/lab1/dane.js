const listaZadan = [ 
    { 
        id: 1, 
        tekst: "Zrobienie zakupów", 
        zrealizowano: true 
    }, 
    { 
        id: 2, 
        tekst: "Przegląd techniczny samochodu", 
        zrealizowano: false 
    }, 
    { 
        id: 3, 
        tekst: "Wizyta u dentysty", 
        zrealizowano: false 
    }, 
]

const poniedzialek = [ 
    { 
        'nazwa': 'Przygotowania do zajęć z AI', 
        'czas': 180 
    }, 
    { 
        'nazwa': 'Realizacja projektu z AI', 
        'czas': 120 
    } 
] 

const wtorek = [ 
    { 
        'nazwa': 'Rozbudowa swojego bloga', 
        'czas': 240 
    }, 
    { 
        'nazwa': 'Administrowanie serwisem szkoly', 
        'czas': 180 
    }, 
    { 
        'nazwa': 'Sluchanie koncertu online', 
        'czas': 240 
    }
] 

const firmy = [ 
    {nazwa:"Abasco", kategoria:"IT", poczatek:1999, koniec:2010}, 
    {nazwa:"Redis", kategoria:"IT", poczatek:1993, koniec:1998}, 
    {nazwa:"Komp", kategoria:"IT", poczatek:2003, koniec:2018}, 
    {nazwa:"Bosco", kategoria:"Technologie", poczatek:2011, koniec: 2014}, 
    {nazwa:"CCA", kategoria:"IT", poczatek:1991, koniec:1995}, 
    {nazwa:"Autosan", kategoria:"Auto", poczatek:2009, koniec: 2018}, 
    {nazwa:"Broke", kategoria:"Finanse", poczatek:1990, koniec: 1992}, 
    {nazwa:"Funds", kategoria:"Finanse", poczatek:2000, koniec: 2021} 
]

module.exports = {listaZadan, poniedzialek, wtorek, firmy}