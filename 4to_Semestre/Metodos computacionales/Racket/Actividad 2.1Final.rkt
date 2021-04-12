#lang racket

;Juan Carlos Garfias Tovar, A01652138

;Ejercicio 1
(display "\nEjerecicio 1 \n\n")
(define (fahrenheit-to-celsius f)
    (/ (* 5 (- f 32)) 9)
)

#|Verificacion|#
(fahrenheit-to-celsius 212.0)
;100.0
(fahrenheit-to-celsius 32.0)
;0.0
(fahrenheit-to-celsius -40.0)
;-40.0


;Ejercicio 2
(display "\nEjerecicio 2 \n\n")

(define (bmiCalc weight height)
    (/ weight (expt height 2)))

(define (bmi weight height)
  (if (or (> (bmiCalc weight height) 40) (= (bmiCalc weight height) 40))
    (display "obese3 \n")
    (if (and (< (bmiCalc weight height) 40) (or (> (bmiCalc weight height) 30) (= (bmiCalc weight height) 30)))
        (display "obese2 \n")
        (if (and (< (bmiCalc weight height) 30) (or (> (bmiCalc weight height) 25) (= (bmiCalc weight height) 25)))
            (display "obese1 \n")
            (if (and (< (bmiCalc weight height) 25) (or (> (bmiCalc weight height) 20) (= (bmiCalc weight height) 20)))
                (display "normal \n")
                (if(< (bmiCalc weight height) 20)
                    (display "underweight \n")
                    (display "")
                )
            )
        )
    )
  )
)

(bmi 45 1.7)
;underweight
(bmi 55 1.5)
;normal
(bmi 76 1.7)
;obese1


;Ejercicio 3
(display "\nEjerecicio 3 \n\n")
(define (positives lst)
  (if (empty? lst)
     '()
     (filter (lambda (x) (positive? x)) lst)
   )
 )
 

(positives '())
;|⇒ ()

(positives '(12 -4 3 -1 -10 -13 6 -5))
;|⇒ '(12 3 6)

(positives '(-4 -1 -10 -13 -5))
;⇒ ()


;Ejercicio 4
(display "\nEjerecicio 4 \n\n")

;car primer valor de lista
;cdr todo lo que no es el primer elemento (se va moviendo)
;append (fuciona listas)
;cons es un append de enteros


;a reemplaza a b

(define (swapperhelper lst init final) 
  (cond
    [(empty? lst) '()];si esta vacia
    [(equal? lst init) final init]
    [(list? lst)
     (cons (swapperhelper (car lst) init final) (swapperhelper (cdr lst) init final))] ;condicion para hacer los cambios y copiar
    [else lst];no se encuentra el caracter
  )
)

(define (swapper final init lst)
  (swapperhelper lst init final)
)


(swapper 1 2 '())
;⇒ ()

(swapper 1 2 '(4 4 5 2 4 8 2 5 6 4 5 1 9 5 9 9 1 2 2 4))
;⇒ (4 4 5 1 4 8 1 5 6 4 5 2 9 5 9 9 2 1 1 4)

(swapper 1 2 '(4 3 4 9 9 3 3 3 9 9 7 9 3 7 8 7 8 4 5 6))
;⇒ (4 3 4 9 9 3 3 3 9 9 7 9 3 7 8 7 8 4 5 6)

(swapper 'purr 'kitty '(soft kitty warm kitty little ball of fur happy kitty sleepy kitty purr purr purr))
;⇒ (soft purr warm purr little ball of fur happy purr sleepy purr kitty kitty kitty)
