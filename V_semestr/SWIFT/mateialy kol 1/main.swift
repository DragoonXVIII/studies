//
//  main.swift
//  kolokwium2
//
//  Created by student on 21/01/2025.
//

import Foundation


func test_trojkat(a:Double, b:Double, c:Double) -> Double{
    if max(a,b,c) < ((a + b + c) - max(a,b,c)){
        return 1
    }
    return 0
}


func testuj(odcinki:[Dane2P]) -> [Dane2P]?{
    
    var mozna:[Dane2P] = []
    var odcinki2 = odcinki
    odcinki2.removeFirst()
    var odcinki3 = odcinki2
    odcinki3.removeFirst()
    
    for odcinek in odcinki{
        for odcinek2 in odcinki2{
            for odcinek3 in odcinki3{
                
                    if test_trojkat(a: odcinek.obliczAB(), b: odcinek2.obliczAB(), c: odcinek3.obliczAB()) == 1{
                        mozna.append(odcinek)
                        mozna.append(odcinek2)
                        mozna.append(odcinek3)
                        return mozna
                    
                    }else{
                        continue
                    }
                
            }
        }
    }
    return nil
}


func testuj2(obiekty:[Dane3P]) -> [Dane3P]?{
    var niemozna:[Dane3P] = []
    for elem in obiekty{
        let abc = elem.dlugosci()
        if test_trojkat(a:abc.0, b:abc.1, c:abc.2) == 0{
            niemozna.append(elem)
        }
    }
    if niemozna.isEmpty {
        return nil
    }
    return niemozna
}


func na4() -> Int?{
    
    var odcinki:[Dane2P] = []
    
    for _ in 1...6{
        let a = Punkt(x:Double(Int.random(in: -20...20)),y:Double(Int.random(in: -20...20)))
        let b = Punkt(x:Double(Int.random(in: -20...20)), y:Double(Int.random(in: -20...20)))
        odcinki.append(Dane2P(a: a, b: b))
    }
    
    for odcinek in odcinki{
        odcinek.show()
        print("Cwiartki tego odcinka to:")
        print(odcinek.cwiartki())
        let punkty = odcinek.translacja(dx: 5, dy: 5)
        print("Punkt a po translacji o 5")
        punkty.0.show()
        print("Punkt b po translacji o 5")
        punkty.1.show()
    }
    
    guard let a = testuj(odcinki: odcinki),true else{
        print("Brak odcinkow do stworzenia trojkata")
        return nil
    }
    
    print("Odcinki spelniajace warunki")
    for elem in a{
        print("\nOdcinek\n")
        elem.show()
    }
    
    return 0
    
}

func na5() -> Int?{
    
    var obiekty:[Dane3P] = []
    
    for _ in 1...6{
        let a = Punkt(x:Double(Int.random(in: -5...5)),y:Double(Int.random(in: -5...5)))
        let b = Punkt(x:Double(Int.random(in: -5...5)), y:Double(Int.random(in: -5...5)))
        let c = Punkt(x:Double(Int.random(in: -5...5)), y:Double(Int.random(in: -5...5)))
        obiekty.append(Dane3P(a: a, b: b,c:c))
    }
    let tempA = Punkt(x:0, y: 0)
    let tempB = Punkt(x:1, y:1)
    let tempC = Punkt(x:2,y:2)
    
    obiekty.append(Dane3P(a: tempA, b: tempB, c: tempC))
    
    for obiekt in obiekty{
        obiekt.show()
        if obiekt.saWspolniowe(){
            print("Ten obiekt jest wspolniowy")
        }else{
            print("Ten obiekt nie jest wspolniowy")
        }
    }
    
    
    
    guard let a = testuj2(obiekty: obiekty),true else{
        print("Brak obiektow ktore nie moga stworzyc trojkata")
        return nil
    }

    
    print("Obiekty z ktorych nie mozna stworzy")
    for elem in a{
        print("\nObiekt\n")
        elem.show()
    }
    
    print(obiekty[0].obliczDowolneAB(a: obiekty[0].a, b: obiekty[0].c))
    
    return 0
    
}


print(na5())

