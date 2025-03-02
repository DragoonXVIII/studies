<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;
use Illuminate\Support\Facades\Hash;

class AuthController extends Controller
{
    public function logout(Request $request){ 
        auth()->user()->tokens()->delete(); 
 
        return [ 
            'message' => 'Logged out' 
        ]; 
    } 

    public function register(Request $request) {
        $fields = $request->validate([
            'name' => 'required|string',
            'email' => 'required|string|unique:users,email',
            'password' => 'required|string|confirmed'
        ]);
    
        $user = User::create([
            'name' => $fields['name'],
            'email' => $fields['email'],
            'password' => bcrypt($fields['password'])
        ]);
    
        $token = $user->createToken('myapptoketn')->plainTextToken;
    
        $response = [
            'user' => $user,
            'token' => $token
        ];
    
        return response($response, 201);
    }

    public function login(Request $request) { 
        $fields = $request->validate([ 
            'email' => 'required|string', 
            'password' => 'required|string' 
        ]); 
 
        $user = User::where('email', $fields['email'])->first();   // sprawdzenie maila 
 
        if(!$user || !Hash::check($fields['password'], $user->password)){ // sprawdzenie hasła 
            return response([ 
                'message' => 'Bad creds' 
            ], 401); 
        } 
 
        $token = $user->createToken('myapptoketn')->plainTextToken; 
 
        $response = [ 
            'user' => $user, 
            'token' => $token 
        ]; 
 
        return response($response, 201); 
    }
}
