<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProductController;
use Laravel\Sanctum\Http\Middleware\EnsureFrontendRequestsAreStateful;


Route::get('/', function () {
    return view('welcome');
});

/*
Route::get('/products', [ProductController::class, 'index']); 
Route::post('/products', [ProductController::class,'store']);
Route::get('/products/{id}', [ProductController::class, 'show']); 
*/
Route::resource('products', ProductController::class);
Route::get('/products/search/{name}', [ProductController::class, 'search']);

/*
Route::middleware([
    EnsureFrontendRequestsAreStateful::class,
    'throttle:web',
    \Illuminate\Routing\Middleware\SubstituteBindings::class,
])->group(function () {
    // Twoje chronione trasy
});*/

use App\Http\Controllers\AuthController;

/*
/ Trasy publiczne

Route::post('/register', [AuthController::class, 'register']);
Route::post('/login', [AuthController::class, 'login']);
*/
/*
// Trasy chronione
Route::middleware('auth:sanctum')->group(function () {
    Route::post('/logout', [AuthController::class, 'logout']);
    // Inne chronione trasy
});*/