using Lab3.Models;
using Microsoft.VisualStudio.Web.CodeGenerators.Mvc.Templates.BlazorIdentity.Pages.Manage;
using System.Xml.Linq;

public class PhoneBookService
{
    private List<Contact> contacts;

    public PhoneBookService()
    {
        contacts = new List<Contact>()
        {
            new Contact
            {
            Id = 1,
            Name = "Jan",
            Surname = "Kowalski",
            City = "Lublin",
            Email = "jan@kowalski.com",
            PhoneNumber = "123456789"
            },
            new Contact
            {
            Id = 2,
            Name = "Adam",
            Surname = "Paździoch",
            City = "Zamość",
            Email = "adam@wp.com",
            PhoneNumber = "987654321"
            },
            new Contact
            {
            Id = 3,
            Name = "Mariusz",
            Surname = "Nowak",
            City = "Warszawa",
            Email = "mariusz.nowak@gmail.com",
            PhoneNumber = "837264917"
            },
            new Contact
            {
            Id = 4,
            Name = "Jarosław",
            Surname = "Kamiński",
            City = "Zamość",
            Email = "kaminskij@test.pl",
            PhoneNumber = "83102849"
            },
            new Contact
            {
            Id = 5,
            Name = "James",
            Surname = "Kaczmarek",
            City = "Lublin",
            Email = "kaczmarek.james@ir.com",
            PhoneNumber = "027384716"
            },
            new Contact
            {
            Id = 6,
            Name = "Rafał",
            Surname = "Nowicki",
            City = "Kraków",
            Email = "rafalnowicki@wp.com",
            PhoneNumber = "627193482"
            },
            new Contact
            {
            Id = 7,
            Name = "Kamil",
            Surname = "Malinowski",
            City = "Poznań",
            Email = "kamil.m@wp.com",
            PhoneNumber = "038462817"
            }
            };
    }
    public IEnumerable<Contact> GetContacts()
    {
        return contacts;
    }
    public void Add(Contact contact)
    {
        contact.Id = contacts.Max(x => x.Id) + 1;
        contacts.Add(contact);
    }

    public void Remove(int Id)
    {
        var contact = contacts.FirstOrDefault(x => x.Id == Id);
        if (contact == null)
            throw new ArgumentException($"Contact with Id {Id} not found.");

        contacts.Remove(contact);
    }

}