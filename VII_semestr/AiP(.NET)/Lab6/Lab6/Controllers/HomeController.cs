using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Lab6.Data;
using Lab6.Models;

namespace Lab6.Controllers
{
    public class HomeController : Controller
    {
        private readonly MoviesDbContext _context;

        public HomeController(MoviesDbContext context)
        {
            _context = context;
        }

        // GET: Home
        public async Task<IActionResult> Index()
        {
            return _context.Movies != null
                // zad 6.6
                ? View(await _context.Movies.Include(x => x.Genre).ToListAsync())
                : Problem("Entity set 'MoviesDbContext.Movies'  is null.");
        }

        // GET: Home/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.Movies == null)
            {
                return NotFound();
            }

            var movie = await _context.Movies.FirstOrDefaultAsync(m => m.Id == id);
            if (movie == null)
            {
                return NotFound();
            }

            return View(movie);
        }

        // GET: Home/Create
        public IActionResult Create()
        {
            //6.8
            var m = new MovieDto
            {
                AllGenres = _context.Genres.Select(x => x.Name).ToList()
            };
            return View(m);
        }

        // POST: Home/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create(
            [Bind("Id,Title,Description,Rating,TrailerLink,Genre")] MovieDto movie
        )
        {
            if (ModelState.IsValid)
            {
                var genre = _context.Genres.FirstOrDefault(x => x.Name == movie.Genre);
                if (genre == null)
                {
                    genre = new Genre { Id = 0, Name = movie.Genre };
                }
                Movie m = new Movie
                {
                    Id = 0,
                    Title = movie.Title,
                    Description = movie.Description,
                    Rating = movie.Rating,
                    TrailerLink = movie.TrailerLink,
                    Genre = genre
                };
                _context.Add(m);
                await _context.SaveChangesAsync();
            }
            return View(movie);
        }

        // GET: Home/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null || _context.Movies == null)
            {
                return NotFound();
            }

            var movie = await _context.Movies
                .Include(x => x.Genre)
                .FirstOrDefaultAsync(x => x.Id == id);

            if (movie == null)
            {
                return NotFound();
            }

            var dto = new MovieDto
            {
                Id = movie.Id,
                Title = movie.Title,
                Description = movie.Description,
                Rating = movie.Rating,
                TrailerLink = movie.TrailerLink,
                Genre = movie.Genre?.Name ?? string.Empty
            };

            return View(dto);
        }

        // POST: Home/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, MovieDto dto)
        {
            if (id != dto.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                var movie = await _context.Movies
                    .Include(x => x.Genre)
                    .FirstOrDefaultAsync(x => x.Id == id);

                if (movie == null)
                {
                    return NotFound();
                }

                movie.Title = dto.Title;
                movie.Description = dto.Description;
                movie.Rating = dto.Rating;
                movie.TrailerLink = dto.TrailerLink;

                // Obs³uga gatunku
                var genre = await _context.Genres.FirstOrDefaultAsync(g => g.Name == dto.Genre);
                if (genre == null)
                {
                    genre = new Genre { Name = dto.Genre };
                    _context.Genres.Add(genre);
                }

                movie.Genre = genre;

                try
                {
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!_context.Movies.Any(e => e.Id == id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }

                return RedirectToAction(nameof(Index));
            }

            return View(dto);
        }


        // GET: Home/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.Movies == null)
            {
                return NotFound();
            }

            var movie = await _context.Movies.FirstOrDefaultAsync(m => m.Id == id);
            if (movie == null)
            {
                return NotFound();
            }

            return View(movie);
        }

        // POST: Home/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            if (_context.Movies == null)
            {
                return Problem("Entity set 'MoviesDbContext.Movies'  is null.");
            }
            var movie = await _context.Movies.FindAsync(id);
            if (movie != null)
            {
                _context.Movies.Remove(movie);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool MovieExists(int id)
        {
            return (_context.Movies?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
