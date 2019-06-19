#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


String a;
int sx = 0, sy = 0, sz = 0;
int kierunekx = 1;
int kieruneky = 1;
int kierunekz = 1;
int kroki = 0;
bool wysylamy = 0;
void setup() {
  // put your setup code here, to run once:
  //krancowki
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

  //osie x.y.z
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, 0);

  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, kierunekx);

  pinMode(X_STEP_PIN, OUTPUT);
  //osy
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, 0);

  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, kieruneky);

  pinMode(Y_STEP_PIN, OUTPUT);
  //osz
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, 0);

  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, kierunekz);

  pinMode(Z_STEP_PIN, OUTPUT);

  Serial.begin(115200);

}

void loop() {
  //Serial.println(digitalRead(X_MAX_PIN));
  if ((digitalRead(X_MAX_PIN) == 0) && sx > 0)
  {
    digitalWrite(X_STEP_PIN, 1);
    sx--;
  }
  if ((digitalRead(Y_MAX_PIN) == 0) && sy > 0)
  {
    digitalWrite(Y_STEP_PIN, 1);
    sy--;
  }
  if ((digitalRead(Z_MAX_PIN) == 0) && sz > 0)
  {
    digitalWrite(Z_STEP_PIN, 1);
    sz--;

  }

  delay(1);
  digitalWrite(X_STEP_PIN, 0);
  digitalWrite(Y_STEP_PIN, 0);
  digitalWrite(Z_STEP_PIN, 0);
  delay(1);
  kroki = kroki + 1;
  if (kroki == 1000)
  { kroki = 0;
    // kierunek = !kierunek;
    digitalWrite(X_DIR_PIN, kierunekx);
    digitalWrite(Y_DIR_PIN, kieruneky);
    digitalWrite(Z_DIR_PIN, kierunekz);
  }
  while (Serial.available() > 0) //komunikacja
  {
    a = Serial.readStringUntil('\n');
    sscanf(a.c_str(), "a %d b %d c %d", &sx, &sy, &sz);
    wysylamy = 1;
    if (sx < 0) {
      kierunekx = 1;
      digitalWrite(X_DIR_PIN, kierunekx);
      sx = -sx;
    }
    else {
      kierunekx = 0;
      digitalWrite(X_DIR_PIN, kierunekx);
    }

    if (sy < 0) {
      kieruneky = 1;
      digitalWrite(Y_DIR_PIN, kieruneky);
      sy = -sy;
    }
    else {
      kieruneky = 0;
      digitalWrite(Y_DIR_PIN, kieruneky);
    }

    if (sz < 0) {
      kierunekz = 1;
      digitalWrite(Z_DIR_PIN, kierunekz);
      sz = -sz;
    }
    else {
      kierunekz = 0;
      digitalWrite(Z_DIR_PIN, kierunekz);
    }
    //Serial.println(sx);
    //Serial.println(sy);
    //Serial.println(sz);



  } // koniec komunikacji

  if (sx == 0 && sy == 0 && sz == 0 && wysylamy == 1)
  {
    Serial.println("OK");
    wysylamy = 0;
  }
}
