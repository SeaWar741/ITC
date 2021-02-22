#lang racket
;Juan Carlos Garfias Tovar, A01652138

;Ejercicio 1
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
