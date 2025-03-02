<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

use App\Http\Controllers\ProductController; 

Route::post('/products', [ProductController::class, 'store']);
Route::get('/products', [ProductController::class, 'index']); 
Route::get('/products/{id}', [ProductController::class, 'show']); 
Route::put('products/{id}', [ProductController::class, 'update']); 
Route::delete('/products/{id}',[ProductController::class, 'destroy']); 
