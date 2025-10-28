package org.example;

public class zad_3_5 {
}

// jeszcze sie mozna pokusic o entity pod playerem i enemy ale to tak bez przesady

abstract class Player {
    enum Type

    public void up();
    public void down();
    public void forward();
    public void backward();
    public getType(){
        return Type;
    }
}

abstract class Enemy {
    enum Type
    public getType(){
        return Type;
    }
}

public class GreenSoldier extends Player

public class PlatformGame {

    Level level;
    GameMap gameMap;
    ArrayList<Platform> platforms;
    Player player;
    ArrayList<Oponents> oponents;
    ArrayList<Treasure> treasures;
    double score;
    String playerName;
    Image avatar;
    int nOfGroundPlatforms;
    Colour groundPlatformColor;
    int nOfEnemy;
    enemy typeEnemy;
    int nOfDiamonds;
    int diamondValue;

    PlatformGame(String playerName) {
        level = new FirstLevel(„Level for begginers”);
        gameMap = new EuropeMap(“Green background”);
        player = new player(Type);
        for (int i = 0; i < nOfGroundPlatforms; i++) {
            platforms.add(new GroundPlatform(groundPlatformColor));
        }
        for (int i = 0; i < nOfEnemy; i++) {
            oponents.add(new enemyType.);
        }
        for (int i = 0; i < nOfDiamonds; i++) {
            treasures.add(new Diamond(diamondValue));
        }
        score = 0;
        this.playerName = playerName;
        avatar = new Avatar(this.playerName);
    }

    public void changeLevel() {
        level.next(); //w level jest metoda next zmieniajaca na kolejny element w zapetlonej liscie
    }

    public void movePlayer(int direction) {
        switch (direction) {
            case 1:
                if (player instanceof GreenSoldier) {
                    ((GreenSoldier) player).upGreen();
                } else if (player instanceof BlackSoldier) {
                    ((BlackSoldier) player).upBlack();
                } else if (player instanceof Alien) {
                    ((Alien) player).upAlien();
                }
                break;
            case 2:
                if (player instanceof GreenSoldier) {
                    ((GreenSoldier) player).downGreen();
                } else if (player instanceof BlackSoldier) {
                    ((BlackSoldier) player).downBlack();
                } else if (player instanceof Alien) {
                    ((Alien) player).downAlien();
                }
                break;
            case 3:
                if (player instanceof GreenSoldier) {
                    ((GreenSoldier) player).forwardGreen();
                } else if (player instanceof BlackSoldier) {
                    ((BlackSoldier) player).forwardBlack();
                } else if (player instanceof Alien) {
                    ((Alien) player).forwardAlien();
                }
                break;
            case 4:
                if (player instanceof GreenSoldier) {
                    ((GreenSoldier) player).backwardGreen();
                } else if (player instanceof BlackSoldier) {
                    ((BlackSoldier) player).backwardBlack();
                } else if (player instanceof Alien) {
                    ((Alien) player).backwardAlien();
                }
                break;
            default:
                player.stop();
        }
    }
}