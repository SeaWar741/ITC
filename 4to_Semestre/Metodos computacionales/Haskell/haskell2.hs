{-
0 Operadores y primitivos de orden mayor en Haskell

 En Haskell podemos definir nuestros propios operadores binarios

-}

b |*^*| ac = b^2 - 4*ac

{-

También podemos usar un operador como función y pasarlo como parámetros
a funciones de orden mayor. Sólo necesitamos usar paréntesis

Ejemplo:

-}

aplicaEnPares f xs = [r | (a,b) <- xs, let r = f a b]

aplicaEnPares2 f xs = map (\(x,y) -> f x y) xs

-- También podemos usar una función como operador usando ``

unModulo = 5 `mod` 2

{-
map f xs

Genera una lista de los resultados de aplicar una función a cada elemento de una lista
enviada como parámetro

map (+1) [1,2,3,4]


filter f xs

Genera una lista con sólo aquellos elementos dan positivo al predicado enviado como parámetro
-}

data SmashCharacter = Joker | Ness | Lucina | Pichu | Olimar | Banjo 
    deriving (Show, Eq)

data TierList = Top | High | Mid | Low | Garbage | LittleMac
    deriving (Show, Eq)

tier sc
    | sc `elem` [Ness, Olimar] = Top
    | sc `elem` [Lucina, Pichu] = High
    | sc `elem` [Banjo] = Low
    | otherwise = LittleMac

valeLaPena sc = case (tier sc) of
                    Top -> True                
                    High -> True
                    _ -> False            

valenLaPena = filter valeLaPena [Joker, Lucina, Ness, Pichu, Olimar, Banjo]


{-
foldl, foldr

Función que va acumulando el resultado de aplicar una función enviada como parámetro
a cada elemento de la lista, uno a la vez. 

Puede comenzar a aplicarlos de izquierda a derecha, o viceversa. 

Ejemplos:
-}

lasumatoria xs = foldl (+) 0 xs

desglosaSuma suma numero = "(" ++ suma ++ "+" ++ (show numero) ++ ")"
sumatoriaHasta6 = foldl desglosaSuma "0" [1,2,3,4,5,6]

desglosaSuma' numero suma = "(" ++ (show numero) ++ "+" ++ suma ++ ")"
sumatoriaDesde6 = foldr desglosaSuma' "0" [1,2,3,4,5,6]

-- En operaciones conmutativas no importa, pero en otros casos, como la resta
-- Usar la versión que corresponda al orden de aplicación deseado



{-
1 Evaluación perezosa

El orden de evaluación en Haskell es particular, no se evalúa o interpreta
como los demás...

Consideremos el siguiente ejemplo en Python:

unaFuncionDeEjemplo(suma(1, 3), resta(1, 3))

El intérprete evalúa los parámetros de la función print interpolados,
inyecta el resultado, y luego completa la llamada a la función. Es aplicativa. 

En el caso de Haskell, si tuviéramos una función similar:

unaFuncionDeEjemplo (suma 1 3 ) (resta 1 3)

La evaluación de la suma o de la resta no están garantizadas. Todo depende
del trabajo interno que haga "unaFunciónDeEjemplo". Esto es, sólo serán
evaluadas si el valor del parámetro es necesario para un cómputo interno. 

A esta estrategia de evaluación se le conoce como evaluación perezosa. 

Ejemplo:
-}

answerToLife :: Fractional a => a -> a -> Int
answerToLife _ _ = 42

{-
Una aplicación común, pero extraña para los nuevos programadores en Haskell,
son las listas infinitas. 
-}

enterosDesde n = n : (enterosDesde (n + 1))

li = enterosDesde 1

-- ¿Qué pasa si le pedimos a Haskell que evalúe las siguientes funciones?
-- null li
-- head li
-- take 100 li
-- length li
-- li

-- La evaluación perezosa también se va anidando, de llamada a llamada, hasta
-- hasta que el valor es extrictamente necesario. Haskell es bastante hábil
-- para detectar en qué momento desenvolver una expresión.

esPrimo n = if n <= 1 then
                False
            else
                null [x | x <- [2..n-1], n `mod` x == 0]

soloPrimos xs = filter esPrimo xs

primosInfinitos = soloPrimos (enterosDesde 1)



