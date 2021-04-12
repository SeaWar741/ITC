#lang racket

;Juan Carlos Garfias Tovar, A01652138

;Ejercicio 1
(display "\nEjerecicio 1 \n\n")
(define (insert number lst)
  ;(sort (cons number lst) <)
  (if (empty? lst)
      (cons number lst)
      (append
       (filter (lambda (x) (< x number)) lst)
       (cons number (filter (lambda (x) (> x number)) lst))
      )
  )
)

(insert 14 '())
;⇒ (14)
(insert 4 '(5 6 7 8))
;⇒ '(4 5 6 7 8)
(insert 5 '(1 3 6 7 9 16))
;⇒ (1 3 5 6 7 9 16)
(insert 10 '(1 5 6))
;⇒ (1 5 6 10)


;Ejercicio 2
(display "\nEjerecicio 2 \n\n")

(define (rotate-left-aux lst)
  (if (null? lst)
      '()
      (append (cdr lst)
              (cons (car lst)
                    '()))
   )
)

(define (rotate-right lst)
  (let ((rev (reverse lst)))
    (cons (car rev) (reverse (cdr rev)))
   )
 )

(define (rotate-left number lst)
  (if (empty? lst)
      '()
      (if(> number 0)
         (rotate-left (- number 1) (rotate-left-aux lst))
         (if(= number 0)
            lst
            (rotate-left (+ number 1) (rotate-right lst))
         )
      )
      
  )
)



(rotate-left 5 '())
;⇒ ()
(rotate-left 0 '(a b c d e f g))
;⇒ (a b c d e f g)
(rotate-left 1 '(a b c d e f g))
;⇒ (b c d e f g a)
(rotate-left -1 '(a b c d e f g))
;⇒ (g a b c d e f)
(rotate-left 3 '(a b c d e f g))
;⇒ (d e f g a b c)
(rotate-left -3 '(a b c d e f g))
;⇒ (e f g a b c d)
(rotate-left 8 '(a b c d e f g))
;⇒ (b c d e f g a)
(rotate-left -8 '(a b c d e f g))
;⇒ (g a b c d e f)
(rotate-left 45 '(a b c d e f g))
;⇒ (d e f g a b c)
(rotate-left -45 '(a b c d e f g))
;⇒ (e f g a b c d)


;Ejercicio 3
(display "\nEjerecicio 3 \n\n")

(define (count lst item amount)
  (if(empty? lst)
     '()
     (if (number? (car lst))
        (if(= (car lst) item)
           (count (cdr lst) item (+ amount 1))
           (amount)
        )
        (if(equal? (car lst) item)
           (count (cdr lst) item (+ amount 1))
           (amount)
        )
        
     )
  )
)


(define (encode lst)
  (if(empty? lst)
     '()
     (count lst (car lst) 0)
  )
  
)

(encode '())
;⇒ ()
(encode '(a a a a b c c a a d e e e e))
;⇒ ((4 a) (1 b) (2 c) (2 a) (1 d) (4 e))
(encode '(1 2 3 4 5))
;⇒ ((1 1) (1 2) (1 3) (1 4) (1 5))
(encode '(9 9 9 9 9 9 9 9 9))
;⇒ ((9 9))

