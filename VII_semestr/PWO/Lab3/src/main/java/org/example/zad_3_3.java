package org.example;

public class zad_3_3 {

}

public class User {
    public String userName;
    protected String login;
    private String pwdHash;
    UserService service;

    User(String userName, String login, String pwd) {
        this.useNname = username;
        this.login = login;
        this.pwdHash = SHA256.hash(pwd);
    }

    public void logIn() {
        if (pwdHash = SHA256.hash(pwd))
            service.logIn(username, pwdHash);
    }

    public void logOut() {
        service.logOut(username);
    }
}
public class SuperUser extends User{
    private double age;
    private String userName;
    private String login;
    public double[] permissions;

    SuperUser (String userName, String login, String pwd) {
        super.User();
    }
    //konstruktory super + ovveride
    public void setPermissions(double[] perms){
        permissions = perms;
    }
    public double[] getPermissions(){
        return permissions;
    }
    @Override
    public void logIn(){
        if(pwdHash = SHA256.hash(pwd))
            service.logIn(username, String.toUpperCase(pwdHash));
    }
    @Override
    public void logOut(){
        service.logOutWithPwd(username,
                String.toUpperCase(pwdHash));
    }
}

public class Admin extends User{
    private double age;
    private String userName;
    private String login;
    private boolean loggedIn = false;
    public double[] permissions;

    Admin (String userName, String login, String pwd){
        super.User();
    }
    public void setPermissions(double[] perms){
        System.out.println(“Set permissions”);
        permissions = perms;
    }
    public double getPermission(int index){
        return permissions.get(index);
    }
    @Override
    public void logIn(){
        if(pwdHash = SHA256.hash(pwd)){
            service.logIn(username, String.toUpperCase(pwdHash));
            loggedIn = true;
        }
    }
    @Override
    public void logOut(){
        service.logOutWithPwd(username,
        String.toUpperCase(pwdHash));
        loggedIn = false;
    }
}