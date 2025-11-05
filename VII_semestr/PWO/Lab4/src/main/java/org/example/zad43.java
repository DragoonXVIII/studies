package org.example;

public class zad43 {
}

public class Student{


    private String studentName;
    private int studentIndex;
    private Logger logger;

    Student(String studentName, int studentIndex){
        this.studentName = studentName;
        this.studentIndex = studentIndex;
        logger.info(“Student: {} created.”, studentName);
    }

    public List<Mark> publishStudentMarks(Date date, int
            studentIndex) {
        // some business logic here
    }

    //This method is commented because project of this feature
    //was not ready on 03/18/2022
    //public List<Mark> printStudentMarks(Date date,
    //                               int studentIndex) {
    //   // some business logic here
    //}

    public Student setStudentPromotion(Student student, Lecture
            lecture){
        // some business logic here
    }

    // returns Student of the last year
    public Student getFifthYearStudent(){
        // some business logic here
    }

    // This method will be used for User Story: see Jira-1254
    // ticket
    // public void checkPayments(){
    //   // some business logic here
    //}

    public void graduateStudent(){

    }

    // TODO: this method should be extended - Feature 10.1
    public void checkStudentAbsence(){
        // some business logic here
    }

}