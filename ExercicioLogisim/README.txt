Nome: Matheus de Mello Santos Oliveira
NUSP: 8642821

A tabela verdade dos 16 numeros de 4 bits, colocando como verdade
somente quando e primo gera atravez da soma de produtos a seguinte
expressao booleana:

O numero binario e representado da forma dcba, onde d e o bit mais
significativo e a o menos. Por exemplo, 4 nessa notacao seria: 
0100, onde d = 0, c = 1, b = 0 e a = 0.

(~d~cb~a) + (~d~cba) + (~dc~ba) + (~dcba) + (d~cba) + (dc~ba)
que pode ser reduzida atravez de Mapa de Karnaugh para:
(ab~c) + (ab~d) + (a~bc) + (b~c~d)

Que gera o circuito em anexo, o isPrime(4bits).


