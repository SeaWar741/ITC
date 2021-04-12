#|
multiplo de 400 si
multiplo de 100 no
multiplo de 4 si 
cualquier otro no
|#

(define (bici num)
    (if(=  (modulo num 400)0)
        (display "SI")
        (if(=(modulo num 100) 0)
            (display ("NO"))
            (if(=(modulo num 4) 0)
                (display "SI")
                (display "NO")))
    )
)