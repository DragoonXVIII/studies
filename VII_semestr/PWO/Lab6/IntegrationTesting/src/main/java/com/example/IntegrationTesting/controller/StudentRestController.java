package com.example.IntegrationTesting.controller;

import com.example.IntegrationTesting.domain.StudentEntity;
import com.example.IntegrationTesting.service.StudentService;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class StudentRestController {
    @Autowired
    private StudentService studentService;

    @PostMapping("/students")
    public ResponseEntity<StudentEntity>
    createStudent(@RequestBody StudentEntity student) {
        HttpStatus status = HttpStatus.CREATED;
        StudentEntity saved = studentService.save(student);
        return new ResponseEntity<>(saved, status);
    }

    @GetMapping("/students")
    public List<StudentEntity> getAllStudents() {
        return studentService.getAllStudents();
    }

    @GetMapping("/students/id/{id}")
    public StudentEntity getstudentById(@PathVariable Long id) {
        return studentService.getStudentById(id);
    }

    @GetMapping("/students/name/{name}")
    public StudentEntity getStudentByName(@PathVariable String name) {
        return studentService.getStudentByName(name);
    }

    @GetMapping("/students/exists/{name}")
    public boolean studentExists(@PathVariable String name) {
        return studentService.exists(name);
    }

    @GetMapping("/students/existsFromId/{id}")
    public ResponseEntity<Boolean> existsFromId(@PathVariable Long id) {
        boolean result = studentService.existsFromId(id);
        return ResponseEntity.ok(result);
    }

}