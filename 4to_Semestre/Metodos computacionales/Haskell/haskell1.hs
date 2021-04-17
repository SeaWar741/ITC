{-
Fundamentos de Haskell

Resultado de un comité con un alto interés en lenguajes puramente funcionales con 
evaluación perezosa. Miranda era el más usado circa 1985, pero era software
propietario. 

El trabajo del comité comienza en 1987, pero Haskell 1.0 nace hasta 1990. 

Múltiples compiladores son creados y se ve la necesidad de estandarizar el lenguaje. 
Haskell 98 se gesta como resultado. 

La segunda revisión se da en 2010. 

El compilador más completo y robusto, por mucho, es GHC (Glasgow Haskell Compiler)

Trivia: ¿De dónde viene el nombre de Haskell?

Haskell es un lenguaje de programación:
1. Funcional puro
2. Estáticamente tipificado
3. Evaluación perezosamente

¿Qué significa que sea puro?
Sin efectos secundarios. Dados los mismos parámetros, las funciones regresan lo mismo. 

¿Puras vs Impuras?

1. Función de raíz cuadrada
2. Función time()
3. Función print()
4. Función concat
5. Función random()

¿Qué es estáticamente tipificado?
Toda expresión está tipificada en este lenguaje. Dichos tipos deben verificarse
y validarse durante la compilación. 

Finalmente, evaluación perezosa implica que un cómputo es relegado hasta que es 
necesario, lo cual aumenta considerablemente el rendimiento, a costo de la memoria, 
pues todo cómputo no resuelto es almacenado. 
-}



-- 0 Anatomía de una función

cuadrado :: Int -> Int     -- Encabezado con la declaración de tipos
cuadrado x = x * x         -- No hay paréntesis en los parámetros, no hay valor de retorno

-- Tampoco necesitamos paréntesis para invocar la función
-- doble 10



-- 1 Función recursiva y condicional if-else

factorial :: Int -> Int
factorial x = if x == 0 then 1 else x * factorial (x - 1)

-- El paréntesis tiene la misma función que en una expresión aritmética: priorizar la evaluación de una expresión

fibonacci :: Int -> Int
fibonacci x = if x == 0 then 
                1 
              else 
                if x == 1 then 
                  1 
                else 
                  fibonacci (x - 2) + fibonacci (x - 1)

-- Podemos anidar condicionales if-else, como en cualquier otro lenguaje. No hay elsif, elif o equivalente.



-- 2 Listas

reversa :: [Int] -> [Int]
reversa xs = if (null xs) then [] else (reversa (tail xs)) ++ [head xs]

-- Las listas en Haskell NO llevan paréntesis. Usan corchetes y los elementos
-- van separados por ,

-- Una lista sólo puede contener elementos de un mismo tipo, a diferencia de Racket.

-- Tenemos las funciones head y tail para obtener el primero y el resto de la lista
-- similares a car y cdr

-- El equivalente a cons en Haskell es el operador :
-- 1:2:3:4:[] es igual a [1,2,3,4]


-- Más ejemplos de listas:

sumatoria1_i :: Double -> Double
sumatoria1_i n = if n == 0 then 0 else (1 / n) + sumatoria1_i (n - 1)

teje :: [Int] -> [Int] -> [Int]
teje xs ys = if null xs then 
               ys 
             else 
               if null ys then
                 xs
               else
                (head xs):(head ys):(teje (tail xs) (tail ys))


-- 3 Polimorfismo paramétrico y coincidencia de patrones (pattern-matching)

teje' :: [Int] -> [Int] -> [Int]
teje' [] ys = ys
teje' xs [] = xs
teje' (x:xs) (y:ys) = x:y:(teje' xs ys) 

-- Haskell nos permite tener multiples declaraciones de una función, siempre
-- que la estructura o valores de los parámetros sean diferentes. 
-- Haskell se encarga de invocar la versión correcta de la función.
-- De no encontrar una versión que satisfaga los patrones enumerados
-- lanzará un error de exhaustividad en la búsqueda de una coincidencia

-- El operador _ se le conoce comunmente como "don't care" y sirve para
-- marcar un valor que no me interesa en el patrón. 

-- Haskell también permite desestructuración de parámetros, como el caso de (x:xs)
-- Aquí no solamente coincide cuando envías una lista, sino que ya la desestructura
-- según el patrón que hayas declarado, para tener ya las piezas disponibles a procesar

-- Ejercicios

-- ¿Cómo reescribiríamos la función de reversa y fibonacci con polimorfismo paramétrico y 
-- coincidencia de patrones?

reversa' :: [a] -> [a]
reversa' [] = []
reversa' (x:xs) = (reversa' xs) ++ [x]

fibo :: Int -> Int
fibo 0 = 0
fibo 1 = 1
fibo x = fibo (x - 1) + fibo (x - 2)

-- 4 Guardias

-- Haskell nos permite un nivel adicional de filtrado de parámetros, donde podemos
-- combinarlos en expresiones para tomar decisiones a raíz del resultado

filtraImpares :: [Int] -> [Int]
filtraImpares [] = []
filtraImpares (x:xs)
              | mod x 2 == 0 = x:(filtraImpares xs)
              | otherwise = filtraImpares xs

tomaMientras :: [Int] -> (Int -> Bool) -> [Int]
tomaMientras [] _ = []
tomaMientras (x:xs) pred
                | pred x = x:(tomaMientras xs pred)
                | otherwise = [] 

