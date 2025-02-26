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


let formatter = DateFormatter()
formatter.dateFormat = "yyyy/MM/dd"
if let date = formatter.date(from: "2021/12/20") {
    var i = date.distance(to: date)
} else {
    print("Invalid date format")
}
//jak wyswitlic w swift pole z obiektu ?
/*
mam string z peselem osoby powyzej 200 roku (oznacza ze do liczby miesiaca dodawane jest liczba 20), jak npaisac funkcje w swift która zwóci mi wiek na podstawie tego peselu?
*/