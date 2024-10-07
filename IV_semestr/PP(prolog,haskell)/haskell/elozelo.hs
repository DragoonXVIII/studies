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

-- lab 4

mul a b
    | b == 0 = 0                                        -- Jeśli drugi argument to 0, iloczyn wynosi 0
    | b < 0 = -mul a (-b)                               -- Jeśli drugi argument jest mniejszy od zera, zmień jego znak i rekurencyjnie wywołaj funkcję
    | otherwise = a + mul a (b-1)                       -- W przeciwnym razie kontynuuj standardowe dodawanie

czyUp a = a `elem` ['A'..'Z']

--Napisz funkcję obliczającą liczbę wszystkich nieparzystych kwadratów liczb od 1 do 10000.
pNK = length [x | x <- [1..10000], odd (x^2)]

--Napisz funkcję uDL usuwającą z napisu duże litery używając elem i list comprehensions
uDL str = [c | c <- str, not (czyUp c)]

uDL2 str = [c | c <- str, c `elem` ['a'..'z']]

--Napisz kod, który zwróci największą wartość poniżej 1000000 podzielną przez 3829 bez reszty. Zastosuj klasyczne rozwiązanie. Napisz drugą wersję funkcji wykorzystując leniwość Haskella. Która jest szybsza.
nWP =  maximum [ n | n <- [1..10000], n `mod` 3829 == 0]

mP limit  = last [x | x <- [1..limit], x `mod` 3829 == 0]

mPN = head [x | x <- [1000000, 7658..], x `mod` 3829 == 0]


mPNL = last [x | x <- [3829..], x `mod` 3829 == 0]

mPNLOUTPUT = [x | x <- [3829..], x `mod` 3829 == 0]

-- LABY NIEZROBILISMY

{-
silniaRec 0 = 1
silniaRec n = n * silniaRec (n - 1)

factorialGuards n
    | n == 0    = 1
    | otherwise = n * factorialGuards (n - 1)

factorialIf n = 
    if n == 0 
        then 1
    else 
        n * factorialIf (n - 1)

factorialCase n = case n of
    0 -> 1
    _ -> n * factorialCase (n - 1)





fibonacciRec 0 = 0
fibonacciRec 1 = 1
fibonacciRec n = fibonacciRec (n - 1) + fibonacciRec (n - 2)



fibonacciAcc n = fibHelper n 0 1

fibHelper 0 a _ = a
fibHelper n a b = fibHelper (n - 1) b (a + b)
-}
