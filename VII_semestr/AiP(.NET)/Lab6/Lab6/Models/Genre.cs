using System.ComponentModel.DataAnnotations;

namespace Lab6.Models
{
    public class Genre
    {
        [Key]
        public int Id { get; set; }
        public string Name { get; set; }
    }

}
