using ImageMagick;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Lab4.Pages
{
    public class UploadModel : PageModel
    {
        [BindProperty]
        public IFormFile Upload { get; set; }

        private string imagesDir;

        //add to constructor
        // imagesDir = Path.Combine(environment.WebRootPath, "images");
        public UploadModel(IWebHostEnvironment environment)
        {
            imagesDir = Path.Combine(environment.WebRootPath, "images");
        }

        public void OnGet()
        {
        }

        public IActionResult OnPost()
        {
            if (Upload != null)
            {
                if (Upload.Length > 1 * 1024 * 1024)
                {
                    ModelState.AddModelError("Upload", "Plik jest za du¿y (max. 1 MB).");
                    return Page();
                }

                string extension = ".jpg";
                switch (Upload.ContentType)
                {
                    case "image/png":
                        extension = ".png";
                        break;
                    case "image/gif":
                        extension = ".gif";
                        break;
                }
                var fileName = Path.GetFileNameWithoutExtension(Path.GetRandomFileName()) + extension;

                using (var fs = System.IO.File.OpenWrite(Path.Combine(imagesDir, fileName)))
                {
                    Upload.CopyTo(fs);
                }

                var imagePath = Path.Combine(imagesDir, fileName);
                using var image = new MagickImage(imagePath);
                using var watermark = new MagickImage("watermark.png");
                watermark.Evaluate(Channels.Alpha, EvaluateOperator.Divide, 4);
                image.Composite(watermark, Gravity.Southeast, CompositeOperator.Over);
                image.Write(imagePath);
            }
            return RedirectToPage("Index");
        }
    }
}
