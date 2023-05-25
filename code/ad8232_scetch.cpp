// Copyright Bulgakov Daniil 2023

// Полезная инфа
// Сенсор с зеленым проводом снимает второе отведение
// Распиновка
// output, 3v3, gnd - это стандарт
// lo+, lo- - пины, по которым можно отследить,
//            что считывающие контакты подключены или нет
// nds - пин, который переводит сенсор в энергосберегающий режим

//=============================================================================
// Пины для сенсора
//=============================================================================
#define Type1InPin 34
#define Type2InPin 32
// #define LOPlusInPin <input-here>
// #define LOMinusInPin <input-here>
// #define NDSOutPin <input-here>

//=============================================================================
// Стандартные параметры
//=============================================================================
#define TimeDelay 10
#define MonitorSpeed 9600
#define StandartDelay 10

//=============================================================================
// Объявление переменных
//=============================================================================
int sensorType1Value = 0;  // Считываем с сенсора на пине 34
int sensorType2Value = 0;  // Считываем с сенсора на пине 32
int sensorType3Value = 0;  // Получаем в виде
                           //    (sensorType2Value - sensorType1Value)
uint32_t last_ms = 0;

//=============================================================================
// Инициализация
//=============================================================================
void setup() {
  Serial.begin(MonitorSpeed);
  last_ms = millis();
}

//=============================================================================
// Цикл
//=============================================================================
void loop() {
  #if defined(LOPlusInPin) || defined(LOMinusInPin)
  if (digitalRead(LOPlusInPin) == 0 || digitalRead(LOMinusInPin) == 0)
    continue;
  #endif
  if ((millis() - last_ms) >= TimeDelay) {
    sensorType1Value = analogRead(Type1InPin);
    sensorType2Value = analogRead(Type2InPin);
    sensorType3Value = sensorType2Value - sensorType1Value;
    last_ms = millis();
    Serial.println(sensorType1Value);  // Выводит первое отведение
  }
}
