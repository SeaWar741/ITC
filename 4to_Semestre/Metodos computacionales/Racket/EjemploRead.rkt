#lang racket
(define p1 (open-input-file "EjemAct3_2.txt"))

(define (eof-object? p1))
(define (lee puerto)
  (if (eof-object? p1)
      (display "ADIOS")
      (define dato (read p1))
       (display dato)
       (lee p1)))



(define dato (read p1))
(display dato)
(define dato2(read p1))
(display dato2)
(define dato3 (read p1))
(display dato3)