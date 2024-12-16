//Zad1
enum Ocena: Double { //nwm czy nie brakuje Comparable ale dziala bez xd
    case dwojka = 2.0
    case trojka = 3.0
    case trojkaPlus = 3.5
    case czworka = 4.0
    case czworkaPlus = 4.5
    case piatka = 5.0
    
    static func < (lhs: Ocena, rhs: Ocena) -> Bool {
        return lhs.rawValue < rhs.rawValue
    }
}

typealias Student = (nazwisko: String, oceny: (Ocena, Ocena, Ocena))

func wczytajStudentow(n: Int) -> [Student] {
    var studenci = [Student]()
    
    for i in 1...n {
        print("Podaj nazwisko studenta \(i):")
        let nazwisko = readLine() ?? ""
        
        var oceny = (Ocena.dwojka, Ocena.dwojka, Ocena.dwojka)
        var poprawneOceny = false
        
        while !poprawneOceny {
            print("Podaj trzy oceny studenta \(i) (2.0, 3.0, 3.5, 4.0, 4.5, 5.0):")
            if let ocena1 = readLine(), let ocena2 = readLine(), let ocena3 = readLine() {
                if let o1 = Ocena(rawValue: Double(ocena1) ?? -1),
                   let o2 = Ocena(rawValue: Double(ocena2) ?? -1),
                   let o3 = Ocena(rawValue: Double(ocena3) ?? -1) {
                    oceny = (o1, o2, o3)
                    poprawneOceny = true
                } else {
                    print("Błędne oceny. Spróbuj ponownie.")
                }
            }
        }
        
        let student = (nazwisko: nazwisko, oceny: oceny)
        studenci.append(student)
    }
    
    return studenci
}

func wyswietlStudentowPosortowanych(studentowie: [Student]) {
    let posortowaniStudenci = studentowie.sorted { srednia(student: $0) > srednia(student: $1) }
    
    for student in posortowaniStudenci {
        print("\(student.nazwisko): Średnia ocen = \(srednia(student: student))")
    }
}

func srednia(student: Student) -> Double {
    let suma = student.oceny.0.rawValue + student.oceny.1.rawValue + student.oceny.2.rawValue
    return suma / 3.0
}

func najlepszyStudent(studentowie: [Student]) -> [Student] {
    guard let najlepszaSrednia = studentowie.map({ srednia(student: $0) }).max() else {
        return []
    }
    return studentowie.filter { srednia(student: $0) == najlepszaSrednia }
}

let n = 3 
let studenci = wczytajStudentow(n: n)

print("\nStudenci posortowani według średniej:")
wyswietlStudentowPosortowanych(studentowie: studenci)
print("\nNajlepsi studenci (z najwyższą średnią):")
let najlepsi = najlepszyStudent(studentowie: studenci)
for student in najlepsi {
    print("\(student.nazwisko): Średnia ocen = \(srednia(student: student))")
}

// Zad 2
enum Miesiac: String {
    case styczen = "Styczeń"
    case luty = "Luty"
    case marzec = "Marzec"
    case kwiecien = "Kwiecień"
    case maj = "Maj"
    case czerwiec = "Czerwiec"
    case lipiec = "Lipiec"
    case sierpien = "Sierpień"
    case wrzesien = "Wrzesień"
    case pazdziernik = "Październik"
    case listopad = "Listopad"
    case grudzien = "Grudzień"
}

func poraRoku(miesiac: Miesiac) -> String {
    switch miesiac {
    case .styczen, .luty, .grudzien:
        return "Zima"
    case .marzec, .kwiecien, .maj:
        return "Wiosna"
    case .czerwiec, .lipiec, .sierpien:
        return "Lato"
    case .wrzesien, .pazdziernik, .listopad:
        return "Jesień"
    }
}

let miesiac: Miesiac = .czerwiec
print("Miesiąc: \(miesiac.rawValue), Pora roku: \(poraRoku(miesiac: miesiac))")


//Zad 3 
enum Standard: String, Comparable {
    case niski = "Niski"
    case sredni = "Średni"
    case wysoki = "Wysoki"
    
    var order: Int {
        switch self {
        case .niski: return 0
        case .sredni: return 1
        case .wysoki: return 2
        }
    }
    
    static func < (lhs: Standard, rhs: Standard) -> Bool {
        return lhs.rawValue < rhs.rawValue
    }
}

struct Mieszkanie {
    var lokalizacja: String
    var powierzchnia: Double
    var cenaZaMetr: Double
    var standard: Standard
}

func wczytajMieszkania(liczbaMieszkan: Int) -> [Mieszkanie] {
    var mieszkania: [Mieszkanie] = []
    
    for i in 1...liczbaMieszkan {
        print("Wprowadź dane dla mieszkania \(i):")
        
        print("Podaj lokalizację:")
        let lokalizacja = readLine() ?? ""
        
        print("Podaj powierzchnię:")
        let powierzchnia = Double(readLine() ?? "") ?? 0.0
        
        print("Podaj cenę za metr:")
        let cenaZaMetr = Double(readLine() ?? "") ?? 0.0
        
        print("Podaj standard (niski, sredni, wysoki):")
        let standardString = readLine() ?? ""
        let standard: Standard
        switch standardString.lowercased() {
        case "niski":
            standard = .niski
        case "sredni":
            standard = .sredni
        case "wysoki":
            standard = .wysoki
        default:
            print("Nieprawidłowy standard, domyślnie ustawiono niski.")
            standard = .niski
        }
        
        let mieszkanie = Mieszkanie(lokalizacja: lokalizacja, powierzchnia: powierzchnia, cenaZaMetr: cenaZaMetr, standard: standard)
        mieszkania.append(mieszkanie)
    }
    
    return mieszkania
}

func wyswietlMieszkaniaPosortowane(mieszkania: [Mieszkanie]) {
    let posortowaneMieszkania = mieszkania.sorted { $0.standard.order < $1.standard.order }
    
    for mieszkanie in posortowaneMieszkania {
        print("Lokalizacja: \(mieszkanie.lokalizacja), Powierzchnia: \(mieszkanie.powierzchnia) m², Cena za metr: \(mieszkanie.cenaZaMetr) PLN, Standard: \(mieszkanie.standard.rawValue)")
    }
}

let liczbaMieszkan = 4
let mieszkania = wczytajMieszkania(liczbaMieszkan: liczbaMieszkan)
wyswietlMieszkaniaPosortowane(mieszkania: mieszkania)

