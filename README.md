
# Algoritmos e estruturas de dados I

  O primeiro trabalho prático da disciplina de Algoritmos e Estruturas de Dados 1 tem como objetivo o desenvolvimento de um sistema de gerenciamento de tempo, com o 
  intuito de solidificar o entendimento de conceitos relacionados a disciplina, mais especificamente, sobre TAD’s e alocação dinâmica, por meio da implementação de   
  listas encadeadas. O sistema possibilita que o usuário crie e gerencie uma agenda de compromissos e uma lista de contatos digital para cada professor cadastrado. 
  O mesmo foi elaborado na linguagem C, devendo ser compilado preferencialmente usando o compilador GCC 9.2.0 e utilizando um sistema Linux com kernel 5.8.0

## Deselvolvimento

  - O trabalho foi dividido em várias partes para facilitar tanto o desenvolvimento quanto
  o entendimento do código. Algumas decisões tomadas para a criação do código foram
  fundamentais para o resultado obtido.
  
  - Primeiramente, optamos por não colocar a lista de professores dentro do TAD
  agenda. Isso se deu porque a nossa intenção era a de que cada agenda estivesse
  associada apenas a um único professor afim de manter a proporção 1:1, uma vez que, caso
  existisse uma lista de professores dentro da agenda, essa proporção não seria alcançada.
  Para criar um vínculo entre professor e agenda as duas compartilham o mesmo ID, este
  sendo único para um par professor/agenda. Já os outros TAD’s ficam todos contidos no TAD
  agenda, pois entre eles e a agenda se estabelece uma proporção 1:N.
