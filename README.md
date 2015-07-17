
[//]: # (Mixture of GitHub markdown and HTML. HTML is needed for formatting.)

***
<div align=center> <h2>
ZOModel: Zombie Outbreak Modeling Software
</h2> </div>

<div align=center> <h4> By: Eric G. Kratz </h4> </div>

***

### Introduction

This is a simple set of programs I wrote to simulate a zombie outbreak over
time. This was just for fun and is not a realistic model. 

Required packages:
```
 ZOModel: OpenMP
 ZOMlog: clisp
```

To install,
```
user:$ make install
```

### ZOModel

#### Input

ZOModel requests only a handful of parameters to track the zombie outbreak:
```
+Population: total world population
+Zombies: the initial number of zombies when the outbreak starts
+Win prob: probability that a human kills a zombie one-on-one
+Eaten prob: probability that a zombie consumes a human (i.e. no-reanimation)
+Bite prob: probability that a "victorious" human was bitten
+Mercy prob: probability that a bitten human is prevented from reanimating
+Infection prob: probability that a human starts out infected
```

#### Rules of the game

ZOModel assumes that humans are on the defensive while the zombies are the
aggressors.

Each day every zombie attacks a single human one-on-one. If the zombie kills
the human, then the human either reanimates immediately or is eaten by the
zombie (which prevents reanimation). If the human wins, the zombie is
eliminated. However, not all humans escape unscathed. If a human leaves the
fight will a little less flesh, then the human will survive one more day
before turning into a zombie. Since humans are compasionate [citation needed],
there is a chance that the victim is mercifully prevented from reanimating
after death.

The simulation continues until either all humans or all zombies are dead.

#### Running a simulation

ZOModel prompts users for input at run time. Example output is shown below.

```
user:$ ./ZOModel

###############################################################################
#                                                                             #
#                      ZOModel: Zombie Outbreak Modeling                      #
#                                                                             #
###############################################################################


Initial population:
Initial zombies:
Prob. that a human will win a fight:
Prob. that a zombie is super-hungry:
Prob. that a human gets bitten:
Mercy probability:
Percent infected:
```

### ZOMlog: Zombie logistics map

