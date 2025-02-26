//
//  Dane3P.swift
//  kolokwium2
//
//  Created by student on 21/01/2025.
//

class Dane3P:Dane2P{
    var c:Punkt
    
    init(a:Punkt, b:Punkt, c:Punkt){
        self.c = c
        super.init(a: a, b: b)
    }
    
    func saWspolniowe() -> Bool{
        let a = obliczDowolneAB(a: self.a, b: self.b)
        let b = obliczDowolneAB(a: self.b, b: self.c)
        let c = obliczDowolneAB(a: self.c, b: self.a)
        print(a,b,c)
        return max(a,b,c) == ((a+b+c) - max(a,b,c))
        
    }
    
    func dlugosci() -> (Double, Double, Double){
        let a = obliczDowolneAB(a: self.a, b: self.b)
        let b = obliczDowolneAB(a: self.b, b: self.c)
        let c = obliczDowolneAB(a: self.c, b: self.a)
        return (a, b, c)
    }
    
    
    
    
    override func show(){
        print("Dane punktu A")
        self.a.show()
        print("Dane punktu B")
        self.b.show()
        print("Dane punktu C")
        self.c.show()
    }
}
