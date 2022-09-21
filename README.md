# projeto_final
Trabalho de conclusão de curso "Dispositivo eletrônico seletor de tampas plásticas para fins de reciclagem" (2021) do aluno Felipe Barbosa (eu) do curso de Engenharia Eletrônica no CEFET/RJ 

A proposta do trabalho era utilizar o sensor de cor TCS230 junto a uma placa UNO (equivalente do Arduino UNO), um motor de passo e um servomotor para realizar a triagem de tampas plásticas coloridas. As cores de tampa escolhidas foram vermelho, verde e azul.

![diagrama_sistema](https://user-images.githubusercontent.com/79610980/190881162-969d5415-d6cb-475c-ade8-cd94e7fe0dfb.jpg)

O diagrama de blocos acima representa a forma como o sistema atuava e foi utilizado para definir a organização do código do programa.

O código coordena o funcionamento dos componentes através de bibliotecas e funções. 

Para a atuação do servomotor foi utilizada uma biblioteca simples com comandos que permitiam sua movimentação em determinados graus de posição. 

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583233-d16bf983-3e21-4599-be15-cf5c2001d239.png" width=20% height=20% align="middle" />
</div>

<i>Servomotor</i>


No funcionamento do motor de passo foi utilizada uma função para acionar as fases de máximo potencial (fulll step), devido ao peso do sistema.

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583406-cd86feea-30fa-460e-9883-9fe61ced2089.png" width=20% height=20% align="middle" />
</div>

<i>Motor de passo</i>


Por fim, a atuação do sensor de cor foi definida também através de uma função que obtém valores RGB correspondentes a cor da tampa que está sendo captada, mapeia esses valores dentro de um intervalo e os analisa condicionalmente para definir a cor que está sendo lida.  

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583514-a9ffd6d3-4b93-4b5b-93cc-9878fb312ee5.png" width=20% height=20% align="middle" />
</div>

<i>TCS230</i>


O sistema funcionava com o motor de passo girando um disco de papelão que empurrava as tampas em um único sentido, com pequenos intervalos entre os movimentos.

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583943-68b37c26-a624-4c56-96b5-45ba73a9c527.png" width=20% height=20% align="middle" />
</div>

<i>Disco de posicionamento das tampas</i>


Durante esses intervalos, uma tampa se posicionava sob uma cabine onde o TCS230 fazia uma rápida leitura.

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583816-bd3fc048-bca2-4bd6-8883-e1085b379fa5.png" width=20% height=20% align="middle" />
</div>

<i>Cabine do TCS230</i>


A partir desta leitura, o grau de posição do servomotor (posicionado em um furo logo abaixo do disco) era definido para que o cano acoplado a este direcionasse a tampa para o recipiente correto. 

<div>
<img src="https://user-images.githubusercontent.com/79610980/191583670-5ed01437-876e-4f04-be0c-7e462509b88e.png" width=20% height=20% align="middle" />
</div>

<i>Cano acoplado ao servomotor com apoio</i>


Abaixo, uma imagem do projeto construído.

![image](https://user-images.githubusercontent.com/79610980/191581107-9a7bad7d-d0dd-48b0-acbe-da30b50d04e9.png)
