# EstruturaDeDados2

## Mudança para o sistema de listas em Transportes
Neste programa, foi realizada uma mudança significativa no sistema de armazenamento e manipulação dos transportes. Anteriormente, utilizava-se um sistema baseado em arrays para armazenar os dados dos transportes. No entanto, migrei para um sistema de listas encadeadas para obter vantagens adicionais em termos de flexibilidade e eficiência.

## Motivação
A mudança para o sistema de listas em Transportes foi motivada pelos seguintes fatores:

#### Inserção e remoção dinâmicas: Com o sistema de listas, podemos inserir e remover transportes de forma dinâmica, sem a necessidade de definir previamente um tamanho fixo para o array. Isso nos proporciona mais flexibilidade ao lidar com um número variável de transportes.

#### Eficiência em operações de adição e remoção: As listas encadeadas são mais eficientes do que os arrays quando se trata de adicionar ou remover elementos no meio da estrutura. Com o sistema de listas, podemos adicionar e remover transportes em qualquer posição da lista de forma eficiente, sem a necessidade de reorganizar todos os elementos.

#### Utilização otimizada de memória: Com o sistema de listas, a memória é alocada de forma dinâmica à medida que novos transportes são adicionados, evitando o desperdício de espaço em memória. Além disso, a capacidade da lista pode ser facilmente expandida conforme necessário.

## Alterações realizadas
As seguintes alterações foram feitas para implementar o sistema de listas em Transportes:

A estrutura TransporteList foi introduzida para representar cada nó da lista encadeada. Essa estrutura contém os campos necessários para armazenar os dados do transporte e ponteiros para o próximo e o anterior elementos da lista.

A função AddTransporte foi modificada para lidar com a adição de transportes na lista encadeada. Agora, ao adicionar um novo transporte, o sistema cria um novo nó TransporteList, preenche-o com os dados do transporte e o insere corretamente na lista.

A função RemoverTransporte foi ajustada para remover um transporte específico da lista encadeada. Ao remover um transporte, o sistema atualiza corretamente os ponteiros dos nós adjacentes para manter a integridade da lista.

A função AlterarTransporte foi adaptada para permitir a alteração dos dados de um transporte existente na lista encadeada. Agora, o sistema percorre a lista procurando o transporte pelo seu ID e atualiza os dados conforme necessário.

## Benefícios do novo sistema
A mudança para o sistema de listas em Transportes traz os seguintes benefícios:

Flexibilidade: Agora é possível adicionar e remover transportes de forma dinâmica, acomodando um número variável de elementos na lista.

Eficiência: As operações de adição, remoção e alteração são realizadas de forma eficiente, sem a necessidade de reorganizar todos os elementos da lista.

Utilização otimizada de memória: A alocação dinâmica de memória evita o desperdício de espaço e permite a expansão da lista conforme necessário.

Maior facilidade de manutenção: O sistema de listas é mais modular e flexível, facilitando a manutenção e extensão do código.

## Considerações finais
A mudança para o sistema de listas em Transportes foi uma escolha estratégica para melhorar a eficiência e flexibilidade do programa. Com essa nova abordagem, obtenho um sistema mais robusto e escalável para lidar com a gestão de transportes.
