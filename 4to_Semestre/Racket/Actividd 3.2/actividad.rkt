#lang racket

;Bohyeon Cha A01023804
;Juan Carlos Garfias Tovar A01652138

(define (isComment string)
  (if(regexp-match-positions #rx"//" string)
     (display "COMENTARIO\n")
     (display "Otro\n")
  )
)

(define (isAsignacion string)
  (if(regexp-match-positions #rx"=" string)
     (display "Asignacion")
     (display "Otro")
  )
)

(define (isSuma string)
  (if(regexp-match-positions #rx"[+]" string)
     (display "Suma\n")
     (display "Otro\n")
  )
)

(define (isResta string)
  (if(regexp-match-positions #rx"[-]" string)
     (display "Resta\n")
     (display "Otro\n")
  )
)

(define (isMultiplicacion string)
  (if(regexp-match-positions #rx"[*]" string)
     (display "Multiplicacion")
     (display "Otro")
  )
)

(define (isPotencia string)
  (if(regexp-match-positions #rx"[{]" string)
     (display "Potencia\n")
     (display "Otro\n")
  )
)

(define (isVariable string)
  (if(regexp-match-positions #rx"[a-zA-Z]+" string)
     (display "Variable\n")
     (display "Otro\n")
  )
)

(define (isReal string)
  (if(regexp-match-positions #rx"[0-9]" string)
     (display "Real\n")
     (display "Otro\n")
  )
)

(define (iterate lst)
  (unless (empty? lst)
    (isReal (first lst))
    (iterate (rest lst))))


(define (next-line-it file)
  (let ((line (read-line file 'any)))
    (unless (eof-object? line)
      (iterate (regexp-split #px" " line))
      (next-line-it file))))

(call-with-input-file "01.txt" next-line-it) 