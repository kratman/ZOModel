##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

#NB: The installer for the lisp and JavaScript source code uses Linux shell
#    commands (sed,chmod).

### C/C++ compiler settings

CXX=g++
CXXFLAGS=-static -fopenmp -O3
LDFLAGS=-I./src/ -I./include/

### Java compiler settings

JAVAC=javac
JAVAFLAGS=-d ./bin/

### Regular expression (sed) for lisp and JavaScript

LISP=\/usr\/bin\/clisp
JVASCPT=\/usr\/bin\/nodejs

### Compile rules for users and devs

install:	title zomodd vomspread zombin zomlog zomapp compdone

clean:	title delbin compdone

### Combine settings

FLAGSBIN=$(CXXFLAGS) $(LDFLAGS)

### Rules for building various parts of the code

zomodd:	
	@echo ""; \
	echo "### Making the ZOMOdds executable ###"; \
	mkdir -p bin; \
	echo " Copying JavaScript code..."; \
	cat ./src/ZOMOdds.js > ./bin/ZOMOdds; \
	echo " Setting JS interpreter..."; \
	sed -i 's/\/\/JAVASCRIPT/\#\!$(JVASCPT)/g' ./bin/ZOMOdds; \
	echo " Purging garbage..."; \
	sed -i '/\/\//d' ./bin/ZOMOdds; \
	sed -i '/\/\*/,/\*\//d' ./bin/ZOMOdds; \
	sed -i '/^$$/d' ./bin/ZOMOdds; \
	chmod a+x ./bin/ZOMOdds; \
	echo " [Complete]"

vomspread: 
	@echo ""; \
	echo "### Making the VOMSpread executable ###"; \
	mkdir -p bin; \
	echo " Copying JavaScript code..."; \
	cat ./src/VOMSpread.js > ./bin/VOMSpread; \
	echo " Setting JS interpreter..."; \
	sed -i 's/\/\/JAVASCRIPT/\#\!$(JVASCPT)/g' ./bin/VOMSpread; \
	echo " Purging garbage..."; \
	sed -i '/\/\//d' ./bin/VOMSpread; \
	sed -i '/\/\*/,/\*\//d' ./bin/VOMSpread; \
	sed -i '/^$$/d' ./bin/VOMSpread; \
	chmod a+x ./bin/VOMSpread; \
	echo " [Complete]"

zombin:	
	@echo ""; \
	echo "### Compiling the ZOModel binary ###"; \
	mkdir -p bin
	$(CXX) ./src/ZOModel.cpp -o ./bin/ZOModel $(FLAGSBIN)

zomlog:	
	@echo ""; \
	echo "### Making the ZOMlog executable ###"; \
	mkdir -p bin; \
	echo " Copying lisp code..."; \
	cat ./src/ZOMlog.lisp > ./bin/ZOMlog; \
	echo " Setting lisp interpreter..."; \
	sed -i 's/\;CLISP/\#\!$(LISP)/g' ./bin/ZOMlog; \
	echo " Purging garbage..."; \
	sed -i '/\;/d' ./bin/ZOMlog; \
	sed -i '/\#|/,/|\#/d' ./bin/ZOMlog; \
	sed -i '/^$$/d' ./bin/ZOMlog; \
	chmod a+x ./bin/ZOMlog; \
	echo " [Complete]"

zomapp:	
	@echo ""; \
	echo "### Compiling the ZOModelApp ###"
	$(JAVAC) ./src/ZOModelApp.java $(JAVAFLAGS)

title:	
	@echo ""; \
	echo "#####################################"; \
	echo "#                                   #"; \
	echo "# ZOModel: Zombie Outbreak Modeling #"; \
	echo "#                                   #"; \
	echo "#####################################"; \
	echo ""

compdone:	
	@echo ""; \
	echo "Done."; \
	echo ""

delbin:	
	@echo ""; \
	echo '     ___'; \
	echo '    |_  |'; \
	echo '      \ \'; \
	echo '      |\ \'; \
	echo '      | \ \'; \
	echo '      \  \ \'; \
	echo '       \  \ \'; \
	echo '        \  \ \       <wrrr vroooom wrrr> '; \
	echo '         \__\ \________'; \
	echo '             |_________\'; \
	echo '             |__________|  ..,  ,.,. .,.,, ,..'; \
	echo ""; \
	echo ""; \
	echo "Removing executables..."; \
	rm -rf ./bin