{-
2 Tipos en Haskell

El sistema de tipos de Haskell es diferente, pero más capaz que en los lenguajes convencionales, como Java o C#
Con frecuencia, las últimas innovaciones en teoría de tipos llegan a Haskell y otros lenguajes académicos, 
como OCaml, antes de alcanzar la masa crítica y popularidad necesaria para verlas en los Top 5 
de StackOverlfow

-----
Repaso de sistemas de tipos estáticos y dinámicos

Tipos estáticos
- Detectar errores en tiempo de compilación
- Tedioso y laborioso para la construcción de expresiones complejas
- Puede requerir múltiples definiciones de una función o precedimiento por la restricción de tipos

Tipos dinámicos
- Más errores en tiempo de ejecución
- Más ágil en la creación de expresiones
- Una función puede aplicarse a múltiples tipos sin reescribir

En los últimos años se ha popularizado la práctica de tipos graduales (Gradual Typing)
donde los tipos se van añadiendo paulatinamente y sólo cuando son necesarios.
Tal es el caso de mypy en Python y Sorbet en Ruby. En el caso de Javascript, existen
diversas librerías y transpiladores que ofrecen funcionalidad similar, como Flow o 
Typescript, respectivamente. 

Haskell tiene una implementación potente de inferencia de tipos. Rara vez se necesita
especificar los tipos. Por lo general, los tipos son especificados para propósitos de
documentación. 
-}



{-
3 Explorando tipos con GHCi

:t EXPRESION

:t length
:t lines
:t head
:t tail

¿Por qué con funciones de múltiples argumentos aparece un listado como a -> b -> c -> ...?

R: Aplicación parcial. Haskell es más fiel al cálculo lambda que Racket. Por tanto, 
una función de múltiples argumentos es en realidad una función que se aplica a un argumento y 
regresa otra función con dicho argumento aplicado y lista para consumir el siguiente argumento
y así sucesivamente

a -> b -> c -> d

a -> (b -> (c -> d)) argA argB argC argD

Más adelante veremos los fundamentos teóricos de la currificación y la aplicación parcial
-}



{-
4 Anotaciones de tipos

El compilador es bastante inteligente en determinar el tipo correcto de un literal o expresión. 
Sin embargo, pueden existir situaciones en donde explícitamente queremos que un literal sea
interpretado con un tipo específico. 

Por ejemplo

a = 5 + 10.0

No marca error, pues el compilador interpreta los dos literales como Double y procede a
la aplicación de la función +

a = (5 :: Int) + (10.0 :: Double)

Marca un error, pues no existe una sobrecarga de + que tome un Int y un Double.

Por lo general, el compilador es más inteligente que el programador y es raro hacer
una anotación de tipos. 

Se considera un code smell en Haskell. 
-}

-- a = 5 + 10.0
-- a = (5 :: Int) + (10.0 :: Double)



{-
5 Inferencia de tipos en acción

En la clase pasada usamos tipos explícitos en nuestras definiciones de función para aprender
los tipos primitivos de Haskell y acostumbrarnos a documentar nuestro código con ellos. 

No obstante, estas anotaciones no son necesarias la mayor parte del tiempo. Haskell es bastante
hábil en detectar el mejor tipo, o clase de tipos, para una definición en cuestión. Esto es,
el tipo más general posible que satisfaga las restricciones de las operaciones que se hagan
dentro de la función.

A diferencia de una anotación en un literal, los tipos explícitos en una declaración de 
función no son un Code Smell, pues favorecen la documentación y entendimiento entre
múltiples programadores trabajando sobre un mismo proyecto. 

Ejemplo

-}

cuadrado_no_doble_me_equivoque_y_que x = x * x
-- :t cuadrado_no_doble_me_equivoque_y_que 

{-
Debido a que no existen efectos secundarios (funciones puras) los tipos 
explícitos nos dan una buena idea de qué hace una función sin necesidad de ver su 
implementación

Por ejemplo

Si tuvieramos:

que_hago :: String -> Int

Muy probablemente obtiene el tamaño de la cadena. 

Sitios como Hoogle funcionan así https://hoogle.haskell.org/

Muchas veces no sabemos cómo se llama una función, pero sí tenemos una idea
completa de qué tipos manipula y regresa. Podemos usarlos para buscar
documentación.
-}



{-
6 Funciones polimórficas

Preguntémosle a Haskell qué tipos tiene la siguiente función

:t length

La respuesta es: 

a -> [Int]

¿Qué es la a?

Respuesta: Es una variable de tipo. 

Haskell determina y genera una versión de la función durante la compilación para el tipo en cuestión. 
Por tanto, no hay una definición en el runtime de todos los tipos que podrían usar la función. Esto
alentaría significativamente el tiempo de compilación sin generar beneficio alguno. 

Convenciones: 

Las variables de tipo siempre comienzan con minúsculas
Los tipos concretos van capitalizados
-}



