#define PIN_LED 7
unsigned int count, toggle;

void setup(){
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  toggle=0; 
  //토글이 0이라면, LED의 전원은 꺼짐
  while(!Serial){
    ;
  }
  //여기까지는 별 수정x
}
void loop(){
  toggle=0;
  digitalWrite(PIN_LED, toggle);

  delay(1000);
  toggle=0;
  //한번 키고 1초동안 유지

  //반목문 이용해서 다음 깜빡깜빡을 5번 시행 , 그 이후에는 무한반복문으로 끄기
  for(int i=0; i<5; i++){
    //현재 토글은 0
    toggle=0;
    //켜져 있었으니 먼저 끄고 다시 키기(이 과정을 1초동안 5번 시행해야 됨으로, 각 깜빡은 200ms 소요, 끄고 100 키고 100)
    digitalWrite(PIN_LED, toggle);
    delay(100);
    //끄고 100
    toggle=1;
    digitalWrite(PIN_LED, toggle);
    delay(100);
    //키고 100
  }

  toggle=1;
  //다시 토글을 0으로 설정 
  while(1){
    toggle=1;
    digitalWrite(PIN_LED, 1);
  }

  //무한반복 
}

  
  
  //입력값을 부정하는 것을 반환 

