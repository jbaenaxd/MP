# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src


all : $(BIN)/CopiaTodo $(BIN)/CopiaExceptoVocales $(BIN)/CuentaCaracteres \
      $(BIN)/CuentaLineasNoVacias  $(BIN)/MuestraLineasNoVacias 

#ejecutables
$(BIN)/CopiaTodo : $(OBJ)/CopiaTodo.o 
	g++ -g -o $(BIN)/CopiaTodo $(OBJ)/CopiaTodo.o -std=c++11

$(BIN)/CopiaExceptoVocales : $(OBJ)/CopiaExceptoVocales.o 
	g++ -g -o $(BIN)/CopiaExceptoVocales $(OBJ)/CopiaExceptoVocales.o -std=c++11

$(BIN)/CuentaCaracteres : $(OBJ)/CuentaCaracteres.o 
	g++ -g -o $(BIN)/CuentaCaracteres $(OBJ)/CuentaCaracteres.o -std=c++11
       
$(BIN)/CuentaLineasNoVacias : $(OBJ)/CuentaLineasNoVacias.o 
	g++ -g -o $(BIN)/CuentaLineasNoVacias $(OBJ)/CuentaLineasNoVacias.o \
	-std=c++11

$(BIN)/MuestraLineasNoVacias : $(OBJ)/MuestraLineasNoVacias.o 
	g++ -g -o $(BIN)/MuestraLineasNoVacias $(OBJ)/MuestraLineasNoVacias.o \
	-std=c++11
	   
#objetos del main
$(OBJ)/CopiaTodo.o : $(SRC)/CopiaTodo.cpp
	g++ -g -c -o $(OBJ)/CopiaTodo.o $(SRC)/CopiaTodo.cpp -std=c++11

$(OBJ)/CopiaExceptoVocales.o : $(SRC)/CopiaExceptoVocales.cpp
	g++ -g -c -o $(OBJ)/CopiaExceptoVocales.o $(SRC)/CopiaExceptoVocales.cpp \
    -std=c++11

$(OBJ)/CuentaCaracteres.o : $(SRC)/CuentaCaracteres.cpp
	g++ -g -c -o $(OBJ)/CuentaCaracteres.o $(SRC)/CuentaCaracteres.cpp \
	-std=c++11

$(OBJ)/CuentaLineasNoVacias.o : $(SRC)/CuentaLineasNoVacias.cpp
	g++ -g -c -o $(OBJ)/CuentaLineasNoVacias.o $(SRC)/CuentaLineasNoVacias.cpp \
	-std=c++11

$(OBJ)/MuestraLineasNoVacias.o : $(SRC)/MuestraLineasNoVacias.cpp
	g++ -g -c -o $(OBJ)/MuestraLineasNoVacias.o $(SRC)/MuestraLineasNoVacias.cpp \
	-std=c++11
    
cleanlib :
	@echo Borrando librerias
	@-rm $(LIB)/*.a

clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o
mr-proper : clean cleanlib

	@echo Borrando ejecutables
	@-rm $(BIN)/*
