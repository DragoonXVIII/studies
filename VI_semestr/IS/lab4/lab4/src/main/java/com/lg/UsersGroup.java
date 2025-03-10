package com.lg;

import jakarta.persistence.*;
import java.util.HashSet;
import java.util.Set;

@Entity
public class UsersGroup {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @ManyToMany(mappedBy = "groups")
    private Set<User> users = new HashSet<>();

    public UsersGroup() {}

    public UsersGroup(String name) {
        this.name = name;
    }

    public void addUser(User user) {
        users.add(user);
        user.getGroups().add(this); // Synchronizacja relacji
    }

    public Set<User> getUsers() {
        return users;
    }

    public String getName() {
        return name;
    }
}
