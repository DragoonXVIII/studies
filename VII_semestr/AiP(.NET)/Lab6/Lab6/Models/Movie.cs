using System.ComponentModel.DataAnnotations;

namespace Lab6.Models
{
    //6.1, 6.2
    public class Movie
    {
        [Key]
        public int Id { get; set; }

        [Required(ErrorMessage = "Tytu³ jest wymagany.")]
        [MaxLength(50, ErrorMessage = "Tytu³ mo¿e mieæ maksymalnie 50 znaków.")]
        public string Title { get; set; } = string.Empty;

        public Genre Genre { get; set; }

        [Required(ErrorMessage = "Opis filmu jest wymagany.")]
        public string Description { get; set; } = string.Empty;

        [UIHint("Stars")]
        [Range(1, 5, ErrorMessage = "Ocena filmu musi byæ liczb¹ pomiêdzy 1 a 5.")]
        public int Rating { get; set; }

        public string? TrailerLink { get; set; }


    }
}
