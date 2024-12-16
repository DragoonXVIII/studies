//1
import Foundation

var tab: [Int] = Array(repeating: 1, count: 12) // Zmiana 1.0 na 1
for i in tab {
    print(i)
}

//2

tab = (1...10).map { _ in Int.random(in: 1...100) }
print("Początkowa tablica: \(tab)")

print("Podaj liczbę całkowitą do dodania na zerowy indeks:")
guard let firstNumberInput = readLine(), let firstNumber = Int(firstNumberInput) else {
    print("Nieprawidłowa liczba.")
    exit(0)
}
tab[0] = firstNumber

print("Podaj liczbę całkowitą do dodania na losowy indeks:")
guard let secondNumberInput = readLine(), let secondNumber = Int(secondNumberInput) else {
    print("Nieprawidłowa liczba.")
    exit(0)
}
let randomIndex = Int.random(in: 0..<tab.count)
tab[randomIndex] = secondNumber

print("Tablica po modyfikacjach: \(tab)")

//3
print("Podaj liczbę elementów tablicy:")
guard let countInput = readLine(), let count = Int(countInput), count > 0 else {
    print("Nieprawidłowa liczba elementów. Musi być liczbą dodatnią.")
    exit(0)
}

tab = []
for i in 0...count-1 {
    print("Podaj element \(i):")
    guard let elementInput = readLine(), let element = Int(elementInput) else {
        print("Nieprawidłowy element tablicy. Musi być liczbą całkowitą.")
        exit(0)
    }
    tab.append(element)
}

print("Podaj liczbę całkowitą do sprawdzenia:")
guard let numberInput = readLine(), let number = Int(numberInput) else {
    print("Nieprawidłowa liczba.")
    exit(0)
}

if let first = tab.first, number == first {
    print("Podana liczba jest pierwszym elementem tablicy.")
} else if let last = tab.last, number == last {
    print("Podana liczba jest ostatnim elementem tablicy.")
} else {
    print("Podana liczba nie jest ani pierwszym, ani ostatnim elementem tablicy.")
}

//4
import Foundation

let elementCount = Int.random(in: 3...100)
var array: [Int] = (1...elementCount).map { _ in Int.random(in: 3...100) }

print("Wygenerowana tablica: \(array)")

let sum = array.reduce(0, +) //suma reducem
let arithmeticMean = Double(sum) / Double(elementCount)
print("Średnia arytmetyczna: \(arithmeticMean)")

let evenElements = array.filter { $0 % 2 == 0 } //filter na parzystosc
let geometricMean: Double = evenElements.isEmpty ? 0 : pow(evenElements.map { Double($0) }.reduce(1, *), 1.0 / Double(evenElements.count))
print("Średnia geometryczna elementów parzystych: \(geometricMean)")

let harmonicMean: Double = elementCount > 0 ? Double(elementCount) / (array.map { 1.0 / Double($0) }.reduce(0, +)) : 0
print("Średnia harmoniczna: \(harmonicMean)")

//5
import Foundation
print("Podaj liczbę elementów tablicy (dodatnia liczba całkowita):")
guard let countInput = readLine(), let elementCount = Int(countInput), elementCount > 0 else {
    print("Nieprawidłowa liczba elementów. Musi być liczbą dodatnią.")
    exit(0)
}

var array1: [Int] = (1...elementCount).map { _ in Int.random(in: 1...20) }
var array2: [Int] = (1...elementCount).map { _ in Int.random(in: 1...20) }

print("Wygenerowana tablica 1: \(array1)")
print("Wygenerowana tablica 2: \(array2)")

let areIdentical = Set(array1) == Set(array2)

if areIdentical {
    print("Obie tablice zawierają identyczne elementy.")
} else {
    print("Tablice nie zawierają identycznych elementów.")
}

let matrix = [
    [10, 20, 30],
    [40, 50, 60],
    [70, 80, 90]
]

for i in 0..<matrix.count {
    for j in 0..<matrix[i].count {
        print("\(matrix[i][j])", terminator: "  ")
    }
    print() 
}
