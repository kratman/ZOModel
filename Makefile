##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

#NB: The installer for the lisp code uses Linux shell commands (sed,chmod).

### Compiler settings

CXX=g++
CXXFLAGS=-static -fopenmp -O3

### Regular expression (sed) for lisp

LISP=\/usr\/bin\/clisp

### Compile rules for users and devs

install:	title zombin zomlog compdone

clean:	title delbin compdone

### Rules for building various parts of the code

zombin:	
	@echo ""; \
	echo "### Compiling the ZOModel binary ###"; \
	mkdir -p bin
	$(CXX) $(CXXFLAGS) ./src/ZOModel.cpp -o ./bin/ZOModel

zomlog:	
	@echo ""; \
	echo "### Making the ZOMlog executable ###"; \
	mkdir -p bin; \
	echo " Copy lisp code..."; \
	cat ./src/ZOMlog.lisp > ./bin/ZOMlog; \
	echo " Set lisp interpreter..."; \
	sed -i 's/\;CLISP/\#\!$(LISP)/g' ./bin/ZOMlog; \
	echo " Purge garbage..."; \
	sed -i '/\;/d' ./bin/ZOMlog; \
	sed -i '/\#|/,/|\#/d' ./bin/ZOMlog; \
	sed -i '/^$$/d' ./bin/ZOMlog; \
	chmod a+x ./bin/ZOMlog; \
	echo " [Complete]"

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
