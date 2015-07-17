##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

### Compiler settings

CXX=g++
CXXFLAGS=-static -fopenmp -O3

### Regular expression (sed) for clisp
LISP=\/usr\/bin\/clisp

### Compile rules for users and devs

install:	title zombin zomlog compdone

clean:	title delbin compdone

### Rules for building various parts of the code

zombin:	
	@echo ""; \
	echo "### Compiling the ZOModel binary ###"
	$(CXX) $(CXXFLAGS) ./src/ZOModel.cpp -o ZOModel

zomlog:	
	@echo ""; \
	echo "### Making the ZOMlog executable ###"; \
	cat ./src/ZOMlog.lisp > ZOMlog; \
	sed -i 's/\;CLISP/\#\!$(LISP)/g' ZOMlog; \
	chmod a+x ZOMlog; \
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
	rm -f ZOModel ZOMlog
