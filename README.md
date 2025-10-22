# Projeto Semáforo com Arduino – Documentação

## Introdução

Este projeto consiste na criação de um **semáforo automatizado** desenvolvido no **Tinkercad**, que simula o funcionamento de um semáforo real utilizando **LEDs** de cores verde, amarela e vermelha, além de um **LED RGB**. O sistema é controlado por um **Arduino Uno**, que muda as luzes de forma sequencial com diferentes tempos de espera entre cada cor.  

Assim que o Arduino é ligado, o semáforo inicia com a luz verde acesa e, após um intervalo de tempo configurado, alterna para amarelo e depois para vermelho. Esse ciclo se repete continuamente, simulando um cruzamento com controle eletrônico simples.  

<div align="center">
  <figure>
    <video controls width="640">
      <source src="assets/simulating-on-tinkercard.mp4" type="video/mp4">
      Seu navegador não suporta o elemento de vídeo. Baixe o vídeo aqui: <a href="assets/simulating-on-tinkercard.mp4">assets/simulating-on-tinkercard.mp4</a>.
    </video>
    <figcaption>Demonstração da simulação no Tinkercad.</figcaption>
  </figure>
</div>

---

## Componentes Utilizados

O projeto foi construído com **6 componentes** distintos, listados abaixo:

| Componente  | Quantidade | Função no circuito |
|--------------|-------------|--------------------|
| Arduino Uno | 1 | Controla toda a lógica e os sinais enviados aos LEDs |
| LED Verde | 1 | Indica que a passagem está liberada |
| LED Amarelo | 1 | Indica atenção ou transição entre estados |
| LED Vermelho | 1 | Indica parada obrigatória |
| LED RGB | 1 | Usado como reforço visual e para testar mistura de cores no controle de pinos |
| Resistor 330 Ω | 1 | Limita a corrente elétrica, protegendo os LEDs |

Os pinos utilizados foram configurados da seguinte forma:
- Pino **3**: LED verde  
- Pino **6**: LED amarelo (canal do LED amarelo) 
- Pino **7**: LED amarelo (canal do LED RGB)  
- Pino **11**: LED vermelho  

---

## Conceitos de Programação Orientada a Objetos (P.O.O.)

O código implementa **conceitos fundamentais de P.O.O.** através da criação da classe `Semaforo`. Essa classe encapsula atributos e comportamentos relacionados ao ciclo do semáforo, tornando o código mais organizado, reutilizável e modular.  

Os principais conceitos aplicados são:

- **Encapsulamento:**  
  Os dados internos (`availableColors` e `currentColorIndex`) estão protegidos dentro da classe. O acesso e modificação desses valores ocorrem apenas por meio de métodos públicos (`getColor()` e `changeColor()`).

- **Abstração:**  
  O funcionamento interno do semáforo (índices de cor, verificação e impressão no Serial) é abstraído na classe, simplificando o uso para o programador — basta chamar os métodos para mudar ou consultar o estado.

- **Instanciação de objeto:**  
  O objeto `semaforo` é criado a partir da classe `Semaforo`. Ele representa uma instância funcional do componente lógico, responsável por controlar o estado atual de cor do semáforo durante o loop.

Esses princípios tornam o código mais limpo, modular e fácil de expandir. Por exemplo, seria simples adicionar métodos para controlar o LED RGB ou ajustar o tempo de delay dinamicamente sem alterar a estrutura principal.  

---

**Observação:**  
Esta atividade foi desenvolvida integralmente no **Tinkercad**, sem o uso de ferramentas de IA. Foram consultadas apenas documentações básicas do **Wokwi** e exemplos sobre o uso do **Serial Monitor**. Em contrapartida, esta documentação foi realizada com ajuda de IA, mas adaptada por mim.