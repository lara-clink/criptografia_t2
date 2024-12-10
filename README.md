# RSA Cracking Program

## Autores
- **Vinícius Oliveira dos Santos**
- **Lara Ricalde Machado Clink**

## Descrição do Trabalho
Este programa implementa um algoritmo para determinar a chave privada (‘d’) no sistema de criptografia RSA. O programa assume que os fatores primos de ‘n’ (‘p’ e ‘q’) são menores ou iguais a 1023 (10 bits). Com base nos valores fornecidos de ‘e’ e ‘n’ (chave pública), o programa:

1. **Fatora ‘n’**: Encontra os valores de ‘p’ e ‘q’ que são primos e satisfazem a condição ‘n = p \* q’.
2. **Calcula o valor de φ(n)**: φ(n) = (p-1) \* (q-1).
3. **Verifica coprimalidade**: Garante que ‘e’ e φ(n) sejam coprimos.
4. **Determina a chave privada (‘d’)**: Calcula o inverso modular de ‘e’ em relação a φ(n).

## Requisitos do Programa
- Compilador C compatível (GCC ou similar).
- Biblioteca padrão C (<stdio.h>, <math.h>, <stdlib.h>).

## Como Executar
1. Compile o programa com o comando:
   ```bash
   gcc -o rsa_crack rsa_crack.c -lm
   ```
2. Execute o programa:
   ```bash
   ./rsa_crack
   ```
3. Insira os valores de entrada solicitados:
   - **e**: Exponente público.
   - **n**: Produto dos fatores primos (p \* q).

O programa irá calcular e exibir os seguintes resultados:
- Os fatores primos ‘p’ e ‘q’ encontrados.
- O valor da chave privada ‘d’.

## Exemplo de Execução
### Entrada
```
Digite o valor de e (chave pública): 17
Digite o valor de n (chave pública): 3233
```

### Saída
```
Fatores encontrados: p = 53, q = 61
Chave privada d: 2753
```

## Observações
- O programa é projetado para trabalhar apenas com chaves onde ‘p’ e ‘q’ têm no máximo 10 bits (menores ou iguais a 1023).
- Se ‘n’ não puder ser fatorado usando as condições acima, o programa retorna um erro.
