int led = 13;
char str;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    str = Serial.read();
  
  switch(str) {
    case 'a' : msa(); break;
    case 'b' : msb(); break;
    case 'c' : msc(); break;
    case 'd' : msd(); break;
    case 'e' : mse(); break;
    case 'f' : msf(); break;
    case 'g' : msg(); break;
    case 'h' : msh(); break;
    case 'i' : msi(); break;
    case 'j' : msj(); break;
    case 'k' : msk(); break;
    case 'l' : msl(); break;
    case 'm' : msm(); break;
    case 'n' : msn(); break;
    case 'o' : mso(); break;
    case 'p' : msp(); break;
    case 'q' : msq(); break;
    case 'r' : msr(); break;
    case 's' : mss(); break;
    case 't' : mst(); break;
    case 'u' : msu(); break;
    case 'v' : msv(); break;
    case 'w' : msw(); break;
    case 'x' : msx(); break;
    case 'y' : msy(); break;
    case 'z' : msz(); break;
    
    default :  break;
  }
  }
}


void chang(){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
}

void duan(){
  digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW);
    delay(1000);
}


void msa(){
  duan();
  chang();
}


void msb(){
  chang();
  duan();
  duan();
  duan();
}


void msc(){
  chang();
  duan();
  chang();
  duan();
}

void msd(){
  chang();
  duan();
  duan();
}

void mse(){
  duan();
}

void msf(){
  duan();
  duan();
  chang();
  duan();
}

void msg(){
  chang();
  chang();
  duan();
}

void msh(){
  for(int i=0;i<4;i++){
    duan();
  }
}


void msi(){
  duan();
  duan();

}

void msj(){
  duan();
  chang();
  chang();
  chang();
}

void msk(){
  chang();
  duan();
  chang();
}

void msl(){
  duan();
  chang();
  duan();
  duan();
}

void msm(){
  chang();
  chang();
}

void msn(){
  chang();
  duan();
}

void mso(){
  chang();
  chang();
  chang();
}

void msp(){
  duan();
  chang();
  chang();
  duan();
}


void msq(){
  chang();
  chang();
  duan();
  chang();
}

void msr(){
  duan();
  chang();
  duan();
}

void mss(){
  duan();
  duan();
  duan();
}

void mst(){
  chang();
}

void msu(){
  duan();
  duan();
  chang();
}


void msv(){
  for(int i=0;i<3;i++){
    duan();
  }
  chang();

}

void msw(){
  duan();
  chang();
  chang();
}


void msx(){
  chang();
  duan();
  duan();
  chang();
}

void msy(){
  chang();
  duan();
  chang();
  chang();
}

void msz(){
  chang();
  chang();
  duan();
  duan();
}
