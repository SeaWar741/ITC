#lang racket
(regexp-match* #rx"\\(|\\)|,| " e #:match-select car #:gap-select? #t)