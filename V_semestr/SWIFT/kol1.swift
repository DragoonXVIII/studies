func wylosujDane(n: Int) -> [(Int, Int)] {
    guard (5...10).contains(n) else {
        print("Liczba punktów musi być z przedziału 5 - 10")
        return []
    }
    var points: [(Int, Int)] = []
    for _ in 1...n {
        let x = Int.random(in: 0...10)
        let y = Int.random(in: 0...10)
        points.append((x, y))
    }
    return points
}

let points = wylosujDane(n: 7)
print("Wylosowane punkty: \(points)")

func obliczSredniaArytXY(punkty: [(Int, Int)]) -> (Double, Double) {
    let sumaX = punkty.map { Double($0.0) }.reduce(0, +)
    let sumaY = punkty.map { Double($0.1) }.reduce(0, +)
    let sredniaX = sumaX / Double(punkty.count)
    let sredniaY = sumaY / Double(punkty.count)
    return (sredniaX, sredniaY)
}

let srednie = obliczSredniaArytXY(punkty: points)
print("Średnia arytmetyczna X: \(srednie.0), Średnia arytmetyczna Y: \(srednie.1)")


func obliczOdchylenieStd(punkty: [(Int, Int)], srednie: (Double, Double)) -> (Double, Double) {
    let sumaKwadratowX = punkty.map { pow(Double($0.0) - srednie.0, 2) }.reduce(0, +)
    let sumaKwadratowY = punkty.map { pow(Double($0.1) - srednie.1, 2) }.reduce(0, +)
    let stdX = sqrt(sumaKwadratowX / Double(punkty.count))
    let stdY = sqrt(sumaKwadratowY / Double(punkty.count))
    return (stdX, stdY)
}

let odchylenieStd = obliczOdchylenieStd(punkty: points, srednie: srednie)
print("Odchylenie standardowe X: \(odchylenieStd.0), Odchylenie standardowe Y: \(odchylenieStd.1)")

/*Napisz funkcje obliczWspolczynnikR która przyjmujem tablice danych zwroconych przez funkcje wylosuj dane i zwroci czynnik R wyznaczonye wedlug kroków:
a) wyznaczy n SumX i SumY, SumX2 i SumY2 SumXY cyzli kolejno: liczba elementow tablicy,  suma wszystkich X, suma wszystkich Y, suma wszystkich x^2, suma wszystkich y^2, i sumą wszystkich iloczynów x*y.
Polcizy R według wzoru = n*Su