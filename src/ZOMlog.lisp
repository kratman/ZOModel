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

#|

;;; Documentation ;;;

#|

 This program simulates a zombie outbreak using two logistic map style
 equations. Humans and zombies fight each other and the natural world.

 In a typical logistics map the human population would be given by:

 hpop = hpop + poprate*h - poprate*hpop*hpop/compscl

 where hpop is the population, poprate is the population growth rate, and
 compscl is a scale factor related to the amount of human cooperation.
 A large population growth rate would push the human population into
 the chaotic regime.

 The human-zombie model is given by:

 hpop = hpop + poprate*hpop - poprate*hpop*hpop/compscl
        -(1-winrate)*zpop - infrate*hpop

 zpop = zpop + (1-merrate)*((1-winrate)*zpop+infrate*hpop)
        -erorate*zpop - winrate*zpop

 where zpop is the zombie population, winrate is the probability that a
 human can beat a zombie, merrate is the probability that an infected
 human will be prevented from reanimating, and erorate is the rate of
 zombie population erosion from natural forces. Zombie-human interactions
 are not calculated when there is less than 1 member of the population and
 negative populations are set to zero.

 Chaotic simulations are unlikely in ZOMlog due to limits on growth rates,
 avoidance of negative populations, and the zombie-human interactions.
 This model should be realistic for large populations, but it will break
 down when the populations are small.

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
; Strange number, but tuned for ~10 billion humans
(setf compscl 10000400)

;; Print blank line
(format t "~%")

;; Print title
(format t
"############################################################################
#                                                                          #
#                     ZOModel: Zombie Outbreak Modeling                    #
#                                                                          #
#                            By: Eric G. Kratz                             #
#                                                                          #
############################################################################
~%")

;; Print separator
(format t "####")
(format t "~%")

;; Collect input variables
(format t "~%")
(format t "Input:")
(format t "~%")
; Human population
(format t " Initial human population (thousands):")
(format t "~%")
(setf hpop (read))
; Zombie population
(format t " Initial zombie population (thousands):")
(format t "~%")
(setf zpop (read))
; Simulation time
(format t " Run time \(years\):")
(format t "~%")
(setf years (read))
; Population growth rate
(format t " Human population growth rate:")
(format t "~%")
(setf poprate (read))
; Human win rate
(format t " Human win rate:")
(format t "~%")
(setf winrate (read))
; Viral infection rate
(format t " Human infection rate:")
(format t "~%")
(setf infrate (read))
; Mercy rate
(format t " Mercy rate:")
(format t "~%")
(setf merrate (read))
; Zombie destruction rate
(format t " Zombie erosion rate:")
(format t "~%")
(setf erorate (read))

;; Check the input against minimum values
(if (< hpop 1) (setf hpop 0))
(if (< zpop 1) (setf zpop 0))
(if (< years 1) (setf years 0))
(if (< poprate 0) (setf poprate 0))
(if (< winrate 0) (setf winrate 0))
(if (< infrate 0) (setf infrate 0))
(if (< merrate 0) (setf merrate 0))
(if (< erorate 0) (setf erorate 0))
(if (< compscl 1) (setf compscl 1))

;; Check input against maximum values
(if (> poprate 1) (setf poprate 1))
(if (> winrate 1) (setf winrate 1))
(if (> infrate 1) (setf infrate 1))
(if (> merrate 1) (setf merrate 1))
(if (> erorate 1) (setf erorate 1))

;; Print settings after the sanity checks
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "Simulation settings:")
(format t "~%")
(format t "~%")
; Human population
(format t " hpop: ")
(princ hpop)
(format t "~%")
; Zombie population
(format t " zpop: ")
(princ zpop)
(format t "~%")
; Simulation time
(format t " years: ")
(princ years)
(format t "~%")
; Population rate
(format t " poprate: ")
(princ (* 100 poprate))
(format t "\%~%")
; Competion scale factor
(format t " compscl: ")
(princ compscl)
(format t "~%")
; Win rate
(format t " winrate: ")
(princ (* 100 winrate))
(format t "\%~%")
; Infection rate
(format t " infrate: ")
(princ (* 100 infrate))
(format t "\%~%")
; Mercy rate
(format t " merrate: ")
(princ (* 100 merrate))
(format t "\%~%")
; Zombie destruction rate
(format t " erorate: ")
(princ (* 100 erorate))
(format t "\%~%")

