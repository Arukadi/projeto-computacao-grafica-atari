# Projeto Computação Gráfica

Projeto desenvolvido para a disciplina de Computação Gráfica. A ideia é desenvolver um jogo do Atari da escolha do grupo, no caso meu grupo escolhou o jogo X-Men.

O desenvolvimento utiliza OpenGL e o Freeglut.

Esse projeto está configurado para rodar no Visual Studio 2019.

# Observação

O Git não deixa subir DLLs e Libs portanto para executar esse projeto é necessário baixar o freeglut 3.0 no link: https://www.transmissionzero.co.uk/files/software/development/GLUT/freeglut-MSVC.zip

Após baixar esse arquivo basta descompactar e fazer as seguintes alterações.
* Na pasta freeglut/bin mover o freeglut.dll para freeglut/bin/win32
* Na pasta freeglut/lib mover o freeglut.lib para freeglut/lib/win32
* Mover a pasta freeglut para dependencies do projeto

# Integrantes

* Christian Meneghetti - RA 99855
* Gabriel Orpinelli - RA 101236
* Guilherme Hepfener - RA 99646
* João Ramos - RA 99571
* Wiliender Silva - RA 101027
