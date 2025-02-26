/*
Zadanie 9.1.  
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę liczbaZespolona składającą się 
z części rzeczywistej i urojonej liczby.  
Polecenie 2. Wczytaj dwie liczby zespolone. 
Polecenie 3. Zaimplementuj dodawanie dwóch liczb zespolonych. 
Polecenie 4. Zaimplementuj odejmowanie dwóch liczb zespolonych. 
Polecenie 5. Zaimplementuj mnożenie dwóch liczb zespolonych. 
Polecenie 6. Opracuj menu dla zaimplementowanych funkcjonalności.
*/

import Foundation

struct LiczbaZespolona {
    var rzeczywista: Double
    var urojona: Double

    func opis() -> String {
        return "\(rzeczywista) + \(urojona)i"
    }

    func dodaj(_ inna: LiczbaZespolona) -> LiczbaZespolona {
        return LiczbaZespolona(rzeczywista: rzeczywista + inna.rzeczywista, urojona: urojona + inna.urojona)
    }

    func odejmij(_ inna: LiczbaZespolona) -> LiczbaZespolona {
        return LiczbaZespolona(rzeczywista: rzeczywista - inna.rzeczywista, urojona: urojona - inna.urojona)
    }

    func mnoz(_ inna: LiczbaZespolona) -> LiczbaZespolona {
        let rzeczywistaCzesc = rzeczywista * inna.rzeczywista - urojona * inna.urojona
        let urojonaCzesc = rzeczywista * inna.urojona + urojona * inna.rzeczywista
        return LiczbaZespolona(rzeczywista: rzeczywistaCzesc, urojona: urojonaCzesc)
    }
}

func wczytajLiczbe() -> LiczbaZespolona {
    print("Podaj część rzeczywistą:", terminator: " ")
    let rzeczywista = Double(readLine() ?? "0") ?? 0

    print("Podaj część urojoną:", terminator: " ")
    let urojona = Double(readLine() ?? "0") ?? 0

    return LiczbaZespolona(rzeczywista: rzeczywista, urojona: urojona)
}

func menu() {
    print("\nWybierz operację:")
    print("1. Dodawanie")
    print("2. Odejmowanie")
    print("3. Mnożenie")
    print("4. Wyjście")
}
/*
func main() {
    print("Wprowadź pierwszą liczbę zespoloną:")
    let liczba1 = wczytajLiczbe()

    print("Wprowadź drugą liczbę zespoloną:")
    let liczba2 = wczytajLiczbe()

    while true {
        menu()
        print("Twój wybór:", terminator: " ")
        guard let wybor = readLine(), let opcja = Int(wybor) else {
            print("Nieprawidłowy wybór. Spróbuj ponownie.")
            continue
        }

        switch opcja {
        case 1:
            let wynik = liczba1.dodaj(liczba2)
            print("Wynik dodawania: \(wynik.opis())")
        case 2:
            let wynik = liczba1.odejmij(liczba2)
            print("Wynik odejmowania: \(wynik.opis())")
        case 3:
            let wynik = liczba1.mnoz(liczba2)
            print("Wynik mnożenia: \(wynik.opis())")
        case 4:
            print("Koniec programu.")
            return
        default:
            print("Nieprawidłowy wybór. Spróbuj ponownie.")
        }
    }
}
main()
*/


/*
Zadanie 9.2.  
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę rzutOszczepem składającą się 
z identyfikatora osoby oraz trzech prób rzutów.   
Polecenie 2. Wczytaj dane dla czterech zawodników. 
Polecenie 3. Wyświetl zawodnika, który uzyskał największą średnią swoich rzutów. 
Polecenie 4. Usuń zawodnika, który uzyskał najmniejszą średnią swoich rzutów.
*/

import Foundation

struct RzutOszczepem {
    var identyfikator: String
    var proby: [Double]

    func srednia() -> Double {
        return proby.reduce(0, +) / Double(proby.count)
    }
}

