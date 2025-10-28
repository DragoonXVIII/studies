package org.example;

public class zad_3_2_1 {
}

    abstract class Human{
        public double getId();
    }

    class Student extends Human{
        public double getId(){
            return Student.getIndex();
        }

        public double getIndex(){};
    }

    class Teacher extends Human{
        public double get(){
            return Teacher.getEmploeeNumber();
        }

        public double getEmploeeNumber(){};
    }

    final class PeopleInfo{
        public double humanId(Human hmn) {
            return hmn.getId();
        }
    }
