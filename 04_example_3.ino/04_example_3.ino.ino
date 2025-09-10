
 #define PIN_LED 13
 unsigned int count, toggle; 

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); 
  while (!Serial){
    ;
  }
  Serial.println("Hello world!");
  count = toggle =0;
  //토글이 0으로 설정되어 있음 : 0은 폴스 
  //
  digitalWrite(PIN_LED, toggle); //turn off LED.
  //아마 digitalwrite이 내장 매소드, (pin led, true or false )
  //false 면 전원 끄는거 true 면 키는거 

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(++count);
  //
  toggle = toggle_state(toggle);

  digitalWrite(PIN_LED, toggle); // update LED Status.
  delay(1000); // wait for 1,000 milliseconds 

}

int toggle_state(int toggle){
  if(toggle==1){
    toggle=0;

  }else{
    toggle=1;
  }  
  
  return toggle; 
  //입력값을 부정하는 것을 반환 
}
