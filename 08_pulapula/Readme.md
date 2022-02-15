# Pula pula & Movendo objetos entre duas listas

<!--TOC_BEGIN-->
- [Requisitos](#requisitos)
- [Shell](#shell)
- [Diagrama](#diagrama)
<!--TOC_END-->
![](figura.jpg)

Nosso objetivo no trabalho é modelar um gestor de pula pulas em um parquinho.

## Requisitos
- Inserir crianças na fila de espera do pula pula
- Mover a primeira criança da fila de espera do pula pula para dentro do pula pula.
- Mover a primeira criança que entrou no pula pula para o final da fila de espera.


## Shell
```bash
#__case unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
=> luana:3 livia:4 mario:5 => [ ]

#__case entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
=> luana:3 livia:4 => [ mario:5 ]
$enter
$show
=> luana:3 => [ livia:4 mario:5 ]

#__case saindo
$leave
$show
=> mario:5 luana:3 => [ livia:4 ]

#__case remove
$remove luana
$show
=> mario:5 => [ livia:4 ]
$remove livia
$show
=> mario:5 => [ ]
$end
```
***
