====================================
João Francisco Lino Daniel - 7578279
Mateus dos Anjos           - 9298191 
Matheus Oliveira           - 8642821
Victor Sprengel            - 9298002
====================================


Nesse arquivo consta como segmentamos a "main" de nosso circuito (que é basica-
mente o HIPO) e o que cada segmento se propõe a fazer. Esse foi um bom jeito de
dividir o que precisava ser feito (de modo a ser feito passo a passo) e também
de entender o circuito como um todo, quando já completo.

-- Fase Converter --

	Nessa fase alteramos o andamento do clock, dividindo a frequencia de
andamento pela metade, pois em algumas operações precisamos de tempo “dobrado”.


-- PC --

	Recebe em sua etrada de endereço inicial END-I. Em Load recebe JMP, pois
essa função necessita que seja carregada a memória e em Count recebe ~JMP, assim
só pularemos para o endereço seguinte da RAM. Em clock entra C++ (clock
“dobrado”). Clear recebe um OU entre Overflow e STP  a saída do PC será END
(novo endereço da memória).
	O que este segmento de nossa arquitetura faz é escolher qual posição está
sendo apontada pelo PC, e ajustá-la após um dos jumps. Além disso, força uma 
volta para a posição 0 quando STP for requisitado.


-- ACC --

	Data do acumulador receberá DATA ou RESUL, dependendo do resultado do MUX
16x1. MUX 16x1 recebe  DATA e RESUL  em suas entradas A e B, a entrada controle
receberá ao resultado da operação OU entre as operações REM, DIV, MUL, SUB, ADD
para verificarmos se será utilizado DATA ou RESULT no ACC. Enable do ACC receberá
o resultado de OU entre as operações citadas acima  e LDA.  A saída será o valor
corrente do registrador (IN).
	Aqui tratamos do conteúdo do acumulador. No geral, ele estará travado para
nunca receber dados. No caso de uma operação aritmética ou um LOAD, os MUX's
selecionam qual dado deve entrar nele.


-- RAM --

	A posição acessada na memória será dada a partir de um Mux 8x1. Neste multiplexer
END-I e END serão selecionados dependendo da operação a ser executada, uma vez
que o control do mux 8x1 é dado por um OU das operações que necessitam de END.
A entrada da RAM receberá a saída de mux 16x1 que selecionará entra Ent (entrada
dada no início do programa) ou IN (valor corrente do registrador) o controle
dessa seleção é dado pela operação INN.
	A saída da RAM (DATA) será o valor carregado a partir do endereço corrente 
da RAM.


-- In/Out --

	a Entrada (ENT) e saída(Saida) é arazenada em 16 bits cada. Desta forma a
entrada juntamente com a saida do ACC passam por um MUX 16x1 para escolhermos
qual valor e endereço será utilizado nas operações que seguem. Para Saída será
mostrado o valor corrente do registrador quando for requisitado.


-- CTRL e ALU --

	Nossa implementação "esconde" a ALU dentro do Controlador. Na parte externa
da arquitetura, o controlador recebe o conteúdo do IR (Instruction Register), 
conteúdo da RAM e o conteúdo do acumALUdor. Usando estas coisas, o controlador
fornece as seguintes informações: (i) Qual operação foi identificada e está
sendo realizada; (ii) A parte do endereço dos 16bits de cada instrução;
(iii) O resultado da operação aritmética realizada, se há alguma. 	


-- Dentro do CTRL --

	Dentro do CTRL temos uma parte que separa os 16 bits da RAM em (operação)
e (endereço), uma parte que identifica qual operação está sendo requisitada
e uma parte que identifica se alguma operação da ULA está sendo requisitada.
	A ALU está aqui dentro e o resultado da operação requisitada é uma das saídas
do controlador.


-- ALU --

	A ALU é composta por circuitos combinatórios das 5 operações e dois multi-
plexers. Um deles (16x3) seleciona qual resultado deve ser mandado para a saída
e o outro (1x3) seleciona adequadamente qual informação de overflow será usada
para decidir se houve overflow.

