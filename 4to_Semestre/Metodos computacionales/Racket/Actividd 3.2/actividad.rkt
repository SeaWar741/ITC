#lang racket

;Bohyeon Cha A01023804
;Juan Carlos Garfias Tovar A01652138

(define (isComentario string)
  (if(regexp-match #rx"//" string)
     ;(display "COMENTARIO\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isDivision string)
  (if(regexp-match #rx"/" string)
     ;(display "COMENTARIO\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isParentesisAbre string)
  (if(regexp-match #rx"[(]" string)
     ;(display "Parentesis que abre\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isParentesisCierra string)
  (if(regexp-match #rx"[)]" string)
     ;(display "Parentesis que cierra\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


(define (isAsignacion string)
  (if(regexp-match-positions #rx"=" string)
     ;(display "Asignacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isSuma string)
  (if(regexp-match-positions #rx"[+]" string)
     ;(display "Suma\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isResta string)
  (if(regexp-match #rx"[-]" string)
     ;(display "Resta\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isMultiplicacion string)
  (if(regexp-match-positions #rx"[*]" string)
     ;(display "Multiplicacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;este no se como hacerlo
(define (isPotencia string)
  (if(regexp-match-positions #rx"[/^]" string)
     ;(display "Potencia\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isVariable string)
  (if(regexp-match-positions #rx"[a-zA-Z]+" string)
     ;(display "Variable\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isReal string)
  (if(regexp-match #rx"[0-9].[0-9]" string)
     ;(display "Real\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isEntero string)
  (if(regexp-match #rx"[0-9]+[0-9]*" string)
     ;(display "Entero\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (printLine lst)
  (unless (empty? lst)
    (display (first lst))
    (display " ")
    (printLine (rest lst))
   )
)

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
      [(isVariable (first lst)) (display (first lst)) (display "\tVariable\n")]
      [(isReal (first lst)) (display (first lst)) (display "\tReal\n")]
      [(isEntero (first lst)) (display (first lst)) (display "\tEntero\n")]
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

(call-with-input-file "02.txt" next-line-it)


;Problemas
;Funcion para potencia
;Funcion para resta (solo aceptar el caracter independiente en el inicio de string)
;Funcion para entero (aceptar mas de dos digitos y negativos)
;Funcion para real (aceptar negativos)
;Funcion parentesis (hacer un loop interno en el string para ver que no sean mas elementos