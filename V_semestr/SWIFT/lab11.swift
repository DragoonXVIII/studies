/*Zadanie 11.1.  
Polecenie 1. Utwórz klasę Prostokąt, scharakteryzowaną przez długości boków. 
Polecenie 2. Utwórz metodę init(). 
Polecenie 3. Utwórz funkcję zwracającą pole figury. 
Polecenie 4. Utwórz funkcję zwracającą obwód figury. 
Polecenie 3. Utwórz funkcję wyświetlająca dane figury w postaci wymiarów, pola i obwodu. 
Polecenie 7. Przetestuj utworzone funkcje*/

class Prostokat {
	var dlugosc: Double
	var szerokosc: Double
	
	init(dlugosc: Double, szerokosc: Double) {
		self.dlugosc = dlugosc
		self.szerokosc = szerokosc
	}
	
	func pole() -> Double {
		return dlugosc * szerokosc
	}
	
	func obwod() -> Double {
		return 2 * (dlugosc + szerokosc)
	}
	
	func wyswietlDane() {
		print("Wymiary: \(dlugosc) x \(szerokosc)")
		print("Pole: \(pole())")
		print("Obwod: \(obwod())")
	}
}

let prostokat = Prostokat(dlugosc: 5.0, szerokosc: 3.0)
prostokat.wyswietlDane()

/*
Zadanie 11.2.  
Polecenie 1. Utwórz klasę Prostopadłościan, dziedziczącą po klasie Prostokat 
i scharakteryzowaną dodatkowo przez wysokość. 
Polecenie 2. Utwórz metodę init(). 
Polecenie 3. Utwórz funkcję zwracającą pole całkowite bryły. 
Polecenie 4. Utwórz funkcję zwracającą sumę krawędzi. 
Polecenie 5. Utwórz funkcję zwracającą objętość bryły. 
Polecenie 6. Utwórz funkcję wyświetlająca dane bryły w postaci: wymiarów, pola całkowitego 
oraz objętości. 
Polecenie 7. Przetestuj utworzone funkcje. 
*/

class Prostopadloscian: Prostokat {
	var wysokosc: Double
	
	init(dlugosc: Double, szerokosc: Double, wysokosc: Double) {
		self.wysokosc = wysokosc
		super.init(dlugosc: dlugosc, szerokosc: szerokosc)
	}
	
	func poleCalkowite() -> Double {
		return 2 * (dlugosc * szerokosc + dlugosc * wysokosc + szerokosc * wysokosc)
	}
	
	func sumaKrawedzi() -> Double {
		return 4 * (dlugosc + szerokosc + wysokosc)
	}
	
	func objetosc() -> Double {
		return dlugosc * szerokosc * wysokosc
	}
	
	func wyswietlDaneBryly() {
		print("Wymiary: \(dlugosc) x \(szerokosc) x \(wysokosc)")
		print("Pole calkowite: \(poleCalkowite())")
		print("Objetosc: \(objetosc())")
	}
}

let prostopadloscian = Prostopadloscian(dlugosc: 5.0, szerokosc: 3.0, wysokosc: 4.0)
prostopadloscian.wyswietlDaneBryly()

