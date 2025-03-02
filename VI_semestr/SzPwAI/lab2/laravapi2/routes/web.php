<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProductController;
use App\Http\Controllers\AuthController;

Route::get('/', function () {
    return view('welcome');
});

/*
//basic w/o auth
Route::resource('products', ProductController::class);
Route::get('/products/search/{name}', [ProductController::class, 'search']);
*/

//Route::resource('products', ProductController::class); 

//Trasy publiczne 
Route::get('/products', [ProductController::class, 'index']); 
Route::get('/products/{id}', [ProductController::class, 'show']); 
Route::get('/products/search/{name}', [ProductController::class, 'search']); 
Route::post('/login', [AuthController::class, 'login']);
Route::post('/register', [AuthController::class, 'register']);

//Trasy chronione 
Route::group(['middleware' => ['auth:sanctum']], function() { 
Route::post('/products', [ProductController::class, 'store']); 
Route::put('/products/{id}', [ProductController::class, 'update']); 
Route::delete('/products/{id}', [ProductController::class, 'destroy']); 
Route::post('/logout', [AuthController::class, 'logout']);
});

