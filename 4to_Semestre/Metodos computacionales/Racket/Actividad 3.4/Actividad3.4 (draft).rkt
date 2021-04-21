#lang racket
(require html)
(require xml)

;Bohyeon Cha A01023804
;Juan Carlos Garfias Tovar A01652138

;GO R Python

;funcion counter
(define (contadorCreador(cont 0)(agregar 1))
  (lambda() (set! cont (+ cont agregar)) cont)
)
(define contador(contadorCreador)) 

;funcion isDivision 
;input string
;verifica si el string tiene el simbolo de division
;return true or false
(define (isDivision string)
  (if(regexp-match #rx"/$" string)
     ;(display "COMENTARIO\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isParentesisAbre 
;input string
;verifica si el string tiene el simbolo de parentesis abierto
;return true or false
(define (isParentesisAbre string)
  (if(regexp-match #rx"^[(]+$" string)
     ;(display "Parentesis que abre\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isParentesisCierra 
;input string
;verifica si el string tiene el simbolo de parentesis cerrado
;return true or false
(define (isParentesisCierra string)
  (if(regexp-match #rx"^[)]+$" string)
     ;(display "Parentesis que cierra\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isAsignacion 
;input string
;verifica si el string tiene el simbolo de igual
;return true or false
(define (isAsignacion string)
  (if(regexp-match-positions #rx"=|<-$" string)
     ;(display "Asignacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isDiferente 
;input string
;verifica si el string tiene el simbolo de igual
;return true or false
(define (isDiferente string)
  (if(regexp-match-positions #rx"^!=+$" string)
     ;(display "Asignacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isSuma 
;input string
;verifica si el string tiene el simbolo de suma
;return true or false
(define (isSuma string)
  (if(regexp-match-positions #rx"[+]$" string)
     ;(display "Suma\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isResta 
;input string
;verifica si el string tiene el simbolo de resta y es el unico en el string
;return true or false
(define (isResta string)
  (if(regexp-match #rx"-(?!.)" string)
     ;(display "Resta\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isMultiplicacion 
;input string
;verifica si el string tiene el simbolo de multiplicacion
;return true or false
(define (isMultiplicacion string)
  (if(regexp-match-positions #rx"[*]" string)
     ;(display "Multiplicacion\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion isPotencia 
;input string
;verifica si el string tiene el simbolo de potencia
;return true or false
(define (isPotencia string)
  (if(regexp-match-positions #rx"\\^+" string)
     ;(display "Potencia\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (printIdentifier string out)
        (display "no hizo caso")
        (display "<td>\n" out) 
            (display string out)
          (display "</td>\n" out)
          (display "<td>\n" out) 
            (display "Identificador\n" out)
        (display "</td>\n" out)   
)

(define (evaluateIdentifier string out)
        (display "<td>\n" out) 
            (display (first (regexp-match* #rx"[-!$%^&*()_+|~=`{}'<>?,.\\/]" string #:match-select car #:gap-select? #t)) out)
          (display "</td>\n" out)
          (display "<td>\n" out) 
            (display "Identificador\n" out)
          (display "</td>\n" out)  
        (iterate (rest (regexp-match* #rx"[-!$%^&*()_+|~=`{}'<>?,.\\/]" string #:match-select car #:gap-select? #t)) out)
)


;funcion isVariable 
;input string
;verifica si el string tiene caracteres, numeros y underscore. El primer caracter siempre tiene que ser letras
;return true or false
(define (isVariable string out)
  (if(regexp-match-positions #rx"(?<![_0-9])[a-zA-Z]" string) 
    (if(regexp-match-positions #rx"^[a-zA-Z]+$" string)
     ;(display "Variable\n")
     ;(display "Otro\n")
    (printIdentifier string out)
        ;itera sobre el string y evalua cada elemento separado por espacio, coma o parentesis
    (evaluateIdentifier string out)
      
    )
    #f
  )
)




;funcion isFloat
;input string
;verifica que sea un numero con un punto ya sea cualquier parte del string
;verifica si contiene e o E o no. Toma si es negativo o positivo. Verifica que solo
;exista un punto en el string
;si no existe punto regresa falso
;return true or false
(define (isReal string)
  ;(if(regexp-match #rx"[-]?[0-9].[0-9]" string)
  (if(regexp-match #px"^([+-]?(\\d*\\.)?(?!.*?\\.\\.)\\d+[eE]?[-+]?\\d*?)|^[+-]?(?!.*?\\.\\.)[0-9.]+$" string)
     ;(display "Float\n")
     ;(display "Otro\n")
     (if (regexp-match #px"^[^.]*$" string)
         #f
         #t
     )
     #f
  )
)


;funcion isEntero 
;input string
;verifica que sea un numero positivo o negativo entero
;return true or false
(define (isEntero string)
  ;(if(regexp-match #rx"[-]?[0-9]+[0-9]*" string)
  (if(regexp-match #px"^[-+]?\\d+$)" string)
     ;(display "Entero\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion is if
;input string
;verifica que sea un if
(define (isIf string)
  (if(regexp-match #px"^if+$)" string)
     ;(display "If\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is else
;input string
;verifica que sea un else
(define (isElse string)
  (if(regexp-match #px"^else+$)" string)
     ;(display "Else\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (printFuncion string out)
        (display "<td>\n" out) 
            (display string out)
          (display "</td>\n" out)
          (display "<td>\n" out) 
            (display "Funcion\n" out)
        (display "</td>\n" out)   
)

(define (evaluateFunction string out)
        (display "<td>\n" out) 
            (display (first (regexp-match* #rx"\\(|\\)|,| |\\[|\\]|\\{|\\}" string #:match-select car #:gap-select? #t)) out)
          (display "</td>\n" out)
          (display "<td>\n" out) 
            (display "Funcion\n" out)
          (display "</td>\n" out)  
        (iterate (rest (regexp-match* #rx"\\(|\\)|,| |\\[|\\]|\\{|\\}" string #:match-select car #:gap-select? #t)) out)
)

;funcion is funcion
;input string
;verifica que sea una funcion
(define (isFuncion string out)
  (if(regexp-match #rx"[a-zA-Z]+\\(+" string)
    (if(regexp-match #rx"[a-zA-Z]+\\([^\\)]*\\)(\\.[^\\)]*\\))?" string) ;<--- esta no se cumple
      ;(display "Funcion\n")
      ;(display "Otro\n")

        (printFuncion string out)
      (if(regexp-match #rx"[a-zA-Z]+\\(+" string)
        ;itera sobre el string y evalua cada elemento separado por espacio, coma o parentesis
        (evaluateFunction string out)
        #f
      )
    )
    #f
  )
)


;funcion is equal
;input string
;verifica que sea un equal
(define (isEqual string)
  (if(regexp-match #rx"(?<!=)==(?!=)" string)
     ;(display "Igual\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is masmas
;input string
;verifica que sea un masmas
(define (isMasmas string)
  (if(regexp-match #px"[+]{2}" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is boolean
;input string
;verifica que sea un masmas
(define (isBoolean string)
  (if(regexp-match #rx"^([Tt][Rr][Uu][Ee]|[Ff][Aa][Ll][Ss][Ee])$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveAbre
(define (isLlaveAbre string)
  (if(regexp-match #rx"^[[]+$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveCierra
(define (isLlaveCierra string)
  (if(regexp-match #rx"^[]]+$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveAbre
(define (isCurlyBracketAbre string)
  (if(regexp-match #rx"^[{]+$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveCierra
(define (isCurlyBracketCierra string)
  (if(regexp-match #rx"^[}]+$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion is import
(define (isImport string)
  (if(regexp-match #rx"^import+$" string)
     ;(display "Import\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is defFunc
(define (isDefFunc string)
  (if(regexp-match #rx"(\\s|^|[\t])func|def+$" string)
     ;(display "Def\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is return
(define (isReturn string)
  (if(regexp-match #rx"(\\s|^|[\t])return+$" string)
     ;(display "Return\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is end
(define (isEnd string)
  (if(regexp-match #rx"(\\s|^|[\t])end+$" string)
     ;(display "End\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is comment
(define (isFor string)
  (if(regexp-match #rx"for+$" string)
     ;(display "For\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion is comment
(define (isComment string)
  (if(regexp-match #rx"//|#" string)
     ;(display "Comment\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion isLlaveAbre
(define (isComillasAbre string)
  (if(regexp-match #rx"^["\".*\""]+$" string)
     ;(display "Mas mas\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

(define (isString string)
  (if(regexp-match #rx"^$" string)
     ;(display "Comment\n")
     ;(display "Otro\n")
     #t
     #f
  )
)



;funcion whiteline 
;input lista
;imprime los strings de una linea/lista
;imprime
(define (whiteline string)
  (if(regexp-match #rx"^\\s*$" string)
     ;(display "Comment\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion minor 
;input lista
(define (isMinor string)
  (if(regexp-match #rx"^<" string)
     ;(display " Minor\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion minorEqual
;input lista
(define (isMinorEqual string)
  (if(regexp-match #rx"^<=" string)
     ;(display "MinorEqual\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion major 
;input lista
(define (isMajor string)
  (if(regexp-match #rx"^>" string)
     ;(display "Major\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion majorEqual
;input lista
(define (isMajorEqual string)
  (if(regexp-match #rx"^>=" string)
     ;(display "MajorEqual\n")
     ;(display "Otro\n")
     #t
     #f
  )
)

;funcion modulus
;input lista
(define (isModulus string)
  (if(regexp-match #rx"^%" string)
     ;(display "Modulus\n")
     ;(display "Otro\n")
     #t
     #f
  )
)


;funcion reserved
(define (isReserved string)
  (if(regexp-match #rx"(\\s|^|[\t])(and|except|lambda|with|as|finally|nonlocal|while|assert|false|None|yield|break|for|not|class|from|or|continue|global|pass|def|if|raise|del|import|return|elif|in|True|else|is|try|const|var|func|type|package|chan|interface|map|struct|case|default|fallthrough|goto|range|select|switch|defer|go|repeat|function|next|TRUE|FALSE|NULL|Inf|NaN|NA|NA_integer_|NA_real_|NA_complex_|NA_character_|\\.\\.\\.)+$" string)
     #t
     #f
  )
)

;-------------------funciones Helper-------------------

;funcion printLine 
;input lista
;imprime los strings de una linea/lista
;imprime
(define (printLine lst out)
  (unless (empty? lst)
    (display (first lst) out)
    (display " " out)
    (printLine (rest lst) out)
   )
)


;funcion para exportar a HTML
(define (print-tuple tuple out)
  (cond [(empty? (rest tuple))
         (display (first tuple) out)]
        [else
         (display (first tuple) out)
         (display "\n" out)
         (print-tuple (rest tuple) out)])
)


;-------------------funciones principales-------------------


;funcion iterate 
;input lista
;evalua el tipo de string y realiza la tokenizacion
;si es comentario todo lo demas se ignora de la tokenizacion y se imprimen juntos
;imprime los strings con su tipo
(define (iterate lst out)
  (unless (empty? lst) ;verifica que no este vacia
    (display "\n<tr>\n" out)
    (cond ;aplica funcionaes condicionales para evaluar los strings
      [(whiteline (first lst)) #f]
      [(isComment (first lst))
              (display "<td>\n" out) 
                (printLine lst out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Comentario\n" out)
              (display "</td>\n" out)
      ]
      [(isDefFunc(first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Definicion de funcion\n" out)
              (display "</td>\n" out)
      ]
      [(isFuncion (first lst) out) 
      ]
      [(isIf(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "IF\n" out)
              (display "</td>\n" out)
      ]
      [(isElse(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Else\n" out)
              (display "</td>\n" out)
      ]
      [(isBoolean(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Boolean\n" out)
              (display "</td>\n" out)
        ]
      [(isImport(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Import\n" out)
              (display "</td>\n" out)
      ]
      [(isReturn(first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Return\n" out)
              (display "</td>\n" out)
      ]
      [(isEnd(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "End\n" out)
              (display "</td>\n" out)
      ]
      [(isFor(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "For\n" out)
              (display "</td>\n" out)
      ]

      [(isReal (first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Real\n" out)
              (display "</td>\n" out)
      ]

      [(isMinorEqual(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "MinorEqual\n" out)
              (display "</td>\n" out)
      ]
      [(isMajorEqual(first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "MajorEqual\n" out)
              (display "</td>\n" out)
      ]
 
      [(isEqual(first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "IgualIgual\n" out)
              (display "</td>\n" out)
      ]

      [(isDiferente(first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Diferente\n" out)
              (display "</td>\n" out)
      ]

      [(isMasmas(first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "MasMas\n" out)
              (display "</td>\n" out)
      ]

      [(isAsignacion (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Asignacion\n" out)
              (display "</td>\n" out)
      ]

      [(isMajor(first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Major\n" out)
              (display "</td>\n" out)
      ]

      [(isMinor(first lst))
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Minor\n" out)
              (display "</td>\n" out)
      ]
      
      [(isSuma (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Suma\n" out)
              (display "</td>\n" out)
      ]

      [(isResta (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Resta\n" out)
              (display "</td>\n" out)
      ]

      [(isMultiplicacion (first lst)) 
              (display "<td>\n" out)   
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Multiplicacion\n" out)
              (display "</td>\n" out)
      ]

      [(isDivision (first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Division\n" out)
              (display "</td>\n" out)
      ]

      [(isPotencia (first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Potencia\n" out)
              (display "</td>\n" out)
      ]

      [(isModulus (first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Modulo\n" out)
              (display "</td>\n" out)
      ]

      [(isParentesisAbre (first lst)) 
              (display "<td>\n" out) 
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
              (display "Parentesis que abre\n" out)
              (display "</td>\n" out)
      ]
      [(isParentesisCierra (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Parentesis que cierra\n" out)
              (display "</td>\n" out)
      ]

      [(isLlaveAbre (first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Llave que abre\n" out)
              (display "</td>\n" out)
      ]

      [(isLlaveCierra (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Llave que cierra\n" out)
              (display "</td>\n" out)
      ]

      [(isCurlyBracketAbre (first lst)) 
              (display "<td>\n" out)
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Curly bracket que abre\n" out)
              (display "</td>\n" out)
      ]

      [(isCurlyBracketCierra (first lst))
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Curly bracket que cierra\n" out)
              (display "</td>\n" out)
      ]



      [(isEntero (first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Entero\n" out)
              (display "</td>\n" out)
      ]

      ;reservados, hace catch si no encuentra especificamente la necesaria
      [(isReserved (first lst)) 
              (display "<td>\n" out)  
                (display (first lst) out)
              (display "</td>\n" out)
              (display "<td>\n" out)
                (display "Reservada\n" out)
              (display "</td>\n" out)
      ]
      
      [(isVariable (first lst) out) 
      ]
      [else 
              (display "<td>\n" out)
                (display (first lst) out)  
              (display "</td>\n" out)  
              (display "<td>\n" out)
                (display "Error de formato\n"  out)
              (display "</td>\n" out)
      ] 
    ) 
    ;si no es comentario se itera si es comentario se imprime directamente
    (if (not (isComment (first lst)))
        (iterate (rest lst) out)
        #f
    )
    ;;; (display "<td>\n" out)
    ;;; (display (contador) out)  
    ;;; (display "</td>\n" out)

  )


  (display "</tr>\n" out)
)


;funcion next-line-it 
;input file (nombre o path del archivo)
;lee cada linea del archivo y la separa por espacios
;toma esa linea y la evalua con la funcion iterate
(define (next-line-it file out)
  (for ([e (in-list file)])
    (iterate (regexp-split #px" " e) out)
  )
)

;funcion lexerAritmetico
;input file (nombre o path del archivo)
;output imprime la tokenizacion 
(define (lexer filename)
  (define out (open-output-file "testing.html" #:exists 'replace))
  (define iistt (file->lines "htmlBase.txt"))
  (print-tuple iistt out)

  ;exportar a hmtl y lectura de archivo
  
  ;(call-with-input-file filename next-line-it )
  (define filelist (file->lines filename))
  (next-line-it filelist out)

  (display "<tbody>\n" out)
  (display "</table>\n" out)
  (display "</div>\n" out)
  (display "</div>\n" out)
  (display "</body>\n" out)
  (display "</html>\n" out)
  (close-output-port out)
)





(display "Bohyeon Cha & Juan Carlos Garfias\n")
(display "Ingresar (lexer Nombre del archivo)\n")




(lexer "./Examples/Quicksort.go")