/*
Zadanie 11.3.  
Polecenie 1. Utwórz klasę Student, dziedziczącą po klasie Osoba (zad. 10.5) i scharakteryzowaną 
przez: numer indeksu, kierunek studiów zdefiniowaną jako typ wyliczeniowy (składający się 
z elementów: Informatyka, Matematyka, Filozofia i Elektrotechnika), rok studiów, oceny z 5 
przedmiotów. Oceny powinny być zdefiniowane jako typ wyliczeniowy (2.0; 3.0; 3.5; 4.0; 4.5; 
5.0). 
Polecenie 2. Utwórz metodę init(). Kierunek studiów powinien być zdefiniowany jako typ 
wyliczeniowy. Należy zapewnić poprawność danych wprowadzonych ocen. 
Polecenie 3. Utwórz funkcję wyznaczającą średnią ocen studenta. 
Polecenie 4. Utwórz funkcję wyświetlającą dane studenta. 
Polecenie 5. Utwórz tablicę studentów. Liczbę studentów należy pobrać od użytkownika. Należy 
wczytać dane studentów, w tym oceny. W tym celu należy utworzyć następujące funkcje: 
• wczytajRokUrodzenia() zwracającą poprawny rok. Należy wymusić poprawność danych; 
• wczytajKierunekStudiow() zwracającą kierunek studiów zgodny ze zdefiniowanym typem 
wyliczeniowym. Należy wymusić poprawność danych; 
• wczytajRokStudiow() zwracającą rok studiów. Należy wymusić poprawność danych; 
• wczytajOcenyStudenta(liczbaOcen: Int) zwracającą tablicę pięciu ocen studenta. Oceny 
muszą być zgodne ze zdefiniowanym typem wyliczeniowym. Należy wymusić 
poprawność danych; 
• wczytajDaneStudenta() zwracającą obiekt typu Student i korzystającą ze wszystkich 
utworzonych funkcji. 
Polecenie 6. Wyświetl wszystkich studentów studiujących na podanym przez użytkownika 
kierunku. Należy utworzyć odpowiednią funkcję. 
*/

import Foundation

class Osoba {
	var imie: String
	var nazwisko: String
	
	init(imie: String, nazwisko: String) {
		self.imie = imie
		self.nazwisko = nazwisko
	}
}

enum KierunekStudiow: String {
	case Informatyka, Matematyka, Filozofia, Elektrotechnika
}

enum Ocena: Double {
	case niedostateczny = 2.0, dostateczny = 3.0, dostatecznyPlus = 3.5, dobry = 4.0, dobryPlus = 4.5, bardzoDobry = 5.0
}

class Student: Osoba {
	var numerIndeksu: String
	var kierunek: KierunekStudiow
	var rokStudiow: Int
	var oceny: [Ocena] = Array(repeatinghow?: .niedostateczny, count: 5)
	var najlepszeWyniki: [(sezon: Int, punkty: Int)] = []

	func dodajWynik(sezon: Int, punkty: Int) {
		najlepszeWyniki.append((sezon: sezon, punkty: punkty))
		najlepszeWyniki.sort { $0.punkty > $1.punkty }
		if najlepszeWyniki.count > 5 {
			najlepszeWyniki.removeLast()
		}
	}
	var absolwenci: [Absolwent] = [
		Absolwent(imie: "Jan", nazwisko: "Kowalski", numerIndeksu: "12345", kierunek: .Informatyka, rokStudiow: 3, oceny: [.dobry, .dobryPlus, .bardzoDobry, .dobry, .dobryPlus], rokUkonczenia: 2020),
		Absolwent(imie: "Anna", nazwisko: "Nowak", numerIndeksu: "23456", kierunek: .Matematyka, rokStudiow: 2, oceny: [.dobry, .dobryPlus, .bardzoDobry, .dobry, .dobryPlus], rokUkonczenia: 2021),
		Absolwent(imie: "Piotr", nazwisko: "Wiśniewski", numerIndeksu: "34567", kierunek: .Filozofia, rokStudiow: 4, oceny: [.dobry, .dobryPlus, .bardzoDobry, .dobry, .dobryPlus], rokUkonczenia: 2019),
		Absolwent(imie: "Katarzyna", nazwisko: "Wójcik", numerIndeksu: "45678", kierunek: .Elektrotechnika, rokStudiow: 1, oceny: [.dobry, .dobryPlus, .bardzoDobry, .dobry, .dobryPlus], rokUkonczenia: 2022),
		Absolwent(imie: "Michał", nazwisko: "Kowalczyk", numerIndeksu: "56789", kierunek: .Informatyka, rokStudiow: 5, oceny: [.dobry, .dobryPlus, .bardzoDobry, .dobry, .dobryPlus], rokUkonczenia: 2018)
	]


	class Absolwent: Student {
		var rokUkonczenia: Int
		
		init(imie: String, nazwisko: String, numerIndeksu: String, kierunek: KierunekStudiow, rokStudiow: Int, oceny: [Ocena], rokUkonczenia: Int) {
			self.rokUkonczenia = rokUkonczenia
			super.init(imie: imie, nazwisko: nazwisko, numerIndeksu: numerIndeksu, kierunek: kierunek, rokStudiow: rokStudiow, oceny: oceny)
		}
		
