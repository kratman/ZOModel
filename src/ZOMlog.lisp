;CLISP
#|

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

|#

;;; Main code ;;;

; Print blank line
(format t "~%")

; Print title
(format t
"############################################################################
#                                                                          #
#                     ZOModel: Zombie Outbreak Modeling                    #
#                            By: Eric G. Kratz                             #
#                                                                          #
############################################################################
~%")

; Collect input variables
(format t "Input:~%")
(format t " Initial human population (thousands):~%")
(setq hpop (read))
(format t " Initial zombie population (thousands):~%")
(setq zpop (read))
(format t " Run time \(years\):~%")
(setq years (read))
(format t " Human population growth rate:~%")
(setq poprate (read))
(format t " Zombie win rate:~%")
(setq winrate (read))
(format t " Human infection rate:~%") 
(setq infrate (read))
(format t " Mercy rate:~%")
(setq merrate (read))
(format t " Zombie erosion rate:~%")
(setq erorate (read))

; Switch from years to months
(setq months (* 12 years))
(setq poprate (/ poprate 12.0))
(setq winrate (/ winrate 12.0))
(setq infrate (/ infrate 12.0))
(setq merrate (/ merrate 12.0))
(setq erorate (/ erorate 12.0))

; Output simulation info
(format t "~%")
(format t "Simulating the human and zombie populations \(in thousands\)")
(format t "~%")
(format t "for the first ")
(princ months)
(format t " months of a zombie outbreak:")
(format t "~%")

; Loop over the zombie apocalypse
(format t "~%")
(format t "Month Humans Zombies")
(format t "~%")
(loop
  for i from 0 to months
  do
    ; Print current stats
    (format t " ")
    (princ i)
    (format t " ")
    (princ hpop)
    (format t " ")
    (princ zpop)
    (format t "~%")
    ; Update human population
    (setq newhpop hpop)
    (setq newhpop (+ newhpop (* poprate hpop)))
    (setq newhpop (- newhpop (* (/ poprate 10000) hpop hpop)))
    (setq newhpop (- newhpop (* winrate zpop)))
    (setq newhpop (- newhpop (* infrate hpop)))
    ; Update zombie population
    (setq newzpop zpop)
    (if (> hpop 0.001)
      (setq newzpop (+ newzpop (* (- 1 merrate) (* winrate zpop)))))
    (if (> hpop 0.001)
      (setq newzpop (+ newzpop (* (- 1 merrate) (* infrate hpop)))))
    (setq newzpop (- newzpop (* erorate zpop)))
    (if (> hpop 0.001)
      (setq newzpop (- newzpop (* (- 1 winrate) zpop))))
    ; Prevent impossible populations
    (if (< newhpop 0.001) (setq newhpop 0))
    (if (< newzpop 0.001) (setq newzpop 0))
    ; Save populations
    (setq hpop newhpop)
    (setq zpop newzpop)
)

; End of the world (and program)
(format t "~%")
(format t "The end?")
(format t "~%")
(if (< hpop 0.001) (format t " Yes. Everyone is dead."))
(format t "~%")
(format t "~%")
