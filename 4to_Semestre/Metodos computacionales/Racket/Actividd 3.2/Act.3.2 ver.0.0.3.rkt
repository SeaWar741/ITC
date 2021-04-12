#lang racket

;Bohyeon Cha A01023804
;Juan Carlos Garfias Tovar A01652138

;funcion isComentario 
;input string
;verifica si el string tiene el simbolo de igual
;return true or false
(define (isComentario string)
  (if(regexp-match #rx"/(?=/)" string)
     ;(display "COMENTARIO\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isDivision 
;input string
;verifica si el string tiene el simbolo de division
;return true or false
(define (isDivision string)
  (if(regexp-match #rx"/$" string)
     ;(display "COMENTARIO\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isParentesisAbre 
;input string
;verifica si el string tiene el simbolo de parentesis abierto
;return true or false
(define (isParentesisAbre string)
  (if(regexp-match #rx"[(]" string)
     ;(display "Parentesis que abre\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isParentesisCierra 
;input string
;verifica si el string tiene el simbolo de parentesis cerrado
;return true or false
(define (isParentesisCierra string)
  (if(regexp-match #rx"[)]" string)
     ;(display "Parentesis que cierra\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isAsignacion 
;input string
;verifica si el string tiene el simbolo de igual
;return true or false
(define (isAsignacion string)
  (if(regexp-match-positions #rx"=$" string)
     ;(display "Asignacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isAsignacion 
;input string
;verifica si el string tiene el simbolo de igual
;return true or false
(define (isSuma string)
  (if(regexp-match-positions #rx"[+]$" string)
     ;(display "Suma\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isResta 
;input string
;verifica si el string tiene el simbolo de resta y es el unico en el string
;return true or false
(define (isResta string)
  (if(regexp-match #rx"-(?!.)" string)
     ;(display "Resta\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isMultiplicacion 
;input string
;verifica si el string tiene el simbolo de multiplicacion
;return true or false
(define (isMultiplicacion string)
  (if(regexp-match-positions #rx"[*]" string)
     ;(display "Multiplicacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isPotencia 
;input string
;verifica si el string tiene el simbolo de potencia
;return true or false
(define (isPotencia string)
  (if(regexp-match-positions #rx"\\^+" string)
     ;(display "Potencia\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isVariable 
;input string
;verifica si el string tiene caracteres, numeros y underscore. El primer caracter siempre tiene que ser letras
;return true or false
(define (isVariable string)
  (if(regexp-match-positions #rx"(?<![_0-9])[a-zA-Z]" string) 
     ;(display "Variable\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isReal 
;input string
;verifica que sea un numero con un punto ya sea cualquier parte del string
;verifica si contiene e o E o no. Toma si es negativo o positivo. Verifica que solo
;exista un punto en el string
;si no existe punto regresa falso
;return true or false
(define (isReal string)
  ;(if(regexp-match #rx"[-]?[0-9].[0-9]" string)
  (if(regexp-match #px"^([+-]?(\\d*\\.)?(?!.*?\\.\\.)\\d+[eE]?[-+]?\\d*?)|^[+-]?(?!.*?\\.\\.)[0-9.]+$" string)
     ;(display "Real\n")
     ;(display "Otro\n")
     (if (regexp-match #px"^[^.]*$" string)
         #f
         #t
     )
     #f
  )
)

;funcion isEntero 
;input string
;verifica que sea un numero positivo o negativo entero
;return true or false
(define (isEntero string)
  ;(if(regexp-match #rx"[-]?[0-9]+[0-9]*" string)
  (if(regexp-match #px"^[-+]?\\d+$)" string)
     ;(display "Entero\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion printLine 
;input lista
;imprime los strings de una linea/lista
;return true or false
(define (printLine lst)
  (unless (empty? lst)
    (display (first lst))
    (display " ")
    (printLine (rest lst))
   )
)


;funcion iterate 
;input lista
;imprime los strings de una linea/lista
;return true or false
(define (iterate lst)
  (unless (empty? lst)
    (cond
      [(isComentario (first lst)) (printLine lst) (display "\tComentario\n")]
      [(isDivision (first lst)) (display (first lst)) (display "\tDivision\n")]
      [(isParentesisAbre (first lst)) (display (first lst)) (display "\tParentesis que abre\n")]
      [(isParentesisCierra (first lst)) (display (first lst)) (display "\tParentesis que cierra\n")]
      [(isParentesisCierra (first lst)) (display (first lst)) (display "\tParentesis que cierra\n")]
      [(isAsignacion (first lst)) (display (first lst)) (display "\tAsignacion\n")]
      [(isSuma (first lst)) (display (first lst)) (display "\tSuma\n")]
      [(isResta (first lst)) (display (first lst)) (display "\tResta\n")]
      [(isMultiplicacion (first lst)) (display (first lst)) (display "\tMultiplicacion\n")]
      [(isPotencia (first lst)) (display (first lst)) (display "\tPotencia\n")]
      [(isReal (first lst)) (display (first lst)) (display "\tReal\n")]
      [(isEntero (first lst)) (display (first lst)) (display "\tEntero\n")]
      [(isVariable (first lst)) (display (first lst)) (display "\tVariable\n")]
      
      
    )
    (if (not (isComentario (first lst)))
        (iterate (rest lst))
        #f
    )

  )
)


(define (next-line-it file)
  (let ((line (read-line file 'any)))
    (unless (eof-object? line)
      (iterate (regexp-split #px" " line))
      (next-line-it file))))


(define (lexerAritmetico filename)
  (call-with-input-file filename next-line-it)
)