		override func wyswietlDane() {
			super.wyswietlDane()
			print("Rok ukończenia: \(rokUkonczenia)")
		}
	}
	
	init(imie: String, nazwisko: String, numerIndeksu: String, kierunek: KierunekStudiow, rokStudiow: Int, oceny: [Ocena]) {
		self.numerIndeksu = numerIndeksu
		self.kierunek = kierunek
		self.rokStudiow = rokStudiow
		self.oceny = oceny
		super.init(imie: imie, nazwisko: nazwisko)
	}
	
	func sredniaOcen() -> Double {
		let suma = oceny.reduce(0) { $0 + $1.rawValue }
		return suma / Double(oceny.count)
	}
	
	func wyswietlDane() {
		print("Imię: \(imie), Nazwisko: \(nazwisko), Numer indeksu: \(numerIndeksu), Kierunek: \(kierunek.rawValue), Rok studiów: \(rokStudiow), Średnia ocen: \(sredniaOcen())")
	}
}

func wczytajRokUrodzenia() -> Int {
	while true {
		print("Podaj rok urodzenia: ", terminator: "")
		if let input = readLine(), let rok = Int(input), rok > 1900 && rok < 2023 {
			return rok
		} else {
			print("Niepoprawny rok. Spróbuj ponownie.")
		}
	}
}

func wczytajKierunekStudiow() -> KierunekStudiow {
	while true {
		print("Podaj kierunek studiów (Informatyka, Matematyka, Filozofia, Elektrotechnika): ", terminator: "")
		if let input = readLine(), let kierunek = KierunekStudiow(rawValue: input) {
			return kierunek
		} else {
			print("Niepoprawny kierunek. Spróbuj ponownie.")
		}
	}
}



func wczytajRokStudiow() -> Int {
	while true {
		print("Podaj rok studiów: ", terminator: "")
		if let input = readLine(), let rok = Int(input), rok > 0 && rok <= 5 {
			return rok
		} else {
			print("Niepoprawny rok studiów. Spróbuj ponownie.")
		}
	}
}

func wczytajOcenyStudenta(liczbaOcen: Int) -> [Ocena] {
	var oceny: [Ocena] = []
	for i in 1...liczbaOcen {
		while true {
			print("Podaj ocenę \(i) (2.0, 3.0, 3.5, 4.0, 4.5, 5.0): ", terminator: "")
			if let input = readLine(), let ocena = Ocena(rawValue: Double(input) ?? 0) {
				oceny.append(ocena)
				break
			} else {
				print("Niepoprawna ocena. Spróbuj ponownie.")
			}
		}
	}
	return oceny
}

func wczytajDaneStudenta() -> Student {
	print("Podaj imię: ", terminator: "")
	let imie = readLine() ?? ""
	print("Podaj nazwisko: ", terminator: "")
	let nazwisko = readLine() ?? ""
	print("Podaj numer indeksu: ", terminator: "")
	let numerIndeksu = readLine() ?? ""
	let kierunek = wczytajKierunekStudiow()
	let rokStudiow = wczytajRokStudiow()
	let oceny = wczytajOcenyStudenta(liczbaOcen: 5)
	
	return Student(imie: imie, nazwisko: nazwisko, numerIndeksu: numerIndeksu, kierunek: kierunek, rokStudiow: rokStudiow, oceny: oceny)
}

func wyswietlStudentowNaKierunku(studenci: [Student], kierunek: KierunekStudiow) {
	for student in studenci where student.kierunek == kierunek {
		student.wyswietlDane()
	}
}

// Example usage
let liczbaStudentow = 2
var studenci: [Student] = []
for _ in 1...liczbaStudentow {
	studenci.append(wczytajDaneStudenta())
}

print("Podaj kierunek studiów do wyświetlenia: ", terminator: "")
if let input = readLine(), let kierunek = KierunekStudiow(rawValue: input) {
	wyswietlStudentowNaKierunku(studenci: studenci, kierunek: kierunek)
} else {
	print("Niepoprawny kierunek.")
}

/*
Utwórz klasę Osoba z polami imie, nazwisko pesel, obywatelstwo
*/