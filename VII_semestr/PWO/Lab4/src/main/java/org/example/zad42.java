package org.example;

public class zad42 {
}

public void saveProduct(String productName, double price){
    productReposiroty.save(productName);
    priceRepository.save(price);
}



@PostMapping("/api/document")

public boolean saveDocument(@RequestBody Document doc){
    doc.setCreationDate(new Date());
    doc.setCreator(sessionGetUserId());
    return documentRepository.saveDocument(doc);
}

//class documentRepository
public User saveDocument(Document doc) {
    doc.setCreationDate(new Date());
    doc.setCreator(sessionRepository.getCurrentUser().getId());
    return documentRepository.save(doc);
}





public void updateProduct(long idProduct, String productName){
    List<Product> products = productRepository.findAll();
    product = productReposiroty.find(idProduct);
    product.setName(productName);
    productReposiroty.save(idProduct, product);
    return products;
}





???
public void modifyAllParametersOfSummerTripPlan(TripPlan trip,
List<Member> members, Accomodation[] sleepPlaces, List<Ticket>
        tickets, Date startTripDate, Date[] tripMiddleDates, Date
        endTripDate, List<Item> itemsToTake, Contact[] contacts,
Weather weatherInformations, List<MedicalInformation>
        medInfos){
…
    tripRepository.save(trip);
    eMailService.send(trip, members, tickets, itemsToTake,
            medInfos, weatherInformations);
}

???
public class TripContext {
    private TripPlan trip;
    private List<Member> members;
    private Accomodation[] sleepPlaces;
    private List<Ticket> tickets;
    private Date startTripDate;
    private Date[] tripMiddleDates;
    private Date endTripDate;
    private List<Item> itemsToTake;
    private Contact[] contacts;
    private Weather weatherInformations;
    private List<MedicalInformation> medInfos;

    // gettery i settery
}


public class TripService {

    private final TripRepository tripRepository;
    private final EmailService emailService;

    public TripService(TripRepository tripRepository, EmailService emailService) {...}

    public void modifyAllParametersOfSummerTripPlan(TripContext context) {
        tripRepository.save(context.getTrip());
        emailService.send(
                context.getTrip(),
                context.getMembers(),
                context.getTickets(),
                context.getItemsToTake(),
                context.getMedInfos(),
                context.getWeatherInformations()
        );
    }
}







public int saveGameResult(Player player, Result result){
    if(player.getCountry()==”Poland” &&
    result.getScore()>1000){
        player.setWinCount(player.getWinCount()+1);
    }
    return gameRepository.save(player, result);
}


public boolean checkUser(long userId, Token token){
    User user = userRepository.findById(userId);
    boolean isVerifiedUser =
            userRepository.verifyUser(user,token);
    return isVerifiedUser;
}
public User updateUser(long userId, Token token, String
        userName, String userTelNumber){
    if(checkUser()){
        user.setTel(userTelNumber);
        return userRepository.save(user);
    }else
        return null;
}



List<Privilege> privileges =
        getCountry(idCountry).getCompany(idCompany).getDepartment(idDe
                partment).getEmploee(idDepartmentEmployee).gerPermissions();


List<Privilege> privileges = Collections.emptyList();

Country country = getCountry(idCountry);
if (country == null) return privileges;

Company company = country.getCompany(idCompany);
if (company == null) return privileges;

Department department = company.getDepartment(idDepartment);
if (department == null) return privileges;

Employee employee = department.getEmployee(idDepartmentEmployee);
if (employee == null) return privileges;

privileges = employee.getPermissions();
return privileges;
