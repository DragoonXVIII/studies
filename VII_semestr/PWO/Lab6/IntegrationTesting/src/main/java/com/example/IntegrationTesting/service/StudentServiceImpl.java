package com.example.IntegrationTesting.service;

import com.example.IntegrationTesting.domain.StudentEntity;
import com.example.IntegrationTesting.repository.StudentRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
public class StudentServiceImpl implements StudentService {
    @Autowired
    private StudentRepository studentRepository;

    @Override
    public StudentEntity getStudentById(Long id) {
        return studentRepository.findById(id).orElse(null);
    }

    @Override
    public StudentEntity getStudentByName(String name) {
        return studentRepository.findByName(name);
    }

    @Override
    public List<StudentEntity> getAllStudents() {
        return studentRepository.findAll();
    }

    @Override
    public boolean exists(String name) {
        if (studentRepository.findByName(name)!=null) {
            return true;
        }
        return false;
    }

    public boolean existsFromId(Long Id) {
        if (studentRepository.findById(Id).isPresent()) {
            return true;
        }
        return false;
    }

    @Override
    public StudentEntity save(StudentEntity student) {
        return studentRepository.save(student);
    }
}