func wczytajZawodnika() -> RzutOszczepem {
    print("Podaj identyfikator zawodnika:", terminator: " ")
    let identyfikator = readLine() ?? "Nieznany"

    var proby: [Double] = []
    for i in 1...3 {
        print("Podaj wynik próby \(i):", terminator: " ")
        let wynik = Double(readLine() ?? "0") ?? 0
        proby.append(wynik)
    }

    return RzutOszczepem(identyfikator: identyfikator, proby: proby)
}
/*
func main() {
    var zawodnicy: [RzutOszczepem] = []

    print("Wprowadź dane dla czterech zawodników:")
    for _ in 1...4 {
        zawodnicy.append(wczytajZawodnika())
    }

    if let najlepszy = zawodnicy.max(by: { $0.srednia() < $1.srednia() }) {
        print("Zawodnik z najwyższą średnią to: \(najlepszy.identyfikator) ze średnią: \(najlepszy.srednia())")
    }

    if let najgorszyIndex = zawodnicy.enumerated().min(by: { $0.element.srednia() < $1.element.srednia() })?.offset {
        let usuniety = zawodnicy.remove(at: najgorszyIndex)
        print("Zawodnik \(usuniety.identyfikator) został usunięty za najniższą średnią: \(usuniety.srednia())")
    }

    print("Pozostali zawodnicy:")
    for zawodnik in zawodnicy {
        print("\(zawodnik.identyfikator) ze średnią: \(zawodnik.srednia())")
    }
}
main()
*/

/*
Polecenie 1. Napisz program konsolowy, który zdefiniuje zbiór samochody składający się z modeli 
samochodów. 
Polecenie 2. Wprowadź nazwy dla 6 samochodów. 
Polecenie 3. Wyświetl wszystkie elementy zbioru. 
Polecenie 4. Wczytaj model samochodu od użytkownika i usuń go ze zbioru. Należy sprawdzić, 
czy element taki istnieje w zbiorze.
*/

import Foundation

func wprowadzSamochody() -> Set<String> {
    var samochody: Set<String> = []
    for i in 1...6 {
        print("Podaj nazwę samochodu \(i):", terminator: " ")
        if let nazwa = readLine(), !nazwa.isEmpty {
            samochody.insert(nazwa)
        }
    }
    return samochody
}

func wyswietlSamochody(_ samochody: Set<String>) {
    print("\nLista samochodów:")
    for samochod in samochody {
        print(samochod)
    }
}

func usunSamochod(zbioru: inout Set<String>) {
    print("\nPodaj nazwę samochodu do usunięcia:", terminator: " ")
    if let nazwa = readLine() {
        if zbioru.contains(nazwa) {
            zbioru.remove(nazwa)
            print("Samochód \(nazwa) został usunięty.")
        } else {
            print("Samochód \(nazwa) nie istnieje w zbiorze.")
        }
    }
}

/*
func main() {
    var samochody = wprowadzSamochody()
    wyswietlSamochody(samochody)
    usunSamochod(zbioru: &samochody)
    wyswietlSamochody(samochody)
}

main()
*/

/*
Zadanie 9.4.  
Polecenie 1. Napisz program konsolowy, który zdefiniuje słownik student, który zawiera nazwisko 
i identyfikator studenta. 
Polecenie 2. Dodaj 5 studentów na podstawie wczytanych danych od użytkownika. 
Polecenie 3. Wyświetl wszystkie dane. 
Polecenie 4. Wczytaj dane studenta i wyszukaj go. Jeśli istnieje należy wyświetlić dane. 
W przeciwnym wypadku wyświetl odpowiednią informację. 
Polecenie 5. Wczytaj dane studenta i jeśli istnieje, należy go usunąć.
*/

import Foundation

func wprowadzStudentow() -> [String: String] {
    var studenci: [String: String] = [:]
    for i in 1...5 {
        print("Podaj nazwisko studenta \(i):", terminator: " ")
        let nazwisko = readLine() ?? ""
        print("Podaj identyfikator studenta \(i):", terminator: " ")
        let identyfikator = readLine() ?? ""
        studenci[identyfikator] = nazwisko
    }
    return studenci
}

func wyswietlStudentow(_ studenci: [String: String]) {
    print("\nLista studentów:")
    for (identyfikator, nazwisko) in studenci {
        print("Identyfikator: \(identyfikator), Nazwisko: \(nazwisko)")
    }
}

func wyszukajStudenta(w studenci: [String: String]) {
    print("\nPodaj identyfikator studenta do wyszukania:", terminator: " ")
    if let identyfikator = readLine() {
        if let nazwisko = studenci[identyfikator] {
            print("Znaleziono studenta: Identyfikator: \(identyfikator), Nazwisko: \(nazwisko)")
        } else {
            print("Student z identyfikatorem \(identyfikator) nie istnieje.")
        }
    }
}

