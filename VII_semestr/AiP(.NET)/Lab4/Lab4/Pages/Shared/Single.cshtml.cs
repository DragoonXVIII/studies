using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Lab4.Pages.Shared
{
    public class SingleModel : PageModel
    {
        [BindProperty(SupportsGet = true)]
        public string Image { get; set; }
        private string imagesDir;

        public SingleModel(IWebHostEnvironment environment)
        {
            imagesDir = Path.Combine(environment.WebRootPath, "images");
        }
        public IActionResult OnGet()
        {
            if (System.IO.File.Exists(Path.Combine(imagesDir, Image)))
            {
                return Page();
            }
            else
            {
                return NotFound();
            }
        } 


    }
}
