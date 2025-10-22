class Semaforo {
  const char* availableColors[3] = { "GREEN", "YELLOW", "RED" };
  int currentColorIndex = 0;

  public:
    Semaforo() {}
    
    int getColor(const bool canPrint) const {
      if(canPrint) {
      	Serial.print("Current color index: ");
      	Serial.println(Semaforo::currentColorIndex);
      
      	Serial.print("Current color name: ");
      	Serial.println(Semaforo::availableColors[Semaforo::currentColorIndex]);
      }
      
      return Semaforo::currentColorIndex;
    }
    
    void changeColor() {
      currentColorIndex++;
      if (currentColorIndex >= 3) currentColorIndex = 0;
    }
};

Semaforo semaforo;
int currentColorIndex = semaforo.getColor(false);
int currentDelay = 7000;

void setup() {
  Serial.begin(9600);
  
  pinMode(11, OUTPUT); // red
  pinMode(3, OUTPUT); // green
  pinMode(7, OUTPUT); // yellow (saida para led rgb)
  pinMode(6, OUTPUT); // yellow (saida para led comum)

}

void loop() {
  currentColorIndex = semaforo.getColor(true);
  
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(3, LOW);
  
  // muda a cor do semaforo no led
  switch(currentColorIndex) {
    case 2:
	    // vermelho
    	digitalWrite(11, HIGH);
    	currentDelay = 5000;
    	break;
    case 1:
    	// verde e vermelho pra fazer o amarelo
    	digitalWrite(11, HIGH);
    	digitalWrite(3, HIGH);
    	digitalWrite(6, HIGH);
    	currentDelay = 3000;
    	break;
    case 0:
    default:
    	// verde
    	digitalWrite(3, HIGH);
    	currentDelay = 7000;
    	break;
  };

  // muda a cor do semaforo na classe
  semaforo.changeColor();
  
  Serial.print("Current delay to next color: ");
  Serial.print(currentDelay);
  Serial.println("ms\n");
  
  delay(currentDelay);
}

/*
* Observações:
* Esta atividade foi feita no Tinkercad
*
* Estou muito feliz em dizer que não usei IA de forma alguma nesta atividade,
* apenas consultei a documentação do wokwi em alguns momentos e pesquisei
* sobre como usar o Serial
*/