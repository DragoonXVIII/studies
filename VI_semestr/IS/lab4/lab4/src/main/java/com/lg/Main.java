package com.lg;

import jakarta.persistence.*;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.TypedQuery;

import java.io.IOException;
import java.util.Arrays;
import java.util.List;
import java.util.HashSet;


public class Main {
    public static void main(String[] args) {
        // Zad 4.1-4.2
        /*
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = factory.createEntityManager();

        em.getTransaction().begin();

        // Sprawdzenie, czy użytkownik o loginie już istnieje
        String loginToCheck = "test_1";
        User existingUser = em.createQuery("SELECT u FROM User u WHERE u.login = :login", User.class)
                .setParameter("login", loginToCheck)
                .getResultStream()
                .findFirst()
                .orElse(null);

        if (existingUser == null) {
            User u1 = new User(null, loginToCheck, "test_1", "Andrzej", "Kowalski", Sex.MALE);
            em.persist(u1);
            System.out.println("Nowy użytkownik został dodany.");
        } else {
            System.out.println("Użytkownik o podanym loginie już istnieje.");
        }

        em.getTransaction().commit();
        em.close();
        factory.close();
         */

        // Zad 4.3
        /*
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();

        try {
            //  ZADANIE 4.3.1: Utrwalanie 5 użytkowników i 5 ról
            em.getTransaction().begin();

            // Tworzenie ról
            List<Role> roles = Arrays.asList(
                    new Role("ADMIN"),
                    new Role("USER"),
                    new Role("MODERATOR"),
                    new Role("EDITOR"),
                    new Role("GUEST")
            );
            roles.forEach(em::persist); // Zapis ról do bazy

            // Tworzenie użytkowników
            List<User> users = Arrays.asList(
                    new User("user1", "pass1", "Jan", "Kowalski", Sex.MALE, roles.get(0)),
                    new User("user2", "pass2", "Anna", "Nowak", Sex.FEMALE, roles.get(1)),
                    new User("user3", "pass3", "Tomasz", "Lis", Sex.MALE, roles.get(2)),
                    new User("user4", "pass4", "Ewa", "Dąbrowska", Sex.FEMALE, roles.get(3)),
                    new User("user5", "pass5", "Robert", "Wójcik", Sex.MALE, roles.get(4))
            );
            users.forEach(em::persist); // Zapis użytkowników do bazy

            em.getTransaction().commit();
            System.out.println(" Zapisano użytkowników i role do bazy!");

            //  ZADANIE 4.3.2: Aktualizacja hasła użytkownika o id = 1
            em.getTransaction().begin();
            User user = em.find(User.class, 1L); // Pobranie użytkownika o ID = 1
            if (user != null) {
                user.setPassword("new_secure_password");
                em.merge(user); // Aktualizacja użytkownika w bazie
                System.out.println(" Zaktualizowano hasło użytkownika o ID = 1");
            } else {
                System.out.println(" Użytkownik o ID = 1 nie istnieje!");
            }
            em.getTransaction().commit();

            // ZADANIE 4.3.3: Usunięcie roli o id = 5
            em.getTransaction().begin();
            Role roleToDelete = em.find(Role.class, 5L); // Pobranie roli o ID = 5
            if (roleToDelete != null) {
                em.remove(roleToDelete); // Usunięcie roli
                System.out.println(" Usunięto rolę o ID = 5");
            } else {
                System.out.println(" Rola o ID = 5 nie istnieje!");
            }
            em.getTransaction().commit();

        } catch (Exception e) {
            em.getTransaction().rollback(); // W razie błędu wycofujemy transakcję
            e.printStackTrace();
        } finally {
            em.close();
            factory.close();
        }
        */

        // Zadanie 4.3.4
        /*
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();

        try {
            em.getTransaction().begin();

            //  Tworzymy zapytanie JPQL do pobrania użytkowników o nazwisku "Kowalski"
            TypedQuery<User> query = em.createQuery(
                    "SELECT u FROM User u WHERE u.lastName = :lastName",
                    User.class
            );
            query.setParameter("lastName", "Kowalski");

            // Pobieramy listę wyników
            List<User> users = query.getResultList();

            //  Wypisujemy znalezionych użytkowników
            if (users.isEmpty()) {
                System.out.println(" Brak użytkowników o nazwisku 'Kowalski'.");
            } else {
                System.out.println(" Znaleziono użytkowników o nazwisku 'Kowalski':");
                for (User user : users) {
                    System.out.println(" ID: " + user.getId() +
                            ", Imię: " + user.getFirstName() +
                            ", Nazwisko: " + user.getLastName() +
                            ", Login: " + user.getLogin());
                }
            }

            em.getTransaction().commit();
        } catch (Exception e) {
            System.err.println(" Błąd podczas pobierania użytkowników: " + e.getMessage());
            e.printStackTrace();
        } finally {
            em.close();
            emf.close();
        }
        */

        // Zadanie 4.4.4
        /*
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();
        // Tworzenie użytkownika

        try {
            em.getTransaction().begin();

            // Pobieranie istniejących ról z bazy
            Role adminRole = em.find(Role.class, 1L); // Zakładamy, że ADMIN ma ID = 1
            Role userRole = em.find(Role.class, 2L);  // Zakładamy, że USER ma ID = 2

            if (adminRole == null || userRole == null) {
                throw new RuntimeException("Nie znaleziono wymaganych ról w bazie!");
            }

            // Tworzenie nowego użytkownika
            User newUser = new User("jan_kowalski","password","Jan","Kowalski", Sex.MALE);

            // Przypisanie istniejących ról do użytkownika
            newUser.addRole(adminRole);
            newUser.addRole(userRole);

            // Zapisanie użytkownika w bazie
            em.persist(newUser);

            // Zatwierdzenie transakcji
            em.getTransaction().commit();

            System.out.println("Nowy użytkownik został dodany z istniejącymi rolami!");

        } catch (Exception e) {
            em.getTransaction().rollback();
            e.printStackTrace();
        } finally {
            em.close();
            emf.close();
        }
        */

        // zad 4.4.5
        /*
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();

        try {
            em.getTransaction().begin();

            // Tworzymy użytkownika
            User user1 = new User("jan_k0owalski","password","Jan","Kowalski", Sex.MALE);

            // Tworzymy grupy
            UsersGroup groupA = new UsersGroup("London City Group");
            UsersGroup groupB = new UsersGroup("New York City Group");

            // Przypisujemy użytkownika do grup
            user1.addGroup(groupA);
            user1.addGroup(groupB);

            // Zapisujemy wszystko do bazy
            em.persist(groupA);
            em.persist(groupB);
            em.persist(user1);

            em.getTransaction().commit();

            System.out.println("Użytkownik i grupy zostały zapisane!");

        } catch (Exception e) {
            em.getTransaction().rollback();
            e.printStackTrace();
        } finally {
            em.close();
            emf.close();
        }
        */

        //Zad 4.5
        /*
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();
        try {
            em.getTransaction().begin();

            // Tworzymy nowego użytkownika
            User user = new User("jan_kowal", "haslo123", "Jan", "Kowalski", Sex.MALE);

            // Wczytujemy obrazek
            byte[] imageBytes = ImageUtil.loadImageAsBytes("D:/foto.jpg");
            user.setProfilePicture(imageBytes);

            // Zapisujemy użytkownika w bazie
            em.persist(user);

            em.getTransaction().commit();

            System.out.println("Użytkownik z obrazkiem zapisany w bazie!");

        } catch (IOException e) {
            System.err.println("Błąd podczas wczytywania obrazka: " + e.getMessage());
        } catch (Exception e) {
            em.getTransaction().rollback();
            e.printStackTrace();
        } finally {
            em.close();
            emf.close();
        }
        */

        //FULL:
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = emf.createEntityManager();

        try {
            em.getTransaction().begin();

            // Tworzenie rol
            List<Role> roles = Arrays.asList(
                    new Role("ADMIN"),
                    new Role("USER"),
                    new Role("MODERATOR"),
                    new Role("EDITOR"),
                    new Role("GUEST")
            );
            // Zapis rol
            roles.forEach(em::persist);

            // Tworzenie uztkownikow
            List<User> users = Arrays.asList(
                    new User("user1", "pass1", "Jan", "Kowalski", Sex.MALE, new HashSet<>(Arrays.asList(roles.get(0), roles.get(1)))),
                    new User("user2", "pass2", "Anna", "Nowak", Sex.FEMALE, new HashSet<>(Arrays.asList(roles.get(1)))),
                    new User("user3", "pass3", "Tomasz", "Lis", Sex.MALE, new HashSet<>(Arrays.asList(roles.get(2), roles.get(1)))),
                    new User("user4", "pass4", "Ewa", "Dąbrowska", Sex.FEMALE, new HashSet<>(Arrays.asList(roles.get(3)))),
                    new User("user5", "pass5", "Robert", "Wójcik", Sex.MALE, new HashSet<>(Arrays.asList(roles.get(4))))
            );

            // Dodanie grup uzytkownikom
            UsersGroup groupA = new UsersGroup("London City Group");
            UsersGroup groupB = new UsersGroup("New York City Group");

            users.get(0).addGroup(groupA);
            users.get(0).addGroup(groupB);
            users.get(1).addGroup(groupA);
            users.get(2).addGroup(groupB);
            users.get(3).addGroup(groupA);
            users.get(4).addGroup(groupA);
            users.get(4).addGroup(groupB);

            // Zapis grup
            em.persist(groupA);
            em.persist(groupB);

            // Zapis uztkownikow
            users.forEach(em::persist);

            // Super uzytkownik z pfp obrazkiem
            User user = new User("super_user", "haslo123", "SUPER", "EXTRA", Sex.MALE);

            // Wczytujemy obrazek
            byte[] imageBytes = ImageUtil.loadImageAsBytes("C:/foto.jpg");
            user.setProfilePicture(imageBytes);

            // Zapis uzytkownika
            em.persist(user);

            em.getTransaction().commit();
            System.out.println(" Zapisano użytkowników i role do bazy!");
        }
        catch (Exception e) {
            em.getTransaction().rollback();
            e.printStackTrace();
        }
        finally {
            em.close();
            emf.close();
        }
    }
}
