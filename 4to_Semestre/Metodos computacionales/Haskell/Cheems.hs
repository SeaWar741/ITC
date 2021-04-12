{-
Trivia de pureza
1 raiz cuadrada
2 time()
3 print()
4 concat, String ->string
-}

cuadrado :: Num a =>a->a
cuadrado x = x * x

factorial :: Int -> Int
factorial x = if x == 0 then 1 else x * factorial(x-1)


fibonacci :: Int-> Int
fibonacci x = 
    if x == 0 
        then 1
            else
                if x == 1 then
                    1
                else fibonacci(x-2) + fibonacci(x-1)


-- Polimorfismo parametrico (ir de lo mas especifico a mas general)

fibo :: Int -> Int
fibo 0 = 0
fibo 1 = 1
fibo x = fibo (x-1) + fibo(x-2)



reversa :: [Int] -> [Int]
reversa xs = if(null xs) then [] else (reversa(tail xs)) ++ [head xs]
--car cdr ++ null

reversa' :: [a] -> [a]
reversa' [] = []
--reversa' xs = (reversa' (tail xs) ++ [head xs])
reversa' (x:xs) = (reversa' xs)++[x]


--teje :: [Int] -> [Int] ->[Int]
teje:: [a] -> [a] -> [a]
teje [] ys = ys
teje xs [] = xs
teje (x:xs) (y:ys) = x : y : teje xs ys
--teje xs ys = (head xs):(head ys) :teje(tail xs)(tail ys)

--[a b c][1 2]


quitaImpares :: [Int] -> [Int]
quitaImpares [] = []
quitaImpares (x: xs)
    |even x = x:quitaImpares xs
    |otherwise = quitaImpares xs


quicksort [] = []
quicksort (x:xs) = lesser ++ [x] ++ greater
                where
                    lesser = quicksort[e | e <-xs, e <=x]
                    greater = quicksort [e | e<- xs, e > x]
                    
