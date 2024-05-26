void alternarCardRele(int idxRele, int status) {
  if (status != 1) {
    status = 0;
  }

  switch (idxRele) {
    case 0:
      cardRele0.update(status);
      break;
    case 1:
      cardRele1.update(status);
      break;
    case 2:
      cardRele2.update(status);
      break;
    case 3:
      cardRele3.update(status);
      break;
    case 4:
      cardRele4.update(status);
      break;
    case 5:
      cardRele5.update(status);
      break;
    case 6:
      cardRele6.update(status);
      break;
    case 7:
      cardRele7.update(status);
      break;
    default:
      status = 0;
      break;
  }

  dashboard.sendUpdates();
  
}

void alternarRele(int idxRele, int status) {

  if(idxRele >= sizeof(portasRele) | idxRele < 0) {
    idxRele = 0;
  }

  if(status == 0) {
    status = 2;
  }

  if(status == 1) {
    digitalWrite(portasRele[idxRele], HIGH);
  } else if (status == 2) {
    digitalWrite(portasRele[idxRele], LOW);
  }

  if(status == 1 | status == 2) {
    alternarCardRele(idxRele, status);
  }

}

void callBackBotoesRele() {

  /* Button card callback */
  cardRele0.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(0, value);
  });

  /* Button card callback */
  cardRele1.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(1, value);
  });

  /* Button card callback */
  cardRele2.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(2, value);
  });

  /* Button card callback */
  cardRele3.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(3, value);
  });

  /* Button card callback */
  cardRele4.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(4, value);
  });

  /* Button card callback */
  cardRele5.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(5, value);
  });

  /* Button card callback */
  cardRele6.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(6, value);
  });

  /* Button card callback */
  cardRele7.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    alternarRele(7, value);
  });

}