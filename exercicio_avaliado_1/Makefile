# Nome do projeto
PROJ_NAME=exec
 
# recebe todos arquivos com terminacao .cpp
C_SOURCE=$(wildcard *.cpp)
 
# recebe todos os arquivos com terminacao .h
H_SOURCE=$(wildcard *.h)
 
# indica todos arquivos .o necessarios baseado na existencia dos arquivos .c
OBJ=$(C_SOURCE:.c=.o)
 
# Compilador
CC=g++

# Flags do compilador
CC_FLAGS=-Wall
 
# objetivo a ser compilado

all: $(PROJ_NAME)
#compila e linkedita 
$(PROJ_NAME): $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^

#limpa todos os arquivos gerados pelo compilador 
clean:
	rm -rf *.o $(PROJ_NAME) *~