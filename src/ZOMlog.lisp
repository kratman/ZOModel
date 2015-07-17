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

; Loop over the zombie apocalypse


; End of the world (and program)
(format t "~%")
(format t "The end?~%")
(format t "~%")