-- Las lambdas en Haskell siguen la siguiente sintaxis: \a b c d... -> a + b * c...  
-- Veremos ejemplos ejemplos más adelanta con las funciones de alto orden primitivas

-- 5 Strings

-- Las cadenas en Haskell son listas de caracteres. Se usan los mismos operadores y patrones
-- de las listas para navegarlas y procesarlas

-- ['a', 's', 'd', 'f'] == "asdf"

tamano :: String -> Int
tamano [] = 0
tamano (_:xs) = 1 + tamano xs



-- 6 Tuplas

-- En Racket podíamos implementar registros y otras estructuras de datos heterogéneas usando sólo listas
-- En Haskell tenemos las tuplas para agrupar datos de diferentes tipos. Las tuplicas también son 
-- fuertemente tipificadas y son inferidas por el compilador cuando se crean literalmente. 

-- ("Guillermo", 32, 50.0)

nomina :: (String, Int, Double) -> Double
nomina (nombre, edad, quincena) = quincena

edadDe (_, x, _) = x

-- Podemos emular una base de datos, o los resultados de una consulta a un RDBMS con una lista de tuplas

-- Hay una sintaxis alterna que ya genera los getters para un registro de datos

data Empleado = Catedra {nombre :: String, edad :: Int, quincena :: Double}

-- 7 Case

-- Como se mencionó anteriormente, Haskell no tienen elif, elseif o un equivalente. Sin embargo, 
-- tiene un condicional similar al cond en Racket: case

chabelo :: Bool -> Bool
chabelo b = case b of 
                True -> False
                False -> True



-- 8 Tipos definidos por el usuario

-- Haskell nos permite definir tipos de datos algebráicos, combinándolos con tipos primitivos 
-- o con otros datos definidos por el usuario

data Pokemon = Squirtle | Ivysaur | Charizard deriving (Eq, Show)
data SmashCharacter = Mario | Samus | Bowser | MrGameAndWatch | Lucas | DuckHunt | PokemonTrainer Pokemon deriving (Eq, Show)

bestCharacter :: SmashCharacter -> Bool
bestCharacter smc = case smc of
                        Lucas -> True
                        PokemonTrainer pokemon -> case pokemon of 
                                                    Ivysaur -> True
                                                    _ -> False
                        _ -> False


-- 9 Bindings locales con let y where

-- Como en el caso de Racket, y con el fin de evitar recursión inecesaria o hacer más claras nuestras
-- funciones, Haskell permite hacer bindings locales a través de let y where

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = lesser ++ [x] ++ greater
                   where 
                    lesser = quicksort [e | e <- xs, e <= x]
                    greater = quicksort [e | e <- xs, e > x]

quicksort' :: [Int] -> [Int]
quicksort' [] = []
quicksort' (x:xs) = let lesser = quicksort' [e | e <- xs, e <= x]
                        greater = quicksort' [e | e <- xs, e > x]
                    in
                        lesser ++ [x] ++ greater



-- 10 Comprensión de listas

-- Como en el ejemplo de quicksort anterior, podemos armar listas a través de una sintaxis
-- sucinta, pero expresiva, en vez de escribir una función recursiva o usar un primitivo de alto 
-- orden con una lambda. Esta funcionalidad se puede encontrar en Python y otros
-- lenguajes "inspirados" (piratas)

filtraImpares' :: [Int] -> [Int]
filtraImpares' xs = [x | x <- xs, (mod x 2) == 0]


combina :: [Int] -> [Int] -> [(Int, Int)]
combina xs ys = [(x,y)| x<-xs, y<-ys]

-- NOTA: Cuando se usan dos listas simultáneas en el generador, la semántica es producir un elemento por cada
-- combinación de la lista A con la lista B, esto es, no las recorre linealmente, sino que genera 
-- conjunto producto.


-- 11 Enumeraciones y rangos
-- Anuado al poder y conveniencia de la comprensión de listas, Haskell tiene una notación especial para 
-- generar secuencias de números para las series más comunes, sin necesidad de usar comprensión de listas
-- funciones anónimas con funciones de orden mayor o funciones recursivas.

-- La conveniencia sigue y sigue y sigue y sigue... ad infinitum. I <3 Haskell

-- [1..10]
-- [100..]
-- [100..1]
-- [0,-1..]
-- [1,3..100]
-- ['a'..'z']
-- [1.0,1.5..10]


-- 12 Clases de tipos

-- Hasta ahora hemos hecho funciones para enteros y listas de enteros. ¿Qué pasa si queremos ahora que funcionen
-- con Dobles u otros tipos de datos, incluso aquellos que hayamos creado nosotros. 

-- Las clases de tipos nos permiten hacer funciones para grupos de tipos, sin necesidad de repetir la 
-- definición. Esto gracias a la capacidad de declarar clases y derivar de las mismas en los tipos que hayamos
-- creado. 


-- Esta función aplica para cualquier tipo que derive de Eq, una clase que sólo impone una restricción:
-- que el tipo pueda compararse con un operador relacional. Para eso es el "deriving" en nuestra declaración de tipos.
existe :: (Eq a) => a -> [a] -> Bool
existe _ [] = False
existe a (x:xs) = (x == a) || (existe a xs)


-- existe Lucas [DuckHunt, Mario, Samus]
