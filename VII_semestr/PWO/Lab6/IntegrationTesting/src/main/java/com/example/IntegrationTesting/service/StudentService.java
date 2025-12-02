package com.example.IntegrationTesting.service;

import com.example.IntegrationTesting.domain.StudentEntity;
import java.util.List;

public interface StudentService {
    public StudentEntity getStudentById(Long id);
    public StudentEntity getStudentByName(String name);
    public List<StudentEntity> getAllStudents();
    public boolean exists(String email);
    public StudentEntity save(StudentEntity student);
    public boolean existsFromId(Long id);
}