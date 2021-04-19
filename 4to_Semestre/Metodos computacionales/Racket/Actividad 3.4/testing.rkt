#lang racket
(define (isMinor string)
  (if(regexp-match #rx"^<" string)
     ;(display " Minor\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(isMinor "<")