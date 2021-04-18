#lang racket
(require html)
(require xml)

(define (print-tuple tuple out)
  (cond [(empty? (rest tuple))
         (display (first tuple) out)]
        [else
         (display (first tuple) out)
         (display " " out)
         (print-tuple (rest tuple) out)]))

(define (reader filename)
  (define out (open-output-file "testing.html"))
  (file->lines "htmlBase.txt")

  ;(for-each display file out)

  ;(print-tuple file out)
  
  (display "<tbody>\n" out)
  (display "</table>\n" out)
  (display "</div>\n" out)
  (display "</div>\n" out)
  (display "</body>\n" out)
  (display "</html>\n" out)
  (close-output-port out)
)

(reader "htmlBase.txt")