#include <Adafruit_Sensor.h>                       
#include <DHT.h>
#include <DHT_U.h>
// selecione um sensor, retirando o comentário - duas barras
#define DHTTYPE    DHT11                           
//#define DHTTYPE      DHT22                      
#define DHTPIN 2                                   
DHT_Unified dht(DHTPIN, DHTTYPE);                  
uint32_t delayMS;                 
void setup()
{
  Serial.begin(9600);                            
  dht.begin();                                    
  Serial.println("Usando o Sensor DHT");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);           
  Serial.println("------------------------------------");
  Serial.println("Temperatura");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Valor min:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolucao:   "); Serial.print(sensor.resolution); Serial.println(" *C");
  Serial.println("------------------------------------");
  dht.humidity().getSensor(&sensor);           
  Serial.println("------------------------------------");
  Serial.println("Umidade");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Valor min:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolucao:   "); Serial.print(sensor.resolution); Serial.println("%");
  Serial.println("------------------------------------");
  delayMS = sensor.min_delay / 1000;          
}
void loop()
{
  delay(delayMS);                              
  sensors_event_t event;                        
  dht.temperature().getEvent(&event);        
  if (isnan(event.temperature))        
  {
    Serial.println("Erro na leitura da Temperatura!");
  }
  else                                     
  {
    Serial.print("Temperatura: ");             
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  dht.humidity().getEvent(&event);              
  if (isnan(event.relative_humidity))          
  {
    Serial.println("Erro na leitura da Umidade!");
  }
  else                                        
  {
    Serial.print("Umidade: ");                 
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}
