# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -O2

# Nome do programa
TARGET = rsa_crack

# Regras de compilação
all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -lm

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para executar o programa
run: all
	./$(TARGET)
