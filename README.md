# Exercício de OpenGL: Cenário com Alternância de Dia e Noite

Programa em C++ utilizando OpenGL que desenhe um cenário e alterne as cores do céu e outros elementos para representar dia e noite a cada 5 segundos. Neste exercício, você irá criar um cenário que inclui um chão, uma casa, árvores, sol, lua e estrelas. A cor do céu deve alternar entre azul claro (representando o
dia) e azul escuro (representando a noite) a cada 5 segundos. Alguns elementos devem ser exibidos somente no dia ou noite, como sul, lua a estrelas. Você é livre para adicionar mais elementos.

# Passos para Implementação:

•Configure o ambiente de desenvolvimento no Visual Studio para utilizar OpenGL e GLUT.
•Crie um novo projeto em C++.
•Inicialize a biblioteca GLUT.
•Configure o modo de exibição para utilizar um buffer duplo e cores RGB.
•Defina o tamanho da janela e o título.
•Implemente uma função DesenhaCena que desenhe o chão, uma casa, árvores, um sol e estrelas.
•Utilize glBegin e glEnd para desenhar os elementos do cenário.
•Defina as cores apropriadas para cada elemento (por exemplo, verde para o chão e as árvores, marrom para a casa, amarelo para o sol, branco para as estrelas).
•Crie variáveis para armazenar as cores do céu durante o dia e a noite.
•Implemente uma função TrocaCor que alterne entre as cores do dia e da noite.
•Utilize glutTimerFunc para chamar a função TrocaCor a cada 5 segundos.
•Configure a função de exibição (glutDisplayFunc) para chamar DesenhaCena.
•Inicialize a cor de fundo da janela com a cor do céu atual.
•Inicie o loop principal do GLUT (glutMainLoop).

# Pontos importantes:
• Certifique-se de que todas as bibliotecas necessárias estão corretamente instaladas e configuradas.
