//
//  Dane2P.swift
//  kolokwium2
//
//  Created by student on 21/01/2025.
//

import Foundation

class Dane2P{
    var a:Punkt
    var b:Punkt
    init(a:Punkt, b:Punkt){
        self.a = a
        self.b = b
    }
    
    
    func cwiartka(a:Punkt) -> String?{
        if a.x > 0 && a.y > 0{
            return "I"
        } else if a.x > 0 && a.y < 0 {
            return "II"
        } else if a.x < 0 && a.y < 0 {
            return "III"
        } else if a.x < 0 && a.y > 0 {
            return "IV"
        } else if a.y == 0 {
            return "OY"
        } else if a.x == 0 {
            return "OX"
        } else if a.x == 0 && a.y == 0 {
            return "OO"
        }
        return nil
    }
    
    func cwiartki() -> (String, String){
        let a = cwiartka(a:self.a)
        let b = cwiartka(a:self.b)
        return (a!,b!)
    }
    
    func obliczAB() -> Double{
        return obliczDowolneAB(a: self.a, b: self.b)
    }
    
    func obliczDowolneAB(a:Punkt, b:Punkt) -> Double{
        let dx = pow(b.x - a.x,2)
        let dy = pow(b.y - a.y,2)
        return sqrt(dx+dy)
    }
    
    func translacja(dx:Double, dy:Double) -> (Punkt, Punkt){
        let temp_a = Punkt(x:self.a.x + dx, y:self.a.y + dy)
        let temp_b = Punkt(x:self.b.x + dx, y:self.b.y + dy)
        return (temp_a, temp_b)
    }
    
    
    func show(){
        print("Dane punktu A")
        self.a.show()
        print("Dane punktu B")
        self.b.show()
        print("Odległość między punktami wynosi \(obliczAB())")
    }
    
}
