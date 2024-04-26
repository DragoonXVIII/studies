-- ghci elozelo.hs i potem pozadana funkcja

{- podstawy
volumeOfSphere :: Double -> Double
volumeOfSphere
    radius = (4.0/3.0) * pi * (radius ^ 3)

volume1 :: Floating a => a -> a
volume1 r = a * pi * cube
    where
    a = 4 / 3
    cube = r ^ 3
-}

-- lab 1

{- 
f a b | a >= b = "wieksze lub rowne"
    | a == b = "rowne"
    | a < b = "mniejsze"
    | otherwise = "niewieksze"
-}

-- lab 2

{- 
delta a b c = b^2 - 4*a*c
pdelta a b c = if delta a b c < 0 then error "Delta ujemna" 
    else if delta a b c == 0 then
        [-b / (2*a)]
    else 
        [(-b - sqrt( delta a b c)) / (2*a),
        (-b + sqrt (delta a b c) ) / (2*a)]
-}

{-
delta a b c = b^2-4*a*c
pdelta a b c = if wyroznik < 0 then error "Delta ujemna" 
    else if wyroznik == 0 then
        [x0]
    else 
        [x1, x2]
    where
    wyroznik = delta a b c
    x0 = -b/(2*a)
    x1 = (-b-sqrt(wyroznik))/(2*a)
    x2 = (-b+sqrt(wyroznik))/(2*a)
-}

{-main :: IO ()
main = do
    --let radius = 5.0
    --putStrLn $ "Objętość kuli o promieniu " ++ show radius ++ " wynosi " ++ show(volumeOfSphere radius)
    --let result = pdelta 1 2 1
    --putStrLn $ "Miejsca zerowe: " ++ show result
-}

-- lab 3

{-
delta a b c = b^2-4*a*c
pdelta a b c = 
    let
        wyroznik = delta a b c
        x0 = -b/(2*a)
        x1 = (-b-sqrt(wyroznik))/(2*a)
        x2 = (-b+sqrt(wyroznik))/(2*a)
    in
        if wyroznik < 0 then error "Delta ujemna" 
        else if wyroznik == 0 then
            [x0]
        else 
            [x1, x2]
-}

-- sgn x = if(x>0)then 1 else if(x<0)then (-1) else 0
{-
sgn x
  | x>0 = 1
  | x<0 = -1
  | otherwise = 0
-}


{-
sgn x =
    case compare x 0 of
        GT -> 1
        LT -> -1
        EQ -> 0
-}
{-
sgn :: (Ord a1, Num a1, Num a2) => a1 -> a2
sgn x =
    case x>0 of
        True -> 1
        False -> case x<0 of
                True -> -1
                False -> 0
-}
sgn x =
    