{-
7 Restricciones de clases de tipo

En Haskell no sólo es posible generalizar el uso de una función a 
cualquier tipo usando variables de tipo. 

También nos proporciona un nivel mayor de granularidad para ir
restringiendo los tipos que podrían hacer uso de ella y así evitar 
inconsistencias en tiempo de ejecución. 

En ocasiones, las restricciones de tipos son obligatorias, 
pues las expresiones dentro del cuerpo de una función requieren que el 
tipo parametrizado implemente una interfaz de tipo. 

¿Recuerdan las plantillas (templates) en C++?
Aunque son una versión simplificada de lo que puede hacer Haskell, su 
objetivo es el mismo: generalizar algoritmos, pero con precauciones

Por ejemplo

sumaMal :: [a] -> a
sumaMal [] = 0
sumaMal (x:xs) = x + sumaMal xs

¿En verdad se podría usar cualquier tipo en sustitución de "a"?
¿Cómo podemos mantener la flexibilidad de suma sin comprometer un cómputo correcto?

En este caso le podemos preguntar al compilador qué haría:

suma [] = 0
suma (x : xs) = x + sum xs

:t suma

Num es una clase de tipos. Su presencia en el tipo de una función implica que
todo tipo que quiera hacer uso de la función debe implementar y respetar la 
definición de esta clase de tipos

Trivia: ¿Qué tipo tienen las literales numéricas si no anotamos explícitamente?

:t 3
:t 3/2
-}



{-
8 Sinónimos de tipos

Podemos tener alias de un tipo a otro para cuestiones de legibilidad del código.
La sintaxis es la siguiente:

type Tipo = OtroTipo

Ejemplo concreto:

type Punto = (Double, Double)

¿Cómo mejora esto la legibilidad del código?

puntoMedio :: (Double, Double) -> (Double, Double) -> (Double, Double)

es más legible como:

puntoMedio :: Punto -> Punto -> Punto

El tipo y sus sinónimos son intercambiables completamente. El 
compilador no marcará errores al mezclarlos. 

Aunque no es error, mezclarlos es un Code Smell.
-}



{-
9 Nuevos tipos (sinónimos de tipos no intercambiables)

newType Tipo = ConstructorDeTipo OtroTipo

newtype Point = MakePoint (Double, Double)

Para convertirlos entre sí, se utiliza la coincidencia de patrones:

coordenadaX :: Point -> Double
coordenadaX (MakePoint (x, _)) = x

El constructor puede tener el mismo nombre del tipo. 

Al usar nuevos tipos, el compilador salvaguarda el tipo de las expresiones
que involucren los nuevos tipos, sin posibilidad de que sean mezclados
y añadiendo valor semántica a nuestro código fuente
-}



{- 
10 Tipos de datos algebráicos

Los más comunes en la comunidad de Haskell. También los más flexibles y poderosos.

data NombreDelTipo = Constructor Argumentos | ...

Son parecidos a un newtype, pero soportan múltiples argumentos
También son parecidos a las tuplas, pero son preferidos que estas últimas 

data RGB = RGB Double Double Double

es más legible, documentado y correcto que 

(Double, Double, Double)

data Token = Operador String | Identificador String | Delimitador deriving Show
data ArbolSintaxis = ArbolSintaxis Token [ArbolSintaxis] deriving Show

Múltiples constructores en tipos de datos algebráicos

Cada constructor es un tipo diferente de valor que podría tomar el tipo

data Genre = Pop | Rock | Electronica | SinReggetonNoHayGrammy

data MaybeInt = NotAnInt | AnInt Int

data Lista = Vacia | Cons Int Lista

Tipos de datos parametrizados

data ListaGenerica a = VacioGenerico | Cons a (ListaGenerica a)

-}



{-
11 Clases de tipos

Instancias de una clase de tipos

elem :: Eq a => a -> [a] -> Bool

pertenece _ [] = False
pertenece x (y : ys) 
    | x == y = True
    | otherwise = pertenece x ys

data RGB = RGB Int Int Int

instance Show RGB where
    show (RGB r g b) =
        "RGB " ++ (show r) ++ " " ++ (show g) ++ " " ++ (show b)

Definir clases de tipos nuevas, como Eq, Ord o Show

class EQ a where
    (==) :: a -> a -> Bool
    (/=) :: a -> a -> Bool
-}

data RGB = RGB Int Int Int

instance Show RGB where
    show (RGB r g b) =
        "RGB " ++ (show r) ++ " " ++ (show g) ++ " " ++ (show b)



