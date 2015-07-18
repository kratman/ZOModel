; The line below should say CLISP and is used to place the interpreter
;CLISP
#|

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

 This program simulates a zombie outbreak using two logistic map style
 equations. Humans and zombies fight each other and the natural world.

 In a typical logistics map the human population would be given by:
 h = h+poprate*h-poprate*h*h/compscl
 where h is the population, poprate is the population growth rate, and
 compscl is a scale factor related to the amount of human cooperation.
 A large population growth rate would push the human population into
 the chaotic regime.

|#

;;; Main code ;;;

;; Define variables
; hpop => Initial human population
; zpop => Initial zombie population
; years => Simulation time in years
; months => Simulation time in months
; poprate => Yearly population growth rate
; winrate => Probability that a human beats a zombie
; infrate => Yearly infection rate
; merrate => Probability that the infected are prevented from turning
; erorate => Yearly rate of zombie destruction by natural forces
; compscl => Sets the amount of human-human cooperation

;; Parameters
(setq compscl 10000000)

; Print blank line
(format t "~%")

; Print title
(format t
"############################################################################
#                                                                          #
#                     ZOModel: Zombie Outbreak Modeling                    #
#                                                                          #
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
(format t " Human win rate:~%")
(setq winrate (read))
(format t " Human infection rate:~%") 
(setq infrate (read))
(format t " Mercy rate:~%")
(setq merrate (read))
(format t " Zombie erosion rate:~%")
(setq erorate (read))

; Check the input against minimum values
(if (< hpop 1) (setq hpop 0))
(if (< zpop 1) (setq zpop 0))
(if (< years 1) (setq years 0))
(if (< poprate 0) (setq poprate 0))
(if (< winrate 0) (setq winrate 0))
(if (< infrate 0) (setq infrate 0))
(if (< merrate 0) (setq merrate 0))
(if (< erorate 0) (setq erorate 0))
(if (< compscl 1) (setq compscl 1))

; Check input against maximum values
(if (> poprate 1) (setq poprate 1))
(if (> winrate 1) (setq winrate 1))
(if (> infrate 1) (setq infrate 1))
(if (> merrate 1) (setq merrate 1))
(if (> erorate 1) (setq erorate 1))

; Print settings after the sanity checks
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "Simulation settings:")
(format t "~%")
(format t "~%")
(format t " hpop: ")
(princ hpop)
(format t "~%")
(format t " zpop: ")
(princ zpop)
(format t "~%")
(format t " years: ")
(princ years)
(format t "~%")
(format t " poprate: ")
(princ (* 100 poprate))
(format t "\%~%")
(format t " compscl: ")
(princ compscl)
(format t "~%")
(format t " winrate: ")
(princ (* 100 winrate))
(format t "\%~%")
(format t " infrate: ")
(princ (* 100 infrate))
(format t "\%~%")
(format t " merrate: ")
(princ (* 100 merrate))
(format t "\%~%")
(format t " erorate: ")
(princ (* 100 erorate))
(format t "\%~%")

; Switch from years to months
(setq months (* 12 years))
(setq poprate (/ poprate 12.0))
(setq infrate (/ infrate 12.0))
(setq erorate (/ erorate 12.0))

; Explain model
#| Equations:

  h = h+poprate*h-poprate*h*h/compscl
      -(1-winrate)*z-infrate*h

  z = z+(1-merrate)*((1-winrate)*z+infrate*h)
      -erorate*z-winrate*z

|#

; Combine constants for readability (not used in the calculations)
(setq hlinrate (- (+ 1 poprate) infrate))
(setq hquadrate (/ poprate compscl))
(setq hzlinrate (- 1 winrate))
(setq zlinrate (- 1 erorate winrate))
(setq zlinrate (+ zlinrate (* (- 1 merrate) (- 1 winrate))))
(setq zhlinrate (* infrate (- 1 merrate)))

; Print intial model
(format t "~%")
(format t "Approximate model:")
(format t "~%")
(format t "~%")

; Human model
(format t " hpop=\(")
(princ hlinrate)
(format t "\)*hpop-\(")
(princ hquadrate)
(format t "\)*hpop*hpop-\(")
(princ hzlinrate)

; Zombie model
(format t "\)*zpop")
(format t "~%")
(format t "~%")
(format t " zpop=\(")
(princ zlinrate)
(format t "\)*zpop+\(")
(princ zhlinrate)
(format t "\)*hpop")
(format t "~%")
(format t "~%")

; Output more simulation info
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "Simulating the human and zombie populations \(in thousands\)")
(format t "~%")
(format t "for the first ")
(princ months)
(format t " months of a zombie outbreak.")
(format t "~%")

; Set stats counters to zero
(setq maxh 0)
(setq maxz 0)
(setq extmon 0)

; Loop over the zombie apocalypse
(format t "~%")
(format t "####")
(format t "~%")
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
    ; Collect stats
    (if (> hpop maxh) (setq maxh hpop))
    (if (> zpop maxz) (setq maxz zpop))
    (if (> hpop 0) (setq extmon i))
    ; Update human population
    (setq newhpop hpop)
    (setq newhpop (+ newhpop (* poprate hpop)))
    (setq newhpop (- newhpop (* (/ poprate compscl) hpop hpop)))
    (setq newhpop (- newhpop (* (- 1 winrate) zpop)))
    (setq newhpop (- newhpop (* infrate hpop)))
    ; Update zombie population
    (setq newzpop zpop)
    (if (> hpop 0.001)
      (setq newzpop (+ newzpop (* (- 1 merrate) (* (- 1 winrate) zpop)))))
    (if (> hpop 0.001)
      (setq newzpop (+ newzpop (* (- 1 merrate) (* infrate hpop)))))
    (setq newzpop (- newzpop (* erorate zpop)))
    (if (> hpop 0.001)
      (setq newzpop (- newzpop (* winrate zpop))))
    ; Prevent impossible populations
    (if (< newhpop 0.001) (setq newhpop 0))
    (if (< newzpop 0.001) (setq newzpop 0))
    ; Save populations
    (setq hpop newhpop)
    (setq zpop newzpop)
)

; Print stats
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "Statistics:")
(format t "~%")
(format t " Humans survived for ")
(princ extmon)
(format t " months")
(format t "~%")
(format t " Largest number of humans (in thousands): ")
(princ maxh)
(format t "~%")
(format t " Largest number of Zombies (in thousands): ")
(princ maxz)
(format t "~%")

; End of the world (and program)
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "The end?")
(format t "~%")
(if (< hpop 0.001) (format t " Yes. Everyone is dead.~%"))
(format t "~%")