;; Switch from years to months
; Easy conversion from years to months
(setf months (* 12 years))
; Fix growth rate for exponential growth
(setf poprate (+ 1 poprate))
(setf poprate (expt poprate (/ 1 12.0)))
(setf poprate (- poprate 1))
; These are additive and should be fine
(setf infrate (/ infrate 12.0))
(setf erorate (/ erorate 12.0))

;; Explain model
#| Equations:

  hpop = hpop+poprate*hpop-poprate*hpop*hpop/compscl
         -(1-winrate)*zpop-infrate*hpop

  zpop = zpop+(1-merrate)*((1-winrate)*zpop+infrate*hpop)
         -erorate*zpop-winrate*zpop

|#

;; Combine constants for readability (not used in the calculations)
; Humans
(setf hlinrate (- (+ 1 poprate) infrate))
(setf hquadrate (/ poprate compscl))
(setf hzlinrate (- 1 winrate))
; Zombies
(setf zlinrate (- 1 erorate winrate))
(setf zlinrate (+ zlinrate (* (- 1 merrate) (- 1 winrate))))
(setf zhlinrate (* infrate (- 1 merrate)))

;; Print intial model
(format t "~%")
(format t "Approximate model:")
(format t "~%")
(format t "~%")

;; Human model
(format t " hpop=\(")
(princ hlinrate)
(format t "\)*hpop-\(")
(princ hquadrate)
(format t "\)*hpop*hpop-\(")
(princ hzlinrate)

;; Zombie model
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

;; Output more simulation details
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
(format t "~%")
(format t "This model should be realistic for large populations, but")
(format t "~%")
(format t "it will break down when the populations are small.")
(format t "~%")

;; Set stats counters to zero
(setf maxh 0)
(setf maxz 0)
(setf extmon 0)

;; Loop over the zombie apocalypse
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
    (if (> hpop maxh) (setf maxh hpop))
    (if (> zpop maxz) (setf maxz zpop))
    (if (> hpop 0) (setf extmon i))
    ; Update human population
    (setf newhpop hpop)
    (setf newhpop (+ newhpop (* poprate hpop)))
    (setf newhpop (- newhpop (* (/ poprate compscl) hpop hpop)))
    (setf newhpop (- newhpop (* (- 1 winrate) zpop)))
    (setf newhpop (- newhpop (* infrate hpop)))
    ; Update zombie population
    (setf newzpop zpop)
    (if (> hpop 0.001)
      (setf newzpop (+ newzpop (* (- 1 merrate) (* (- 1 winrate) zpop)))))
    (if (> hpop 0.001)
      (setf newzpop (+ newzpop (* (- 1 merrate) (* infrate hpop)))))
    (setf newzpop (- newzpop (* erorate zpop)))
    (if (> hpop 0.001)
      (setf newzpop (- newzpop (* winrate zpop))))
    ; Prevent impossible populations
    (if (< newhpop 0.001) (setf newhpop 0))
    (if (< newzpop 0.001) (setf newzpop 0))
    ; Save populations
    (setf hpop newhpop)
    (setf zpop newzpop)
)

;; Print stats
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "Statistics:")
(format t "~%")
; Print human extiction date
(format t " Humans survived for ")
(princ extmon)
(format t " months")
(format t "~%")
; Print maximum number of humans
(format t " Largest number of humans (in thousands): ")
(princ maxh)
(format t "~%")
; Print maximum number of zombies
(format t " Largest number of Zombies (in thousands): ")
(princ maxz)
(format t "~%")

;; End of the world (and program)
(format t "~%")
(format t "####")
(format t "~%")
(format t "~%")
(format t "The end?")
(format t "~%")
(if (< hpop 0.001) (format t " Yes. Everyone is dead.~%"))
(format t "~%")
