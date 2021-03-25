# Nome do projeto
PROJ_NAME=exec
 
# recebe todos arquivos com terminacao .cpp
C_SOURCE=$(wildcard *.cpp)
 
# recebe todos os arquivos com terminacao .h
H_SOURCE=$(wildcard *.h)
 
# indica todos arquivos .o necessarios baseado na existencia dos arquivos .o
OBJ=$(C_SOURCE:.c=.o)
 
# Compiler
CppC=g++

#flag necessaria para a execucao das funcoes da API pthreads
#LDFLAGS = -pthread

# Flags for compiler
CC_FLAGS=-Wall
 

# objetivo a ser compilado

all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CppC) -o $@ $^

#dependencias necessarias para obtencao do executavel 
%.o: %.c %.h
	$(CppC) -o $@ $<

#limpa todos os arquivos gerados pelo compilador 
clean:
	rm -rf *.o $(PROJ_NAME) *~