#lang racket

;Bohyeon Cha A01023804
;Juan Carlos Garfias Tovar A01652138

;GO R Python

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
  (if(regexp-match-positions #rx"=|(<-)$" string)
     ;(display "Asignacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isSuma 
;input string
;verifica si el string tiene el simbolo de suma
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


;funcion isFloat
;input string
;verifica que sea un numero con un punto ya sea cualquier parte del string
;verifica si contiene e o E o no. Toma si es negativo o positivo. Verifica que solo
;exista un punto en el string
;si no existe punto regresa falso
;return true or false
(define (isReal string)
  ;(if(regexp-match #rx"[-]?[0-9].[0-9]" string)
  (if(regexp-match #px"^([+-]?(\\d*\\.)?(?!.*?\\.\\.)\\d+[eE]?[-+]?\\d*?)|^[+-]?(?!.*?\\.\\.)[0-9.]+$" string)
     ;(display "Float\n")
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


;funcion is if
;input string
;verifica que sea un if
(define (isIf string)
  (if(regexp-match #px"^if+$)" string)
     ;(display "If\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is else
;input string
;verifica que sea un else
(define (isElse string)
  (if(regexp-match #px"^else+$)" string)
     ;(display "Else\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is funcion
;input string
;verifica que sea una funcion
(define (isFuncion string)
  (if(regexp-match #rx"(?:(\(+([0-9]|[a-zA-Z])?\)+) )[ ( ?<![0-9])[a-zA-Z]]" string)
     ;(display "Else\n")
     ;(display "Otro\n")
     #t
     #f
  )
)



;funcion is equal
;input string
;verifica que sea un equal
(define (isEqual string)
  (if(regexp-match #rx"(?<!=)==(?!=)" string)
     ;(display "Igual\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is masmas
;input string
;verifica que sea un masmas
(define (isMasmas string)
  (if(regexp-match #px"[+]{2}" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is boolean
;input string
;verifica que sea un masmas
(define (isBoolean string)
  (if(regexp-match #rx"^([Tt][Rr][Uu][Ee]|[Ff][Aa][Ll][Ss][Ee])$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveAbre
(define (isLlaveAbre string)
  (if(regexp-match #rx"[[]" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveCierra
(define (isLlaveCierra string)
  (if(regexp-match #rx"[]]" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is import
(define (isImport string)
  (if(regexp-match #rx"^import+$" string)
     ;(display "Import\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is defFunc
(define (isDefFunc string)
  (if(regexp-match #rx"^func|def+$" string)
     ;(display "Def\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is return
(define (isReturn string)
  (if(regexp-match #rx"^return+$" string)
     ;(display "Return\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is end
(define (isEnd string)
  if(regexp-match #rx"^end+$" string)
     ;(display "End\n")
     ;(display "Otro\n")
     #t
     #f
  )
)




;funcion iterate 
;input lista
;evalua el tipo de string y realiza la tokenizacion
;si es comentario todo lo demas se ignora de la tokenizacion y se imprimen juntos
;imprime los strings con su tipo
(define (iterate lst)
  (unless (empty? lst) ;verifica que no este vacia
    (cond ;aplica funcionaes condicionales para evaluar los strings
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
      [else (display (first lst)) (display "\tError de formato\n")]
      
    )
    (iterate (rest lst))

  )
)

;funcion next-line-it 
;input file (nombre o path del archivo)
;lee cada linea del archivo y la separa por espacios
;toma esa linea y la evalua con la funcion iterate
(define (next-line-it file)
  (let ((line (read-line file 'any)))
    (unless (eof-object? line)
      (iterate (regexp-split #px" " line))
      (next-line-it file))))

;funcion lexerAritmetico
;input file (nombre o path del archivo)
;output imprime la tokenizacion 
(define (lexerAritmetico filename)
  (display "\nToken\tTipo\n")
  (call-with-input-file filename next-line-it)
)

(display "Bohyeon Cha & Juan Carlos Garfias\n")
(display "Ingresar (lexerAritmetico Nombre del archivo)\n")