func usunStudenta(ze studenci: inout [String: String]) {
    print("\nPodaj identyfikator studenta do usunięcia:", terminator: " ")
    if let identyfikator = readLine() {
        if let nazwisko = studenci.removeValue(forKey: identyfikator) {
            print("Student \(nazwisko) z identyfikatorem \(identyfikator) został usunięty.")
        } else {
            print("Student z identyfikatorem \(identyfikator) nie istnieje.")
        }
    }
}
/*
func main() {
    var studenci = wprowadzStudentow()
    wyswietlStudentow(studenci)
    wyszukajStudenta(w: studenci)
    usunStudenta(ze: &studenci)
    wyswietlStudentow(studenci)
}

main()
*/

/*
Zadanie 9.5.  
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę loty składającą z miejsca 
wylotu (jako słownik: numer lotniska i jego nazwa), miejsca docelowego (jako słownik: numer 
lotniska i jego nazwa) oraz czas podróży w minutach. 
Polecenie 2. Wczytaj dane dla n lotów do tablicy (n – podaje użytkownik). Należy sprawdzić 
poprawność danych. 
Polecenie 3. Wyświetl dane wszystkich lotów. 
Polecenie 4. Wyświetl dane wszystkich lotów, które trwają dłużej niż średnia wszystkich. 
Zintegrowany Program Rozwoju Politechniki Lubelskiej – część druga 
Polecenie 5. Usuń dane wszystkich lotów, które trwają krócej niż średnia wszystkich lotów. 
Polecenie 6. Wyświetl dane lotów.
*/

import Foundation

struct Lot {
    var departure: [Int: String] = [:]
    var destination: [Int: String] = [:]
    var time: Int
}

func wczytajLot() -> Lot {
    print("Podaj numer lotniska wylotu:", terminator: " ")
    let numerWylotu = Int(readLine() ?? "0") ?? 0
    print("Podaj nazwę lotniska wylotu:", terminator: " ")
    let nazwaWylotu = readLine() ?? ""

    print("Podaj numer lotniska docelowego:", terminator: " ")
    let numerDocelowego = Int(readLine() ?? "0") ?? 0
    print("Podaj nazwę lotniska docelowego:", terminator: " ")
    let nazwaDocelowego = readLine() ?? ""

    print("Podaj czas lotu w minutach:", terminator: " ")
    let czas = Int(readLine() ?? "0") ?? 0

    return Lot(departure: [numerWylotu: nazwaWylotu], destination: [numerDocelowego: nazwaDocelowego], time: czas)
}

func wczytajLoty(n: Int) -> [Lot] {
    var loty: [Lot] = []
    for i in 1...n {
        print("Wprowadz dane dla lotu \(i):")
        loty.append(wczytajLot())
    }
    return loty
}

func wyswietlLoty(_ loty: [Lot]) {
    //print("\nLista wszystkich lotów:")
    for (index, lot) in loty.enumerated() {
        if let departure = lot.departure.first, let destination = lot.destination.first {
            print("Lot \(index + 1): Wylot - \(departure.value) (\(departure.key)), Docelowe - \(destination.value) (\(destination.key)), Czas: \(lot.time) minut")
        }
    }
}

func lotyDluzszeNizSrednia(_ loty: [Lot]) -> [Lot] {
    let srednia = Double(loty.reduce(0) { $0 + $1.time }) / Double(loty.count)
    return loty.filter { Double($0.time) > srednia }
}

func usunLotyKrotszeNizSrednia(_ loty: inout [Lot]) {
    let srednia = Double(loty.reduce(0) { $0 + $1.time }) / Double(loty.count)
    loty.removeAll { Double($0.time) < srednia }
}

func main() {
    print("Podaj liczbę lotów do wprowadzenia:", terminator: " ")
    let n = Int(readLine() ?? "0") ?? 0

    var loty = wczytajLoty(n: n)
    print("\nLista wszystkich lotów:")
    wyswietlLoty(loty)

    print("\nLoty dłuższe niż średnia:")
    let dluzszeLoty = lotyDluzszeNizSrednia(loty)
    wyswietlLoty(dluzszeLoty)

    usunLotyKrotszeNizSrednia(&loty)
    print("\nLista lotów po usunięciu krótszych niż średnia:")
    wyswietlLoty(loty)
}

main()
