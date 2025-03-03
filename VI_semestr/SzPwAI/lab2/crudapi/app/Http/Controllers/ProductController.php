<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Product;
use Illuminate\Support\Facades\Validator;


class ProductController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {       
        $products = Product::all(); 
        return $products; 
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request) 
    { 
        $validator = Validator::make($request->all(), [ 
            'name' => 'required|regex:/^[A-Za-z]{1,30}$/i', 
            'price' => 'required|numeric|min:0|max:999999' 
        ]);
        if ($validator->fails()) { 
            return response()->json(['error'=>$validator->errors()], 401);            
        }

        $product = new Product(); 
        $product->name = $request->input('name'); 
        $product->price = $request->input('price'); 
        $product->save(); 
        return $product; 
    }

    /**
     * Display the specified resource.
     */
    public function show(string $id)
    {
        $product  = Product::findOrFail($id); 
        return $product; 
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(string $id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, string $id) 
    {
        $product = Product::find($id);
        if ($product !== null) 
        {
            $validator = Validator::make($request->all(), [ 
                'name' => 'required|regex:/^[A-Za-z0-9 ]{1,30}$/i',/*'required|regex:/^[A-Za-z]{1,30}$/i', */
                'price' => 'required|numeric|min:0|max:999999' 
            ]);
            if ($validator->fails()) { 
                return response()->json(['error'=>$validator->errors()], 401);            
            }
            $product->update($request->all());
            return $product;
        }
        else 
        {
            return response()->json(['message' => "Nie istnieje w bazie obiekt o podanym id=$id"], 404);
        }
    }

    
    /**
     * Remove the specified resource from storage.
     */
    public function destroy(string $id) 
    { 
        $product = Product::find($id); 
        if ($product!==null)
        { 
            $product->delete(); 
            return $product; 
        } 
        else return "Nie istnieje w bazie obiekt o podanym id=$id"; 
    }
}
