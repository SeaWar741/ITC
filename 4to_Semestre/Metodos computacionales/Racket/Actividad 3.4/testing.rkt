#lang racket
(define (ismember1? str strs) (ormap [lambda (s) (string=? s str)] strs) )
(ismember1? "\t" '("hola","como","\t"))