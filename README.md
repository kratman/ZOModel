
[//]: # (Mixture of GitHub markdown and HTML. HTML is needed for formatting.)

***
<div align=center> <h2>
ZOModel: Zombie Outbreak Modeling Software
</h2> </div>

<div align=center> <h4> By: Eric G. Kratz </h4> </div>

***

### Introduction

This is a simple program written to simulate a zombie outbreak over
time. Currently, three different models are available in this repository.
ZOMOdds performs a back of the envelope calculation of the number of zombies
a human population needs to eliminate. ZOModel is designed to simulate small
populations of humans and zombies (e.g. an infested town). ZOMLog is designed
for large scale populations (e.g. infested countries and planets).

### ZOModelApp

An Android application and desktop GUI for simulating zombie outbreaks.
The graphical functionality is still a work in progress.

### ZOMOdds: Approximate number of zombies each survivor must eliminate

#### Input

ZOMOdds requires two command line arguments:
```
-Percent of the population that was zombified
-Percent of the survivors that can fight
```

#### Rules of the game

ZOMOdds performs a back of the envelope calculation to estimate the number
of zombies each survivor has to eliminate.

### VOMSpread: Approximate number of days until the population is entirely vampires

VOMSpread requires two command line arguments:
```
-Number of days a vampire goes without feeding
-Fraction of victims which die before turning into vampires
```

#### Rules of the game

VOMSpread performs a back of the envelope calculation to estimate the number
of days until vampires turn all humans into vampires.

### ZOModel: Model for zombie outbreaks in small populations

#### Input

ZOModel requests only a handful of parameters to track the zombie outbreak:
```
-Population: total world population
-Zombies: the initial number of zombies when the outbreak starts
-Win prob: probability that a human kills a zombie one-on-one
-Eaten prob: probability that a zombie consumes a human (i.e. no-reanimation)
-Bite prob: probability that a "victorious" human was bitten
-Mercy prob: probability that a bitten human is prevented from reanimating
-Infection prob: probability that a human starts out infected
```

#### Rules of the game

ZOModel assumes that humans are on the defensive while the zombies are the
aggressors.

Each day every zombie attacks a single human one-on-one. If the zombie kills
the human, then the human either reanimates immediately or is eaten by the
zombie (which prevents reanimation). If the human wins, the zombie is
eliminated. However, not all humans escape unscathed. If a human leaves the
fight will a little less flesh, then the human will survive one more day
before turning into a zombie. Since humans are compassionate
[citation needed], there is a chance that the victim is mercifully prevented
from reanimating after death.

The simulation continues until either all humans or all zombies are dead.

### ZOMLog: Zombie logistics map for large scale outbreaks

#### Input

ZOMLog requests only a handful of parameters to track the zombie outbreak:
```
-hpop => Initial human population
-zpop => Initial zombie population
-years => Simulation time in years
-poprate => Yearly population growth rate
-winrate => Probability that a human beats a zombie
-infrate => Yearly infection rate
-merrate => Probability that the infected are prevented from turning
-erorate => Yearly rate of zombie destruction by natural forces
```
One additional parameter (compscl) is set inside the source code. This
parameter controls the amount of human-human cooperation. It is currently
tuned to allow the world to support 10 billion humans.

The logistics map propagates the following equations:
```
  hpop = hpop + poprate*hpop - poprate*hpop*hpop/compscl
         - (1-winrate)*zpop - infrate*hpop

  zpop = zpop + (1-merrate)*((1-winrate)*zpop+infrate*hpop)
         - erorate*zpop - winrate*zpop
```

Additional controls are added to avoid impossible populations and growth
rates.

#### Rules of the game

While ZOModel favors the zombies by making humans defensive, ZOMLog favors
the humans by including a population growth rate. The logistics model also
includes human-human, human-nature, and zombie-nature interactions. The goal
of ZOMLog is to simulate the coexistence of humans and zombies.

Each month the populations of humans and zombies are updated. The
simulation continues until the time runs out or both populations reach
zero.

